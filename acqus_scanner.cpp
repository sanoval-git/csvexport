#include "acqus_scanner.h"
#include <QDebug>
#include <QString>
#include "exception.h"
AcqusScanner::AcqusScanner(QDir root, QDir parent, CsvBuilder* builder)
    : m_rootDir(root)
    , m_parentDir(parent)
    , m_builder(builder)
{
    m_acqus = new QFile( getParentPath() + "/acqus");
    if(!m_acqus->exists())
        throw Exception(QString("No acqus in %1 dir").arg(getParentPath()));
    if(!m_acqus->open(QIODevice::ReadOnly | QIODevice::Text))
        throw Exception(QString("Can't open %1 file for read!").arg(m_acqus->fileName()));
    int i = 1;
    int td,ns;
    float sw,sfo1;
    QString date,time;
    float spent_time;
    while (!m_acqus->atEnd()) {
        QByteArray line = m_acqus->readLine();
        if(i == 6){
            date = line.chopped(48).remove(0,3).remove(11,9);
            time = line.chopped(48).remove(0,14).remove(8,8);
        }
        else if( line.startsWith("##$SW=")) {
            sw = QString(line.remove(0,7).simplified()).toFloat();
//            qDebug() << "SW:" << sw;
        }
        else if(line.startsWith("##$SFO1=")){
            sfo1 = QString(line.remove(0,8).simplified()).toFloat();
//            qDebug() << "SFO1:" << sfo1;
        }
        else if(line.startsWith("##$TD=")){
            td = QString(line.remove(0,6).simplified()).toInt();
//            qDebug() << "TD:" << td;
        }
        else if(line.startsWith("##$NS=")){
            ns = QString(line.remove(0,6).simplified()).toInt();
            qDebug() << "NS:" << ns;
        }
        i++;
    }

    float dw = 1 / (2 * sw * sfo1);
//    qDebug()<<"DW:"<<dw;
    float aq = dw * (td - 1);
    qDebug()<<"AQ:"<<aq;
    spent_time = ns*aq/86400;
    qDebug()<<spent_time;

    m_builder->addLine({parent.dirName(), date, time, spent_time, ns, aq, td, dw});
}

AcqusScanner::~AcqusScanner()
{
    m_acqus->close();
    delete m_acqus;
}

QString AcqusScanner::getParentPath()
{
    return m_rootDir.path().append("/").append(m_parentDir.dirName());
}

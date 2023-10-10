#include "csv_builder.h"
#include "exception.h"
#include <QDebug>
#include <QByteArray>
CsvBuilder::CsvBuilder(QDir parent, QString filename)
    : m_file(parent.path().append("/").append(filename).append(".csv"))
{
    if(m_file.exists())
    {
        for(int i=1; i<=100; i++)
        {
            QString newFileName(parent.path().append("/").append(filename).append(QString::number(i)).append(".csv"));
            if(!QFile::exists(newFileName)){
                m_file.setFileName(newFileName);
                break;
            }
            else continue;
        }
    }
    if (!m_file.open(QIODevice::WriteOnly | QIODevice::Text))
        throw Exception(QString("Can't open %1 file for write!").arg(m_file.fileName()));
}

CsvBuilder::~CsvBuilder()
{
    m_file.close();
}

void CsvBuilder::addLine(const exporter::Data &data)
{
//    qDebug()<<data.csv();
    m_file.write(data.csv().append('\n').toLocal8Bit());
//    m_file.write();
}

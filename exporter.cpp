#include "exporter.h"
#include <QDebug>

#include "csv_builder.h"
#include "exception.h"

Exporter::Exporter(QDir root)
    : m_dir(root)
{
    try {
        auto dirs = m_dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        CsvBuilder csv(m_dir, "data");
        foreach (auto const& dir, dirs) {
            qDebug()<<dir;
            AcqusScanner scaner(m_dir, dir, &csv);
        }

    } catch (Exception& ex) {
        qDebug()<<ex.error();
    }
//    qDebug()<<"Count of directories in parent dir"<<m_dir.count();
}

Exporter::~Exporter()
{

}

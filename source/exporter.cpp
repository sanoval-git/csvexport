#include "exporter.h"
#include "csv_builder.h"
#include "exception.h"

#include <QDebug>
#include <iostream>

Exporter::Exporter(QDir root)
    : m_dir(root)
{
    try {
        auto dirs = m_dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        CsvBuilder csv(m_dir, "data");
        foreach (auto const& dir, dirs) {
            AcqusScanner scaner(m_dir, dir, &csv);
        }
    } catch (Exception& ex) {
        qDebug()<<ex.error();
    }
    std::cout<<"Parse completed"<<std::endl;
}

Exporter::~Exporter()
{

}

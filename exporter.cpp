#include "exporter.h"
#include <QDebug>

Exporter::Exporter(QDir dir)
    : m_dir(dir)
{
    qDebug()<<"Count of directories in parent dir"<<m_dir.count();
}

Exporter::~Exporter()
{

}

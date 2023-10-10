#ifndef CSVBUILDER_H
#define CSVBUILDER_H

#include <QString>
#include "structs.h"
#include <QFile>
#include <QDir>
class CsvBuilder
{
public:
    CsvBuilder(QDir parent, QString filename);
    ~CsvBuilder();
    void addLine(const exporter::Data &data);

private:
    QString m_filename;
    QFile m_file;
};

#endif // CSVBUILDER_H

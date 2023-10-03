#ifndef CSVBUILDER_H
#define CSVBUILDER_H

#include <QString>
#include "structs.h"
class CsvBuilder
{
public:
    CsvBuilder(QString filename);

    void addLine(exporter::Data &data);

    QString m_filename;
};

#endif // CSVBUILDER_H

#ifndef EXPORTER_H
#define EXPORTER_H

#include <QDir>
#include "acqus_scanner.h"
class Exporter
{
public:
    Exporter(QDir dir);
    ~Exporter();


private:
    QDir m_dir;
};

#endif // EXPORTER_H

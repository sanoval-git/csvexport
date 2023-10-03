#ifndef EXPORTER_H
#define EXPORTER_H

#include <QDir>

class Exporter
{
public:
    Exporter(QDir dir);
    ~Exporter();

    void recursiveParse();
    QDir m_dir;
};

#endif // EXPORTER_H

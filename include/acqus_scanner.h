#ifndef ACQUSSCANNER_H
#define ACQUSSCANNER_H
#include <QString>
#include <QDir>
#include <QFile>
#include "csv_builder.h"
class AcqusScanner
{
public:
    AcqusScanner(QDir root, QDir parent, CsvBuilder* builder);
    ~AcqusScanner();

private:
    QString getParentPath();

private:
    QDir m_rootDir;
    QDir m_parentDir;
    QFile* m_acqus;
    CsvBuilder* m_builder;

};

#endif // ACQUSSCANNER_H

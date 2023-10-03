#ifndef ACQUSSCANNER_H
#define ACQUSSCANNER_H
#include <QString>
#include <QFile>

class AcqusScanner
{
public:
    AcqusScanner();

    // setters
    void setFile(QFile &file);

    //  getters
    QString getDate(QFile &acqus);
    QString getTime(QFile &qcqua);
    QString getStartTime();
    int getSpentTime();
    int getNs();
    float getAq();
    int getTd();
    float getDw();

private:

};

#endif // ACQUSSCANNER_H

#ifndef STRUCTS_H
#define STRUCTS_H
#include <QString>
#include <QStringList>

namespace exporter {
    struct Data
    {
        QString name;       ///     Название образца
        QString date;       ///     Дата
        QString time_start; ///     Время начала
        float spent_time;     ///     Затраченное время, мин ns*aq/86400
        int ns;             /// 	Количество сканов
        float aq;           /// 	Время накопления одного скана, сек aq = dw*(td-1)
        int td;             /// 	Количество точек
        float dw;           /// 	Время на одну точку, сек

        QString csv() const
        {
            QStringList list;
            list << name
                 << date
                 << time_start
                 << QString::number(spent_time)
                 << QString::number(ns)
                 << QString::number(aq)
                 << QString::number(td)
                 << QString::number(dw);
            return list.join(";");
        }
    };
}
#endif // STRUCTS_H

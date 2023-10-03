#ifndef STRUCTS_H
#define STRUCTS_H
#include <QString>
namespace exporter {
    struct Data
    {
        QString name;       ///     Название образца
        QString date;       ///     Дата
        QString time_start; ///     Время начала
        int spent_time;     ///     Затраченное время, мин ns*aq/86400
        int ns;             /// 	Количество сканов
        float aq;           /// 	Время накопления одного скана, сек aq = dw*(td-1)
        int td;             /// 	Количество точек
        float dw;           /// 	Время на одну точку, сек
    };
}
#endif // STRUCTS_H

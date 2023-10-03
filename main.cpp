#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDebug>
#include "exporter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QCommandLineParser parser;
    parser.setApplicationDescription("\nFolder export into csv!");
    parser.addHelpOption();
    QCommandLineOption folderOption(QStringList() << "f", "Folder", "directory");
    parser.addOption(folderOption);
    parser.parse(a.arguments());

    if(parser.isSet(folderOption))
        qDebug()<<"Folder:"<<parser.value(folderOption);
    else{
        parser.showHelp(EXIT_FAILURE);
    }

    Exporter exp(parser.value(folderOption));

    return a.exec();
}

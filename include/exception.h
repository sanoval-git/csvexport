#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <QString>

class Exception : public std::exception
{
public:
    Exception(QString what)
        : m_what(what)
    {}

    const QString& error() { return m_what; }

private:
    QString m_what;
};

#endif // EXCEPTION_H

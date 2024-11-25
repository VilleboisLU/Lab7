#include <QCoreApplication>
#include <QtTest/QTest>

#include "api_tests.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec(new API_Tests, argc, argv);
    return a.exec();
}

#ifndef API_TESTS_H
#define API_TESTS_H

#include <QtTest/QTest>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QAuthenticator>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QUrlQuery>
#include <QDebug>
#include <QVector>

class API_Tests: public QObject
{
    Q_OBJECT
public:
    QNetworkAccessManager *netMan;
    explicit API_Tests(QObject *parent = 0);
    bool validateJsonObject(const QJsonObject&);

private slots:
    void GetUserTest();
    void GetOneUserTest();
    void GetNonExistentUserTest();

    void PostCreateUserTest();
    void PostBadCreateUserTest();

    void PutUserUpdateTest();

    void DeleteUserTest();
};

#endif // API_TESTS_H

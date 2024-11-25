#include "api_tests.h"

API_Tests::API_Tests(QObject *parent):
    QObject(parent)
{
}

bool API_Tests::validateJsonObject(const QJsonObject & jsonObject)
{
    if (!jsonObject.contains("id") || !jsonObject["id"].isDouble())
    {
        return false;
    }
    if (!jsonObject.contains("email") || !jsonObject["email"].isString())
    {
        return false;
    }
    if (!jsonObject.contains("first_name") || !jsonObject["first_name"].isString())
    {
        return false;
    }
    if (!jsonObject.contains("last_name") || !jsonObject["last_name"].isString())
    {
        return false;
    }
    if (!jsonObject.contains("avatar") || !jsonObject["avatar"].isString())
    {
        return false;
    }
    return true;
}

void API_Tests::GetUserTest()
{
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_0);
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyPeer);

    QFile ca("RootCA.crt");
    if (ca.open(QIODevice::ReadOnly))
    {
      QSslCertificate cert = QSslCertificate(&ca);
      QList <QSslCertificate> caList;
      caList.append(cert);
      sslConfig.setCaCertificates(caList);
    }

    QByteArray APIReply;
    QEventLoop eventLoop;
    QNetworkReply *reply;
    netMan = new QNetworkAccessManager();
    QObject::connect(netMan, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest request;
    request.setUrl(QUrl( QString( "https://reqres.in/api/users") ));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(sslConfig);

    reply = netMan->get(request);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError){
        APIReply = reply->readAll();
    }
    netMan->disconnect();
    QCOMPARE(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 200);
}

void API_Tests::GetOneUserTest()
{
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_0);
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyPeer);

    QFile ca("RootCA.crt");
    if (ca.open(QIODevice::ReadOnly))
    {
      QSslCertificate cert = QSslCertificate(&ca);
      QList <QSslCertificate> caList;
      caList.append(cert);
      sslConfig.setCaCertificates(caList);
    }

    QByteArray APIReply;
    QEventLoop eventLoop;
    QNetworkReply *reply;
    netMan = new QNetworkAccessManager();
    QObject::connect(netMan, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest request;
    request.setUrl(QUrl( QString( "https://reqres.in/api/users/5") ));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(sslConfig);

    reply = netMan->get(request);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError){
        APIReply = reply->readAll();
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(APIReply);
    QJsonObject obj = jsonResponse.object();
    QJsonValue data = obj.value("data");
    if (data.isObject())
    {
        obj = data.toObject();
    }
    netMan->disconnect();

    QCOMPARE(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 200);
    QCOMPARE(validateJsonObject(obj), true);
    QCOMPARE(obj["id"], 5);
}

void API_Tests::GetNonExistentUserTest()
{
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_0);
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyPeer);

    QFile ca("RootCA.crt");
    if (ca.open(QIODevice::ReadOnly))
    {
      QSslCertificate cert = QSslCertificate(&ca);
      QList <QSslCertificate> caList;
      caList.append(cert);
      sslConfig.setCaCertificates(caList);
    }

    QByteArray APIReply;
    QEventLoop eventLoop;
    QNetworkReply *reply;
    netMan = new QNetworkAccessManager();
    QObject::connect(netMan, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest request;
    request.setUrl(QUrl( QString( "https://reqres.in/api/users/200") ));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(sslConfig);

    reply = netMan->get(request);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError){
        APIReply = reply->readAll();
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(APIReply);
    QJsonObject obj = jsonResponse.object();
    QJsonValue data = obj.value("data");
    if (data.isObject())
    {
        obj = data.toObject();
    }
    netMan->disconnect();

    QCOMPARE(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 404);
}


void API_Tests::PostCreateUserTest()
{
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_0);
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyPeer);

    QFile ca("RootCA.crt");
    if (ca.open(QIODevice::ReadOnly))
    {
      QSslCertificate cert = QSslCertificate(&ca);
      QList <QSslCertificate> caList;
      caList.append(cert);
      sslConfig.setCaCertificates(caList);
    }

    QByteArray APIReply;
    QJsonObject APIRequest;
    APIRequest.insert("name", "Lev");
    APIRequest.insert("job", "C++ Developer");
    APIReply = QJsonDocument(APIRequest).toJson();
    QEventLoop eventLoop;
    QNetworkReply *reply;
    netMan = new QNetworkAccessManager();
    QObject::connect(netMan, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest request;
    request.setUrl(QUrl( QString( "https://reqres.in/api/users") ));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(sslConfig);

    reply = netMan->post(request, APIReply);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError){
        APIReply = reply->readAll();
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(APIReply);
    QJsonObject obj = jsonResponse.object();
    netMan->disconnect();

    QCOMPARE(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 201);
    QCOMPARE(obj.contains("id"), true);
    QCOMPARE(obj["name"].toString(), "Lev");
}

void API_Tests::PostBadCreateUserTest()
{
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_0);
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyPeer);

    QFile ca("RootCA.crt");
    if (ca.open(QIODevice::ReadOnly))
    {
      QSslCertificate cert = QSslCertificate(&ca);
      QList <QSslCertificate> caList;
      caList.append(cert);
      sslConfig.setCaCertificates(caList);
    }

    QByteArray APIReply;
    QJsonObject APIRequest;
    APIReply = QJsonDocument(APIRequest).toJson();
    QEventLoop eventLoop;
    QNetworkReply *reply;
    netMan = new QNetworkAccessManager();
    QObject::connect(netMan, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest request;
    request.setUrl(QUrl( QString( "http://reqres.in/api/users") ));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(sslConfig);

    reply = netMan->post(request, APIReply);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError){
        APIReply = reply->readAll();
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(APIReply);
    QJsonObject obj = jsonResponse.object();
    netMan->disconnect();

    QCOMPARE(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 301);
}


void API_Tests::PutUserUpdateTest()
{
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_0);
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyPeer);

    QFile ca("RootCA.crt");
    if (ca.open(QIODevice::ReadOnly))
    {
      QSslCertificate cert = QSslCertificate(&ca);
      QList <QSslCertificate> caList;
      caList.append(cert);
      sslConfig.setCaCertificates(caList);
    }

    QByteArray APIReply;
    QJsonObject APIRequest;
    APIRequest.insert("name", "Lev");
    APIRequest.insert("job", "C++ Developer");
    APIReply = QJsonDocument(APIRequest).toJson();
    QEventLoop eventLoop;
    QNetworkReply *reply;
    netMan = new QNetworkAccessManager();
    QObject::connect(netMan, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest request;
    request.setUrl(QUrl( QString( "https://reqres.in/api/users/5") ));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(sslConfig);

    reply = netMan->put(request, APIReply);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError){
        APIReply = reply->readAll();
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(APIReply);
    QJsonObject obj = jsonResponse.object();
    netMan->disconnect();

    QCOMPARE(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 200);
    QCOMPARE(obj["name"].toString(), "Lev");
}


void API_Tests::DeleteUserTest()
{
    QSslConfiguration sslConfig = QSslConfiguration::defaultConfiguration();
    sslConfig.setProtocol(QSsl::TlsV1_0);
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyPeer);

    QFile ca("RootCA.crt");
    if (ca.open(QIODevice::ReadOnly))
    {
      QSslCertificate cert = QSslCertificate(&ca);
      QList <QSslCertificate> caList;
      caList.append(cert);
      sslConfig.setCaCertificates(caList);
    }

    QByteArray APIReply;
    QEventLoop eventLoop;
    QNetworkReply *reply;
    netMan = new QNetworkAccessManager();
    QObject::connect(netMan, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QNetworkRequest request;
    request.setUrl(QUrl( QString( "https://reqres.in/api/users/5") ));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setSslConfiguration(sslConfig);

    reply = netMan->deleteResource(request);
    eventLoop.exec();

    if (reply->error() == QNetworkReply::NoError){
        APIReply = reply->readAll();
    }
    netMan->disconnect();

    QCOMPARE(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt(), 204);
}


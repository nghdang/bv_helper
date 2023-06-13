#include "Application/MainWindow/MainWindowViewModel.hpp"

#include <iostream>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>

namespace Application {
namespace MainWindow {

MainWindowViewModel::MainWindowViewModel(QObject* parent)
    : QObject{parent}
{
}

void MainWindowViewModel::saveToJson(QVariantMap jsonMap, QString filePath)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;

    auto jsonObject = QJsonObject::fromVariantMap(jsonMap);
    QJsonDocument jsonDoc{jsonObject};

    QFile jsonFile(filePath);
    if (jsonFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&jsonFile);
        stream << jsonDoc.toJson();
        jsonFile.close();
    }
}

QVariantMap MainWindowViewModel::loadFromJson(QString filePath)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    QVariantMap jsonMap;
    QFile jsonFile(filePath);
    if (jsonFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QByteArray jsonData = jsonFile.readAll();
        auto jsonDoc = QJsonDocument::fromJson(jsonData);
        auto jsonObject = jsonDoc.object();
        jsonMap = jsonObject.toVariantMap();
        jsonFile.close();
    }

    return jsonMap;
}

bool MainWindowViewModel::getIsFirstUse()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return not(QFile::exists("user_profile.json") or QFile::exists("team_profile.json"));
}

bool MainWindowViewModel::getIsLeader()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return m_isLeader;
}

void MainWindowViewModel::setIsLeader(bool value)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_isLeader = value;
    emit isLeaderChanged();
}

QString MainWindowViewModel::getGitHubToken()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return m_githubToken;
}

void MainWindowViewModel::setGitHubToken(QString value)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    m_githubToken = value;
    emit gitHubTokenChanged();
}

} // namespace MainWindow
} // namespace Application

#pragma once

#include <QObject>
#include <QVariantMap>

namespace MainWindow {

class MainWindowViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isFirstUse READ getIsFirstUse NOTIFY isFirstUseChanged)

    Q_PROPERTY(bool isLeader READ getIsLeader WRITE setIsLeader NOTIFY isLeaderChanged)

    Q_PROPERTY(QString githubToken READ getGitHubToken WRITE setGitHubToken NOTIFY gitHubTokenChanged)
public:
    explicit MainWindowViewModel(QObject* parent = nullptr);

    Q_INVOKABLE void saveToJson(QVariantMap jsonMap, QString filePath);
    Q_INVOKABLE QVariantMap loadFromJson(QString filePath);

    bool getIsFirstUse();

    bool getIsLeader();
    void setIsLeader(bool value);

    QString getGitHubToken();
    void setGitHubToken(QString value);

signals:
    void isFirstUseChanged();
    void isLeaderChanged();
    void gitHubTokenChanged();

protected:
    bool m_isLeader;
    QString m_githubToken;
};

} // namespace MainWindow

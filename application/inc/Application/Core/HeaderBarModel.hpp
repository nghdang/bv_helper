#pragma once

#include <QObject>

class HeaderBarModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString headerText READ getHeaderText NOTIFY headerTextChanged)

    Q_PROPERTY(bool hasBackButton READ hasBackButton NOTIFY hasBackButtonChanged)
public:
    explicit HeaderBarModel(QObject* parent = nullptr);

    QString getHeaderText() const;
    void setHeaderText(const QString& value);

    bool hasBackButton() const;
    void setHasBackButton(bool value);

signals:
    void headerTextChanged();
    void hasBackButtonChanged();

protected:
    QString m_headerText;
    bool m_hasBackButton;
};

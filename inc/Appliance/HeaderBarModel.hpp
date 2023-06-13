#pragma once

#include <QObject>

class HeaderBarModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString headerText READ getHeaderText NOTIFY headerTextChanged)
public:
    explicit HeaderBarModel(QObject* parent = nullptr);

    QString getHeaderText() const;
    void setHeaderText(const QString& value);

signals:
    void headerTextChanged();

protected:
    QString m_headerText;
};

#pragma once

#include <QObject>

namespace Application {
namespace Gui {

class HeaderBarModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool isShowHeaderBar READ isShowHeaderBar NOTIFY isShowHeaderBarChanged)

    Q_PROPERTY(QString headerText READ getHeaderText NOTIFY headerTextChanged)

    Q_PROPERTY(bool hasBackButton READ hasBackButton NOTIFY hasBackButtonChanged)

    Q_PROPERTY(bool hasNextButton READ hasNextButton NOTIFY hasNextButtonChanged)
public:
    explicit HeaderBarModel(QObject* parent = nullptr);

    bool isShowHeaderBar() const;
    void setIsShowHeaderBar(bool value);

    QString getHeaderText() const;
    void setHeaderText(const QString& value);

    bool hasBackButton() const;
    void setHasBackButton(bool value);

    bool hasNextButton() const;
    void setHasNextButton(bool value);

signals:
    void isShowHeaderBarChanged();
    void headerTextChanged();
    void hasBackButtonChanged();
    void hasNextButtonChanged();

protected:
    bool m_isShowHeaderBar;
    QString m_headerText;
    bool m_hasBackButton;
    bool m_hasNextButton;
};

} // namespace Gui
} // namespace Application

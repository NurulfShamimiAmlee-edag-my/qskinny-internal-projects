#ifndef TOPBAR_H
#define TOPBAR_H

#include <QskAspect.h>
#include <QskGraphicLabel.h>
#include <QskGridBox.h>
#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <QskPushButton.h>
#include <qquickitem.h>

class TopBarMenuButton : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Text);

        TopBarMenuButton();
};

class TopBar : public QskLinearBox
{

    private:
        TopBarMenuButton* m_menuButton = new TopBarMenuButton;
    public:
        QSK_SUBCONTROLS(Panel)

        TopBar(QQuickItem* parent = nullptr);
        QskGraphicLabel* setLogo(QString text);
        QskTextLabel* setStatusLabels(QString text);
        TopBarMenuButton* setMenuButton(QString text);
        TopBarMenuButton* getMenuButton();
};


#endif //TOPBAR_H
#ifndef TOPBAR_H
#define TOPBAR_H

#include <QskGraphicLabel.h>
#include <QskGridBox.h>
#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <QskPushButton.h>
#include <qquickitem.h>

class TopBar : public QskLinearBox
{
    public:
        QskPushButton* m_menuButton = new QskPushButton;
    public:
        TopBar(QQuickItem* parent = nullptr);
        // ~TopBar();
        QskGraphicLabel* setLogo(QString text);
        QskTextLabel* setStatusLabels(QString text);
        QskPushButton* setMenuButton(QString text);
};


#endif //TOPBAR_H
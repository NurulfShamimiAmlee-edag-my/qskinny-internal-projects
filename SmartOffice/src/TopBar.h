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
        TopBar(QQuickItem* parent = nullptr);
        // ~TopBar();
        QskGraphicLabel* setCompanyLogo(QString text);
        QskTextLabel* setStatusLabels(QString text);
        QskPushButton* setMenuButton(QString text);
};


#endif //TOPBAR_H
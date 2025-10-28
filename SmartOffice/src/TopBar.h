#ifndef TOPBAR_H
#define TOPBAR_H

#include <QskAspect.h>
#include <QskGraphicLabel.h>
#include <QskGridBox.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <QskPushButton.h>
#include <qquickitem.h>

#include "TopBarMenuButton.h"
#include "TopBarGraphicLabel.h"

class TopBar : public QskLinearBox
{

    private:
        TopBarMenuButton* m_menuButton = new TopBarMenuButton;
    public:
        QSK_SUBCONTROLS(Panel)

        TopBar(QQuickItem* parent = nullptr);
        TopBarGraphicLabel* setGraphicLabel(const QString& path);
        QskTextLabel* setStatusLabels(QString text);
        TopBarMenuButton* setMenuButton(const QString& path);
        TopBarMenuButton* getMenuButton();
};


#endif //TOPBAR_H
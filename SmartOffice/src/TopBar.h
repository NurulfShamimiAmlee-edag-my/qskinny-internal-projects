#ifndef TOPBAR_H
#define TOPBAR_H

#include <QskAspect.h>
#include <QskGraphicLabel.h>
#include <QskGridBox.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <QskPushButton.h>
#include <qquickitem.h>
#include <qtimer.h>

#include "TopBarMenuButton.h"
#include "TopBarGraphicLabel.h"

class TopBar : public QskLinearBox
{

    private:
        TopBarMenuButton* m_menuButton = nullptr;
        QskLinearBox* m_dateAndClockBox = nullptr;
        QskTextLabel* m_timeLabel = nullptr;
        QskTextLabel* m_dateLabel = nullptr;
        QTimer* m_timer = nullptr;

    public:
        QSK_SUBCONTROLS(Panel)

        TopBar(QQuickItem* parent = nullptr);
        TopBarGraphicLabel* setGraphicLabel(const QString& path);
        QskTextLabel* setStatusLabels(QString text);
        TopBarMenuButton* setMenuButton(const QString& path);
        QskLinearBox* setClockAndDate();
        TopBarMenuButton* getMenuButton();
    
    protected:
        void geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry) override;
};


#endif //TOPBAR_H
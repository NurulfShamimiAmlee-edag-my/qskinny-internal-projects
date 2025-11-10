#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QskAspect.h>
#include <QskLinearBox.h>
#include <QskStackBox.h>
#include <QskSwitchButton.h>
#include <QskTextLabel.h>
#include <QskPushButton.h>
#include <QskGraphicLabel.h>
#include <qnamespace.h>
#include <qquickitem.h>
#include <qvectornd.h>

#include "MainPageTextLabel.h"
#include "MainPageGraphicLabel.h"
#include "MainPageSwitchButton.h"
#include "SingletonBannerDb.h"

class MainPageBannerBox : public QskLinearBox
{
    protected:
        /*
            TODO: If master switch from room page is toggled, update the banner text label
            - consider that the master switch should control the related utility only.
        */
        MainPageTextLabel* m_bannerText = nullptr;
        MainPageGraphicLabel* m_graphicLabel = nullptr;
        MainPageSwitchButton* m_switchButton = nullptr;
        QVector<MainPageBannerBox*> m_bannersList;
        SingletonBannerDb::BannerSlot m_slot;

    
    public:
        QSK_SUBCONTROLS(Panel);

        MainPageBannerBox(QString labelText, SingletonBannerDb::BannerSlot slot);
        MainPageBannerBox();
    
    protected:
        void geometryChange(const QRectF &newGeometry, const QRectF &oldGeometry) override;
        void setBannerButton();
        void setBannerGraphicLabel();
        void setBannerSwitchButton();
};



class MainPage : public QskLinearBox
{
    public:
        MainPage();
};


#endif //MAINPAGE_H
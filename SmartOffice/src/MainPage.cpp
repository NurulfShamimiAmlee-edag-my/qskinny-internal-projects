#include "MainPage.h"
#include <QskAspect.h>
#include <QskBoxBorderColors.h>
#include <QskBoxShapeMetrics.h>
#include <QskGraphic.h>
#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskMargins.h>
#include <QskPushButton.h>
#include <QskSizePolicy.h>
#include <QskSkin.h>
#include <QskSkinFactory.h>
#include <QskSkinnable.h>
#include <QskStackBox.h>
#include <QskTextLabel.h>
#include <QskBoxBorderMetrics.h>
#include <QskFontRole.h>
#include <QskTextOptions.h>
#include <QskSkinnable.h>
#include <qnamespace.h>


#include <QskSkinManager.h>

QSK_SUBCONTROL(MainPageTextLabel, Panel)
QSK_SUBCONTROL(MainPageTextLabel, Text)

QSK_SUBCONTROL(MainPagePushButton, Panel)
QSK_SUBCONTROL(MainPagePushButton, Text)

QSK_SUBCONTROL(MainPageGraphicLabel, Panel)

QSK_SUBCONTROL(MainPageBannerBox, Panel);

MainPageTextLabel::MainPageTextLabel(const QString& text, QQuickItem* parent) : QskTextLabel(text, parent)
{
    setSubcontrolProxy(QskTextLabel::Panel, Panel);
    setSubcontrolProxy(QskTextLabel::Text, Text);
}

MainPagePushButton::MainPagePushButton(const QString& text, QQuickItem* parent) : QskPushButton(text, parent)
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Text, Text);
}

MainPageGraphicLabel::MainPageGraphicLabel(const QskGraphic& graphic, QQuickItem* parent) : QskGraphicLabel(graphic, parent)
{
    setSubcontrolProxy(QskGraphicLabel::Panel, Panel);
}

MainPageBannerBox::MainPageBannerBox() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    setSubcontrolProxy(QskLinearBox::Panel, Panel);
}

class LightBannerFactory :  public BannerFactory
{
    public:
        MainPageTextLabel* createTileTitle() override
        {
            auto* lightTileTitle = new MainPageTextLabel("Active Lights: 10");
            lightTileTitle->setPanel(true);
            lightTileTitle->setFixedWidth(300);
            lightTileTitle->setLayoutAlignmentHint(Qt::AlignCenter);
            return lightTileTitle;
        }

        MainPagePushButton* createMasterSwitch() override
        {
            auto* lightMasterSwitch = new MainPagePushButton("Master switch light");
            lightMasterSwitch->setFixedSize(180,180);
            lightMasterSwitch->setLayoutAlignmentHint(Qt::AlignCenter);
            return lightMasterSwitch;
        }

        MainPageGraphicLabel* createIconLabel() override
        {
            QImage lightIconImage("assets/lamp.png");
            QskGraphic lightIconGraphic = QskGraphic::fromImage(lightIconImage);
            auto* lightIconLabel = new MainPageGraphicLabel(lightIconGraphic);
            // lightIconLabel->setPanel(true);
            lightIconLabel->setFixedSize(360,360);
            lightIconLabel->setLayoutAlignmentHint(Qt::AlignCenter);
            lightIconLabel->setColor(MainPageGraphicLabel::Graphic, QColor("#f5bd82"));
            return lightIconLabel;
        }


};

class WifiBannerFactory :  public BannerFactory
{
    public:
        MainPageTextLabel* createTileTitle() override
        {
            auto* wifiTileTitle = new MainPageTextLabel("Active Wifi: 3");
            wifiTileTitle->setPanel(true);
            wifiTileTitle->setFixedWidth(300);
            wifiTileTitle->setLayoutAlignmentHint(Qt::AlignCenter);
            return wifiTileTitle;
        }

        MainPagePushButton* createMasterSwitch() override
        {
            auto* wifiMasterSwitch = new MainPagePushButton("Master switch Wifi");
            wifiMasterSwitch->setFixedSize(180,180);
            wifiMasterSwitch->setLayoutAlignmentHint(Qt::AlignCenter);
            return wifiMasterSwitch;
        }

        MainPageGraphicLabel* createIconLabel() override
        {
            QImage wifiIconImage("assets/wifi-router.png");
            QskGraphic wifiIconGraphic = QskGraphic::fromImage(wifiIconImage);
            auto* wifiIconLabel = new MainPageGraphicLabel(wifiIconGraphic);
            // wifiIconLabel->setPanel(true);
            wifiIconLabel->setFixedSize(360,360);
            wifiIconLabel->setLayoutAlignmentHint(Qt::AlignCenter);
            return wifiIconLabel;
        }


};

class AcBannerFactory :  public BannerFactory
{
    public:
        MainPageTextLabel* createTileTitle() override
        {
            auto* acTileTitle = new MainPageTextLabel("Active AC: 3");
            acTileTitle->setPanel(true);
            acTileTitle->setFixedWidth(300);
            acTileTitle->setLayoutAlignmentHint(Qt::AlignCenter);
            return acTileTitle;
        }

        MainPagePushButton* createMasterSwitch() override
        {
            auto* acMasterSwitch = new MainPagePushButton("Master switch AC");
            acMasterSwitch->setFixedSize(180,180);
            acMasterSwitch->setLayoutAlignmentHint(Qt::AlignCenter);
            return acMasterSwitch;
        }

        MainPageGraphicLabel* createIconLabel() override
        {
            QImage acIconImage("assets/air-conditioner.png");
            QskGraphic acIconGraphic = QskGraphic::fromImage(acIconImage);
            auto* acIconLabel = new MainPageGraphicLabel(acIconGraphic);
            // acIconLabel->setPanel(true);
            acIconLabel->setFixedSize(360,360);
            acIconLabel->setLayoutAlignmentHint(Qt::AlignCenter);           
            return acIconLabel;
        }


};

MainPage::MainPage() : QskLinearBox()
{
    LightBannerFactory lightBannerFact;
    WifiBannerFactory wifiBannerFact;
    AcBannerFactory acBannerFact;
    this->setOrientation(Qt::Horizontal);
    // this->setSpacing(10)
    this->addItem(buildBanner(lightBannerFact));
    this->addItem(buildBanner(wifiBannerFact));
    this->addItem(buildBanner(acBannerFact));

    //TODO:
    //this->addItem(new Banner("Active Lights", "Master Switch Light", "assets/lamp.png"));
    //this->addItem(new Banner("Active AC, "Master Switch AC", "assets/air-conditioner.png"));
    //this->addItem(new Banner("Active Wifi, "Master Switch Wifi, "assets/wifi-router.png"));
}

MainPageBannerBox* MainPage::buildBanner(BannerFactory& factory)
{
    auto* banner = new MainPageBannerBox();
    banner->setPanel(true);
    banner->addItem(factory.createTileTitle());
    banner->addItem(factory.createIconLabel());
    banner->addItem(factory.createMasterSwitch());
    return banner;
}



#include "MainPage.h"
#include <QskBoxShapeMetrics.h>
#include <QskGraphic.h>
#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskSkinnable.h>
#include <QskStackBox.h>
#include <QskTextLabel.h>
#include <QskBoxBorderMetrics.h>
#include <QskFontRole.h>
#include <qnamespace.h>

class LightBannerFactory :  public BannerFactory
{
    public:
        QskTextLabel* createTileTitle() override
        {
            auto* lightTileTitle = new QskTextLabel("Active Lights: 10");
            lightTileTitle->setAlignment(Qt::AlignCenter);
            lightTileTitle->setFontRole({QskFontRole::Display, QskFontRole::High});
            return lightTileTitle;
        }

        QskPushButton* createMasterSwitch() override
        {
            auto* lightMasterSwitch = new QskPushButton("Master switch light");
            return lightMasterSwitch;
        }

        QskGraphicLabel* createIconLabel() override
        {
            QImage lightIconImage("assets/lamp.png");
            QskGraphic lightIconGraphic = QskGraphic::fromImage(lightIconImage);
            auto* lightIconLabel = new QskGraphicLabel(lightIconGraphic);
            // lightIconLabel->setSize(25, 25);
            return lightIconLabel;
        }


};

class WifiBannerFactory :  public BannerFactory
{
    public:
        QskTextLabel* createTileTitle() override
        {
            auto* wifiTileTitle = new QskTextLabel("Active Wifi: 3");
            wifiTileTitle->setAlignment(Qt::AlignCenter);
            wifiTileTitle->setFontRole({QskFontRole::Display, QskFontRole::High});
            return wifiTileTitle;
        }

        QskPushButton* createMasterSwitch() override
        {
            auto* wifiMasterSwitch = new QskPushButton("Master switch Wifi");
            return wifiMasterSwitch;
        }

        QskGraphicLabel* createIconLabel() override
        {
            QImage wifiIconImage("assets/wifi-router.png");
            QskGraphic wifiIconGraphic = QskGraphic::fromImage(wifiIconImage);
            auto* wifiIconLabel = new QskGraphicLabel(wifiIconGraphic);
            return wifiIconLabel;
        }


};

class AcBannerFactory :  public BannerFactory
{
    public:
        QskTextLabel* createTileTitle() override
        {
            auto* acTileTitle = new QskTextLabel("Active AC: 3");
            acTileTitle->setAlignment(Qt::AlignCenter);
            acTileTitle->setFontRole({QskFontRole::Display, QskFontRole::High});
            return acTileTitle;
        }

        QskPushButton* createMasterSwitch() override
        {
            auto* acMasterSwitch = new QskPushButton("Master switch AC");
            return acMasterSwitch;
        }

        QskGraphicLabel* createIconLabel() override
        {
            QImage acIconImage("assets/air-conditioner.png");
            QskGraphic acIconGraphic = QskGraphic::fromImage(acIconImage);
            auto* acIconLabel = new QskGraphicLabel(acIconGraphic);
            return acIconLabel;
        }


};

MainPage::MainPage() : QskLinearBox()
{

    LightBannerFactory lightBannerFact;
    WifiBannerFactory wifiBannerFact;
    AcBannerFactory acBannerFact;
    this->setOrientation(Qt::Horizontal);
    // this->setSpacing(10);
    this->addItem(buildBanner(lightBannerFact));
    this->addItem(buildBanner(wifiBannerFact));
    this->addItem(buildBanner(acBannerFact));
}

QskLinearBox* MainPage::buildBanner(BannerFactory& factory)
{
    auto* banner = new QskLinearBox(Qt::Vertical);
    banner->setPanel(true);
    // banner->setMargins(10);
    banner->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    banner->setColor(QskLinearBox::Panel, QColor("#cb8587"));
    banner->addItem(factory.createIconLabel());
    banner->addItem(factory.createTileTitle());
    banner->addItem(factory.createMasterSwitch());
    return banner;
}


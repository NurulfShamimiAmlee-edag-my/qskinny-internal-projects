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

class LightBannerFactory :  public BannerFactory
{
    public:
        QskTextLabel* createTileTitle() override
        {
            auto* lightTileTitle = new QskTextLabel("Active Lights: 10");
            lightTileTitle->setPanel(true);
            lightTileTitle->setFixedWidth(300);
            lightTileTitle->setLayoutAlignmentHint(Qt::AlignCenter);
            return lightTileTitle;
        }

        QskPushButton* createMasterSwitch() override
        {
            auto* lightMasterSwitch = new QskPushButton("Master switch light");
            lightMasterSwitch->setFixedSize(180,180);
            lightMasterSwitch->setLayoutAlignmentHint(Qt::AlignCenter);
            return lightMasterSwitch;
        }

        QskGraphicLabel* createIconLabel() override
        {
            QImage lightIconImage("assets/lamp.png");
            QskGraphic lightIconGraphic = QskGraphic::fromImage(lightIconImage);
            auto* lightIconLabel = new QskGraphicLabel(lightIconGraphic);
            // lightIconLabel->setPanel(true);
            lightIconLabel->setFixedSize(360,360);
            lightIconLabel->setLayoutAlignmentHint(Qt::AlignCenter);
            lightIconLabel->setColor(QskGraphicLabel::Graphic, QColor("#f5bd82"));
            return lightIconLabel;
        }


};

class WifiBannerFactory :  public BannerFactory
{
    public:
        QskTextLabel* createTileTitle() override
        {
            auto* wifiTileTitle = new QskTextLabel("Active Wifi: 3");
            wifiTileTitle->setPanel(true);
            wifiTileTitle->setFixedWidth(300);
            wifiTileTitle->setLayoutAlignmentHint(Qt::AlignCenter);
            return wifiTileTitle;
        }

        QskPushButton* createMasterSwitch() override
        {
            auto* wifiMasterSwitch = new QskPushButton("Master switch Wifi");
            wifiMasterSwitch->setFixedSize(180,180);
            wifiMasterSwitch->setLayoutAlignmentHint(Qt::AlignCenter);
            return wifiMasterSwitch;
        }

        QskGraphicLabel* createIconLabel() override
        {
            QImage wifiIconImage("assets/wifi-router.png");
            QskGraphic wifiIconGraphic = QskGraphic::fromImage(wifiIconImage);
            auto* wifiIconLabel = new QskGraphicLabel(wifiIconGraphic);
            // wifiIconLabel->setPanel(true);
            wifiIconLabel->setFixedSize(360,360);
            wifiIconLabel->setLayoutAlignmentHint(Qt::AlignCenter);
            return wifiIconLabel;
        }


};

class AcBannerFactory :  public BannerFactory
{
    public:
        QskTextLabel* createTileTitle() override
        {
            auto* acTileTitle = new QskTextLabel("Active AC: 3");
            acTileTitle->setPanel(true);
            acTileTitle->setFixedWidth(300);
            acTileTitle->setLayoutAlignmentHint(Qt::AlignCenter);
            return acTileTitle;
        }

        QskPushButton* createMasterSwitch() override
        {
            auto* acMasterSwitch = new QskPushButton("Master switch AC");
            acMasterSwitch->setFixedSize(180,180);
            acMasterSwitch->setLayoutAlignmentHint(Qt::AlignCenter);
            return acMasterSwitch;
        }

        QskGraphicLabel* createIconLabel() override
        {
            QImage acIconImage("assets/air-conditioner.png");
            QskGraphic acIconGraphic = QskGraphic::fromImage(acIconImage);
            auto* acIconLabel = new QskGraphicLabel(acIconGraphic);
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
}

QskLinearBox* MainPage::buildBanner(BannerFactory& factory)
{
    auto* banner = new QskLinearBox(Qt::Vertical);
    // banner->setSize(720,800);
    banner->setPanel(true);
    banner->setMargins(QskMargins(25));
    banner->setBoxBorderMetricsHint(QskLinearBox::Panel, QskBoxBorderMetrics(5));
    banner->setColor(QskLinearBox::Panel | QskAspect::Border, QColor("#f5bd82"));
    banner->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    banner->addItem(factory.createTileTitle());
    banner->addItem(factory.createIconLabel());
    banner->addItem(factory.createMasterSwitch());
    return banner;
}


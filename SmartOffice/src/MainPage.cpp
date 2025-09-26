#include "MainPage.h"
#include <QskBoxShapeMetrics.h>
#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h>
#include <QskBoxBorderMetrics.h>
#include <qnamespace.h>


class LightBannerFactory :  public BannerFactory
{
    public:
        QskTextLabel* createTileTitle() override
        {
            auto* lightTileTitle = new QskTextLabel("Active Lights: 10");
            lightTileTitle->setAlignment(Qt::AlignCenter);
            return lightTileTitle;
        }

        QskPushButton* createMasterSwitch() override
        {
            auto* lightMasterSwitch = new QskPushButton("Master switch light");
            return lightMasterSwitch;
        }

        QskGraphicLabel* createIconLabel() override
        {
            auto* lightIconLabel = new QskGraphicLabel();
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
            return wifiTileTitle;
        }

        QskPushButton* createMasterSwitch() override
        {
            auto* wifiMasterSwitch = new QskPushButton("Master switch Wifi");
            return wifiMasterSwitch;
        }

        QskGraphicLabel* createIconLabel() override
        {
            auto* wifiIconLabel = new QskGraphicLabel();
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
            return acTileTitle;
        }

        QskPushButton* createMasterSwitch() override
        {
            auto* acMasterSwitch = new QskPushButton("Master switch AC");
            return acMasterSwitch;
        }

        QskGraphicLabel* createIconLabel() override
        {
            auto* acIconLabel = new QskGraphicLabel();
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
    banner->setColor(QskLinearBox::Panel, QColor("#d3abac"));
    banner->addItem(factory.createTileTitle());
    banner->addItem(factory.createMasterSwitch());
    // banner->addItem(factory.createIconLabel());
    return banner;
}
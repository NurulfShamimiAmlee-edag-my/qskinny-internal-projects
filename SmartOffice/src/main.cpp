#include <QskAspect.h>
#include <QskMargins.h>
#include <QskScrollView.h>
#include <QskSkinnable.h>
#include <QskWindow.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h>
#include <QskGridBox.h>
#include <QskBoxBorderMetrics.h>
#include <QskBoxBorderColors.h>
#include <QskBoxShapeMetrics.h>
#include <QGuiApplication>
#include <qnamespace.h>
 
int main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );
 
    auto* verticalContainerBox = new QskLinearBox( Qt::Vertical );
    verticalContainerBox->setPanel( true );
    verticalContainerBox->setColor(QskLinearBox::Panel, QColor("#8a8691"));

    /*
        TOP BAR
    */
    auto* topBarGridBox = new QskGridBox(verticalContainerBox);
    topBarGridBox->setPanel(true);
    topBarGridBox->setBoxShapeHint(QskGridBox::Panel, QskBoxShapeMetrics(8));
    // topBarGridBox->setBoxBorderMetricsHint(QskGridBox::Panel, QskBoxBorderMetrics(2));
    // topBarGridBox->setBoxBorderColorsHint(QskGridBox::Panel, QskBoxBorderColors(Qt::white));
    topBarGridBox->setPaddingHint(QskGridBox::Panel, 10);
    topBarGridBox->setColor(QskGridBox::Panel, QColor("#6d6875"));
    topBarGridBox->setFixedHeight(50);
    //TODO: Make this bar static when page changes
    //TODO: Place edag logo on most left. 
    auto* edagLogo = new QskTextLabel("EDAG");
    topBarGridBox->addItem(edagLogo, 0,0);
    //TODO: Place temperature, enery consumption, humidity logo in the middle.
    auto* temperatureLogo = new QskTextLabel("Temperature");
    temperatureLogo->setAlignment(Qt::AlignCenter);
    auto* energyLogo = new QskTextLabel("Energy");
    energyLogo->setAlignment(Qt::AlignCenter);
    auto* humidityLogo = new QskTextLabel("Humidity");
    humidityLogo->setAlignment(Qt::AlignCenter);
    topBarGridBox->addItem(temperatureLogo, 0, 4);
    topBarGridBox->addItem(energyLogo, 0,5);
    topBarGridBox->addItem(humidityLogo, 0,6);
    //TODO: Place button with menu logo on most right
    auto* menuButton =  new QskPushButton("Menu");
    topBarGridBox->addItem(menuButton, 0, 10);


    /*
        BOTTOM SECTION
    */    
    auto* horizontalBottomSection = new QskLinearBox(Qt::Horizontal, verticalContainerBox);
    //TODO: Place a box with how many lights are currently on in the unit and a master switch to switch off the lights when needed. Maybe if button is pushed set the number of light counts to 0?
    auto* lightsUtilityBox = new QskLinearBox(Qt::Vertical, horizontalBottomSection);
    lightsUtilityBox->setPanel(true); 
    lightsUtilityBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(50));
    lightsUtilityBox->setColor(QskLinearBox::Panel, QColor("#ffcdb2"));   

    auto* activeLightsLabel = new QskTextLabel("Active Lights: 3", lightsUtilityBox);
    activeLightsLabel->setPanel(true);
    activeLightsLabel->setAlignment(Qt::AlignCenter);
    activeLightsLabel->setBoxShapeHint(QskTextLabel::Panel, QskBoxShapeMetrics(50));
    activeLightsLabel->setPaddingHint(QskTextLabel::Panel, QskMargins(25,25));
    activeLightsLabel->setBoxBorderColorsHint(QskTextLabel::Panel, Qt::white);
    // activeLightsLabel->setPreferredHeight(200);
    activeLightsLabel->setColor(QskTextLabel::Panel,QColor("#e5989b"));
    activeLightsLabel->setTextColor("#6d6875");

    auto* masterSwitchLights = new QskPushButton("Lights off", lightsUtilityBox);
    masterSwitchLights->setBoxShapeHint(QskGridBox::Panel, QskBoxShapeMetrics(8));
    masterSwitchLights->setColor(QskPushButton::Panel, QColor("#e5989b"));

    //TODO: Place a box with how many AC are currently on in the unit with a master to switch off all AC when needed,
    auto* acUtilityBox = new QskLinearBox(Qt::Vertical, horizontalBottomSection);
    acUtilityBox->setPanel(true); 
    acUtilityBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(16));
    acUtilityBox->setColor(QskLinearBox::Panel, QColor("#ffcdb2"));  
    // acUtilityBox->setBoxBorderMetricsHint(QskLinearBox::Panel, QskBoxBorderMetrics(2));
    // acUtilityBox->setBoxBorderColorsHint(QskLinearBox::Panel, QskBoxBorderColors(Qt::white));
    auto* activeAcLabel = new QskTextLabel("Active AC: 5", acUtilityBox);
    activeAcLabel->setAlignment(Qt::AlignCenter);
    auto* masterSwitchAc = new QskPushButton("AC off", acUtilityBox);
    
    //TODO: Place a box with how many WiFi are currently on in the unit with a master switch to switch off all WiFi when needed
    auto* wifiUtilityBox = new QskLinearBox(Qt::Vertical, horizontalBottomSection);
    wifiUtilityBox->setPanel(true); 
    wifiUtilityBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    wifiUtilityBox->setColor(QskLinearBox::Panel, QColor("#ffcdb2")); 
    // wifiUtilityBox->setBoxBorderMetricsHint(QskLinearBox::Panel, QskBoxBorderMetrics(2));
    // wifiUtilityBox->setBoxBorderColorsHint(QskLinearBox::Panel, QskBoxBorderColors(Qt::white));
    auto* activeWifiLabel = new QskTextLabel("Active WiFi: 4", wifiUtilityBox);
    activeWifiLabel->setAlignment(Qt::AlignCenter);
    auto* masterSwitchWifi = new QskPushButton("WiFi off", wifiUtilityBox);

    QskWindow window;
    window.addItem( verticalContainerBox );
    window.resize(1920, 1080);
    window.show();
 
    return app.exec();
}
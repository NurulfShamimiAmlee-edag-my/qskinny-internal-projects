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
 

#include "TopBar.h"
#include "MainPage.h"
int main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );
 
    auto* verticalContainerBox = new QskLinearBox( Qt::Vertical );
    verticalContainerBox->setPanel( true );
    verticalContainerBox->setColor(QskLinearBox::Panel, QColor("#6f819a"));

    /*
        TOP BAR
    */
    // auto* topBar =  new TopBar(verticalContainerBox);
    verticalContainerBox->addItem(new TopBar());

    /*
        BOTTOM SECTION
    */ 
    verticalContainerBox->addItem(new MainPage());   
    // auto* horizontalBottomSection = new QskLinearBox(Qt::Horizontal, verticalContainerBox);
    // //TODO: Place a box with how many lights are currently on in the unit and a master switch to switch off the lights when needed. Maybe if button is pushed set the number of light counts to 0?
    // auto* lightsUtilityBox = new QskLinearBox(Qt::Vertical, horizontalBottomSection);
    // lightsUtilityBox->setPanel(true); 
    // lightsUtilityBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(50));
    // lightsUtilityBox->setColor(QskLinearBox::Panel, QColor("#ffcdb2"));   

    // auto* activeLightsLabel = new QskTextLabel("Active Lights: 3", lightsUtilityBox);
    // activeLightsLabel->setPanel(true);
    // activeLightsLabel->setAlignment(Qt::AlignCenter);
    // activeLightsLabel->setBoxShapeHint(QskTextLabel::Panel, QskBoxShapeMetrics(50));
    // activeLightsLabel->setPaddingHint(QskTextLabel::Panel, QskMargins(25,25));
    // activeLightsLabel->setBoxBorderColorsHint(QskTextLabel::Panel, Qt::white);
    // // activeLightsLabel->setPreferredHeight(200);
    // activeLightsLabel->setColor(QskTextLabel::Panel,QColor("#e5989b"));
    // activeLightsLabel->setTextColor("#6d6875");

    // auto* masterSwitchLights = new QskPushButton("Lights off", lightsUtilityBox);
    // masterSwitchLights->setBoxShapeHint(QskGridBox::Panel, QskBoxShapeMetrics(8));
    // masterSwitchLights->setColor(QskPushButton::Panel, QColor("#e5989b"));

    // //TODO: Place a box with how many AC are currently on in the unit with a master to switch off all AC when needed,
    // auto* acUtilityBox = new QskLinearBox(Qt::Vertical, horizontalBottomSection);
    // acUtilityBox->setPanel(true); 
    // acUtilityBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(16));
    // acUtilityBox->setColor(QskLinearBox::Panel, QColor("#ffcdb2"));  
    // // acUtilityBox->setBoxBorderMetricsHint(QskLinearBox::Panel, QskBoxBorderMetrics(2));
    // // acUtilityBox->setBoxBorderColorsHint(QskLinearBox::Panel, QskBoxBorderColors(Qt::white));
    // auto* activeAcLabel = new QskTextLabel("Active AC: 5", acUtilityBox);
    // activeAcLabel->setAlignment(Qt::AlignCenter);
    // auto* masterSwitchAc = new QskPushButton("AC off", acUtilityBox);
    
    // //TODO: Place a box with how many WiFi are currently on in the unit with a master switch to switch off all WiFi when needed
    // auto* wifiUtilityBox = new QskLinearBox(Qt::Vertical, horizontalBottomSection);
    // wifiUtilityBox->setPanel(true); 
    // wifiUtilityBox->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    // wifiUtilityBox->setColor(QskLinearBox::Panel, QColor("#ffcdb2")); 
    // // wifiUtilityBox->setBoxBorderMetricsHint(QskLinearBox::Panel, QskBoxBorderMetrics(2));
    // // wifiUtilityBox->setBoxBorderColorsHint(QskLinearBox::Panel, QskBoxBorderColors(Qt::white));
    // auto* activeWifiLabel = new QskTextLabel("Active WiFi: 4", wifiUtilityBox);
    // activeWifiLabel->setAlignment(Qt::AlignCenter);
    // auto* masterSwitchWifi = new QskPushButton("WiFi off", wifiUtilityBox);

    QskWindow window;
    window.addItem( verticalContainerBox );
    window.resize(1920, 1080);
    window.show();
 
    return app.exec();
}
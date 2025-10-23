#include "MySkinFactory.h"
#include <QskAspect.h>
#include <QskBox.h>
#include <QskBoxBorderMetrics.h>
#include <QskBoxShapeMetrics.h>
#include <QskFontRole.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskSkinFactory.h>
#include <QskSkin.h>
#include <QskSkinHintTableEditor.h>
#include <QskSkinnable.h>
#include <QskSlider.h>
#include <QskStateCombination.h>
#include <QskTextLabel.h>
#include <QskSwitchButton.h>
#include <QskGraphicLabel.h>
#include <QskMargins.h>
#include <QskColorFilter.h>
#include <QskRgbValue.h>
#include <qfont.h>
#include <qnamespace.h>
#include <qsize.h>

#include "TopBar.h"
#include "NavigationBox.h"
#include "MainPage.h"
#include "MyGraphicRole.h"
#include "SettingsPage.h"
MySkinFactory::MySkinFactory(QObject* parent) : QskSkinFactory(parent)
{

}

QStringList MySkinFactory::skinNames() const
{
    return {"DefaultSkin"};
}

QskSkin* MySkinFactory::createSkin(const QString& skinName)
{
    if(skinName == "DefaultSkin")
    {
        class DefaultSkin : public QskSkin
        {

            protected:
                void initHints() override
                {
                    QskSkinHintTableEditor e(&hintTable());
                    {
                        setupFontTable("System", false);

                        {
                            
                            //Change icon's color
                            QskColorFilter filterMainPage;
                            filterMainPage.addColorSubstitution(Qt::black, qRgb(138,155,161));
                            QskColorFilter filterTopBar;
                            filterTopBar.addColorSubstitution(Qt::black, qRgb(245,189,130));       

                            e.setGraphicRole(TopBarGraphicLabel::Graphic,  MimiGraphicRole::TopBar);
                            e.setGraphicRole(MainPageGraphicLabel::Graphic, MimiGraphicRole::MainPage);  
                            e.setGraphicRole(TopBarMenuButton::Icon, MimiGraphicRole::Default);

                            setGraphicFilter(MimiGraphicRole::MainPage, filterMainPage);
                            setGraphicFilter(MimiGraphicRole::TopBar, filterTopBar);
                            setGraphicFilter(MimiGraphicRole::Default, filterMainPage);
    
                            
                            //TopBar
                            e.setBoxShape(TopBar::Panel, QskBoxShapeMetrics(8));
                            e.setGradient(TopBar::Panel, QColor("#5a756e"), QColor("#8a9ba1"));
                            e.setPadding(TopBar::Panel, 5);
                            //TopBarMenuButton
                            e.setBoxShape(TopBarMenuButton::Panel, QskBoxShapeMetrics(8));
                            e.setGradient(TopBarMenuButton::Panel, QColor("#82f5d4"), QColor("#82d6f5"));
                            e.setGradient(TopBarMenuButton::Panel | TopBarMenuButton::Hovered, QColor("#82f5d4"));
                            e.setAnimation(TopBarMenuButton::Panel | QskAspect::Color, 100);

                            //NavigationButton
                            e.setBoxShape(NavigationButton::Panel, QskBoxShapeMetrics(8));
                            e.setGradient(NavigationButton::Panel, QColor("#82f5d4"), QColor("#82d6f5"));
                            e.setGradient(NavigationButton::Panel | NavigationButton::Hovered, QColor("#82f5d4"));
                            e.setAnimation(NavigationButton::Panel | QskAspect::Color, 100);
                        
                        }
                        
                        {   
                            // //ForMainPageGraphicLabel                            
                            // e.setBoxShape(MainPageGraphicLabel::Panel, 360);
                            // e.setGradient(MainPageGraphicLabel::Panel, QColor("#75645e"));
                            
                            //For MainPageTextLabel
                            e.setColor(MainPageTextLabel::Text, QColor("#5a756e"));
                            e.setFontRole(MainPageTextLabel::Text, {QskFontRole::Display, QskFontRole::VeryHigh});
                            e.setAlignment(MainPageTextLabel::Text, Qt::AlignCenter);
                            e.setPadding(MainPageTextLabel::Panel, QskMargins(25));

                            //For MainPagePushButton
                            e.setBoxShape(MainPagePushButton::Panel, 8);
                            e.setMetric(MainPagePushButton::Panel | QskAspect::Border, 2);
                            e.setGradient(MainPagePushButton::Panel | QskAspect::Border, QColor("#82f5d4"));
                            e.setGradient(MainPagePushButton::Panel, QColor("#8a9ba1"),QColor("#82d6f5"));
                            e.setGradient(MainPagePushButton::Panel | MainPagePushButton::Hovered, QColor("#82f5d4"));
                            e.setAnimation(MainPagePushButton::Panel | QskAspect::Color, 100);
                  

                            //For MainPageBannerBox -- banner
                            e.setGradient(MainPageBannerBox::Panel, QColor("#f5bd82"), QColor("#f5d682"));
                            e.setMargin(MainPageBannerBox::Panel, QskMargins(25));
                            e.setBoxBorderMetrics(MainPageBannerBox::Panel, QskBoxBorderMetrics(5));
                            e.setBoxShape(MainPageBannerBox::Panel, QskBoxShapeMetrics(8));
                            e.setGradient(MainPageBannerBox::Panel | QskAspect::Border, QColor("#f5bd82"));

                            
                            //For QskSwitchButton - Groove
                            const QSizeF  strutSize(300,100);
                            e.setStrutSize(QskSwitchButton::Groove | QskAspect::Horizontal, strutSize);
                            e.setStrutSize(QskSwitchButton::Groove | QskAspect::Vertical, strutSize.transposed());
                            e.setBoxShape(QskSwitchButton::Groove, 100, Qt::RelativeSize);
                            e.setBoxBorderMetrics(QskSwitchButton::Groove, 8);
                            e.setGradient(QskSwitchButton::Groove, QColor("#f5bd82"));


                            //For QskSwitchButton - Handle
                            e.setBoxShape(QskSwitchButton::Handle, 100, Qt::RelativeSize);
                            e.setPosition(QskSwitchButton::Handle, 0.1, {QskStateCombination::CombinationNoState, QskSwitchButton::Disabled});
                            e.setPosition(QskSwitchButton::Handle | QskSwitchButton::Checked, 0.9, {QskStateCombination::CombinationNoState, QskSwitchButton::Disabled});
                            e.setStrutSize(QskSwitchButton::Handle, 50, 50);
                            e.setGradient(QskSwitchButton::Handle, QColor("#82f5d4"));

                        }

                        {
                            //For RoomPage
                            //QskSlider
                            e.setGradient(QskSlider::Handle, QColor("#82f5d4"));
                            e.setGradient(QskSlider::Panel, QColor("#82d6f5"));
                            e.setBoxShape(QskSlider::Handle, QskBoxShapeMetrics(20));
                            e.setStrutSize(QskSlider::Handle, QSizeF(20,20));

                            //QskPushButton
                            e.setBoxShape(QskPushButton::Panel, QskBoxShapeMetrics(100));
                            e.setGradient(QskPushButton::Panel, QColor("#f5bd82"), QColor("#f5d682"));
                            e.setGradient(QskPushButton::Panel | QskPushButton::Pressed, QColor("#f5bd82"));
                            e.setGradient(QskPushButton::Panel | QskPushButton::Hovered, QColor("#f5d682"));
                            e.setAnimation(QskPushButton::Panel | QskAspect::Color, 100);  
                                                      
                        }

                        {
                            //For SettingsPage
                            e.setGradient(DragGraphicLabel::Panel, QColor("#82f5d4"), QColor("#82d6f5"));
                            // e.setStrutSize(DragGraphicLabel::Panel | QskAspect::Horizontal, QSizeF(10,10));
                            // e.setStrutSize(DragGraphicLabel::Panel | QskAspect::Vertical, QSizeF(10,10)); 
                            // e.setStrutSize(DragGraphicLabel::Graphic, QSizeF(10,10));
                            e.setBoxShape(DragGraphicLabel::Panel, 100);
                        }
                    }

                }

        };
        return new DefaultSkin();
    }

    return nullptr;
}

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
#include <QskTabBar.h>
#include <QskTabView.h>
#include <QskTabButton.h>
#include <QFontDatabase>
#include <qcontainerfwd.h>
#include <qfont.h>
#include <qfontdatabase.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qsize.h>

#include "TopBar.h"
#include "MainPage.h"
#include "MyGraphicRole.h"
#include "DragGraphicLabel.h"
#include "NavigationButton.h"
#include "TemperatureSlider.h"
#include "TemperatureButton.h"


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
                        
                        {
                            //SetupFont
                            const QString fontPath = QStringLiteral("fonts/Segoe UI.ttf");
                            int fontId = QFontDatabase::addApplicationFont(fontPath);

                            QStringList families = QFontDatabase::applicationFontFamilies(fontId);
                            
                            QString family = families.first();
                            
                            setupFontTable(family, false);
                            
                            // QFont appFont(family)
                            // setFont({QskFontRole::Display, QskFontRole::VeryHigh}, QFont(family, -1, QFont::DemiBold));

                            // QFont font(family, QFont::DemiBold);
                            // font.setItalic(false);
                            // font.setWeight(QFont::Normal);

                            // font.setPointSize(48);
                            // setFont({QskFontRole::Display, QskFontRole::VeryHigh}, font);
                        }


                        {
                            
                            //Change icon's color: rgb color obtained from converting hex to rgb via imagecolorpicker.com
                            QskColorFilter filterMainPage;
                            filterMainPage.addColorSubstitution(Qt::black, qRgb(138,155,161));
                            QskColorFilter filterTopBar;
                            filterTopBar.addColorSubstitution(Qt::black, qRgb(90,117,110));       

                            e.setGraphicRole(TopBarGraphicLabel::Graphic,  MimiGraphicRole::TopBar);
                            e.setGraphicRole(MainPageGraphicLabel::Graphic, MimiGraphicRole::MainPage);  
                            e.setGraphicRole(TopBarMenuButton::Icon, MimiGraphicRole::TopBar);

                            setGraphicFilter(MimiGraphicRole::MainPage, filterMainPage);
                            setGraphicFilter(MimiGraphicRole::TopBar, filterTopBar);
                            setGraphicFilter(MimiGraphicRole::Default, filterMainPage);
    
                            
                            //TopBar
                            e.setBoxShape(TopBar::Panel, QskBoxShapeMetrics(8));
                            e.setGradient(TopBar::Panel, QColor("#f5d682"), QColor("#f5bd82"));
                            e.setPadding(TopBar::Panel, 5);
                            //TopBarMenuButton
                            e.setBoxShape(TopBarMenuButton::Panel, QskBoxShapeMetrics(8));
                            e.setGradient(TopBarMenuButton::Panel, QColor("#82f5d4"), QColor("#82d6f5"));
                            e.setGradient(TopBarMenuButton::Panel | TopBarMenuButton::Hovered, QColor("#82f5d4"));
                            e.setAnimation(TopBarMenuButton::Panel | QskAspect::Color, 100);

                            //NavigationButton
                            e.setBoxShape(NavigationButton::Panel, QskBoxShapeMetrics(8));
                            e.setGradient(NavigationButton::Panel, QColor("#f5d682"), QColor("#f5bd82"));
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
                            e.setGradient(MainPageBannerBox::Panel, QColor("#f5d682"));
                            e.setMargin(MainPageBannerBox::Panel, QskMargins(25,10,25,10));
                            e.setPadding(MainPageBannerBox::Panel, QskMargins(25));
                            e.setBoxBorderMetrics(MainPageBannerBox::Panel, QskBoxBorderMetrics(5));
                            e.setBoxBorderMetrics(MainPageBannerBox::Panel | MainPageBannerBox::Hovered, QskBoxBorderMetrics(1));
                            e.setBoxShape(MainPageBannerBox::Panel, QskBoxShapeMetrics(8));
                            // e.setGradient(MainPageBannerBox::Panel | QskAspect::Border, QColor("#f5bd82"));
                            

                            //For MainPageSwitchButton - Groove
                            const QSizeF  strutSize(150,50);
                            e.setStrutSize(MainPageSwitchButton::Groove | QskAspect::Horizontal, strutSize);
                            e.setStrutSize(MainPageSwitchButton::Groove | QskAspect::Vertical, strutSize.transposed());
                            e.setBoxShape(MainPageSwitchButton::Groove, 100, Qt::RelativeSize);
                            e.setBoxBorderMetrics(MainPageSwitchButton::Groove, 8);
                            e.setGradient(MainPageSwitchButton::Groove, QColor("#f5bd82"));


                            //For MainPageSwitchButton - Handle
                            e.setBoxShape(MainPageSwitchButton::Handle, 100, Qt::RelativeSize);
                            e.setPosition(MainPageSwitchButton::Handle, 0.1, {QskStateCombination::CombinationNoState, MainPageSwitchButton::Disabled});
                            e.setPosition(MainPageSwitchButton::Handle | MainPageSwitchButton::Checked, 0.9, {QskStateCombination::CombinationNoState, MainPageSwitchButton::Disabled});
                            e.setStrutSize(MainPageSwitchButton::Handle, 25, 25);
                            e.setGradient(MainPageSwitchButton::Handle, QColor("#82f5d4"));

                        }

                        {
                            //For RoomPage
                            //TemperatureSlider - see example on how to skin this from QskSkinFluent2Skin.cpp
                            e.setGradient(TemperatureSlider::Handle, QColor("#82f5d4"));
                            e.setGradient(TemperatureSlider::Groove, QColor("#82d6f5"));
                            e.setGradient(TemperatureSlider::Tick, Qt::white);
                        
                            e.setBoxShape(TemperatureSlider::Handle, QskBoxShapeMetrics(20));
                            e.setStrutSize(TemperatureSlider::Handle, QSizeF(20,20));

                            const qreal size = 10.0;
                            e.setMetric( TemperatureSlider::Panel | QskAspect::Size, size );
                            e.setBoxShape( TemperatureSlider::Panel, 0 );
                            e.setBoxBorderMetrics( TemperatureSlider::Panel, 0 );
                            e.setPadding( TemperatureSlider::Panel | QskAspect::Horizontal, QskMargins( 0.5 * size, 0 ) );
                            e.setPadding( TemperatureSlider::Panel | QskAspect::Vertical, QskMargins( 0, 0.5 * size) );

                            for ( auto subControl : { TemperatureSlider::Groove, TemperatureSlider::Fill } )
                            {
                                e.setMetric( subControl | QskAspect::Size, 4.0 );
                                e.setBoxShape( subControl, 100, Qt::RelativeSize );
                            }

                            e.setFlag( TemperatureSlider::Tick | QskAspect::Option, Qsk::Maybe);
                            e.setStrutSize( TemperatureSlider::Tick | QskAspect::Horizontal, 2, -2);
                            e.setStrutSize( TemperatureSlider::Tick | QskAspect::Vertical, -2, 2 );

                            //LightIntensitySlider - see example on how to skin this from QskSkinFluent2Skin.cpp
                            e.setGradient(LightIntensitySlider::Handle, QColor("#82f5d4"));
                            e.setGradient(LightIntensitySlider::Groove, QColor("#82d6f5"));
                            e.setGradient(LightIntensitySlider::Tick, Qt::white);
                        
                            e.setBoxShape(LightIntensitySlider::Handle, QskBoxShapeMetrics(20));
                            e.setStrutSize(LightIntensitySlider::Handle, QSizeF(20,20));

                            // const qreal size = 10.0;
                            e.setMetric( LightIntensitySlider::Panel | QskAspect::Size, size );
                            e.setBoxShape( LightIntensitySlider::Panel, 0 );
                            e.setBoxBorderMetrics( LightIntensitySlider::Panel, 0 );
                            e.setPadding( LightIntensitySlider::Panel | QskAspect::Horizontal, QskMargins( 0.5 * size, 0 ) );
                            e.setPadding( LightIntensitySlider::Panel | QskAspect::Vertical, QskMargins( 0, 0.5 * size) );

                            for ( auto subControl : { LightIntensitySlider::Groove, LightIntensitySlider::Fill } )
                            {
                                e.setMetric( subControl | QskAspect::Size, 4.0 );
                                e.setBoxShape( subControl, 100, Qt::RelativeSize );
                            }

                            e.setFlag( LightIntensitySlider::Tick | QskAspect::Option, Qsk::Maybe);
                            e.setStrutSize( LightIntensitySlider::Tick | QskAspect::Horizontal, 2, -2);
                            e.setStrutSize( LightIntensitySlider::Tick | QskAspect::Vertical, -2, 2 );



                            //TemperatureButton
                            e.setBoxShape(SliderButtons::Panel, QskBoxShapeMetrics(50));
                            e.setGradient(SliderButtons::Panel, QColor("#f5d682"), QColor("#82f5d4"));
                            e.setGradient(SliderButtons::Panel | SliderButtons::Pressed, QColor("#82f5d4"));
                            e.setGradient(SliderButtons::Panel | SliderButtons::Hovered, QColor("#f5d682"));
                            e.setAnimation(SliderButtons::Panel | QskAspect::Color, 100); 
                            
                            //QskPushButton - on image
                            e.setBoxShape(QskPushButton::Panel, QskBoxShapeMetrics(50));
                            e.setGradient(QskPushButton::Panel, QColor("#f5bd82"), QColor("#f5d682"));
                            e.setGradient(QskPushButton::Panel | QskPushButton::Pressed, QColor("#f5bd82"));
                            e.setGradient(QskPushButton::Panel | QskPushButton::Hovered, QColor("#f5d682"));
                            e.setAnimation(QskPushButton::Panel | QskAspect::Color, 100); 

                                                      
                        }

                        {
                            //Based on example from FusionSkin
                            //TabButton
                            e.setStrutSize(QskTabButton::Panel, 30, 16);
                            e.setPadding(QskTabButton::Panel, QskMargins(3));
                            e.setBoxShape(QskTabButton::Panel, QskBoxShapeMetrics(10));
                            e.setBoxBorderMetrics(QskTabButton::Panel , 3);
                            e.setBoxBorderMetrics(QskTabButton::Panel | QskTabButton::Checked, 1);
                            e.setGradient(QskTabButton::Panel, QColor("#f5d682"));
                            e.setGradient(QskTabButton::Panel | QskTabButton::Checked, QColor("#f5bd82"));

                            //TabBar
                            // e.setMargin(QskTabBar::Panel, QskMargins(0,25,0,25));
                        }

                        {
                            //For SettingsPage
                            //For DragGraphicLabel
                            e.setGradient(DragGraphicLabel::Panel, QColor("#82f5d4"), QColor("#82d6f5"));
                            // e.setStrutSize(DragGraphicLabel::Panel,10,10);
                            // e.setStrutSize(DragGraphicLabel::Panel | QskAspect::Vertical, QSizeF(10,10).transposed()); 
                            // e.setStrutSize(DragGraphicLabel::Graphic, 10,10);
                            e.setBoxShape(DragGraphicLabel::Panel, 100);

                            //ForDropBox
                            // e.setMargin(DropBox::Panel,QskMargins(25,10,25,10));
                            // e.setGradient(DropBox::Panel,QColor("#f5bd82"));
                        }
                    }

                }

        };
        return new DefaultSkin();
    }

    return nullptr;
}

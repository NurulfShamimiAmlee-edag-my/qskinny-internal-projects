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
#include <QskShadowMetrics.h>
#include <QFontDatabase>
#include <qbrush.h>
#include <qcontainerfwd.h>
#include <qfont.h>
#include <qfontdatabase.h>
#include <qlogging.h>
#include <qnamespace.h>
#include <qsize.h>

#include "DiagramSkinlet.h"
#include "MainPageSwitchButton.h"
#include "TopBar.h"
#include "MainPage.h"
#include "MainPagePushButton.h"
#include "MyGraphicRole.h"
#include "DragGraphicLabel.h"
#include "NavigationButton.h"
#include "Sliders.h"
#include "SliderButtons.h"
#include "MasterSwitchButton.h"
#include "ImageButtons.h"
#include "UsageDiagram.h"

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
            public:
                DefaultSkin(QObject* parent = nullptr) : QskSkin(parent)
                {
                    declareSkinlet<Diagram, DiagramSkinlet>();
                }

                ~DefaultSkin() override {};
            
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
                            // e.setGradient(TopBar::Panel, QGradient::SoftCherish); -- if we like to use different gradient color :D

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
                            e.setBoxShape(MainPageBannerBox::Panel, QskBoxShapeMetrics(15));
                            QskShadowMetrics myShadowMetrics(-2, 8, { 0, 5 } );
                            myShadowMetrics.setShapeMode(QskShadowMetrics::Rectangle);
                            e.setShadowMetrics(MainPageBannerBox::Panel, myShadowMetrics);
                            e.setShadowColor(MainPageBannerBox::Panel, QColor("#8a9ba1"));
                            // e.setGradient(MainPageBannerBox::Panel | QskAspect::Border, QColor("#f5bd82"));
                            

                            //For MainPageSwitchButton - Groove
                            const QSizeF  strutSize(125,50);
                            e.setStrutSize(MainPageSwitchButton::Groove | QskAspect::Horizontal, strutSize);
                            e.setStrutSize(MainPageSwitchButton::Groove | QskAspect::Vertical, strutSize.transposed());
                            e.setBoxShape(MainPageSwitchButton::Groove, 100, Qt::RelativeSize);
                            e.setBoxBorderMetrics(MainPageSwitchButton::Groove, 5);
                            e.setGradient(MainPageSwitchButton::Groove, Qt::lightGray);
                            e.setGradient(MainPageSwitchButton::Groove | MainPageSwitchButton::Checked, QColor("#f5bd82"));


                            //For MainPageSwitchButton - Handle
                            e.setBoxShape(MainPageSwitchButton::Handle, 100, Qt::RelativeSize);
                            e.setBoxBorderMetrics(MainPageSwitchButton::Handle, 2);
                            e.setBoxBorderMetrics(MainPageSwitchButton::Handle | MainPageSwitchButton::Checked , 1);
                            e.setAnimation(MainPageSwitchButton::Handle | QskAspect::Metric, 100);
                            e.setPosition(MainPageSwitchButton::Handle, 0.1, {QskStateCombination::CombinationNoState, MainPageSwitchButton::Disabled});
                            e.setPosition(MainPageSwitchButton::Handle | MainPageSwitchButton::Checked, 0.9, {QskStateCombination::CombinationNoState, MainPageSwitchButton::Disabled});
                            e.setStrutSize(MainPageSwitchButton::Handle, 25, 25);
                            e.setGradient(MainPageSwitchButton::Handle, Qt::gray);
                            e.setGradient(MainPageSwitchButton::Handle | MainPageSwitchButton::Checked, QColor("#82f5d4"));

                        }

                        {
                            //For RoomPage
                            //Sliders - see example on how to skin this from QskSkinFluent2Skin.cpp
                            e.setGradient(Sliders::Handle, QColor("#82f5d4"));
                            e.setGradient(Sliders::Handle | Sliders::Disabled, Qt::lightGray);
                            e.setGradient(Sliders::Groove, QColor("#82d6f5"));
                            e.setGradient(Sliders::Groove | Sliders::Disabled, Qt::lightGray);                            
                            e.setGradient(Sliders::Tick, Qt::white);
                        
                            e.setBoxShape(Sliders::Handle, QskBoxShapeMetrics(20));
                            e.setStrutSize(Sliders::Handle, QSizeF(20,20));

                            const qreal size = 10.0;
                            e.setMetric( Sliders::Panel | QskAspect::Size, size );
                            e.setBoxShape( Sliders::Panel, 0 );
                            e.setBoxBorderMetrics( Sliders::Panel, 0 );
                            e.setPadding( Sliders::Panel | QskAspect::Horizontal, QskMargins( 0.5 * size, 0 ) );
                            e.setPadding( Sliders::Panel | QskAspect::Vertical, QskMargins( 0, 0.5 * size) );

                            for ( auto subControl : { Sliders::Groove, Sliders::Fill } )
                            {
                                e.setMetric( subControl | QskAspect::Size, 4.0 );
                                e.setBoxShape( subControl, 100, Qt::RelativeSize );
                            }

                            e.setFlag( Sliders::Tick | QskAspect::Option, Qsk::Maybe);
                            e.setStrutSize( Sliders::Tick | QskAspect::Horizontal, 2, -2);
                            e.setStrutSize( Sliders::Tick | QskAspect::Vertical, -2, 2 );


                            //SliderButtons
                            e.setBoxShape(SliderButtons::Panel, QskBoxShapeMetrics(50));
                            e.setGradient(SliderButtons::Panel, QColor("#f5d682"), QColor("#82f5d4"));
                            e.setGradient(SliderButtons::Panel | SliderButtons::Checked, QColor("#82f5d4"));
                            e.setGradient(SliderButtons::Panel | SliderButtons::Disabled, Qt::lightGray);
                            e.setGradient(SliderButtons::Panel | SliderButtons::Hovered, QColor("#f5d682"));
                            e.setAnimation(SliderButtons::Panel | QskAspect::Color, 100); 
                            
                            //ImageButtons - on image - has to be updated to ImageButtons
                            e.setBoxShape(ImageButtons::Panel, QskBoxShapeMetrics(50));
                            e.setGradient(ImageButtons::Panel, QColor("#f5bd82"), QColor("#f5d682"));
                            e.setGradient(ImageButtons::Panel | ImageButtons::Checked, QColor("#f5bd82"));
                            e.setGradient(ImageButtons::Panel | ImageButtons::Disabled, Qt::lightGray);
                            e.setGradient(ImageButtons::Panel | ImageButtons::Hovered, QColor("#f5d682"));
                            e.setAnimation(ImageButtons::Panel | QskAspect::Color, 100); 

                            //For MasterSwitchButton - Groove
                            const QSizeF  strutSize(59,30);
                            e.setStrutSize(MasterSwitchButton::Groove | QskAspect::Horizontal, strutSize);
                            e.setStrutSize(MasterSwitchButton::Groove | QskAspect::Vertical, strutSize.transposed());
                            e.setBoxShape(MasterSwitchButton::Groove, 100, Qt::RelativeSize);
                            e.setBoxBorderMetrics(MasterSwitchButton::Groove, 3);
                            e.setGradient(MasterSwitchButton::Groove, Qt::lightGray);
                            e.setGradient(MasterSwitchButton::Groove | MasterSwitchButton::Checked, QColor("#f5d682"));


                            //For MasterSwitchButton - Handle
                            e.setBoxShape(MasterSwitchButton::Handle, 100, Qt::RelativeSize);
                            e.setBoxBorderMetrics(MasterSwitchButton::Handle, 2);
                            e.setBoxBorderMetrics(MasterSwitchButton::Handle | MasterSwitchButton::Checked , 1);
                            e.setAnimation(MasterSwitchButton::Handle | QskAspect::Metric, 100);
                            e.setPosition(MasterSwitchButton::Handle, 0.1, {QskStateCombination::CombinationNoState, MasterSwitchButton::Disabled});
                            e.setPosition(MasterSwitchButton::Handle | MasterSwitchButton::Checked, 0.9, {QskStateCombination::CombinationNoState, MasterSwitchButton::Disabled});
                            e.setStrutSize(MasterSwitchButton::Handle, 15, 15);
                            e.setGradient(MasterSwitchButton::Handle, Qt::gray);
                            e.setGradient(MasterSwitchButton::Handle | MasterSwitchButton::Checked, QColor("#82f5d4"));

                                                      
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
                            //For SummaryPage
                            // diagram:
                            e.setBoxBorderMetrics( UsageDiagramBox::DaysBox, 0, 0, 3, 3 );
                            e.setFontRole( UsageDiagramBox::DayText, { QskFontRole::Caption, QskFontRole::Low } );

                            e.setStrutSize( UsageDiagramLegend::Symbol, 8, 8 );
                            e.setBoxShape( UsageDiagramLegend::Symbol, 100, Qt::RelativeSize ); // a circle
                            e.setGradient( UsageDiagramLegend::Symbol | UsageDiagramLegend::Water, { 0xff6776ff } );
                            e.setGradient( UsageDiagramLegend::Symbol | UsageDiagramLegend::Electricity, { 0xffff3122 } );
                            e.setGradient( UsageDiagramLegend::Symbol | UsageDiagramLegend::Gas, { 0xffff7d34 } );

                            e.setPadding( UsageDiagramBox::Panel, 0 );
                               
                            QskShadowMetrics shadowMetrics( 0, 10 );
                            e.setGradient( UsageDiagramBox::Panel, QGradient::CleanMirror );
                            e.setShadowMetrics( UsageDiagramBox::Panel, shadowMetrics );
                            e.setShadowColor( UsageDiagramBox::Panel, Qt::lightGray );

                            e.setColor(UsageDiagramBox::DaysBox | QskAspect::Border, Qt::white);
                            e.setColor( UsageDiagramBox::DayText, Qt::black);

                            // new diagram:
                            e.setColor( Diagram::ChartArea1, 0x666776ff );
                            e.setColor( Diagram::ChartArea2, 0x66ff3122 );
                            e.setColor( Diagram::ChartArea3, 0x66ff7d34 );

                            e.setColor( Diagram::ChartBar1, 0xff6776ff );
                            e.setColor( Diagram::ChartBar2, 0xffff3122 );
                            e.setColor( Diagram::ChartBar3, 0xffff7d34 );

                            e.setStrutSize( Diagram::ChartBar1, { 6, -1 } );
                            e.setStrutSize( Diagram::ChartBar2, { 6, -1 } );
                            e.setStrutSize( Diagram::ChartBar3, { 6, -1 } );

                            e.setBoxShape( Diagram::ChartBar1, { 3, 3, 0, 0 } );
                            e.setBoxShape( Diagram::ChartBar2, { 3, 3, 0, 0 } );
                            e.setBoxShape( Diagram::ChartBar3, { 3, 3, 0, 0 } );

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

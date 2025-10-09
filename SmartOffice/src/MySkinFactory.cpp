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
#include <QskTextLabel.h>
#include <QskGraphicLabel.h>
#include <QskMargins.h>
#include <QskColorFilter.h>
#include <QskRgbValue.h>
#include <qfont.h>
#include <qnamespace.h>

#include "TopBar.h"
#include "NavigationBox.h"
#include "MainPage.h"
#include "MyGraphicRole.h"
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

                            setGraphicFilter(MimiGraphicRole::MainPage, filterMainPage);
                            setGraphicFilter(MimiGraphicRole::TopBar, filterTopBar);
    
                            
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
                        
                        {   //For MainPageTextLabel
                            e.setShadowColor(MainPageTextLabel::Panel, QColor("#82f5d4"));
                            e.setMetric(MainPageTextLabel::Panel | QskAspect::Border, 2);
                            e.setFontRole(MainPageTextLabel::Text, QskFontRole::Title);
                            e.setBoxShape(MainPageTextLabel::Panel, 8);
                            e.setColor(MainPageTextLabel::Text, QColor("#5a756e"));
                            e.setGradient(MainPageTextLabel::Panel, QColor("#f5d682"));
                            e.setGradient(MainPageTextLabel::Panel | QskAspect::Border, QColor("#5a756e"));
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
                        }
                    }

                }

        };
        return new DefaultSkin();
    }

    return nullptr;
}

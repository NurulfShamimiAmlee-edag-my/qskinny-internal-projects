#include "MySkinFactory.h"
#include <QskAspect.h>
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
#include <qfont.h>
#include <qnamespace.h>

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
                        //For QskTextLabel
                        setupFontTable("System", false);
                        e.setShadowColor(QskTextLabel::Panel, QColor("#82f5d4"));
                        e.setMetric(QskTextLabel::Panel | QskAspect::Border, 2);
                        e.setFontRole(QskTextLabel::Text, QskFontRole::Title);
                        e.setBoxShape(QskTextLabel::Panel, 8);
                        e.setGradient(QskTextLabel::Panel, QColor("#f5d682"));
                        e.setGradient(QskTextLabel::Panel | QskAspect::Border, QColor("#5a756e"));
                        e.setAlignment(QskTextLabel::Text, Qt::AlignCenter);
                        e.setPadding(QskTextLabel::Panel, QskMargins(25));

                        //For QskPushButton
                        e.setBoxShape(QskPushButton::Panel, 8);
                        e.setMetric(QskPushButton::Panel | QskAspect::Border, 2);
                        e.setGradient(QskPushButton::Panel | QskAspect::Border, QColor("#82f5d4"));
                        e.setGradient(QskPushButton::Panel, QColor("#82d6f5"));
                        e.setGradient(QskPushButton::Panel | QskLinearBox::Hovered, QColor("#82f5d4"));
                        e.setAnimation(QskLinearBox::Panel | QskAspect::Color, 100);


                        //For QskGraphicLabel
                        e.setBoxShape(QskGraphicLabel::Panel, 8);
                        e.setMetric(QskGraphicLabel::Panel | QskAspect::Border, 2);
                        e.setGradient(QskGraphicLabel::Panel | QskAspect::Border, QColor("#5a756e"));
                        e.setGradient(QskGraphicLabel::Panel, QColor("#82f5d4")); 
                        // e.setColor(QskGraphicLabel::Graphic, QColor("#f5bd82")); //Does not work                    

                        //For QskLinearBox -- banner
                        e.setGradient(QskLinearBox::Panel, QColor("#f5d682"));
                        // e.setMetric(QskLinearBox::Panel | QskAspect::Border, 5);
                        // e.setGradient(QskLinearBox::Panel | QskAspect::Border, QColor("#f5d682"));
                    }

                }

        };
        return new DefaultSkin();
    }

    return nullptr;
}

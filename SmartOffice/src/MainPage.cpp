#include "MainPage.h"
#include "SingletonBannerDb.h"
#include <QskAspect.h>
#include <QskBoxBorderColors.h>
#include <QskBoxShapeMetrics.h>
#include <QskGradient.h>
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
#include <QskSwitchButton.h>
#include <QskTextLabel.h>
#include <QskBoxBorderMetrics.h>
#include <QskFontRole.h>
#include <QskTextOptions.h>
#include <QskSkinnable.h>
#include <QskGraphicIO.h>
#include <QskSkinManager.h>
#include <qbytearrayalgorithms.h>
#include <qnamespace.h>
#include <qquickitem.h>
#include <qsize.h>

QSK_SUBCONTROL(MainPageBannerBox, Panel)


MainPageBannerBox::MainPageBannerBox(QString labelText, SingletonBannerDb::BannerSlot slot) : QskLinearBox(), m_slot(slot)
{
    this->setOrientation(Qt::Vertical);
    this->setPanel(true);
    setAcceptHoverEvents(true);
    setSubcontrolProxy(QskLinearBox::Panel, Panel);
    
    m_graphicLabel = new MainPageGraphicLabel(SingletonBannerDb::instance().readBannerGraphic(m_slot), this);

    // connect to singleton changes 
    QObject::connect(&SingletonBannerDb::instance(), &SingletonBannerDb::bannerChanged,
                     this, [this](SingletonBannerDb::BannerSlot changedSlot, QskGraphic graphic) {
                         if (changedSlot == m_slot) {
                             m_graphicLabel->setGraphic(graphic);
                         }
                     });    

    m_bannerText = new MainPageTextLabel(labelText, this);

    m_switchButton = new MainPageSwitchButton(this);
    connect(m_switchButton, &MainPageSwitchButton::toggled, [this](bool checked)
    {
        
        //textLabel->setText(checked ? "0" : "Nothing") --> just another method to set text to 0 whenever button is toggled
        if (checked)
        {
            m_bannerText->setText("0");
        }
        // this->setDisabled(true); --> if we want to disable the switch is also possible 
    });
}

MainPageBannerBox::MainPageBannerBox() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    this->setPanel(true);
    setSubcontrolProxy(QskLinearBox::Panel, Panel);

}

void MainPageBannerBox::geometryChange(const QRectF &newGeometry, const QRectF &oldGeometry)
{
    //Use geometryChange to set banner box size instead of fixing it direectly using setFixeddSize
    QskLinearBox::geometryChange(newGeometry, oldGeometry);
    qreal smallestSide = qMin(width(), height());

    if (width() != height())
    {
        setSize(QSizeF(smallestSide, smallestSide));
    }

    // qDebug() << "Contents Rect in geometry change: " << contentsRect();
}


MainPage::MainPage() : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    auto* welcomeText = new QskTextLabel("Welcome!", this);//A place holder
    auto* hztlBx = new QskLinearBox(this);
    welcomeText->setFontRole({QskFontRole::Display, QskFontRole::High});
    welcomeText->setText("Hello!");
    welcomeText->setAlignment(Qt::AlignCenter);
    hztlBx->addItem(hztlBx);
    SingletonBannerDb::instance().dumpContents();
    hztlBx->addItem(new MainPageBannerBox("10", SingletonBannerDb::Slot1));
    SingletonBannerDb::instance().dumpContents();
    hztlBx->addItem(new MainPageBannerBox("5", SingletonBannerDb::Slot2));
    hztlBx->addItem(new MainPageBannerBox("5", SingletonBannerDb::Slot3));
}
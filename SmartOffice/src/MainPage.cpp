#include "MainPage.h"
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


MainPageBannerBox::MainPageBannerBox(QString labelText, QString path) : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    this->setPanel(true);
    setAcceptHoverEvents(true);
    setSubcontrolProxy(QskLinearBox::Panel, Panel);
    
    QskGraphic graphic = QskGraphicIO::read(path);
    auto* graphicLabel = new MainPageGraphicLabel(graphic, this);

    auto* textLabel = new MainPageTextLabel(labelText, this);

    auto* switchVerticalButton = new MainPageSwitchButton(this);
    connect(switchVerticalButton, &MainPageSwitchButton::toggled, [textLabel, this](bool checked)
    {
        
        //textLabel->setText(checked ? "0" : "Nothing") --> just another method to set text to 0 whenever button is toggled
        if (checked)
        {
            textLabel->setText("0");
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
    QskLinearBox::geometryChange(newGeometry, oldGeometry);
    qreal smallestSide = qMin(width(), height());

    if (width() != height())
    {
        setSize(QSizeF(smallestSide, smallestSide));
    }

    qDebug() << "Contents Rect in geometry change: " << contentsRect();
}


MainPage::MainPage() : QskLinearBox()
{
    this->setOrientation(Qt::Horizontal);
    this->addItem(new MainPageBannerBox("10", "assets/qvg/lamp.qvg"));
    this->addItem(new MainPageBannerBox("5", "assets/qvg/air-conditioner.qvg"));
    this->addItem(new MainPageBannerBox("5", "assets/qvg/wifi.qvg"));

}




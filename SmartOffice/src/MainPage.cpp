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

QSK_SUBCONTROL(MainPageTextLabel, Panel)
QSK_SUBCONTROL(MainPageTextLabel, Text)

QSK_SUBCONTROL(MainPagePushButton, Panel)
QSK_SUBCONTROL(MainPagePushButton, Text)

QSK_SUBCONTROL(MainPageGraphicLabel, Panel)

QSK_SUBCONTROL(MainPageBannerBox, Panel);

MainPageTextLabel::MainPageTextLabel(const QString& text, QQuickItem* parent) : QskTextLabel(text, parent)
{
    setSubcontrolProxy(QskTextLabel::Panel, Panel);
    setSubcontrolProxy(QskTextLabel::Text, Text);
}

MainPagePushButton::MainPagePushButton(const QString& text, QQuickItem* parent) : QskPushButton(text, parent)
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
    setSubcontrolProxy(QskPushButton::Text, Text);
}

MainPageGraphicLabel::MainPageGraphicLabel(const QskGraphic& graphic, QQuickItem* parent) : QskGraphicLabel(graphic, parent)
{
    setSubcontrolProxy(QskGraphicLabel::Panel, Panel);
    setSubcontrolProxy(QskGraphicLabel::Graphic, Graphic);
}

MainPageBannerBox::MainPageBannerBox(QString labelText, QString path, QString buttonText) : QskLinearBox()
{
    this->setOrientation(Qt::Vertical);
    this->setPanel(true);
    setSubcontrolProxy(QskLinearBox::Panel, Panel);
    
    QskGraphic graphic = QskGraphicIO::read(path);
    auto* graphicLabel = new MainPageGraphicLabel(graphic, this);
    graphicLabel->setFixedSize(200,200);
    graphicLabel->setLayoutAlignmentHint(Qt::AlignCenter);

    auto* textLabel = new MainPageTextLabel(labelText, this);
    textLabel->setLayoutAlignmentHint(Qt::AlignCenter);

    auto* masterButton = new MainPagePushButton(buttonText, this);
    masterButton->setFixedSize(180, 180);
    masterButton->setLayoutAlignmentHint(Qt::AlignCenter);

    connect(masterButton, &MainPagePushButton::clicked, [textLabel, this]()
    {
        textLabel->setText("0");
        this->setDisabled(true);
    });

    auto* switchVerticalButton = new QskSwitchButton(this);
    switchVerticalButton->setLayoutAlignmentHint(Qt::AlignCenter);
    connect(switchVerticalButton, &QskSwitchButton::toggled, [textLabel, this](bool checked)
    {
        textLabel->setText(checked ? "0" : "Nothing");
        this->setDisabled(true);
    });
}



MainPage::MainPage() : QskLinearBox()
{

    this->setOrientation(Qt::Horizontal);

    this->addItem(new MainPageBannerBox("10", "assets/qvg/lamp.qvg", "OFF"));
    this->addItem(new MainPageBannerBox("5", "assets/qvg/air-conditioner.qvg", "OFF"));
    this->addItem(new MainPageBannerBox("5", "assets/qvg/wifi-router.qvg", "OFF"));
}




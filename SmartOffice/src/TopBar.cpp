#include "TopBar.h"
#include <QskAspect.h>
#include <QskBoxShapeMetrics.h>
#include <QskGraphicLabel.h>
#include <QskGridBox.h>
#include <QskLinearBox.h>
#include <QskMargins.h>
#include <QskPushButton.h>
#include <QskSizePolicy.h>
#include <QskTextLabel.h>
#include <QskGraphic.h>
#include <QskGraphicIO.h>
#include <qcolor.h>
#include <qimage.h>
#include <qnamespace.h>
#include <QskColorFilter.h>
#include <QPainter>
#include "MyGraphicRole.h"

#include <iostream>
#include <qpixmap.h>

QSK_SUBCONTROL(TopBar, Panel)

QSK_SUBCONTROL(TopBarMenuButton, Panel)
QSK_SUBCONTROL(TopBarMenuButton, Text)

QSK_SUBCONTROL(TopBarGraphicLabel, Panel)
QSK_SUBCONTROL(TopBarGraphicLabel, Graphic)

TopBarMenuButton::TopBarMenuButton(): QskPushButton()
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
};

TopBarGraphicLabel::TopBarGraphicLabel(): QskGraphicLabel()
{
    setSubcontrolProxy(QskGraphicLabel::Panel, Panel);
    setSubcontrolProxy(QskGraphicLabel::Graphic, Graphic);
};

TopBar::TopBar(QQuickItem* parent) : QskLinearBox(parent)
{
    setSubcontrolProxy(QskLinearBox::Panel, Panel);
    
    this->setOrientation(Qt::Horizontal);
    this->setPanel(true);
    this->setFixedHeight(50);
    this->addItem(setGraphicLabel("assets/capybara.png"));  
    //TODO: Create a class that can use both logo and label -> label is used to display latest information
    this->addItem(setGraphicLabel("assets/qvg/thermometer-svgrepo-com.svg"));
    this->addItem(setGraphicLabel("assets/qvg/water.png"));
    this->addItem(setGraphicLabel("assets/qvg/electricity.png"));
    // this->addItem(setStatusLabels("Temperature"));
    // this->addItem(setStatusLabels("Humiditiy"));
    // this->addItem(setStatusLabels("Energy"));
    this->addItem(setMenuButton("assets/qvg/list.qvg"));
};

QskGraphicLabel* TopBar::setGraphicLabel (const QString& path)
{
    // QImage image(text);
    QPixmap image(path);
    // QskGraphic graphic = QskGraphic::fromImage(image);
    QskGraphic graphic = QskGraphic::fromPixmap(image);
    auto* graphicLabel = new QskGraphicLabel();
    // graphicLabel->setGraphicRole(MimiGraphicRole::Warning);
    // graphicLabel->setGradientHint(QskGraphicLabel::Graphic, Qt::magenta);
    graphicLabel->setGraphic(graphic);
    return graphicLabel;
}

QskTextLabel* TopBar::setStatusLabels(QString text)
{
    auto* statusLabel = new QskTextLabel(text);
    statusLabel->setPanel(true);
    statusLabel->setBoxShapeHint(QskTextLabel::Panel, QskBoxShapeMetrics(8));
    statusLabel->setPaddingHint(QskTextLabel::Panel, QskMargins(10));
    statusLabel->setGradientHint(QskTextLabel::Panel,  QColor("#70503fff"));
    statusLabel->setAlignment(Qt::AlignCenter);
    return statusLabel;
}

TopBarMenuButton* TopBar::setMenuButton(const QString& path)
{
    // auto* menuButton = new TopBarMenuButton();
    // QImage buttonImage(path);
    QskGraphic buttonGraphic = QskGraphicIO::read(path);
    m_menuButton->setIcon(buttonGraphic);
    m_menuButton->setIconStrutSize(QSizeF(25,25));
    // m_menuButton->setColor(TopBarMenuButton::Panel, QColor("#d6d4ad"));
    m_menuButton->setFixedSize(30,30);
    return m_menuButton;
}

TopBarMenuButton* TopBar::getMenuButton()
{
    return m_menuButton;
}
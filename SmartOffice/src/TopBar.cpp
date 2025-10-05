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
#include <qnamespace.h>

QSK_SUBCONTROL(TopBar, Panel)

QSK_SUBCONTROL(TopBarMenuButton, Panel)
QSK_SUBCONTROL(TopBarMenuButton, Text)

TopBarMenuButton::TopBarMenuButton(): QskPushButton()
{
    setSubcontrolProxy(QskPushButton::Panel, Panel);
};

TopBar::TopBar(QQuickItem* parent) : QskLinearBox(parent)
{
    setSubcontrolProxy(QskLinearBox::Panel, Panel);
    
    this->setOrientation(Qt::Horizontal);
    this->setPanel(true);
    this->setFixedHeight(50);
    this->addItem(setLogo("assets/capybara.png"));  
    //TODO: Create a class that can use both logo and label -> label is used to display latest information
    this->addItem(setLogo("assets/thermometer.png"));
    this->addItem(setLogo("assets/water.png"));
    this->addItem(setLogo("assets/electricity.png"));
    // this->addItem(setStatusLabels("Temperature"));
    // this->addItem(setStatusLabels("Humiditiy"));
    // this->addItem(setStatusLabels("Energy"));
    this->addItem(setMenuButton("assets/list.png"));
};

QskGraphicLabel* TopBar::setLogo(QString text)
{
    QImage companyLogo(text);
    QskGraphic companyGraphic = QskGraphic::fromImage(companyLogo);
    auto* companyLogoLabel = new QskGraphicLabel(companyGraphic);
    return companyLogoLabel;
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

TopBarMenuButton* TopBar::setMenuButton(QString text)
{
    // auto* menuButton = new TopBarMenuButton();
    QImage buttonImage(text);
    QskGraphic buttonGraphic = QskGraphic::fromImage(buttonImage);
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
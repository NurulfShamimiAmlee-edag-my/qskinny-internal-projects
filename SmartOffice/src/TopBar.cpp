#include "TopBar.h"
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

TopBar::TopBar(QQuickItem* parent) : QskLinearBox(parent)
{
    this->setOrientation(Qt::Horizontal);
    // this->setSpacing(200);
    this->setPanel(true);
    this->setBoxShapeHint(QskLinearBox::Panel, QskBoxShapeMetrics(8));
    this->setGradientHint(QskLinearBox::Panel,  QColor("#8a9ba1"));
    this->setFixedHeight(50);
    this->setPaddingHint(QskLinearBox::Panel, 5);
    this->addItem(setLogo("assets/capybara.png"));  
    //TODO: Create a class that can use both logo and label -> label is used to display latest information
    this->addItem(setLogo("assets/thermometer.png"));
    this->addItem(setLogo("assets/water.png"));
    this->addItem(setLogo("assets/electricity.png"));
    // this->addItem(setStatusLabels("Temperature"));
    // this->addItem(setStatusLabels("Humiditiy"));
    // this->addItem(setStatusLabels("Energy"));
    this->addItem(setMenuButton("assets/app.png"));
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

QskPushButton* TopBar::setMenuButton(QString text)
{
    // auto* menuButton = new QskPushButton();
    QImage buttonImage(text);
    QskGraphic buttonGraphic = QskGraphic::fromImage(buttonImage);
    m_menuButton->setIcon(buttonGraphic);
    m_menuButton->setIconStrutSize(QSizeF(25,25));
    m_menuButton->setColor(QskPushButton::Panel, QColor("#d6d4ad"));
    // QObject::connect(menuButton, &QskPushButton::clicked, [bottomSection](){
    //     bottomSection->setCurrentIndex(3);
    // });
    return m_menuButton;
}

QskPushButton* TopBar::getMenuButton()
{
    return m_menuButton;
}
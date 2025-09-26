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
    this->setColor(QskLinearBox::Panel,  QColor("#af7178"));
    this->setFixedHeight(50);
    this->setPaddingHint(QskLinearBox::Panel, 5);
    this->addItem(setCompanyLogo("assets/capybara.png"));  
    this->addItem(setStatusLabels("Temperature"));
    this->addItem(setStatusLabels("Humiditiy"));
    this->addItem(setStatusLabels("Energy"));
    this->addItem(setMenuButton("assets/app.png"));
};

QskGraphicLabel* TopBar::setCompanyLogo(QString text)
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
    statusLabel->setColor(QskTextLabel::Panel,  QColor("#70503fff"));
    statusLabel->setAlignment(Qt::AlignCenter);
    return statusLabel;
}

QskPushButton* TopBar::setMenuButton(QString text)
{
    auto* menuButton = new QskPushButton();
    QImage buttonImage(text);
    QskGraphic buttonGraphic = QskGraphic::fromImage(buttonImage);
    menuButton->setIcon(buttonGraphic);
    menuButton->setIconStrutSize(QSizeF(25,25));
    return menuButton;
}
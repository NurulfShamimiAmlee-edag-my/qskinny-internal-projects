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


QSK_SUBCONTROL(TopBar, Panel)


TopBar::TopBar(QQuickItem* parent) : QskLinearBox(parent)
{
    setSubcontrolProxy(QskLinearBox::Panel, Panel);
    
    this->setOrientation(Qt::Horizontal);
    this->setPanel(true);
    this->addItem(setGraphicLabel("assets/qvg/capybara.qvg"));  
    //TODO: Create a class that can use both logo and label -> label is used to display latest information
    this->addItem(setGraphicLabel("assets/qvg/thermometer-svgrepo-com.qvg"));
    this->addItem(setGraphicLabel("assets/qvg/water.qvg"));
    this->addItem(setGraphicLabel("assets/qvg/electricity.qvg"));
    this->addItem(setMenuButton("assets/qvg/list.qvg"));

};

TopBarGraphicLabel* TopBar::setGraphicLabel (const QString& path)
{
    QskGraphic graphic = QskGraphicIO::read(path);
    auto* graphicLabel = new TopBarGraphicLabel();
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
    QskGraphic buttonGraphic = QskGraphicIO::read(path);
    m_menuButton->setIcon(buttonGraphic);
    m_menuButton->setIconStrutSize(QSizeF(20,20)); //Strutsize of the icon actually influence the size of all property in TopBar box... interesting
    //TODO: Figure out a better size policy so that the size of the box is not dependent on the icon strut size?

    return m_menuButton;
}

TopBarMenuButton* TopBar::getMenuButton()
{
    return m_menuButton;
}
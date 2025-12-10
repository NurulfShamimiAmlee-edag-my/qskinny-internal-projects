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
#include <qmargins.h>
#include <qnamespace.h>
#include <QskColorFilter.h>
#include <QPainter>
#include <qtimer.h>


#include "MyGraphicRole.h"
#include "TopBarMenuButton.h"


QSK_SUBCONTROL(TopBar, Panel)


TopBar::TopBar(QQuickItem* parent) : QskLinearBox(parent)
{
    setSubcontrolProxy(QskLinearBox::Panel, Panel);
    setFixedHeight(50);
    setPadding(QMarginsF(24,10,24,10));

    
    this->setOrientation(Qt::Horizontal);
    this->setPanel(true);
    this->addItem(setGraphicLabel(":/assets/qvg/edag-logo.qvg"));  
    //TODO: Create a class that can use both logo and label -> label is used to display latest information
    this->addItem(setGraphicLabel(":/assets/qvg/thermometer-svgrepo-com.qvg"));
    this->addItem(setGraphicLabel(":/assets/qvg/water.qvg"));
    this->addItem(setGraphicLabel(":/assets/qvg/electricity.qvg"));
    this->addItem(setClockAndDate());
    this->addItem(setMenuButton(":/assets/qvg/list.qvg"));

};

void TopBar::geometryChange(const QRectF& newGeometry, const QRectF& oldGeometry)
{
    QskLinearBox::geometryChange(newGeometry, newGeometry);

    // qDebug()<< "Contenst Rect of TopBar" << contentsRect() ;
}

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
    m_menuButton = new TopBarMenuButton();
    m_menuButton->setIcon(buttonGraphic);
    m_menuButton->setIconStrutSize(QSizeF(24,24)); //Strutsize of the icon actually influence the size of all property in TopBar box... interesting
    //TODO: Figure out a better size policy so that the size of the box is not dependent on the icon strut size?

    return m_menuButton;
}

QskLinearBox* TopBar::setClockAndDate()
{
    setMargins(2,0,2,0);//TODO: No margin top and bottom, left and right have margin -- not the final solution
    m_dateAndClockBox = new QskLinearBox(Qt::Horizontal);
    m_dateLabel = new QskTextLabel(QDate::currentDate().toString(Qt::DateFormat::TextDate), this);
    m_timeLabel = new QskTextLabel(QTime::currentTime().toString("hh:mm:ss"),this);
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, [this](){
        const QString t = QTime::currentTime().toString("hh:mm:ss");
        m_timeLabel->setText(t);
        m_dateLabel->setText(QDate::currentDate().toString(Qt::DateFormat::ISODate));
    });
    m_timer->start(1000);

    return m_dateAndClockBox;
}

TopBarMenuButton* TopBar::getMenuButton()
{
    return m_menuButton;
}
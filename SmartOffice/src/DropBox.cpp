#include "DropBox.h"
#include "MainPageSwitchButton.h"
#include "SingletonBannerDb.h"

#include <QskBoxShapeMetrics.h>
#include <QskGraphic.h>
#include <QskGraphicIO.h>
#include <QskLinearBox.h>
#include <qnamespace.h>
#include <qtimer.h>

DropBox::DropBox(const SingletonBannerDb::BannerSlot& slot) : MainPageBannerBox(), m_slot(slot)
{
    // setFlags(QFlag(Qt::ItemIsDropEnabled));
    setAutoLayoutChildren(true);
    m_graphicLabel = new MainPageGraphicLabel(SingletonBannerDb::instance().readBannerGraphic(m_slot),this);
    m_bannerText = new MainPageTextLabel("0",this);
    m_switchButton = new MainPageSwitchButton(this);

}

bool DropBox::containsPoint(const QPointF &point) const
{
    return (point.x() >= 0 && point.x() <= width() && point.y() >= 0 && point.y() <= height());
}

void DropBox::handleDrop(QskGraphic labelGraphic)
{
    m_graphicLabel->setGraphic(labelGraphic);
    SingletonBannerDb::instance().changeBannerGraphic(m_slot, labelGraphic);
    SingletonBannerDb::instance().dumpContents();

}

void DropBox::flashBackground(const QColor& color)
{
    QColor originalColor = this->color(QskBox::Background);
    setBackgroundColor(color);
    QTimer::singleShot(300, this, [this, originalColor](){
        setBackgroundColor(originalColor);
    });

}
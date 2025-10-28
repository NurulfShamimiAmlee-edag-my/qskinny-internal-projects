#include "DropBox.h"
#include <QskGraphic.h>
#include <qtimer.h>

DropBox::DropBox() : QskLinearBox()
{
    setFlags(QFlag(Qt::ItemIsDropEnabled));
    setAutoLayoutChildren(true);
    setPanel(true);
    setBackgroundColor(QColor("#f5bd82"));
    // setMargins(25);
    // m_label = new QskTextLabel("Drop Area", this);
    // m_graphicLabel = new MainPageGraphicLabel(this);
    m_label = new MainPageTextLabel("Drop Area",this);
    // m_label->setTextColor(QColor("#5a756e"));
    // m_label->setAlignment(Qt::AlignCenter);m,.

}

bool DropBox::containsPoint(const QPointF &point) const
{
    return (point.x() >= 0 && point.x() <= width() && point.y() >= 0 && point.y() <= height());
}

void DropBox::handleDrop(QskGraphic labelGraphic)
{
    m_label->setText("0");
    // flashBackground(QColor("#b9fbc0"));
    //TODO: Modify this so that a banner is created instead.
    // m_graphicLabel->setGraphic(labelGraphic);
    // addItem(new MainPageBannerBox("0", "assets/qvg/air-conditioner.qvg"));


}

void DropBox::flashBackground(const QColor& color)
{
    QColor originalColor = this->color(QskBox::Background);
    setBackgroundColor(color);
    QTimer::singleShot(300, this, [this, originalColor](){
        setBackgroundColor(originalColor);
    });

}
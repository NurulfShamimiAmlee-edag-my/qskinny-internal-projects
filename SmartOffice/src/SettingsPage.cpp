#include "SettingsPage.h"
#include <QGuiApplication>
#include <QMimeData>
#include <QDrag>
#include <QskEvent.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <QskBox.h>
#include <QskGraphic.h>
#include <QskGraphicIO.h>
#include <QTimer>
#include <QStyleHints>
#include <qdrag.h>
#include <qevent.h>
#include <qguiapplication.h>
#include <qicon.h>
#include <qmimedata.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpoint.h>
#include <qstringliteral.h>
#include <iostream>

QSK_SUBCONTROL(DragGraphicLabel, Panel)
QSK_SUBCONTROL(DragGraphicLabel, Graphic)

DropBox::DropBox() : QskBox()
{
    setFlags(QFlag(Qt::ItemIsDropEnabled));
    setAutoLayoutChildren(true);
    setPanel(true);
    setBackgroundColor(QColor("#f5bd82"));
    setMargins(25);
    m_label = new QskTextLabel("Drop Area", this);
    m_label->setTextColor(QColor("#5a756e"));
    m_label->setAlignment(Qt::AlignCenter);

}

bool DropBox::containsPoint(const QPointF &point) const
{
    return (point.x() >= 0 && point.x() <= width() && point.y() >= 0 && point.y() <= height());
}

void DropBox::handleDrop(const QString &text)
{
    m_label->setText(QStringLiteral("Dropped: %1").arg(text));
    flashBackground(QColor("#b9fbc0"));
}

void DropBox::flashBackground(const QColor& color)
{
    QColor originalColor = this->color(QskBox::Background);
    setBackgroundColor(color);
    QTimer::singleShot(300, this, [this, originalColor](){
        setBackgroundColor(originalColor);
    });

}

DragGraphicLabel::DragGraphicLabel( QString graphicPath, DropBox* targetArea) : QskGraphicLabel(), m_targetArea(targetArea)
{
    setSubcontrolProxy(QskGraphicLabel::Panel, Panel);
    setSubcontrolProxy(QskGraphicLabel::Graphic, Graphic);

    setPanel(true);
    setFixedSize(100,100);

    QskGraphic graphic = QskGraphicIO::read(graphicPath);
    setGraphic(graphic);

    setFocusPolicy(Qt::StrongFocus);
    setAcceptedMouseButtons(Qt::AllButtons);

    setLayoutAlignmentHint(Qt::AlignCenter);
    setAlignment(Qt::AlignCenter);

}

void DragGraphicLabel::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_startPos = e->position();
        m_initPos = position();
        m_dragging = true;

        setZ(1000);
    }

    QskGraphicLabel::mousePressEvent(e);
}

void DragGraphicLabel::mouseMoveEvent(QMouseEvent* e)
{
    if(m_dragging == false)
    {
        return;
    }

    if((e->position() - m_startPos).manhattanLength() < QGuiApplication::styleHints()->startDragDistance())
    {
        return;
    }

    QPointF delta = e->position() - m_startPos;
    setPosition(position() + delta);
    m_startPos = e->position();
}

void DragGraphicLabel::mouseReleaseEvent(QMouseEvent* e)
{
    if((m_dragging) && (e->button() == Qt::LeftButton))
    {
        m_dragging = false;
        setZ(0);
    }

    QPointF center = mapToItem(m_targetArea, QPointF(width()/2, height()/2));

    if (m_targetArea->containsPoint(center))
    {
        m_targetArea->handleDrop("Dropped");
    }

    setPosition(m_initPos);

}

SettingsPage::SettingsPage() : QskLinearBox()
{
    setOrientation(Qt::Vertical);
    auto* dropBox = new DropBox();
    this->addItem(dropBox);

    //DragGraphicLabelArea
    auto* DragGraphicLabelsBox = new QskLinearBox(Qt::Vertical);
    DragGraphicLabelsBox->setPanel(true);
    DragGraphicLabelsBox->setColor(QskLinearBox::Panel, QColor("#f5d682"));
    // DragGraphicLabelsBox->setMargins(25);

    for (int row = 0 ; row < 2; row++)
    {
        auto* horizontalDragGraphicLabelsBox = new QskLinearBox(Qt::Horizontal);
        if(row == 0)
        {
            auto* acDragGraphicLabel = new DragGraphicLabel("assets/qvg/air-conditioner.qvg", dropBox);
            auto* wifiDragGraphicLabel = new DragGraphicLabel("assets/qvg/wifi-router.qvg", dropBox);
            auto* lightDragGraphicLabel =  new DragGraphicLabel("assets/qvg/lamp.qvg", dropBox);

            horizontalDragGraphicLabelsBox->addItem(acDragGraphicLabel);
            horizontalDragGraphicLabelsBox->addItem(wifiDragGraphicLabel);
            horizontalDragGraphicLabelsBox->addItem(lightDragGraphicLabel);
        }
        else
        {
            auto* blindDragGraphicLabel = new DragGraphicLabel("assets/qvg/window.qvg", dropBox);
            auto* temperatureDragGraphicLabel = new DragGraphicLabel("assets/qvg/thermometer-svgrepo-com.qvg", dropBox);
            auto* plugPointDragGraphicLabel =  new DragGraphicLabel("assets/qvg/socket.qvg", dropBox);

            horizontalDragGraphicLabelsBox->addItem(blindDragGraphicLabel);
            horizontalDragGraphicLabelsBox->addItem(temperatureDragGraphicLabel);
            horizontalDragGraphicLabelsBox->addItem(plugPointDragGraphicLabel);

        }

        DragGraphicLabelsBox->addItem(horizontalDragGraphicLabelsBox);
    }
    // this->addItem(new DragGraphicLabel("Test drag label", dropBox));
    this->addItem(DragGraphicLabelsBox);

}

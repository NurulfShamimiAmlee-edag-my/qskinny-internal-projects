#include "DragGraphicLabel.h"
#include "SingletonBannerDb.h"

#include <QskGraphicIO.h>
#include <QskGraphic.h>
#include <QGuiApplication>
#include <QStyleHints>

QSK_SUBCONTROL(DragGraphicLabel, Panel)
QSK_SUBCONTROL(DragGraphicLabel, Graphic)

DragGraphicLabel::DragGraphicLabel( QString graphicPath, const QVector<DropBox*> &targetAreas) : QskGraphicLabel(), m_targetAreas(targetAreas)
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
    QskGraphicLabel::mouseMoveEvent(e);
}

void DragGraphicLabel::mouseReleaseEvent(QMouseEvent* e)
{
    if((m_dragging) && (e->button() == Qt::LeftButton))
    {
        m_dragging = false;
        setZ(0);

        qreal cx = width() * 0.5;
        qreal cy = height() * 0.5;

        bool handled = false;
        for (DropBox *d : m_targetAreas)
        {
            if (!d)
            {
                continue;
            }
            QPointF centerInTarget = mapToItem(d, QPointF(cx, cy));
            if (d->containsPoint(centerInTarget))
            {
                d->handleDrop(this->graphic());
                handled = true;
                break;
            }
        }

        setPosition(m_initPos);
        // setDisabled(true); //so that user won't try to the label multiple times
    }

    QskGraphicLabel::mouseReleaseEvent(e);

    


    //Example for one target drop area only
    // QPointF center = mapToItem(m_targetArea, QPointF(width()/2, height()/2));
    // if (m_targetArea->containsPoint(center))
    // {
    //     m_targetArea->handleDrop("Dropped");
    // }
    // setPosition(m_initPos);

}
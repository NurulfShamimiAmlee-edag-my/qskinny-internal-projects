#include "SettingsPage.h"
#include <QGuiApplication>
#include <QMimeData>
#include <QDrag>
#include <QskEvent.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <QskBox.h>
#include <QTimer>
#include <QStyleHints>
#include <qdrag.h>
#include <qevent.h>
#include <qguiapplication.h>
#include <qmimedata.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qobjectdefs.h>
#include <qpoint.h>
#include <qstringliteral.h>
#include <iostream>


DropBox::DropBox() : QskBox()
{
    setFlags(QFlag(Qt::ItemIsDropEnabled));
    setPanel(true);
    setBackgroundColor(Qt::white);
    m_label = new QskTextLabel("Drop Area", this);
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

DragLabel::DragLabel(const QString &text, DropBox* targetArea) : QskTextLabel(text), m_targetArea(targetArea)
{
    this->setPanel(true);
    setBackgroundColor(Qt::magenta);
    setFocusPolicy(Qt::StrongFocus);
    setAcceptedMouseButtons(Qt::AllButtons);
}

void DragLabel::mousePressEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton)
    {
        m_startPos = e->position();
        m_initPos = position();
        m_dragging = true;

        setZ(1000);
    }

    QskTextLabel::mousePressEvent(e);
}

void DragLabel::mouseMoveEvent(QMouseEvent* e)
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

void DragLabel::mouseReleaseEvent(QMouseEvent* e)
{
    if((m_dragging) && (e->button() == Qt::LeftButton))
    {
        m_dragging = false;
        setZ(0);
    }

    QPointF center = mapToItem(m_targetArea, QPointF(width()/2, height()/2));

    if (m_targetArea->containsPoint(center))
    {
        m_targetArea->handleDrop(text());
    }

    setPosition(m_initPos);

}

SettingsPage::SettingsPage() : QskLinearBox()
{
    auto* settingPagePlaceHolder = new QskTextLabel("Settings Page placeholder");
    auto* dropBox = new DropBox();
    this->addItem(settingPagePlaceHolder);
    this->addItem(new DragLabel("Test drag label", dropBox));
    this->addItem(dropBox);
}

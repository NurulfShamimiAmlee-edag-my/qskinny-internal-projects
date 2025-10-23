#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QskGraphicLabel.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <qevent.h>
#include <qtmetamacros.h>

class DropBox : public QskBox
{
    Q_OBJECT
    
    private:
        QskTextLabel* m_label = nullptr;
        void flashBackground(const QColor& color);
    public:
        DropBox();
        bool containsPoint(const QPointF &point) const;
        void handleDrop(const QString& text);
        
};


class DragGraphicLabel : public QskGraphicLabel
{
    Q_OBJECT
    private:
        QPointF m_startPos;
        QPointF m_initPos;
        bool m_dragging = false;
        DropBox* m_targetArea = nullptr;
    
    public:
        QSK_SUBCONTROLS(Panel, Graphic)
        DragGraphicLabel(QString graphicPath, DropBox* m_targetArea);
    protected:
        void mousePressEvent(QMouseEvent* e) override;
        void mouseMoveEvent(QMouseEvent* e) override;
        void mouseReleaseEvent(QMouseEvent* e) override;
};

class SettingsPage : public QskLinearBox
{
    public:
        SettingsPage();
};

#endif //SETTINGSPAGE_Hl
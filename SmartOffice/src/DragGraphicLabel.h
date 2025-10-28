#ifndef DRAGGRAPHICLABEL_H
#define DRAGGRAPHICLABEL_H

#include <QskGraphicLabel.h>

#include "DropBox.h"

class DragGraphicLabel : public QskGraphicLabel
{
    Q_OBJECT
    private:
        QPointF m_startPos;
        QPointF m_initPos;
        bool m_dragging = false;
        // DropBox* m_targetArea = nullptr;
        QVector<DropBox*> m_targetAreas;
    
    public:
        QSK_SUBCONTROLS(Panel, Graphic)
        DragGraphicLabel(QString graphicPath, const QVector<DropBox*> &targetAreas);
    protected:
        void mousePressEvent(QMouseEvent* e) override;
        void mouseMoveEvent(QMouseEvent* e) override;
        void mouseReleaseEvent(QMouseEvent* e) override;
};


#endif  //DRAGGRAPHICLABEL_H
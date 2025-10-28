#ifndef DROPBOX_H
#define DROPBOX_H

#include <QskLinearBox.h>

#include "MainPageGraphicLabel.h"
#include "MainPageTextLabel.h"

class DropBox : public QskLinearBox
{
    Q_OBJECT
    
    private:
        MainPageTextLabel* m_label = nullptr;
        MainPageGraphicLabel* m_graphicLabel = nullptr;
        void flashBackground(const QColor& color);
    public:
        DropBox();
        bool containsPoint(const QPointF &point) const;
        void handleDrop(QskGraphic labelGraphic);
        
};


#endif //DROPBOX_H
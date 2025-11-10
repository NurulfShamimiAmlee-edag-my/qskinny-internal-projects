#ifndef DROPBOX_H
#define DROPBOX_H

#include <QskLinearBox.h>

#include "MainPageGraphicLabel.h"
#include "MainPageTextLabel.h"
#include "SingletonBannerDb.h"
#include "MainPage.h"

class DropBox : public MainPageBannerBox
{
    Q_OBJECT
    
    private:
        bool m_bannerChanged;
        SingletonBannerDb::BannerSlot m_slot;
    
    private:
        // MainPageTextLabel* m_label = nullptr;
        // MainPageGraphicLabel* m_graphicLabel = nullptr;
        void flashBackground(const QColor& color);
    public:
        DropBox(const SingletonBannerDb::BannerSlot& slot);
        bool containsPoint(const QPointF &point) const;
        void handleDrop(QskGraphic labelGraphic);
        
};


#endif //DROPBOX_H
#ifndef PAGEVIEWER_H
#define PAGEVIEWER_H

#include <QskLinearBox.h>
class PageViewer : public QskLinearBox
{
    private:
        int m_totalPage = 0;

    public:
        PageViewer();
};


#endif //PAGEVIEWER_H
#ifndef ROOMPAGETAB_H
#define ROOMPAGETAB_H

#include <QskTabView.h>

#include "RoomPage.h"

class RoomPageTab : public QskTabView
{
    private:
        QVector<RoomPage*> m_roomPages;
    
    public:
        RoomPageTab();
        void addRoomPage(RoomPage* roomPage);
};


#endif //ROOMPAGETAB_H
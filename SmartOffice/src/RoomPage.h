#ifndef ROOMPAGE_H
#define ROOMPAGE_H

#include <QskLinearBox.h>
class RoomPage : public QskLinearBox
{
    private:
        void setButtonOnImage(int row, int column);
        void setSliderUtility();
        void setRoomName(QString text);
        QskGraphic createGraphic(QString text);
        
    public:
        RoomPage();
        int getActiveUtility();
        int getRoomName();
};

#endif //ROOMPAGE_H
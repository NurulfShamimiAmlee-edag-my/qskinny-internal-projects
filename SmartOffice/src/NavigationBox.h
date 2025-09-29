#ifndef NAVIGATIONBOX_H
#define NAVIGATIONBOX_H

#include <QskLinearBox.h>
#include <QskPushButton.h>
class  NavigationBox : public QskLinearBox
{
    public:
        QskPushButton* m_nextButton = new QskPushButton(">");
        QskPushButton* m_previousButton = new QskPushButton("<");
    
    public:
        NavigationBox();
};


#endif //NAVIGATIONBOX_H
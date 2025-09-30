#ifndef NAVIGATIONBOX_H
#define NAVIGATIONBOX_H

#include <QskLinearBox.h>
#include <QskPushButton.h>
class  NavigationBox : public QskLinearBox
{
    private:
        QskPushButton* m_nextButton = new QskPushButton(">");
        QskPushButton* m_previousButton = new QskPushButton("<");
    
    public:
        NavigationBox();
        QskPushButton* getNextButton();
        QskPushButton* getPreviousButton();
};


#endif //NAVIGATIONBOX_H
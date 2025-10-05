#ifndef NAVIGATIONBOX_H
#define NAVIGATIONBOX_H

#include <QskAspect.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>

class NavigationButton : public QskPushButton
{
    public:
        QSK_SUBCONTROLS(Panel, Text);
        NavigationButton(QString text);
};

class  NavigationBox : public QskLinearBox
{
    private:
        //TODO: Replace text with icon?
        NavigationButton* m_nextButton = new NavigationButton(">");
        NavigationButton* m_previousButton = new NavigationButton("<");
    
    public:
        NavigationBox();
        NavigationButton* getNextButton();
        NavigationButton* getPreviousButton();
};


#endif //NAVIGATIONBOX_H
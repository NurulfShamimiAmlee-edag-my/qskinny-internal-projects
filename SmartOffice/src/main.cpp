#include <QskScrollView.h>
#include <QskWindow.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h>
#include <QskGridBox.h>
#include <QGuiApplication>


 
int main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );
 
    auto* verticalContainerBox = new QskLinearBox( Qt::Vertical );
    
    verticalContainerBox->setPanel( true );

    QskWindow window;
    window.addItem( verticalContainerBox );
    window.show();
 
    return app.exec();
}
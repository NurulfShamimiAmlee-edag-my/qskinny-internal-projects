#include <QskAspect.h>
#include <QskMargins.h>
#include <QskScrollView.h>
#include <QskSkinnable.h>
#include <QskWindow.h>
#include <QskLinearBox.h>
#include <QskPushButton.h>
#include <QskTextLabel.h>
#include <QskGridBox.h>
#include <QskBoxBorderMetrics.h>
#include <QskBoxBorderColors.h>
#include <QskBoxShapeMetrics.h>
#include <QskStackBox.h>
#include <QskBoundedValueInput.h>
#include <QskFontRole.h>
#include <QskSkinManager.h>
#include <QGuiApplication>
#include <qevent.h>
#include <qnamespace.h>

/* My Classes */
#include "PageViewer.h"
#include "MySkinFactory.h"


int main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );

    qskSkinManager->registerFactory("MySkinFactory", new MySkinFactory());
    qskSkinManager->setSkin("DefaultSkin");
    
    QskWindow window;
    window.addItem(new PageViewer());
    // window.addItem( verticalContainerBox );
    window.resize(1920, 1080);
    // window.resize(1024, 600);
    window.show();
 
    return app.exec();
}
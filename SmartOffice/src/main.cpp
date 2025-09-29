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
#include <QGuiApplication>
#include <qevent.h>
#include <qnamespace.h>

#include "PageViewer.h"


int main( int argc, char* argv[] )
{
    QGuiApplication app( argc, argv );
 
    QskWindow window;
    window.addItem(new PageViewer());
    // window.addItem( verticalContainerBox );
    window.resize(1920, 1080);
    window.show();
 
    return app.exec();
}
#include "UsageBox.h"

#include <QskFontRole.h>
#include <QskTextLabel.h>

// QSK_SUBCONTROL( UsageBox, Separator )

namespace
{
    class UsageLine : public QskLinearBox
    {
      public:
        UsageLine( const QString& info, const QString& value, QQuickItem* parent )
            : QskLinearBox( Qt::Horizontal, parent )
        {
            auto infoLabel = new QskTextLabel( info, this );
            infoLabel->setFontRole( QskFontRole::Body );

            auto separator = new QskTextLabel( "_____", this );

            auto valueLabel = new QskTextLabel( value, this );
            valueLabel->setFontRole( QskFontRole::Body );
        }
    };
}

UsageBox::UsageBox( QQuickItem* parent )
    : QskLinearBox(Qt::Vertical, parent)
{
    auto title = new QskTextLabel("Usage", this);
    title->setFontRole(QskFontRole::Body);
    
    ( void ) new UsageLine( "Usage today", "0,5 kwH", this );
    ( void ) new UsageLine( "Usage this month", "66 kwH", this );
    ( void ) new UsageLine( "Total working hours", "125 hrs", this );
}
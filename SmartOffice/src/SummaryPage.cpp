#include  "SummaryPage.h"
#include <QskLinearBox.h>
#include <QskTextLabel.h>


SummaryPage::SummaryPage() : QskLinearBox()
{
    auto* summaryPagePlaceHolder = new QskTextLabel("Summary Page Place Holder");
    this->addItem(summaryPagePlaceHolder);
}
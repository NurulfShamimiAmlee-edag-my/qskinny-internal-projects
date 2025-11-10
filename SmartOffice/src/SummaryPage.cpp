#include  "SummaryPage.h"
#include "UsageDiagram.h"
#include <QskFontRole.h>
#include <QskLinearBox.h>
#include <QskTextLabel.h>
#include <qnamespace.h>


SummaryPage::SummaryPage() : QskLinearBox()
{
    setOrientation(Qt::Vertical);
    auto* verticalSummaryBox = new QskLinearBox(Qt::Vertical, this);

    auto* energyConsumptionBox = new QskLinearBox(Qt::Vertical, verticalSummaryBox);
    auto* energyConsumptionLabel = new QskTextLabel("Energy Consumption", energyConsumptionBox);
    energyConsumptionLabel->setFontRole({QskFontRole::Title, QskFontRole::High});

    energyConsumptionBox->addItem(new UsageDiagramBox(QString(), new UsageDiagram()));
    // auto* waterConsumptionBox = new QskLinearBox(Qt::Vertical, verticalSummaryBox);
    // auto* waterConsumptionLabel = new QskTextLabel("Water Consumption", waterConsumptionBox);  
    // waterConsumptionLabel->setFontRole({QskFontRole::Title, QskFontRole::High});
}
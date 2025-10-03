#ifndef MYSKINFACTORY_H
#define MYSKINFACTORY_H

#include <QskSkinFactory.h>

class MySkinFactory : public QskSkinFactory
{
    Q_OBJECT

    public:
        MySkinFactory(QObject* parent = nullptr);
        QStringList skinNames() const override;
        QskSkin* createSkin(const QString& skinName) override;
};


#endif //MYSKINFACTORY_H
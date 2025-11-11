#pragma once

#include <QMap>
#include <QObject>
#include <QskGraphic.h>
#include <qnamespace.h>


class SingletonBannerDb : public QObject
{
    Q_OBJECT

    public:
        enum BannerSlot
        {
            Slot1 = 0,
            Slot2,
            Slot3
        };

    private:
        SingletonBannerDb() = default; // a private constructor
        QMap<BannerSlot, QskGraphic> m_bannerBoxGraphic;
        explicit SingletonBannerDb(QObject* parent = nullptr);

    public:
        SingletonBannerDb(const SingletonBannerDb& other) = delete;
        void operator = (const SingletonBannerDb &) = delete;
        static SingletonBannerDb& instance(); //object can only be created once
        void changeBannerGraphic(const BannerSlot& slot, const QskGraphic& bannerIcon);//for drop area to change?
        const QskGraphic& readBannerGraphic(const BannerSlot& slot) const; //for MainPage to read from
        void dumpContents() const; //debugging only
    signals:
        void bannerChanged(SingletonBannerDb::BannerSlot slot, const QskGraphic& bannerIcon); //signal so that MainPage has to read everytime signal is emitted?

};
/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -c DBusUpdateJob -p dbusupdatejob com.deepin.lastore.Job.xml
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUSUPDATEJOB_H_1446176044
#define DBUSUPDATEJOB_H_1446176044

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

/*
 * Proxy class for interface com.deepin.lastore.Job
 */
class DBusUpdateJob: public QDBusAbstractInterface
{
    Q_OBJECT

    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName !="com.deepin.lastore.Job")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        QStringList keys = changedProps.keys();
        foreach(const QString &prop, keys) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
 	            Q_EMIT p.notifySignal().invoke(this);
                }
            }
        }
   }
public:
    static inline const char *staticInterfaceName()
    { return "com.deepin.lastore.Job"; }

public:
    DBusUpdateJob(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~DBusUpdateJob();

    Q_PROPERTY(qlonglong CreateTime READ createTime NOTIFY CreateTimeChanged)
    inline qlonglong createTime() const
    { return qvariant_cast< qlonglong >(property("CreateTime")); }

    Q_PROPERTY(QString Description READ description NOTIFY DescriptionChanged)
    inline QString description() const
    { return qvariant_cast< QString >(property("Description")); }

    Q_PROPERTY(int ElapsedTime READ elapsedTime NOTIFY ElapsedTimeChanged)
    inline int elapsedTime() const
    { return qvariant_cast< int >(property("ElapsedTime")); }

    Q_PROPERTY(QString Id READ id NOTIFY IdChanged)
    inline QString id() const
    { return qvariant_cast< QString >(property("Id")); }

    Q_PROPERTY(QString PackageId READ packageId NOTIFY PackageIdChanged)
    inline QString packageId() const
    { return qvariant_cast< QString >(property("PackageId")); }

    Q_PROPERTY(double Progress READ progress NOTIFY ProgressChanged)
    inline double progress() const
    { return qvariant_cast< double >(property("Progress")); }

    Q_PROPERTY(QString Status READ status NOTIFY StatusChanged)
    inline QString status() const
    { return qvariant_cast< QString >(property("Status")); }

    Q_PROPERTY(QString Type READ type NOTIFY TypeChanged)
    inline QString type() const
    { return qvariant_cast< QString >(property("Type")); }

public Q_SLOTS: // METHODS
Q_SIGNALS: // SIGNALS
    void Notify(int in0);
// begin property changed signals
void CreateTimeChanged();
void DescriptionChanged();
void ElapsedTimeChanged();
void IdChanged();
void PackageIdChanged();
void ProgressChanged();
void StatusChanged();
void TypeChanged();
};

namespace org {
  namespace deepin {
    namespace lastore {
      typedef ::DBusUpdateJob Job;
    }
  }
}
#endif

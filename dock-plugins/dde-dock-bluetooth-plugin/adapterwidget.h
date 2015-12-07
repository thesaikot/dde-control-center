#ifndef ADAPTERWIDGET_H
#define ADAPTERWIDGET_H

#include <QWidget>

#include <libdui/dlistwidget.h>
#include <libdui/dloadingindicator.h>
#include <libdui/dswitchbutton.h>
#include <libdui/dseparatorhorizontal.h>
#include <libdui/darrowlineexpand.h>
#include <libdui/dlabel.h>
#include <libdui/dboxwidget.h>

#include "bluetoothobject.h"

DUI_USE_NAMESPACE

class AdapterWidget : public DVBoxWidget
{
    Q_OBJECT
public:
    explicit AdapterWidget(BluetoothObject::AdapterInfo *info,
                           QWidget *parent = 0);
    ~AdapterWidget();

    void addDevice(BluetoothObject::DeviceInfo *info);
    void removeDevice(BluetoothObject::DeviceInfo *info, bool isDelete);

public slots:
    void updateUI();

private:
    void initUI();

    DListWidget *m_deviceItemList = nullptr;
    DSeparatorHorizontal *m_listWidgetSeparator = nullptr;
    BluetoothObject::AdapterInfo *m_info = nullptr;
    DHeaderLine *m_headerLine;
    DSwitchButton *m_bluetoothSwitch;
};

#endif // ADAPTERWIDGET_H
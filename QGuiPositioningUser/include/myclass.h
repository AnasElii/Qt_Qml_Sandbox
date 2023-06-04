#ifndef MYCLASS_H
#define MYCLASS_H

#include "pch.h"
#include <winrt/Windows.Devices.Geolocation.Geofencing.h>
#include <iostream>
#include <objbase.h>

#include <QObject>
#include <qqmlintegration.h>

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Devices::Geolocation;

class MyClass : public QObject
{
    Q_OBJECT
public:
	explicit MyClass(QObject *parent = nullptr);

	void myFunction();
public slots:
	void myFunctionHelper();

signals:

};

#endif // MYCLASS_H

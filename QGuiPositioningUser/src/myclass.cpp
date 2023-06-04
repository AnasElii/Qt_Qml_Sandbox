#include "myclass.h"

MyClass::MyClass(QObject *parent)
    : QObject{parent}
{

}

void MyClass::myFunction()
{
    // Call this function using Qt::BlockingQueuedConnection
    QMetaObject::invokeMethod(this, "myFunctionHelper", Qt::QueuedConnection);
}

void MyClass::myFunctionHelper() {
    // Code that uses COM goes here
    CoInitialize(NULL);

    

    CoUninitialize();
}
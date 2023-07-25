#include <QCoreApplication>

#include "customclass.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CustomClass *grandParent = new CustomClass();
    grandParent->setObjectName("GrandParent");

    CustomClass *parent = new CustomClass(grandParent);
    parent->setObjectName("Parent");

    CustomClass *child = new CustomClass(parent);
    child->setObjectName("Child 1");

    CustomClass *child2 = new CustomClass(parent);
    child2->setObjectName("Child 2");

    CustomClass *child3 = new CustomClass();
    child3->setObjectName("Child 3");
    child3->setParent(parent);

    grandParent->dumpObjectTree();

    delete grandParent;

    return a.exec();
}
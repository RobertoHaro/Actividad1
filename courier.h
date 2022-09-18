#ifndef COURIER_H
#define COURIER_H

#include "packageList.h"
#include "packagenode.h"
#include "package.h"

class Courier{

private:
    PackageList* packageListRef;

    void pause();

    void mainMenu();

    void addPackage();

    void deleteOnePackage();

    void showAllPackages();

    void deleteAllPackages();

    void writeToDisk();

    void readFromDisk();


public:
    Courier(PackageList*);
};

#endif // COURIER_H

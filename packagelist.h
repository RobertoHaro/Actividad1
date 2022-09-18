#ifndef PACKAGELIST_H
#define PACKAGELIST_H

#include <string>
#include <fstream>
#include <iostream>
#include <istream>

#include "package.h"
#include "packagenode.h"
#include "listexception.h"

class PackageList{

private:
    PackageNode* anchor;

    bool isValidPos(PackageNode*);

    void copyAll(const PackageList&);

public:
    PackageList();
    PackageList(const PackageList&);

    ~PackageList();

    bool isEmpty();

    void insertData(PackageNode*, const Package&);
    void insertFirst(const Package&);
    void insertOrdered(const Package&);
    void deleteData();

    void deleteAll();

    PackageNode* getFirstPos();
    PackageNode* getLastPos();
    PackageNode* getNextPos(PackageNode*);
    PackageNode* getPrevPos(PackageNode*);

    PackageNode* findData(const Package&);

    Package retrieve(PackageNode*);

    std::string toString()const;

    void writeToDisk(const std::string&);
    void readFromDisk(const std::string&);

    PackageList& operator = (const PackageList&);

};

#endif // PACKAGELIST_H

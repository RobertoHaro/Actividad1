#ifndef PACKAGENODE_H
#define PACKAGENODE_H

#include "package.h"

class PackageNode{
private:
    Package data;
    PackageNode* next;

public:
    PackageNode();
    PackageNode(const Package&);

    Package& getData();
    PackageNode* getNext();

    void setData(const Package&);
    void setNext(PackageNode*);
};

#endif // PACKAGENODE_H

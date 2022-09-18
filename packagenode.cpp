#include "packagenode.h"

PackageNode::PackageNode() :next(nullptr){ }

PackageNode::PackageNode(const Package& e) : data(e), next(nullptr){ }

Package& PackageNode::getData(){
    return data;
}

PackageNode* PackageNode::getNext(){
    return next;
}

void PackageNode::setData(const Package& e){
    data = e;
}

void PackageNode::setNext(PackageNode* p){
    next = p;
}

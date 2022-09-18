#include "packagelist.h"

using namespace std;

bool PackageList::isValidPos(PackageNode* p){
    PackageNode* aux(anchor);

    while(aux != nullptr){
        if(aux == p){
            return true;
        }

        aux = aux->getNext();
    }

    return false;
}

PackageList::PackageList() : anchor(nullptr){ }

bool PackageList::isEmpty(){
    return anchor == nullptr;
}

string PackageList::toString()const{

    PackageNode* aux(anchor);
    string result;

    result += " |-------------------------------------------------------|";
    result += "\n";
    result += " | ID   | Origen          | Destino         | Peso(Kg)   |";
    result += "\n";
    result += " |------|-----------------|-----------------|------------|";

    result += "\n";
    while(aux != nullptr){
        result += aux->getData().toString();
        result += "\n";

        aux = aux->getNext();
    }
    result += " |-------------------------------------------------------|";
    result += "\n";
    return result;
}

void PackageList::insertData(PackageNode* p, const Package& e){
    if(p!=nullptr and !isValidPos(p)){
        throw ListException("Posicion invalida, tratando de insertar");
    }

    PackageNode* aux(new PackageNode(e));

    if(aux == nullptr){
        throw ListException("Memoria no disponible, tratando de insertar");
    }

    if(p == nullptr){
        aux->setNext(anchor);

        anchor = aux;
    }
    else{
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
}

void PackageList::insertFirst(const Package& e){

    PackageNode* aux(new PackageNode(e));

    if(aux == nullptr){
        throw ListException("Memoria no disponible, tratando de insertar");
    }

    aux->setNext(anchor);
    anchor = aux;

}

void PackageList::insertOrdered(const Package& e){
    PackageNode* aux(anchor);
    PackageNode* p(nullptr); //es el nodo anterior para saber donde colocarlo

    while(aux != nullptr){
        p = aux;
        aux = aux->getNext();
    }

    insertData(p, e);
}

PackageNode* PackageList::getPrevPos(PackageNode* p){
    if(p == anchor or !isValidPos(p)){
        return nullptr;
    }

    PackageNode* aux(anchor); //el auxiliar es un apuntador que se inicializa con el ancla

    while(aux->getNext() != p){ //empieza un recorrido de lista
        aux = aux->getNext();
    }
    return aux;
}

void PackageList::deleteData(){
    PackageNode* aux;

    aux = anchor;
    anchor = anchor->getNext();

    delete aux;
}

PackageNode* PackageList::findData(const Package& e){
    PackageNode* aux(anchor);

    while(aux != nullptr and aux->getData() != e){
        aux = aux->getNext();
    }

    return aux;
}

void PackageList::deleteAll(){

   PackageNode* aux;

   while (anchor != nullptr){
        aux = anchor;

        anchor = anchor->getNext();

        delete aux;
   }
}

PackageList::~PackageList(){
    deleteAll();
}

void PackageList::copyAll(const PackageList& l){
    PackageNode* aux(l.anchor);
    PackageNode* last(nullptr);
    PackageNode* newNode;

    while(aux != nullptr){
        newNode = new PackageNode(aux->getData());
        if(newNode == nullptr){
            throw ListException("Memoria no disponible, copyAll");
        }
        if(last == nullptr){
            anchor = newNode;
        }else{
            last->setNext(newNode);
        }
        last = newNode;
        aux = aux->getNext();
    }
}

PackageList::PackageList(const PackageList& l) : PackageList(){
    copyAll(l);
}

PackageNode* PackageList::getFirstPos(){
    return  anchor;
}

PackageNode* PackageList::getLastPos(){
    if(isEmpty()){
        return nullptr;
    }

    PackageNode* aux(anchor);

    while(aux->getNext() != nullptr){
        aux = aux->getNext();
    }

    return aux;
}

PackageNode* PackageList::getNextPos(PackageNode* p){
    if(!isValidPos(p)){
        return nullptr;
    }

    return p->getNext();
}

Package PackageList::retrieve(PackageNode* p){
    if(!isValidPos(p)){
        throw ListException("Posicion invalida, retrieve");
    }
    return p->getData();
}

PackageList& PackageList::operator = (const PackageList& l){
    deleteAll();
    copyAll(l);
    return *this;
}

void PackageList::writeToDisk(const std::string& fileName){
    ofstream myFile;

    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open()){
        string msg("No se pudo abrir el archivo ");
        msg+= fileName;
        msg += " para escritura, PackageList::writeToDisk";
        throw ListException(msg);
    }

    PackageNode* aux(anchor);

    while(aux != nullptr){
        myFile << aux->getData() << endl;

        aux = aux->getNext();
    }

    myFile.close();
}

void PackageList::readFromDisk(const std::string& fileName){
    ifstream myFile;

    myFile.open(fileName);

    if(!myFile.is_open()){
        string msg("No se pudo abrir el archivo ");
        msg+= fileName;
        msg += " para lectura, PackageList::readFromDisk";

        throw ListException(msg);
    }

    deleteAll();

    Package myPackage;
    PackageNode* lastNode(nullptr);
    PackageNode* newNode;

    while(myFile >> myPackage){
        if((newNode = new PackageNode(myPackage)) == nullptr){ ///= new PackageNode ) == nullptr){
            myFile.close();

            throw ListException("Memoria no disponible, readFromDisk");
        }

        if(lastNode == nullptr){
            anchor = newNode;
        }
        else{
            lastNode->setNext(newNode);
        }

        lastNode = newNode;
    }

    myFile.close();
}

#include "package.h"
#include <string>

using namespace std;

Package::Package(){}

Package::Package(const Package& p) : id(p.id), origin(p.origin), destiny(p.destiny), weight(p.weight) { }

string Package::getId() const{
    return id;
}

string Package::getOrigin() const{
        return origin;
}

string Package::getDestiny() const{
    return destiny;
}

string Package::getWeight() const{
    return weight;
}

void Package::setId(const string& i){
    id = i;
}

void Package::setOrigin(const string& o){
    origin = o;
}

void Package::setDestiny(const string& d){
    destiny = d;
}

void Package::setWeight(const string& w){
    weight = w;
}

string Package::toString(){
    string result;
    string aux;


    result += " | ";

    aux = id;
    aux.resize(4,' ');
    result += aux;

    result += " | ";

    aux = origin;
    aux.resize(15,' ');
    result += aux;

    result += " | ";

    aux = destiny;
    aux.resize(15,' ');
    result += aux;

    result += " | ";

    aux = weight;
    aux.resize(10,' ');
    result += aux;

    result += " | ";

    return result;
}

Package& Package::operator=(const Package& p){
    id = p.id;
    origin = p.origin;
    destiny = p.destiny;
    weight = p.weight;
    return *this;
}

bool Package::operator==(const Package& p) const{
    return id == p.id;
}

bool Package::operator!=(const Package& p) const{
    return id != p.id;
}

bool Package::operator<(const Package& p) const{
    return id < p.id;
}

bool Package::operator<=(const Package& p) const{
    return id <= p.id;
}

bool Package::operator>(const Package& p) const{
    return id < p.id;
}

bool Package::operator>=(const Package& p) const{
    return id >= p.id;
}

istream& operator >> (istream& is, Package& p){
    getline(is, p.id);
    getline(is, p.origin);
    getline(is, p.destiny);
    getline(is, p.weight);

    return is;
}

ostream& operator << (ostream& os, Package& p){

    os << p.id << endl;
    os << p.origin << endl;
    os << p.destiny << endl;
    os << p.weight;

    return os;
}

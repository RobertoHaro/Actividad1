#ifndef PACKAGE_H
#define PACKAGE_H
#include <string>
#include <iostream>

class Package
{
private:
    std::string id;
    std::string origin;
    std::string destiny;
    std::string weight;

public:
    Package();
    Package(const Package&);

    std::string getId() const;
    std::string getOrigin() const;
    std::string getDestiny() const;
    std::string getWeight() const;

    void setId(const std::string&);
    void setOrigin(const std::string&);
    void setDestiny(const std::string&);
    void setWeight(const std::string&);

    std::string toString();

    Package& operator = (const Package&);

    bool operator == (const Package&) const;
    bool operator != (const Package&) const;
    bool operator < (const Package&) const;
    bool operator <= (const Package&) const;
    bool operator > (const Package&) const;
    bool operator >= (const Package&) const;

    friend std::istream& operator >> (std::istream&, Package&);
    friend std::ostream& operator << (std::ostream&, Package&);
};

#endif // PACKAGE_H

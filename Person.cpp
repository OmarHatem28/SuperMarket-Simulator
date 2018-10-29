#include "Person.h"

Person::Person()
{
    //ctor
}

Person::~Person()
{
    //dtor
}
Person::Person(string n , string add)
{

}

void Person::setname(string n )
{
    Name = n ;
}
string Person::getname()
{
    return Name;
}

void Person::setaddress(string add)
{
    Address = add ;
}
string Person::getaddress()
{
    return Address;
}

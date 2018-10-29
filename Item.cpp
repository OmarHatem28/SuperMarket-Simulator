#include "Item.h"
#include <iostream>

using namespace std;

Item::Item()
{

}
Item::~Item()
{

}
Item::Item(string _name,string _type,int _amount,int _price)
{
  name = _name;
  type = _type;
  availamount = _amount;
  price = _price;
}

string Item::getName()
{
    return name;
}
string Item::getType()
{
    return type;
}
int Item::getAvailamount()
{
    return availamount;
}
int Item::getPrice()
{
    return price;
}
int Item::getID()
{
    return ID;
}

void Item::setAvailamount(int newAmount)
{
    availamount = newAmount;
}
void Item::setPrice(int newPrice)
{
    price = newPrice;
}
void Item::setitemid(int x)
{
    ID=x;
}

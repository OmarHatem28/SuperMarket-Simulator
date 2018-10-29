#include "Stock.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

Stock::Stock()
{
    sizeofitem = getLineNum();
    items = new Item[sizeofitem];
    loadStock();
}
int Stock::getLineNum(){

  int counter=0;
    string line;
    ifstream file("Input.txt");
    while(getline(file,line))
        {counter++;}
        return counter;
}
void Stock::updatestock()
{
    sizeofitem = getLineNum();
    items = new Item[sizeofitem];
    loadStock();
}
int Stock::getsizeofitem()
{
    return sizeofitem;
}

Stock::~Stock()
{
}


void Stock::loadStock()
{
    int counter=0;
    string line;
    ifstream file("Input.txt");


    while(getline(file,line))
    {
        int coma[3];
        int indexComa=0;

        for (int i=0;i < line.length();i++)
        {

            if(line[i] == ',')
            {
                    coma[indexComa]=i;
                    indexComa++;
            }
        }

         string name = line.substr(0,coma[0]);
         string type = line.substr(coma[0]+1,coma[1]-coma[0]-1);
         string amount = line.substr(coma[1]+1,coma[2]-coma[1]-1);
         string price = line.substr(coma[2]+1);
         int finalPrice = atoi(price.c_str());
         int finalAmount = atoi(amount.c_str());
         Item obj(name, type, finalAmount, finalPrice);
         items[counter] = obj;
         counter++;
    }
    for ( int i=0;i<sizeofitem;i++){
        items[i].setitemid(i+1);
    }
}
void Stock::savestock()
{
    ofstream file("Input.txt",ios::out);
    for(int i=0;i<sizeofitem;i++){
        file <<items[i].getName()<<", "<<items[i].getType()<<", "<<items[i].getAvailamount()<<", "<<items[i].getPrice()<<endl;
    }
}

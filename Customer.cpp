#include "Customer.h"
#include "Administrator.h"
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int Customer::Counter =0;
int Customer::TotalCounter=0;
Customer::Customer()
{

}

Customer::~Customer()
{
    Counter=0;
}

void Customer::setID()
{
    Counter++;
    TotalCounter++;
    ostringstream ss;
    ID="Customer";
    ss<<Counter;
    ID+=ss.str();
    setArrivalTime();
    setShoppingDuration();
    setCheckOutTime();
    BuyItems();
}
string Customer::getID()
{
    return ID;
}

void Customer::setArrivalTime()
{
    time_t now = time(0);

    // convert now to string form
    char* date = ctime(&now);
    // take only the hours and minutes from the whole date
    char h1=date[11];
    char h2=date[12];
    char m1=date[14];
    char m2=date[15];
    int arrhour=((int(h1)-48)*10)+(int(h2)-48);
    int arrminutes=((int(m1)-48)*10)+(int(m2)-48);
    if ( arrminutes > 59 ){
            arrminutes-=60;
            arrhour++;
    }
    if ( arrhour > 12 ){
        arrhour-=12;
    }
    ArrivalTime.sethours(arrhour);
    ArrivalTime.setminutes(arrminutes);
}
MyTime Customer::getArrivalTime()
{
    return ArrivalTime;
}
void Customer::setShoppingDuration()
{
    int ranhours=rand()%(4)+1;
    int ranminutes=rand()%(59)+1;
    ShoppingDuration.sethours(ranhours);
    ShoppingDuration.setminutes(ranminutes);
}
MyTime Customer::getShoppingDuration()
{
    return ShoppingDuration;
}
void Customer::setCheckOutTime()
{
    CheckOutTime=ArrivalTime+ShoppingDuration;
}
MyTime Customer::getCheckOutTime()
{
    return CheckOutTime;
}
int Customer::getCounter()
{
    return Counter;
}
int Customer::getTotalCounter()
{
    return TotalCounter;
}
void Customer::BuyItems()
{
    obj.updatestock();
    for ( int i=0;;i++){
        int choice;
        cout<<"=============================================================================="<<endl;
        cout<<endl<<setw(10)<<"Name"<<setw(15)<<"Type"<<setw(20)<<"Amount"<<setw(16)<<"Price"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        for ( int i=0;i<obj.getsizeofitem();i++){
            cout<<i+1<<"-"<<setw(7)<<obj.items[i].getName()<<setw(16);
            cout<<obj.items[i].getType()<<setw(16);
            cout<<obj.items[i].getAvailamount()<<setw(16)<<obj.items[i].getPrice()<<setw(2)<<"L.E"<<endl;
        }
        cout<<"Please select from the following menu the items "<<getID();
        cout<<" want to buy or 0 to end: "<<endl;
        cin>>choice;
        if ( choice == 0 )
            break;
        itemind[i]=choice;
        int amm;
        cout<<"What is the amount that you want from item "<<obj.items[choice-1].getName()<<": ";
        cin>>amm;
        if ( amm > obj.items[choice-1].getAvailamount() ){
            cout<<"Not Enough Items"<<endl;
            itemind[i]=0;
            i--;
        }
        else{
            obj.items[choice-1].setAvailamount(obj.items[choice-1].getAvailamount()-amm);
            amount[i]=amm;
            obj.savestock();
        }
    }
    DisplayShoppingList();
}
void Customer::DisplayShoppingList()
{
    cout<<endl<<"These Are The Items "<<getID()<<" has Bought:"<<endl;
    cout<<"  Name"<<setw(20)<<"Amount"<<endl;
    for ( int i=0;itemind[i]!=0;i++){
        cout<<i+1<<"- "<<obj.items[itemind[i]-1].getName()<<setw(16)<<amount[i]<<endl;
        receipt+=obj.items[itemind[i]-1].getPrice()*amount[i];
    }
    cout<<"Total Cost: "<<getTotal()<<" L.E"<<endl;
}
double Customer::getTotal()
{
    return receipt;
}
int Customer::getreceipt()
{
    return receipt;
}


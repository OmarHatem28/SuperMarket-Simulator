#include "Administrator.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

#include "rlutil.h"
#include "graphics.h"

Administrator::Administrator()
{
    //ctor
}
Administrator::~Administrator()
{
    delete[]customersList;
    delete[]temp;
}
void Administrator::initializecust(int index)
{
    // 2 arrays and copy the old array in the new one
    if ( flag ){
        secondary(index);
    }
    else{
        customersList = new Customer[index];
        for ( int i=0;i<index;i++){
            customersList[i].setID();
        }
    }
    flag=1;
}
void Administrator::secondary(int ind)
{
    int prevind=customersList[0].getTotalCounter();
    temp = new Customer[prevind];
    for ( int i=0;i<prevind;i++){
        temp[i]=customersList[i];
    }
    int newind=customersList[0].getTotalCounter()+ind;
    customersList = new Customer[newind];
    for ( int i=0;i<prevind;i++){
        customersList[i]=temp[i];
    }
    for ( int i=prevind;i<newind;i++){
        customersList[i].setID();
    }
}
void Administrator::reportAllItems()
{
    obj.updatestock();
    cout<<endl<<setw(10)<<"Name"<<setw(15)<<"Type"<<setw(20)<<"Amount"<<setw(16)<<"Price"<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
        for ( int i=0;i<obj.getsizeofitem();i++){
            if ( obj.items[i].getAvailamount() < 5 ){
                rlutil::setColor(12);
                /*
                settextstyle(BOLD_FONT,HORIZ_DIR,2);
                outtextxy(10,10,"HI");
                getch();
                closegraph();*/
            }
            cout<<setw(2)<<obj.items[i].getID()<<"-"<<setw(7)<<obj.items[i].getName()<<setw(16);
            cout<<obj.items[i].getType()<<setw(16);
            cout<<obj.items[i].getAvailamount()<<setw(16)<<obj.items[i].getPrice()<<setw(2)<<"L.E"<<endl;
            rlutil::resetColor();
        }
}

void Administrator::updateExistingItem()
{
    int NumChoice, choice,price, amount;
    reportAllItems();
    cout << "Enter the number of the item: ";
    cin >> NumChoice;
    cout << "Do you want to update \n1- price \n2- amount \n3- price & amount: ";
    cin >> choice;

    if(choice == 1)
    {
        cout << "Enter The new price: ";
        cin >> price;

        obj.items[NumChoice - 1].setPrice(price);
    }

    else if(choice == 2)
    {
        cout << "Enter The new amount: ";
        cin >> amount;

        obj.items[NumChoice - 1].setAvailamount(amount);
    }
    else if(choice == 3)
    {
        cout << "Enter The new amount ";
        cin >> amount;
        cout<<"Enter The new price: ";
        cin>> price;
        obj.items[NumChoice-1].setAvailamount(amount);
        obj.items[NumChoice-1].setPrice(price);
    }
    obj.savestock();
}

double Administrator::reportTotalRevenue()
{
    double totalPaid = 0.0;
    if ( customersList[0].getTotalCounter() == 0 ){
        throw 0;
    }
    for(int i = 0;i < customersList[0].getTotalCounter();i++)
    {
        totalPaid += customersList[i].getTotal();
    }
    return totalPaid;
}

void Administrator::checkout()
{
    int var=customersList[0].getCounter();
    int timy[var];
    for ( int i=0;i<var;i++){
        timy[i]=(customersList[i].CheckOutTime.gethours()*60)+customersList[i].CheckOutTime.getminutes();
    }
    sort(timy,timy+var);
    cout<<endl;
    for ( int i=0;i<var;i++){
        for ( int j=0;j<var;j++){
            if ( timy[i]/60 == customersList[j].CheckOutTime.gethours() &&
                 timy[i]%60 == customersList[j].CheckOutTime.getminutes() ){
                    cout<<customersList[j].getID()<<", Checkout at "<<customersList[j].getCheckOutTime()<<endl;
                 }
        }
    }
    flag=0;
    customersList[0].Counter=0;
    customersList[0].TotalCounter=0;
}

int Administrator::getTotalCustomers()
{
    return customersList[0].getCounter();
}

double Administrator::getmaxReceipt()
{
    double Max = 0;
    if ( customersList[0].getTotalCounter() == 0 ){
        throw 0;
    }
    for(int i = 0;i < customersList[0].getTotalCounter();i++)
    {
        if(Max < customersList[i].getTotal())
        {
            Max = customersList[i].getTotal();
        }
    }
    return Max;
}

void Administrator::addNewItem()
{
    string x;
    cout<<"Please Enter The Item Name, Type, Available Units, Price"<<endl;
    cin.ignore();
    getline(cin,x);
    int coma[3];
        int indexComa=0;

        for (int i=0;i < x.size();i++)
        {

            if(x[i] == ',')
            {
                    coma[indexComa]=i;
                    indexComa++;
            }
        }
        if ( indexComa == 0 ){
            throw 0;
        }
         string name = x.substr(0,coma[0]);
         string type = x.substr(coma[0]+1,coma[1]-coma[0]-1);
         string amount = x.substr(coma[1]+1,coma[2]-coma[1]-1);
         string price = x.substr(coma[2]+1);
    ofstream myFile("Input.txt", ios::app);
    myFile << name << ", " << type << ", " << amount << ", " << price << "\n";
    obj.savestock();
}

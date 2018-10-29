#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "MyTime.h"
#include "Person.h"
#include "Stock.h"
#include <string>
#include <fstream>
using namespace std;

class Customer : public Person
{
    public:
        friend class Administrator;
        Customer();
        ~Customer();
        void DisplayShoppingList();
        void BuyItems();

        void setCheckOutTime();
        void setShoppingDuration();
        void setArrivalTime();
        void setID();

        MyTime getCheckOutTime();
        MyTime getShoppingDuration();
        MyTime getArrivalTime();

        string getID();
        int getCounter();
        int getTotalCounter();
        double getTotal();
        int getreceipt();

    protected:

    private:
        Stock obj;
        int receipt = 0;
        string ID;
        static int Counter,TotalCounter;
        MyTime ArrivalTime,ShoppingDuration,CheckOutTime;
        int itemind[100]={0};
        int amount[100]={0};
        //int itemind,amount;can be used instead of array
};

#endif // CUSTOMER_H

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <iostream>
#include "Stock.h"
#include <fstream>
#include "Customer.h"
#include "Person.h"
#include <stdlib.h>
#include <string>
using namespace std;
class Administrator : public Person
{
    public:
        Administrator();
        ~Administrator();
        void reportAllItems();
        void addNewItem();
        void updateExistingItem();
        double reportTotalRevenue();
        int getTotalCustomers();
        double getmaxReceipt();
        void initializecust(int);
        void secondary(int ind);
        void checkout();

    private:
        Customer *customersList;
        Customer *temp;
        Stock obj;
        bool flag=0;

};

#endif // ADMINISTRATOR_H

#ifndef STOCK_H
#define STOCK_H
#include "Item.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstddef>
#include <stdlib.h>

using namespace std;
class Stock
{
    public:
        Stock();
        ~Stock();
        void loadStock();
        int getLineNum();
        int getsizeofitem();
        void savestock();
        void savestock(int);
        void updatestock();
        Item *items;

    private:
        int sizeofitem;


};

#endif // STOCK_H

#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;

class Item
{
    public:
        Item();
        ~Item();
        Item(string, string, int, int);

        string getName();
        string getType();
        int getID();
        int getAvailamount();
        int getPrice();
        int getitemsCo();

        void setAvailamount(int);
        void setPrice(int);
        void setitemid(int);


    private:
        string name;
        string type;
        int availamount;
        int price;
        int ID;
};

#endif // ITEM_H

#include <iostream>
#include <ctime>
#include "Administrator.h"

using namespace std;

int main()
{
    srand (time(NULL));
    Administrator admin;
    int choice1=99,choice2;
    while ( choice1 !=0 ){
        do{
        cout<<"Press 1 to Enter as Administrator, 2 to Enter as Customer and 0 to End the Program: ";
        cin>>choice1;
        cout<<"=============================================================================="<<endl;
        }while ( choice1 != 1 && choice1 != 2 && choice1 != 0 );
        if ( choice1 == 1 ){
            wrong:
            cout<<"What do you want to do:\n1- ReportAvailableItems\n"<<
            "2- AddNewItem\n3- UpdateExistingItem\n4- ReportTotalRevenue\n"<<
            "5- DisplayTotalCustomers\n6- DisplayMaxReceipt"<<endl;
            cin>>choice2;
            cout<<"=============================================================================="<<endl;
            if ( choice2 == 1 ){
                admin.reportAllItems();
            }
            else if ( choice2 == 2 ){
                try
                {
                    admin.addNewItem();
                }
                catch ( int x )
                {
                    cout<<"Wrong Input"<<endl;
                }

            }
            else if ( choice2 == 3 ){
                admin.updateExistingItem();
            }
            else if ( choice2 == 4 ){
                try
                {
                    cout<<"Total Revenue = "<<admin.reportTotalRevenue()<<" LE"<<endl;
                    cout<<"Order of the customers are :"<<endl;
                    admin.checkout();
                }
                catch (int x)
                {
                    cout<<"There Is No Money Yet"<<endl;
                }
            }
            else if ( choice2 == 5 ){
                cout<<"The currently available customers are "<<admin.getTotalCustomers()<<endl;
            }
            else if ( choice2 == 6 ){
                try
                {
                    cout<<"Max Receipt Value = "<<admin.getmaxReceipt()<<" LE"<<endl;
                }
                catch (int x)
                {
                    cout<<"No Customers"<<endl;
                }
            }
            else
                goto wrong;
            cout<<"=============================================================================="<<endl;
            cout<<"Do you want to do another operation ?"<<endl;
            string YorN;
            cin>>YorN;
            if ( YorN == "Y" || YorN == "y" || YorN == "Yes" || YorN == "yes"){
                goto wrong;
            }
        }
        else if ( choice1 == 2 ){
            int index;
            cout << "Please enter the number of customers: ";
            cin >> index;
            admin.initializecust(index);
        }
        else{
            cout<<"Good Bye"<<endl;
            return 0;
        }
    }
}

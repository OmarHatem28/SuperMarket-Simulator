#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

class Person
{
    public:
        Person();
        ~Person();
        Person(string n , string add);

        void setname(string n );
        string getname();

        void setaddress(string add);
        string getaddress();

    protected:

    private:
        string Name ;
        string Address;
};

#endif // PERSON_H

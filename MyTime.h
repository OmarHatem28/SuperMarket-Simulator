#ifndef MYTIME_H
#define MYTIME_H
#include <string>
using namespace std;

class MyTime
{
    public:
        MyTime();
        ~MyTime();
        MyTime(int h , int m);

        void sethours (int h);
        int gethours();

        void setminutes(int m);
        int getminutes();

        //void printtime();

        MyTime operator+( MyTime &obj );
        friend ostream& operator<<(ostream& out, MyTime obj );

    protected:

    private:
        int hours;
        int minutes;
};

#endif // MYTIME_H

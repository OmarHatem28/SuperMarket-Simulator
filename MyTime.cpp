#include "MyTime.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

MyTime::MyTime()
{
    //ctor
}

MyTime::~MyTime()
{
    //dtor
}
MyTime::MyTime(int h , int m)
{
    hours=h;
    minutes=m;
}

void MyTime::sethours (int h)
{
    hours=h;
}
int MyTime::gethours()
{
    return hours;
}

void MyTime::setminutes(int m)
{
    minutes=m;
}
int MyTime::getminutes()
{
    return minutes;
}
/*
void MyTime::printtime()
{
    cout<<hours<<":"<<minutes;
}
*/
ostream& operator<<(ostream& out,  MyTime obj )
{
    if ( obj.hours >= 12 ){
            obj.hours%=12;
            if ( obj.hours == 0 ){
                obj.hours=12;
            }
            else if (obj.hours < 10 )
                out<<"0";
            out<<obj.hours<<":";
            if (obj.minutes < 10 )
                out<<"0";
            out<<obj.minutes<<" AM"<<endl;
    }
    else{
        if (obj.hours < 10 )
            out<<"0";
        out<<obj.hours<<":";
        if (obj.minutes < 10 )
            out<<"0";
        out<<obj.minutes<<" PM"<<endl;
    }
    return out;
}
MyTime MyTime::operator+( MyTime &obj )
{
        MyTime Temp;

        Temp.hours = hours + obj.hours ;
        Temp.minutes = minutes + obj.minutes ;
        if ( Temp.minutes > 59 ){
            Temp.minutes-=60;
            Temp.hours++;
        }/*
        if ( Temp.hours > 12 ){
            Temp.hours-=12;
        }*/
        return Temp ;

}

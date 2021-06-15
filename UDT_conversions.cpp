#include<iostream>
using namespace std;

class altTime // In alt time an hour is 30mins as opposed to 60mins 
{ 
private:
    int hours, minutes;

public:
    void showTime(){cout << hours << "::" << minutes << endl;}
    int showMinutes(){return (hours*30) + minutes;}
    altTime(int hrs, int mins){hours = hrs; minutes = mins;}
    altTime(){};
    altTime(int whole){hours = whole / 30; minutes = whole % 30;} // int to UDT;

    // UDT to int 
    operator int()
    {
        return ((hours * 30) + minutes);
    }

};

class Time
{
private:
    int hours, minutes;

public:
    void showTime(){cout << hours << "::" << minutes << endl;}
    Time(int hrs, int mins){hours = hrs; minutes = mins;}
    Time(){};


    Time(int whole){hours = whole / 60; minutes = whole % 60;} // int to UDT;

    // UDT to int 
    operator int()
    {
        return ((hours * 60) + minutes);
    }

    // UDT to UDT coversion using operator
    operator altTime()
    {
        int mins = hours*60;
        mins += minutes;
        altTime alt(mins / 30, mins % 30);
        return alt;
    }

    // UDT to UDT conversion using constructor

    Time(altTime &tt)
    {
        int mins = tt.showMinutes();
        minutes = mins % 60; hours = mins / 60;
    }

};

int main(void)
{
    int x = 100;
    Time t1(10, 20);
    t1.showTime();

    // int to UDT
    t1 = x;
    t1.showTime();

    // UDT to int 
    int y = (int)t1;
    cout << y << endl;

    // UDT to UDT using operator 
    altTime tt;
    tt = t1;
    // expected answer should be hours = 100/30 = 3; minutes = 100 % 30 = 10;
    tt.showTime();

    // UDT to UDT using constructor  
    Time t2;
    cout << tt.showMinutes() << endl;
    t2 = tt;
    // expected answer should be hours = 100/30 = 3; minutes = 100 % 30 = 10;
    t2.showTime();
}

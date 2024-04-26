#pragma once 
#include <iostream>
class CFraction {
    int _numenator;
    int _denomenator;
public:
    CFraction();
    CFraction(const CFraction& F1);
    CFraction(int numenator, int denumirator);
    void set_numenator(int numenator);
    void set_denomenator(int denuminator);
    int get_numenator(int numenator);
    int get_denumenator(int denomenator);

    void print();
    void simplify();
    CFraction operator=(const CFraction& frac);
    bool operator!=(const CFraction& frac);
    bool operator!=(const CFraction& frac);
    bool operator>=(const CFraction& fr);
    bool operator<=(const CFraction& fr);
    bool operator<(const CFraction& fr);
    bool operator>(const CFraction& fr);

    CFraction operator+(const CFraction& frac);
    void operator+=(const CFraction& frac);
    CFraction operator-(const CFraction& frac);
    void operator-=(const CFraction& frac);
    CFraction operator*(const CFraction& frac);
    void operator*=(const CFraction& frac);
    CFraction operator/(const CFraction& frac);
    void operator/=(const CFraction& frac);
    friend std::istream& operator>>(std::istream& cin, CFraction& c)
    {
        cin >> c._numenator >> c._denomenator;
        return cin;
    }

    friend std::ostream& operator<<(std::ostream& cout, CFraction& c)
    {
        cout << c._numenator << "/" << c._denomenator;
        return cout;
    }
};
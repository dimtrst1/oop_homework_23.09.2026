#include <iostream>
using namespace std;

class Var
{
private:
    int it;
    double dbl;
    string str;
    int type;

    string ToString() const;
    int ToInt() const;
    double ToDouble() const;

    Var Convert(const Var& obj) const;

public:
    Var();
    Var(int a);
    Var(double a);
    Var(string st);
    Var(const char* st);

    void Show() const;
    int CheckType() const;

    Var operator+(const Var& obj) const;
    Var operator-(const Var& obj) const;
    Var operator*(const Var& obj) const;
    Var operator/(const Var& obj) const;

    Var& operator+=(const Var& obj);
    Var& operator-=(const Var& obj);
    Var& operator*=(const Var& obj);
    Var& operator/=(const Var& obj);

    bool operator==(const Var& obj) const;
    bool operator!=(const Var& obj) const;
    bool operator<(const Var& obj) const;
    bool operator>(const Var& obj) const;
    bool operator<=(const Var& obj) const;
    bool operator>=(const Var& obj) const;

    operator int() const;
    operator double() const;
    operator char*() const;
};

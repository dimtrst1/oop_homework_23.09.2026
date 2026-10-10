#include "Var.h"

Var::Var()
{
    it = 0;
    dbl = 0;
    str = "";
    type = 1;
}

Var::Var(int a)
{
    it = a;
    dbl = 0;
    str = "";
    type = 1;
}

Var::Var(double a)
{
    it = 0;
    dbl = a;
    str = "";
    type = 2;
}

Var::Var(string st)
{
    it = 0;
    dbl = 0;
    str = st;
    type = 3;
}

Var::Var(const char* st)
{
    it = 0;
    dbl = 0;
    str = st;
    type = 3;
}

int Var::CheckType() const
{
    return type;
}

void Var::Show() const
{
    if (type == 1)
        cout << it << endl;
    else if (type == 2)
        cout << dbl << endl;
    else
        cout << str << endl;
}

string Var::ToString() const
{
    if (type == 1)
        return to_string(it);

    if (type == 2)
    {
        string s = to_string(dbl);

        while (s.find('.') != string::npos &&
               s.back() == '0')
            s.pop_back();

        if (s.back() == '.')
            s.pop_back();

        return s;
    }

    return str;
}

int Var::ToInt() const
{
    if (type == 1)
        return it;

    if (type == 2)
        return static_cast<int>(dbl);

    return stoi(str);
}

double Var::ToDouble() const
{
    if (type == 1)
        return it;

    if (type == 2)
        return dbl;

    return stod(str);
}

Var Var::Convert(const Var& obj) const
{
    if (type == 1)
        return Var(obj.ToInt());

    if (type == 2)
        return Var(obj.ToDouble());

    return Var(obj.ToString());
}

Var Var::operator+(const Var& obj) const
{
    Var b = Convert(obj);

    if (type == 1)
        return Var(it + b.it);

    if (type == 2)
        return Var(dbl + b.dbl);

    return Var(str + b.str);
}

Var Var::operator-(const Var& obj) const
{
    Var b = Convert(obj);

    if (type == 1)
        return Var(it - b.it);

    if (type == 2)
        return Var(dbl - b.dbl);

    string result = str;
    size_t pos = result.find(b.str);

    if (pos != string::npos)
        result.erase(pos, b.str.length());

    return Var(result);
}

Var Var::operator*(const Var& obj) const
{
    Var b = Convert(obj);

    if (type == 1)
        return Var(it * b.it);

    if (type == 2)
        return Var(dbl * b.dbl);

    string result = "";

    for (char c : str)
    {
        if (b.str.find(c) != string::npos)
            result += c;
    }

    return Var(result);
}

Var Var::operator/(const Var& obj) const
{
    Var b = Convert(obj);

    if (type == 1)
    {
        if (b.it == 0)
            throw runtime_error("Division by zero");

        return Var(it / b.it);
    }

    if (type == 2)
    {
        if (b.dbl == 0)
            throw runtime_error("Division by zero");

        return Var(dbl / b.dbl);
    }

    string result = "";

    for (char c : str)
    {
        if (b.str.find(c) == string::npos)
            result += c;
    }

    return Var(result);
}

Var& Var::operator+=(const Var& obj)
{
    *this = *this + obj;
    return *this;
}

Var& Var::operator-=(const Var& obj)
{
    *this = *this - obj;
    return *this;
}

Var& Var::operator*=(const Var& obj)
{
    *this = *this * obj;
    return *this;
}

Var& Var::operator/=(const Var& obj)
{
    *this = *this / obj;
    return *this;
}

bool Var::operator==(const Var& obj) const
{
    Var b = Convert(obj);

    if (type == 1)
        return it == b.it;

    if (type == 2)
        return dbl == b.dbl;

    return str == b.str;
}

bool Var::operator!=(const Var& obj) const
{
    return !(*this == obj);
}

bool Var::operator<(const Var& obj) const
{
    Var b = Convert(obj);

    if (type == 1)
        return it < b.it;

    if (type == 2)
        return dbl < b.dbl;

    return str < b.str;
}

bool Var::operator>(const Var& obj) const
{
    Var b = Convert(obj);

    if (type == 1)
        return it > b.it;

    if (type == 2)
        return dbl > b.dbl;

    return str > b.str;
}

bool Var::operator<=(const Var& obj) const
{
    return !(*this > obj);
}

bool Var::operator>=(const Var& obj) const
{
    return !(*this < obj);
}

Var::operator int() const
{
    return ToInt();
}

Var::operator double() const
{
    return ToDouble();
}

Var::operator char*() const
{
    string s = ToString();

    char* result = new char[s.length() + 1];
    strcpy(result, s.c_str());

    return result;
}

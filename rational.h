#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <string>
class Rational
{
public:
    Rational();
    Rational(int x, int y);
    Rational(const char *a);
    int getNumerator();
    int getDenominator();
    void reduce();
    operator double() const;
    friend Rational operator+(Rational a, Rational b);
    friend Rational operator-(Rational a, Rational b);
    friend Rational operator*(Rational a, Rational b);
    friend Rational operator/(Rational a, Rational b);
    friend std::ostream &operator<<(std::ostream &out, Rational a);


private:
    int numerator;
    int denominator;
};


#endif
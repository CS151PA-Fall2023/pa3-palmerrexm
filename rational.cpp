#include "rational.h"
#include <iostream>
#include <string>
/**
 * @brief default constructor
 * 
 */
Rational::Rational()
{
    numerator = 1;
    denominator = 1;
}

/**
 * @brief default constructor with two int parameters
 * 
 * @param x 
 * @param y 
 */
Rational::Rational(int x, int y)
{
    numerator = x;
    denominator = y;
}

/**
 * @brief convert constructor
 * 
 * @param a 
 */
Rational::Rational(const char* a)
{
    int slashLocation;
    int nullLocation;
    std::string numString;
    std::string denomString;

    int i = 0;
    while (a[i] != '/')
    {
        i++;      
    }
    slashLocation = i;

    i = 0;
    while (a[i] != '\0')
    {
        i++;
    }
    nullLocation = i;


    for (int i = 0; i<slashLocation; i++)
    {
        numString = numString + a[i];
    }
    numerator = std::stoi(numString);

    for (int i = slashLocation + 1; i< nullLocation; i++)
    {
        denomString = denomString + a[i];
    }
    denominator = std::stoi(denomString);
}

/**
 * @brief getter function for numerator
 * 
 * @return int 
 */
int Rational::getNumerator()
{
    return numerator;
}

/**
 * @brief getter function for denominator
 * 
 * @return int 
 */
int Rational::getDenominator()
{
    return denominator;
}

/**
 * @brief function reduces Rational object by finding the greatest common denominator and then dividing it into the numerator and denominator
 * 
 */
void Rational::reduce()
{
    int GCD;
    if (denominator == 0)
    {
        return;
    }
    else
    {
        if (abs(denominator) > abs(numerator))
        {
            for(int i=1; i<=abs(denominator); ++i)
            {
                if(numerator % i == 0 && denominator % i == 0)
                {
                    GCD = i;
                }
            }
        }
        else
        {
            for(int i=1; i<=abs(numerator); ++i)
            {
                if(numerator % i == 0 && denominator % i == 0)
                {
                    GCD = i;
                }
            }
        }
    }

    numerator/=GCD;
    denominator/=GCD;
}

/**
 * @brief type conversion operator to convert Rational datatype to double
 * 
 * @return double 
 */
Rational::operator double() const
{
    return static_cast<double>(numerator)/denominator;
}

/**
 * @brief overloads "+" operator to add two rational objects
 * 
 * @param a 
 * @param b 
 * @return Rational 
 */
Rational operator+(Rational a, Rational b)
{
    int newNum,
        newDenom;
    
    
    newDenom = a.getDenominator() * b.getDenominator();
    newNum = (a.getNumerator() * b.getDenominator()) + (b.getNumerator() * a.getDenominator());
    Rational result(newNum, newDenom);
    result.reduce();
    return result;
}

/**
 * @brief overloads "-" operator to subtract two rational objects
 * 
 * @param a 
 * @param b 
 * @return Rational 
 */
Rational operator-(Rational a, Rational b)
{
    int newNum,
        newDenom;
    
    
    newDenom = a.getDenominator() * b.getDenominator();
    newNum = (a.getNumerator() * b.getDenominator()) - (b.getNumerator() * a.getDenominator());
    Rational result(newNum, newDenom);
    result.reduce();
    return result;
}

/**
 * @brief overloads "*" operator to multiply two rational objects
 * 
 * @param a 
 * @param b 
 * @return Rational 
 */
Rational operator*(Rational a, Rational b)
{
    int newNum,
        newDenom;
    
    
    newDenom = a.getDenominator() * b.getDenominator();
    newNum = a.getNumerator() * b.getNumerator();
    Rational result(newNum, newDenom);
    result.reduce();
    return result;
}

/**
 * @brief overloads "/" operator to divide two rational objects
 * 
 * @param a 
 * @param b 
 * @return Rational 
 */
Rational operator/(Rational a, Rational b)
{
    int newNum,
        newDenom;
    
    
    newDenom = a.getDenominator() * b.getNumerator();
    newNum = a.getNumerator() * b.getDenominator();
    Rational result(newNum, newDenom);
    result.reduce();
    return result;
}

/**
 * @brief overloads stream insertion operator to display Rational object
 * 
 * @param out 
 * @param a 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &out, Rational a)
{
    out << a.getNumerator() << "/" << a.getDenominator();
    return out;
}
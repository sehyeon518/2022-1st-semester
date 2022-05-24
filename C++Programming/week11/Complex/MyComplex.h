#ifndef _MYCOMPLEX_H_
#define _MYCOMPLEX_H_
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class myComplex
{
public:
    friend myComplex operator+(int value, const myComplex& number);
    friend myComplex operator-(int value, myComplex& number);
    friend myComplex operator*(int value, const myComplex& number);
    friend ostream& operator <<(ostream& outStream, const myComplex& number);
    friend istream& operator >>(istream& inStream, myComplex& number);

    myComplex(int real = 0, int imag = 0);
    myComplex(const myComplex& number);

    int getRealPart() const;
    int getImaginaryPart() const;
    void setRealPart(int real);
    void setImaginaryPart(int image);
    void set(int real, int image);

    myComplex operator +(const myComplex& number) const;
    myComplex operator +(int value) const;
    myComplex operator ++();
    myComplex operator ++(int);

    myComplex operator -(const myComplex& number) const;
    myComplex operator -(int value) const;
    myComplex operator --();
    myComplex operator --(int);

    myComplex& operator =(const myComplex& number);
    myComplex& operator =(int value);

    myComplex operator *(const myComplex& number) const;
    myComplex operator *(int value) const;

    myComplex operator -();
    myComplex operator ~();
    myComplex& operator +=(const myComplex& number);
    myComplex& operator +=(int value);
    myComplex& operator -=(const myComplex& number);
    myComplex& operator -=(int value);
    myComplex& operator *=(const myComplex& number);
    myComplex& operator *=(int value);
    bool operator ==(const myComplex& number) const;
    bool operator !=(const myComplex& number) const;
    bool operator >(const myComplex& number) const;
    bool operator <(const myComplex& number) const;
    bool operator >=(const myComplex& number) const;
    bool operator <=(const myComplex& number) const;

private:
    int realPart;
    int imaginaryPart;
    int norm() const;

};
#endif
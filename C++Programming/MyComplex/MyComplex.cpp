#include "MyComplex.h"

myComplex::myComplex(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
myComplex::myComplex(const myComplex& number)
{
    realPart = number.realPart;
    imaginaryPart = number.imaginaryPart;
}
int myComplex::getRealPart() const
{
    return realPart;
}
int myComplex::getImaginaryPart() const
{
    return imaginaryPart;
}
void myComplex::setRealPart(int real)
{
    realPart = real;
}
void myComplex::setImaginaryPart(int imag)
{
    imaginaryPart = imag;
}
void myComplex::set(int real, int imag)
{
    realPart = real;
    imaginaryPart = imag;
}
myComplex myComplex::operator +(const myComplex& number) const
{
    int newReal = realPart + number.realPart;
    int newImag = imaginaryPart + number.imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator +(int value) const
{
    return myComplex(value) + (*this);
}
myComplex myComplex::operator ++()
{
    realPart++;
    myComplex pos(getRealPart(), getImaginaryPart());
    return pos;
}
myComplex myComplex::operator ++(int)
{
    myComplex pos(getRealPart(), getImaginaryPart());
    realPart++;
    return pos;
}
myComplex myComplex::operator -(const myComplex& number) const
{
    int newReal = realPart - number.realPart;
    int newImag = imaginaryPart - number.imaginaryPart;
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator -(int value) const
{
    return (*this) - myComplex(value);
}
myComplex myComplex::operator --()
{
    realPart--;
    myComplex pos(getRealPart(), getImaginaryPart());
    return pos;
}
myComplex myComplex::operator --(int)
{
    myComplex pos(getRealPart(), getImaginaryPart());
    realPart--;
    return pos;
}
myComplex& myComplex::operator =(const myComplex& number)
{
    this->realPart = number.realPart;
    this->imaginaryPart = number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator =(int value)
{
    realPart = value;
    imaginaryPart = 0;
    return *this;
}
myComplex myComplex::operator -()
{
    return myComplex(-realPart, -imaginaryPart);
}
myComplex myComplex::operator ~()
{
    return myComplex(realPart, -imaginaryPart);
}
myComplex myComplex::operator *(const myComplex& number) const
{
    int newReal = (realPart * number.realPart) - (imaginaryPart * number.imaginaryPart);
    int newImag = (realPart * number.imaginaryPart) + (imaginaryPart * number.realPart);
    return myComplex(newReal, newImag);
}
myComplex myComplex::operator *(int value) const
{
    return myComplex(value) * (*this);
}
myComplex& myComplex::operator +=(const myComplex& number)
{
    int thr = this->realPart;
    int thi = this->imaginaryPart;
    this->realPart = thr + number.realPart;
    this->imaginaryPart = thi + number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator +=(int value)
{
    realPart = this->realPart + value;
    imaginaryPart = this->imaginaryPart;
    return *this;
}
myComplex& myComplex::operator -=(const myComplex& number)
{
    int thr = this->realPart;
    int thi = this->imaginaryPart;
    this->realPart = thr - number.realPart;
    this->imaginaryPart = thi - number.imaginaryPart;
    return *this;
}
myComplex& myComplex::operator -=(int value)
{
    realPart = this->realPart - value;
    imaginaryPart = this->imaginaryPart;
    return *this;
}
myComplex& myComplex::operator *=(const myComplex& number)
{
    int thr = this->realPart;
    int thi = this->imaginaryPart;
    this->realPart = (thr * number.realPart) - (thi * number.imaginaryPart);
    this->imaginaryPart = (thr * number.imaginaryPart) + (thi * number.realPart);
    return *this;
}
myComplex& myComplex::operator *=(int value)
{
    realPart = this->realPart * value;
    imaginaryPart = this->imaginaryPart * value;
    return *this;
}
bool myComplex::operator ==(const myComplex& number) const
{
    return (realPart == number.realPart) && (imaginaryPart == number.imaginaryPart);
}
bool myComplex::operator !=(const myComplex& number) const
{
    return (realPart != number.realPart) || (imaginaryPart != number.imaginaryPart);
}
bool myComplex::operator >(const myComplex& number) const
{
    return norm() > number.norm();
}
bool myComplex::operator <(const myComplex& number) const
{
    return norm() < number.norm();
}
bool myComplex::operator >=(const myComplex& number) const
{
    return norm() >= number.norm();
}
bool myComplex::operator <=(const myComplex& number) const
{
    return norm() <= number.norm();
}

int myComplex::norm() const
{
    return realPart * realPart + imaginaryPart * imaginaryPart;
}
myComplex operator+(int value, const myComplex& number)
{
    return number + value;
}
myComplex operator-(int value, myComplex& number)
{
    return (-number) + value;
}
myComplex operator*(int value, const myComplex& number)
{
    return number * value;
}
ostream& operator <<(ostream& outStream, const myComplex& number)
{
    outStream << "(" << number.realPart << "," << number.imaginaryPart << ")";
    return outStream;
}
istream& operator >>(istream& inStream, myComplex& number)
{
    inStream >> number.realPart >> number.imaginaryPart;
    return inStream;
}
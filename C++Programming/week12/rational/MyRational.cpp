#include "MyRational.h"

myRational::myRational(long num, long den){
	if ((num != 0 && den != 0)) {
		long _gcd = gcd(num, den);
		num /= _gcd;
		den /= _gcd;
	}

	this->_num = num;
	this->_den = den;
}

myRational::myRational(const myRational& rat){
	(*this) = rat;
}

long myRational::gcd(long m, long n){
	if (m < 0 || n < 0)
		return 1;

	if (m == n)
		return n;
	else if (m < n)
		return gcd(m, n - m);
	else
		return gcd(m - n, n);
}

void myRational::reduce(){
	if (_num == 0 || _den == 0){
		_num = 0;
		_den = 1;
		return;
	}
	if (_den < 0){
		_den *= -1;
		_num *= -1;
	}
	if (_num == 1)
		return;
	int sgn = (_num < 0 ? -1 : 1);
	long g = gcd(sgn * _num, _den);
	_num /= g;
	_den /= g;
}

long myRational::getNumerator() const{
	return this->_num;
}

long myRational::getDenominator() const{
	return this->_den;
}

myRational myRational::reciprocal(){
	long new_num = _num, new_den = _den;
	long _gcd = gcd(new_num, new_den);

	new_num /= _gcd;
	new_den /= _gcd;

	this->_num = new_num;
	this->_den = new_den;

	return (*this);
}

myRational myRational::operator + (const myRational& rat) const{
	long new_num = rat._den * this->_num + this->_den * rat._num;
	long new_den = this->_den * rat._den;
	return myRational(new_num, new_den);
}
myRational myRational::operator - (const myRational& rat) const{
	long new_num = rat._den * this->_num - this->_den * rat._num;
	long new_den = this->_den * rat._den;
	return myRational(new_num, new_den);
}
myRational myRational::operator * (const myRational& rat) const{
	long new_num = this->_num * rat._num;
	long new_den = this->_den * rat._den;
	return myRational(new_num, new_den);
}
myRational myRational::operator / (const myRational& rat) const{
	if (rat._num == 0) return 0;

	long new_num = this->_num * rat._den;
	long new_den = this->_den * rat._num;
	return myRational(new_num, new_den);
}

myRational myRational::operator + (const int value) const{
	return (*this) + myRational(value, 1);
}
myRational myRational::operator - (const int value) const{
	return (*this) - myRational(value, 1);
}
myRational myRational::operator * (const int value) const{
	return (*this) * myRational(value, 1);
}
myRational myRational::operator / (const int value) const{
	return (*this) / myRational(value, 1);
}

myRational operator + (int value, const myRational& rat){
	return myRational(value, 1) + rat;
}
myRational operator - (int value, const myRational& rat){
	return myRational(value, 1) - rat;
}
myRational operator * (int value, const myRational& rat){
	return myRational(value, 1) * rat;
}
myRational operator / (int value, const myRational& rat){
	return myRational(value, 1) / rat;
}

myRational &myRational::operator ++(){
	(*this) += 1;
	return (*this);
}
myRational myRational::operator ++(int){
	myRational temp = (*this);
	operator++();
	return temp;
}
myRational &myRational::operator --(){
	(*this) -= 1;
	return (*this);
}
myRational myRational::operator --(int){
	myRational temp = (*this);
	operator--();
	return temp;
}

myRational myRational::operator -(){
	return (-1) * (*this);
}

bool myRational::operator < (const myRational& rat) const{
	return this->_num * rat._den < rat._num* this->_den;
}
bool myRational::operator <= (const myRational& rat) const{
	return this->_num * rat._den <= rat._num* this->_den;
}
bool myRational::operator > (const myRational& rat) const{
	return this->_num * rat._den > rat._num* this->_den;
}
bool myRational::operator >= (const myRational& rat) const{
	return this->_num * rat._den >= rat._num* this->_den;
}
bool myRational::operator == (const myRational& rat) const{
	return this->_num * rat._den == rat._num* this->_den;
}
bool myRational::operator != (const myRational& rat) const{
	return this->_num * rat._den != rat._num* this->_den;
}

bool myRational::operator < (const int value) const{
	return (*this) < myRational(value, 1);
}
bool myRational::operator <= (const int value) const{
	return (*this) <= myRational(value, 1);
}
bool myRational::operator > (const int value) const{
	return (*this) > myRational(value, 1);
}
bool myRational::operator >= (const int value) const{
	return (*this) >= myRational(value, 1);
}
bool myRational::operator == (const int value) const{
	return (*this) == myRational(value, 1);
}
bool myRational::operator != (const int value) const{
	return (*this) != myRational(value, 1);
}

myRational operator < (int value, const myRational& rat){
	return myRational(value, 1) < rat;
}
myRational operator <= (int value, const myRational& rat){
	return myRational(value, 1) <= rat;
}
myRational operator > (int value, const myRational& rat){
	return myRational(value, 1) > rat;
}
myRational operator >= (int value, const myRational& rat){
	return myRational(value, 1) >= rat;
}
myRational operator == (int value, const myRational& rat){
	return myRational(value, 1) == rat;
}
myRational operator != (int value, const myRational& rat){
	return myRational(value, 1) != rat;
}


myRational &myRational::operator = (const myRational& rat){
	this->_num = rat._num;
	this->_den = rat._den;
	return (*this);
}
myRational &myRational::operator += (const myRational& rat){
	(*this) = (*this) + rat;
	return (*this);
}
myRational &myRational::operator -= (const myRational& rat){
	(*this) = (*this) - rat;
	return (*this);
}
myRational &myRational::operator *= (const myRational& rat){
	(*this) = (*this) * rat;
	return (*this);
}
myRational &myRational::operator /= (const myRational& rat){
	(*this) = (*this) / rat;
	return (*this);
}

myRational &myRational::operator = (const int value){
	(*this) = myRational(value, 1);
	return (*this);
}
myRational &myRational::operator += (const int value){
	(*this) += myRational(value);
	return (*this);
}
myRational &myRational::operator -= (const int value){
	(*this) -= myRational(value);
	return (*this);
}
myRational &myRational::operator *= (const int value){
	(*this) *= myRational(value);
	return (*this);
}
myRational &myRational::operator /= (const int value){
	(*this) /= myRational(value);
	return (*this);
}

ostream& operator <<(ostream& outStream, const myRational& r){
	if (r._num == 0)
		outStream << 0;
	else if (r._den == 1)
		outStream << r._num;
	else
		outStream << r._num << "/" << r._den;

	return outStream;
}

istream& operator >>(istream& inStream, myRational& r){
	inStream >> r._num >> r._den;
	if (r._den == 0){
		r._num = 0;
		r._den = 1;
	}
	r.reduce();
	return inStream;
}

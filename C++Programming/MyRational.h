#ifndef _MYRATIONAL_H_
#define _MYRATIONAL_H_

#include <iostream>

using namespace std;

class myRational
{
private:
	// 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다.
	long _num; // numerator 분자
	long _den; // denominator 분모
	long gcd(long m, long n); // 최대공약수
	void reduce();
public:
	myRational(long num = 0, long den = 1);
	myRational(const myRational& rat);

	long getNumerator() const;
	long getDenominator() const;

	myRational reciprocal();

	myRational operator + (const myRational& rat) const;
	myRational operator - (const myRational& rat) const;
	myRational operator * (const myRational& rat) const;
	myRational operator / (const myRational& rat) const;

	myRational operator + (const int value) const;
	myRational operator - (const int value) const;
	myRational operator * (const int value) const;
	myRational operator / (const int value) const;

	friend myRational operator + (int value, const myRational& rat);
	friend myRational operator - (int value, const myRational& rat);
	friend myRational operator * (int value, const myRational& rat);
	friend myRational operator / (int value, const myRational& rat);

	myRational& operator ++();
	myRational operator ++(int);
	myRational& operator --();
	myRational operator --(int);

	myRational operator -();

	bool operator < (const myRational& rat) const;
	bool operator <= (const myRational& rat) const;
	bool operator > (const myRational& rat) const;
	bool operator >= (const myRational& rat) const;
	bool operator == (const myRational& rat) const;
	bool operator != (const myRational& rat) const;

	bool operator < (const int value) const;
	bool operator <= (const int value) const;
	bool operator > (const int value) const;
	bool operator >= (const int value) const;
	bool operator == (const int value) const;
	bool operator != (const int value) const;

	myRational &operator = (const myRational& rat);
	myRational &operator += (const myRational& rat);
	myRational &operator -= (const myRational& rat);
	myRational &operator *= (const myRational& rat);
	myRational &operator /= (const myRational& rat);

	myRational &operator = (const int value);
	myRational &operator += (const int value);
	myRational &operator -= (const int value);
	myRational &operator *= (const int value);
	myRational &operator /= (const int value);

	friend ostream& operator <<(ostream& outStream, const myRational& r);
	friend istream& operator >>(istream& inStream, myRational& r);
};

#endif

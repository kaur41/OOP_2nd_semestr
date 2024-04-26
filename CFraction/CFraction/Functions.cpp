#include "Header.hpp"
#include <string>
#include <iostream>
int lcd(int a, int b) { // наибольший общий делитель
	if (a == 0) { return b; }
	else if (b == 0) { return a; }
	else if (a >= b) { return lcd(a % b, b); }
	else if (a <= b) { return lcd(a, b % a); }
}

void CFraction::simplify()
{
	int _lcd = lcd(_numenator, _denomenator);
	_denomenator /= _lcd;
	_numenator /= _lcd;
}
CFraction::CFraction()
{
	_numenator = 0;
	_denomenator = 1;
	this->simplify();
}
CFraction::CFraction(const CFraction & frac) {
	_numenator = frac._numenator;
	_denomenator = frac._denomenator;
	this->simplify();
}
CFraction::CFraction(int numenator, int denumenator)
{
	_numenator = numenator;
	_denomenator = denumenator;
	this->simplify();
}
void CFraction::set_numenator(int numenator)
{
	_numenator = numenator;
}
void CFraction::set_denomenator(int denumirator)
{
	_denomenator = denumirator;
}
int CFraction::get_numenator(int numenator)
{
	return _numenator;
}
int CFraction::get_denumenator(int denomenator)
{
	return _denomenator;
}
void CFraction::print()
{
	this->simplify();
	std::cout << _numenator << '/' << _denomenator << '\n';
}

CFraction CFraction::operator=(const CFraction& frac)
{
	if (this != &frac)
	{
		_denomenator = frac._denomenator;
		_numenator = frac._numenator;
	}
	else { return *this; }
}

bool CFraction::operator!=(const CFraction& fr)
{
	return (_denomenator != fr._denomenator && _numenator != fr._numenator);
}

bool CFraction::operator>=(const CFraction& fr)
{
	return ((_denomenator == fr._denomenator && _numenator >= fr._numenator) || (_denomenator <= fr._denomenator));
}
bool CFraction::operator<=(const CFraction& fr)
{
	return((_denomenator == fr._denomenator && _numenator <= fr._numenator) || (_denomenator >= fr._denomenator));
}
bool CFraction::operator<(const CFraction& fr)
{
	return((_denomenator == fr._denomenator && _numenator < fr._numenator) || (_denomenator > fr._denomenator));
}
bool CFraction::operator>(const CFraction& frac)
{
	return((_denomenator == frac._denomenator && _numenator > frac._numenator) || (_denomenator < frac._denomenator));
}

CFraction CFraction::operator+(const CFraction& fr1)
{
	CFraction Res(*this);
	if (Res._denomenator == fr1._denomenator)
	{
		Res._numenator += fr1._numenator;
	}
	else
	{
		Res._numenator = (Res._numenator * fr1._denomenator) + (fr1._numenator * Res._denomenator);
		Res._denomenator = Res._denomenator * fr1._denomenator;
	}
	Res.simplify();
	return Res;
}

void CFraction::operator+=(const CFraction& fr1)
{
	if (_denomenator == fr1._denomenator)
	{
		_numenator += fr1._numenator;
	}
	else
	{
		_numenator = (_numenator * fr1._denomenator) + (fr1._numenator * _denomenator);
		_denomenator = _denomenator * fr1._denomenator;
	}
	this->simplify();
}

CFraction CFraction::operator-(const CFraction& fr)
{
	CFraction Res(*this);
	if (Res._denomenator == fr._denomenator)
	{
		Res._numenator -= fr._numenator;
	}
	else
	{
		Res._numenator = (Res._numenator * fr._denomenator) - (fr._numenator * Res._denomenator);
		Res._denomenator = Res._denomenator * fr._denomenator;
	}
	Res.simplify();
	return Res;
}

void CFraction::operator-=(const CFraction& fr1)
{
	if (_denomenator == fr1._denomenator)
	{
		_numenator -= fr1._numenator;
	}
	else
	{
		_numenator = (_numenator * fr1._denomenator) - (fr1._numenator * _denomenator);
		_denomenator *= fr1._denomenator;
	}
	this->simplify();
}

CFraction CFraction::operator*(const CFraction& fr)
{
	CFraction Res(*this);
	Res._denomenator = Res._denomenator * fr._denomenator;
	Res._numenator = Res._numenator * fr._numenator;
	Res.simplify();
	return Res;
}

void CFraction::operator*=(const CFraction& fr)
{
	_denomenator = _denomenator * fr._denomenator;
	_numenator = _numenator * fr._numenator;
	this->simplify();
}

CFraction CFraction::operator/(const CFraction& fr)
{
	CFraction res(*this);
	res._numenator = res._numenator * fr._denomenator;
	res._denomenator = res._denomenator * fr._numenator;
	res.simplify();
	return res;
}

void CFraction::operator/=(const CFraction& frac)
{
	_numenator = _numenator * frac._denomenator;
	_denomenator = _denomenator * frac._numenator;
	this->simplify();
}
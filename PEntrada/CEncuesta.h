#pragma once
class CEncuesta
{
public:
	CEncuesta(){}
	~CEncuesta(){}
	void setp1(char nuevo) { p1 = nuevo; }
	void setp2(char nuevo) { p2 = nuevo; }
	void setp3(char nuevo) { p3 = nuevo; }
	char getp1() { return p1; }
	char getp2() { return p2; }
	char getp3() { return p3; }
private:
	char p1, p2, p3;
};
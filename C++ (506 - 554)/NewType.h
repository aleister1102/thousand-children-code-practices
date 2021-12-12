#pragma once
//Điểm Oxy
struct Point {
	double x;
	double y;
};
typedef struct Point xy;
//Đơn thức
struct monomial {
	double coefficient;
	double power;
};
typedef struct monomial mono;
mono operator* (mono& object1, mono& object2);
mono operator/ (mono& object1, mono& object2);
mono _DerivativeMono(mono para1);
//Đa thức
struct polimial
{
	mono term[100];
	int amount;
};
typedef struct polimial poli;
poli operator- (poli para1, poli para2);
poli operator+ (poli para1, poli para2);
poli operator* (poli para1, poli para2);
poli operator/ (poli para1, poli para2);
poli operator% (poli para1, poli para2);
//Phân số
struct fraction
{
	double numer;
	double deno;
};
typedef struct fraction frac;
frac operator+(frac para1, frac para2);
frac operator-(frac para1, frac para2);
frac operator*(frac para1, frac para2);
frac operator/(frac para1, frac para2);
frac operator++(frac para);
frac operator--(frac para);
//Hỗn số
struct mixnumber {
	int integer;
	frac fraction;
};
typedef struct mixnumber mix;
mix operator+(mix para1, mix para2);
mix operator-(mix para1, mix para2);
mix operator*(mix para1, mix para2);
mix operator/(mix para1, mix para2);
//Số phức
struct complex {
	double real;
	double ima;
};
typedef struct complex com;
com operator+(com para1, com para2);
com operator-(com para1, com para2);
com operator*(com para1, com para2);
com operator/(com para1, com para2);
com operator^(com para, int power);

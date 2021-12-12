#pragma once
//Bài 475
struct Fraction {
	int numerator;
	int denominator;
};
typedef struct Fraction frac;
//Bài 476
struct MixedNumber {
	int integer;
	int numerator;
	int denominator;
};
typedef struct MixedNumber mix;
//Bài 477
struct Point {
	double x;
	double y;
};
typedef struct Point xy;
//Bài 478
struct Point3D {
	int x; int y; int z;
};
typedef struct Point3D xyz;
//Bài 479
struct aPOWx {
	int a;
	int n;
}; typedef struct aPOWx apowx;
//Bài 480
struct Polimial {
	double coefficient[100];
	double power;
};
typedef struct Polimial P;
//Bài 481
struct Date {
	int day; int month; int year;
};
typedef struct Date date;
//Bài 482
struct Line {
	//Đường thẳng sẽ có dạng ax+by+c=0
	int a;
	int b;
	int c;
};
typedef struct Line line;
//Bài 483
struct circle {
	xy center;
	int radius;
};
typedef struct circle cir;
//Bài 485
struct Triangle {
	xy a;
	xy b;
	xy c;
};
typedef struct Triangle tri;
//Bài 486 - 492 (Đơn thức)
struct monomial {
	double coefficient;
	double power;
};
typedef struct monomial mono;
//Các toán tử nhân chia của đơn thức
mono operator* (mono& object1, mono& object2);
mono operator/ (mono& object1, mono& object2);
//Bài 487 - 505 (Đa thức)
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

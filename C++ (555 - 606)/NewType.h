#pragma once
//Điểm Oxy
struct Point {
	double x;
	double y;
};
typedef struct Point xy;
//Điểm Oxyz
struct Point3D {
	double x;
	double y;
	double z;
};
typedef struct Point3D xyz;
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
//Đường tròn
struct circle
{
	xy center;
	double radi;
}; typedef struct circle cir;
struct CoupleCircle {
	cir small;
	cir big;
};
typedef struct CoupleCircle coucir;
//Hình cầu
struct Sphere {
	xyz center;
	double radius;
}; typedef struct Sphere sph;
//Tam giác
struct Triangle {
	xy a;
	xy b;
	xy c;
}; typedef struct Triangle tri;
//Ngày tháng năm
struct Date {
	int day;
	int month;
	int year;
}; typedef struct Date date;
//Kiểu dữ liệu gồm 1 ngày có năm nhỏ và một ngày có năm lớn hơn
struct CoupleDate {
	date small;
	date big;
}; typedef struct CoupleDate coudate;

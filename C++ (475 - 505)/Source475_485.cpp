#include "Header.h"
#include"NewType.h"
//Bài 475
void Fraction() 
{
	frac num;
	cout << "Nhap tu so cho phan so" << endl;
	cin >> num.numerator;
	do {
		cout << "Nhap mau so cho phan so" << endl;
		cin >> num.denominator;
	} while (num.denominator == 0);
	cout << "Phan so da nhap la: " << num.numerator << "/" << num.denominator;
}
//Bài 476
void MixedNumber()
{
	mix num;
	cout << "Nhap phan nguyen" << endl;
	cin >> num.integer;
	do {
		cout << "Nhap tu so" << endl;
		cin >> num.numerator;
		cout << "Nhap mau so" << endl;
		cin >> num.denominator;
		int div = num.numerator / num.denominator;
		int remainder = num.numerator % num.denominator;
		//Xét trường hợp phần phân số lớn hơn 1 (phần nguyên được cộng thêm)
		if (div >= 1)
		{
			num.numerator = remainder;
			num.integer += div;
		}
	} while (num.integer == 0 || num.denominator == 0);
	cout << "Hon so da nhap la: " << num.integer << " " << num.numerator << "/" << num.denominator;
}
//Bài 477
xy Point()
{
	xy point;
	cout << "Nhap toa do x" << endl;
	cin >> point.x;
	cout << "Nhap toa do y" << endl;
	cin >> point.y;
	cout << "Toa do nhap vao la: (" << point.x << ":" << point.y << ")" << endl;
	return point;
}
//Bài 478
void Point3D() 
{
	xyz point;
	cout << "Nhap toa do x" << endl;
	cin >> point.x;
	cout << "Nhap toa do y" << endl;
	cin >> point.y;
	cout << "Nhap toa do z" << endl;
	cin >> point.z;
	cout << "Toa do nhap vao la: (" << point.x << ":" << point.y << ":" << point.z << ")";
}
//Bài 479
void _479() 
{
	apowx p;
	do {
		cout << "Nhap he so a" << endl;
		cin >> p.a;
		cout << "Nhap so mu n" << endl;
		cin >> p.n;
	} while (p.a == 0 || p.n == 0);
	cout << "Da thuc nhap vao la: " << p.a << "x^" << p.n << endl;
}
//Bài 480
void _480_I(P &poli) 
{
	cout << "Nhap so mu n" << endl;
	cin >> poli.power;
	cout << "Nhap he so cho tung so hang" << endl;
	for (int i = 0; i < poli.power;i++) {
		cin >> poli.coefficient[i];
	}
}
void _480_O(P poli)
{
	string plus = " + ";
	cout << "Da thuc P(x)= ";
	for (int i = 0 ; i < poli.power;i++) {
		if (i == poli.power-1)
			plus = "";
		cout << poli.coefficient[i] * (poli.power -i ) << "x^" << poli.power - i << plus;
	}
}
//Bài 481
void _481_I(date& time) 
{
	do {
		cout << "Nhap ngay: " << endl;
		cin >> time.day;
		cout << "Nhap thang: " << endl;
		cin >> time.month;
		cout << "Nhap nam: " << endl;
		cin >> time.year;
	} while (time.day < 1 || time.day >31 || time.month < 1 || time.month>12 || time.year < 1);
}
void _481_O(date time)
{
	cout << "Thoi diem da cho la: " << time.day << "/" << time.month << "/" << time.year;
}
//Bài 482
void _482_I(line &para)
{
	do {
		cout << "Phuong trinh co dang ax+by+c=0" << endl;
		cout << "Nhap he so a: " << endl;
		cin >> para.a;
		cout << "Nhap he so b: " << endl;
		cin >> para.b;
		cout << "Nhap he so c: " << endl;
		cin >> para.c;
	} while (para.a == 0);
}
void _482_O(line para)
{
	cout << "Duong thang co dang: " << para.a << "x + " << para.b << "y + " << para.c << " = 0";
}
//Bài 483: Đường tròn
cir Circle(cir &para) 
{
	do {
		cout << "Nhap toa do tam duong tron" << endl;
		cin >> para.center.x;
		cin >> para.center.y;
		cout << "Nhap ban kinh duong tron" << endl;
		cin >> para.radius;
	} while (para.radius == 0);
	int c = pow(para.center.x, 2) + pow(para.center.y, 2) - pow(para.radius, 2);
	cout << "Duong tron co phuong trinh: " <<
		"x^2 + y^2 - " << 2 * para.center.x << "x - " << 2 * para.center.y << "y + " << c << " = 0";
	return para;
}
//Bài 484: Chu vi diện tích đường/hình tròn
void Cal_Circle(cir& para)
{
	cir circle = Circle(para);
	double perimeter = 2.0 * circle.radius * 3.14;
	double surface = pow(circle.radius, 2) * 3.14;
	cout << endl;
	cout << "Chu vi cua hinh tron la: " << perimeter << endl;
	cout << "Dien tich cua hinh tron la: " << surface << endl;
}
//Bài 485: Chu vi diện tích tam giác
void Cal_Triangle(tri& para)
{
	do {
		cout << "Nhap toa do diem a" << endl;
		para.a = Point();
		cout << "Nhap toa do diem b" << endl;
		para.b = Point();
		cout << "Nhap toa do diem c" << endl;
		para.c = Point();
	} while (DuplicateXY(para.a, para.b) == true
		|| DuplicateXY(para.b, para.c) == true
		|| DuplicateXY(para.a, para.c) == true);
	//Công thức tính diện tích dựa vào ba đỉnh là: S=1/2 *abs((xB-xA)(yC-yA) - (xC-xA)(yB-yA))
	double inner = (para.b.x - para.a.x) * (para.c.y - para.a.y)
		- (para.c.x - para.a.x) * (para.b.y - para.a.y);
	double surface = 1.0 / 2 * abs(inner);
	double perimeter = VectorModule(para.a, para.b) +
		VectorModule(para.b, para.c) +
		VectorModule(para.a, para.c);
	double x_cross = (para.a.x + para.b.x + para.c.x) / 3;
	double y_cross = (para.a.y + para.b.y + para.c.y) / 3;
	cout << "Dien tich tam giac la: " << surface << endl;
	cout << "Chu vi tam giac la: " << perimeter << endl;
	cout << "Trong tam giac la: " << "("<<x_cross<<":"<<y_cross<<")"<< endl;
}
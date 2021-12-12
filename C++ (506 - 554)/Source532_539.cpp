#include "Header.h"
#include "NewType.h"
//533 - 534 (Nhập xuất số phức)
com Input_com()
{
	com result;
	cout << "Nhap phan thuc: " << endl;
	cin >> result.real;
	cout << "Nhap phan ao: " << endl;
	cin >> result.ima;
	return result;
}
string ComtoString(com para)
{
	string result, sign = " + ";
	if (para.ima < 0)
		sign = " ";
	result += Convert(para.real) + sign + Convert(para.ima) + "i";
	return result;
}
void Output_com(com para)
{
	cout << "So phuc co dang: ";
	cout << ComtoString(para);
	cout << endl;
}
//535 - 539 (Toán tử cơ bản của số phức)
com operator+(com para1, com para2)
{
	com result;
	result.real = para1.real + para2.real;
	result.ima = para1.ima + para2.ima;
	return result;
}
com operator-(com para1, com para2)
{
	com result;
	result.real = para2.real - para1.real;
	result.ima = para2.ima - para1.ima;
	return result;
}
com operator*(com para1, com para2)
{
	com result;
	result.real = para2.real*para1.real - para2.ima*para1.ima;
	result.ima = para1.real * para2.ima + para2.real * para1.ima;
	return result;
}
com operator/(com para1, com para2)
{	
	//Có công thức khai triển phép chia số phức:
	//c+di/a+bi = ac+bd/modu^2 + (ad-bc/modu^2)i 
	//Với modu là module của mẫu số
	
	//Module^2 số phức
	double modu2 = pow(para1.ima, 2) + pow(para1.real, 2);
	//Tính kết quả
	com result;
	result.real = (para1.real * para2.real + para1.ima * para2.ima) / modu2;
	result.ima = (para1.real * para2.ima - para2.real * para1.ima) / modu2;
	return result;
}
com operator^(com para, int power)
{
	com result = para;
	for (int i = 1; i < power-1; i++)
	{
		result = result * para;
	}
	return result;
}
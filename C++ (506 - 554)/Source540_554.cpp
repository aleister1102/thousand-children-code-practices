#include "Header.h"
#include "NewType.h"
//541 - 542
xy Input_xy()
{
	xy result;
	cout << "Nhap toa do x: " << endl;
	cin >> result.x;
	cout << "Nhap toa do y: " << endl;
	cin >> result.y;
	return result;
}
string XyToString(xy para)
{
	string result;
	result += "(" + Convert(para.x) + ";" + Convert(para.y) + ")";
	return result;
}
void Output_xy(xy para)
{
	cout << "Diem co toa do: ";
	cout << XyToString(para);
	cout << endl;
}
//544 - 545: Tính khoảng cách hai điểm theo Ox/Oy
double Distance_Ox(xy para1, xy para2)
{
	return abs(para1.x - para2.x);
}
double Distance_Oy(xy para1, xy para2)
{
	return abs(para1.y - para2.y);
}
xy Symmetry_xy(xy para)
{
	para.x = -para.x;
	para.y = -para.y;
	return para;
}
xy Symmetry_Ox(xy para)
{
	para.x = -para.x;
	return para;
}
xy Symmetry_Oy(xy para)
{
	para.y = -para.y;
	return para;
}
//Tìm điểm đối xứng qua y=x
//Lấy vào một điểm, trả về một điểm
//Hoán đổi tọa độ x và y
xy Symmetry_Y_X_(xy para)
{
	double temp = para.x;
	para.x = para.y;
	para.y = temp;
	return para;
}
//Tìm điểm đối xứng qua y=-x
//Lấy vào một điểm, trả về 1 điểm
//Hoán đổi tọa độ x và y sau đó đổi dấu cả 2
xy Symmetry_Y__X_(xy para)
{
	double temp = para.x;
	para.x = -para.y;
	para.y = -temp;
	return para;
}
//Kiểm tra các phần tư 
//Lấy vào một điểm và trả về 0 và 1 (không đúng và đúng)
bool FirstQuar(xy para)
{
	if (para.x > 0 && para.y > 0)
		return true;
	return false;
}
bool SecondQuar(xy para)
{
	if (para.x < 0 && para.y > 0)
		return true;
	return false;
}
bool ThirdQuar(xy para)
{
	if (para.x < 0 && para.y < 0)
		return true;
	return false;
}
bool ForthQuar(xy para)
{
	if (para.x > 0 && para.y < 0)
		return true;
	return false;
}

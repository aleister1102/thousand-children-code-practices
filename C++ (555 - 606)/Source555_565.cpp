#include "Header.h"
#include "NewType.h"
//556 - 557: Nhập xuất tọa độ Oxy
xyz Input_xyz()
{
	xyz result;
	cout << "Nhap cac toa do: " << endl;
	cout << "Nhap x,y va z " << endl;
	cin >> result.x >> result.y >> result.z;
	return result;
}
void Output_xyz(xyz para)
{
	cout << "Toa do trong OXYZ la: "
		<< "(" << para.x << ":" << para.y << ":" << para.z << ")" << endl;
}
//558 - 565: Các phép tính và biến đổi
double VectorModule3D(xyz para1,xyz para2)
{
	double a = pow(para1.x - para2.x, 2);
	double b = pow(para1.y - para2.y, 2);
	double c = pow(para1.z - para2.z, 2);
	return sqrt(a + b + c);
}
double Distance3D_X(xyz para1, xyz para2)
{
	return abs(para2.x - para1.x);
}
double Distance3D_Y(xyz para1, xyz para2)
{
	return abs(para2.y - para1.y);
}
double Distance3D_Z(xyz para1, xyz para2)
{
	return abs(para2.z - para1.z);
}
xyz SymmetryO(xyz para)
{
	para.x = - para.x;
	para.y = - para.y;
	para.z = - para.z;
	return para;
}
xyz SymmetryOxy(xyz para)
{
	para.z = -para.z;
	return para;
}
xyz SymmetryOxz(xyz para)
{
	para.y = -para.y;
	return para;
}
xyz SymmetryOyz(xyz para)
{
	para.x = -para.x;
	return para;
}

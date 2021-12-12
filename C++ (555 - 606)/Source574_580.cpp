#include "Header.h"
#include "NewType.h"
//575 - 576: Nhập xuất hình cầu
sph Input_sph()
{
	sph result;
	cout << "Nhap tam hinh cau: " << endl;
	result.center = Input_xyz();
	cout << "Nhap ban kinh: " << endl;
	cin >> result.radius;
	return result;
}
void Output_sph(sph para)
{
	cout << "((" << para.center.x << "," << para.center.y << "," << para.center.z << ")," << para.radius <<")"<< endl;
}
//577 - 578: Diện tích - Thể tích hình cầu
double S_Sphere(sph para)
{
	return 4.0 * 3.14 * pow(para.radius, 2);
}
double V_Sphere(sph para)
{
	return 4.0/3 * 3.14 * pow(para.radius, 3);
}

//579: Xét vị trí tương đối hai hình cầu
int SpherePosition(sph para1, sph para2)
{
	double d = VectorModule3D(para1.center, para2.center);
	if (d > para1.radius + para2.radius)
		return -1;
	else if (d < para1.radius + para2.radius)
		return 1;
	else
		return 0;
}

//580: Kiểm tra 1 điểm có nằm trong hình cầu
bool PointInSphere(sph para, xyz point)
{
	double d = VectorModule3D(para.center, point);
	if (d >= para.radius)
		return 0;
	return 1;
}


#include "Header.h"
#include "NewType.h"
//582 - 583: Nhập xuất tam giác trong mặt phẳng oxy
tri Input_tri()
{
	tri result;
	cout << "Nhap cac dinh cho tam giac: " << endl;
	result.a = Input_xy();
	result.b = Input_xy();
	result.c = Input_xy();
	return result;
}
string TriToString(tri para) {
	string s;
	s += "((" + Convert(para.a.x) + "," + Convert(para.a.y) + "); ("
		+ Convert(para.b.x) + "," + Convert(para.b.y) + "); ("
		+ Convert(para.c.x) + "," + Convert(para.c.y) + "))" + "\n";
	return s;
}
void Output_tri(tri para)
{
	cout << TriToString(para);
}

//584: Kiểm tra ba tọa độ có thành tam giác
bool CheckTriangle(tri para)
{
	//Ta chỉ cần tính tam giác của nó, nếu lớn hơn 0 là tam giác
	if (S_Triangle(para) > 0)
		return true;
	return false;
}

//585 - 586: Chu vi diện tích tam giác
double S_Triangle(tri para)
{
	double xb = para.b.x - para.a.x; double yb = para.b.y - para.a.y;
	double xc = para.c.x - para.a.x; double yc = para.c.y - para.a.y;
	return  abs(xb * yc - xc * yb) * 1.0 / 2;
}
double P_Triangle(tri para)
{
	double AB = VectorModule(para.b, para.a);
	double AC = VectorModule(para.a, para.c);
	double BC = VectorModule(para.b, para.c);
	return AB + AC + BC;
}

//587: Trọng tâm tam giác
xy CenterTriangle(tri para)
{
	xy result;
	result.x = (1.0/3) * (para.a.x + para.b.x + para.c.x);
	result.y = (1.0/3) * (para.a.y + para.b.y + para.c.y);
	return result;
}

//588: Tìm đỉnh có hoành độ lớn nhất
xy Tri_Max_x(tri para)
{
	double max = para.a.x;
	if (para.b.x > para.c.x && para.b.x > max)
		return para.b;
	else if (para.c.x > para.b.x && para.c.x > max)
		return para.c;
	else return para.a;
}

//589: Tìm đỉnh có tung độ nhỏ nhất
xy Tri_Min_y(tri para)
{
	double min = para.a.y;
	if (para.b.y < para.c.y && para.b.y < min)
		return para.b;
	else if (para.c.y < para.b.y && para.c.y < min)
		return para.c;
	else return para.a;
}

//590: Tính tổng khoảng cách từ P(x,y) đến ba đỉnh tam giác
double P_Distance(tri para, xy p)
{
	double a = VectorModule(para.a, p);
	double b = VectorModule(para.b, p);
	double c = VectorModule(para.c, p);
	return a + b + c;
}

//Hàm viết phương trình đường thẳng
poli StraightEquation(xy a, xy b)
{
	double slope = (b.y - a.y) / (b.x - a.x);
	double c = a.y - a.x * slope;
	poli result;
	result.term[0] = { slope,1 };
	result.term[1] = { c,0 };
	result.amount = 2;
	return result;
}
//Hàm kiểm tra xem điểm có thuộc đường thẳng
bool PointOnLine(poli para, xy point)
{
	if (Poli_at_x(para, point.x) == point.y)
		return true;
	return false;
}
//Hàm kiểm tra xem điểm có thuộc ba cạnh tam giác
bool PointOnTriangle(tri para, xy point)
{
	poli AB = StraightEquation(para.a, para.b);
	poli BC = StraightEquation(para.b, para.c);
	poli AC = StraightEquation(para.a, para.c);
	if (PointOnLine(AB, point) == true
		|| PointOnLine(BC, point) == true
		|| PointOnLine(AC, point) == true)
		return true;
	return false;
}
//Hàm tính tổng diện tích tam giác của 1 điểm tới ba đỉnh cho trước
double TripleSurface(tri para,xy point)
{
	double d_ac = S_Triangle({ point, para.a, para.c });
	double d_bc = S_Triangle({ point ,para.b ,para.c });
	double d_ab = S_Triangle({ point ,para.a ,para.b });
	return d_ac + d_bc + d_ab;
}
//591: Hàm kiểm tra điểm có bên trong tam giác
bool PointInTriangle(tri para, xy point)
{
	double tri_surface = TripleSurface(para, point);
	double surface = S_Triangle(para);
	if (PointOnTriangle(para, point))
		return false;
	if (tri_surface!=surface)
		return false;
	return true;
}

bool RightTriangle(double AB, double AC, double BC)
{
	double AB_2 = pow(AB, 2);
	double AC_2 = pow(AC, 2);
	double BC_2 = pow(BC, 2);
	if (AB_2 + AC_2 == BC_2 || AB_2 + BC_2 == AC_2 || BC_2 + AC_2 == AB_2)
		return true;
	return false;
}
//592: Hàm kiểm tra loại tam giác
int TriangleTypes(tri para)
{
	if(CheckTriangle(para)==false)
	{
		cout << "Khong phai tam giac" << endl; return 0;
	}
	cout << endl;
	double AB = VectorModule(para.a, para.b);
	double BC = VectorModule(para.b, para.c);
	double AC = VectorModule(para.a, para.c);
	if (AB == BC == AC)
	{
		cout << "Tam giac deu" << endl;
		return 1;
	}
	else if (AB == AC || BC == AC || AB == BC) {
		if (RightTriangle(AB, AC, BC))
		{
			cout << "Tam giac vuong can" << endl; return 3;
		}
		cout << "Tam giac can" << endl;
		return 4;
	}
	else if (RightTriangle(AB, AC, BC))
	{
		cout << "Tam giac vuong" << endl;
		return 2;
	}
	cout << "Tam giac thuong" << endl;
	return 5;
}

#include "Header.h"
#include "NewType.h"
//567 - 568: Nhập xuất dữ liệu cho đường tròn

//Nhập dữ liệu cho đường tròn
cir Input_cir()
{
	cir result;
	cout << "Nhap toa do tam: " << endl;
	result.center = Input_xy();
	cout << "Nhap ban kinh: " << endl;
	cin >> result.radi;
	return result;
}
//Xuất kiểu dữ liệu đường tròn
void Output_cir(cir para)
{
	cout << "(("<< para.center.x <<","<<para.center.y<< "),";
	cout << para.radi << ")" << endl;
}

//569 - 570: Chu vi diện tích hình tròn
double P_Circle(cir para)
{
	return 2.0 * 3.14 * para.radi;
}
double S_Circle(cir para)
{
	return 3.14 * pow(para.radi,2);
}

//571: Vị trí tương đối của hai đường tròn 
//Hàm lấy vào 2 đường tròn, trả về -1,1,0 lần lượt là:
//Không cắt, cắt, tiếp xúc
//Hoạt động: Dựa vào khoảng cách hai tâm mà so sánh với tổng hai bán kính
int CirclePosition(cir para1, cir para2)
{
	//Tính khoảng cách giữa hai tâm
	double d = VectorModule(para1.center,para2.center);
	if (d > para1.radi + para2.radi)
		return -1;
	else if (d < para1.radi + para2.radi)
		return 1;
	else
		return 0;
}
//572: Kiểm tra tọa độ có nằm trong đường tròn
//Hàm lấy vào đường tròn và tọa độ điểm cần xét
//Trả về 0 là nằm trên hoặc ngoài đường tròn
//Trả về 1 là bên trong đường tròn
//Nguyên lý: So sánh khoảng cách giữa điểm và bán kính
bool PointInCircle(cir para, xy point)
{
	double d = VectorModule(para.center, point);
	if (d >= para.radi)
		return 0;
	return 1;
}
//Kiểm tra đường tròn có nằm bên trong đường tròn hay không
//In: hai đường tròn, Out: một cặp đường tròn
//Nếu tâm đường tròn 1 trong tâm đường tròn 2 và 
//tổng khoảng cách tâm và bán kính đường tròn 1 bé hơn bán kính đường tròn 2
//Thì đường tròn 1 bên trong đường tròn 2
coucir CircleInCircle(cir para1, cir para2)
{
	double d = VectorModule(para1.center, para2.center);
	if (PointInCircle(para2, para1.center) == true && d + 2.0 * para1.radi <= para2.radi)
		return { para1,para2 };
	else if (PointInCircle(para1, para2.center) == true && d +  para2.radi <= para1.radi)
		return { para2,para1 };
	//Return về small và big cùng 1 hình tròn khi không cái nào trong cái nào
	return { para1,para1 };
}

//573: Tính diện tích trùng nhau
//Kiểu dữ liệu thể hiện các đoạn nhỏ của đường nối tâm
struct bisection {
	double a;//Thể hiện cho đoạn từ tâm 1 đến điểm giữa
	double b;//Từ điểm giữa đến tâm 2
};
typedef struct bisection bi;
//Tịnh tiến tâm và tính khoảng cách 2 tâm.
//Lấy vào 2 đường tròn, trả về khoảng cách giữa hai tâm.
//Hàm sẽ tính toán dựa trên toán học.
//Tịnh tiến về cho hai đường tròn cùng nằm trên trục ox.
double ChangeCenter(cir& para1, cir& para2)
{
	//Tính khoảng cách hai tâm dựa vào căn bậc hai của tổng bình phương hiệu các tọa độ.
	double d = sqrt(pow(para1.center.x - para2.center.x, 2) + pow(para1.center.y - para2.center.y, 2));
	//Tâm đường tròn 1 sẽ lấy làm gốc tọa độ.
	para1.center.x = 0; para1.center.y = 0;
	//Dựa vào khoảng cách tính được mà tịnh tiến tọa độ x của đường tròn 2 là khoảng cách 2 tâm (là d)
	para2.center.x = d; para2.center.y = 0;
	return d;
}
//Tính điểm giao giữa đường nối tâm và đường nối hai giao điểm của hai hình tròn (từ giờ gọi tắt là điểm giữa)
//Lấy vào 2 đường tròn và khoảng cách giữa hai tâm, trả về kiểu dữ liệu bisecton lưu hai đoạn nhỏ của đường nối tâm
//Hàm sẽ tính được phương trình giao điểm của hai đường tròn dựa trên công thức đã chứng minh
bi Center(cir para1, cir para2, double distance)
{
	double c = (pow(para1.radi, 2) - pow(para2.radi, 2) + pow(distance, 2)) / (2.0 * distance);
	//Bisection là đoạn nhỏ của trung trực tính từ điểm giữa đến tâm đường tròn thứ 2
	double bisection = distance - c;
	return { c,bisection };
}
//Hàm tính diện tích cung tròn bên trong mỗi hình tròn
//Lấy vào một đường tròn và khoảng cách giữa hai tâm
//Tính diện tích cung tròn nhỏ bằng cách tính diện tích cung tròn lớn (một phân mảnh của bánh pizza)
//rồi đem trừ cho tam giác có cùng góc chiếu (Tính cung tròn và tam giác tại một góc cố định)
double CurveSurface(double bisection, cir para)
{
	//Tính góc bằng cách dùng arccos cho nửa tam giác trên rồi nhân hai lên
	//(Đơn vị radian)
	double alpha = 2.0 * acos(bisection / para.radi);
	//Tìm diện tích cung tròn lớn và tam giác hoàn toàn dựa vào công thức toán
	double curve = pow(para.radi, 2) * alpha * 1.0 / 2;
	double triangle = (sqrt(pow(para.radi, 2) - pow(bisection, 2)) * bisection);
	//Trả về hiệu diện tích cung tròn lớn và tam giác sẽ được cung tròn nhỏ bên trong
	return curve - triangle;
}
//Hàm tính diện tích trùng nhau của hai đường tròn
//Lấy vào hai đường tròn, trả về diện tích phần trùng nhau
//Hoạt động: tính hai phần diện tích bị trùng của hai hình tròn rồi cộng lại
double DuplicateSurface(cir para1, cir para2)
{
	//Kiểm tra nếu hai hình tròn không cắt thì tính tổng
	if (CirclePosition(para1, para2) != 1)
		return 0;
	//Kiểm tra nếu hình tròn nằm trong hình tròn thì tính hình tròn nhỏ hơn
	coucir test = CircleInCircle(para1, para2);
	if (DuplicateXY(test.big.center, test.small.center) == false && test.big.radi != test.small.radi)
		return S_Circle(test.small);
	//Tạo ra một biến chứa các đoạn thẳng của đường nối tâm hai hình tròn
	//Đồng thời tịnh tiến hình tròn về trục Ox
	bi bisection = Center(para1, para2, ChangeCenter(para1, para2));
	double bisection1 = bisection.a;
	double bisection2 = bisection.b;
	//Tổng diện tích hai phần bị trùng của 2 đường tròn
	return CurveSurface(bisection1, para1) + CurveSurface(bisection2, para2);
}

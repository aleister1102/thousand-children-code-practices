#include "Header.h"
#include "NewType.h"
//Bài 486: Tích hai đơn thức
void _486(mono para1,mono para2)
{
	mono result;
	result.coefficient = para1.coefficient * para2.coefficient;
	result.power = para1.power + para2.power;
	cout << "Da thuc 1 la: " << para1.coefficient << "x^" << para1.power << endl;
	cout << "Da thuc 2 la: " << para2.coefficient << "x^" << para2.power << endl;
	cout << "Tich hai da thuc la: " << result.coefficient << "x^" << result.power << endl;
}
	//Bài 487: Đạo hàm bậc 1 đơn thức
mono _DerivativeMono(mono para1) 
{
	//Đạo hàm ax^n sẽ thành a*nx^n-1
	mono deriv;
	deriv.coefficient = para1.coefficient * para1.power;
	deriv.power = para1.power - 1;
	//cout << "Dao ham cua don thuc "
	//	<< para1.coefficient << "x^" << para1.power
	//	<< " la " << deriv.coefficient << "x^" << deriv.power << endl;
	return deriv;
}
//Bài 488 : Thương 2 đơn thức
void _488(mono para1, mono para2) 
{
	//Thương hai đơn thức thì lấy hệ số chia, số mũ trừ
	cout << "Thuong don thuc "
		<< para1.coefficient << "x^" << para1.power << " va "
		<< para2.coefficient << "x^" << para2.power << " la "
		<< para1.coefficient / para2.coefficient << "x^"
		<< para1.power - para2.power << endl;
}
//Bài 489: Đạo hàm cấp k đơn thức
void _489(mono para1)
{
	int k = 0;
	mono deriv = para1;
	cout << "Nhap vao bac dao ham (>0)" << endl;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		deriv.coefficient *= deriv.power;
		deriv.power -= 1;
	}
	if (deriv.coefficient == 0)
	{
		cout << "Dao ham cua don thuc "
			<< para1.coefficient << "x^"
			<< para1.power << " la: " << 0 << endl;
	}
	else {
		cout << "Dao ham cua don thuc "
			<< para1.coefficient << "x^"
			<< para1.power << " la: "
			<< deriv.coefficient << "x^" << deriv.power << endl;
	}
}
//Bài 490: Tính giá trị đơn thức tại x=x0
void _490(mono para1)
{
	double x;
	cout << "Nhap x0: " << endl; cin >> x;
	cout << "Gia tri cua don thuc "
		<< para1.coefficient << "x^"
		<< para1.power << " la "
		<< para1.coefficient * pow(x, para1.power) << endl;
}
//Bài 491: Định nghĩa toán tử nhân cho 2 đơn thức
mono operator* (mono &object1, mono &object2)
{
	return { object1.coefficient * object2.coefficient,object1.power + object2.power };
}
//Bài 492: Định nghĩa toán tử chia cho 2 đơn thức
mono operator/ (mono &object1, mono &object2)
{
	return { object1.coefficient / object2.coefficient,object1.power - object2.power };
}

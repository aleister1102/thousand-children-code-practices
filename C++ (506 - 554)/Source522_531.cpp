#include "Header.h"
#include "NewType.h"
//523 - 524: Nhập xuất hỗn số
mix Input_mix()
{
	mix para;
	cout << "Nhap phan nguyen: " << endl;
	cin >> para.integer;
	cout << "Nhap phan so: " << endl;
	para.fraction = Input();
	return para;
}
void Output_mix(mix para)
{
	cout << "Hon so co dang: "
		<< para.integer << " "
		<< para.fraction.numer << "/"
		<< para.fraction.deno << endl;
}
//525: Rút gọn hỗn số 
mix Simpler_mix(mix para)
{
	//Rút gọn phần phân số thành tối giản 
	para.fraction=Simpler(para.fraction);
	//Rút gọn các hỗn số với phần phân số > 1
	//Chuyển thành int để tìm số dư
	int r_num = para.fraction.numer;
	int r_deno = para.fraction.deno;
	int remain = r_num % r_deno;
	int div = r_num / r_deno;
	if (div >= 1)
	{
		para.integer += div; 
		para.fraction.numer = remain;
	}
	return para;
}
//Hàm biến đổi hỗn số thành phân số
frac MixToFrac(mix para)
{
	frac integer = { para.integer,1 };
	return (integer + para.fraction);
}
//526 - 529: Các toán tử cơ bản cho hỗn số
mix operator+(mix para1, mix para2)
{
	mix result;
	result.integer = para1.integer + para2.integer;
	result.fraction = para1.fraction + para2.fraction;
	result =Simpler_mix(result);
	return result;
}
mix operator-(mix para1, mix para2)
{
	mix result;
	result.integer = para2.integer - para1.integer;
	result.fraction = para2.fraction - para1.fraction;
	Simpler_mix(result);
	return result;
}
mix operator*(mix para1, mix para2)
{
	frac a= MixToFrac(para1);
	frac b= MixToFrac(para2);
	frac temp = a * b;
	mix result = { 0,temp };
	result=Simpler_mix(result);
	return result;
}
mix operator/(mix para1, mix para2)
{
	frac a= MixToFrac(para1);
	frac b= MixToFrac(para2);
	frac temp = a / b;
	mix result = { 0,temp };
	result=Simpler_mix(result);
	return result;
}
//530: Kiểm tra hỗn số tối giản
bool Simplest_mix(mix para)
{
	int r_num = para.fraction.numer;
	int r_deno = para.fraction.deno;
	int remain = r_num % r_deno;
	int div = r_num / r_deno;
	//Kiểm tra phần phân số xem có > 1 
	if (div < 1)
		return true;
	else return false;
}
//531: Quy đồng hai hỗn số
void SameDeno_mix(mix para1, mix para2)
{
	frac a = MixToFrac(para1);
	frac b = MixToFrac(para2);
	SameDeno(a, b);
	Output(a);
	Output(b);
}

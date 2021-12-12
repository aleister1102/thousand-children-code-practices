#include "Header.h"
#include "NewType.h"
double IntToDecimal(int n,int count)
{
	//Gán kết quả kiểu double bằng tham số int
	double num = n;
	int times = count;
	//Vòng lặp chia 10 thành số thập phân
	while (times > 0)
	{
		num /= 10;
		times -= 1;
	}
	return num;
}
int DecimalToInt(double n,int &count)
{
	int times = count;
	//Vòng lặp nhân 10 thành số nguyên
	//Điều kiện kết thúc vòng lặp là nhân đến
	//khi nào số làm tròn bằng phần nguyên
	//(lúc ấy số thập phân có một số sau dấu chấm)
	while (n-round(n)!=0)
	{
		n *= 10;
		count += 1;
	}
	return n;
}
double GCD_double(double a, double b)
{
	//Giải pháp là chuyển về số nguyên rồi tìm GCD bình thường
	//Chuyển thành số nguyên và tìm ước chung
	int count_a = 0; int count_b = 0;
	int num = GCD(DecimalToInt(a,count_a), DecimalToInt(b,count_b));
	//Tìm số nhỏ hơn
	double min = a; int count = count_a;
	if (b < min)
	{
		min = b; count = count_b;
	}
	//Chuyển từ int sang số thập phân trở lại
	double result = IntToDecimal(num, count);
	return result ;
}
frac Input()
{
	frac para;
	cout << "Nhap tu so: " << endl;
	cin >> para.numer;
	cout << "Nhap mau so: " << endl;
	cin >> para.deno;
	return para;
}
void Output(frac para)
{
	cout << "Phan so co dang la: "
		<< para.numer << "/" << para.deno << endl;
}
//Bài 506: Hàm tối giản phân số
frac Simpler(frac para)
{
	double div = GCD_double(para.numer, para.deno);
	para.deno /= div;
	para.numer /= div;
	return para;
}
//Bài 507 - 510 (516 - 519) (Các hàm tính tổng/hiệu/tích/thương và toán tử tương ứng)
frac operator+(frac para1, frac para2)
{
	//Quy đồng mẫu số
	frac result;
	result.numer = (para1.deno * para2.numer) + (para2.deno * para1.numer);
	result.deno = para1.deno * para2.deno;
	Simpler(result);
	return result;
}
frac operator-(frac para1, frac para2)
{
	//Quy đồng mẫu số
	frac result;
	result.deno = (para2.deno * para1.numer) - (para1.deno * para2.numer);
	result.numer = para1.deno * para2.deno;
	Simpler(result);
	return result;
}
frac operator*(frac para1, frac para2)
{
	frac result;
	result.deno = para1.deno * para2.deno;
	result.numer = para1.numer * para2.numer;
	Simpler(result);
	return result;
}
frac operator/(frac para1, frac para2)
{
	//Đảo ngược phân số thứ 2
	//Tuy nhiên chương trình lại lấy para1 làm phân số thứ 2
	double temp = para1.deno;
	para1.deno = para1.numer;
	para1.numer = temp;
	return Simpler(para1 * para2);
}
//Bài 511: Kiểm tra xem phân số có tối giản chưa
bool Simplest(frac para)
{
	double div = GCD_double(para.numer, para.deno);
	//Thiết lập sao cho dấu trừ luôn ở tử
	if (para.deno > 0 && para.numer < 0)
	{
		para.deno = -para.deno; para.numer = -para.numer;
	}
	//Phân số tối giản khi ước chung lớn nhất của tử và mẫu là 1	
	if (div == 1)
		return true;
	return false;
}
//Bài 512: Quy đồng mẫu số
void SameDeno(frac &para1, frac &para2)
{
	double deno = para1.deno;
	double numer = para1.numer;
	para1.deno *= para2.deno;
	para1.numer *= para2.deno;
	para2.deno *= deno;
	para2.numer *= numer;
}
//Bài 513 - 514: Kiểm tra dấu phân số
bool SignFraction(frac para)
{
	//Nếu dương thì true, âm thì false
	if (para.deno / para.numer > 0)
		return true;
	return false;
}
//Bài 515: So sánh hai phân số
double FracToDouble(frac para)
{
	return para.numer / para.deno;
}
int CompareFraction(frac para1, frac para2)
{
	double result = FracToDouble(para2 - para1);
	if (result > 0)
		return 1;
	else if (result < 0)
		return -1;
	else return 0;
}
//Bài 520 - 521: Toán tử ++frac và --frac
frac operator++(frac para)
{
	frac one = { 1,1 };
	return para + one;
}
frac operator--(frac para)
{
	frac one = { 1,1 };
	return para - one;
}



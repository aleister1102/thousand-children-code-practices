#include "Header.h"
#include "NewType.h"

bool LeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
//594: Nhập ngày
date Input_date()
{
	date result;
	do {
		cout << "Nhap ngay,thang va nam " << endl;
		cin >> result.day >> result.month >> result.year;
	} while (result.day < 1 || result.day>31 || result.month < 1 || result.month>12 || result.year < 1 || (result.day > 29 && result.month == 2));
	if (LeapYear(result.year) == false && result.day > 28 && result.month == 2)
		cout << "Ngay khong hop le" << endl;
	return result;
}
//595: Xuất ngày
void Output_date(date para)
{
	cout << "(" << para.day << "/" << para.month << "/" << para.year << ")" << endl;
}
//Nhập thời gian
timee Input_timme()
{
	timee result;
	do {
		cout << "Nhap gio: "; cin >> result.hour;
		cout << "Nhap phut: "; cin >> result.minute;
		cout << "Nhap giay: "; cin >> result.second;
	} while (result.hour > 24 || result.hour < 0 || result.minute < 0 || result.minute>59 || result.second < 0 || result.second>59);
	return result;
}
//Xuất thời gian
void Output_timee(timee para)
{
	cout << "(" << para.hour << ":" << para.minute << ":" << para.second << ")" << endl;
}
//607: Nhập xuất tỉnh
province Input_prov()
{
	province result;
	cout << "Nhap ma tinh: ";
	cin>>result.codex;
	cin.ignore(32767, '\n');
	cout << "Nhap ten tinh: ";
	gets_s(result.name);
	cout << "Nhap dien tich (km^2): ";
	cin >> result.surface;
	return result;
}
void Output_prov(province param)
{
	cout << "Thong tin cua tinh la: " << endl;
	cout << "Ma tinh: " << param.codex << endl;
	cout << "Ten tinh: " << param.name << endl;
	cout << "Dien tich: " << param.surface <<"km^2"<< endl;
}

//608: Nhập xuất hộp sữa
milk Input_milk()
{
	milk result;
	cout << "Nhap nhan hieu hop sua: ";
	gets_s(result.brand);
	cout << "Nhap trong luong: ";
	cin >> result.weight;
	cout << "Nhap han su dung: ";
	result.expiry = Input_date();
	return result;
}
void Output_milk(milk param)
{
	cout << "Thong tin hop sua: " << endl;
	cout <<"Nhan hieu: "<<param.brand << endl;
	cout <<"Trong luong: "<<param.weight <<"N"<< endl;
	cout << "Han su dung "; Output_date(param.expiry);
}

//609: Vé xem phim
tic Input_tic()
{
	tic result;
	cout << "Nhap ten phim: ";
	gets_s(result.name);
	cout << "Nhap gia tien: ";
	cin >> result.price;
	cout << "Nhap gio chieu (h:m::s): ";
	cin >> result.dis.hour >> result.dis.minute >> result.dis.second;
	cout << "Nhap ngay chieu: ";
	result.day = Input_date();
	return result;
}
void Output_tic(tic param)
{
	cout << "Thong tin ve xem phim: " << endl;
	cout << "Ten phim: " << param.name << endl;
	cout << "Gia tien: " << param.price << endl;
	cout << "Gio chieu: (" << param.dis.hour << ":" << param.dis.minute << ":" << param.dis.second << ")" << endl;
	cout << "Ngay chieu - "; Output_date(param.day);
	cout << endl;
}

//610: Mặt hàng
pro Input_pro()
{
	pro result;
	cout << "Nhap ten mat hang ";
	gets_s( result.name);
	cout << "Nhap don gia ";
	cin >> result.price;
	cout << "Nhap so luong ton ";
	cin >> result.quantity;
	return result;
}
void Output_pro(pro para)
{
	cout << "Thong tin mat hang: " << endl;
	cout << "Ten mat hang: " << para.name << endl;
	cout << "Don gia: " << para.price << endl;
	cout << "So luong ton: " << para.quantity << endl;
}

//611: Chuyến bay
fly Input_fly()
{
	fly result;
	cout << "Nhap ma chuyen bay ";
	gets_s(result.code);
	cout << "Nhap ngay bay  " << endl;
	result.day = Input_date();
	cout << "Nhap gio bay  " << endl;
	result.time = Input_timme();
	cout << "Di tu: ";
	cin.ignore(32767, '\n');
	gets_s(result.from);
	cout << "Den: ";
	gets_s(result.dest);
	return result;
}
void Output_fly(fly para)
{
	cout << "Thong tin chuyen bay la: " << endl;
	cout << "Ma chuyen bay: " << para.code << endl;
	cout << "Ngay bay - "; Output_date(para.day);
	cout << "Gio bay - "; Output_timee(para.time);
	cout << "Noi di: " << para.from << endl;
	cout << "Noi den: " << para.dest << endl;
}

//612: Cầu thủ
socplay Input_socplay()
{
	socplay result;
	cout << "Nhap ma cau thu: ";
	gets_s(result.code);
	cout << "Nhap ten cau thu: ";
	gets_s(result.name);
	cout << "Nhap ngay sinh - ";
	result.born = Input_date();
	return result;
}
void Output_socplay(socplay para)
{
	cout << "Cau thu co thong tin: " << endl;
	cout << "Ma cau thu: " << para.code << endl;
	cout << "Ten cau thu: " << para.name << endl;
	cout << "Ngay sinh: "; Output_date(para.born);
}

//613: Đội bóng
fc Input_fc()
{
	
	fc result; int num;
	cout << "Nhap ma doi bong: ";
	gets_s(result.code);
	cout << "Nhap ten doi bong: ";
	gets_s(result.name);
	cout << "Nhap cac thanh vien doi bong: " << endl;
	cout << "Nhap bao nhieu thanh vien ?" << endl; cin >> num;
	cin.ignore(32676, '\n');
	for (int i = 0; i < num; i++)
	{
		result.list[i] = Input_socplay();
		cin.ignore(32676, '\n');
	}
	return result;
}
void Output_fc(fc para)
{
	int num;
	cout << "Thong tin doi bong: " << endl;
	cout << "Ma doi bong: " << para.code << endl;
	cout << "Ten doi bong: " << para.name << endl;
	cout << "Muon xuat ra danh sach bao nhieu cau thu ?" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		Output_socplay(para.list[i]);
	}
}

//614: Nhân viên
staff Input_staff()
{
	staff result;
	cout << "Nhap thong tin nhan vien: " << endl;
	cout << "Nhap ma nhan vien: " << endl;
	gets_s(result.code);
	cout << "Nhap ten nhan vien: " << endl;
	gets_s(result.name);
	cout << "Nhap luong nhan vien: " << endl;
	cin >> result.sala;
	return result;
}
void Output_staff(staff para)
{
	cout << "Thong tin nhan vien la: " << endl;
	cout << "Ma nhan vien: " << para.code << endl;
	cout << "Ten nhan vien: " << para.name << endl;
	cout << "Luong nhan vien: " << para.sala << endl;
}
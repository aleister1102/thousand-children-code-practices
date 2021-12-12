#include "Header.h"
#include "NewType.h"
//615: Thí sinh
candi Input_candi()
{
	candi result;
	cout<<"Nhap thong tin thi sinh: " << endl;
	cout << "Nhap ma thi sinh: " << endl;
	gets_s(result.code);
	cout << "Nhap ten thi sinh: " << endl;
	gets_s(result.name);
	cout << "Nhap diem toan, ly va hoa: " << endl;
	cin >> result.math >> result.phys >> result.chem;
	result.total = result.math + result.phys + result.chem;
	return result;
}
void Output_candi(candi para)
{
	cout << "Thong tin thi sinh la: " << endl;
	cout << "Ma sinh: " << para.code << endl;
	cout << "Ten thi sinh: " << para.name << endl;
	cout << "Diem toan: " << para.math << endl;
	cout << "Diem ly: " << para.phys << endl;
	cout << "Diem hoa: " << para.chem << endl;
	cout << "Diem tong: " << para.total<< endl;
}

//616: Luận văn
ess Input_ess()
{
	ess result;
	cout << "Nhap thong tin luan van" << endl;
	cout << "Nhap ma luan van: " << endl; gets_s(result.code);
	cout << "Nhap ten luan van: " << endl; gets_s(result.name);
	cout << "Nhap sinh vien thuc hien: " << endl; gets_s(result.stu);
	cout << "Nhap giao vien huong dan: " << endl; gets_s(result.teac);
	cout << "Nhap nam thuc hien: " << endl; cin>>result.year;
	return result;
}
void Output_ess(ess para)
{
	cout << "Thong tin luan van" << endl;
	cout << "Ma luan van: " <<para.code<< endl;
	cout << "Ten luan van: " <<para.name << endl; 
	cout << "Sinh vien thuc hien: " <<para.stu<< endl;
	cout << "Giao vien huong dan: " <<para.teac<<endl;
	cout << "Nam thuc hien: " <<para.year <<endl; 
}

//617: Học sinh
stu Input_stu()
{
	stu result;
	cout << "Nhap thong tin hoc sinh: " << endl;
	cout << "Nhap ten hoc sinh: " << endl; gets_s(result.name);
	cout << "Nhap diem toan: " << endl; cin >> result.math;
	cout << "Nhap diem van: " << endl; cin >> result.lit;
	result.avg = (result.math + result.lit) / 2.0;
	return result;
}
void Output_stu(stu para)
{
	cout << "Thong tin hoc sinh: " << endl;
	cout << "Ten hoc sinh: " <<para.name<< endl; 
	cout << "Diem toan: " <<para.math<< endl; 
	cout << "Diem toan: " <<para.lit<< endl; 
	cout << "Diem trung binh: " <<para.avg<<endl; 
}

//618 - 613 là tương tự nhau, 619, 620 tương tự mấy bài trên


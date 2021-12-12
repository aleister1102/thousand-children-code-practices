#include "Header.h"
#include "NewType.h"
//Bài 493 - 505 (501 - 504 tương tự 493 - 496)

//Hàm hoán vị hai phần tử kiểu mono (Đơn thức)
void swapping_mono(mono& para1, mono &para2)
{
	mono temp = para1;
	para1 = para2;
	para2 = temp;
}
//Hàm sắp xếp đa thức số mũ giảm dần (Dùng bubble sort cho số mũ)
void Arrange(poli& para)
{
	for (int i = 0; i <= para.amount-1; i++) {
		bool check = false;
		for (int j = 0; j < para.amount - i - 1; j++) {
			if (para.term[j].power < para.term[j + 1].power)
			{
				swapping_mono(para.term[j], para.term[j + 1]); check = true;
			}
		}
		if (check == false)
			break;
	}
}
//Hàm cộng các phần tử có cùng số mũ trong đa thức
void MonoInPoli(poli& result) {
	
	for (int i = 0; i < result.amount; i++) {
		for (int j = i + 1; j < result.amount; j++) {
			if (result.term[i].power == result.term[j].power)
			{
				result.term[i].coefficient += result.term[j].coefficient;
				//Hệ số của đa thức được cộng cho bằng 0 để loại bỏ
				result.term[j].coefficient = 0;
			}
		}
	}
}
//Hàm chuyển đổi kiểu double sang string
string Convert(double para)
{
	stringstream ss;
	string s;
	ss << para; ss >> s;
	return s;
}
//Hàm chuyển từ Polimial sang string
string Poli(poli para)
{
	string polimial;
	string sign[2] = { " + "," " };//Dấu của các số hạng
	for (int i = 0; i < para.amount; i++) {
		//Mỗi vòng lặp thì dấu reset về dấu +
		string out = sign[0];
		//Nếu hệ số là 0 hoặc có số mũ bé hơn 0 thì chuyển sang lần lặp kế
		if (para.term[i].coefficient == 0 || para.term[i].power < 0)
			continue;
		//Nếu số hạng kế tiếp có hệ số < 0
		//Hoặc phần tử hiện tại là số hạng cuối
		//Thì dấu sẽ là chuỗi rỗng
		if (para.term[i + 1].coefficient <= 0 || i == para.amount - 1)
			out = sign[1];
		polimial += Convert(para.term[i].coefficient) + "x^" + Convert(para.term[i].power)+ out;
	}
	return polimial;
}
poli Input(poli& para)
{
	//Hàm nhập đa thức
	cout << endl;
	cout << "Nhap so luong phan tu" << endl;
	cin >> para.amount;
	for (int i = 0; i < para.amount; i++) {
		cout << "Nhap he so: "; cin >> para.term[i].coefficient;
		cout << "Nhap so mu: "; cin >> para.term[i].power;
	}
	return para;
}
poli Output(poli para)
{
	MonoInPoli(para);
	Arrange(para);
	//Hàm xuất đa thức
	cout << "Da thuc co dang: ";
	cout << Poli(para) << endl;
	return para;
}
//Các toán tử dùng cho đa thức
poli operator+ (poli para1, poli para2)
{
	//Add 2 to 1
	poli result = para1;//Đa thức kết quả
	//Vòng lặp cộng hai đa thức, mỗi lần cộng tăng kích thước đa thức
	for (int i = 0; i < para2.amount; i++)
	{
		//Cộng ở đây thực chất là gán bằng, xuất phát từ cuối đa thức đầu
		result.term[result.amount].coefficient =para2.term[i].coefficient;
		result.term[result.amount].power = para2.term[i].power;
		result.amount += 1;
	}
	//Vòng lặp xử lý các đơn thức cùng số mũ (cộng lại)
	MonoInPoli(result);
	return result;
}
poli operator- (poli para1, poli para2)
{
	//Minus 2 for 1
	poli result = para1;
	//Vòng lặp trừ hai đa thức, mỗi lần trừ tăng kích thước đa thức
	for (int i = 0; i < para2.amount; i++)
	{
		//Trừ ở đây thực chất là gán bằng số âm, xuất phát từ cuối đa thức đầu
		result.term[result.amount].coefficient = -para2.term[i].coefficient;
		result.term[result.amount].power = para2.term[i].power;
		result.amount += 1;
	}
	//Vòng lặp xử lý các đơn thức cùng số mũ (cộng lại)
	MonoInPoli(result);
	return result;
}
poli operator* (poli para1, poli para2)
{
	poli result; int index = 0;
	result.amount = para1.amount * para2.amount;
	//Nhân từng số hạng của para1 cho para2 rồi ghi vào đa thức result
	for (int i = 0; i < para1.amount; i++) {
		for (int j = 0; j < para2.amount; j++) {
			result.term[index++] = para1.term[i] * para2.term[j];
		}
	}
	//Sắp xếp và cộng cùng số mũ
	Arrange(result);
	MonoInPoli(result);
	return result;
}
poli operator/ (poli para1, poli para2)
{
	poli result; int index = 0;
	result.amount = para1.amount * para2.amount;
	//Ý tưởng tương tự toán tử nhân, khác là dùng phép chia
	for (int i = 0; i < para1.amount; i++) {
		for (int j = 0; j < para2.amount; j++) {
			result.term[index++] = para1.term[i] / para2.term[j];
		}
	}
	Arrange(result);
	MonoInPoli(result);
	return result;
}
poli operator% (poli para1, poli para2)
{
	//Ý tưởng được lấy trực tiếp ra từ toán học
	//Ví dụ có 3x^2+4x+3 (đa thức bị chia) chia cho 2x+1 (đa thức chia)
	//Ta lấy 3x^2 chia cho 2x được 3x/2, sau đó nhân 3x/2 cho 2x+1 được 3x^2+3x/2
	//(Ở đây 3x/2 là thương và 3x^2+3x/2 là tích của thương và đa thức chia)
	//Sau đó lấy đa thức bị chia trừ cho tích của thương và đa thức chia.
	//Cứ tiếp tục quy trình cho đến khi không chia được nữa (thương có số mũ âm) thì trả về đa thức dư
	MonoInPoli(para1);
	MonoInPoli(para2);
	poli result; int index = 0;
	//Ước lượng đa thức thương có số số hạng bằng đa thức bị chia (hoặc bé hơn)
	result.amount = para1.amount;
	for (int i = 0; i < para1.amount; i++) {
		for (int j = 0; j < para2.amount; j++) {
			
			//Thương bằng đa thức bị chia chia cho phần tử đầu đa thức chia
			result.term[index] = para1.term[i] / para2.term[j];
			//Đa thức temp lưu đa thức nhân ngược lại của thương và đa thức chia
			poli temp; int m = 0;
			//Vòng lặp nhân result cho đa thức chia (para2)
			for (int k = 0; k < para2.amount; k++) {
				temp.term[m++] = result.term[index] * para2.term[k];
			}
			temp.amount = m;
			//Nếu đa thức dư chia cho đa thức chia mà không hết (số mũ bé hơn)
			//Thì trả về số dư
			if (result.term[index].power < 0)
				return para1;
			//Đa thức ban đầu trừ cho đa thức temp (tích của thương và đa thức chia)
			para1 = para1 - temp;
			//Chuyển sang số hạng kế tiếp của đa thức bị chia
			index += 1;
		}
	}
	return para1;
}
//Hàm tính đạo hàm một đa thức 
poli Derive(poli para)
{
	//(Bản chất là đạo hàm đơn thức nhỏ lẻ ở trong)
	poli result = para;
	for (int i = 0; i < result.amount; i++) {
		result.term[i] = _DerivativeMono(para.term[i]);
	}
	MonoInPoli(result);
	return result;
}
//Hàm tính đạo hàm bậc k
poli Derive_k(poli para)
{
	//Ý tưởng tương tự đạo hàm bậc 1, chỉ là dùng vòng lặp
	int k;
	cout << "Dao ham bac k la ?" << endl;
	cin >> k;
	poli result = para;
	for (int i = 1; i <= k; i++) {
		result=Derive(result);
	}
	MonoInPoli(result);
	return result;
}
//Tính giá trị đa thức tại x
double Poli_at_x(poli para,double x)
{
	double sum = 0;
	for (int i = 0; i < para.amount; i++) {
		sum += para.term[i].coefficient * pow(x, para.term[i].power);	
	}
	return sum;
} 
//Tìm nghiệm đa thức trong đoạn cho trước
double Poli_root(poli para)
{
	double left, right;
	cout << "Trong doan [a,b], nhap a: " << endl;
	cin >> left; cout << "  Nhap b: " << endl;
	cin >> right;
	const double epsilon = 0.000000001;
	double steps = epsilon*10000;
	double distance = abs(Poli_at_x(para, left));
	double root = left;
	for (double i = left; i <= right; i += steps) {
		if (abs(Poli_at_x(para,i)) < distance ) {
			distance = abs(Poli_at_x(para, i));
			root = i;
		}
	}
	return root;
}
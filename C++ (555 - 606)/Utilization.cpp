#include "Header.h"
#include "NewType.h"
//Tìm ước chung nhờ thuật toán chia Euclid
int GCD(int a, int b)
{
	//biến temp lưu số mỗi vòng lặp
	int temp;
	//Sau vòng lặp 1 thì a là b, số bị chia thành số chia
	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}
bool divisor(int n, int b)
{
	//Nếu phép chia 0 xảy ra thì return false
	if (b == 0)
		return false;
	if (n % b == 0)
		return true;
	return false;
}
bool Elementary(int n)
{
	int count = 0;
	if (n <= 1) return false;
	for (int i = 1; i <= n; i++)
	{
		if (divisor(n, i)) {
			count += 1;
		}
	}
	if (count == 2)
		return true;
	return false;
}
bool SquareNumber(int n)
{
	//Việc tìm số chính phương này chưa tối ưu
	//Tính chính xác dựa vào độ lớn giá trị của kiểu dữ liệu (sai số)
	int a = sqrt(n);
	//Số chính phương phải tính với n>1
	if (a * a == n && n > 1) {
		return true;
	}
	else
		return false;
}
bool Perfect_Number(int n) {
	int num = 0;
	for (int i = 1; i < n; i++) {
		if (divisor(n, i))
			num += i;
	}
	//Khoảng xét là các số nguyên lớn hơn 1
	if (num == n && n > 1)
		return true;
	else
		return false;
}
int Reverse(int number)
{
	int reverse = 0;
	while (number > 0)
	{
		//Các số dư sẽ tách ra
		int remainder = number % 10;
		//Giảm đi 10 lần để tách số
		number /= 10;
		//Số dư cộng vào số đão
		//Nhân cho 10 khiến cho các số dịch trái một vị trí
		reverse = reverse * 10 + remainder;
	}
	return reverse;
}
bool All_Odd(int n) {
	while (n > 0) {
		int remainder = n % 10;
		if (remainder % 2 == 0)
			return false;
		n /= 10;
	}
	return true;
}
bool Power_Check(int n, int base) {
	while (n > base) {
		int a = n % base;
		if (a != 0) {
			return false;
		}
		n /= base;
	}return true;
}
bool First_Odd_Even(int number) {
	//True là số bắt đầu là lẻ, false là số bắt đầu là chẵn
	//Có thể dùng kiểm tra chẵn lẻ cho số 1 chữ số
	int remainder = 1;
	//Kiểm tra hai chữ số
	while (number > 0)
	{
		remainder = number % 10;
		number /= 10;
	}
	//Kiểm tra số 1 chữ số
	if (number / 10 == 0)
	{
		if (remainder % 2 == 0)
			return false;
		else
			return true;
	}
}

//Hàm tính số chữ số
int AmountofNumber(int n)
{
	int count = 0;
	for (; n > 0;)
	{
		n /= 10;
		count += 1;
	}
	return count;
}
//Hàm swapping hai số double/int
void swapping(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}
//Hàm convert double to string
string Convert(double para)
{
	stringstream ss;
	string s;
	ss << para; ss >> s;
	return s;
}
//Hàm đếm số chữ số sau dấu phẩy (giới hạn tổng 15 chữ số không kể dấu chấm)
int Count_after_point(double n)
{
	string s;
	stringstream ss;
	//Set độ chính xác cho số với tổng cộng 15 số hai phía dấu chấm
	ss << setprecision(15) << n; ss >> s;
	//Biến số đại diện cho vị trí của dấu chấm (theo index mảng)
	size_t pos = s.find(".");
	//Số chữ số bằng độ dài chuỗi trừ vị trí dấu chấm (trừ thêm 1 do là index mảng)
	int digits = 0;
	if (pos != string::npos)
		digits = s.length() - 1 - pos;
	return digits;
}


//Hàm hoán vị hai phần tử kiểu mono (Đơn thức)
void swapping_mono(mono& para1, mono& para2)
{
	mono temp = para1;
	para1 = para2;
	para2 = temp;
}
//Toán tử cho đơn thức
mono operator* (mono& object1, mono& object2)
{
	return { object1.coefficient * object2.coefficient,object1.power + object2.power };
}
mono operator/ (mono& object1, mono& object2)
{
	return { object1.coefficient / object2.coefficient,object1.power - object2.power };
}
//Đạo hàm bậc 1 đơn thức
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
//Tích phân vô định cho đơn thức
mono InfIntegral(mono para)
{
	para.coefficient = para.coefficient / (para.power + 1);
	para.power += 1;
	return para;
}

//Hàm sắp xếp đa thức số mũ giảm dần (Dùng bubble sort cho số mũ)
void Arrange(poli& para)
{
	for (int i = 0; i <= para.amount - 1; i++) {
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
void MonoInPoli(poli& result)
{

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
		polimial += Convert(para.term[i].coefficient) + "x^" + Convert(para.term[i].power) + out;
	}
	return polimial;
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
		result.term[result.amount].coefficient = para2.term[i].coefficient;
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
//Tính giá trị đa thức tại x
double Poli_at_x(poli para, double x)
{
	double sum = 0;
	for (int i = 0; i < para.amount; i++) {
		sum += para.term[i].coefficient * pow(x, para.term[i].power);
	}
	return sum;
}
poli Input_poli(poli& para)
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
poli Output_poli(poli para)
{
	MonoInPoli(para);
	Arrange(para);
	//Hàm xuất đa thức
	cout << "Da thuc co dang: ";
	cout << Poli(para) << endl;
	return para;
}
//Hàm tính tích phân vô định cho đa thức
poli InfIntegral(poli para)
{
	for (int i = 0; i < para.amount; i++)
	{
		para.term[i] = InfIntegral(para.term[i]);
	}
	para.amount += 1;
	return para;
}
//Hàm tính tích phân xác định cho đa thức
double DefIntegral(poli para, double upper, double lower)
{
	poli integral = InfIntegral(para);
	return Poli_at_x(integral, upper) - Poli_at_x(integral, lower);
}

//Điểm trong không gian hai chiều
string XyToString(xy para)
{
	string result;
	result += "(" + Convert(para.x) + ";" + Convert(para.y) + ")";
	return result;
}
void Output_xy(xy para)
{
	cout << "Diem co toa do: ";
	cout << XyToString(para);
	cout << endl;
}
xy Input_xy()
{
	xy result;
	cout << "Nhap toa do x: " << endl;
	cin >> result.x;
	cout << "Nhap toa do y: " << endl;
	cin >> result.y;
	return result;
}
//Hàm tính độ lớn vector
double VectorModule(xy A, xy B)
{
	//Tính đoạn thẳng BA
	//BA = sqrt((xB-xA)^2+(yB-yA)^2)
	return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}
//Hàm kiểm tra hai điểm có trùng nhau
bool DuplicateXY(xy A, xy B)
{
	//Kiểm tra các đỉnh trùng nhau
	if (A.x == B.x && A.y == B.y)
		return true;
	return false;
}


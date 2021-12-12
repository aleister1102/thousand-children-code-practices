#include"Header.h"
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
	for (;n > 0;)
	{
		n /= 10;
		count += 1;
	}
	return count;
}
//Hàm sắp xếp
void Sort_Ascending_int(int a[size * size], int end)
{
	for (int i = 0; i < end - 1; i++)
	{
		bool check = false;
		for (int j = 0; j < end - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swapping_int(a[j], a[j + 1]);
				check = true;
			}
		}
		if (check == false)
			break;
	}
}
void Sort_Descending_int(int a[size * size], int end)
{
	for (int i = 0; i < end - 1; i++)
	{
		bool check = false;
		for (int j = 0; j < end - i - 1; j++)
		{
			if (a[j] < a[j + 1])
			{
				swapping_int(a[j], a[j + 1]);
				check = true;
			}
		}
		if (check == false)
			break;
	}
}
//Hàm xuất ma trận 2D
void Out2D(int a[size][size])
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << /*"a[" << i << "][" << j << "]: " <<*/ a[i][j] << " ";
		}cout << endl;
	}
}
void Out2D_double(double a[size][size])
{

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << /*"a[" << i << "][" << j << "]: " <<*/ a[i][j] << "\t";
		}cout << endl;
	}
}
//Tìm Max 2d
int _Max2D_(int a[size][size])
{
	int max = a[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] > max) {
				max = a[i][j];
			}
		}
	}
	cout << "Max la: " << max << endl;
	return max;
}
//Đảo hai dòng 2D
void swap_lines(int a[size][size], int l1, int l2)
{
	//l1 và l2 đại diện cho hai hàng cần swap
	int temp[size] = { 0 };
	for (int i = 0; i < size; i++)
	{
		temp[i] = a[l1][i];
		a[l1][i] = a[l2][i];
		a[l2][i] = temp[i];
	}
}




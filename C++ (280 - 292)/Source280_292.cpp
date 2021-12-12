#include "Header.h"
void set_color(int code) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}
int  Move_left(int a[size], int &n)
{
	//Hàm trả về giá trị bị mất
	int temp = a[0];
	for (int i = 0; i < n-1; i++) {
		a[i] = a[i + 1];
	}n -= 1;
	return temp;
}
int  Move_right(int a[size], int &n) {
	//Hàm trả về giá trị bị mất
	int temp = a[n-1];
	for (int i = n-1; i > 0; i--) {
		a[i] = a[i-1];
	}n -= 1;
	return temp;
}
void swapping(int &a, int &b)
{
	int temp = a;
	a = b; b = temp;
}
void Reverse_arr(int a[size], int n)
{
	int cond = n / 2;
	for (int i = 0; i < cond; i++) {
		swapping(a[i], a[n - i-1]);
	}
}
void Out_arr(int a[size], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
void Out_arr_double(double b[size], int n) 
{
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
}
//Bai 284
void _284_ (int a[size], int n) 
{
	int even[size] = { 0 };
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			even[k++] = a[i];
		}
	}
	int temp = k;
	Reverse_arr(even, k);
	k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			a[i] = even[k++];
		}
	}
}
//Bai 285
void _285_(int a[size], int n)
{
	int posi[size] = { 0 };
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			posi[k++] = a[i];
		}
	}
	int temp = k;
	Reverse_arr(posi, k);
	k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			a[i] = posi[k++];
		}
	}
}
//Bai 286
void _286_(int a[size], int n) 
{
	int num;
	cout << "Dich trai bao nhieu phan tu: ?" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		//----Comment---- 
		a[n] = Move_left(a, n); n += 1;
		Out_arr(a, n);cout << endl;
	}
}
//Bai 287
void _287_(int a[size], int n)
{
	int num;
	cout << "Dich phai bao nhieu phan tu: ?" << endl;
	cin >> num;
	for (int i = 0; i < num; i++) {
		//----Comment---- 
		a[0] = Move_right(a, n); n += 1;
		Out_arr(a, n); cout << endl;
	}
}
//Bai 288
void _288_(int a[size], int n) 
{
	int yellow = 0x06;
	int white = 0x07;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0 && a[i]!=0)
		{
			set_color(yellow);
			cout << a[i] << " ";
		}
		else if(a[i]%2!=0)
		{
			set_color(white);
			cout << a[i] << " ";
		}
	}
}
//Bai 289
void _289_(int a[size], int n)
{
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			cout << a[i] << " ";
		}
	}cout << endl;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			cout << a[i] << " ";
		}
	}
}
//Bai 290
void _290_(int a[size], int n)
{
	int even[size] = { 0 };
	int odd[size] = { 0 };
	int e=0, o = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] %2 == 0) {
			even[e++] = a[i];
		}
		else
			odd[o++] = a[i];
	}
	int temp1 = e;
	int temp2 = o;
	Reverse_arr(even, e);
	Reverse_arr(odd, o);
	e = o = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			a[i] = even[e++];
		}else
			a[i] = odd[o++];
	}
	Out_arr(even, e); cout << endl;
	Out_arr(odd, o); cout << endl;
	Out_arr(a, n);
}
//Bài 291
void _291_(int a[size], int n) {
	int max = a[0], min = max;
	int i_max = 0, i_min = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
		{
			i_max = i; max = a[i];
		}
		
		else if (a[i] < min)
		{
			i_min = i; min = a[i];
		}

	}
	cout << max << "|" << min << endl;
	swapping(a[i_min], a[i_max]);
	Out_arr(a, n);
} 


//Bài 292
void _292_(double b[size], int n) {
	for (int i = 0; i < n; i++) {
		b[i] = round(b[i]);
	}Out_arr_double(b, n);
}




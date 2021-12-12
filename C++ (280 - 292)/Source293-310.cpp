#include "Header.h"
bool divisor(int a, int b) {
	if (a % b == 0)
		return true;
	else
		return false;
}

bool Elementary(int a) {
	int count = 0;
	for (int i = 1; i <= a; i++) {
		if (divisor(a, i))
			count += 1;
	}
	if (count == 2)
		return true;
	else return false;
}

void Out_arr_range(int a[size], int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		cout << a[i] << " ";
	}
}
bool positive_arr(int a[size], int start,int end)
{
	for (int i = start; i <= end; i++) {
		if (a[i] <= 0)
			return false;
	}return true;
}
//Hàm tính tổng các mảng
int sum_arr(int a[size], int start,int end) 
{
	int sum = 0;
	for (int i = start; i <= end; i++) {
		sum += a[i];
	}return sum;
}
//Hàm kiểm tra phần tử có trong mảng
bool find_arr(int a[size], int start,int end,int target)
{
	//Cần chú ý điểm bắt đầu và kết thúc vòng lặp tùy thuộc dạng bài 
	for (int i = start; i <= end; i++) {
		if (a[i] ==target)
			return true;
	}return false;
}
//Hàm tìm giá trị lớn nhất trong mảng
int max_arr(int a[size], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}return max;
}
//Dãy tăng với công sai không đổi
bool Increasing_gradu(int a[size], int start,int end)
{
	int diff = a[1] - a[0];
	for (int i = 1; i < end; i++) {
		if (a[i]+diff != a[i + 1])
			return false;
	}return true;
}
bool Increasing(int a[size], int start,int end) 
{
	//Ta định nghĩa dãy tăng dần là dãy tăng có công sai không đổi
	//Ở đây viết hàm cho dãy tăng tổng quát
	//Nếu mảng con có 1 phần tử thì không xét tăng
	if (end - start < 1)
		return false;
	//Do kiểm tra theo cặp nên điểm kết thúc của i phải trừ hao cho i+1 (i <end)
	for (int i = start; i < end; i++) {
		if (a[i] > a[i + 1])
			return false;
	}return true;
}
bool Decreasing(int a[size], int start,int end) 
{
	//Ta định nghĩa dãy giảm dần là dãy giảm có công sai không đổi
	//Ở đây viết hàm cho dãy giảm tổng quát
	//Nếu mảng con có 1 phần tử thì không xét giảm
	if (end - start < 1)
		return false;
	//Do kiểm tra theo cặp nên điểm kết thúc của i phải trừ hao cho i+1 (i <end)
	for (int i = start; i < end; i++) {
		if (a[i] < a[i + 1])
			return false;
	}return true;
}

//Bài 293
//Qua bài này ta biết rằng mảng con không giống như tập hợp con
//Thứ tự trong mảng con phải đúng với thứ tự phần tử chứa trong mảng chính.
//Ví dụ có 1234 thì mảng con phải là 123,12,1,234,34,4,34,4 
void subArray(int a[size], int n)
{
	//Chọn điểm đầu
	for (int i = 0; i < n; i++) {
		//Chọn điểm cuối
		for (int j = i; j < n; j++) {
			//In ra các mảng con trong khoảng đã cho
			for (int k = i; k <= j; k++) {
				cout << a[k] << " ";
			}cout << endl;
		}
	}
}
//Bài 294
void _294_(int a[size], int n) {
	for (int i = 0; i < n; i++)
	{
		//Cho phần tử kết thúc có ĐIỂM BẮT ĐẦU lớn hơn phần tử bắt đầu là 1
		for (int j = i+1; j < n; j++) {
			for (int k = i; k <= j; k++)
			{
				cout << a[k] << " ";
			}cout << endl;
		}
	}
}
//Bài 295
void _295_(int a[size], int n) {
	for (int i = 0; i <n; i++)
	{
		for (int j = i; j <n; j++) {
			if (Increasing_gradu(a, i, j)) {
				for (int k = i; k <= j; k++)
				{
					cout << a[k] << " ";
				}cout << endl;
			}
		}
	}
}
//Bài 296
void _296_(int a[size], int n) {
	int max = max_arr(a, n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) {
			if (Increasing(a, i, j)==true && find_arr(a,i,j,max)==true) {
				for (int k = i; k <= j; k++)
				{
					cout << a[k] << " ";
				}cout << endl;
			}
		}
	}
}
//Bài 297
void _297_(int a[size], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) {
			if (Increasing(a, i, j)==true) {
				for (int k = i; k <= j; k++)
				{
					cout << a[k] << " ";
				}cout <<"Sum is: "<<sum_arr(a,i,j) <<endl;
			}
		}
	}
}
//Bài 298
void _298_(int a[size], int n) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) {
			if (j - i >= 1)
			{
				count += 1;
				for (int k = i; k <= j; k++) {
					cout << a[k] << " ";
				}cout <<"So luong mang co do dai hon 1: "<<count <<endl;
			}
		}
	}
}
//Bài 299
void _299_(int a[size], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) {
			if (j - i >= 1 && positive_arr(a,i,j)==true)
			{
				for (int k = i; k <= j; k++) {
					cout << a[k] << " ";
				}cout << endl;
			}
		}
	}
}
//Bài 300
void _300_(int a[size], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) {
			if (Decreasing(a,i,j))
			{
				for (int k = i; k <= j; k++) {
					cout << a[k] << " ";
				}cout << endl;
			}
		}
	}
}
//Bài 301
bool a_in_b(int a[size], int b[size],int size_a,int size_b) {
	int start = 0;
	for (int i = 0; i < size_b;i++) {
		if (a[0] == b[i])
			start = i;
	}
	for (int i = 0; i < size_a; i++) {
		if (a[i] != b[start++])
			return false;
	}
	return true;
}
//Bài 302
int _302_(int a[size], int b[size], int size_a, int size_b) {
	int start = 0;
	int count = 0;
	for (int i = 0; i < size_b; i++) {
		if (a[0] == b[i])
		{
			start = i;
			for (int i = 0; i < size_a; i++) {
				if (a[i] != b[start++])
					break;
			}
			count += 1;
		}
	}
	return count;
}
//Bài 303
void _303_(int a[size], int n) {
	int max = 1;
	//Tìm max
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (positive_arr(a, i, j))
			{
				if (j - i + 1 > max)
					max = j - i + 1;
			}
		}
	}
	//Xuất vị trí có max
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
		{
			if (positive_arr(a, i, j) == true && j - i+1 == max)
			{
				for (int k = i; k <= j; k++) {
					cout << a[k] << " ";
				}cout << endl;
			}
		}
	}
}
//Bài 304
void _304_(int a[size], int n) {
	int M;
	cout << "Nhap M nguyen: " << endl;
	cin >> M;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += a[k];
			}
			if (sum == M)
			{
				Out_arr_range(a, i, j); cout << endl;
			}
		}
	}
}
//Bài 305
void _305_(int a[size], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			if (positive_arr(a, i, j)==true && sum_arr(a, i, j) > max)
			{
					max = sum_arr(a,i,j);
			}
		}
	}
	//Xuất vị trí có max
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
		{
			if (positive_arr(a, i, j) == true && sum_arr(a, i, j) == max)
			{
				Out_arr_range(a, i, j); cout << endl;
			}
		}
	}
	cout << "Co gia tri max la: " << max << endl;
}
//Bài 306
void _306_(int a[size], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			if (sum_arr(a, i, j) > max)
			{
					max = sum_arr(a,i,j);
			}
		}
	}
	//Xuất vị trí có max
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++)
		{
			if (sum_arr(a, i, j) == max)
			{
				Out_arr_range(a, i, j); cout << endl;
			}
		}
	}
	cout << "Co gia tri max la: " << max << endl;
}
//Bài 307
void _307_(int a[size], int n) {
	int sub[size] = { 0 };
	int m = 0;
	for (int i = 0; i <n; i++)
	{
		if (a[i] % 2 != 0)
			sub[m++] = a[i];
	}
	Out_arr(sub, m);
}
//Bài 308
void _308_(int a[size], int n) {
	int sub[size] = { 0 };
	int m = 0;
	for (int i = 0; i <n; i++)
	{
		if (a[i] < 0)
			sub[m++] = a[i];
	}
	Out_arr(sub, m);
}
//Bài 309
void _309_(int a[size], int n) {
	int sub[size] = { 0 };
	int m = 1;
	sub[0] = a[1];
	for (int i = 1; i < n-1; i++)
	{
		sub[m++] = a[i - 1] + a[i + 1];
	}sub[m++] = a[n - 1];
	Out_arr(sub, m);
}
//Bài 310
void _310_(int a[size], int n) {
	int sub[size] = { 0 };
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (Elementary(a[i]))
			sub[m++] = a[i];
	}
	Out_arr(sub, m);
}




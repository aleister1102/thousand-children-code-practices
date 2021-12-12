#include"Header.h"
//Bài 366
bool _366_(int a[size][size])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] % 2 == 0) {
				cout << "So chan dau tien: " << a[i][j];
				cout << " tai vi tri " << i << " " << j << endl;
				return 1;
			}
		}
	}
	return 0;
}
//Bài 367
//Bài 368
void _Out1D_(int a[size*size])
{
	for (int i = 0; i < size * size; i++)
	{
		cout << a[i] << " ";
	}cout << endl;
}
void swapping_int(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void _Sort2Dto1D_(int a[size][size],int b[(size*size)])
{
	int k = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			b[k++] = a[i][j];
		}
	}
	//Sort Ascending
	bool check;
	for (int i = 0; i < size*size - 1; i++)
	{
		check = false;
		for (int j = 0; j < size*size - i - 1; j++)
		{
			if (b[j] > b[j + 1])
			{
				swapping_int(b[j], b[j + 1]);
				check = true;
			}
		}
		if (check == false)
			break;
	}
}
int _368_(int a[size][size])
{
	int b[(size * size)] = { 0 };
	_Sort2Dto1D_(a, b);
	return b[(size * size) - 2];
}
//Bài 369
bool _369_(int a[size][size])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] > 0)
			{
				cout << "So duong dau tien la: " << a[i][j];
				cout << " tai vi tri " << i << " " << j << endl;
				return 1;
			}
		}
	}return 0;
}
//Bài 370
int _370_(int a[size][size])
{
	int max = -100000;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] < 0 && a[i][j]>max)
			{
				max = a[i][j];
			}
		}
	}return max;
}
//Bài 371
void _371_(int a[size][size])
{
	int max = _Max2D_(a);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j]==max )
			{
				cout << "Dong " << i + 1 << " co max" << endl;
			}
		}
	}
}
//Bài 372
void _372_(int a[size][size])
{
	Out2D(a);
	for (int i = 0; i < size; i++)
	{
		int max = a[i][0];
		for (int j = 0; j < size; j++)
		{
			if (a[i][j]>max )
			{
				max = a[i][j];
			}
		}
		cout << "Dong " << i + 1 << " co max la: " << max << endl;
	}
}
//Bài 373
void _373_(int a[size][size])
{
	Out2D(a);
	for (int j = 0; j < size; j++)
	{
		int min = a[0][j];
		for (int i = 0; i < size; i++)
		{
			if (a[i][j]<min )
			{
				min = a[i][j];
			}
		}
		cout << "Cot " << j + 1 << " co min la: " << min << endl;
	}
}
//Bài 374
bool _374_(int a[size][size])
{
	Out2D(a);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Elementary(a[i][j]))
			{
				cout << "So nguyen to dau tien la: " << a[i][j];
				return 1;
			}
		}
	}return 0;
}
//Bài 375
int _375_(int a[size][size])
{
	Out2D(a);
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] % 2 == 0 && a[i][j] > max)
			{
				max = a[i][j];
			}
		}
	}return max;
}
//Bài 376
int _376_(int a[size][size])
{
	Out2D(a);
	int min = 10000;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] > 0 && a[i][j] < min)
			{
				min = a[i][j];
			}
		}
	}return min;
}
//Bài 377
int _377_(int a[size][size])
{
	Out2D(a);
	int max = 2;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Elementary(a[i][j])==true && a[i][j] > max)
			{
				max = a[i][j];
			}
		}
	}return max;
}
//Bài 378
int _378_(int a[size][size])
{
	int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int count[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int temp = a[i][j];
			if (temp < 0)
				temp *= -1;
			while (temp > 0) {
				int remain = temp % 10;
				for (int k = 0; k < 10; k++)
				{
					if (remain == num[k])
					{
						count[k] += 1; break;
					}
				}
				temp/= 10;
			}
		}
	}
	int max = 0, value;
	for (int i = 0; i < 10; i++)
	{
		if (count[i] > max)
		{
			max = count[i]; value = num[i];
		}
	}
	cout << "Chu so xuat hien nhieu nhat la: " << value << " voi " << max << " lan xuat hien" << endl;
	return value;
}
//Bài 379
int _379_(int a[size][size])
{
	int min = a[0][0];
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j]; 
				//Nếu có sự thay đổi về min thì ta reset biến đếm lại
				count = 0;
			}
			if (a[i][j] == min)
				count += 1;
		}
	}return count;
}
//Bài 380
int _EvenMin_(int a[size][size])
{
	int min = 10000;
	for (int i=0;i<size;i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] % 2 == 0 && a[i][j] < min)
				min = a[i][j];
		}
	}
	return min;
}
int _380_(int a[size][size]) 
{
	int min = _EvenMin_(a);
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] == min)
			{
				count += 1;
			}
		}
	}return count;
}
//Bài 381
bool Duplicate(int a[(size * size)], int check)
{
	for (int i = 0; i < size * size; i++)
	{
		if (a[i] == check)
			return true;
	}
	return false;
}
void _381_(int a[size][size])
{
	int dup[size * size] = { 0 };
	int size_dup = size * size;
	int max = 0;
	int value = a[0][0];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			int count = 0;
			
			for (int k = 0; k < size; k++)
			{
				for (int h = 0; h < size; h++)
				{
					if (a[i][j] == a[k][h])
						count += 1;
				}
			}
			if (count > max)
			{
				max = count;
				value = a[i][j];
			}
		}
	}
	cout << value << " xuat hien nhieu nhat" << endl;
}
//Bài 382
int _382_(int a[size][size])
{
	int max = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (SquareNumber(a[i][j]) == true && a[i][j] > max)
				max = a[i][j];
		}
	}
	return max;
}
//Bài 383
int _383_(int a[size][size])
{
	int min = 8128;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Perfect_Number(a[i][j]) == true && a[i][j] < min)
				min = a[i][j];
		}
	}return min;
}
//Bài 384
void _384_(int a[size][size])
{
	int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int count[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int temp = a[i][j];
			if (temp < 0)
				temp *= -1;
			//Tách các chữ số và lưu tuần suất vào mảng count
			while (temp > 0) {
				int remain = temp % 10;
				for (int k = 0; k < 10; k++)
				{
					if (remain == num[k])
					{
						count[k] += 1; break;
					}
				}
				temp /= 10;
			}
		}
	}
	int max = 0;
	//Tạo mảng lưu các giá trị có tần suất cao nhất
	int sub[10] = { 0 };
	int m = 0;
	for (int i = 0; i < 10; i++)
	{
		if (count[i] > max)
		{
			max = count[i];
			//Nếu có sự thay đổi thì mảng reset (bản chất là sẽ ghi đè)
			m = 0;
		}
		if (count[i] == max)
		{
			//Nếu giá trị khác có cùng tần suất thì ghi vào mảng
			sub[m++] = num[i];
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << "Chu so xuat hien nhieu nhat la: " << sub[i] << " voi " << max << " lan xuat hien" << endl;
	}
}
//Bài 385
void _385_(int a[size][size])
{
	int max = a[0][0];
	int m = 0;
	int sub[size] = { 0 };
	Out2D(a);
	for (int i = 0; i < size; i++)
	{
		int sum = 0;

		for (int j = 0; j < size; j++)
		{
			sum += a[i][j];
		}
		if (sum > max)
		{
			max = sum; m = 0;
		}
		if (sum == max)
			sub[m++] = i;
	}
	for (int i = 0; i <m; i++)
	{
		cout << "Dong " << sub[i] << " co tong lon nhat" << endl;
	}
}
//Bài 386
void _386_(int a[size][size])
{
	int min = 10000;
	int m = 0;
	int sub[size] = { 0 };
	Out2D(a);
	for (int j = 0; j < size; j++)
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += a[i][j];
		}
		if (sum < min)
		{
			min = sum; sub[0] = j; m = 0;
		}
		if (sum == min)
			sub[m++] = j;
	}
	for (int i = 0; i <m; i++)
	{
		cout << "Cot " << sub[i] +1 << " co tong nho nhat" << endl;
	}
}
//Bài 387 - 388 - 389 (tương tự nhau chỉ khác điều kiện)
void _387_388_389_(int a[size][size])
{
	Out2D(a);
	int max = 0;
	int sub[size] = { 0 };
	int m = 0;
	for (int i = 0; i < size; i++)
	{
		int count = 0;
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] % 2 == 0)
				count += 1;
		}
		if (count > max)
		{
			max = count; 
			//Reset mảng lưu giá trị về 0 khi có sự thay đổi cờ hiệus
			m = 0;
		}
		//Sau đó sẽ lưu lần đầu giá trị có count > max. Các lần sau cũng lưu tương tự.
		if (count == max)
		{
			sub[m++] = i;
		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << "Dong " << sub[i]<< " co nhieu so chan nhat" << endl;
	}
}
//Bài 390
void _390_(int a[size][size])
{
	Out2D(a);
	int max = 0;
	int sub[size] = { 0 };
	int m = 0;
	for (int j = 0; j < size; j++)
	{
		int count = 0;
		for (int i = 0; i < size; i++)
		{
			int temp = a[i][j];
			if (temp < 0)
				temp *= -1;
			while (temp > 0)
			{
				temp /= 10;
				count += 1;
			}
		}
		if (count > max)
		{
			max = count; m = 0;
		}
		if (count == max)
			sub[m++] = j;
	}
	for (int i = 0; i < m; i++)
	{
		cout << "Cot " << sub[i] << " co nhieu chu so nhat" << endl;
	}
}
//Bài 391
int m = 0;
//Các hàm phục vụ sắp xếp mảng
void Sort_391_(int a[size * size * size])
{
	bool check;
	for (int i = 0; i < size * size - 1; i++)
	{
		check = false;
		for (int j = 0; j < size * size - i - 1; j++)
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
//Hàm kiểm tra tính đã tồn tại của phần tử trong mảng nào đó
bool Duplicate(int a[(size * size * size)], int end, int check)
{
	for (int i = 0; i < end; i++)
	{
		if (a[i] == check)
			return true;
	}
	return false;
}
//Hàm cộng dồn các phần tử xung quanh, trong 1 bán kính cho trước, theo 1 quy luật cụ thể
int Summer(int a[size][size], int x, int y, int constant, char sign, int end)
{
	//Biến end thể hiện bán kính cộng sum 
	//Ví dụ end =2 thì cộng xung quanh 1 phần tử
	//Biến sign để biết bên nào là cộng với constant
	//constant là hằng số tùy chọn truyền vào hàm
	int sum = 0;
	for (int i = 0; i < end; i++)
	{
		if (sign == 'x')
		{
			sum += a[constant][y + i];
		}
		if (sign == 'y') {
			sum += a[x + i][constant];
		}
	}
	return sum;
}
//Hàm này tính các ma trận con lớn nhất (chưa bị cắt)
void Sub2DArray(int a[size][size], int x, int y, int end, int list[size * size * size])
{
	//Tính ngang
	int sum[size * size] = { 0 };
	if (y == 0)
	{
		for (int j = 0; j < size; j++)
		{
			//Tham số y+j thể hiện cột bị thay đổi sau mỗi vòng lặp
			//(Do tính tổng ngang)s
			sum[0] += Summer(a, x, y, y + j, 'y', end);
		}
	}
	//Kiểm tra nếu chưa có giá trị của ma trận con trong mảng thì thêm vào.
	//Trường hợp có rồi thì không cần thêm vì ta chỉ tìm ma trận lớn nhất
	if (Duplicate(list, m, sum[0]) == false)
		list[m++] = sum[0];
	//Tính dọc
	if (x == 0)
	{
		for (int i = 0; i < size; i++)
		{
			//Tương tự tham số x+i mang ý nghĩa dòng thay đổi
			sum[1] += Summer(a, x, y, x + i, 'x', end);
		}
	}
	if (Duplicate(list, m, sum[1]) == false)
		list[m++] = sum[1];
	if (sum[0] != 0 || sum[1] != 0)
	{
		//cout << "Sum ngang cua " << x << ":" << y << " la " << sum[0] << endl;
		//cout << "Sum doc cua " << x << ":" << y << " la " << sum[1] << endl;
	}
	//Gọi hàm cắt ma trận con lớn thành các ma trận con nhỏ hơn
	SubSub2DArray(a, x, y, sum[0], sum[1], end, list);
}
//Hàm cắt các ma trận con
void SubSub2DArray(int a[size][size], int x, int y, int sum_hori, int sum_verti, int end, int list[(size * size * size)])
{
	//Cắt các tọa độ biên trước
	//Vòng lặp đầu này đại diện cho các loại cắt (Do chúng ta cắt đến khi ma trận còn tối thiểu 2x2)
	//Ví dụ 4x4 thì ta chỉ được cắt 2 lần (chừa lại ít nhất 2 hàng 2 cột)
	for (int times = 1; times <= size - 2; times++) {
		bool check1 = 0, check2 = 0;
		//Tạo các biến tạm thời lưu giá trị của mảng con lớn nhất
		int temp_hori = sum_hori;
		int temp_hori2 = sum_hori;
		int temp_verti = sum_verti;
		int temp_verti2 = sum_verti;
		//Vòng lặp này đại diện cho các lần cắt
		for (int cut = 1; cut <= times; cut++)
		{
			if (temp_hori != 0)
				//Cắt ngang
			{
				//Đầu tiên ta sẽ cắt đuôi trước, tiến dần vào trong đến khi còn 2x2
				temp_hori -= Summer(a, x, y, size - cut, 'y', end);
				//Sau đó ta cắt đầu, cũng tiến dần về cuối mảng đến khi còn 2x2
				temp_hori2 -= Summer(a, x, y, cut - 1, 'y', end);
				check1 = true;
			}
			if (temp_verti != 0)
				//Cắt dọc áp dụng tương tự cắt ngang
				temp_verti -= Summer(a, x, y, size - cut, 'x', end);
			temp_verti2 -= Summer(a, x, y, cut - 1, 'x', end);
			check2 = true;
		}
		//Tương tự tìm tổng các ma trận con lớn nhất, ta cũng cho các giá trị tìm được vào mảng
		if (Duplicate(list, m, temp_hori) == false)
			list[m++] = temp_hori;
		if (Duplicate(list, m, temp_hori2) == false)
			list[m++] = temp_hori2;
		if (Duplicate(list, m, temp_verti) == false)
			list[m++] = temp_verti;
		if (Duplicate(list, m, temp_verti2) == false)
			list[m++] = temp_verti2;
		if (check1)
		{
			//cout << "Sum ngang thieu " << times << " cua " << x << ":" << y << " la " << temp_hori << endl;
			//cout << "Sum ngang thieu (cat dau)" << times << " cua " << x << ":" << y << " la " << temp_hori2 << endl;

		}
		if (check2)
		{
			//cout << "Sum doc thieu " << times << " cua " << x << ":" << y << " la " << temp_verti << endl;
			//cout << "Sum doc thieu (cat dau) " << times << " cua " << x << ":" << y << " la " << temp_verti2 << endl;
		}
	}
}
//Hàm lựa chọn kích thước tối thiểu của các ma trận con
void SelectMatrix(int a[size][size], int x, int y, int list[size * size * size])
{
	//Tùy thuộc vào kích thước ma trận chính ,à số lần tính ma trận con sẽ thay đổi
	//Ví dụ 4x4 thì kích thước ma trận con có thể là 3x3,3x2,2x3,2x2,3x4,4x3.
	//Vì thế với 4x4 thì chỉ xét 2 lần tính ma trận con (1 lần 3,1 lần 2). Với 5x5 thì là 3 lần (4-3-2).
	for (int i = size - 1; i >= 2; i--)
	{
		//cout << "Ma tran luon co dang " << i << "xN hoac Nx" << i << endl;
		Sub2DArray(a, x, y, i, list);
	}
}
void _391_(int a[size][size])
{
	//Tạo một mảng lưu các giá trị ma trận con tính được
	int list[size * size * size] = { 0 };
	Out2D(a);
	//Tùy kích thước ma trận mà chọn các vị trí xét cụ thể.
	//Thông thường chỉ cần từ 1-4 vị trí ở góc tây bắc là đủ tính hết ma trận con 
	SelectMatrix(a, 0, 0, list);
	SelectMatrix(a, 0, 1, list);
	SelectMatrix(a, 1, 0, list);
	//SelectMatrix(a, 1, 1, list);
	cout << endl;
	cout << "So tong ma tran da tinh duoc: " << m << endl;
	//for (int i = 0; i < m; i++)
	//{
	//	cout << list[i] << " ";
	//}cout << endl;
	//Gọi hàm ra sắp xếp để giá trị lớn nhất nằm ở đầu
	Sort_391_(list);
	cout << endl;
	cout << "Ma tran con co tong lon nhat la: " << list[0] << endl;
}

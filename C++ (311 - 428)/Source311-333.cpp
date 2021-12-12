#include "Header.h"
//Bài 311-314
//Từ việc viết hàm có một số nhận xét như sau:
//Số cột của đối số và tham số phải bằng nhau
//Đối số truyền vào phải đầy đủ dòng và cột
void In2D(int a[size][size], int& row, int& col)
{
	cout << "Nhap so dong: " << endl;cin >> row;
	cout << "Nhap so cot: " << endl;cin >> col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "a[" << i << "][" << j << "]: "; cin >> a[i][j];
		}
	}
}
void Out2D2(int a[size+1][size+1])
{
	
	for (int i = 0; i < size+1; i++)
	{
		for (int j = 0; j < size+1; j++)
		{
			cout << /*"a[" << i << "][" << j << "]: " <<*/ a[i][j] << " ";
		}cout << endl;
	}
}
void In2D_double(double a[size][size], int& row, int& col)
{
	cout << "Nhap so dong: " << endl;cin >> row;
	cout << "Nhap so cot: " << endl;cin >> col;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "a[" << i << "][" << j << "]: "; cin >> a[i][j];
		}
	}
}
void Out_arr(double a[size], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}
//Bài 315
double _315_(double b[size][size], int row, int col)
{
	double max = b[0][0];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (b[i][j] > max)
				max = b[i][j];
		}
	}
	return max;
}
//Bài 316
bool _316_(int a[size][size], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] % 2 == 0 && a[i][j]<2015)
				return true;
		}
	}
	return false;
}
//Bài 317
int _317_(int a[size][size], int row, int col)
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (Elementary(a[i][j]))
				count += 1;
		}
	}
	return count;
}//Bài 318
int _318_(double a[size][size], int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j]<0)
				sum += a[i][j];
		}
	}
	return sum;
}
//Bài 319
void swapping(double &a, double &b)
{
	double temp = a;
	a = b;
	b = temp;
}
void Sort_Ascending(double b[size], int n)
{
	bool check;
	for (int i = 0; i < n-1; i++)
	{
		check = false;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (b[j] > b[j + 1])
			{
				swapping(b[j], b[j+1]);
				check = true;
			}
		}
		if (check==false)
			break;
	}
}
void Sort_Ascending2D(double b[size][size], int row, int col)
{
	double sub[size * size];
	int m = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sub[m++] = b[i][j];
		}
	}
	Out_arr(sub, m);
	cout << endl;
	Sort_Ascending(sub, m);
	Out_arr(sub, m);
	cout << endl;

	m = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			b[i][j] = sub[m++];
		}
	}
}
//Bài 320
double _320_(double a[size][size], int row, int col)
{
	double sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] > 0)
				sum += a[i][j];
		}
	}
	return sum;
}
//Bài 321
int _321_(int a[size][size], int row, int col)
{
	int mul = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j]%2!= 0)
				mul *= a[i][j];
		}
	}
	return mul;
}
//Bài 322
void _322_(double a[size][size], int row, int col)
{
	double sum;
	for (int i = 0; i < row; i++)
	{
		sum = 0;
		for (int j = 0; j < col; j++)
		{
				sum += a[i][j];
		}cout << "Dong" << i << ": " << sum << endl;
	}
}
//Bài 323
void _323_(double a[size][size], int row, int col)
{
	double mul;
	for (int i = 0; i < col; i++)
	{
		mul = 1;
		for (int j = 0; j < row; j++)
		{
			if (a[j][i] > 0)
				mul *= a[j][i];
		}cout << "Cot " << i << ": " << mul << endl;
	}
}
//Bài 324
void _324_(double a[size][size], int row, int col)
{
	double sum;
	for (int i = 0; i < row; i++)
	{
		sum = 0;
		for (int j = 0; j < col; j++)
		{
			if(a[i][j]>0)
			sum += a[i][j];
		}cout << "Dong" << i << ": " << sum << endl;
	}
}
//Bài 325
void _325_(int a[size][size], int row, int col)
{
	int mul;
	for (int i = 0; i < col; i++)
	{
		mul = 1;
		for (int j = 0; j < row; j++)
		{
			if (a[j][i] % 2 == 0)
				mul *= a[j][i];
		}cout << "Cot " << i << ": " << mul << endl;
	}
}
//Bài 326
double _326_(double a[size][size], int row, int col)
{
	double count = 0;
	double sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] > 0)
			{
				sum += a[i][j];
				count += 1;
			}
		}
	}return sum / count;
}
//Bài 327
int _327_(int a[size][size], int row, int col)
{
	int sum = 0;
	//Hai cột biên
	for (int i = 0; i < row; i++)
	{
		sum += a[i][0];
		sum += a[i][col - 1];
	}
	//Các cột giữa nhưng bỏ giá trị trung tâm;
	for (int i = 1; i < col - 1; i++)
	{
		sum += a[0][i];
		sum += a[row - 1][i];
	}return sum;
}
//Bài 328
double _328_(double a[size][size], int row, int col)
{
	double mul = 1, count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] > 0)
			{
				mul *= a[i][j]; count += 1;
			}
		}
	}
	return pow(mul, 1.0 / count);
}
//Bài 329
void _329_(double a[size][size], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] < 0)
			{
				a[i][j] = abs(a[i][j]);
			}
		}
	}
}
//Bài 330
void _330_(double a[size][size], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a[i][j] = round(a[i][j]);
		}
	}
}
//Bài 331 giống 322
//Bài 332
void _332_(int a[size][size], int row, int col)
{
	int sum;
	for (int i = 0; i < col; i++)
	{
		sum = 0;
		for (int j = 0; j < row; j++)
		{
			if (a[j][i] %2!= 0)
				sum += a[j][i];
		}cout << "Cot " << i << ": " << sum << endl;
	}
}
//Bài 333
int _333_(int a[size][size], int row, int col)
{
	int sum = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (Perfect_Number(a[i][j]))
				sum += a[i][j];
		}
	}return sum;
}

		
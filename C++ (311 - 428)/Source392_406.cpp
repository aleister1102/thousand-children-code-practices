#include "Header.h"
//Bài 392
void _392_(int a[size][size])
{
	Out2D(a);
	int x, y;
	cout << "Nhap hai dong can hoan vi" << endl;
	cin >> x >> y;
	for (int j = 0; j < size; j++)
	{
		swapping_int(a[x][j], a[y][j]);
	}
	Out2D(a);
}
//Bài 393
void _393_(int a[size][size])
{
	Out2D(a);
	int x, y;
	do {
		cout << "Nhap hai cot can hoan vi" << endl;
		cin >> x >> y;
	} while (x * y < 0 || x >= size || y >= size);
	for (int i = 0; i < size; i++)
	{
		swapping_int(a[i][x], a[i][y]);
	}
	Out2D(a);
}
//Bài 394
void _394_(int a[size][size])
{
	Out2D(a);
	int temp[size] = { 0 };
	for (int j = 0; j < size; j++)
	{
		temp[j] = a[size - 1][j];
	}
	for (int i = size-1; i >=0; i--)
	{
		for (int j = 0; j <size ; j++)
		{
			a[i][j] = a[i - 1][j];
		}
	}
	for (int j = 0; j < size; j++)
	{
		a[0][j] = temp[j];
	}
	Out2D(a);
}
//Bài 395
void _395_(int a[size][size])
{
	Out2D(a);
	int temp[size] = { 0 };
	for (int j = 0; j < size; j++)
	{
		temp[j] = a[0][j];
	}
	for (int i = 0; i <size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a[i][j] = a[i + 1][j];
		}
	}
	for (int j = 0; j < size; j++)
	{
		a[size-1][j] = temp[j];
	}
	Out2D(a);
}
//Bài 396
void _396_(int a[size][size]) {
	Out2D(a);
	int temp[size] = { 0 };
	for (int i = 0; i < size; i++)
	{
		temp[i] = a[i][0];
	}
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++) {
			a[i][j] = a[i][j + 1];
		}
	}
	for (int i = 0; i < size; i++)
	{
		a[i][size - 1] = temp[i];
	}
	Out2D(a);
}
//Bài 397
void _397_(int a[size][size]) {
	Out2D(a);
	int temp[size] = { 0 };
	for (int i = 0; i < size; i++)
	{
		temp[i] = a[i][size - 1];
	}
	for (int j= size-1; j >=0; j--)
	{
		for (int i = 0; i < size; i++) {
			a[i][j] = a[i][j - 1];
		}
	}
	for (int i = 0; i < size; i++)
	{
		a[i][0] = temp[i];
	}
	Out2D(a);
}
//Bài 398 
void _398_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int temp = a[0][0];
	for (int i = 0; i <size-1; i++)
	{
		a[i][0] = a[i + 1][0];
	}
	for (int j = 0; j < size; j++)
	{
		a[size - 1][j] = a[size - 1][j + 1];
	}
	for (int i = size - 1; i > 0; i--)
	{
		a[i][size - 1] = a[i - 1][size - 1];
	}
	for (int j = size - 1; j > 0; j--)
	{
		a[0][j] = a[0][j - 1];
	}
	a[0][1] = temp;
	Out2D(a);
}
//Bài 399
void _399_(int a[size][size])
{
	Out2D(a);
	int temp = a[0][0];
	for (int j = 0; j < size; j++)
	{
		a[0][j] = a[0][j + 1];
	}
	for (int i = 0; i < size; i++)
	{
		a[i][size - 1] = a[i + 1][size - 1];
	}
	for (int j = size - 1; j > 0; j--)
	{
		a[size - 1][j] = a[size - 1][j - 1];
	}
	for (int i = size - 1; i > 0; i--)
	{
		a[i][0] = a[i - 1][0];
	}
	a[1][0] = temp;
	Out2D(a);
}
//Bài 400
void Out2D_flex(int a[size][size], const int& row,const int& col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << a[i][j] << " ";
		}cout << endl;
	}
}
void _400_(int a[size][size]) {
	int s = size;
	Out2D(a);
	int row;
	cout << "Chon dong can xoa: " << endl;
	cin >> row;
	for (int j = 0; j < size; j++)
	{
		a[row][j] = a[size - 1][j];
	}//Lấy dòng cuối đè lên dòng bị xóa
	s -= 1;
	Out2D_flex(a,s,size);
}
//Bài 401
void _401_(int a[size][size])
{
	int s = size;
	Out2D(a);
	int col;
	cout << "Chon cot can xoa: " << endl;
	cin >> col;
	for (int i = 0; i < size; i++)
	{
		a[i][col] = a[i][size-1];
	}//Lấy cột cuối đè lên dòng bị xóa
	s -= 1;
	Out2D_flex(a, size, s);

}
//Bài 402
void _402_(int a[size][size])
{
	cout << endl;
	//Ví dụ cho ma trận 
	//123 sẽ thành 741
	//456		   852
	//789		   963
	//Lưu dòng bị mất ban đầu
	int temp[size] = { 0 };
	for (int j = 0; j < size; j++)
	{
		temp[j] = a[0][j];
	}
	//Biến j đại diện cho dòng được chép, biến i là cột được chép
	for (int i = size-1; i >= 0; i--)
	{
		a[0][i] = a[size-i-1][0];
	}
	for (int j = 1; j < size; j++)
	{
		a[j][0] = a[size - 1][j];
	}
	for (int i = 1; i < size; i++)
	{
		a[size - 1][i] = a[i][size - 1];
	}
	for (int j = 0; j < size; j++)
	{
		a[j][size - 1] = temp[j];
	}
	cout << endl;
}
//Bài 403
void _403_(int a[size][size])
{
	cout << endl;
	//Quay 180 độ là đổi hai dòng/cột biên với nhau
	//Đổi dòng/cột trong một vòng lặp
	for (int k = size - 2; k > 0; k--)
	{
		swapping_int(a[0][k], a[size - 1][size - k-1]);
		swapping_int(a[k][0], a[size - k - 1][size - 1]);
	}
	//Hoán vị các góc
	swapping_int(a[0][0] , a[size - 1][size - 1]);
	swapping_int(a[size - 1][0] , a[0][size - 1]);
	cout << endl;
}
//Bài 404
void _404_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	//Quay 270 (giả sử theo chiều đồng hồ) là quay ngược đồng hồ 90 độ
	int temp[size]={0};
	//Lưu dòng đầu tiên:
	for (int j = 0; j < size; j++)
	{
		temp[j] = a[0][j];
	}
	for (int j = 0; j < size; j++)
	{
		a[0][j] = a[j][size - 1];
	}
	for (int i = 0; i < size; i++)
	{
		a[i][size - 1] = a[size - 1][size - i - 1];
	}
	for (int j = 0; j < size-1; j++)
	{
		a[size - 1][j] = a[j][0];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		a[i][0] = temp[size-i-1];
	}
	Out2D(a);
}
//Bài 405
void _405_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			swapping_int(a[i][j], a[i][size - j - 1]);
		}
	}	
	Out2D(a);
	cout << endl;

}
//Bài 406
void _406_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size / 2; i++)
		{
			swapping_int(a[i][j], a[size-i-1][j]);
		}
	}	
	Out2D(a);
	cout << endl;

}

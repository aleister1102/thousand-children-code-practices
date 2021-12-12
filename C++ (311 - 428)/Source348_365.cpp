#include "Header.h"
#if 0
//Bài 348
bool _348_(double a[size][size])
{
	Out2D_double(a);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			if (a[i][j] > 0)
				return true;
		}
	}return false;
}
//Bài 349
bool _349_(double a[size][size])
{
	Out2D_double(a);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			if (Perfect_Number(a[i][j]))
				return true;
		}
	}return false;
}
//Bài 350
bool _350_(int a[size][size])
{
	Out2D(a);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			if (a[i][j] % 2 != 0)
				return true;
		}
	}return false;
}
//Bài 351
bool _351_(int a[size][size])
{
	Out2D(a);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			if (a[i][j] < 0)
				return false;
		}
	}return true;
}
//Bài 352
bool _352_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	cout << "Kiem tra hang thu may: ? (bat dau tu 0)" << endl; int row;
	cin >> row;
	for (int j = 0; j < size-1; j++)
	{
		if (a[row][j] > a[row][j + 1])
			return false;
	}
	return true;
}
//Bài 353
bool _353_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	cout << "Kiem tra cot thu may: ? (bat dau tu 0)" << endl; int  col;
	cin >> col;
	for (int i = 0; i < size-1; i++)
	{
		if (a[i][col] < a[i+1][col])
			return false;
	}
	return true;
}
//Bài 354
bool _354_(int a[size][size])
{
	Out2D(a);
	//Xét hàng
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++) {
			if (a[i][j] < a[i][j + 1])
				return false;
		}
	}
	//Xét cột
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size - 1; i++) {
			if (a[i][j] < a[i + 1][j])
				return false;
		}
	}
	return true;
}
//Bài 355
void _355_(double a[size][size])
{
	Out2D_double(a);
	bool check;
	for (int i = 0; i < size; i++) {
		check = true;
		for (int j = 0; j < size; j++) {
			if (a[i][j] >= 0)
				check = false;
		}
		if (check)
			cout << "Dong " << i + 1 << " toan am" << endl;
	}
}
//Bài 356
void _356_(int a[size][size])
{
	Out2D(a);
	bool check;
	for (int i = 0; i < size; i++) {
		check = true;
		for (int j = 0; j < size; j++) {
			if (a[i][j] %2!= 0)
				check = false;
		}
		if (check)
			cout << "Dong co chi so " << i << " toan chan" << endl;
	}
}
//Bài 357
void _357_(int a[size][size])
{
	Out2D(a);
	bool check;
	for (int i = 0; i < size; i++) {
		check = false;
		for (int j = 0; j < size; j++) {
			if (Elementary(a[i][j]))
				check = true;
		}
		if (check)
			cout << "Dong  " << i+1 << " co chua so nguyen to" << endl;
	}

}
//Bài 358
void _358_(int a[size][size])
{
	Out2D(a);
	bool check;
	for (int i = 0; i < size; i++) {
		check = false;
		for (int j = 0; j < size; j++) {
			if (a[i][j]%2==0)
				check = true;
		}
		if (check)
			cout << "Dong  " << i+1 << " co chua so chan" << endl;
	}
}
//Bài 359
void _359_(double a[size][size])
{
	Out2D_double(a);
	bool check;
	for (int i = 0; i < size; i++) {
		check = false;
		for (int j = 0; j < size; j++) {
			if (a[i][j]<0)
				check = true;
		}
		if (check)
			cout << "Dong  " << i+1 << " co chua so am" << endl;
	}
}
//Bài 360
void _360_(int a[size][size])
{
	Out2D(a);
	bool check;
	for (int j = 0; j < size; j++) {
		check = false;
		for (int i = 0; i < size; i++) {
			if (SquareNumber(a[i][j]))
				check = true;
		}
		if (check)
			cout << "Cot  " << j+1 << " co chua so chinh phuong" << endl;
	}
}
//Bài 361
void _361_(int a[size][size])
{
	Out2D(a);
	bool check1, check2, check3;
	for (int i = 0; i < size; i++) {
		check1 = false;
		check2 = false;
		check3 = false;
		for (int j = 0; j < size; j++) {
			if (a[i][j] < 0)
				check1 = true;
			if (a[i][j] == 0)
				check2 = true;
			if (a[i][j] > 0)
				check3 = true;
		}
		if (check1 == true && check2 == true && check3 == true)
			cout << "Dong " << i + 1 << " thoa man ba dieu kien" << endl;
	}
}
//Bài 362
void _362_(int a[size][size])
{
	Out2D(a);
	bool check;
	for (int i = 0; i < size; i++) {
		check = true;
		for (int j = 0; j < size; j++) {
			if (a[i][j] < a[i][j + 1])
				check = false;
		}
		if (check)
			cout << "Dong " << i + 1 << " giam dan" << endl;
	}
}
//Bài 363
void _363_(int a[size][size])
{
	Out2D(a);
	bool check;
	for (int j = 0; j < size; j++) {
		check = true;
		for (int i = 0; i < size; i++) {
			if (a[i][j] > a[i+1][j])
				check = false;
		}
		if (check)
			cout << "Cot " << j + 1 << " tang dan" << endl;
	}
}
//Bài 364
bool _AinB_(int a[size][size], int b[size + 1][size + 1])
{
	
	Out2D(a);
	cout << endl;
	Out2D2(b);
	cout << endl;
	for (int i = 0; i < size + 1; i++)
	{
		int istart=0, jstart=0;
		for (int j = 0; j < size + 1; j++) {
			if (b[i][j] == a[0][0])
			{
				istart = i, jstart = j;
			}
			bool check = true;
			for (int k = 0; k < size; k++) {
				for (int h = 0; h < size; h++) {
					if (b[istart][jstart++] != a[k][h])
					{
						check = false; break;
					}
				}
				istart++;//Tăng số dòng lên 1
				jstart = 0;//Số cột quét quay về 0
			}
			if (check)
				return true;
		}
	}
	return false;
}
//Bài 365
int _365_(int a[size][size], int b[size + 1][size + 1])
{
	int count = 0;
	Out2D(a);
	cout << endl;
	Out2D2(b);
	cout << endl;
	for (int i = 0; i < size + 1; i++)
	{
		int istart = 0, jstart = 0;
		for (int j = 0; j < size + 1; j++) {
			if (b[i][j] == a[0][0])
			{
				istart = i, jstart = j;
				bool check = true;
				for (int k = 0; k < size; k++) {
					for (int h = 0; h < size; h++) {
						if (b[istart][jstart++] != a[k][h])
						{
							check = false; break;
						}
					}
					istart++;//Tăng số dòng lên 1
					jstart = 0;//Số cột quét quay về 0
				}
				if (check)
					count += 1;
			}
		}
	}
	return count;
}
#endif

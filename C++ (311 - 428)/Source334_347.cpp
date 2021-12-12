#include "Header.h"
#if 0
//Bài 334
int _334_(double a[size][size], int row, int col)
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] > 0)
				count += 1;
		}
	}return count;
}
//Bài 335
int _335_(int a[size][size], int row, int col)
{
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (Elementary(a[i][j]))
				count += 1;
		}
	}return count;
}
//Bài 336
int _336_(double a[size][size], int row, int col)
{
	Out2D_double(a, row, col); double num; int count = 0;
	cout << "Nhap so can tinh tan suat: " << endl; cin >> num;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (a[i][j] == num)
				count += 1;
		}
	}return count;
}
//Bài 337
int _337_(int a[size][size], int row, int col)
{
	int amount = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			amount += AmountofNumber(a[i][j]);
		}
	}return amount;
}
//Bài 338
void _338_(double a[size][size], int row, int col)
{
	Out2D_double(a, row, col);
	int count;
	for (int i = 0; i < row; i++)
	{
		count = 0;
		for (int j = 0; j < col; j++) {
			if (a[i][j] > 0)
				count += 1;
		}cout << "Dong " << i << " : " << count << endl;
	}
}
//Bài 339
void _339_(int a[size][size], int row, int col)
{
	Out2D(a, row, col);
	int count;
	for (int i = 0; i < row; i++)
	{
		count = 0;
		for (int j = 0; j < col; j++) {
			if (Perfect_Number(a[i][j]))
				count += 1;
		}cout << "Dong " << i << " : " << count << endl;
	}
}
//Bài 340
void _340_(double a[size][size], int row, int col)
{
	Out2D_double(a, row, col);
	int count;
	for (int i = 0; i < col; i++)
	{
		count = 0;
		for (int j = 0; j < row; j++) {
			if (a[j][i]<0)
				count += 1;
		}cout << "Cot " << i << " : " << count << endl;
	}
}
//Bài 341
int _341_(double a[size][size], int row, int col)
{
	Out2D_double(a, row, col);
	int count = 0;
	//Xét các dòng biên,cho chạy các cột
	for (int i = 0; i < col; i++)
	{
		//Xét hàng đầu
		if (a[0][i] > 0)
			count += 1;
		//Xét hàng cuối
		if(a[row - 1][i] > 0)
			count += 1;
	}
	for (int i = 1; i < row-1; i++)
	{
		//Xét các hàng ở giữa
		if (a[i][0] > 0)
			count += 1;
		if (a[i][col-1] > 0)
			count += 1;
	}
	return count;
}
//Tham số fake đánh dấu tham số nào sẽ bị bỏ qua ( bằng 0)
//Vì có những trường hợp tham số vào bằng 0 nhưng lại không bị bỏ qua
//So sánh các phần tử xung quanh: 
int Check(double a, double b, double c, int fake)
{
	//Nếu tham số 2,3 truyền vào là 0 thì không so sánh
	if (b ==0 && fake ==1)
		b = a - 1;//Biến đổi cho luôn bé hơn a
	else if (c == 0 && fake ==2)
		c = a - 1;
	if (a > b && a > c)
		return 1;
	return 0;
}
int Check_less(double a, double b, double c, int fake)
{
	//Nếu tham số 2,3 truyền vào là 0 thì không so sánh
	if (b ==0 && fake ==1)
		b = a + 1;
	else if (c == 0 && fake ==2)
		c = a + 1;
	if (a < b && a < c)
		return 1;
	return 0;
}
//Bài 342 - 343 - 345
void _342_343_345_(double a[size][size], int row, int col) {
	Out2D_double(a, row, col);
	//Ví dụ số dòng thực là 3 thì index thực chỉ có 2 nên giảm 1 cho dễ sử dụng
	col -= 1;
	row -= 1;
	int count = 0;
	for (int i = 0; i <= row; i++)
	{
		for (int j = 0; j <= col; j++)
		{
			double temp = a[i][j];
			//Cờ lệnh, nếu bất kỳ số nào lớn hơn temp thì check thành 0
			//Chỉ cần không thỏa 1 đk thì check thành 0 (do nhân 0 thành 0)
			int check = 1;
			int check2 = 1;
			//Xét hàng đầu (kể cả các góc)
			if (i == 0) {
				check *= Check(temp, false, a[i + 1][j],1);
				check2 *= Check_less(temp, false, a[i + 1][j], 1);
				if (j == 0) {
					//Lần lượt kiểm tra các phía
					check *= Check(temp, false, a[i][j + 1],1);
					check *= Check(temp, false, a[i + 1][j + 1],1);
					check2 *= Check_less(temp, false, a[i][j + 1],1);
					check2 *= Check_less(temp, false, a[i + 1][j + 1],1);
				}
				else if (j == col) {
					//Lần lượt kiểm tra các phía
					check *= Check(temp, a[i][j - 1], false,2);
					check *= Check(temp, false, a[i + 1][j - 1],2);
					check2 *= Check_less(temp, a[i][j - 1], false,2);
					check2 *= Check_less(temp, false, a[i + 1][j - 1],2);
				}
				else
				{
					check *= Check(temp, a[i][j - 1], a[i][j + 1],0);
					check *= Check(temp, false, a[i + 1][j - 1],1);
					check *= Check(temp, false, a[i + 1][j + 1],1);
					check2 *= Check_less(temp, a[i][j - 1], a[i][j + 1],0);
					check2 *= Check_less(temp, false, a[i + 1][j - 1],1);
					check2 *= Check_less(temp, false, a[i + 1][j + 1],1);
				}
			}
			else if (i == row) {
				check *= Check(temp, a[i - 1][j], false,2);
				check2 *= Check_less(temp, a[i - 1][j], false,2);
				if (j == 0) {
					//Lần lượt kiểm tra các phía
					check *= Check(temp, false, a[i][j + 1],1);
					check *= Check(temp, a[i - 1][j + 1], false,2);
					check2 *= Check_less(temp, false, a[i][j + 1],1);
					check2 *= Check_less(temp, a[i - 1][j + 1], false,2);
				}
				else if (j == col) {
					//Lần lượt kiểm tra các phía
					check *= Check(temp, a[i][j - 1], false,2);
					check *= Check(temp, a[i - 1][j - 1], false,2);
					check2 *= Check_less(temp, a[i][j - 1], false,2);
					check2 *= Check_less(temp, a[i - 1][j - 1], false,2);
				}
				else
				{
					check *= Check(temp, a[i][j - 1], a[i][j + 1],0);
					check *= Check(temp, a[i - 1][j - 1], false,2);
					check *= Check(temp, a[i - 1][j + 1], false,2);
					check2 *= Check_less(temp, a[i][j - 1], a[i][j + 1],0);
					check2 *= Check_less(temp, a[i - 1][j - 1], false,2);
					check2 *= Check_less(temp, a[i - 1][j + 1], false,2);
				}

			}
			//Xét cột đầu và cột cuối (không kể các góc)
			else if (j == 0 && i >= 1 && i <= row)
			{
				check *= Check(temp, false, a[i][j + 1],1);
				check *= Check(temp, a[i - 1][j], a[i + 1][j],0);
				check *= Check(temp, a[i - 1][j + 1], false,2);
				check *= Check(temp, false, a[i + 1][j + 1],1);
				check2 *= Check_less(temp, false, a[i][j + 1],1);
				check2 *= Check_less(temp, a[i - 1][j], a[i + 1][j],0);
				check2 *= Check_less(temp, a[i - 1][j + 1], false,2);
				check2 *= Check_less(temp, false, a[i + 1][j + 1],1);
			}
			else if (j == col && i >= 1 && i <= row)
			{
				check *= Check(temp, a[i][j - 1], false,2);
				check *= Check(temp, a[i - 1][j], a[i + 1][j],0);
				check *= Check(temp, false, a[i + 1][j - 1],1);
				check *= Check(temp, a[i - 1][j - 1], false,2);
				check2 *= Check_less(temp, a[i][j - 1], false,2);
				check2 *= Check_less(temp, a[i - 1][j], a[i + 1][j],0);
				check2 *= Check_less(temp, false, a[i + 1][j - 1],1);
				check2 *= Check_less(temp, a[i - 1][j - 1], false,2);
			}
			//Xét các phần tử không thuộc biên
			else
			{
				check *= Check(temp, a[i - 1][j], a[i + 1][j],0);
				check *= Check(temp, a[i][j - 1], a[i][j + 1],0);
				check *= Check(temp, a[i - 1][j - 1], a[i + 1][j + 1],0);
				check *= Check(temp, a[i - 1][j + 1], a[i + 1][j - 1],0);
				check2 *= Check_less(temp, a[i - 1][j], a[i + 1][j],0);
				check2 *= Check_less(temp, a[i][j - 1], a[i][j + 1],0);
				check2 *= Check_less(temp, a[i - 1][j - 1], a[i + 1][j + 1],0);
				check2 *= Check_less(temp, a[i - 1][j + 1], a[i + 1][j - 1],0);
			}
			if (check == 1)
			{
				cout << a[i][j] << " la cuc tri" << endl; count += 1;
			}
			if (check2 == 1)
			{
				cout << a[i][j] << " la cuc tri" << endl; count += 1;
			}
		}
	}
	cout << "Tong so phan tu cuc tri la: " << count << endl;
}
//Bài 344
bool Duplicate_double(double sub[size*size],int n, double num)
{
	for (int i = 0; i < n; i++)
	{
		if (sub[i] == num)
			return true;
	}return false;
}
int _344_(double a[size][size], int row, int col)
{
	Out2D_double(a, row, col);
	double sub[size*size] = { 0 };
	int k = 0;
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (Duplicate_double(sub, k, a[i][j]) == false)
			{
				sub[k++] = a[i][j]; count += 1;
			}
		}
	}return count;
}
//Bài 346
bool Diagonal_down(double a[size][size], int istart,int jstart)
{
	//Xét Đông Nam
	for (int i = istart+1,j=jstart+1; i < size && j<size; i++,j++)
	{
			if (a[istart][jstart] < a[i][j])
				return false;
	}
	//Xét Tây Nam
	for (int i = istart + 1, j = jstart - 1; i < size && j >=0; i++, j--)
	{
		if (a[istart][jstart] < a[i][j])
			return false;
	}
	return true;
}
bool Diagonal_up(double a[size][size], int istart,int jstart)
{
	//Xét Tây Bắc
	for (int i = istart - 1, j = jstart -1; i >=0 && j >=0; i--, j--)
	{
		if (a[istart][jstart] < a[i][j])
			return false;
	}
	//Xét Đông Bắc
	for (int i = istart - 1, j = jstart + 1; i >=0 && j <size; i--, j++)
	{
		if (a[istart][jstart] < a[i][j])
			return false;
	}
	return true;
}
bool Verti(double a[size][size], int istart, int jstart)
{
	//Xét dọc lên và xuống
	for (int i = istart + 1; i < size; i++)
	{
		if (a[istart][jstart] < a[i][jstart])
			return false;
	}
	for (int i = istart - 1; i >=0; i--)
	{
		if (a[istart][jstart] < a[i][jstart])
			return false;
	}
	return true;
}
bool Hori(double a[size][size], int istart, int jstart)
{
	//Xét ngang tiến và lùi
	for (int j = istart + 1; j < size; j++)
	{
		if (a[istart][jstart] < a[istart][j])
			return false;
	}
	for (int j = istart - 1; j >=0; j--)
	{
		if (a[istart][jstart] < a[istart][j])
			return false;
	}
	return true;
}
int _346_(double a[size][size], int row, int col)
{
	Out2D_double(a, row, col);
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (Diagonal_up(a, i, j) == 1 && Diagonal_down(a,i,j)==1 && Hori(a,i,j)==1&& Verti(a,i,j)==1)
			count += 1;
		}
	}
	return count;
}
//Bài 347
bool Hori_saddle(double a[size][size],int istart,int jstart)
{
	for (int j = jstart + 1; j < size; j++)
	{
		if (a[istart][jstart] < a[istart][j])
			return false;
	}
	for (int j = jstart - 1; j >=0; j--)
	{
		if (a[istart][jstart] < a[istart][j])
			return false;
	}
	return true;
}
bool Verti_saddle(double a[size][size],int istart,int jstart)
{
	for (int i = istart + 1; i < size; i++)
	{
		if (a[istart][jstart] > a[i][jstart])
			return false;
	}
	for (int i = istart - 1; i >=0; i--)
	{
		if (a[istart][jstart] > a[i][jstart])
			return false;
	}
	return true;
}
int _347_(double a[size][size],int row, int col)
{
	Out2D_double(a, row, col);
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Hori_saddle(a, i, j) == true && Verti_saddle(a, i, j) == true)
				count += 1;
		}
	}return count;
}
#endif
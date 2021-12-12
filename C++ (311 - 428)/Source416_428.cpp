#include "Header.h"
//Bài 416 - 417 (417 thay điều kiện dương thành chẵn)
void _416_417_a_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	//Sắp dòng
	for (int times = 0; times < size; times++)
	{
		bool check_change = false;
		for (int m = 0; m < size; m++)
		{
			//Gán mảng phụ cho hàng
			int temp[size] = { 0 };
			for (int n = 0; n < size; n++) {
				temp[n] = a[m][n];
			}
			//Sắp xếp hàng của mảng phụ
			for (int i = 0; i < size; i++)
			{
				for (int k = i; k < size; k++) {
					if (temp[i] > temp[k] && temp[i] >0 && temp[k] > 0)
					{
						swapping_int(temp[i], temp[k]); check_change = true;
					}
				}
			}
			//Gán lại mảng phụ cho mảng
			for (int j = 0; j < size; j++) {
				a[m][j] = temp[j];
			}
		}
		
		for (int m = 0; m < size; m++)
		{
			int temp2[size] = { 0 };
			//Gán mảng phụ cho cột
			for (int n = 0; n < size; n++) {
				temp2[n] = a[n][m];
			}
			//Sắp xếp cột cho mảng phụ
			for (int i = 0; i < size; i++)
			{
				for (int k = i; k < size; k++) {
					if (temp2[i] > temp2[k] && temp2[i] > 0 && temp2[k] > 0)
					{
						swapping_int(temp2[i], temp2[k]); check_change = true;
					}
				}
			}
			//Gán lại mảng phụ cho mảng
			for (int i = 0; i < size; i++) {
				a[i][m] = temp2[i];
			}
		}
		if (check_change == false)
			break;
	}
	Out2D(a);
	cout << endl;
}
void _416_417_b_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	for (int times = 0; times < size; times++) {
		bool check_change = false;
		for (int m = 0; m < size; m++)
		{
			for (int n = 0; n < size; n++) {
				for (int k = n; k < size; k++)
				{
					if (a[m][n] > a[m][k] && a[m][n] > 0 && a[m][k] > 0){
						swapping_int(a[m][n], a[m][k]); check_change = true;
					}
					if (a[n][m] > a[k][m] && a[n][m] > 0 && a[k][m] > 0) {
						swapping_int(a[n][m], a[k][m]); check_change = true;
					}
				}
			}
		}
		if (check_change == false)
			break;
	}
	Out2D(a);
	cout << endl;
}
//Bài 418 - 419( 419 thay điều kiện dương và âm thành chẵn và lẻ)
void _418_419_(int a[size][size])
{
	//Không dùng mảng phụ
	Out2D(a);
	cout << endl;
	for (int times = 0; times < size; times++)
	{
		bool check_change = false;
		for (int m = 0; m < size; m++) {
			for (int n = 0; n < size; n++)
			{
				for (int k = n; k < size; k++) {
					//Xét hàng
					if (a[m][n] > a[m][k] && a[m][n] < 0 && a[m][k] < 0) {
						swapping_int(a[m][n], a[m][k]); check_change = true;
					}
					if (a[m][n] < a[m][k] && a[m][n] >0 && a[m][k] > 0) {
						swapping_int(a[m][n], a[m][k]); check_change = true;
					}
					//Xét cột
					if (a[n][m] > a[k][m] && a[n][m] < 0 && a[k][m] < 0) {
						swapping_int(a[n][m], a[k][m]); check_change = true;
					}
					if (a[n][m] < a[k][m] && a[n][m] >0 && a[k][m] > 0) {
						swapping_int(a[n][m], a[k][m]); check_change = true;
					}
				}
			}
		}
		if (check_change == false)
			break;
	}
	Out2D(a);
	cout << endl;
}
//Bài 420 - 421 (421 thêm điều kiện số dương, xét nhảy (swap skip)
void _420_421_(int a[size][size])
{
	//Sắp tăng dần theo từ trái sang phải và từ trên xuống dưới
	//Nếu muốn sắp xoay vòng (thuận chiều đồng hồ or not):
	//thì làm bốn 1 vòng lặp nhưng lặp 4 lần cho các biên khác nhau
	Out2D(a);
	cout << endl;
	int sub[2] = { 0,size - 1 };
	for (int times = 0; times < size; times++) {
		for (int k = 0; k < 2; k++)
		{
			bool check;
			for (int j = 0; j < size; j++)
			{
				check = false;
				for (int m = j; m < size; m++)
				{
					int c = a[sub[k]][m];
					int d = a[sub[k]][m + 1];
					if (c > d && c>0 && d>0)
					{
						swapping_int(a[sub[k]][m], a[sub[k]][m + 1]); check = true;
					}
				}
				for (int n = j; n < size; n++)
				{
					int e = a[n][sub[k]];
					int f = a[n + 1][sub[k]];
					if (e > f && e>0 && f>0)
					{
						swapping_int(a[n][sub[k]], a[n + 1][sub[k]]); check = true;
					}
				}
				if (check == false)
					break;
			}
		}
	}
	Out2D(a);
	cout << endl;
}
//Bài 422
void _422_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	int sum_line[size] = { 0 };
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		int sum = 0;
		for (int j = 0; j < size; j++)
		{
			sum += a[i][j];
		}
		sum_line[k++] = sum;
	}
	for (int i = 0; i < k-1; i++)
	{
		bool check = false;
		for (int m = 0; m < k - i-1; m++) {
			if (sum_line[m] > sum_line[m + 1])
			{
				//Đổi các tổng
				swapping_int(sum_line[m], sum_line[m + 1]);
				//Đổi các dòng
				swap_lines(a, m, m + 1); check = true;
			}
		}
		if (check == false)
			break;
	}	
	Out2D(a);
	cout << endl;
}
//Bài 423
struct coordinate {
	int x;
	int y;
};
typedef struct coordinate XY;
bool Duplicate_struct(XY zero[(size * size)],int x,int y)
{
	for (int c = 0; c < size * size; c++)
	{
		if (zero[c].x == x && zero[c].y == y)
			return true;// Số 0 đang chặn đường là số 0 thực
	}
	return false;
}
void _423_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	//Tìm số 0 có thật trong mảng
	XY zero[size * size];
	int z = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i][j] == 0)
			{
				zero[z].x = i;
				zero[z].y = j;
				z += 1;
			}
		}
	}
	//Xuất mảng chứa tọa độ zero thực:
	for (int i = 0; i < z; i++)
	{
		cout << zero[i].x << ":" << zero[i].y << " ";
	}
	cout<<endl;
	//Truyền giá trị qua mảng con, lấp mảng bằng số 0, sắp xếp mảng con
	int sub[size * size];
	int s = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sub[s++] = a[i][j];
			a[i][j] = 0;
		}
	}
	int size_sub = s;
	Sort_Ascending_int(sub,size_sub);
	for (int i = 0; i < size * size; i++)
	{
		cout << sub[i] << " ";
	}
	cout << endl;
	//Cảm biến dò đường và gắn giá trị đã sắp vào mảng
	int row_above = 0; int wall_right = size;
	int row_below = size - 1; int wall_left = 0;
	int col_right = size - 1; int wall_bot = size;
	int col_left = 0; int wall_top = 0;
	s = 0;
	for (int step = 0; step < size_sub;)
	{
		
		//Trái qua phải
		for (int y = col_left; y < wall_right; y++){
			//Nếu số chặn đường là 0 và là số 0 thực
			if (a[row_above][y] == 0 && Duplicate_struct(zero, row_above, y) == true)
				a[row_above][y] = 0;
			a[row_above][y] = sub[s++];
			step += 1;
		}
		row_above += 1; 
		wall_top += 1;
		//Comment !!!!!!
		//Trên xuống dưới
		for (int x = row_above; x < wall_bot; x++)
		{
			//Nếu số chặn đường là 0 và là số 0 thực
			if (a[x][col_right] == 0 && Duplicate_struct(zero, x, col_right) == true)
				a[x][col_right] = 0;
			a[x][col_right] = sub[s++];
			step += 1;
		}
		col_right -= 1;
		wall_right -= 1;
		//Comment !!!!!
		//Phải qua trái
		for (int y = col_right; y >= wall_left; y--)
		{
			if (a[row_below][y] == 0 && Duplicate_struct(zero, row_below, y) == true)
				a[row_below][y] = 0;
			a[row_below][y] = sub[s++];
			step += 1;
		}
		row_below -= 1;
		wall_bot -= 1;
		//Dưới lên trên
		for (int x = row_below; x >= wall_top; x--) {
			if (a[x][col_left] == 0 && Duplicate_struct(zero, x, col_left) == true)
				a[x][col_left] = 0;
			a[x][col_left] = sub[s++];
			step += 1;
		}
		col_left += 1;
		wall_left += 1;
	}
	cout << size_sub << endl;
	Out2D(a);
	cout << endl;
}
//Bài 424
void _424_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	//Code ziczac cho đường dài nhất
	//Bắt đầu với điểm đầu tiên góc trái (0;0).
	//Nhận xét thấy số phần tử ở đường ziczac giữa dài nhất luôn là size*2-1
	
	//Lấy ra các phần tử trước:
	int temp[2*size-1] = { 0 };
	int s = 1;
	int x = 0;
	int y = 1;
	//Mỗi step đi được là mỗi phần tử được lấy ra
	//Ta gán phần tử đầu sẵn cho mảng phụ
	//Lý do là vì tránh việc truy cập vùng nhớ không được cấp phép
	temp[0] = a[0][0];
	for (int steps = 0; steps < 2*size-3; steps += 2) {
		//Cho vào mảng phụ các phần tử cần lấy
		//Đi dọc thì số hàng +1	
		temp[s++] = a[x++][y];
		//Đi ngang thì số cột +1
		temp[s++] = a[x][y++];
	}
	Sort_Ascending_int(temp, s);
	s = 0;
	x = 0;
	y = 0;
	//Gán lại cho mảng chính
	for (int steps = 0; steps < 2 * size - 1; steps += 2) {

		a[x][y++] = temp[s++];
		a[x++][y] = temp[s++];
	}
	Out2D(a);
	cout << endl;
}
//Bài 425
void _425_(int a[size][size]) {
	Out2D(a);
	int temp[size * size] = { 0 };
	int k = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
		{
			if (a[i][j] < 0)
				temp[k++] = a[i][j];
		}
	}
	Sort_Descending_int(temp, k);
	for (int i = 0; i < k; i++) {
		cout << temp[i] << " ";
	}cout << endl;
	
}
//Bài 426
void _426_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	int b[size][size] = { 0 };
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) {
			b[i][j] = abs(a[i][j]);
		}
	}
	Out2D(b);
}
//Bài 427
int Max_row_col(int a[size][size], int x,int y)
{
	int max = a[x][0];
	//Xét dòng x
	for (int j=0; j < size; j++)
	{
		if (a[x][j] > max)
			max = a[x][j];
	}
	//Xét cột y
	for (int i=0; i < size; i++)
	{
		if (a[i][y] > max)
			max = a[i][y];
	}
	return max;
}
void _427_(int a[size][size])
{
	int b[size][size] = { 0 };
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			b[i][j] = Max_row_col(a, i, j);
		}
	}
	Out2D(b);
}
//Bài 428
int Check_Around(int a[size+2][size+2],int x,int y)
{
	int count = 0;
	//Kiểm tra hai hàng trên và dưới
	for (int i = x-1;i<= x+1;i+=2){
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (a[i][j] > 0)
				count += 1;
		}
	}
	//Kiểm tra hai phần tử kế bên cùng hàng
	for (int j = y - 1; j <= y + 1; j += 2)
	{
		if (a[x][j] > 0)
			count += 1;
	}
	return count;
}
void _428_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	//Ma trận con cần xây dựng
	int b[size][size] = { 0 };

	//Qua thực nghiệm thì có thể thấy ma trận bao quanh một ma trận vuông bất kỳ sẽ có dạng:
	// size^2 + 4size +4 (1)
	//Tương ứng với ma trận bị bao quanh + bốn cạnh dôi ra của ma trận nhỏ + bốn góc.
	//Biến đổi ta được với ma trận bất kỳ có size thì kích thước ma trận bao quanh là size+2
	//(do pt (1) thành (size+2)^2)
	int bigger[size + 2][size + 2] = { 0 };
	
	//Chép ma trận nhỏ sang ma trận lớn 
	int x = 1;
	int y = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			bigger[x][y++] = a[i][j];
		}x += 1; y = 1;
	}
	//Lúc này ta có thể so sánh phần tử với phần tử xung quanh mà ko bị lỗi truy cập vùng nhớ không được phép\
	//Lý do là vì ta đã bao bên ngoài ma trận lớn hơn chứa các số 0
	int x_b = 0;
	int y_b = 0;
	for (int i = 1 ; i < size+1; i++)
	{
		for (int j = 1; j < size + 1; j++)
		{
			b[x_b][y_b++] = Check_Around(bigger, i, j);
		}x++;
	}
	
	Out2D(b);
}
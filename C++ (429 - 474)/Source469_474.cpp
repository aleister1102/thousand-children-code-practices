#include "Header.h"
//Bài 469
void _ADD2Dto2D_(int a[size][size], int b[size][size]) 
{
	//Lưu ý là tổng hai ma trận phải luôn cùng kích thước
	//Xuất hai ma trận trên hàng ngang
	//Cộng ma trận b vào ma trận a
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] += b[i][j];
		}
	}
}
//Bài 470
void _MINUS2Dfor2D_(int a[size][size], int b[size][size]) 
{
	//Lưu ý là tổng hai ma trận phải luôn cùng kích thước
	//Xuất hai ma trận trên hàng ngang
	//Cộng ma trận b vào ma trận a
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] -= b[i][j];
		}
	}
}
//Bài 471
void _471_(int a[size][size], int b[size][size]) 
{
	//Lưu ý là tổng hai ma trận phải luôn cùng kích thước
	//Xuất hai ma trận trên hàng ngang
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j] << "  ";
		}cout << "\t";
		for (int j = 0; j < size; j++) {
			cout << b[i][j] << "  ";
		}cout << endl;
	}
	//Cộng ma trận b vào ma trận a
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] *= b[i][j];
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << a[i][j] << "  ";
		}cout << endl;
	}
}
//Bài 472 - 473 cần có kiến thức về định thức ma trận
//Bài 474 tương tự như 468 (do 468 đã làm tổng quát cho các ma phương lẻ, giờ sẽ làm cho chăn)
//Hàm kiểm tra phần tử có thuộc chéo chính hay không
bool Diagonal(int x,int y,int x_square,int y_square) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			//Nếu hằng số cộng thêm đi theo 1 đường chéo (hàng và cột đều tăng 1)
			//thì là chéo chính
			if (i == j && x == x_square + i && y == y_square + j)
			{
				cout << "Phan tu " << x << "|" << y << " thuoc cheo chinh" << endl; return true;
			}
			//Nếu hàng tăng 1 nhưng cột giảm 1 thì vẫn là chéo (chéo phụ)
			if (i == 3-j && x== x_square+i && y== y_square+j )
			{
				cout << "Phan tu " << x << "|" << y << " thuoc cheo phu" << endl; return true;
			}
		}
	}
		cout << "Phan tu " << x << "|" << y << " khong thuoc duong cheo" << endl;
		return false;
}
//Hàm xây dựng ma phương 4n
void _474a_() {
	int Square[size][size] = { 0 };
	int x_square = 0;
	int y_square = 0;
	//Các số điền vào ma phương, 1 cái tăng 1 cái giảm
	int m = 1;
	int n = size*size;
	for (int i = 0; i < size; i++) {
		//Kết thúc một hàng thì reset biến mốc trục ngang thành 0
		y_square = 0;
		//Nếu bước qua hàng số 4n thì mốc trục dọc tăng lên 4
		if (i % 4 == 0 && i >= 4)
			x_square += 4;
		for (int j = 0; j < size; j++) {
			//Nếu cột qua các mốc 4n thì mốc trục ngang tăng 4
			if (j % 4 == 0 && j >= 4)
				y_square += 4;
			//Nếu không thuộc đường chéo thì gán số tăng
			if (Diagonal(i, j, x_square, y_square)==false)
				Square[i][j] = m;
			//Nếu thuộc chéo thì gán số giảm
			else
				Square[i][j]=n;
			m++;
			n--;
		}
	}
	cout << endl;
	Out2D(Square);
}
//Hàm tạo ma trận cuối
void FinalSquare(int final[size][size],int n,int con2,int con3) {
	int jump = size/2;
	for (int i = 0; i < size/2; i++) {
		for (int j = 0; j <= n; j++) {
			final[i][j] = con2;
			final[i+jump][j] = -con2;
		}
		for (int j = 0; j <= n - 1; j++) {
			final[i][size - 1 - j] = -con3;
			final[i + jump][size - 1 - j] = con3;
		}
	}
	int mid = size / 4;
	swapping_int(final[mid][0], final[mid][n+1]);
	mid += jump;
	swapping_int(final[mid][0], final[mid][n+1]);;
}
//Hàm tạo ma phương rỗng
void EmptySquare(int empty[size][size], int con1, int con2, int con3)
{
	int jump = size/2;
	for (int i = 0; i < size / 2; i++) {
		for (int j = 0; j < size / 2; j++) {
			empty[i][j] = 0;
			empty[i][j + jump] = con1;
			empty[i + jump][j] = con2;
			empty[i + jump][j + jump] = con3;
		}
	}
}
//Hàm nhân bản vô tính
void Cloning(int a[size][size]) {
	
	int jump = size/2;
	for (int i = 0; i < size / 2; i++) {
		for (int j = 0; j < size / 2; j++) {
			a[i][j+jump] = a[i][j];
			a[i + jump][j] = a[i][j];
			a[i + jump][j + jump] = a[i][j];
		}
	}
}
//Hàm Siamese
void Siamese(int a[size][size]) 
{
	//Comment
	const int small_size = size / 2 +1 ;
	int sub[small_size][small_size] = { 0 };
	int num = 1;
	sub[0][size / 4 + 1] = num;
	int row = 0;
	int col = size / 4 + 1;
	do{
		if (sub[small_size-2][size/4+1] == size*size/4)
			break;
		if (row == 0 && col == small_size-1) {
			row += 1; sub[row][col] = ++num;
		}
		if (row >= 1 && sub[row - 1][col + 1] != 0)
		{
			row += 1;
			sub[row][col] = ++num;
		}
		if (row - 1 < 0)
		{
			row = small_size-1; sub[row][col] = num;
		}
		if (col + 1 > small_size-1)
		{
			col = 0; sub[row][col] = num;
		}
		sub[--row][++col] = ++num;
	} while (num <= size*size/4);
	for (int i = 0; i < small_size-1; i++) {
		for (int j = 1; j < small_size; j++) {
			cout << sub[i][j] << "  ";
		} cout << endl;
	}
	for (int i = 0; i <small_size-1; i++) {
		for (int j = 0; j < small_size - 1; j++) {
			a[i][j] = sub[i][j + 1];
		}
	}
}
//Hàm xây dựng ma phương 4n+2
void _474b_() {
	int Square[size][size] = { 0 };
	if ((size / 2) % 2 == 0)
		cout << "Ma phuong khong co dang 4n+2" << endl;
	//Tìm n trong dạng 4n+2=size
	int n = (size - 2) / 4;
	//Tính các hằng số cần thiết
	int con1 = (size * size) / 2;
	int con2 = (3 * size * size) / 4;
	int con3 = (size * size) / 4;
	//Chia ra thành 4 ma trận(size/2)*(size/2), tạo các mốc
	int Xmark = size/2;
	int Ymark = size/2;
	//Dùng Siamese cho ma phương nhỏ góc trái đầu tiên
	Siamese(Square);
	//Nhân bản vô tính cho ma phương khác xung quanh trong ma phương lớn
	Cloning(Square);
	//Tạo ma phương rỗng chứa các hằng số
	int Empty[size][size] = { 0 };
	EmptySquare(Empty, con1, con2, con3);
	//Cộng ma phương empty vào ma phương square
	_ADD2Dto2D_(Square, Empty);
	//Tạo bảng cuối xây dựng từ bảng empty (các phần tử = 0)
	int Final[size][size] = { 0 };
	FinalSquare(Final, n, con2, con3);
	//Cộng bảng cuối vào Square
	_ADD2Dto2D_(Square, Final);
	Out2D(Square);
	
}

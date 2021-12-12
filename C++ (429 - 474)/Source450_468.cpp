#include "Header.h"	
//Bài 450
int _450_(int a[size][size]) {
	//Xét tam giác trên chéo chính rồi kiểm tra nó với phần tử đối xứng
	Out2D(a);
	cout << endl;
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			//cout << a[i][j] << " " << endl;
			//cout << a[j][i] << " " << endl;
			if (a[i][j] == a[j][i])
				count += 1;
		}
	}
	cout << "So cap doi xung: " << count << endl;
	return 0;
}
//Bài 451
bool Descending_line(int a[size][size], int row)
{
	for (int j = 0; j < size-1; j++) {
		if (a[row][j] < a[row][j + 1])
			return false;
	}
	return true;
}
int _451_(int a[size][size])
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (Descending_line(a, i))
			count += 1;
	}
	cout << count;
	return count;
}
//Bài 452
void Insert2D(int a[size + 2][size + 2], int value) {
	for (int i = 0; i < size + 2; i++) {
		for (int j = 0; j < size + 2; j++) {
			a[i][j] = value;
		}
	}
}
int _Min2D_(int a[size][size]) 
{
	int min = a[0][0];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i][j] < min)
				min = a[i][j];
		}
	}
	return min;
}
bool Check_Around(int a[size + 2][size + 2], int x, int y)
{
	//Kiểm tra hai hàng trên và dưới
	for (int i = x - 1; i <= x + 1; i += 2) {
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (a[x][y] < a[i][j])
				return false;
		}
	}
	//Kiểm tra hai phần tử kế bên cùng hàng
	for (int j = y - 1; j <= y + 1; j += 2)
	{
		if (a[x][y] < a[x][j])
			return false;
	}
	return true;
}
int _452_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int count = 0;
	//Tạo mảng lớn hơn, các giá trị bao quanh của mảng lớn nhỏ hơn 
	//giá trị nhỏ nhất của ma trận.
	//(Để điều kiện cực đại có thể thỏa mãn nếu so sánh với phần tử bao quanh)
	int bigger[size + 2][size + 2];
	Insert2D(bigger, _Min2D_(a) - 1);
	int x = 1, y = 1;
	//Gán cho mảng lớn hơn
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			bigger[x][y++] = a[i][j];
		}
		x += 1; y = 1;
	}
	//So sánh tìm cực đại
	for (int i = 0; i < size + 2; i++) {
		for (int j = 0; j < size + 2; j++) {
			if (Check_Around(bigger, i, j))
				count += 1;
		}
	}
	cout << count;
	return count;
}
//Bài 453
int _453_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (a[i][i] > 0)
			count += 1;
	}
	cout << count << endl;
	return count;
}
//Bài 454
int _454_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (a[i][size-i-1] < 0)
			count += 1;
	}
	cout << count << endl;
	return count;
}
//Bài 455
int _455_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int count = 0;
	//Ma trận tam giác trên tính luôn cả đường chéo.
	//Ở đây xét chéo chính
	for (int i = 0; i < size;i ++) {
		for (int j = i; j < size; j++) {
			if (a[i][j] % 2 == 0)
				count += 1;
		}
	}
	cout << count;
	return count;
}
//Bài 456
bool _456_(int a[size][size]) 
{
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size - 1; i++) {
		if (a[i][i] > a[i + 1][i + 1])
		{
			cout << "Cheo chinh khong tang dan" << endl;
			return false;
		}
	}
	cout << "Cheo chinh tang dan" << endl;
	return true;
}
//Bài 457
bool _457_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if (a[i][j] != a[j][i])
			{
				cout << "Ma tran khong doi xung qua cheo chinh" << endl;
				return false;
			}
		}
	}
	cout << "Ma tran doi xung qua cheo chinh" << endl;
	return true;
}
//Bài 458
bool _458_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			cout << a[i][j] << "  ";
			if (a[i][j] != a[j][i])
			{
				cout << "ma tran khong doi xung qua cheo phu" << endl;
				return false;
			}
		}cout << endl;
	}
	cout << "Ma tran doi xung qua cheo phu" << endl;
	return true;
}//Bài 459
//Bài 459
bool _459_(int a[size][size]) 
{
	Out2D(a);
	cout << endl;
	//Hằng số kì ảo tương ứng với ma trận bậc NxN là:
	// M=n*(n^2+1)/2
	//Vì thế ta chỉ cần kiểm tra tổng các hàng, cột, chéo chính phụ với hằng số kì ảo
	int M = ((size * (size * size + 1)) / 2);
	//Kiểm tra hàng và cột
	for (int m = 0; m < size; m++) {
		int row = 0, col = 0;
		for (int n = 0; n < size; n++) {
			row += a[m][n];
			col += a[n][m];
		}
		if (row != M || col != M) {
			cout << "Ma tran khong phai ma phuong" << endl;
			return false;
		}
	}
	//Kiểm tra chéo chính phụ
	int main_dia = 0, sub_dia = 0;
	for (int i = 0; i < size; i++) {
		main_dia += a[i][i];
		sub_dia += a[i][size - i - 1];
	}if (main_dia != M || sub_dia != M)
	{
		cout << "Ma tran khong phai ma phuong" << endl;
		return false;
	}
	cout << "Ma tran la ma phuong" << endl;
	return true;
}
//Bài 460
void _460_(int a[size][size]) 
{
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			if (a[i][i] < a[k][k])
				swapping_int(a[i][i], a[k][k]);
		}
	}
	Out2D(a);
}
//Bài 461
void _461_(int a[size][size]) 
{
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int k = 0; k < size; k++) {
			if (a[i][size-i-1] > a[k][size-k-1])
				swapping_int(a[i][size-i-1], a[k][size-k-1]);
		}
	}
	Out2D(a);
}
//Bài 462 - 463  là hàm swapping_lines và swapping_columns
//Bài 464
void _464_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	int row[size] = { 0 };
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			row[i] += a[i][j];
		}
	}
	for (int i = 0; i < size - 1; i++) {
		bool check = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (row[j] > row[j + 1])
			{
				swapping_int(row[j], row[j + 1]);
				swap_lines(a, j, j + 1);
				check = true;
			}
		}
		if (check == false)
			break;
	}
	Out2D(a);
}
//Bài 465
void Mover_right_465(int a[size][size], int row,int index)
{
	int temp = a[row][index];
	for (int j = index; j > 0; j--) {
		a[row][j] = a[row][j - 1];
	}
	a[row][0] = temp;
}
void _465_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i][j] % 2 == 0)
				Mover_right_465(a, i, j);
		}
	}
	Out2D(a);
}
//Bài 466
void _466_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	//Ma trận nXn thì tam giác trên (ở đây lấy chéo chính làm ví dụ)
	//có kích thước là size^2-size/2 phần tử
	//Tương ứng với tổng phần tử trừ cho chéo chính(hoặc phụ) chia hai ra một tam giác trên(hoặc dưới)
	int triangle[((size * size) - size) / 2] = { 0 };
	int m = 0;
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			triangle[m++] = a[i][j];
		}
	}
	for (int i = 0; i < m-1; i++) {
		for (int k = 0; k < m - i - 1; k++) {
			if (triangle[k] > triangle[k + 1])
				swapping_int(triangle[k], triangle[k + 1]);
		}
	}
	m = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			a[i][j] = triangle[m++];
		}
	}
	Out2D(a);
}
//Bài 467
void _467_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	//Ma trận nXn thì tam giác trên (ở đây lấy chéo chính làm ví dụ)
	//có kích thước là size^2-size/2 phần tử
	//Tương ứng với tổng phần tử trừ cho chéo chính(hoặc phụ) chia hai ra một tam giác trên(hoặc dưới)
	int triangle[((size * size) - size) / 2] = { 0 };
	int m = 0;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			triangle[m++] = a[i][j];
		}
	}
	for (int i = 0; i < m-1; i++) {
		for (int k = 0; k < m - i - 1; k++) {
			if (triangle[k] > triangle[k + 1])
				swapping_int(triangle[k], triangle[k + 1]);
		}
	}
	m = 0;
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			a[i][j] = triangle[m++];
		}
	}
	Out2D(a);
}
//Bài 468
void _468_() {
	//Tạo một ma phương có kích thước lẻ
	int Square[size][size] = { 0 };
	int num = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Square[i][j] = num++;
		}
	}
	const int size_tower = 2 * size - 1;
	int Tower[size_tower][size_tower] = { 0 };
	int m = 0;
	int n = 0;
	//Chép giá trị vào mảng lớn sao cho hình thành dạng các tháp
	//Điểm bắt đầu tăng dần xuống các dòng dưới
	for (int k = size-1; k < size_tower; k++) {
		//Index cột tăng dần, có giá trị bằng khoảng cách giữa dòng và kích thước +1
		int j = k + 1 - size;
		//Index dòng cần chép giá trị giảm dần
		for (int i = k; i >= k + 1 - size; i--) {
			Tower[i][j++] = Square[m][n++];
		}
		//Kết thúc một chu trình thì dòng trong mảng con tăng, cột được reset
		m++; n = 0;
	}
	//Quét các tháp và cho giá trị của tháp vào trong mảng cần lấy bên trong
	//Qua thực nghiệm thì thấy số dòng/cột các tháp (hay chiều cao tháp)
	//luôn = (size-1)/2

	//Quét tháp dọc
	for (int i = 0; i < (size - 1) / 2; i++) {
		//Cột bắt đầu xét của tháp sẽ là cột ở giữa (rồi tiến dần về bên trái)
		int start_colum = size - 1-i;
		//Vòng lặp bề rộng của tháp (j phụ thuộc vào phương trình 2i+1) 
		//(tùy thuộc bậc thang nào của tháp mà bề rộng sẽ thay đổi)
		for (int j = 0; j < 2*i+1; j++) {
			//Các số 0 rỗng thì không chép nên phải có điều kiện loại trừ
			if (Tower[i][start_colum + j] != 0) {
				//Chép hai phần tử cách nhau size dòng
				Tower[i + size][start_colum + j] = Tower[i][start_colum + j];
				//Đảo chiều cho tháp dọc quay ngược
				Tower[size_tower-1-i-size][start_colum + j] = Tower[size_tower-1-i][start_colum + j];
			}
		}
	}

	//Quét tháp ngang
	for (int j = 0; j < (size - 1) / 2; j++) {
		//Dòng bắt đầu xét của tháp
		int start_row = size - 1 - j;
		//Vòng lặp bề rộng của tháp ngang
		for (int i = 0; i < 2 * j + 1; i++) {
			if (Tower[start_row+i][j] != 0) 
			{
			//Chép hai phần tử cách nhau size cột
			Tower[start_row + i][j + size] = Tower[start_row + i][j];
			//Đảo chiều cho tháp ngang bên phải
			Tower[start_row + i][size_tower-1-j-size] = Tower[start_row + i][size_tower-1-j]; }
		}
	}
	//Chép lại mảng Square ban đầu
	int start_i = (size - 1) / 2;
	int start_j = (size - 1) / 2;
	m = 0, n = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Square[m][n++] = Tower[start_i + i][start_j + j];
		}m++; n = 0;
	}
	//Xuất hai mảng Tower và Square
	for (int i = 0; i < size_tower; i++) {
		for (int j = 0; j < size_tower; j++) {
			cout << Tower[i][j] << " ";
		}cout << endl;
	}cout << endl;
	Out2D(Square);
}
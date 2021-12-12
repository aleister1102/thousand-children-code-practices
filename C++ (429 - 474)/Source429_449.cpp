#include"Header.h"
//Bài 429 đến 432 
void _429_432_(int a[size][size]) 
{
	//(Nhập xuất như nhau nên chỉ làm xuất,int và double chỉ khác kdl nên chỉ làm int, tiện cho mấy bài sau)
	Out2D(a);
	cout << endl;
#if 0
	//Xét trên đường chéo chính
	for (int i = 0; i < size; i++) {
		cout << a[i][i] << " ";
	}cout << endl;
	//Xét tam giác trên chéo chính
	for (int i = 0; i < size - 1; i++)
	{
		for (int k = 1; k <= 1 + i; k++)
		{
			cout << "  ";
		}
		for (int j = 1 + i; j < size; j++) {
			cout << a[i][j] << "  ";
		}cout << endl;
	}
	//Xét tam giác dưới chéo chính
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			cout << a[i][j] << "  ";
		}cout << endl;
	}
	//Xét đường chéo phụ
	for (int i = 0; i < size; i++) {
		cout << a[i][size - i - 1] << " ";
	}
	//Tam giác trên chéo phụ
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			cout << a[i][j] << "  ";
		}cout << endl;
	}
	//Tam giác dưới chéo phụ
	for (int i = 1; i < size; i++) {
		for (int k = 0; k < size - i; k++) {
			cout << "   ";
		}
		for (int j = size - i; j < size; j++) {
			cout << a[i][j] << " ";
		}cout << endl;
	}
#endif
}
//Bài 433 đã có MAX2D
//Bài 434
bool _434_(int a[size][size])
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i][j] % 2 == 0 && a[i][j] < 2015)
				return true;
		}
	}return false;
}
//Bài 435
int _435_(int a[size][size]) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Elementary(a[i][j])) {
				count += 1;
			}
		}
	}
	return count;
}
//Bài 436
int _436_(int a[size][size]) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (a[i][j] < 0)
				sum += a[i][j];
		}
	}return sum;
}
//Bài 437
void _437_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int b[size * size] = { 0 };
	int s = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			b[s++] = a[i][j];
		}
	}
	Sort_Ascending_int(b,size*size);
	s = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			a[i][j] = b[s++];
		}
	}
	Out2D(a);
}
//Bài 438
int _438_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int sum = 0;
#if 0
	//Xét tam giác trên chéo chính
	//Chừa hàng cuối
	for (int i = 0; i < size - 1; i++)
	{
		//Cột = hàng + 1
		for (int j = i + 1; j < size; j++) {
			sum += a[i][j];
		}
	}
#endif
	//Xét tam giác trên chéo phụ
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			sum += a[i][j];
		}
	}
	cout << sum;
	return sum;
	
}
//Bài 439
int _439_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int sum = 0;
#if 0
	//Xét tam giác dưới chéo chính
	for (int i = 1; i < size ; i++)
	{
		for (int j = 0; j < i; j++) {
			sum += a[i][j];
		}
	}
#endif
	//Xét tam giác trên chéo phụ
	for (int i = 1; i < size; i++) {
		for (int j = size - i; j < size; j++) {
			sum += a[i][j];
		}
	}
	cout << sum;
	return sum;
	
}
//Bài 440
int _440_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i][i];
	}cout << sum;
	return sum;
}
//Bài 441
int _441_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i][size-i-1];
	}cout << sum;
	return sum;
}
//Bài 442
int _442_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int index[3] = { 0,size - 1,0 };
	int sum = 0;
	//Vòng lặp dòng/cột (đầu và cuối)
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < size - 1; j++)
		{
			//Cộng các hàng
			sum += a[index[i]][j];
			//Cộng các cột
			sum += a[j][index[i]];
		}
		sum += a[index[i]][index[i]];
		//Với các phần tử góc ở trên chéo phụ thì mở rộng mảng ra thêm 1 phần tử 
		//Sao cho quét qua được hai cặp 0, size-1 và size-1,s
		sum += a[index[i]][index[i + 1]];
	}
	cout << sum;
	return sum;
}
//Bài 443
int _443_(int a[size][size]) {
	//Chỉ xét chéo chính (chéo phụ cùng ý tưởng)
	Out2D(a);
	cout << endl;
	int max = a[0][size - 1];
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			cout << a[i][j] << "  ";
			if (a[i][j] > max)	
				max = a[i][j];
		}cout << endl;
	}
	cout << max;
	return max;
}
//Bài 444
int _444_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int max = a[1][0];
	for (int i = 1; i < size; i++) {
		for (int j = 0; j < i; j++) {
			cout << a[i][j] << "  ";
			if (a[i][j] > max)
				max = a[i][j];
		}cout << endl;
	}
	cout << max;
	return max;

}
//Bài 445
int _445_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int max = a[0][0];
	for (int i = 0; i < size; i++) {
		if (a[i][i] > max) {
			max = a[i][i];
		}
	}
	cout << max;
	return max;
}
//Bài 446
int _446_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int max = a[0][0];
	for (int i = 0; i < size; i++) {
		if (a[i][size-i-1] > max) {
			max = a[i][size-i-1];
		}
	}
	cout << max;
	return max;
}
//Bài 447
int _447_(int a[size][size]) {
	Out2D(a);
	cout << endl;
	int max = 2;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (Elementary(a[i][j]) == true && a[i][j] > max)
				max = a[i][j];
		}
	}
	cout << max;
	return max;
}
//Bài 448
bool Couple_Duplicate(int a[(size * size) / 2], int b[(size * size) / 2],int x,int y,int end)
{
	for (int i = 0; i < end; i++) {
		if ((x == a[i] || y == a[i]) && (x == b[i] || y == b[i]))
			return true;
	}
	return false;
}
void _448_(int a[size][size]) {
	int closest = 10;
	int left[(size * size) / 2] = { 0 };
	int right[(size * size) / 2] = { 0 }; int c = 0;
	int distance;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int x = 0; x < size; x++) {
				for (int y = 0; y < size; y++) {
					distance = abs(a[i][j] - a[x][y]);
					if (distance < closest && a[x][y] != a[i][j])
					{
						closest = distance;
						cout << closest << endl;
						c = 0; 
					}
					if (closest == distance) {
						if (Couple_Duplicate(left, right, a[x][y], a[i][j], c) == false)
						{
							left[c] = a[i][j];
							right[c] = a[x][y];
							c += 1;
						}
					}
				}
			}
		}
	}
	cout << "So cac cap gan nhau: " << c << endl;
	cout << "Cac cap gan nhau la: " << endl;
	for (int i = 0; i < c; i++) {
		cout << left[i] << " va " << right[i] << endl;
	}
}
//Bài 449 ý tưởng giống bài ma trận con lớn nhất
//Ý tưởng cũ :
//Tính các ma trận con lớn nhất rồi giảm dần, cụ thể:
/*
Tính ma trận có dạng sizeXn trước, sau đó cắt các ma trận này. 

Việc tính các ma trận dựa trên ý tưởng cho vào 1 hay 2 phần tử ở góc trái trên (tây bắc):
rồi chúng ta tính các phần tử xung quanh của chúng, dựa trên phiên làm việc đó là sizeXn hay size-1Xn,...
Phiên làm việc kết thúc khi ma trận lớn cần tính không thể cắt được nữa (là 3Xn hay nX3)
Nếu là phiên làm việc ví dụ 4Xn hay nX4 thì ta sẽ tính xung quanh phần tử đầu vào bán kính 4 phần tử (dọc hoặc ngang).

Về việc cắt:
Chúng ta sẽ cắt theo cặp
Ví dụ nếu đó là ma trận ngang có kích thước 3x4 (4 là size) thì ta sẽ lặp việc cắt từng cột.
Mỗi lần lặp tạo ra một ma trận mới lưu vào mảng chứa các tổng của ma trận.
Tương tự đối với các ma trận dọc như 4x3,3x2,... thì chúng ta sẽ cắt các hàng ngang.

Tuy nhiên bài này cần lưu thêm tọa độ phần tử góc tây bắc và phần tử góc đông nam để biết được ma trận con nào có tổng lớn nhất
Dẫu vậy cần cải tiến sao cho có thể cắt từ 2-3 hàng/cột (vì ma trận con ko nhất thiết được tạo ra nhờ cắt only 1 cột/1 hàng)
Nhận xét rằng hàm cắt và hàm tính xung quanh luôn cần 1-2 vòng lặp, rất gọn gàng, nhưng mà lại khó sử dụng ở chỗ phải biết cắt vị trí nào.
*/
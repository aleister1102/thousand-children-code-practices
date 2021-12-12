#include "Header.h"
//Bài 407
void _407_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			bool check = false;
			for (int k = 0; k < size - j - 1; k++)
			{
				if (a[i][k] > a[i][k + 1])
				{
					swapping_int(a[i][k], a[i][k + 1]);
					check = true;
					check = true;
				}
			}
			if (check == false)
				break;
		}
	}
	Out2D(a);
}
//Bài 408
void _408_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			bool check = false;
			for (int k = 0; k < size - j - 1; k++)
			{
				if (a[i][k] < a[i][k + 1])
				{
					swapping_int(a[i][k], a[i][k + 1]);
					check = true;
					check = true;
				}
			}
			if (check == false)
				break;
		}
	}
	Out2D(a);
}
//Bài 409
void _409_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			bool check = false;
			for (int k = 0; k < size - i - 1; k++)
			{
				if (a[k][j] > a[k+1][j])
				{
					swapping_int(a[k][j], a[k+1][j]);
					check = true;
				}
			}
			if (check == false)
				break;
		}
	}
	Out2D(a);
}
//Bài 410
void _410_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			bool check = false;
			for (int k = 0; k < size - i - 1; k++)
			{
				if (a[k][j] < a[k + 1][j])
				{
					swapping_int(a[k][j], a[k + 1][j]);
					check = true;
				}
			}
			if (check == false)
				break;
		}
	}
	Out2D(a);
}
bool Sort_DAscending_int(int sub[size * size])
{
	//Cờ lệnh thứ hai nếu có sự thay đổi thì từ false thành true;
	bool check; bool check_change = false;
	for (int i = 0; i < size - 1; i++)
	{
		check = false;
		for (int k = 0; k < size - i - 1; k++)
		{
			if (sub[k] > sub[k + 1])
			{
				swapping_int(sub[k], sub[k + 1]);
				check = true;
				check_change = true;
			}
		}
		if (check == false)
			break;
	}
	return check_change;
}
//Bài 411
void _411_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	int sub[size * size] = { 0 };
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (a[i][j]%2==0 && Duplicate(sub,k,a[i][j])==false )
				sub[k++] = a[i][j];
		}
	}Sort_DAscending_int(sub);
	for
		 (int i = 0; i < k; i++)
	{
		cout << sub[i] << " ";
	}
	cout << endl;
}
//Bài 412
void _412_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	int sub[size * size] = { 0 };
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Elementary(a[i][j])==true && Duplicate(sub,k,a[i][j])==false )
				sub[k++] = a[i][j];
		}
	}Sort_DAscending_int(sub);
	for
		 (int i = 0; i < k; i++)
	{
		cout << sub[i] << " ";
	}
	cout << endl;
}
//Bài 413
void _413_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int i = 0; i < size; i+=1)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < size - 1; j++)
			{
				for (int k = 0; k < size - j - 1; k++) {
					if (a[i][k] > a[i][k + 1])
						swapping_int(a[i][k], a[i][k + 1]);
				}
			}
		}
		else
		{
			for (int j = 0; j < size - 1; j++)
			{
				for (int k = 0; k < size - j - 1; k++) {
					if (a[i][k] < a[i][k + 1])
						swapping_int(a[i][k], a[i][k + 1]);
				}
			}
		}
	}
	Out2D(a);
}
//Bài 414
void _414_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	for (int j = 0; j < size; j += 1)
	{
		if (j % 2 == 0)
		{
			for (int i = 0; i < size - 1; i++)
			{
				for (int k = 0; k < size - i - 1; k++) {
					if (a[k][j] < a[k+1][j])
						swapping_int(a[k][j], a[k + 1][j]);
				}
			}
		}
		else
		{
			for (int i = 0; i < size - 1; i++)
			{
				for (int k = 0; k < size - i - 1; k++) {
					if (a[k][j] > a[k+1][j])
						swapping_int(a[k][j], a[k + 1][j]);
				}
			}
		}
	}
	Out2D(a);
}
//Bài 415a
void _415a_(int a[size][size])
{
	Out2D(a);
	cout << endl;
	//Có mảng phụ
	//Vòng lặp làm cho mảng sau khi xếp hàng và cột được xếp lại
	//(vì cột/hàng lúc đó có thể chưa xếp xong)
	for (int times = 0; times < size; times++) {
		//Nếu hàm Sort_DAscending ==true (có sự thay đổi) thì cờ lệnh cũng là true
		bool check = false;
		for (int i = 0; i < size; i++) {
			int temp[size] = { 0 };
			//Gán mảng phụ cho hàng
			for (int j = 0; j < size; j++) {
				temp[j] = a[i][j];
			}
			//Sắp xếp tăng dần theo hàng, kiểm tra sự thay đổi và gán lại vào mảng chính
			if (Sort_DAscending_int(temp)) {
				for (int j = 0; j < size; j++)
				{
					a[i][j] = temp[j];
				}check = true; //Có sự thay đổi
			}
		}
		for (int j = 0; j < size; j++) {
			int temp[size] = { 0 };
			//Gán mảng phụ cho cột
			for (int i = 0; i < size; i++) {
				temp[i] = a[i][j];
			}
			//Tăng dần theo cột
			if (Sort_DAscending_int(temp)) {
				for (int i = 0; i < size; i++)
				{
					a[i][j] = temp[i];
				}check = true; //Có sự thay đổi
			}
		}
		if (check == false)
			break;
	}
	Out2D(a);
	cout << endl;
}
//Bài 415b
void _415b_(int a[size][size])
{
	//Comment đã viết ở câu a
	Out2D(a);
	cout << endl;
	for (int times = 0; times < size; times++)
	{
		bool check_change = false;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size-1; j++)
			{
				bool check = false;
				for (int k = 0; k < size - j - 1; k++)
				{
					//Ở đây cùng sort cột và hàng trong một vòng lặp
					if (a[i][k] > a[i][k + 1])
					{
						swapping_int(a[i][k], a[i][k + 1]); check = true, check_change = true;
					}
					if (a[k][i] > a[k + 1][i]) {
						swapping_int(a[k][i], a[k + 1][i]); check = true, check_change = true;
					}
				}
				if (check == false)
					break;
			}
		}
		if (check_change == false)
			break;
	}
	Out2D(a);
	//Kết quả câu a và b đều đúng nhưng chúng lại khác nhau
	//Giải thích một chút:
	//Câu a tách ra một mảng phụ, sắp hết size-1 dòng một lần rồi mới sắp đến cột.
	//Câu b sắp một dòng (ví dụ dòng i) xong rồi lập tức sắp cột i.
	//Hai cách có vòng lặp times ở ngoài đảm bảo điều kiện tăng dần ở hàng và cột luôn đúng.
	//Dẫu hai cách khác nhau nhưng thật sự chúng đều cho ra kết quả đúng, từ đây ta có thể áp dụng sắp mảng kiểu vậy theo hai cách:
	//Có mảng phụ và không có mảng phụ
}

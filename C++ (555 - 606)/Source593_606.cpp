#include "Header.h"
#include "NewType.h"
//Kiểm tra năm nhuận
bool LeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
//594: Nhập ngày
date Input_date() W
{
	date result;
	do {
		cout << "Nhap ngay,thang va nam " << endl;
		cin >> result.day >> result.month >> result.year;
	} while (result.day < 1 || result.day>31 || result.month < 1 || result.month>12 || result.year < 1|| (result.day>29 && result.month==2));
	if (LeapYear(result.year) == false && result.day > 28 && result.month == 2)
		cout << "Ngay khong hop le" << endl;
	return result;
}
//595: Xuất ngày
void Output_date(date para)
{
	cout << "Ngay/Thang/Nam la: " << endl;
	cout << "(" << para.day << "/" << para.month << "/" << para.year << ")" << endl;
}
//597: Số thứ tự ngày trong năm
int OrderOfDay(date para)
{
	int sum = 0;
	int a[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i <= para.month-2; i++)
	{
		if (LeapYear(para.year) && i == 1)
			day[i] += 1;
		sum += day[i];
	}
	sum += para.day;
	return sum;
}
//598: Số thứ tự ngày kể từ 1/1/1
int OrderFromAC(date para)
{
	int sum = 0;
	for (int i = 1; i < para.year; i++)
	{
		if (LeapYear(para.year))
			sum += 366;
		else sum += 365;
	}
	sum+=OrderOfDay(para);
	return sum;
}

//Hàm tính số ngày trong tháng
int AmountOfDay(int year,int month)
{
	int day;
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		{day = 31; break; }

		case 4:case 6:case 9:case 11:
		{day = 30; break; }
		default: 
		{
				if (LeapYear(year))
				{
					day = 29; break;
				}
				else
				{
					day = 28; break;
				}
		}
	}
	return day;
}
//599: Tìm ngày khi biết năm và số thứ tự ngày trong năm
date FindDate(int year, int order)
{
	int limit_day;
	int count = 0;
	date result;
	for (int month = 1; month < 12; month++)
	{
		limit_day = AmountOfDay(year, month);
		for (int day = 1; day <= limit_day; day++)
		{
			count += 1;
			if (count == order)
			{
				result.day = day; result.month = month; result.year = year;
				return result;
			}
		}
	}
}

//600: Tìm ngày khi biết số thứ tự từ ngày 1/1/1
date FindDateFromAC(int order)
{
	int count1 = 0;
	int count2 = 0;
	date result;
	for (int year = 1; year < 2021; year++)
	{
		if (LeapYear(year))
		{
			count1 += 366; count2 = count1 + 365;
		}
		else {
			if (LeapYear(year + 1)) {
				count1 += 365; count2 = count1 + 366;
			}
			else {
				count1 += 365; count2 = count1 + 365;
			}
		}
		if (count1<order && count2>order)
		{
			result = FindDate(year, order - count1);
			result.year = year;
			return result;
		}
	}
}

//601: Tìm ngày kế tiếp
date FindNextDate(date para)
{
	date result = para;
	if (LeapYear(result.year) == false && result.day > 28 && result.month == 2)
		return result;
	switch (result.month)
	{
	case 1:case 3:case 5:case 7:case 8: case 10: case 12:
		if (result.day == 31)
		{
			if (result.month == 12)
				return { 1,1,result.year + 1 };
			return { 1,result.month + 1,result.year };
		}
		else return { result.day + 1,result.month,result.year };
	case 4:case 6: case 9: case 11:
		if (result.day == 30)
			return { 1,result.month + 1,result.year };
		else return { result.day + 1,result.month,result.year };
	default: 
		if (LeapYear(result.year))
		{
			if (result.day == 28)
				return { 29,2,result.year };
			else if (result.day == 29)
				return { 1,3,result.year };
		}
		else {
			if (result.day == 28)
				return{ 1,3,result.year };
		}
		return { result.day + 1,result.month,result.year };
	}
}
//602: Tìm ngày hôm qua
date FindPreDate(date para)
{
	date result = para;
	if (LeapYear(result.year) == false && result.day > 28 && result.month == 2)
		return result;
	switch (result.month)
	{
	case 1:case 2:case 4:case 6:case 9:case 8:case 11:
		if (result.day == 1) {
			if (result.month == 1)
				return { 31,12,result.year - 1 };
			return { 31,result.month - 1 ,result.year };
		}
		else return { result.day -1,result.month,result.year };
	case 5: case 7:case 10: case 12:
		if (result.day == 1)
			return { 30,result.month - 1,result.year };
		else return { result.day - 1,result.month,result.year };
	default: 
		if (result.day == 1)
		{
			if (LeapYear(result.year))
				return { 29,2,result.year };
			else return { 28,2,result.year };
		}
		return { result.day - 1,result.month,result.year };
	}
}

//603: Tìm ngày kế đó k ngày
date FindNext_k(date para, int k)
{
	
	for (int i = 1; i <= k; i++)
	{
		int limit_day = AmountOfDay(para.year, para.month);
		
		if (para.day == limit_day)
		{
			if (para.month == 12)
			{
				para.day = 1, para.month = 1; para.year += 1;
			}
			else { para.day = 1; para.month += 1; }
		}
		else 
			para.day += 1;
	}
	return para;
}

//604: Tìm ngày trước đó k ngày
date FindPre_k(date para, int k)
{
	for (int i = 1; i <= k; i++)
	{
		int limit_day = AmountOfDay(para.year, para.month-1);
		if (para.day == 1)
		{
			if (para.month == 1)
			{
				para.day = 31; para.month = 12; para.year -= 1;
			}
			else { para.day = limit_day; para.month -= 1; }
		}
		else para.day -= 1;
	}
	return para;
}
int DayOfYear(int year)
{
	if (LeapYear(year))
		return 366;
	return 365;
}

//So sánh hai năm tìm ra một cặp gồm năm lớn và năm nhỏ
coudate CompareYear(date year1, date year2)
{
	date small = year1;
	date big = year2;
	if (big.year < small.year)
	{
		int temp = small.year; small.year = big.year; big.year = temp;
	}
	return {small,big };
}
//605: Khoảng cách giữa hai ngày
int DistanceTwoDay(date para1, date para2)
{
	coudate D =  CompareYear(para1, para2);
	int count = 1;
	int limit_day = AmountOfDay(D.small.year, D.small.month);
	for (int i = 1;; i++)
	{
		
		if (D.small.day == limit_day)
		{
			if (D.small.month == 12)
			{
				D.small.day = 1; D.small.month = 1; D.small.year += 1;
				
			}
			else
				D.small.day = 1; D.small.month += 1;
		}
		else
			D.small.day++;
		count++;
		if (D.small.day == D.big.day && D.small.month == D.big.month && D.small.year == D.big.year)
			return count;
	}
}

//606: So sánh hai ngày
coudate CompareDate(date para1, date para2)
{
	if (para1.year > para2.year)
		return { para2,para1 };
	else if (para1.year == para2.year)
	{
		if (para1.month > para2.month)
			return { para2,para1 };
		else if (para1.month == para2.month)
		{
			if (para1.day > para2.day)
				return { para2,para1 };
			else 
				return { para1,para2 };
		}
		else return { para1,para2 };
	}
	else
		return { para1,para2 };
}


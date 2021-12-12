#pragma once
#include <iostream>
#include<cmath>
#include<sstream>
using namespace std;
#define size 14
#define SIZE 3
struct coordinate {
	int x;
	int y;
};
typedef struct coordinate XY;
//Utilization
int GCD(int a, int b);
bool divisor(int n, int b);
bool Elementary(int n);
bool divisor(int n, int i);
bool SquareNumber(int n);
bool Perfect_Number(int n);
int Reverse(int number);
int AmountofNumber(int n);
void Sort_Ascending_int(int a[size * size], int end);
void Sort_Descending_int(int a[size * size], int end);
void Out2D(int a[size][size]);
void Out2D_double(double a[size][size]);
int _Max2D_(int a[size][size]);
int _Min2D_(int a[size][size]);
void swap_lines(int a[size][size], int l1, int l2);
void swap_columns(int a[size][size], int c1, int c2);
void swapping_int(int& a, int& b);
//429 - 437
void _429_432_(int a[size][size]);
bool _434_(int a[size][size]);
int _435_(int a[size][size]);
int _436_(int a[size][size]);
void _437_(int a[size][size]);
//438 - 442
int _438_(int a[size][size]);
int _439_(int a[size][size]);
int _440_(int a[size][size]);
int _441_(int a[size][size]);
int _442_(int a[size][size]);
//443 - 449
int _443_(int a[size][size]);
int _444_(int a[size][size]);
int _445_(int a[size][size]);
int _446_(int a[size][size]);
int _447_(int a[size][size]);
void _448_(int a[size][size]);
//450 - 468
int _450_(int a[size][size]);
int _451_(int a[size][size]);
int _452_(int a[size][size]);
int _453_(int a[size][size]);
int _454_(int a[size][size]);
int _455_(int a[size][size]);
bool _456_(int a[size][size]);
bool _457_(int a[size][size]);
bool _458_(int a[size][size]);
bool _459_(int a[size][size]);
//460 - 468
void _460_(int a[size][size]);
void _461_(int a[size][size]);
void _464_(int a[size][size]);
void _465_(int a[size][size]);
void _466_(int a[size][size]);
void _467_(int a[size][size]);
void _468_();
//469 - 474
void _ADD2Dto2D_(int a[size][size], int b[size][size]);
void _MINUS2Dfor2D_(int a[size][size], int b[size][size]);
void _471_(int a[size][size], int b[size][size]);
void _474a_();
void _474b_();
void Siamese(int a[size][size]);




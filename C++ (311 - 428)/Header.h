#pragma once
#include <iostream>
#include<cmath>
using namespace std;
#define size 5
#define SIZE 3
//Utilization
int GCD(int a, int b);
bool divisor(int n, int b);
void swapping(double& a, double& b);
void Sort_Ascending(double b[size], int n);
void Sort_Ascending2D(double b[size][size], int row, int col);
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

void swap_lines(int a[size][size], int l1, int l2);

//315-319
double _315_(double b[size][size], int row, int col);
bool _316_(int a[size][size], int row, int col);
int _317_(int a[size][size], int row, int col);
int _318_(double a[size][size], int row, int col);
//320 - 333
double _320_(double a[size][size], int row, int col);
int _321_(int a[size][size], int row, int col);
void _322_(double a[size][size], int row, int col);
void _323_(double a[size][size], int row, int col);
void _324_(double a[size][size], int row, int col);
void _325_(int a[size][size], int row, int col);
void _325_(int a[size][size], int row, int col);
double _326_(double a[size][size], int row, int col);
int _327_(int a[size][size], int row, int col);
double _328_(double a[size][size], int row, int col);
void _329_(double a[size][size], int row, int col);
void _330_(double a[size][size], int row, int col);
void _332_(int a[size][size], int row, int col);
int _333_(int a[size][size], int row, int col);
//334 - 347
int _334_(double a[size][size], int row, int col);
int _335_(int a[size][size], int row, int col);
int _336_(double a[size][size], int row, int col);
int _337_(int a[size][size], int row, int col);
void _338_(double a[size][size], int row, int col);
void _339_(int a[size][size], int row, int col);
void _340_(double a[size][size], int row, int col);
int _341_(double a[size][size], int row, int col);
void _342_343_345_(double a[size][size], int row, int col);
int _344_(double a[size][size], int row, int col);
int _346_(double a[size][size], int row, int col);
int _347_(double a[size][size],int row,int col);
//348 - 365
bool _348_(double a[size][size]);
bool _349_(double a[size][size]);
bool _350_(int a[size][size]);
bool _351_(int a[size][size]);
bool _352_(int a[size][size]);
bool _353_(int a[size][size]);
bool _354_(int a[size][size]);
void _355_(double a[size][size]);
void _356_(int a[size][size]);
void _357_(int a[size][size]);
void _358_(int a[size][size]);
void _359_(double a[size][size]);
void _360_(int a[size][size]);
void _361_(int a[size][size]);
void _362_(int a[size][size]);
void _363_(int a[size][size]);
bool _AinB_(int a[size][size], int b[size + 1][size + 1]);
int _365_(int a[size][size], int b[size + 1][size + 1]);
//366 - 391
bool _366_(int a[size][size]);
int _Max2D_(int a[size][size]);
int _368_(int a[size][size]);
bool _369_(int a[size][size]);
int _370_(int a[size][size]);
void _371_(int a[size][size]);
void _372_(int a[size][size]);
void _373_(int a[size][size]);
bool _374_(int a[size][size]);
int _375_(int a[size][size]);
int _376_(int a[size][size]);
int _377_(int a[size][size]);
int _378_(int a[size][size]);
int _379_(int a[size][size]);
int _380_(int a[size][size]);
void _381_(int a[size][size]);
int _382_(int a[size][size]);
int _383_(int a[size][size]);
void _384_(int a[size][size]);
void _385_(int a[size][size]);
void _386_(int a[size][size]);
void _387_388_389_(int a[size][size]);
void _390_(int a[size][size]);
void _391_(int a[size][size]);
void SelectMatrix(int a[size][size], int x, int y, int list[size * size * size]);
void Sub2DArray(int a[size][size], int x, int y, int end, int list[size * size * size]);
void SubSub2DArray(int a[size][size], int x, int y, int sum_hori, int sum_verti, int end, int list[(size * size * size)]);
int Summer(int a[size][size], int x, int y, int constant, char sign, int end);
bool Duplicate(int a[(size * size * size)], int end, int check);
void swapping_int(int& a, int& b); void Sort_391_(int a[size * size * size]);
//Bài 392 - 406
void _392_(int a[size][size]);
void _393_(int a[size][size]);
void _394_(int a[size][size]);
void _395_(int a[size][size]);
void _396_(int a[size][size]);
void _397_(int a[size][size]);
void _398_(int a[size][size]);
void _399_(int a[size][size]);
void _400_(int a[size][size]);
void _401_(int a[size][size]);
void _402_(int a[size][size]);
void _403_(int a[size][size]);
void _404_(int a[size][size]);
void _405_(int a[size][size]);
void _406_(int a[size][size]);
//Bài 407 - 415
void _407_(int a[size][size]);
void _408_(int a[size][size]);
void _409_(int a[size][size]);
void _410_(int a[size][size]);
void _411_(int a[size][size]);
void _412_(int a[size][size]);
bool Sort_DAscending_int(int sub[size * size]);
void _413_(int a[size][size]);
void _414_(int a[size][size]);
void _415a_(int a[size][size]);
void _415b_(int a[size][size]);
//Bài 416 - 428
void _416_417_a_(int a[size][size]);
void _416_417_b_(int a[size][size]);
void _418_419_(int a[size][size]);
void _420_421_(int a[size][size]);
void _422_(int a[size][size]);
void _423_(int a[size][size]);
void _424_(int a[size][size]);
void _425_(int a[size][size]);
void _427_(int a[size][size]);
void _428_(int a[size][size]);

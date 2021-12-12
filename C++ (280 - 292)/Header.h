#pragma once
#include <iostream>
#include <Windows.h>
#include <cmath>
using namespace std;
#define size 50
//Utilization
void swapping(int &a, int &b);
void Reverse_arr(int a[size], int n);
void Out_arr(int a[size], int n);
void Out_arr_double(double b[size], int n);
bool positive_arr(int a[size], int start, int end);
int max_arr(int a[size], int n);

//Mảng con
bool find_arr(int a[size], int start, int end, int target);
int sum_arr(int a[size], int start, int end);
void subArray(int a[size], int n);
bool Increasing_gradu(int a[size], int start, int end);
bool Increasing(int a[size], int start, int end);
bool Decreasing(int a[size], int start, int end);
bool a_in_b(int a[size], int b[size], int size_a, int size_b);
void Out_arr_range(int a[size], int start, int end);


//284 - 292
void _284_(int a[size], int n);
void _285_(int a[size], int n);
void _286_(int a[size], int n);
void _287_(int a[size], int n);
void _288_(int a[size], int n);
void _289_(int a[size], int n);
void _290_(int a[size], int n);
void _291_(int a[size], int n);
void _292_(double a[size], int n);

//293 - 310
void _294_(int a[size], int n);
void _295_(int a[size], int n);
void _296_(int a[size], int n);
void _297_(int a[size], int n);
void _298_(int a[size], int n);
void _299_(int a[size], int n);
void _300_(int a[size], int n);
int _302_(int a[size], int b[size], int size_a, int size_b);
void _303_(int a[size], int n);
void _304_(int a[size], int n);
void _305_(int a[size], int n);
void _306_(int a[size], int n);
void _307_(int a[size], int n);
void _308_(int a[size], int n);
void _309_(int a[size], int n);
void _310_(int a[size], int n);



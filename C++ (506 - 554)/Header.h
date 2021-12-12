#pragma once
#include "NewType.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

#define size 14
#define SIZE 3
//Utilization
int GCD(int a, int b);
bool divisor(int n, int b);
bool Elementary(int n);
bool divisor(int n, int i);
bool SquareNumber(int n);
bool Perfect_Number(int n);
int Reverse(int number);
int AmountofNumber(int n);
void swapping(double& a, double& b);
/*Đa thức*/
void Arrange(poli& para);
void MonoInPoli(poli& result);
string Poli(poli para);
string Convert(double para);
poli Input_poli(poli& para);
poli Output_poli(poli para);
poli InfIntegral(poli para);
double DefIntegral(poli para, double upper, double lower);
double Poli_at_x(poli para, double x);

/*Oxy*/
double VectorModule(xy A, xy B);
bool DuplicateXY(xy A, xy B);

//Customize
int Count_after_point(double n);
/* Convertion */
int DecimalToInt(double n, int& count);
double FracToDouble(frac para);
double IntToDecimal(int n,int count);
/* Function */
double GCD_double(double a, double b);

//Bài 506 - 521
//Rút gọn phân số
frac Simpler(frac para);
frac Input();
void Output(frac para);
//Kiểm tra phân số tối giản
bool Simplest(frac para);
//Quy đồng
void SameDeno(frac& para1, frac& para2);
//Kiểm tra dấu phân số
bool SignFraction(frac para);
//So sánh phân số
int CompareFraction(frac para1, frac para2);

//Bài 522 - 531
mix Input_mix();
void Output_mix(mix para);
mix Simpler_mix(mix para);
frac MixToFrac(mix para);
bool Simplest_mix(mix para);
void SameDeno_mix(mix para1, mix para2);

//532 - 539
com Input_com();
void Output_com(com para);
string ComtoString(com para);

//540 - 554
xy Input_xy();
string XyToString(xy para);
void Output_xy(xy para);
double Distance_Ox(xy para1, xy para2);
double Distance_Oy(xy para1, xy para2);
xy Symmetry_xy(xy para);
xy Symmetry_Ox(xy para);
xy Symmetry_Oy(xy para);
xy Symmetry_Y_X_(xy para);
xy Symmetry_Y__X_(xy para);







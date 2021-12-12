#pragma once
#include <iostream>
#include<cmath>
#include<sstream>
#include "NewType.h"
#include<sstream>
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
double VectorModule(xy A, xy B);
bool DuplicateXY(xy A, xy B);
void swapping(double& a, double& b);
//475 - 485
void Fraction();
void MixedNumber();
xy Point();
void Point3D();
void _479();
bool DuplicateXY(xy a, xy b);
void _480_I(P &poli);
void _480_O(P poli);
void _481_I(date& time);
void _481_O(date time);
void _482_I(line& para);
void _482_O(line para);
void Cal_Circle(cir& para); 
void Cal_Triangle(tri& para);
cir Circle(cir& para);

//486 - 492
void _486(mono para1, mono para2);
void _488(mono para1, mono para2); 
void _489(mono para1);
void _490(mono para1);
mono _DerivativeMono(mono para1);
//493 - 505
poli Input(poli& para);
poli Output(poli para);
poli Derive(poli para);
poli Derive_k(poli para);
double Poli_at_x(poli para, double x);
double Poli_root(poli para);

#pragma once
#include "NewType.h"
#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
using namespace std;

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
string Convert(double para);
void Arrange(poli& para);
void MonoInPoli(poli& result);
string Poli(poli para);
poli Input_poli(poli& para);
poli Output_poli(poli para);
double Poli_at_x(poli para, double x);

//Customize
int Count_after_point(double n);

//Point in Oxy
xy Input_xy();
string XyToString(xy para);
void Output_xy(xy para);

//Point in Oxyz
xyz Input_xyz();
void Output_xyz(xyz para);
double VectorModule3D(xyz para1, xyz para2);
double Distance3D_X(xyz para1, xyz para2);
double Distance3D_Y(xyz para1, xyz para2);
double Distance3D_Z(xyz para1, xyz para2);
xyz SymmetryO(xyz para);
xyz SymmetryOxy(xyz para);
xyz SymmetryOxz(xyz para);
xyz SymmetryOyz(xyz para);

//Circle
cir Input_cir();
void Output_cir(cir para);
double P_Circle(cir para);
double S_Circle(cir para);
int CirclePosition(cir para1, cir para2);
bool PointInCircle(cir para, xy point);
double DuplicateSurface(cir para1, cir para2);
coucir CircleInCircle(cir para1, cir para2);

//Sphere
sph Input_sph();
void Output_sph(sph para);
double S_Sphere(sph para);
double V_Sphere(sph para);
int SpherePosition(sph para1, sph para2);
bool PointInSphere(sph para, xyz point);

//Triangle
void Output_tri(tri para);
tri Input_tri();
bool CheckTriangle(tri para);
double S_Triangle(tri para);
xy CenterTriangle(tri para);
xy Tri_Max_x(tri para);
xy Tri_Min_y(tri para);
poli StraightEquation(xy a, xy b);
bool PointOnLine(poli para, xy point);
bool PointOnTriangle(tri para, xy point);
bool PointInTriangle(tri para, xy point);
int TriangleTypes(tri para);

//Date
date Input_date();
void Output_date(date para);
int OrderOfDay(date para);
int OrderFromAC(date para);
date FindDate(int year, int order);
date FindDateFromAC(int order);
date FindNextDate(date para);
date FindPreDate(date para);
date FindNext_k(date para, int k);
date FindPre_k(date para, int k);
int DistanceTwoDay(date para1, date para2);
coudate CompareDate(date para1, date para2);















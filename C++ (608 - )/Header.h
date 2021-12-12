#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
struct Oxy{
    float x,y;
};

void enter_oxy_array(Oxy *&arr, int &n);
void display_oxy_array(Oxy *arr, int n);
int count_pos_x(Oxy *arr, int n);
int count_not_duplicated(Oxy *arr, int n);
Oxy find_max_y(Oxy *arr, int n);
Oxy find_near_O(Oxy *arr, int n);
Oxy find_far_O(Oxy *arr, int n);
Oxy *find_near_point(Oxy *arr, int n);
Oxy *find_far_point(Oxy *arr, int n);
Oxy *independent_triganle(Oxy *arr, int n);
#include "Header.h"
int main()
{
    Oxy *arr;
    int n=0;
    enter_oxy_array(arr,n);
    // display_oxy_array(arr,n);
    // cout << count_pos_x(arr,n)<<endl;
    // cout <<count_not_duplicated(arr,n)<<endl;
    // find_max_y(arr,n);
    // find_near_O(arr,n);
    // find_far_O(arr,n);
    // display_oxy_array(find_near_point(arr,n),n);
    // display_oxy_array(find_far_point(arr,n),n);
    display_oxy_array(independent_triganle(arr,n),n);
    system("pause");
    return 0;
}
#include "Header.h"
void enter_oxy_array(Oxy* &arr,int &n)
{
    cout<<"Nhap so luong phan tu thuc: ";
    cin>>n;
    arr = new Oxy[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Nhap phan tu ["<<i<<"]: "<<endl;
        cin>>arr[i].x>>arr[i].y;
    }
}
void display_oxy_array(Oxy* arr,int n)
{
    cout<<"---Xuat mang cac diem OXY---"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Phan tu ["<<i<<"]: ("<<arr[i].x<<";"<<arr[i].y<<")"<<endl;
    }
}
int count_pos_x(Oxy* arr,int n)
{
    cout<<"So phan tu co hoanh do duong: ";
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].x > 0)
            count+=1;
    }
    return count;
}
bool operator==(Oxy a, Oxy b)
{
    if(a.x == b.x && a.y == b.y)
        return true;
    return false;
}
int count_not_duplicated(Oxy* arr,int n)
{
    cout<<"Number of unique point: ";
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int iterrate = 0;
        for(int j=0;j<n;j++)
        {
            if(arr[i] == arr[j])
                iterrate += 1;
        }
        if(iterrate <=1)
            count+=1;
    }
    return count;
}
Oxy find_max_y(Oxy* arr,int n)
{
    cout<<"Point has maximum y: ";
    int max = arr[0].y;
    Oxy maxima;
    for(int i=0;i<n;i++)
    {
        if(arr[i].y > max){
            max = arr[i].y;
            maxima = arr[i];
        }
    }
    cout<<maxima.x<<";"<<maxima.y<<endl;
    return maxima;
}
float distance_fromO(Oxy point)
{
    return sqrt(pow(point.x,2) + pow(point.y,2));
}
Oxy find_near_O(Oxy* arr,int n)
{
    cout<<"Point has nearest distance to O: ";
    float min = distance_fromO(arr[0]);
    Oxy nearest = arr[0];
    for(int i=0;i<n;i++)
    {
        float distance = distance_fromO(arr[i]);
        if(distance < min)
        {
            min = distance;
            nearest = arr[i];
        }
    }
    cout<<nearest.x<<";"<<nearest.y<<endl;
    return nearest;
}
Oxy find_far_O(Oxy* arr,int n)
{
    cout<<"Point has farest distance from O: ";
    float max  = distance_fromO(arr[0]);
    Oxy farest = arr[0];
    for(int i=0;i<n;i++)
    {
        
        float distance = distance_fromO(arr[i]);
        if (distance > max)
        {
            max = distance;
            farest = arr[i];
        }
    }
    cout<<farest.x<<";"<<farest.y<<endl;
    return farest;
}
float distance_between_2point(Oxy a, Oxy b)
{
    return sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2));
}
Oxy* find_near_point(Oxy* arr,int n)
{
    cout<<"Nearest pair of point: ";
    float min = distance_between_2point(arr[0],arr[1]);
    Oxy* pair = new Oxy[2];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            float distance = distance_between_2point(arr[i],arr[j]);
            int k=0;
            if(distance<min && distance!=0)
            {
                min = distance;
                pair[k++] = arr[i];
                pair[k] = arr[j];
            }
        }
    }
    return pair;
}
Oxy* find_far_point(Oxy* arr,int n)
{
    cout<<"Farest pair of point: "<<endl;
    float max = distance_between_2point(arr[0],arr[1]);
    Oxy* pair = new Oxy[2];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            float distance = distance_between_2point(arr[i],arr[j]);
            int k=0;
            if(distance>max && distance!=0)
            {
                max = distance;
                pair[k++] = arr[i];
                pair[k] = arr[j];
            }
        }
    }
    return pair;
}
bool check_triangle(Oxy triangle[3])
{
    float AB = distance_between_2point(triangle[0],triangle[1]);
    float BC = distance_between_2point(triangle[1],triangle[2]);
    float AC = distance_between_2point(triangle[0],triangle[2]);
    if(AC >= (AB + BC) || BC >= (AB + AC) || AB >= (BC + AC))
        return false;
    return true;
}
Oxy* independent_triganle(Oxy* arr,int n)
{
    cout<<"Independent Triganle from n points is: "<<endl;
    Oxy* triangle = new Oxy[3];
    Oxy* first_second = find_near_point(arr,n);
    triangle[0] = first_second[0];
    triangle[1] = first_second[1];

    float min = 10000;
    for(int i=0;i<n;i++)
    {
        float distance1 = distance_between_2point(triangle[0],arr[i]);
        float distance2 = distance_between_2point(triangle[1],arr[i]);

        if(distance1 + distance2 < min && distance1 !=0 && distance2 !=0)
        {
            if(check_triangle(triangle))
            {
                min = distance1 +distance2;
                triangle[2] = arr[i];
            }
        }
    }
    return triangle;
}

//!Not Finished Yet, Key word is ConvexHull
vector<Oxy> convex_polygon(Oxy* arr,int n)
{
    vector <Oxy> convex;
    return convex;
}


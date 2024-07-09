// Online C++ compiler to run C++ program online
#include <iostream>
namespace DynamicAlloc{
    int ** create2DArray(int row , int col)
    {
        int**arr_str=new int*[row];
        for(int i=0 ; i<row ; i++)
        {
            arr_str[i]=new int[col];
        }
        return arr_str;
    }
    void Delete2DArray(int** arr_str, int row , int col)
    {
        for(int i=0 ; i < col ; i++)
        {
            delete[]arr_str[i];
        }
        delete[]arr_str;
    }
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    int arr1[]={1,1,1};
    int arr2[]={2,2,2};
    int arr3[]={3,3,3};
    int *arr[3]={arr1,arr2,arr3};
    int ** p=DynamicAlloc::create2DArray(3,3);

    return 0;
}

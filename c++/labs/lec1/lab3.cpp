#include <stdio.h>
#include <stdlib.h>
typedef int* (*CallbackFunc)(int** arr_2d, int arr_size, int* row_sizes, int (*func)(int*, int));


int * func2 (int ** arr_2d , int arr_size, int* row_sizes, int (func)(int, int) )
{
    int * res=(int*)malloc(arr_size * sizeof(int));
    for(int i=0 ; i< arr_size ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            res[i]=res[i] + func(arr_2d[i][j],2);
        }
    }
    return res;
}
int sum (int x , int y)
{
    return x+y;
}
int mul (int x , int y)
{
    return x*y;
}
int main() {
    int raw1 [3]={1,1,1};
    int raw2[3]={2,2,2};
    int *arr[2]={raw1,raw2};
    int (*func)(int,int)=sum;
    int * res = func2(arr,2,arr[2],func);
    
    
    return 0;
}

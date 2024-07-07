// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
void swap(int * x, int*y)
{
    int temp = *x;
    *x=*y;
    *y=temp;
}
namespace MathFunctions {
    void print_square(double num)
    {
        double res = std :: sqrt(num);
        std::cout<<"the square root of " << num<< " is "<<res<<std::endl;
    }
}
namespace StringFunctions{
    void print_string(char* name)
    {
        for(int i=0 ; name[i] ; i++)
        {
          
            if (name[i]>='A' && name[i]<='Z')
            {
               name[i]=(char)tolower(name[i]); 
            }
        }
        for(int i=0 ; name[i] ; i++)
        {
            std::cout<<name[i]<<" " ;
        }
        std::cout<<std::endl;
    }
}
namespace ArrayFunctions{
    void print_rev(int *arr ,int size )
    {
        for(int i=0, j=size-1; i< size/2;i++, j--)
        {
            swap(&arr[i],&arr[j]);
        }
        for(int i=0 ; i<size ; i++)
        {
            std::cout<<arr[i];
        }
        std::cout<<std::endl;
    }
}
int main() {
    // Write C++ code here
    //std::cout << "Try programiz.pro";
    char str[]="yasMen";
    int arr[5]={1,2,3,4,5};
    MathFunctions ::print_square(81);
    StringFunctions::print_string(str);
    ArrayFunctions::print_rev(arr,5);
    return 0;
}
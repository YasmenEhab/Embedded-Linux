// Online C++ compiler to run C++ program online
#include <iostream>
int binary_search (int *arr, int size, int num )
{
    int f=0;
    int l=size;
    int middle;
    int index=-1;
    int i=0;
    while(f<=l)
    {
        middle = (f+l)/2;
        if(arr[middle]>num)
        {
            l=middle-1;
        }
        else if(arr[middle]<num)
        {
            f=middle+1;
        }
        else //(middle == num)
        {
            index=i;
            break;
        }
        i++;
    }
    printf("%d",index);
    return index;
}
int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 7;
    int result = binary_search(arr, size, num);

    return 0;
}

#include <iostream>
#include <cstring>
#include <cstdlib>  

using namespace std;
typedef struct {
    int *array;
    int size;
    int capacity;
}dynamicArr;
void init_arr(dynamicArr * arr, int initSize)
{
    arr->array =(int*)malloc(initSize * sizeof(int));
    arr->capacity=initSize;
    arr->size=initSize;
}
void insert(dynamicArr * arr, int size,int position , int element_val)
{
    if(arr->size == arr->capacity)
    {
        arr->size = arr->size *2; 
    }
    arr->array= (dynamicArr*)realloc(arr->array,arr->size*sizeof(dynamicArr));
    for(int i=0 ; i<;i++)
    {

    }
    
}


int main() {
    // Write C code here
    //std::cout << "hello\n";
    dynamicArr arr;
    init_arr(&arr ,5);
    for(int i=0 ;i<5 ; i++)
    {
        arr.array[i]=i;
        //printf("%d",arr.array[i]);
    }
    return 0;
}
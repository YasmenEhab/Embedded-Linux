// Online C++ compiler to run C++ program online
#include <iostream>
class DynamicArray {
  private:
    int *arr;
    int capacity;
    int current_size;
  
  public:
    DynamicArray()
    {
        arr = new int [5];
        capacity = 5;
        current_size = 0;
            
    }
    DynamicArray(int s)
    {
        arr = new int [s];
        capacity = s;
        current_size = 0;
        
    }
    DynamicArray(int s , int * arr_values)
    {
        arr = new int [s];
        capacity = s;
        current_size = 0;
        for(int i=0 ; i<s ; i++)
        {
            arr[i]=arr_values[i];
        }
    }
    DynamicArray(const DynamicArray& cp_arr)
    {
        arr=new int [cp_arr.capacity];
        capacity=cp_arr.capacity;
        current_size=cp_arr.current_size;
        for(int i=0 ; i<cp_arr.capacity ; i++)
        {
            arr[i]=cp_arr.arr[i];
        }
    }
    ~DynamicArray()
    {
        delete[]arr;
    }
    int getSize()
    {
        return current_size;
        
    }  
    void print()
    {
        for(int i=0 ; i< current_size; i++)
        {
            std::cout<<arr[i]<<<< " ";
        }
        std::cout<<std::endl;
    }
     void pushback(int value)
     {
         if(current_size == capacity)
         {
             resize();
         }
         arr[current_size]=value;
     }
     int popback()
     {
         res=-1;
         if(current_size>0)
         {
             res=arr[size-1];
         }
         return res;
     }
    void resize()
    {
        int * temp = new int [capacity *2];
        for(int i=0 ; i<current_size ; i++)
        {
            temp[i]=arr[i];
        }
        delete[]arr;
        arr=temp;
        capacity=capacity*2;
        
    }
    
     void removeAt(int index)
     {
         if(index >= 0 && index<size)
         {
            for(int i=index ; i  ; i) 
            {
                arr[i] = arr[i + 1];
            }
            size--; 
         }
      
     }   
     void insertAt(int index, int value)
     {
         if(index >= 0 && index < size)
        {
            if(current_size == capacity)
            {
                resize();
            }
            for(int i=current_size ; i<index ; i--)
            {
                arr[i]=arr[i-1];
            }
            arr[index]=value;
            current_size++;
        }
     
     }
};
int main() {
   

    return 0;
}
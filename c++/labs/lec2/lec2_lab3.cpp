// Online C++ compiler to run C++ program online
#include <iostream>
#include <utility>
namespace ArrayPair {
    std :: pair<int, int>* createArray(int size)
    {
        std::pair<int,int>*ptr=new std::pair<int , int>[size];
        return ptr;
    }
    void delete_array(std::pair<int,int>*ptr)
    {
        delete[]ptr;
    }
    void setpair(std::pair<int,int>*ptr, int fr , int sec ,int index)
    {
        ptr[index].first=fr;
        ptr[index].second=sec;
    }
    std :: pair<int, int> getpair(std :: pair<int, int>*ptr,int index)
    {
        
        return ptr[index];
    }
    void printArray(std::pair<int,int>*ptr , int size)
    {
        for(int i=0 ; i<size ; i++)
        {
            std::cout << "Pair " << i << ": (" << ptr[i].first << ", " << ptr[i].second << ")\n";
        }
    }
}
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}

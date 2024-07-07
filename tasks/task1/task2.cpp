// Online C++ compiler to run C++ program online
#include <iostream>

int main() {
    // Write C++ code here
    int sec ;
    int hr;
    int min;
    std::cout << "enter the input sec :"<<std::endl;
    std::cin >> sec;
    hr = sec /3600;
    sec = sec%3600;
    min = sec/60;
    sec =sec%60;
    std::cout<<"H:M:S - "<<hr<<":"<<min<<":"<<sec<<std::endl;
    
    
    
    

    return 0;
}
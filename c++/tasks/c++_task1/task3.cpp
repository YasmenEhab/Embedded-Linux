// Online C++ compiler to run C++ program online
#include <iostream>
#include <math.h>

int main() {
    char str[5];
    int dec=0;
    int bin=0;
    char str2[5];
    //div=0;
    //rem=0;
    int index=0;
    std::cout << "Enter a binary number : "<<std::endl;
    std::cin >> str;
    for(int i=0 ; i< 4 ; i++)
    {
        if(str[i]=='1')
        {
            dec=dec+ pow(2,3-i);
        }
    }
    std::cout << "the binary number is : "<<dec<<std::endl;
    std::cout << "Enter a dec number : "<<std::endl;
    std::cin >> dec;
    while(dec)
    {
       
        str2[index++] = (dec % 2 == 0 ? '0' : '1');
        dec /= 2;
    }
    for(int i=0 ; i< 4 ; i++)
    {
        std::cout<<str2[i];
    }
    
    
    
    

    return 0;
}
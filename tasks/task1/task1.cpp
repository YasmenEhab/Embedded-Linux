
#include <iostream>

int main() {
    int input;
    int result=0;
    int flag=0;
    std::cout << "please enter number"<<std::endl;
    while(flag==0)
    {
    std::cin>>input;
    if(input !=0)
    {
        result=result+input;
         std::cout <<"enter a new number : "<<std::endl;
    }
    else
    {
        std::cout <<"the result is : "<<result<<std::endl;
        flag=1;
    }
    }


    return 0;
}
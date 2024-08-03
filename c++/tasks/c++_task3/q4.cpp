int func (int num)
{
    int rem=0;
    for(int i=0 ; num >0 ; i++)
            {
            rem=rem + (num%10);
            num=num/10;
            }
            return rem;
}

class Solution {
public:
    // int addDigits(int num) 
    // {
    //     int res = func(num);
    //     while(res >10)
    //     {
    //         res = func(num);
    //     }
    //     return res;
        
    // }
    int addDigits(int num) {
        if (num == 0) return 0;
        if (num % 9 == 0) return 9;
        return num % 9;
    }
};

class Solution
{
public:
    int addDigits(int num)
    {
        while (num >= 10)
        {
            int new_num = 0;
            while (num > 0)
            {
                new_num += num % 10;
                num /= 10;
            }
            num = new_num;
        }

        return num;
    }
};

int main()
{
    Solution sol;
    int result = sol.addDigits(38);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

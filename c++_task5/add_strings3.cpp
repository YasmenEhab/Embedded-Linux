class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        if (num1[0] == '0' && num2[0] == '0')
        {
            return "0";
        }
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int a = num1.size();
        int b = num2.size();
        int c = abs(a - b);
        if (a > b)
        {
            while (c--)
            {
                num2.push_back('0');
            }
        }
        else if (a < b)
        {
            while (c--)
            {
                num1.push_back('0');
            }
        }

        int carry = 0;
        string ans = "";
        for (int i = 0; i < num1.size(); i++)
        {
            int d = num1[i] - 48;
            int e = num2[i] - 48;
            int sum = d + e + carry;
            if (sum < 10)
            {
                ans.push_back(sum + '0');
                carry = 0;
            }
            else
            {
                int f = sum % 10;
                ans.push_back(f + '0');
                carry = 1;
            }
        }
        if (carry == 1)
        {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
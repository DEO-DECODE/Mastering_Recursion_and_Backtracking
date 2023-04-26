#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
    for (int i = 1; i < n - 1; ++i)
    {
        string str1 = num.substr(0, i);
        if (str1.size() > 1 && str1[0] == '0')
            break;
        for (int j = i + 1; j < n; ++j)
        {
            string str2 = num.substr(i, j - i);
            if (str2.size() > 1 && str2[0] == '0')
                break;
            long long num1 = stoll(str1);
            long long num2 = stoll(str2);
            long long next = stoll(str1) + stoll(str2);
            string combinedString = str1 + str2 + to_string(next);
            while (combinedString.size() < num.size())
            {
                num1 = num2; // ll
                num2 = next; // ll
                next = num1 + num2;
                combinedString += to_string(next);
            }
            if (combinedString == num)
                return true;
        }
    }
    return false;
    }
};

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
       vector<string> ans;
    for (int hr = 0; hr < 12; ++hr)
    {
        for (int min = 0; min < 60; ++min)
        {
            if (__builtin_popcount(hr) + __builtin_popcount(min) == turnedOn)
            {
                string minString = "";
                if (min < 10)
                {
                    minString += "0";
                }
                minString += to_string(min);
                ans.push_back(to_string(hr) + ":" + minString);
            }
        }
    }
    return ans;
    }
};

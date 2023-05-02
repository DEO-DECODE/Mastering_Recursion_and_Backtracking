#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestNumber(string pattern) {
        int num = 1;
        stack<int> st;

        if(pattern.back() == 'I') pattern += 'I';
        else pattern += 'D';
        vector<string> res(pattern.size());

        for(int i=0; i<pattern.size(); i++){
            if(pattern[i]== 'D'){
                st.push(i);
            }
            else if(st.empty() && pattern[i]== 'I'){
                res[i]= to_string(num);
                num++;
            }
            else{
                res[i]= to_string(num);
                num++;
                while(!st.empty()){
                    int idx= st.top();
                    st.pop();
                    res[idx]= to_string(num);
                    num++;
                }
            }
        }


        while(!st.empty()){
            int idx= st.top();
            st.pop();
            res[idx]= to_string(num);
            num++;
        }

        string ans= "";
        for(int i=0; i<res.size(); i++){
            ans += res[i];
        }

        return ans;
    }
};

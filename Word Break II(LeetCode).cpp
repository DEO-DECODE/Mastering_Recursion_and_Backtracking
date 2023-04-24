#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 unordered_set<int> visited;
    vector<vector<int>> answers; // store all answers here (indices to add spaces)


    void helper(const string& s, vector<string>& wordDict, vector<int>& currInds) {

        int s_top = currInds.back();

        for (const auto word:wordDict){
            if (!word.compare(s.substr(s_top, word.size() ))){
                if (s_top+word.size() == s.size()) {
                    answers.push_back(currInds);
                } else {
                    currInds.push_back(s_top+word.size());
                    helper(s, wordDict, currInds);
                    currInds.pop_back(); // backtrack
                }
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        vector<int> currInds = {0};

        helper(s, wordDict, currInds);

        vector<string> ret;
        for (const auto ans:answers){
            // add spaces and push answer to vector
            // ignore leading 0
            string scopy = s;

            for (int i=ans.size()-1;i>0;i--){
                scopy.insert(ans[i], " ");
            }

            ret.push_back(scopy);
        }

        return ret;
    }
};

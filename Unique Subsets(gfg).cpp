class Solution
{
    public:
    //Function to find all possible unique subsets.
 void subsetsproblem(int pos, int j , vector<int>& org , set<vector<int>> &ans, vector<int> &present){
    if(pos==j){
        // sort(present.begin(), present.end());
        vector<int> vec=present;
        sort(vec.begin(), vec.end());
        ans.insert(vec);
        return;
    }
    // cout<<1<<" ";
    // for(int i=pos; i<org.size(); i++){
        // present.push_back(10);
        subsetsproblem(pos+1,j,org,ans,present);
        // present.pop_back();
        present.push_back(org[pos]);
        subsetsproblem(pos+1,j,org,ans,present);
        present.pop_back();
    // }
}
    vector<vector<int> > AllSubsets(vector<int> org, int n)
    {
        set<vector<int>> ans;
        vector<int> present;
        subsetsproblem(0,org.size(),org,ans,present);
        vector<vector<int>> answer;
        for(auto itr= ans.begin(); itr!=ans.end(); ++itr){
            answer.push_back((*itr));
        }
        return answer;
    }
};

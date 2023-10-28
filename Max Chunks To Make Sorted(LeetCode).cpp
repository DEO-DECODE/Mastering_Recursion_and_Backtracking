class Solution {
public:
    int ans = 0;
void func(int ind, vector<vector<int>> &collect, vector<int> &arr)
{
  // Base Case.
  if (ind == arr.size())
  {
    vector<int> checkSort;
    for (auto vec : collect)
    {
      sort(vec.begin(), vec.end());
      for (auto val : vec)
      {
        checkSort.push_back(val);
      }
    }
    vector<int> temp2 = arr;
    sort(temp2.begin(), temp2.end());
    if (temp2 == checkSort)
    {
      int sz = collect.size();
      ans = max(ans, sz);
    }
    return;
  }
  for (int i = ind; i < arr.size(); ++i)
  {
    vector<int> temp;
    for (int x = ind; x <= i; ++x)
    {
      temp.push_back(arr[x]);
    }
    collect.push_back(temp);
    func(i + 1, collect, arr);
    collect.pop_back();
  }
}
int maxChunksToSorted(vector<int> &arr)
{
  ans = 0;
  vector<vector<int>> collect;
  vector<int> temp;
  func(0, collect, arr);
  return ans;
}
};

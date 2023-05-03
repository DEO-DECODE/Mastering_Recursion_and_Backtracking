/*You are required to complete this method */

class Solution
{
    public:
    int ans;
    int recursion(int n, int k){
    // cout<<"\n"<<nxt<<" "<<sze<<" "<<swrd<<endl;
    if(n==1) return 0;
    int x= recursion(n-1,k);
    int y=(x+k)%n;
    return y;
}
    int josephus(int n, int k)
    {
       //Your code here
      ans =recursion(n,k);
      return ans+1;
    }
};

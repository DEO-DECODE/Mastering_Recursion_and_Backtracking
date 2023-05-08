//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    void dfs(vector<int> &vis, int &count, vector<int> adj[], int vertex, int N, bool &isHamiltonian)
{
    vis[vertex] = 1;
    count++;
    if (count == N)
    {
        isHamiltonian = true;
        return;
    }
    for (auto child : adj[vertex])
    {
        if (vis[child])
            continue;
        else
        {
            dfs(vis, count, adj, child, N, isHamiltonian);
        }
    }
    count--;
    vis[vertex] = 0;
}
    bool check(int N, int M, vector<vector<int>> Edges)
    {
        vector<int> adj[N+1];
        for (auto edge : Edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int i = 1; i <= N; ++i)
        {
            bool isHamiltonian = false;
            int count = 0;
            vector<int> vis(N+1, 0);
            dfs(vis, count, adj, i, N, isHamiltonian);
            if (isHamiltonian)
            {
                return true;
            }
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends

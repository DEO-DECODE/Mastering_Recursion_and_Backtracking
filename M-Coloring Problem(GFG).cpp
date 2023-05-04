//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    bool isSafe(vector<int> &colors, int vertex, int col, bool graph[101][101], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i== vertex)
				continue;
			if (graph[i][vertex] == 0)
				continue;
			if (colors[i] == col)
				return false;
		}
		return true;
	}
	bool isPossible(int vertex, bool graph[101][101], int m, int n, vector<int> &colors)
	{
		if (vertex == n)
		{
			return true;
		}
		for (int i = 1; i <= m; ++i)
		{
			if (isSafe(colors, vertex, i, graph, n))
			{
				colors[vertex] = i;
				if (isPossible(vertex + 1, graph, m, n, colors))
				{
					return true;
				}
				colors[vertex]=0;
			}
		}
		return false;
	}
	bool graphColoring(bool graph[101][101], int m, int n)
	{
		// your code here
		vector<int> colors(n, 0);
		return isPossible(0, graph, m, n, colors);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

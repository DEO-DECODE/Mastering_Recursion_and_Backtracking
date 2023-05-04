// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
void dfs(int i, int j, int initialcolor, int newcolor, vector<vector<int>>& image){
    int n=image.size();
    int m=image[0].size();
    if(i<0||j<0)
    return;
    if(i>=n||j>=m){
        // cout<<i<<" "<<j<<" "<<m<<" "<<n<<endl;
    return;
    }
    if(image[i][j]!=initialcolor)
    return;
    image[i][j]=newcolor;
    dfs(i-1,j,initialcolor,newcolor,image);
    dfs(i+1,j,initialcolor,newcolor,image);
    dfs(i,j-1,initialcolor,newcolor,image);
    dfs(i,j+1,initialcolor,newcolor,image);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
         int incolor=image[sr][sc];
        if(incolor!=newColor){
            dfs(sr,sc,incolor,newColor,image);
            
        }
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends

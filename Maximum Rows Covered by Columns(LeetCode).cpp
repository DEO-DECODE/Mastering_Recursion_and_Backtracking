class Solution {
public:
    int ans,rows,cols;
    void f(vector<vector<int>>& matrix, int numSelect, int i, vector<int> &vis)
    {
        if(numSelect==0)
        {
            int count=0;
            for(int x=0; x<rows; x++)
            {
                int f=1;
                for(int y=0; y<cols; y++)
                {
                    if(vis[y]) continue;
                    if(matrix[x][y])
                    {
                        f=0;
                        break;
                    }
                }
                if(f) count++;
            }
            ans=max(ans,count);
            return;
        }
        if(i==cols) return;
        vis[i]=1;
        f(matrix,numSelect-1,i+1,vis);
        vis[i]=0;
        f(matrix,numSelect,i+1,vis);
    }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) 
    {
        ans=0;
        rows=matrix.size(), cols=matrix[0].size();
        if(numSelect>=cols) return rows;
        vector<int> vis(cols,0);
        f(matrix,numSelect,0,vis);
        return ans;
    }
};

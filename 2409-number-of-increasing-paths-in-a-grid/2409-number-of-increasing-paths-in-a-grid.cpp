class Solution {
public:
    int N=1e9+7;
    int f(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
        int di[]={0,1,0,-1};
        int dj[]={1,0,-1,0};
        int take=1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k=0;k<4;k++){
            int x=i+di[k];
            int y=j+dj[k];
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]>grid[i][j]){
                take=(take+f(x,y,n,m,grid,dp))%N;
            }
        }
        return dp[i][j]=take;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int val=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                val=(val+f(i,j,n,m,grid,dp))%N;
            }
        }
        return val%N;
    }
};
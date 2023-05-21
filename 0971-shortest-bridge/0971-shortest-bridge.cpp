class Solution {
public:
    void dfs(int i, int j, int n, vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<int,int>> &q){
        int di[]={1,0,-1,0};
        int dj[]={0,1,0,-1};
        vis[i][j]=1;
        q.push({i,j});
        for(int k=0;k<4;k++){
            int nexti=i+di[k];
            int nextj=j+dj[k];
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && grid[nexti][nextj]==1 && vis[nexti][nextj]==0){
                dfs(nexti,nextj,n,grid,vis,q);
            }
        }

    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        int find=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0 && !find){
                    dfs(i,j,n,grid,vis,q);
                    find=1;
                }
            }
            if(find==1){
                break;
            }
        }
            int ans=0;
            find=0;
            while(!q.empty()){
                int m=q.size();
                for(int i=0;i<m;i++){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    int di[]={1,0,-1,0};
                    int dj[]={0,1,0,-1};
                    for(int k=0;k<4;k++){
                        int nexti=x+di[k];
                        int nextj=y+dj[k];
                        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && grid[nexti][nextj]==0 && vis[nexti][nextj]==0){
                            vis[nexti][nextj]=1;
                            q.push({nexti,nextj});
                        }
                        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && grid[nexti][nextj]==1 && vis[nexti][nextj]==0){
                            find=1;
                        }
                    }
                }
                if(find==1){
                    break;
                }
                ans++;
            }
        return ans;
    }
};
class Solution {
public:
    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis, int &count){
        count++;
        vis[i]=1;
        for(auto j:adj[i]){
            if(!vis[j]){
                dfs(j,adj,vis,count);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                float dist=sqrt(pow(bombs[j][1]-bombs[i][1],2)+pow(bombs[j][0]-bombs[i][0],2));
                if(dist<=(float)bombs[i][2]){
                    adj[i].push_back(j);
                }
                if(dist<=(float)bombs[j][2]){
                    adj[j].push_back(i);
                }
            }
        }
        int maxi=0;
        for(int j=0;j<n;j++){
            vector<int> vis(n,0);
            int count=1;
            dfs(j,adj,vis,count);
            maxi=max(maxi,count-1);
        }
        return maxi;
    }
};
class Solution {
public:
    int maxi=0;
    void dfs(int i,vector<vector<int>> &adj,vector<int>& iT,vector<int> &vis,int count){
        vis[i]=1;
        maxi=max(count,maxi);
        for(auto j:adj[i]){
            if(!vis[j]){
                dfs(j,adj,iT,vis,count+iT[j]);
            }
        }        
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);

            }
        }
        vector<int> vis(n,0);
        dfs(headID,adj,informTime,vis,informTime[headID]);
        return maxi;

    }
};
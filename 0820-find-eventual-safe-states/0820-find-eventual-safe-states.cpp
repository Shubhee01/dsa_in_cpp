class Solution {
public:
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& vis, vector<int> &pvis){
        vis[i]=1;
        pvis[i]=1;
        for(auto j:adj[i]){
            if(vis[j]==0){
                if(dfs(j,adj,vis,pvis)){
                    return true;
                }
            }else if(pvis[j]==1){
                return true;
            }
        }
        pvis[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> pvis(n,0);
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            if(!dfs(i,graph,vis,pvis)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
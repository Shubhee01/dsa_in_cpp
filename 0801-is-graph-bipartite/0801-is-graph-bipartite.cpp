class Solution {
public:
    bool dfs(int i,  vector<int> &color, vector<vector<int>>& adj){
        for(auto j:adj[i]){
            if(color[j]==-1){
                color[j]=1-color[i];
                if(dfs(j,color,adj)){
                    return true;
                }
            }
            if(color[i]==color[j]){
                return true;
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=1;
                if(dfs(i,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};
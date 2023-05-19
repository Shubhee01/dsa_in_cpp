class Solution {
public:
    bool ans(int node,vector<vector<int>> &graph,vector<int> &color){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto i:graph[x]){
                if(color[i]==-1){
                    color[i]=1-color[x];
                    q.push(i);
                }else if(color[i]==color[x]){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!ans(i,graph,color)){
                   return false; 
                }    
            }
            
        }
        return true;
    }
};
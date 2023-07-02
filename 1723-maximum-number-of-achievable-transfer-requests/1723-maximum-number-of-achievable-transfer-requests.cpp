class Solution {
public:
    int ans=-1e9;
    void f(int i, vector<int> &vis, vector<vector<int>>& req, int count){
        if(i==req.size()){
            for(auto j:vis){
                if(j!=0){
                    return;
                }
            }
            ans=max(ans,count);
            return;
        }
        vis[req[i][0]]--;
        vis[req[i][1]]++;
        f(i+1,vis,req,count+1);
        vis[req[i][0]]++;
        vis[req[i][1]]--;
        f(i+1,vis,req,count);
    }
    int maximumRequests(int n, vector<vector<int>>& req) {
        vector<int> vis(n,0);
        f(0,vis,req,0);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>> v;
        map<int,vector<int>> m;
        int n=g.size();
        for(int i=0;i<n;i++){
            m[g[i]].push_back(i);
            if(m[g[i]].size()==g[i]){
                v.push_back(m[g[i]]);
                m[g[i]].clear();
            }
        }
        return v;
    }
};
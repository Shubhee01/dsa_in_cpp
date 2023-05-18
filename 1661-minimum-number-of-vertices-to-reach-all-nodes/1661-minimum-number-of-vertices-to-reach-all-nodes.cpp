class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> count(n,0);
        for(int i=0;i<edges.size();i++){
            count[edges[i][1]]++;
        }
        vector<int> ans;
        for(int i=0;i<count.size();i++){
            if(count[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
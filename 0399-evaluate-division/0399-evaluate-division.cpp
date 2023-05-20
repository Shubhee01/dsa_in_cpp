class Solution {
public:
    double ans1=-1;
    void f(string k,string x,map<string,vector<pair<string,double>>> adj,map<string,int> &m,double ans){
        if(k==x && adj[k].size()>0){
            ans1=ans;
            return;
        }
        m[k]=1;
        for(auto i:adj[k]){
            if(m[i.first]==0){
                f(i.first,x,adj,m,i.second*ans);
            }
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {
        map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<values.size();i++){
            adj[eq[i][0]].push_back({eq[i][1],values[i]});
            adj[eq[i][1]].push_back({eq[i][0],1/values[i]});
        }
        vector<double> v;
        for(int i=0;i<queries.size();i++){
            map<string,int> m;
            ans1=-1;
            f(queries[i][0],queries[i][1],adj,m,1.00);
            v.push_back(ans1);
        }
        return v;
    }
};
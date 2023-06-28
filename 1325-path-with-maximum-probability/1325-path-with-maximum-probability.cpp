#include <bits/stdc++.h>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& suc, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],suc[i]});
            adj[edges[i][1]].push_back({edges[i][0],suc[i]});
        }
        vector<double> dis(n,0);
        priority_queue <pair<double,int>> q;
        dis[start]=1;
        q.push({1,start});
        double ans=0;
        while(!q.empty()){
            auto x=q.top();
            q.pop();
            // cout<<x.first<<" "<<x.second<<endl;
            for(auto i:adj[x.second]){
                if(dis[i.first]<x.first*i.second){
                    // cout<<i.first<<" "<<i.second<<endl;
                    dis[i.first]=x.first*i.second;
                    // cout<<dis[i.first]<<endl;
                    q.push({dis[i.first],i.first});
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<dis[i]<<endl;
        // }
        ans=dis[end];
        return ans;
    }
};
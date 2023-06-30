class Solution {
public:
    bool isposs(int row, int col, vector<vector<int>> adj){
        queue<pair<int,int>> q;
        for(int i=0;i<col;i++){
            if(adj[0][i]==0){
                q.push({0,i});
                adj[0][i]=1;
            }
        }
        while(!q.empty()){
                auto x=q.front();
                q.pop();
                if(x.first==row-1){
                    return true;
                }
                int di[]={0,-1,0,1};
                int dj[]={-1,0,1,0};
                for(int a=0;a<4;a++){
                    int xi=x.first+di[a];
                    int yi=x.second+dj[a];
                    if(xi>=0 && yi>=0 && xi<row && yi<col && adj[xi][yi]==0){
                        q.push({xi,yi});
                        adj[xi][yi]=1;
                    }
                }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low=0;
        int high=cells.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            vector<vector<int>> adj(row,vector<int>(col,0));
            for(int i=0;i<=mid;i++){
                adj[cells[i][0]-1][cells[i][1]-1]=1;
            }
            bool val=false;
            val=isposs(row,col,adj);
            if(val){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};
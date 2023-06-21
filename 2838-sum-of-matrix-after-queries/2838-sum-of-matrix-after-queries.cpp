class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int m=n;
        int a=n;
        int b=m;
        long long sum=0;
        map<int,int> mc;
        map<int,int> mr;
        for(int i=queries.size()-1;i>=0;i--){
            if(mc.size()==n && mr.size()==m){
                break;
            }
            int index=queries[i][1];
            int val=queries[i][2];
            int type=queries[i][0];
            if(type==1 && mc.find(index)==mc.end()){
                sum+=(a*val);
                b--;
                mc[index]=1;
            }else if(type==0 && mr.find(index)==mr.end()){
                sum+=(b*val);
                a--;
                mr[index]=1;
            }
        }
        return sum;
    }
};
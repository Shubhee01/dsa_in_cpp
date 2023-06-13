class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<int,string> mr;
        map<int,string> mc;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+=to_string(grid[i][j]);
                s+="-";
            }
            mr[i]=s;
        }
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+=to_string(grid[j][i]);
                s+="-";
            }
            mc[i]=s;
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mc[i]==mr[j]){
                    count++;
                }
            }
        }
        return count;
    }
};
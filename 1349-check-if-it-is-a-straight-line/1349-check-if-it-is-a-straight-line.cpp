class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        float m1=float(v[1][1]-v[0][1])/float(v[1][0]-v[0][0]);
        if(n<=2){
            return true;
        }else{
            for(int i=2;i<n;i++){
                float m2=float(v[i][1]-v[0][1])/float(v[i][0]-v[0][0]);
                // cout<<m1<<" "<<m2<<endl;
                if(m2!=m1){
                    return false;
                }
            }
        }
        return true;
        
    }
};
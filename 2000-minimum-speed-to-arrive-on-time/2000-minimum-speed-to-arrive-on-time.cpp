class Solution {
public:
    double isava(double mid, vector<int>& dist){
        double sum=0;
        int n=dist.size();
        for(int i=0;i<n;i++){
            if(i==n-1){
                sum+=(dist[i])/mid;
                // cout<<sum<<endl;
            }else{
                sum+=ceil((dist[i])/mid);
            }
        }
        return sum;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        // int sum=0;
        // for(int i=0;i<n;i++){
        //     sum+=dist[i];
        // }
        double low=1;
        double high=1e9;
        int ans=-1;
        while(low<=high){
            double mid=(int)(high+low)/2;
            // cout<<mid<<" "<<isava(mid,dist)<<endl;
            if(isava(mid,dist)<=hour){
                ans=mid;
                // cout<<mid<<" "<<isava(mid,dist)<<endl;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

class Solution {
private:
    bool isPossible(vector<int>& bat, long long time, int n){
        long long total = 0;
        int s = bat.size();
        for(int i=0; i<s; i++){
            total += min(time,1LL*bat[i]);
        }
        return total >= time * n;
    }
public:
    long long maxRunTime(int n, vector<int>& batteries) {

        int bat = batteries.size();

        long long low = batteries[0];
        long long high = 0;

        for(int i=0; i<bat; i++){
            high += batteries[i];
            low = min(low,1LL * batteries[i]);
        }

        long long ans = low;

        while(low <= high){
            long long mid = (low + high) >> 1;

            if(isPossible(batteries,mid,n)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            
        }
        return ans;
    }
};
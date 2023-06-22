class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<long long>left(n);
        vector<long long>right(n);
        
        stack<pair<int,int>> stk1;
        stack<pair<int,int>> stk2;
        
        for(int i=0; i<n; i++){
            int cnt = 0;
            while(!stk1.empty() && stk1.top().first >= arr[i]){
                cnt+=stk1.top().second+1;
                stk1.pop();
            }
            stk1.push({arr[i],cnt});
            left[i] = cnt;
        }
        
        for(int i=n-1; i>=0; i--){
            int cnt = 0;
            while(!stk2.empty() && stk2.top().first > arr[i]){
                cnt+=stk2.top().second+1;
                stk2.pop();
            }
            stk2.push({arr[i],cnt});
            right[i] = cnt;
        }
        int mod=1000000007;
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += (arr[i]*((left[i]+1)*(right[i]+1)))%mod;
            
        }
        return sum%mod;
        
    }
};
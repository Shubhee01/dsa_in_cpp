class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long int s = 1;
        long long int e = maxSum;
        long long int mid;
        long long int ans;
        while(s<=e)
        {
            mid = ((e+s)/2);
            long long temp = mid;
            long long int res=0;

            if(mid>index)res+=((mid+(mid-index))*(index+1))/2;
            else res+=((mid*(mid+1))/2)+(index-mid+1);

            if(mid>(n-1-index))res+=((mid+(mid-(n-1-index)))*(n-index))/2;
            else res+=((mid*(mid+1))/2)+(n-index-mid);

            res-=mid;

            if(res>maxSum)
            {
                e=mid-1;
            }
            else
            {
                ans=mid;
                s=mid+1;
            }
        }
        return ans;
    }
};
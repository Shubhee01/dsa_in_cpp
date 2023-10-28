class Solution {
public:
    int minimumSum(vector<int>& arr) {
        int mini=1e9;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(arr[i]<arr[j] && arr[j]>arr[k]){
                        mini=min(mini,(arr[i]+arr[j]+arr[k]));
                    }
                }
            }
        } 
        if(mini==1e9){
            return -1;
        }
        return mini;
    }
};
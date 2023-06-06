class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff=abs(arr[1]-arr[0]);
        if(arr.size()<=2){
            return true;
        }else{
            for(int i=2;i<arr.size();i++){
                if(abs(arr[i]-arr[i-1])!=diff){
                    return false;
                }
            }
        }
        return true;
    }
};
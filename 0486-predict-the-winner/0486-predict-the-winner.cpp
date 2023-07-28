class Solution {
public:
    int f(int i, int j, bool turn, vector<int>& nums){
        if(i>j){
            return 0;
        }
        if(turn){
            return max(nums[i]+f(i+1,j,!turn,nums),nums[j]+f(i,j-1,!turn,nums));
        }
        return min(f(i+1,j,!turn,nums),f(i,j-1,!turn,nums));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int pscore=f(0,n-1,true,nums);
        return pscore>=(total-pscore);
    }
};
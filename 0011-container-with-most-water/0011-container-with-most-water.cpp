class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int area=0;
        int maxi=0;
        while(left<=right){
            area=min(height[left],height[right])*(right-left);
            // cout<<right<<" "<<left<<" "<<area<<endl;
            maxi=max(maxi,area);
            if(height[left]<=height[right]){
                left++;
            }else if(height[left]>height[right]){
                right--;
            }
        }
        return maxi;
    }
};
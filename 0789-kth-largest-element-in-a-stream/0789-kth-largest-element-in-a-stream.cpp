class KthLargest {
public:
    int lar=-1;
    priority_queue<int,vector<int>, greater<int>> q;
    KthLargest(int k, vector<int>& nums) {
        lar=k;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(q.size()<k){
                q.push(nums[i]);
            }else{
                if(nums[i]>q.top()){
                    q.pop();
                    q.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        int ans;
        if(q.size()<lar){
                q.push(val);
        }else{
            if(val>q.top()){
                q.pop();
                q.push(val);
            }
        }
        if(q.size()<lar){
            ans=-1;
        }else{
            ans=q.top();
        }
        return ans;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
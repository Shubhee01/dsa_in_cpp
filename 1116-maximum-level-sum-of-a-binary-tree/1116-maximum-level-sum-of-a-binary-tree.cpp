/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int maxi=-1e9;
        int ans=1;
        while(!q.empty()){
            level++;
            int n=q.size();
            int val=0;
            for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                val+=x->val;
                if(x->left!=NULL){
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    q.push(x->right);
                }
            }
            if(val>maxi){
                // cout<<level<<" "<<val<<endl;
                maxi=val;
                ans=level;
            }
        }
        return ans;
    }
};
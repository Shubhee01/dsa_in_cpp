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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        if(root==NULL){
            return v;
        }
        while(!q.empty()){
            int n=q.size();
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* x=q.front();
                maxi=max(maxi,x->val);
                q.pop();
                if(x->left!=NULL){
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    q.push(x->right);
                }
            }
            v.push_back(maxi);
        }
        return v;
    }
};
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
    void fn(TreeNode* root, int &dif, int &prev){
        if(root==NULL){
            return;
        }
        fn(root->left,dif,prev);
        if(prev!=-1){
            dif=min(dif,abs(root->val-prev));
        }
        prev=root->val;
        fn(root->right,dif,prev);
    }
    int getMinimumDifference(TreeNode* root) {
        int dif=1e9;
        int prev=-1;
        fn(root,dif,prev);
        return dif;
    }
};
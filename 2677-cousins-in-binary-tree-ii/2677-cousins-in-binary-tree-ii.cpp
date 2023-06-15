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
    void dfs(TreeNode* &root, int level, map<int,int> &m ,int par){
        if(root==NULL){
            return;
        }
        int par1=0;
        int par2=0;
        root->val=m[level]-(root->val)-par;
        if(root->right!=NULL){
            par1=root->right->val;
        }
        if(root->left!=NULL){
            par2=root->left->val;
        }
        dfs(root->left,level+1,m,par1);
        dfs(root->right,level+1,m,par2);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        map<int,int> m;
        int level=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int total=0;
            for(int i=0;i<n;i++){
                auto x=q.front();
                q.pop();
                total+=x->val;
                if(x->left!=NULL){
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    q.push(x->right);
                }
            }
            m[level]=total;
            level++;
        }
        root->val=0;
        int p1=0;
        int p2=0;
        if(root->left!=NULL){
            p1=root->left->val;
        }
        if(root->right!=NULL){
            p2=root->right->val;
        }
        dfs(root->left,1,m,p2);
        dfs(root->right,1,m,p1);
        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL){
                    m[temp->left]=temp;
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    m[temp->right]=temp;
                    q.push(temp->right);
                }
            }
        }
        queue<TreeNode*> q2;
        vector<TreeNode*> vis;
        q2.push(target);
        int level=0;
        while(!q2.empty() && level<k){
            int n=q2.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q2.front();
                q2.pop();
                vis.push_back(temp);
                if(m.find(temp)!=m.end() && find(vis.begin(),vis.end(),m[temp])==vis.end()){
                    q2.push(m[temp]);
                }
                if(temp->left!=NULL && find(vis.begin(),vis.end(),temp->left)==vis.end()){
                    q2.push(temp->left);
                }
                if(temp->right!=NULL && find(vis.begin(),vis.end(),temp->right)==vis.end()){
                    q2.push(temp->right);
                }
            }
            level++;
        }
        while(!q2.empty()){
            ans.push_back(q2.front()->val);
            q2.pop();
        }
        return ans;
    }
};
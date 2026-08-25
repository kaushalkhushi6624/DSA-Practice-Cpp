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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            
            // check if left child exists
            if(node->left){
                // if left child is a leaf → add its value
                if(!node->left->left && !node->left->right){
                    ans += node->left->val;
                }
                q.push(node->left);
            }
            
            // push right child if exists
            if(node->right){
                q.push(node->right);
            }
        }
        return ans;
    }
};

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q; 
        q.push({root, 0}); 
        
        while(!q.empty()){
            int size = q.size();
            long long left = q.front().second;   // first index at this level
            long long right = q.back().second;   // last index at this level
            ans = max(ans, right - left + 1);
            
            for(int i=0; i<size; i++){
                auto node = q.front(); q.pop();
                long long idx = node.second - left; // normalize to avoid overflow
                
                if(node.first->left) 
                    q.push({node.first->left, 2*idx});
                if(node.first->right) 
                    q.push({node.first->right, 2*idx + 1});
            }
        }
        return (int)ans;
    }
};

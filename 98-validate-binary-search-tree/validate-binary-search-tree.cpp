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
private:
    bool validate(TreeNode* root,long minval,long maxval){
        if(!root)  return true;
        if(minval<root->val && root->val<maxval){
             return validate(root->left,minval,root->val) && validate(root->right,root->val,maxval);
            
            
        }else{
            return false;
        }
        return true;

    }    
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN,LONG_MAX);
        
    }
};
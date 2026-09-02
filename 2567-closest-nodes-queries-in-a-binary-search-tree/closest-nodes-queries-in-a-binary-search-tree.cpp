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
    void inorder(TreeNode* root, vector<int> &arr){
        if(!root) return;
    
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }    
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> arr;
        inorder(root,arr);
        vector<vector<int>>  ans;

        for (int q : queries) {
            int floorVal = -1, ceilVal = -1;

            // Ceil → first element >= q
            auto it = lower_bound(arr.begin(), arr.end(), q);
            if (it != arr.end()) ceilVal = *it;

            // Floor → largest element <= q
            auto it2 = upper_bound(arr.begin(), arr.end(), q);
            if (it2 != arr.begin()) floorVal = *(--it2);

            ans.push_back({floorVal, ceilVal});
        }return ans;   
    }
};
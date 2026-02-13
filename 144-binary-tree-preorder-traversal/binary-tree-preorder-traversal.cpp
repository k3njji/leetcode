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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(root, arr);
        return arr;
    }

private:
    void preorder(TreeNode* curr, vector<int>& arr){
        if(!curr){
            return;
        }

        arr.push_back(curr->val);
        preorder(curr->left, arr);
        preorder(curr->right, arr);
    }
};
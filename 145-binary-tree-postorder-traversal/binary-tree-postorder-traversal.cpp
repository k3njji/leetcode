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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        postorder(root, arr);
        return arr;
    }

private:
    void postorder(TreeNode* curr, vector<int>& arr){
        if(!curr){
            return;
        }

        postorder(curr->left, arr);
        postorder(curr->right, arr);
        arr.push_back(curr->val);

    }
};
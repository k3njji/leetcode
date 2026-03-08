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
    TreeNode* convertBST(TreeNode* root) {
        int count = 0;
        traverse(root, count);

        return root;
    }

private:
    void traverse(TreeNode* curr, int& count){
        if(!curr){
            return;
        }

        traverse(curr->right, count);
        count+=curr->val;
        curr->val = count;
        traverse(curr->left, count);
    }
};
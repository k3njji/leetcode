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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MAX;

        traverse(root, ans, 1);

        return ans;
    }

private:
    void traverse(TreeNode* curr, int& ans, int level){
        if(!curr){
            return;
        }
        if(!curr->left && !curr->right){
            if(ans > level){
                ans = level;
            }
        }

        traverse(curr->left, ans, level+1);
        traverse(curr->right, ans, level+1);
    }
};
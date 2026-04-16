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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        traverse(root, ans, 0);

        return ans;
    }

private:
    void traverse(TreeNode* curr, vector<int>& ans, int level){
        if(!curr){
            return;
        }

        if(ans.size() <= level){
            ans.push_back(curr->val);
        }

        if(ans[level] < curr->val){
            ans[level] = curr->val;
        }

        traverse(curr->left, ans, level+1);
        traverse(curr->right, ans, level+1);
    }
};
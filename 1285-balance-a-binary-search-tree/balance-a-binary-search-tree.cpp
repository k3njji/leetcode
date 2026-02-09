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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        Traverse(root, ans);
        return make(ans, 0, ans.size()-1);
    }

private:
    TreeNode* make(vector<int>& ans, int l, int r){
        if(l > r) return nullptr;
        int mid = (l + r)/2;
        TreeNode* node = new TreeNode(ans[mid]);
        node->left = make(ans, l, mid-1);
        node->right = make(ans, mid+1, r);
        return node;
    }

    void Traverse(TreeNode* node, vector<int>& ans){
        if(!node) return;
        Traverse(node->left, ans);
        ans.push_back(node->val);
        Traverse(node->right, ans);
    }
};
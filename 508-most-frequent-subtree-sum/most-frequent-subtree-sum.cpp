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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> save;
        checkpoint(root, save);

        int maxFreq = 0;
        for(auto& [sum, count] : save){
            maxFreq = max(maxFreq, count);
        }

        vector<int> ans;
        for (auto& [sum, count] : save) {
            if (count == maxFreq) {
                ans.push_back(sum);
            }
        }

        return ans;
    }

private:
    void checkpoint(TreeNode* curr, unordered_map<int, int>& save){
        if(!curr){
            return;
        }
        int sum = 0;
        traverse(curr, sum);

        save[sum]++;
        // ans.push_back(sum);
        checkpoint(curr->left, save);
        checkpoint(curr->right, save);
    }

    void traverse(TreeNode* curr, int& sum){
        if(!curr){
            return;
        }

        sum += curr->val;

        traverse(curr->left, sum);
        traverse(curr->right, sum);
    }
};
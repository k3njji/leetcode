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
    int sumRootToLeaf(TreeNode* root) {

        vector<string> safe;

        dfsSave(root, safe, "");

        int ans = 0;

        for(int i = 0; i < safe.size(); i++){
            ans += binaryToDecimal(safe[i]);
        }

        return ans;
    }

private:

    int binaryToDecimal(const string& s){

        int dec_value = 0;
        int base = 1;

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '1'){
                dec_value += base;
            }
            base *= 2;
        }

        return dec_value;
    }

    void dfsSave(TreeNode* curr, vector<string>& safe, string temp){

        if(!curr){
            return;
        }

        temp.push_back(curr->val + '0');

        if(!curr->left && !curr->right){
            safe.push_back(temp);
            return;
        }

        dfsSave(curr->left, safe, temp);
        dfsSave(curr->right, safe, temp);
    }
};
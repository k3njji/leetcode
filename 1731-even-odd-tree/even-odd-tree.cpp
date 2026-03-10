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
    bool isEvenOddTree(TreeNode* root) {
        vector<vector<int>> arr;
        Traverse(root, 0, arr);

        for(int i = 0; i < arr.size(); i++){
            if(i%2 == 0){
                for(int j = 0; j < arr[i].size(); j++){
                    if(arr[i][j]%2 == 0){
                        return false;
                    }

                    if(j < arr[i].size()-1 && arr[i][j] >= arr[i][j+1]){
                        return false;
                    }
                }
            }else{
                // for(int  = 0; j < arr[i].size(); j++){
                    for(int j = 0; j < arr[i].size(); j++){
                        if(arr[i][j]%2 == 1){
                            return false;
                        }

                        if(j < arr[i].size()-1 && arr[i][j] <= arr[i][j+1]){
                            return false;
                        }
                // }
                }
            }
        }

        return true;
    }

private:
    void Traverse(TreeNode* curr, int level, vector<vector<int>>& arr){
        if(!curr){
            return;
        }

        if(arr.size() <= level){
            arr.push_back({});
        }

        arr[level].push_back(curr->val);

        Traverse(curr->left, level+1, arr);
        Traverse(curr->right, level+1, arr);
    }
};
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
    int isHeight(TreeNode* root, bool& isBalanced){
        if(root == NULL || !isBalanced) {
            return 0;
        }

        int left = isHeight(root->left, isBalanced);
        int right = isHeight(root->right, isBalanced);
        if(abs(left - right) > 1 && isBalanced) isBalanced = false;
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool isB = true;

        isHeight(root, isB);

        return isB;
    }
};

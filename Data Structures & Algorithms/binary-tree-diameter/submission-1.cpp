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
    int diameter(TreeNode* root, int& maxD){
        if(root == NULL) 
            return 0;

        int left = diameter(root->left, maxD);
        int right = diameter(root->right, maxD);
        maxD = max(maxD, left + right);
        return max(left,right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        int maxD = 0;

        diameter(root, maxD);

        return maxD;
    }
};

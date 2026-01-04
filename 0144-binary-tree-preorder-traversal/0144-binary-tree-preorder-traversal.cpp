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
    void preorder(TreeNode* node, vector<int> &v) {
        if(node == NULL)
            return;
        v.push_back(node->val);
        preorder(node->left, v);
        preorder(node->right, v);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;

        preorder(root, v);
        return v;
    }
};
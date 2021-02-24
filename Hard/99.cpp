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

    TreeNode* pre = new TreeNode(INT_MIN);
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    void recoverTree(TreeNode* root) {

        visit(root);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;

    }

    void visit(TreeNode* root) {
        if(nullptr == root) {
            return;
        }

        visit(root->left);

        if(nullptr == first && pre->val > root->val) {
            first = pre;
        }

        if(nullptr != first && pre->val > root->val) {
            second = root;
        }
        pre = root;

        visit(root->right);
    }

};

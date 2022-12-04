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
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {

        return validate(root, numeric_limits<double>::infinity() * -1, numeric_limits<double>::infinity());
    }

    bool validate(TreeNode *node, double leftBoundary, double rightBoundary)
    {
        if (!node)
        {
            return true;
        }

        if (!(leftBoundary < node->val && node->val < rightBoundary))
        {
            return false;
        }

        return validate(node->left, leftBoundary, node->val) && validate(node->right, node->val, rightBoundary);
    }
};
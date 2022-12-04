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
    vector<int> nums;
    int kthSmallest(TreeNode *root, int k)
    {

        traverse(root);

        sort(nums.begin(), nums.end());

        return nums[k - 1];
    }

    void traverse(TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        nums.push_back(root->val);

        traverse(root->left);
        traverse(root->right);
    }
};
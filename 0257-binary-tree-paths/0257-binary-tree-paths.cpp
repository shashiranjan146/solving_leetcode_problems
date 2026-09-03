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
    vector<string> ans;
    vector<string> path;
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;

        path.push_back(to_string(root->val));
        if (root->left == nullptr && root->right == nullptr) {
            string temp = "";
            for (int i = 0; i < path.size(); i++) {
                if (i > 0)
                    temp += "->";

                temp += path[i];
            }

            ans.push_back(temp);
        }
        else {
            dfs(root->left);
            dfs(root->right);
        }
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
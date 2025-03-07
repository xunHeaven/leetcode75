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
    void dfs(TreeNode *node,vector<int> &vec)
    {
        if(node->left==nullptr&&node->right==nullptr)
        {
            vec.push_back(node->val);
        }
        else
        {
            if(node->left)
            {
                dfs(node->left,vec);
            }
            if(node->right)
            {
                dfs(node->right,vec);
            }
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1;
        vector<int> vec2;
        dfs(root1,vec1);
        dfs(root2,vec2);
        return vec1==vec2;
    }
};

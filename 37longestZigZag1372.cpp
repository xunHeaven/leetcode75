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
    int max_path;
    void dfs(TreeNode* root,int dir,int len)
    {
        max_path=max(max_path,len);

        if(dir==0)
        {
            if(root->left) dfs(root->left,1,len+1);
            if(root->right)dfs(root->right,0,1);
        }
        else
        {
            if(root->left) dfs(root->left,1,1);
            if(root->right)dfs(root->right,0,len+1);
        }
    }
    int longestZigZag(TreeNode* root) {
        max_path=0;
        dfs(root,0,0);
        dfs(root,1,0);
        return max_path;
    }
};

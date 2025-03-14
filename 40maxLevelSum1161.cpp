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
    vector<int> vec;
    void dfs(TreeNode* node,int level)
    {
        if(!node) return;
        if(level==vec.size())
        {
            vec.emplace_back(node->val);
        }
        else
        {
            vec[level]+=node->val;
        }
        dfs(node->left,level+1);
        dfs(node->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        dfs(root,0);
        int index=0;
        int maxSum=vec[0];
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]>maxSum)
            {
                maxSum=vec[i];
                index=i;
            }
        }
        return index+1;
    }
};

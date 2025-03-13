//题解参考：https://leetcode.cn/problems/count-good-nodes-in-binary-tree/solutions/2399336/tong-ji-er-cha-shu-zhong-hao-jie-dian-de-dqtl
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
    int dfs(TreeNode *root,int path_max)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int res=0;
        if(root->val>=path_max)
        {
            res++;
            path_max=root->val;
        }
        res+=dfs(root->left,path_max)+dfs(root->right,path_max);
        return res;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};

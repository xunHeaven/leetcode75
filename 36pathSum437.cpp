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
    int dfs(TreeNode* root,int targetSum)
    {
        if(!root) return 0;
        int res=0;
        if(root->val==targetSum)
        {
            res++;
        }
        res+=dfs(root->left,targetSum-root->val);
        res+=dfs(root->right,targetSum-root->val);
        return res;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0;
        //计算当前节点为根节点时，该路径下的目标路径和
        int ret=dfs(root,targetSum);
        //分别以每一个节点作为根节点
        ret+=pathSum(root->left,targetSum);
        ret+=pathSum(root->right,targetSum);
        return ret;
    }
};

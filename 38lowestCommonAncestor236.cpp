//解题思路：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solutions/93282/c-jing-dian-di-gui-si-lu-fei-chang-hao-li-jie-shi-
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root==p||root==q) return root;
        TreeNode* myleft=lowestCommonAncestor(root->left,p,q);
        TreeNode* myright=lowestCommonAncestor(root->right,p,q);
        if(myleft&&myright)
        {
            return root;
        }
        if(myleft==NULL)
        {
            return myright;
        }
        if(myright==NULL)
        {
            return myleft;
        }
        return NULL;
    }
};

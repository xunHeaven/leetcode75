//解题思路：https://leetcode.cn/problems/delete-node-in-a-bst/solutions/3068685/shan-chu-er-cha-sou-suo-shu-zhong-de-jie-chd9
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
        }
        else
        {
            //1.是root是叶子节点
            if((!root->left)&&(!root->right))
            {
                delete root;
                return nullptr;
            }
            //2.只有左子树
            else if(!root->right)
            {
                TreeNode* temp=root;
                root=root->left;
                delete temp;
                return root;
            }
            //3.只有右子树
            else if(!root->left)
            {
                TreeNode* temp=root;
                root=root->right;
                delete temp;
                return root;
            }
            //4.拥有左右子树。找到右子树的最左边节点，将root的左子树变成此节点的左子树
            else
            {
                TreeNode* cur=root->right;
                while(cur->left)
                {
                    cur=cur->left;
                }
                cur->left=root->left;
                TreeNode* temp=root;
                root=root->right;
                delete temp;
                return root;

            }
        }
        return root;
    }
};

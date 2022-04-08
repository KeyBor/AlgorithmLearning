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
 /*
 关于这一题，我看到就想到了昨天的最大路径和，昨天的题可能难在理解转化
 今天的这道题，由于想到了昨天的题，思路很快就有了，那不就是左右子树最长的路径和，即经过最多的节点数减去1
 所以求直径，即求路径长度的最大值，等于求路径经过节点数的最大值减一
 再分解就是左子树的最大节点数（最深路径上的节点数）加上右子树的最深路径上的节点数加上根节点减去1
 那么设该子树的根节点为root，其左孩子经过最多的节点数为L，右孩子经过最多的节点数为R
 总最大节点数为 L+R+1
 最后路径就为L + R
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        traverse(root,diameter);
        return diameter;
    }

    int traverse(TreeNode* Node,int &diameter){
        if(Node == nullptr) return 0;
        int left_num = traverse(Node->left,diameter);
        int right_num = traverse(Node->right,diameter);
        diameter = (left_num+right_num)>diameter?(left_num+right_num):diameter;
        return max(left_num,right_num) + 1; //这边可以理解成以该节点为根节点的子树的深度，左右孩子最深的分支加上根节点即当前的最深深度
    }
};
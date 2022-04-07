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

//运用分解问题的思路：
//以二叉树 abc，a 是根结点（递归中的 root），bc 是左右子结点（代表其递归后的最优解）为例。
//对最大路径和来说，对于父节点延伸下来的路径，不能走入左子树又掉头走入右子树，不能两头收益
//可能的路径情况只有三种：
//（1）b + a + c
//（2）b + a + a 的父结点
//（3）c + a + a 的父结点
//其中情况 1，表示如果不联络父结点的情况，或本身是根结点的情况。这种情况是没法递归的，但是结果有可能是全局最大路径和。
//但是由题意可知，最大路径和是可能产生于其中一个子树的，其中子树的最大路径和是包含子树的根节点的,即上述1的情况
//情况 2 和 3，递归时计算 a+b 和 a+c，选择一个更优的方案返回，也就是上面说的递归后的最优解啦。
//另外结点有可能是负值，最大和肯定就要想办法舍弃负值(max(0, x))
//但是上面 3 种情况，无论哪种，a 作为联络点，都不能够舍弃。

public:
    int maxPathSum(TreeNode* root) {
        int max = root->val;
        backtrace(root,max);
        return max;
    }

    int backtrace(TreeNode* root,int& maxNum){
        if(root == nullptr) return 0;
        int left =  max(backtrace(root->left,maxNum),0);
        int right = max(backtrace(root->right,maxNum),0);
        int sum = root->val + left + right;
        maxNum = max(sum,maxNum);
        return max(left+root->val,right+root->val);
    }
};
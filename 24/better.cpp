#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
class Solution
{
public:    
    ///  递归的过程中同步判断平衡性
    bool IsVALWithDepth(TreeNode *root, int *depth)
    {
        if(root == NULL)
        {
            *depth = 0;
            return true;
        }

        int leftDepth, rightDepth;

        bool left = IsVALWithDepth(root->left, &leftDepth);//保存的是当前节点的层数 
        bool right = IsVALWithDepth(root->right, &rightDepth);

        if(left == true && right == true)
        {
            if(fabs(leftDepth - rightDepth) <= 1)
            {
                *depth = max(leftDepth, rightDepth) + 1;

                cout <<"depth = " <<*depth <<endl;

                return true;
            }
        }

        return false;
    }

};

int main( )
{
//     0
//   1   2
// 3   
    TreeNode tree[4];
    
    tree[0].val = 0;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 1;
    tree[1].left = &tree[3];
    tree[1].right = NULL;

    tree[2].val = 2;
    tree[2].left = NULL;
    tree[2].right = NULL;


    tree[3].val = 3;
    tree[3].left = NULL;
    tree[3].right = NULL;
    
    Solution solu;
    int *a; 
    cout <<solu.IsVALWithDepth(tree,a) <<endl;
    
    return 0;
}


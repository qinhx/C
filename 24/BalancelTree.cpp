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
class Solution{
	public:
	int getNodeDepth(TreeNode *node){
		if(node==NULL)
			return 0;
		else{
			int l = getNodeDepth(node->left);
			int r = getNodeDepth(node->right);
			return max(l,r);
		}
	}
	bool IsBalanced_Tree(TreeNode *node){
		if(node ==NULL){
			return true;
		}
		int l = getNodeDepth(node->left);
		int r = getNodeDepth(node->right);
		if(fabs(l-r)<=1){
			return IsBalanced_Tree(node->left)&&IsBalanced_Tree(node->right);
		}else{
			return false;
		}
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
    cout <<solu.IsBalanced_Tree(tree) <<endl;
    
    return 0;
}


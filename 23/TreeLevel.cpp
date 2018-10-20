#include <iostream>
#include <deque>
#include <queue>
#include <vector>

using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
class Solution{
	public:
	int getThelevelCount(TreeNode *root){
		if(root==NULL){
			return 0;
		}
		else{
			int l = getThelevelCount(root->left);
			int r = getThelevelCount(root->right);
			return max(l,r)+1;
		}
	}
	int getThelevelCount(TreeNode *root,int depth){
		if(root==NULL){
			return 0;
		}
		else{
			int l = getThelevelCount(root->left,depth+1);
			int r = getThelevelCount(root->right,depth+1);
			return max(l,r)+1;
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
    cout <<solu.getThelevelCount(tree,0) <<endl;


    return 0;
}

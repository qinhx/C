#include <iostream>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){
	}
	TreeNode(){
	}
};

class Solution{
	public: 
	void ConvertRecursion(TreeNode *root, TreeNode **pLastNode){
		if(root ==NULL){
			return;
		}
		TreeNode *currNode = root;
		if(currNode->left!=NULL){
			ConvertRecursion(root->left,pLastNode);
		} 
		currNode->left = *pLastNode;
		if(*pLastNode!=NULL){
			(*pLastNode)->right = currNode;
		}
		*pLastNode = currNode;
		if(currNode->right!=NULL){
			ConvertRecursion(currNode->right,pLastNode);
		}
	}
	
	TreeNode* Convert(TreeNode* pRootOfTree){
		if(pRootOfTree == NULL){
			return NULL;
		}
		TreeNode *pLastNode =NULL;
		ConvertRecursion(pRootOfTree,&pLastNode);
		TreeNode *node = pLastNode;
		while(pLastNode!=NULL&&pLastNode->left!=NULL){
			pLastNode = pLastNode->left;
		}
		return pLastNode;
	}
};
int main( )
{

    TreeNode tree[4];
    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[1].val = 3;
    tree[1].left = &tree[3];
    tree[1].right = NULL;
    tree[2].val = 5;
    tree[2].left = NULL;
    tree[2].right = NULL;
    tree[3].val = 2;
    tree[3].left = NULL;
    tree[3].right = NULL;


    Solution solu;
    TreeNode *head = solu.Convert(tree);
    while(head != NULL)
    {
        cout <<head->val <<" ";
        head = head->right;
    }
    return 0;
}

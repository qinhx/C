#include <iostream>

using namespace std;


//  ���Կ���
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

using namespace std;

struct TreeLinkNode
{
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;

    TreeLinkNode(int x = 0)
    :val(x), left(NULL), right(NULL), next(NULL)
    {

    }
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode){
    	if(pNode==NULL){
    		return NULL;
		}
        TreeLinkNode *pNext=NULL;
		if(pNode->right!=NULL){
			pNext = pNode->right;
			while(pNext->left!=NULL){
				pNext = pNext->left;
			}
		}else if(pNode->right==NULL&&pNode->next!=NULL){
			TreeLinkNode *pCurr = pNode;
			TreeLinkNode *pParent = pNode->next;
			while(pParent!=NULL&&pCurr == pParent->right){
				pCurr = pParent;
				pParent = pParent->next;
			}
			pNext = pParent;
		}
		return pNext;		
    }
};

int main( )
{
    Solution solu;
    TreeLinkNode tree[10];

    tree[0].val = 4;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];
    tree[0].next = NULL;

    tree[1].val = 2;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];
    tree[1].next = &tree[0];

    tree[2].val = 5;
    tree[2].left = NULL;
    tree[2].right = &tree[5];
    tree[2].next = &tree[0];
    
    tree[3].val = 1;
    tree[3].left = &tree[6];
    tree[3].right = NULL;
    tree[3].next = &tree[1];
    
    tree[4].val = 3;
    tree[4].left = NULL;
    tree[4].right = NULL;
    tree[4].next = &tree[1];
    
    tree[5].val = 9;
    tree[5].left = &tree[7];
    tree[5].right = NULL;
    tree[5].next = &tree[2];
    
    tree[6].val = 0;
    tree[6].left = NULL;
    tree[6].right = NULL;
    tree[6].next = &tree[3];
    
    tree[7].val = 7;
    tree[7].left = &tree[8];
    tree[7].right = &tree[9];
    tree[7].next = &tree[5];

    tree[8].val = 6;
    tree[8].left = NULL;
    tree[8].right = NULL;
    tree[8].next = &tree[7];

    tree[9].val = 8;
    tree[9].left = NULL;
    tree[9].right = NULL;
    tree[9].next = &tree[7];
    //InOrder(tree);

    cout <<solu.GetNext(&tree[6])->val <<endl;;
    cout <<solu.GetNext(&tree[3])->val <<endl;;
    cout <<solu.GetNext(&tree[1])->val <<endl;
    cout <<solu.GetNext(&tree[4])->val <<endl;;
    cout <<solu.GetNext(&tree[0])->val <<endl;
    cout <<solu.GetNext(&tree[2])->val <<endl;
    cout <<solu.GetNext(&tree[8])->val <<endl;
    cout <<solu.GetNext(&tree[7])->val <<endl;    
    cout <<solu.GetNext(&tree[9])->val <<endl;
    return 0;
}

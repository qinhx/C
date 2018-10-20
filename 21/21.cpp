#include <iostream>
using namespace std;
struct ListNode
{
public :
    int val;
    struct ListNode *next;

};
class Solution{
	public:
		ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead){
			ListNode *left=NULL;
			ListNode *right=NULL;
			for(left=leftHead;left!=NULL;left=left->next){
				for (right=rightHead;right!=NULL;right=right->next){
					if(left == right){
						return left;
						break;
					}
				}
				
			}
			return left;
			
		}
};

int main( )
{
    ListNode common[2];
    common[0].val = 6;
    common[0].next = &common[1];
    common[1].val = 7;
    common[1].next = NULL;

    ListNode left[3];
    left[0].val = 1;
    left[0].next = &left[1];
    left[1].val = 2;
    left[1].next = &left[2];
    left[2].val = 3;
    left[2].next = &common[0];

    ListNode right[2];
    right[0].val = 4;
    right[0].next = &right[1];
    right[1].val = 5;
    right[1].next = &common[0];

    Solution solu;
    ListNode *node = solu.FindFirstCommonNode(left, right);
    while(node != NULL)
    {
        cout <<node->val <<" ";
        node = node->next;
    }
    cout <<endl;

    return 0;
}

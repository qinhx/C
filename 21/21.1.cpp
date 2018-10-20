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
			ListNode *left=leftHead;
			ListNode *right=rightHead;
			int L_len = len(leftHead);
			int R_len = len(rightHead);
			if(L_len>R_len){
				int	l = L_len - R_len;
				while(l>0&&left!=NULL){
					left = left->next;
					l--;
				}
			}
			if(L_len<R_len){
			int	l = -(L_len - R_len);
				while(l>0&&right!=NULL){
					right = right->next;
					l--;
				}
			}
			while(left!=NULL&&right!=NULL){
				if(left==right){
					break;
				}
				left= left->next;
				right = right->next;
			}
			
			return (left==right)?left:NULL;
			
		}
		int len(ListNode *head){
			int len =0;
			ListNode *root =head;
			while(root!=NULL){
				len+=1;
				root = root->next;
			}
			return len;
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

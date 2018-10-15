#include <iostream>
using namespace std;
#include <vector>
struct Node{
	int val;
	struct Node *next;
};
class Solution{
	public:
	Node* Merge(Node *Left,Node *Right){
		if(Left==NULL){
			cout<<"Left is NULL"<<endl;
			return Right;
		}else if(Right ==NULL){
			cout<<"Left is NULL"<<endl;
			return Left;
		}
		Node *head =NULL;
		if(Left->val < Right->val){
			head=Left;
			cout<<"In The Merge Left "<<Left->val<<endl;
			head->next = Merge(Left->next,Right);
		}
		if(Left->val > Right->val){
			head = Right;
			cout<<"In the Merge Right "<<head->val<<endl;
			head->next= Merge(Left,Right->next);
		}
		return head;
	}
};
int main( )
{
    Node left, right[3];

    left.val = 5;
    left.next = NULL;
    right[0].val = 1;
    right[0].next = &right[1];
    right[1].val = 6;
    right[1].next = &right[2];
    right[2].val = 7;
    right[2].next = NULL;


    Solution solu;
    Node *head = solu.Merge(&left, right);
    while(head != NULL)
    {
        cout <<head->val;
        head = head->next;
    }


    return 0;
}

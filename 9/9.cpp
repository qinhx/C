#include <iostream>
using namespace std;

struct Node{
	int val;
	struct Node *next;
};
class Solution{
	public:
		Node* ReverseNode(Node* pHead){
			if(pHead==NULL){
				return NULL;
			}
			Node *pNode = pHead;
			Node *nNode = NULL;
			Node *pNext = NULL;
			
			nNode = pNode;
			pNode = pNode->next;
			nNode->next=NULL;
			cout<<nNode->val <<" in list head now..." <<endl;
			while(pNode!=NULL){
				pNext= pNode->next;
				pNode->next = nNode;
				nNode=pNode;
			cout<<nNode->val <<" in list head now..." <<endl;
				pNode=pNext;
			} 
			return nNode;
		} 
} ;

int main( )
{
    Node list[5];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = &list[4];
    list[4].val = 5;
    list[4].next = NULL;


    Node *node = list;
    while(node != NULL)
    {
        cout <<node->val;
        node = node->next;
    }
    cout <<endl;



    Solution solu;
    node = solu.ReverseNode(list);
    while(node != NULL)
    {
        cout <<node->val;
        node = node->next;
    }
    cout <<endl;

    return 0;
    return 0;
}

#include <iostream>
using namespace std;
#include <string>
#include <stack>
#include <vector>
struct ListNode{
	public:
		int val;
		struct ListNode *next;
};
class Solution{
	public:
	vector<int> printListFromTailToHead(struct ListNode* head){
		ListNode *node =head;
		stack<int> st;
		int count = 0;
		while(node!=NULL){
			
			st.push(node->val);
			count++;
			node = node->next;
		}
	
		vector<int> res(count);
		for (int i=0;i<count&&st.empty()!=true;i++){
			res[i]=st.top();
			st.pop();
		}
		return res;
	}
};

class Solution1{
	public:
	vector<int> res;
	vector<int> printListFromTailToHead(struct ListNode*head){
		if(head!=NULL){
			
			printListFromTailToHead(head->next);
			res.push_back(head->val);
		}
		return res;
	} 
};
int main(){
	ListNode list[4];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;
    Solution1 solu;
    vector<int> res = solu.printListFromTailToHead(list);

    cout <<"there are " <<res.size( ) <<"datas in vector" <<endl;
    for(int i = 0; i < res.size( ); i++)
    {
        cout <<res[i] <<endl;
    }
    return 0;
}

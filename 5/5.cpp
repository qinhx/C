#include <iostream>
#include <stack>
using namespace std;

class Solution{
	private:
	 stack<int> stackIn;
	 stack<int>stackOut;
	public:
	 	void push(int node){
	 		stackIn.push(node);
		 }			
		int pop(){
			while(!stackIn.empty()){
				stackOut.push(stackIn.top());
				stackIn.pop();
			}
			int node = stackOut.top();
			stackOut.pop();
			while(!stackOut.empty()){
				stackIn.push(stackOut.top());
				stackOut.pop();
			}
			return node;
		}
		bool empty(){
			return(stackIn.empty()==true&&stackOut.empty()==true);
		}
		 
};
int main(){
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);

    int node;
    while(solu.empty() != true)
    {

        cout <<solu.pop( );
    }

    return 0;
}


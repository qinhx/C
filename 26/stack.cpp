#include <iostream>
using namespace std;
#include <stack>
#include <string>
class Solution{
	public:
		string rotate(string str,int n){
			stack<char> st1;
			stack<char> st2;
			
			int len = str.size();
			if(n>len)
				n = n%len;
			for(int i=0;i<n;i++){
				st1.push(str[i]);
			}
			for(int i = n;i<len;i++){
				st2.push(str[i]);
			}
			string tmp="";
			while(!st2.empty()){
				tmp=st2.top()+tmp;
				st2.pop();
			}
			string tmp2="";
			while(!st1.empty()){
				tmp2 = st1.top()+tmp2;
				st1.pop();
			}
			tmp = tmp+tmp2;
			return tmp;
		} 
};
int main(){
	string s ="abcXYZdef";
	Solution solu;
	cout<<s<<endl;
	cout<<solu.rotate(s,10)<<endl;
} 

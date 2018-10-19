#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution{		
	protected:
		vector<string> m_res; 
	public:
		void Permutation(string prefix,string str){
			if(str.length() == 0){
				m_res.push_back(prefix);
			}else{
				for(int i=0;i<str.length();i++){
					Permutation(prefix+str[i],str.substr(0,i)+str.substr(i+1,str.length()));//recursion way  to solve this problem	
				}
			}
		}
		vector<string> Permutation(string s ){
			m_res.clear();
			if(s.empty()){
				return m_res;
			}
			Permutation("",s);
			return m_res;
			
		}
};
int main( )
{
	vector<string> out;
    Solution solu;
    out=solu.Permutation("abc");
    vector<string>::iterator m = out.begin();
    while(m!=out.end()){
    	cout<<*m<<endl;
    	m++;
	}
    return 0;
}

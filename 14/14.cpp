#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution{		
	public:
		vector<string> Permutation(string str){
			vector<string> res;
			if(str.length()==0){
				return res;
			}
			sort(str.begin(),str.end());
			do{
				res.push_back(str);
				cout<<str <<endl;
			}while(next_permutation(str.begin(),str.end()));
			return res;
		}
};
int main( )
{
    Solution solu;
    solu.Permutation("abc");
    return 0;
}

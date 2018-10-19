#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
template<class T>
string ToString(const T& t){
	ostringstream os;
	os<<t;
	return os.str(); 
}
class Solution{
	public:
	static bool Compare(const string &left,const string &right){
		string lr = left+right;
		string rl = right + left;
		return lr<rl;
	}
	string PM(vector<int> numbers){
		string res = "";
		string str;
		vector<string> strNum;
		for(int i=0;i<numbers.size();i++){
			str = ToString(numbers[i]);
			strNum.push_back(str);
		}
		sort(strNum.begin(),strNum.end(),Compare);
		for (int i=0;i<strNum.size();i++){
			res +=strNum[i];
		}
		return res;
	}
};
int main( )
{
    Solution solu;

    int arr[] = { 321, 32, 3 };
    vector<int> vec(arr, arr + 3);
    cout <<solu.PM(vec) <<endl;
    return 0;
}

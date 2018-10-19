#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
class Solution{
	public:
    int InversePairs(vector<int> el)
    {
			if(el.size()==0){
				return 0;
			}
			int count =0;
			for (int i=0;i<el.size();i++){
				for(int j=i+1;j<el.size();j++){
					if(el[i]>el[j])
						count++;
				}
			}
			return count;
		}
};
int main( )
{
    Solution solu;

    int arr[] = { 7, 5, 6, 4 };
    vector<int> vec(arr, arr + 4);

    cout <<solu.InversePairs(vec) <<endl;
    return 0;
}

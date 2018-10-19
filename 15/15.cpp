#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain

class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
		if(numbers.size()==0){
			return 0;
		} 
		if(numbers.size()==1){
			return numbers[0];
		}
		int len= numbers.size();
		int count[len]={0};
		for(int i=0;i<len;i++){
			count[numbers[i]] +=1;  
		}
		int max=0;
		for(int j=0;j<len;j++){
			
			if(count[j]>max)
				max = count[j];
		}
		for(int i=0;i<len;i++){
			if(count[i]>(len/2))
				return i;
		}
		return 0;
    }
};


int __tmain( )
{
    int arr1[] = { 2, 2, 2, 2, 3, 3, 2, 5, 5};

    vector<int> vec1(arr1, arr1 + 9);

    Solution solu;
    cout<<solu.MoreThanHalfNum_Solution(vec1)<<endl;

    int arr2[] = { 1, 2 };

    vector<int> vec2(arr2, arr2 + 2);
    cout <<solu.MoreThanHalfNum_Solution(vec2) <<endl;
    return 0;
}

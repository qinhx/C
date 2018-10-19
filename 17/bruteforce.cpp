#include <iostream>
#include <vector>
using namespace std;
class Solution{
	public:
		int FindTheBestSumOfSubArray(vector<int> array){
			if(array.size()==0){
				return 0;
			}
			int sum, maxSum=INT_MIN;
			for (int i =0;i<array.size();i++){
				sum = 0;
				 for (int j=i;j<array.size();j++){
				 	sum += array[j];
					 if(sum>maxSum){
					 	maxSum = sum;
					 } 
				 }
			}
			return maxSum;
		}
};
int main( )
{


    Solution solu;

    int arr1[] = { 6, -3, -2, 7, -15, 1, 2, 2};
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
    cout <<"maxSum = " <<solu.FindTheBestSumOfSubArray(vec1) <<endl;

    int arr2[] = { -2, -8, -1, -5, -9 };
    vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    cout <<"maxSum = " <<solu.FindTheBestSumOfSubArray(vec2) <<endl;

    return 0;
}

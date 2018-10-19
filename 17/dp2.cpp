#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		int FindTheBestSumOfSubArray(vector<int> array){
			if(array.size()==0){
				return 0;
			}
			int maxSum = INT_MIN;
			int maxNum = INT_MIN;
			int sum = 0;
			for(int i=0;i<array.size();i++){
				sum += array[i];
				if(sum<0){
					sum =0;
				} else if(sum >maxSum){
					maxSum = sum;
				}
				if(array[i]>maxNum){
					maxNum = array[i];
				}
			}
			return (maxNum > 0) ? maxSum : maxNum;
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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition(int arr[],int left,int right){
		 int i=left, j=right;
		 int tmp = arr[left];
		 while(i<j){
		 	while(i<j&&arr[j]>tmp)
		 		j--;
		 	if(i<j){
		 		arr[i]=arr[j];
		 		i++;
			 }
			 while(i<j&&arr[i]<tmp)
			 	i++;
			if(i<j){
				arr[j] = arr[i];
				j++;
			}
		 }
		 arr[i]=tmp;
		 return i;
}
void quick_sort(int arr[], int left, int right) {
		if(left>right)
			return;
		int j = partition(arr,left, right);
		quick_sort(arr,left,j-1);
		quick_sort(arr,j+1,right);
}
int main( )
{

    int arr[ ] = { 4, 5, 1, 6, 2, 7, 3, 8 };
    quick_sort(arr,0,7);
    for (int i=0;i<7;i++){
    	cout<<arr[i]<<endl;
	}
    return 0;
}


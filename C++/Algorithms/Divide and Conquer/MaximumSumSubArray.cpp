#include <iostream>
using namespace std;

int max(int a, int b){
	return(a>b)?a:b;
}

int max(int a, int b, int c){
	return max(max(a,b),c);
}

int maxCrossingSum(int arr[], int low, int mid, int high){
	int sum = 0, i, left_sum = INT_MIN;
	for(i = mid; i >= 0; i--){
		sum = sum + arr[i];
		if( sum > left_sum){
			left_sum = sum;
		}
	}
	
	sum = 0;
	int right_sum = INT_MIN;
	for(i = mid+1; i <= high; i++){
		sum = sum + arr[i];
		if( sum > right_sum){
			right_sum = sum;
		}
	}
	return left_sum + right_sum;
}

int maxSumSubArray(int arr[],int low,int high){
	if(high == low){
		return arr[low];
	}
	int mid = (low+high)/2;
	return max( maxSumSubArray(arr,low,mid), 
				maxSumSubArray(arr,mid+1,high), 
				maxCrossingSum(arr,low,mid,high));
}

int main(){
	int arr[] = {4,5,-2,10,10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int max_sum = maxSumSubArray(arr ,0, n-1);
	cout<<"Max sum is"<<max_sum;
	return 0;
}

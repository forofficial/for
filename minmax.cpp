#include<iostream>
#include<omp.h>
#include<climits>
using namespace std;

int main(){
	int n;
	cout<<"how many numbers";
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cout<<"enter number";
		cin>>arr[i];
	}
	
	int m=INT_MAX;
	#pragma omp parallel for reduction(min:m)
	for(int i=0;i<n;i++){
		if(arr[i]<m)m=arr[i];
	}
	cout<<"min value is "<<m<<"\n";
	
	int mn=INT_MIN;
	#pragma omp parallel for reduction(max:m)
	for(int i=0;i<n;i++){
		if(arr[i]>mn)mn=arr[i];
	}
	cout<<"max value is "<<mn<<"\n";
	
	int sum=0;
	#pragma omp parallel for reduction(+:sum)
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	cout<<"sum value is "<<sum<<"\n";
	cout<<"avg value is "<<(double)sum/n;
	
}

#include<iostream>
#include<time.h>
#include<omp.h>
#include<climits>
using namespace std;

int main(){
	int n;
	cout<<"enter number of elements:-";
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cout<<"enter number "<<i+1<<":-";
		cin>>arr[i];
	}
	clock_t strt =clock();
	
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
	clock_t end =clock();
	
	cout<<"sum value is "<<sum<<"\n";
	cout<<"avg value is "<<(double)sum/n;
	cout<<"\ntime taken in ms:-"<<(double)(end-strt);
	
}

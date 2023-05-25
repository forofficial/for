#include<iostream>
#include<time.h>
#include<omp.h>
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
	cout<<"original array:-";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	clock_t strt=clock();
	int var=0;
	for(int i=0;i<n;i++){
		
		#pragma omp parallel for
		for(int j=var;j<n-1;j+=2){
			if(arr[j]>arr[j+1]){
				int tem=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tem;
				cout<<"ad";
			}
		}
		if(var==0)var=1;
		else var=0;
	}
	clock_t end=clock();
	
	cout<<"\nfinal array:-";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\ntime taken in ms:-"<<(double)(end-strt);
}

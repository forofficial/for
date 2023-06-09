#include<iostream>
#include<time.h>
#include<vector>
#include<stack>
using namespace std;

int arr[10][10];
stack<int>s;

void dfs(int n,int vert){
	cout<<vert<<" ";
	#pragma omp parallel for ordered
	for(int i=0;i<n;i++){
		#pragma omp ordered
		if(arr[vert][i]==1){
			s.push(i);
			dfs(n,s.top());
		}
	}
	s.pop();
	
}

int main(){
	cout<<"enter the number of vertices:- ";
	int n;cin>>n;
	
	cout<<"enter number of edges:- ";
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cout<<"enter edge "<<i+1<<":-";
		cin>>a>>b;
		arr[a][b]=1;
	} 
	s.push(0);
	clock_t strt=clock();
	cout<<"\nsolution ";
	dfs(n,0);
	clock_t end=clock();

	cout<<"\ntime taken in ms:-"<<(double)(end-strt);
	
}

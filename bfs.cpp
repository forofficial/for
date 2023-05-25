#include<iostream>
#include<vector>
#include<queue>
#include<time.h>
using namespace std;

int arr[10][10];
queue<int>q;

void bfs(int n,int vert){
	cout<<vert<<" ";
	#pragma omp parallel for ordered
	for(int i=0;i<n;i++){
		#pragma omp ordered
		if(arr[vert][i]==1){
			q.push(i);
		}
	}
	
	while(!q.empty()){
		int tem=q.front();
		q.pop();
		bfs(n,tem);
		
	}
	
}

int main(){
	cout<<"enter the number of vertices:- ";
	int n;cin>>n;
	
	cout<<"enter number of edges:-";
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cout<<"enter edge"<<i+1<<":-";
		cin>>a>>b;
		arr[a][b]=1;
	}
	clock_t strt=clock();
	cout<<"soultion:- ";
	bfs(n,0);
	clock_t end=clock();
	cout<<"\ntime taken in ms:-"<<(double)(end-strt);
	
}

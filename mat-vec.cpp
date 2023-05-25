#include<iostream>
#include<time.h>
#include<omp.h>
using namespace std;
int main()
{
    cout<<"enter no of rows and column in matrix:-";
    int r1,c1;
    cin>>r1>>c1;
    int mat[r1][c1];
    
    for(int i=0;i<r1;i++){
    	cout<<"enter martrix 1 "<<" row "<<i+1<<":-" ;
    	for(int j=0;j<c1;j++){
    		cin>>mat[i][j];
		}
	}
	int n;
	cout<<"number of elements in vector:-";
	cin>>n;
	int vec[n];
	for(int i=0;i<n;i++){
		cout<<"enter element "<<i+1<<" for vector:-";

		cin>>vec[i];
	}
	
	cout<<"mat\n";
	for(int i=0;i<r1;i++){
		for( int j=0;j<c1;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"vec\n";
	for(int i=0;i<n;i++){
		cout<<vec[i]<<" ";
	}
	cout<<"\n";
	
    cout<<"Multiplication: "<<endl;
    int rvec[n];
	clock_t strt=clock();
    #pragma omp parallel for
    for(int i=0; i<r1; i++)
    {
        rvec[i] = 0;
        

        #pragma omp parallel for
        for(int j=0; j<c1; j++) rvec[i] += mat[i][j] * vec[j];

        

    }
	clock_t end=clock();
    for(int i=0; i<r1; i++) cout<<rvec[i]<<" ";
    cout<<endl;
    cout<<"\ntime taken in ms:-"<<(double)(end-strt);
    return 0;
}

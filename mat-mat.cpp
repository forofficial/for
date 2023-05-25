#include<iostream>
#include<omp.h>
#include<time.h>
using namespace std;
int main()
{
    cout<<"Number of rows and column in first matrix: ";
    int r1,c1;
    cin>>r1>>c1;
    cout<<"Number of rows and column in second matrix: ";
    int r2,c2;
    cin>>r2>>c2;
    int mat1[r1][c1],mat2[r2][c2];
        

    for(int i=0;i<r1;i++){
    	cout<<"enter matrix 1"<<" row "<<i+1<<":-";
    	for(int j=0;j<c1;j++){
    		cin>>mat1 [i][j];
		}
	}
	

	for(int i=0;i<r2;i++){
		cout<<"enter matrix 2"<<" row "<<i+1<<":-";
    	for(int j=0;j<c2;j++){
    		cin>>mat2[i][j];
		}
	}
	cout<<"m1\n";
   for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c1; j++) cout<<mat1[i][j]<<" ";
        cout<<endl;
    }
    	cout<<"m2\n";

    for(int i=0; i<r2; i++)
    {
        for(int j=0; j<c2; j++) cout<<mat2[i][j]<<" ";
        cout<<endl;
    }

    cout<<"Multiplication: "<<endl;
    int mat3[r1][c2];
    clock_t strt=clock();
    #pragma omp parallel for		
	for(int i=0;i<r1;i++)
	{
		#pragma omp parallel for
		for(int j=0;j<c2;j++)
		{
			mat3[i][j]=0;
            //int arr[c1];

            #pragma omp parallel for
			for(int k=0;k<c1;k++) mat3[i][j] += mat1[i][k]*mat2[k][j];

		}
	}
	clock_t end=clock();

    for(int i=0; i<r1; i++)
    {
        for(int j=0; j<c2; j++) cout<<mat3[i][j]<<" ";
        cout<<endl;
    }
	cout<<"\ntime taken in ms:-"<<(double)(end-strt);
    return 0;
}

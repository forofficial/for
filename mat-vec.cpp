#include<iostream>
#include<omp.h>
using namespace std;
int main()
{
    cout<<"enter no of rows and column in matrix:-";
    int r1,c1;
    cin>>r1>>c1;
    int mat[r1][c1];
    cout<<"enter mat:-";
    for(int i=0;i<r1;i++){
    	for(int j=0;j<c1;j++){
    		cin>>mat[i][j];
		}
	}
	int n;
	cout<<"number of elements in vector:-";
	cin>>n;
	int vec[n];
	cout<<"enter elements of vector:-";
	for(int i=0;i<n;i++)cin>>vec[i];
	
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

    #pragma omp parallel for
    for(int i=0; i<r1; i++)
    {
        rvec[i] = 0;
        int arr[n] = {0};

        #pragma omp parallel for
        for(int j=0; j<c1; j++) arr[j] = mat[i][j] * vec[j];

        int sum = 0;

        #pragma omp parallel for reduction(+: sum)
        for(int k = 0; k < c1; k++) sum += arr[k];

        rvec[i] = sum;
    }

    for(int i=0; i<c1; i++) cout<<rvec[i]<<" ";
    cout<<endl;
    
    return 0;
}

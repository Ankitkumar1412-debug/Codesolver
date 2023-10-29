//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	/*int i=0;
    	int j=n;
    	long long int sum=0;
    	while(i<j){
    	    for(j=i;j<n;j++){
    	        sum+=arr[i]^arr[j];
    	    }
    	    i++;
    	}
    	return sum;*/
    	
    int totalBits = 32; // Assuming integers are 32-bit
    long long int sum = 0;

    for (int bit = totalBits - 1; bit >= 0; bit--) {
        int countOnes = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] & (1 << bit)) {
                countOnes++;
            }
        }

        sum += ((long long int)countOnes * (n - countOnes) * (1LL << bit));
    }

    return sum;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends
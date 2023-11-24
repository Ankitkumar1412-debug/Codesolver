//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    deque<int> temp;
	    int l = 1, r = n / 2;
	    
	    while(r<n-1) {
	        if(arr[l] != -1)
	            temp.push_back(arr[l]);
	        arr[l] = arr[r];
	        arr[r++] = -1;
	        if(arr[l+1] != -1)
	            temp.push_back(arr[l+1]);
	            
	        arr[l+1] = temp.front();
	        temp.pop_front();
	        l += 2;
	}
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        /*vector<int> vec;
        for(int i=0;i<n;i++){
            if(arr[i]==x){
                vec.push_back(i);
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]==x){
                vec.push_back(i);
                return vec;
            }
        }
        return{-1,-1};*/
        vector<int> vec;
        int i = 0,j = n-1;
        int maxIndex = -1, minIndex = -1;
        
        while(i <= j) {
            int mid = (i+j) / 2;
            
            if(arr[mid] > x) {
                j = mid-1;
            } else {
                if(arr[mid] == x) {
                    maxIndex = mid;
                }
                i = mid+1;
            }
        }
        i = 0; j = n-1;
        while(i <= j) {
            int mid = (i+j) / 2;
            
            if(arr[mid] < x) {
                i = mid+1;
            } else {
                if(arr[mid] == x){
                minIndex = mid;
                }
                j = mid-1;
            }
        }
        if(maxIndex == -1 || minIndex == -1) {
            vec.push_back(-1);
            vec.push_back(-1);
        } else {
            vec.push_back(minIndex);
            vec.push_back(maxIndex);
        }
        
        return vec;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        vector<long long> vec;
        long long res;
        vec.push_back(-1);
        st.push(arr[n-1]);
        for(long long i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i])
            st.pop();
            
            if(st.empty()){
                res=-1;
            }
            else{
                res=st.top(); 
            }
            vec.push_back(res);
            st.push(arr[i]);
        }
        reverse(vec.begin(),vec.end());
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
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
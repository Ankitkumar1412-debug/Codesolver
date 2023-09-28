//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string> vec;
		    permute(vec,0,S);
		    vector<string> res;
		    for(auto it:vec){
		        res.push_back(it);
		    }
		    return res;
		    
		}
		
		void permute(set<string> &ans,int begin,string vec){
		    if(begin>=vec.size()){
		        ans.insert(vec);
		        return;
		    }
		    for(int i=begin;i<vec.size();i++){
		        swap(vec[begin],vec[i]);
		        permute(ans,begin+1,vec);
		        swap(vec[begin],vec[i]);
		    }
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
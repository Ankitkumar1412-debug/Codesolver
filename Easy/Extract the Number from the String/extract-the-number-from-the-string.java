//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S=read.readLine();
            Solution ob = new Solution();
            System.out.println(ob.ExtractNumber(S));
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    long ExtractNumber(String s){
        //code here
        long max = -1;
        int n = s.length();
        
        for(int i=0;i<n;i++){
    
            if(Character.isDigit(s.charAt(i))){
                long temp = 0;
                boolean flag = true;
                while(i<n && s.charAt(i)!=' '){
                    if(s.charAt(i)=='9'){
                        flag = false;
                    }
                    if(flag){
                        temp = temp*10 + s.charAt(i)-'0';
                    }
                    i++;
                }
                if(flag){
                    max = Math.max(temp,max);
                }
            }
        }
        return max;
    }
}
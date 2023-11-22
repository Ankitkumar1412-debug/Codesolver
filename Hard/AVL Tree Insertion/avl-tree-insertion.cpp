//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

class Solution{
  public:
    /*You are required to complete this method */
    
    int height(Node *node){
        if(!node)
            return 0;
        return max(height(node->left),height(node->right))+1;
    }
    int BF(Node *node){
        if(!node)
            return -1;
        else
            return height(node->left)-height(node->right);
    }
    Node *lr(Node *node){
        Node *parent=node->left;
        Node *temp=parent->right;
        parent->right=node;
        node->left=temp;
        return parent;
    }
    Node *rr(Node *node){
        Node *parent=node->right;
        Node *temp=parent->left;
        parent->left=node;
        node->right=temp;
        return parent;
    }
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        if(!node)
            return new Node(data);
            
        if(node->data<data)
            node->right= insertToAVL(node->right,data);
        else if(node->data>data)
            node->left=insertToAVL(node->left,data);
        else
            return node;
        
        int bf=BF(node);
        if(bf>1 and data<node->left->data){
            return lr(node);
        }
        if(bf<-1 and data>node->right->data){
            return rr(node);
        }
        if(bf>1 and data>node->left->data){
            node->left=rr(node->left);
            return lr(node);
        }
        if(bf<-1 and data<node->right->data){
            node->right=lr(node->right);
            return rr(node);
        }
        return node;
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends
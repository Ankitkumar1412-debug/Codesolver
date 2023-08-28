//{ Driver Code Starts
import java.util.*;

class Node
{

    int data;
    Node next;

    Node(int d)
    {
        data = d;
        next = null;
    }
}


public class LinkedList
{
    
 

    /* Function to print linked list */
   public static void print(Node root)
    {
        Node temp = root;
        while(temp!=null)
        {
            System.out.print(temp.data + " ");
            temp=temp.next;
        }
    }


    /* Driver program to test above functions */
    public static void main(String args[])
    {

        /* Constructed Linked List is 1.2.3.4.5.6.
         7.8.8.9.null */
        int value;
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t > 0 && sc.hasNextInt() )
        {
            int n = sc.nextInt();
            
            //int n=Integer.parseInt(br.readLine());
            int a1 = sc.nextInt();
            Node head = new Node(a1);
            Node tail = head;

            for (int i = 1; i < n && sc.hasNextInt() ; i++)
            {
                int a = sc.nextInt();
                tail.next = new Node(a);
                tail = tail.next;
            }


            Node result = new Solution().compute(head);
            print(result);
            System.out.println();
            t--;
        }
    }
}
// } Driver Code Ends


/*
class Node {
   int data;
   Node next;

  Node(int data) {
      this.data = data;
  }
}
*/
class Solution
{
    Node compute(Node head)
    {
        // your code here
        if(head==null){
            return head;
        }
        
        //Reverse the LinkedList
        Node curr=head;
        Node pre=null;
        Node frw=null;
        
        while(curr!=null){
            frw=curr.next;
            curr.next=pre;
            pre=curr;
            curr=frw;
        }
        
        // Condition Time 
        
        Node pos=pre;
        
        while(pos!=null && pos.next!=null){
            if(pos.data>pos.next.data){
                pos.next=pos.next.next;
            }else{
                pos=pos.next;
            }
        }
        
        
        
        // Again Reverse
        
        Node curr1=pre;
        Node pre1=null;
        Node frw1=null;
        
        while(curr1!=null){
            frw1=curr1.next;
            curr1.next=pre1;
            pre1=curr1;
            curr1=frw1;
        }
        
        return pre1;
    }
}
  
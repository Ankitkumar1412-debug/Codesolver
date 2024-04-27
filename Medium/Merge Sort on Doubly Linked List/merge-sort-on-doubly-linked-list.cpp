//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Split the list into two halves
        Node* mid = findMiddle(head);
        Node* nextToMid = mid->next;
        mid->next = nullptr;
        nextToMid->prev = nullptr;

        // Recursively sort the two halves
        Node* left = sortDoubly(head);
        Node* right = sortDoubly(nextToMid);

        // Merge the two sorted halves
        return merge(left, right);
    }

private:
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* merge(Node* left, Node* right) {
         if (left == nullptr) return right;
    if (right == nullptr) return left;

    Node* dummy = new Node(0); // Dummy node
    Node* curr = dummy;

    while (left != nullptr && right != nullptr) {
        if (left->data <= right->data) {
            curr->next = left;
            left->prev = curr;
            left = left->next;
        } else {
            curr->next = right;
            right->prev = curr;
            right = right->next;
        }
        curr = curr->next;
    }

    if (left != nullptr) {
        curr->next = left;
        left->prev = curr;
    }

    if (right != nullptr) {
        curr->next = right;
        right->prev = curr;
    }

    Node* result = dummy->next;
    result->prev = nullptr; // Set the prev pointer of the result's head to null
    delete dummy;
    return result;
        // Your code here
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends
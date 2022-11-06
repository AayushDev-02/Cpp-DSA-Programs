#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;     // for doubly linked list

    Node(int d){
        this -> data = d;
        this-> next = NULL;
        this-> prev = NULL;
    }

    ~Node(){
        int value = this -> data;

        if(next != NULL){
            delete next;
            next = NULL;
        }

        cout << "Data deleted is :" << value << endl;
    }

};
// -------------------------------------------------- Singly Linked List -------------------------------------------------------------
void insertAtHead(Node* &head, int data){

    Node* temp = new Node(data);

    temp -> next = head;
    head = temp;

}

void insertAtTail(Node* &tail, int data){

    Node* temp = new Node(data);

    tail -> next = temp;
    tail = temp;

}


void insertAtPosition(Node* &head, Node* &tail,int position, int data){

    //insert at head
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    //insert at tail and any position

    // Node* temp = new Node(data);
    Node* temp = head;

    int cnt = 1;
    while(cnt< position-1 ) {
        cnt++;
        temp = temp->next;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, data);
        return;
    }

    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;


}

// void deleteNode(Node* &head, int position){

//     Node* temp = head;

//     if(position == 1){
//         head = head -> next;

//         temp -> next = NULL;
//         delete temp;

//     }else{

//         int cnt = 1;
//         Node* prev =NULL;
//         Node* curr = head;

//         while(cnt < position){
            
//             cnt++;
//             prev = curr;
//             curr = curr -> next;
//         }

//         prev -> next = curr -> next;
//         curr->next = NULL;
//         delete curr;

//     }


// }


void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}
// int main(){
    
//     Node* node1 = new Node(10);

//     Node* head = node1;
//     Node* tail = node1;

//     print(head);

//     insertAtHead(head, 12);
//     print(head);

//     insertAtHead(head, 15);
//     print(head);

//     insertAtHead(head, 20);
//     print(head);

//     insertAtTail(tail , 25);
//     print(head);

//     insertAtPosition(head, tail, 1, 5);
//     print(head);

//     insertAtPosition(head, tail, 7, 30);
//     print(head);

//     insertAtPosition(head, tail, 3, 13);
//     print(head);

//     cout << endl;
//     cout << head -> data << endl;
//     cout << tail -> data << endl;
//     cout << endl;

//     deleteNode(head, 2);
//     print(head);

//     return  0;

// }
// -------------------------------------------------- Singly Linked List -------------------------------------------------------------




// -------------------------------------------------- Circular Linked List ------------------------------------------------------------

// void insertNode(Node* &tail, int element, int data){

//     if(tail == NULL){
//         Node* temp = new Node(data);
//         tail = temp;
//         temp -> next = temp;
//     }else{

//         Node* curr = tail;

        
//         while(curr -> data != element){
//             curr = curr -> next;
//         }

//         Node* temp = new Node(data);
//         temp -> next = curr -> next;
//         curr->next = temp;


//     }

// }

// void deleteNode(Node* &tail, int element ){

//     if(tail == NULL){
//         return;
//     }else{

//     Node * curr = tail;
//     Node * prev = NULL;

//     while(curr -> data != element){
//         prev = curr;
//         curr = curr -> next;
//     }

//     prev-> next = curr -> next;

//     if(prev == curr){
//         tail = NULL;
//     }else if(tail == curr){
//         tail = prev;
//     }


//     curr -> next =NULL;
//     delete curr;
//     }
// }

// void print(Node* tail){

//     Node* temp = tail ;

//     do{
//         cout << temp -> data << " ";
//         temp = temp -> next;
//     }while(temp!=tail);

// }


// int main(){


//     Node * tail = NULL;
//     insertNode(tail, 5, 3);
//     insertNode(tail, 3, 4);
//     insertNode(tail, 4, 5);

//     insertNode(tail, 3, 7);

//     insertNode(tail, 5, 10);


//     deleteNode(tail, 6);
//     print(tail);


//     return 0;
// }


// -------------------------------------------------- Circular Linked List ------------------------------------------------------------



// -------------------------------------------------- Doubly Linked List ------------------------------------------------------------

// void insertAtHead(Node* &head, Node* &tail,  int data){

//     Node* temp = new Node(data);

//     if(head == NULL){
//         head = temp;
//         tail = temp;
//         return;
//     }


//     temp -> next = head;
//     head -> prev = temp;
//     head = temp;


// }

// void insertAtTail(Node* &head, Node* &tail , int data){
//     Node* temp = new Node(data);

//     if(head == NULL){
//         head = temp;
//         tail = temp;
//         return;
//     }

//     tail -> next = temp;
//     temp -> prev = tail;
//     tail = temp;

// }

// void insertAtPosition(Node* &head, Node* &tail, int position, int data){

//     if(position == 1){
//         insertAtHead(head,tail,data);
//         return;
//     }

//     Node* temp = head;
//     int cnt =1;
//     while(cnt < position - 1 ){

//         temp = temp -> next;
//         cnt++;
//     }

//     if(temp -> next ==NULL){
//         insertAtTail(head,tail,data);
//         return;
//     }

//     Node* curr = new Node(data);

//     curr -> next = temp ->next;
//     temp -> next -> prev = curr;
//     temp -> next = curr;
//     curr -> prev = temp;

// }


// void deleteNode(Node* &head, int position){

//     if(position == 1){
//         Node* temp = head;
        
//         temp ->next -> prev = NULL;
//         head = temp -> next;
//         temp -> next = NULL;

//         delete temp;
//     }else{

//         Node* curr = head;
//         Node* p = NULL;
//         int cnt=1;
//         while(cnt < position){

//             p = curr;
//             curr = curr-> next;
//             cnt++;

//         }

//         p -> next = curr -> next;
//         curr -> prev = NULL;
//         curr -> next = NULL;

//         delete curr;
//     }


// void print(Node* head){
//     Node * temp = head;

//     while(temp!=NULL){
//         cout << temp -> data << " "; 
//         temp = temp -> next;
//     }

//      cout << endl;
// }


// // int main(){
    
// //     Node* node1 = new Node(10);

// //     Node* head = node1;
// //     Node* tail = node1;

// //     print(head);

// //     insertAtHead(head,tail, 5);
// //     print(head);

// //     insertAtHead(head,tail, 4);
// //     print(head);

// //     insertAtHead(head,tail, 3);
// //     print(head);

// //     insertAtHead(head,tail, 2);
// //     print(head);

// //     insertAtHead(head,tail, 1);
// //     print(head);

// //     insertAtTail(head, tail, 20);
// //     print(head);
    
// //     // cout << head -> prev << endl;

// //     insertAtPosition(head , tail, 8, 40);
// //     print(head);

// //     insertAtPosition(head , tail, 1, -1);
// //     print(head);

// //     insertAtPosition(head , tail, 3, 7);
// //     print(head);

// //     cout << endl;

// //     deleteNode(head, 1);
// //     print(head);
// //     cout << endl;

// //     deleteNode(head, 9);
// //     print(head);
// //     cout << endl;

// //     deleteNode(head, 5);
// //     print(head);
// //     cout << endl;


// //     return 0;
// // }


// }
// -------------------------------------------------- Doubly Linked List ------------------------------------------------------------






// -------------------------------------------------- Reverse a Linked List ------------------------------------------------------------


// void solve(Node* &head, Node* &curr, Node* &prev){

//     if(curr==NULL){
//         head = prev;
//         return;
//     }

//     Node* forward = curr -> next;

//     solve(head, forward, curr);

//     curr -> next = prev;

// }



// Node* reverse(Node* &head){

//     // // iterative approach    ---------------------------------

//     // Node* curr =head;
//     // Node* prev = NULL;
//     // Node* forward = NULL;

//     // while(curr!=NULL){
//     //     forward = curr -> next;
//     //     curr -> next = prev;
//     //     prev = curr;
//     //     curr = forward;
//     // }

//     // return prev;

//     //recursive approach 1  ---------------------------------------------

//     // if(head == NULL || head -> next == NULL){
//     //     return head;
//     // }

//     // Node* chottaHead = reverse(head -> next);

//     // head -> next -> next = head;
//     // head -> next = NULL;

//     // return chottaHead;

//     //recursive approach 2  ---------------------------------------------


//     Node* curr = head;
//     Node* prev = NULL;

//     solve(head, curr, prev);

//     return head;


// }


// int main(){

//     Node* node1 = new Node(10);
//     Node* head = node1;
//     Node* tail = node1;

//     insertAtTail(tail, 20);
//     insertAtTail(tail, 30);
//     insertAtTail(tail, 40);
//     insertAtTail(tail, 50);
//     insertAtTail(tail, 60);

//     print(head);

//     head = reverse(head);

//     print(head);

//     return 0;
// }

// -------------------------------------------------- Reverse a Linked List ------------------------------------------------------------




// -------------------------------------------------- Middle of a Linked List ------------------------------------------------------------

// Node* getMid(Node* head){

//     if(head == NULL || head->next == NULL){
//         return head;
//     }

//     if(head -> next -> next == NULL){
//         return head;
//     }
//     Node* fast = head -> next;
//     Node* slow = head;

//     while(fast != NULL && fast -> next !=NULL ){
//         fast = fast -> next -> next;
//         slow = slow -> next;
//     }

//     return slow -> next;

// }

// Node* getMid(Node* head){

//     int len =0;
//     Node* temp = head;
    
//     while(temp!=NULL){
//         len++;
//         temp = temp -> next;
//     }

//     int mid = (len/2)+1;

//     temp = head;
    
//     int i =1;
//     while(i < mid ){
//         temp = temp -> next;
//         i++;
//     } 

//     return temp;
    

// }

// int main(){

//     Node* node1 = new Node(10);
//     Node* head = node1;
//     Node* tail = node1;

//     insertAtTail(tail, 20);
//     insertAtTail(tail, 30);
//     insertAtTail(tail, 40);
//     insertAtTail(tail, 50);
//     insertAtTail(tail, 60);

//     print(head);

//     Node* mid = getMid(head);

//     cout << mid -> data << endl;
//     cout << mid -> next ->data << endl;

//     return 0;
// }






// -------------------------------------------------- Middle of Linked List ------------------------------------------------------------





// -------------------------------------------------- Reverse Linked List in K groups ------------------------------------------------------------

// Node* kReverse(Node* &head, int k){

//     if(head == NULL){
//         return head;
//     }

//     Node* curr = head ;
//     Node* prev = NULL;

//     Node* forward = NULL;

//     int i =0;
//     while( i < k && curr!=NULL){
        
//         // cout << i << endl; -- just checking
//         forward = curr -> next ;
//         curr -> next = prev;
//         prev = curr;
//         curr = forward;
//         i++;
//     }

//     if(forward!=NULL){
//         head -> next = kReverse(forward, k);
//     }

//     return prev;
// }

// int main(){

//     Node* node1 = new Node(10);
//     Node* head = node1;
//     Node* tail = node1;

//     insertAtTail(tail, 20);
//     insertAtTail(tail, 30);
//     insertAtTail(tail, 40);
//     insertAtTail(tail, 50);
//     insertAtTail(tail, 60);

//     print(head);

//     head = kReverse(head, 2);

//     print(head);

//     return 0;
// }

// -------------------------------------------------- Reverse Linked List in K groups ------------------------------------------------------------


// -------------------------------------------------- Check circular Linked list ------------------------------------------------------------

// bool checkCircular(Node* head){
//     if(head == NULL){
//         return true;
//     }

//     Node* temp = head -> next;
//     while(temp != NULL && temp != head){
//         temp = temp -> next;
//     }


//     if(temp == head){
//         return true;
//     }

//     return false;
// }

// int main(){



    // return 0;
// }

//APPROACH 2:

bool checkCircular(Node* head){
    if(head == NULL){
        return true;
    }

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL){
        if(visited[temp] == true){
            return true;
        }

        visited[temp] = true
        temp = temp -> next;
    }

    return false;

    

}




// -------------------------------------------------- Check circular Linked list ------------------------------------------------------------








// -------------------------------------------------- Reverse a Doubly Linked List ------------------------------------------------------------

//APPROACH 1 ----------------------------
// Node* reverseD(Node* head){

//     Node* curr = head;
//     Node* prev = NULL;
//     Node* forward = NULL;

//     while(curr!=NULL){

//         forward = curr -> next;
//         curr -> next = prev;
//         curr -> prev = forward;
//         prev = curr;
//         curr = forward  

//     }

//     return prev;

// }



//APPROACH 1 -----------------------
// Node* reverse(Node* head){
//     while(head!=null || head -> next == NULL){
//         return head;
//     }

//     Node* chottaHead = reverse(head -> next);

//     head -> next -> next = head;
//     head -> prev = head -> next;

//     return chottaHead;
// }

// Node* reverseD(Node* head){

//     head = reverse(head);

// }



// -------------------------------------------------- Reverse a Doubly Linked List ------------------------------------------------------------



// -------------------------------------------------- Detect Cycle in a LL ------------------------------------------------------------

// bool floydDetect(Node* head){

//     if(head == NULL){
//         return false;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     while(fast!=NULL && fast -> next != NULL){
//         fast  = fast -> next;
//         slow  = slow -> next;

//         if(fast == slow ){
//             return true;
//         }
//     }

//     return false;
 

// }


//Appraoch 2

// bool floydDetect(Node* head){

//     if(head == NULL){
//         return false;
//     }

//     map<Node* , bool> visited;

//     Node* temp = head;

//     while(temp!=NULL){
//         if(visited[temp] == true){
//             return true;
//         }

//         visited[temp] = true;

//         temp = temp -> next;
//     }

//     return false;
// }

// -------------------------------------------------- Detect Cycle in a LL ------------------------------------------------------------




// -------------------------------------------------- Starting Node of LL ------------------------------------------------------------
// Node* floydDetect(Node* head){

//     if(head == NULL){
//         return NULL;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     while(fast!=NULL && fast -> next != NULL){
//         fast  = fast -> next;
//         slow  = slow -> next;

//         if(fast == slow ){
//             return slow;
//         }
//     }

//     return NULL;
 

// }
// Node* startNode(Node* head){

//     if(head == NULL){
//         return NULL;
//     }

//     Node* intersection = floydDetect(head);

//     Node * slow = head;


//     while(slow!=intersection){
//         slow = slow -> next;
//         intersection = intersection -> next;
//     }

//     return slow;


// }



// -------------------------------------------------- Starting Node of LL ------------------------------------------------------------




// -------------------------------------------------- Remove Loop of LL ------------------------------------------------------------




// Node* floydDetect(Node* head){

//     if(head == NULL){
//         return NULL;
//     }

//     Node* slow = head;
//     Node* fast = head;

//     while(fast!=NULL && fast -> next != NULL){
//         fast  = fast -> next;
//         slow  = slow -> next;

//         if(fast == slow ){
//             return slow;
//         }
//     }

//     return NULL;
 

// }

// Node* startNode(Node* head){

//     if(head == NULL){
//         return NULL;
//     }

//     Node* intersection = floydDetect(head);

//     Node * slow = head;


//     while(slow!=intersection){
//         slow = slow -> next;
//         intersection = intersection -> next;
//     }

//     return slow;


// }

// void removeLoop(Node* head){

//     if(head == NULL){
//         return;
//     }

//     Node* startOfLoop = startNode(head);

//     if(startOfLoop == NULL){
//         return;
//     }

//     Node* temp = head;
//     while(temp -> next !=startOfLoop){
//         temp = temp -> next;
//     }

//     temp -> next = NULL;

// }

// -------------------------------------------------- Remove Loop of LL ------------------------------------------------------------




// -------------------------------------------------- Remove Duplicates from  a sorted LL ------------------------------------------------------------

// Node* removeDuplicate(Node* head){

//     Node* curr = head;

//     while(curr != NULL){

//         if( curr -> next !=NULL && curr -> next -> data == curr -> data){
            
//             Node* forward = curr -> next -> next;
//             Node* nodeToDelete = curr -> next;
//             delete nodeToDelete;

//             curr -> next = forward;


//         }else{
//             cur = curr -> next;
//         }
        
//     }

//     return head;


// }


//APPROACH 2-----------------------------


// Node* removeDuplicate(Node* head){

//     Node* curr = head;

//     unordered_map(Node*, bool) visited;

//     while(curr!=NULL){
//         if(curr->next!=NULL && [curr -> next] == true){

//             Node* forward = curr -> next -> next;
//             Node* nodeToDel = curr -> next;
//             delete nodeToDel;

//             curr -> next = forward;

//         }

        
//     }
// }



// -------------------------------------------------- Remove Duplicates from  a sorted LL ------------------------------------------------------------






// -------------------------------------------------- Remove Duplicates from  a unsorted LL ------------------------------------------------------------


//APPROACH 1 ---------------------------------------------
// Node* removeDuplicates(Node* head){

//     Node* curr = head;

//     while(curr !=NULL){

//         Node* temp = curr;

//         while(temp!=NULL){

//             if(temp->next !=NULL && temp->next->data == curr -> data){

//                 Node* forward = temp -> next -> next;
//                 Node* nodeToDelete = temp -> next;
//                 delete nodeToDelete;
//                 temp -> next = forward;

//             }else{
//                 temp = temp -> next;
//             }

//         }

//         curr = curr -> next;
//     }

//     return head;
// }

//APPROACH 2 ---------------------------------------------

// Node* removeDuplicates(Node* head){

//     if(head == NULL){
//         return head;
//     }

//     unordered_map<Node* , bool> visited;

//     Node* temp = head;
//     Node* prev = NULL;

//     while(temp!=NULL){

//         if(visited[temp->data] == true){

//             Node* forward = temp -> next;
//             Node* nodeToDelete = temp;
//             delete nodeToDelete;
//             prev -> next = forward;

//             temp = forward;

//         }

//         visited[temp->data] = true;

//         prev = temp;
//         temp = temp -> next;
//     }

//     return head;
// }

// -------------------------------------------------- Remove Duplicates from  a unsorted LL ------------------------------------------------------------



// -------------------------------------------------- Sort 0 ,1, 2 in a linked list ------------------------------------------------------------


// Node* sort(Node* head){
//     if(head == NULL){
//         return head;
//     }

//     int zero = 0;
//     int one = 0;
//     int two = 0;

//     Node* temp = head;

//     while(temp!=NULL){

//         if(temp -> data == 0){
//             zero++;
//         }else if(temp -> data == 1){
//             one++;
//         }else{
//             two++;
//         }

//         temp = temp -> next;

//     }

//     temp = head;

//     while(temp!=NULL){

//         if(zero!=0){
//             temp -> data = 0;
//             zero--;
//         }else if(one!=0){
//             temp -> data = 1;
//             one--;
//         }else{
//             temp -> data = 2;
//             two--;
//     }

//         temp = temp -> next;

//     }

//     return head;
// }

//APPROACH 2 -------------------------------------

// void insertAtTail(Node* &tail, int d){

//     Node* temp = new Node(d);

//     tail -> next= temp;
//     tail = temp;


// }

// Node* sort(Node* head){

//     if(head == NULL)
//         return head;

//     Node* zeroHead = new Node(-1);
//     Node* zeroTail = zeroHead;

//     Node* oneHead = new Node(-1);
//     Node* oneTail = oneHead;

//     Node* twoHead = new Node(-1);
//     Node* twoTail = twoHead;

//     Node* temp = head;

//     while(temp!=NULL){

//         int value = temp -> data;

//         if(value == 0){
//             insertAtTail(zeroTail ,0);
//         }else if(value == 1){
//             insertAtTail(oneTail ,1);
//         }else{
//             insertAtTail(twoTail ,2);
//         }

//         temp = temp -> next;
//     }

//     //merge
//     if(oneHead-> next !=NULL){
//         zeroTail -> next = oneHead -> next;
//     }else{
//         zeroTail -> next = twoHead -> next;

//     }

//     oneTail -> next = twoHead -> next;
//     twoTail -> next = NULL;

//     head = zeroHead -> next;

        // delete oneHead;
        // delete twoHead;

//     return head;

// }


// -------------------------------------------------- Sort 0 ,1, 2 in a linked list ------------------------------------------------------------






// -------------------------------------------------- Merge 2 sorted linked list ------------------------------------------------------------

// Node *merge(Node* first, Node* second){

//     if(first -> next  == NULL){
//         first -> next = second;
//         return first;
//     }

//     Node* curr = first -> next;
//     Node* prev = first;

//     Node* temp = second;
//     Node* forward = temp->next;

//     while(temp!=NULL && curr!=NULL){
//         if(temp -> data >= prev -> data && temp->data <= curr -> data){

//             Node* forward = temp -> next;
//             prev = temp;

//         }else{
//             prev= curr;
//             curr = curr->next;

//             if(curr == NULL){
//                 prev -> next = temp;
//                 return first;
//             }
//         }
//     }
//     return first;


// }




// Node* merge2Lists(Node* first, Node* second){

//     if(first == NULL){
//         return second;
//     }

//     if(second == NULL){
//         return first;
//     }

//     if(first -> data <= second -> data){
//         return merge(first, second);
//     }else{
//         return merge(second, first);
//     }
// -------------------------------------------------- Merge 2 sorted linked list ------------------------------------------------------------


// -------------------------------------------------- Check palindrome in a LL ------------------------------------------------------------

//APPROACH 1 ------------------------

// bool solve(vector<int> arr){

//     int start = 0;
//     int end = arr.size()-1;

//     while(start<=end){
//         if(arr[start] !=arr[end]){
//             return false;
//         }
//         start++;
//         end--;
//     }

//     return true;

// }


// bool checkPalindrome(Node* head){

//     if(head == NULL){
//         return false;
//     }

//     vector<int> ans;

//     while(head !=NULL){
//         ans.push_back(head -> data);
//         head = head -> next;
//     }

//     return solve(ans);

// }

//APPROACH 2 -----------------------------------------

// Node* checkPalindrome(Node * head){

//     if(head -> next == NULL){
//         return true;
//     }

//     Node* middle = getMid(head);

//     Node* temp = middle -> next;
//     middle -> next = reverse(temp);


//     Node* head1 = head;
//     Node* head2 = middle -> next;

//     while(head2!=NULL){

//         if(head2-> data != head1->data){
//                 return false;
//         }

//         head1 = head1 -> next;
//         head2 = head2 -> next;

//     }

//     temp = middle -> next;
//     middle -> next = reverse(temp);

//     reverse true;
// }



// -------------------------------------------------- Check palindrome in a LL ------------------------------------------------------------




// -------------------------------------------------- Add 2 no represented as linked list ------------------------------------------------------------


Node* add(Node* head1, Node* head2){

    int sum1=0;
    // int i=0;
    Node* temp = head1;
    while(temp!=NULL){
        sum1 = sum1 * 10 + temp->data;
        temp = temp -> next;
        i++;
    }


    int sum2=0;
    temp = head2;

    while(temp!=NULL){

        sum2 = sum2*10+temp->data;
        temp = temp -> next;
        i++;

    }

    int ans = sum1+sum2;

    Node* final = new Node(-1);

    while(ans>0){

        insertAtTail(ans%10);
        ans = ans/10;

    }

    final = reverse(final);

    return final->next;




}







// -------------------------------------------------- Add 2 no represented as linked list ------------------------------------------------------------

void insertAtTail(Node* &head, Node* tail, int d){

    Node* temp = new Node(d);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }else{
        tail-> next = temp;
        tail = temp;

    }


}


Node* add(Node* first, Node* second){

    int carry=0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(first!=NULL || second!=NULL || carry!=0){

        int val1;
        if(first!=NULL){
            val1 = first -> data;
        }

        int val2;
        if(second!=NULL){
            val2 = second -> data;
        }

        int sum = val1+val2+carry;
        int digit = sum%10;

        insertAtTail(ansHead,ansTail,digit);

        carry = sum/10;

        
        if(first!=NULL)
            first=first -> next;
                
        if(second!=NULL)
            second = second ->next;

    }

    return ansHead;





    // while(first!=NULL && second!-NULL){

    //     int sum = first->data + second->data + carry;
    //     int digit = sum%10;

    //     insertAtTail(ansHead, ansTail, digit);

    //     carry = sum/10;
        
    //     first = first -> next;
    //     second = second -> next;

    // }

    // while(first!=NULL){
    //     int sum = first->data + carry;
    //     int digit = sum%10;

    //     insertAtTail(ansHead, ansTail, digit);

    //     carry = sum/10;
        
    //     first = first -> next;
        
    // }

    // while(second!=NULL){
    //     int sum = second->data + carry;
    //     int digit = sum%10;

    //     insertAtTail(ansHead, ansTail, digit);

    //     carry = sum/10;
        
    //     second = second -> next;
    // }

    // while(carry!=NULL){
    //     int sum = carry;
    //     int digit = sum%10;

    //     insertAtTail(ansHead, ansTail, digit);

    //     carry = sum/10;

    // }

    // return ansHeadl

}





Node* add(Node* first, Node* second){


    first = reverse(first);
    second = reverse(second);

    Node* ans = add(first, second);

    ans = reverse(ans);
    return ans;

    


}


// -------------------------------------------------- Add 2 no represented as linked list ------------------------------------------------------------




// -------------------------------------------------- Clone a  linked list with random pointer------------------------------------------------------------

//APPROACH 1 using map

// Node* copyList(Node* head){

//     Node* cloneHead = NULL;
//     Node* cloneTail = NULL;

//     Node* temp = head;;

//     while(temp){
//         insertAtTail(cloneHead, cloneTail, temp -> data);
//         temp = temp -> next;
//     }

//     Node* originalNode = head;
//     Node* cloneNode = cloneHead;

//     unordered_map<Node* , Node*> oldToNew;

//     while(originalNode!=NULL){

//         oldToNew[originalNode] = cloneNode;

//         originalNode =  originalNode-> next;
//         cloneNode =  cloneNode-> next;

//     }

//     originalNode = head;
//     cloneNode = cloneHead;

//     while(originalNode!=NULL){
//         cloneNode -> random = oldToNew[originalNode-> random];
//         originalNode =  originalNode-> next;
//         cloneNode =  cloneNode-> next;
        
//     }

//     return cloneHead;

// }


// ---------------OPTIMISED APPROACH---------------------------------------

Node* copyList(Node* head){

    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;;

    while(temp){
        insertAtTail(cloneHead, cloneTail, temp -> data);
        temp = temp -> next;
    }

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    Node* forward = NULL;

    while(cloneNode!= NULL && originalNode!=NULL){

        forward = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = forward;

        forward = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = forward;

    }

    Node* temp = head;

    while(temp){
        if(temp->next!=NULL){
                if(temp->random!=NULL){

                    temp -> next -> random = temp -> random -> next;
                }else{
                    temp ->next = temp -> random;
                }
                 
            }
            // incrementing temp 2 times as next node in original is after the clone node
            temp = temp -> next -> next;
    }

    return cloneHead;

}





// -------------------------------------------------- Clone a  linked list with random pointer------------------------------------------------------------

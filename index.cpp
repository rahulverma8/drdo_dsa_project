#include <iostream>
#include <cstdlib>
// #include<graphics.h>
using namespace std;

class myArrayStack{
    public:
    int len;
    int *arr;
    int top;
      myArrayStack(int len){
      this->len = len;
      arr = new int[len];   
      top = -1;
          
  }
    void push(){
         
        if(top >= len-1){
            cout << "STACK OVERFLOW\n" << endl;
            return;
        }
        cout << "ENTER AN ENTRY\n" ;
        int num;
        cin >> num ;
        top++;
        arr[top] = num ;
        printStack();
    }
    void pop(){
         
        if(top < 0){
            cout << "STACK UNDERFLOW\n" ;
            return;
        }
        cout << arr[top] << " POPPED\n" ;
        top--;
        printStack();
    }
    void printStack(){
        for(int i=top;i>=0;i--)
            cout << "| "<< arr[i] << " |\n" ;
        cout << endl ;
    }
    void returnTop(){
          cout << flush;
        if(top>=0)
            cout << "TOP OF STACK IS : "<< arr[top]<< endl ;
        else
            cout << "STACK IS EMPTY\n";
    }
    void isEmpty(){
         
        if(top<0)
            cout << "STACK IS EMPTY\n";
        else
            cout << "STACK IS NOT EMPTY\n";
    }
};

class DEque{  
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    DEque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check full or not
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } 
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        else
        {
             rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
         if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear--;
        }
        return ans;
    }
    void display(){
     
    int i=front;    
    cout << "ELEMENTS OF THE DEQUE ARE : \n";    
        
    while(i!=rear)    
    {    
        cout << arr[i] << " | ";
        i=(i+1)%size;    
    }    
     cout << arr[rear] << endl ;  
} 

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
       if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
    if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
            return true;
        }
        else
        {
            return false;
        }
    }
    
};

class Queue {
    
    int* arr;
    int qfront;
    int rear; 
    int size;
    
public:
    Queue(int len) {
        size = len;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        if(qfront == rear) 
            return true;
        else
            return false;
    }

    void enqueue() {
        
        if(rear == size){
            cout << "QUEUE IS FULL" << endl;}
        else
        {
            cout << "ENTER A VALUE TO INSERT IN THE QUEUE\n";
            int data;
            cin >> data ;            
            arr[rear] = data;
            rear++;
            cout << data << " ENQUEUED\n" ;
            display();
        }
    }

    void dequeue() {
        if(qfront == rear) 
            cout << "QUEUE IS EMPTY\n";
        else
        {  int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
         cout << ans <<" DEQUEUED FROM THE QUEUE\n" ;
         display();
        }
    }
    void display() {
   if (qfront == - 1)
        cout << "QUEUE IS EMPTY\n";
   else {
      cout<<"\n| ";
      for (int i = qfront; i < rear; i++)
      cout<<arr[i]<<" | ";
         cout<<endl;
   }
}

    void front() {
        if(qfront == rear)
            cout << "QUEUE IS EMPTY\n";
        else
            cout << "FRONT OF THE QUEUE IS : "<< arr[qfront]<< endl;
        
    }
};

class NodeLL
{
public:
    int data;
    NodeLL *next;
    NodeLL(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// head
NodeLL *head = NULL;

class oneAnswer{
  public:

//              DE-queue
void deque_using_array_options(DEque *d){
      
    cout << "\nENTER A VALUE : \n" ;
    //USE LOOP
    
    cout << "1. Insert At Front" << endl;
    cout << "2. Insert At Rear" << endl;
    cout << "3. Delete from Front" << endl;
    cout << "4. Delete from Rear" << endl;
    cout << "5. Diplay Deque"<<endl;
    cout << "6. Display Front element" << endl;
    cout << "7. Display Rear element" << endl;
    cout << "8. Check if Deque is Empty" << endl;
    cout << "9. BACK" << endl << endl;
    cout << "0. EXIT" << endl << endl;
    
    int num;
    cin >> num ;
    int val,elem;
    
    switch(num){
        case 1 :{
            cout << "ENTER A VALUE\n" ;
            cin >> val;
            
            if(d->pushFront(val))
                cout << val << " INSERTED AT FRONT\n";
            else cout << "CANNOT INSERT NUMBER\n" ;
            deque_using_array_options(d);
            break;}
        case 2:{
            cout << "ENTER A VALUE\n" ;
            cin >> val;
            
            if(d->pushRear(val))
                cout << val << " INSERTED AT REAR\n";
            else cout << "CANNOT INSERT NUMBER\n" ;
            
            deque_using_array_options(d);
            break;}
        case 3:{
            elem = d->popFront();
            if(elem == -1)
                cout << "DEQUE IS EMPTY\n";
            else cout <<elem << " is popped from front\n";
            //take input also |||
            deque_using_array_options(d);
            break;}
        case 4:{
            elem = d->popRear();
            if(elem == -1)
                cout << "DEQUE IS EMPTY\n";
            else cout << "Element with value "<< elem << " is popped from Rear\n";
            deque_using_array_options(d);
            break;}
        case 5:{
            d->display();
            cout << endl;
            deque_using_array_options(d);
            break;
        }
        case 6:{
            elem = d->getFront();
            if(elem == -1)
                cout << "DEQUE IS EMPTY\n";
            else cout << "Front element of the deque is : "<< elem << endl;
            deque_using_array_options(d);
            break;}
        case 7:{
            elem = d->getRear();
            if(elem == -1)
                cout << "DEQUE IS EMPTY\n";
            else cout << "Rear element of the deque is : "<< elem << endl;
            deque_using_array_options(d);
            break;}
        case 8:{
            if(d->isEmpty()) cout << "DEQUE IS EMPTY\n";
            else cout << "Deque is Not Empty\n";
            deque_using_array_options(d);
            break;}
        case 9:{
            delete d;
            d = nullptr;
            group2_options() ;
            break;
        }
//         case 8:{
//             if(d.isFull()) cout << "Deque is Full\n";
//             else cout << "Deque is not Full\n";
//             deque_using_array_options(d);
//             break;}
        case 0:
            cout << "EXIT EXECUTED\n";
            exit(0);
        default:{
            cout << "INVALID ENTRY\n" ;
            deque_using_array_options(d);
            break; }
    }
//     cout << s.stack_using_array() <<endl;
    
}
void deque_using_array(){
      
    cout << "Enter the Size of the DEque\n";
    int len;
    cin >> len;
    DEque *d = new DEque(len);

    cout << "Double-Ended-Queue created of length : "<< len << endl;
    deque_using_array_options(d);
}

//              DE-queue ENDS
    
//              QUEUE  
void print_queue(NodeLL *&head){
     
    NodeLL *n = head;
    cout << "| ";
    while (n != NULL)
    {
        cout << n->data << " | ";
        n = n->next;
    }
}
void dequeue(){
    delete_from_front(head);
}
void enqueue(){
     
    add_to_last(head);
}
void queue_using_ll(){
      
    cout <<endl<< "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Diplay Queue" << endl;
    cout << "4. display front of queue" << endl;
    cout << "5. Check for Empty" << endl;
    cout << "6. BACK" << endl;
    cout << "0. EXIT" << endl << endl;

    int num;
    cin >> num;

    switch (num)
    {
    case 1:
        enqueue();
        print_queue(head);
        queue_using_ll();
        break;

    case 2:
        dequeue();
        print_queue(head);
        queue_using_ll();
        break;
    case 3:
        print_queue(head);
        queue_using_ll();
        break;
    case 4:{
      cout << "Front of the queue is : "<< head->data << endl;
      queue_using_ll();
      break;
    }
    case 5:{
      head==NULL ? cout <<"QUEUE EMPTY\n" : cout << "QUEUE NOT EMPTY\n";
      queue_using_ll();
      break;
    }
    case 6:{
            delete_linked_list(head);
            queue_options();
            break;
        }
    case 0:
         cout << "EXIT EXECUTED\n";
         exit(0);
    default:
        cout << "INVALID ENTRY\n" ;
        queue_using_ll();
        break;
    }
}
void queue_using_array_options(Queue *q){
      
    cout << "\nEnter number for operations :\n\n" ;
    //USE LOOP
    
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Diplay Queue" << endl;
    cout << "4. display front of queue" << endl;
    cout << "5. Check for Empty" << endl;
    cout << "6. BACK" << endl;
    cout << "0. EXIT" << endl << endl;
    int num;
    cin >> num ;
    
    switch(num){
        case 1 :{
            q->enqueue();
            queue_using_array_options(q);
            break;}
        case 2:{
            q->dequeue();
            queue_using_array_options(q);
            break;}
        case 3:{
            q->display();
            queue_using_array_options(q);
            break;}
        case 4:{
            q->front();
            queue_using_array_options(q);
            break;}
        case 5:{
            if(q->isEmpty())  cout << "Queue is Empty\n";
            
            else cout << "Queue is Not Empty\n";
            
            queue_using_array_options(q);
            break;}
        case 6:{
            delete q;
            q = nullptr;
            group2_options();
            break;
        }
        case 0:
            cout << "EXIT EXECUTED\n";
            exit(0);
        default:{
            cout << "INVALID ENTRY\n" ;
            queue_using_array_options(q);
            break; }
    }
//     cout << s.stack_using_array() <<endl;
    
}
void queue_using_array(){
      
    cout << "Enter the Size of Queue\n";
    int len;
    cin >> len;
    Queue *q = new Queue(len);
     
    cout << "Queue created of size : "<< len << endl;
    
    queue_using_array_options(q);
}
void queue_options(){
      
    cout << "Enter a number to select an option\n" ;
    cout << "1. Implement using dynamic array\n";
    cout << "2. Implement using Linked List\n";
    cout << "3. BACK\n";
    cout << "0. EXIT\n";
    
    int num;
    cin >> num;
    
    switch(num){
        case 1:
            queue_using_array();
            break;
        case 2:
            queue_using_ll();
            break;
        case 3:
            group2_options();
            break;
        case 0:
            cout << "EXIT EXECUTED\n";
            exit(0);
        default:
            cout << "INVALID ENTRY\n";
            queue_options();
            break;
    }
}
//          QUEUE Ends 

//              GROUP 2
void group2_options()
{
      
    cout << "1. Queue" << endl;
    cout << "2. Deque" << endl;
    cout << "3. B+ Tree" << endl;
    cout << "9. BACK" << endl;
    cout << "0. EXIT" << endl;

    int num;
    cin >> num;

    switch (num)
    {
    case 1:
        queue_options();
        break;
    case 2:
        deque_using_array();
        break;
    case 9:
        menu();
        break;
    default:
        cout << "INVALID ENTRY" << endl;
        group2_options();
        break;
    }
}
//              GROUP 2
//              LINKED LIST

int countNode = 0;

void printList(NodeLL *&head)
    {

        NodeLL *n = head;
        while (n != NULL)
        {
            cout << n->data << "->";
            n = n->next;
        }
    }
    void delete_from_pos(NodeLL *&head){
        if(head==NULL){
            cout << "LIST IS EMPTY\n";
            return;
        }
        

        cout << "Enter position of element to be deleted\n";
        int pos;
        cin >> pos;

        if (pos > countNode)
        {
            cout << "INVALID ENTRY\n" ;
            delete_from_pos(head);
            return;
        }

        countNode--;
        NodeLL *temp = head;

        if (pos == 1)
        {
            head = head->next;
            temp->next = NULL;
            // Delete to be added
            return;
        }
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        NodeLL *tempnext = temp->next;

        temp->next = tempnext->next;
        tempnext->next = NULL;
    }
    void add_to_front(NodeLL *&head)
    {
        countNode++;
        cout << "Enter Number to Insert \n";

        int num;
        cin >> num;

        NodeLL *newNode = new NodeLL(num);

        newNode->next = head;
        head = newNode;
        cout << num << " Added to the Front of list" << endl;
    }

    void add_to_last(NodeLL *&head)
    {
        countNode++;
        cout << "Enter Number to Insert \n";
        if (head == NULL)
        {
        int num;
        cin >> num;

        NodeLL *newNode = new NodeLL(num);

        newNode->next = head;
        head = newNode;
         
        cout << num << " Added at last of the List"<< endl;
            return;
        }
        int num;
        cin >> num;

        NodeLL *newNode = new NodeLL(num);
        NodeLL *temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = NULL;
    }
    void delete_from_front(NodeLL *&head)
    {
        if(head==NULL){
            cout << "EMPTY LIST\n";
            return;
        }
        countNode--;
        NodeLL *temp = head;
        head = head->next;
        delete temp;
    }
    void delete_from_last(NodeLL *&head)
    {
        if(head==NULL){
            cout << "LIST IS EMPTY\n";
            return;
        }
        countNode--;
        NodeLL *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void delete_linked_list(NodeLL* &head){
        if(head==NULL) return ;
        countNode = 0;
        while(head != NULL){
            delete_from_front(head) ;
        }
    }
    void linked_list_options()
    {
        
        cout << "\n1. Insert at front" << endl
             << "2. Insert at last" << endl
             << "3. Delete from front" << endl
             << "4. Delete from last" << endl
             << "5. Delete from position" << endl
             << "6. Display List" << endl
             << "7. BACK" << endl
             << "0. EXIT" << endl
             << endl;

        int num;
        cin >> num;

        switch (num)
        {
        case 1:
        {
            add_to_front(head);
            printList(head);       
            linked_list_options();
        }
        break;
        case 2:
        {
            add_to_last(head);
            printList(head);
            linked_list_options();
            break;
        }
        case 3:
        {
            delete_from_front(head);
            printList(head);
            linked_list_options();
            break;
        }
        case 4:
        {
            delete_from_last(head);
            printList(head);
            linked_list_options();
            break;
        }
        case 5:
        {
            delete_from_pos(head);
            printList(head);
            linked_list_options();
            break;
        }

        case 6:
        {
            if (head == NULL)
            {
                cout << "No values to print" << endl;
            }
            printList(head);
            linked_list_options();
            break;
        }

        case 7:
            delete_linked_list(head);
            group1_options();
            break;

        case 0:
            cout << "EXIT EXECUTED\n";
            exit(0);
            break;

        default:
            cout << "INVALID ENTRY\n";
            linked_list_options();
            break;
        }
    }
    //              LINKED LIST ENDS

    //                  STACK

    void print_stack(NodeLL *&head)
    {
         
        NodeLL *n = head;
        while (n != NULL)
        {
            cout << " | " << n->data << " |" << endl;
            n = n->next;
        }
    }
    void push_stack(NodeLL *&head)
    {
          
        cout << "Enter Number to Insert\n";

        int num;
        cin >> num;

        NodeLL *newNode = new NodeLL(num);

        newNode->next = head;
        head = newNode;
        cout << "You have entered number :" << num << endl;
    }
    void pop_stack(NodeLL *&head)
    {
        NodeLL *temp = head;
        head = head->next;
        delete temp;
    }
    void stack_using_ll()
    {
          
        cout << "\n1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. display" << endl;
        cout << "4. BACK" << endl;
        cout << "0. EXIT" << endl
             << endl;

        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            push_stack(head);
            print_stack(head);
            stack_using_ll();
            break;

        case 2:
            pop_stack(head);
            print_stack(head);
            stack_using_ll();
            break;

        case 3:
            if (head == NULL)
            {
                cout << "No values to print" << endl;
            }
            case 4:{
                delete_linked_list(head);
                stack_options();
                break;
            }
            print_stack(head);
            stack_using_ll();
        default:
            {
        cout << "INVALID ENTRY\n";
        stack_using_ll();
        break;
            }
            
        }
    }

void stack_using_array_options(myArrayStack* s)
{
      
    cout << "Enter number for operations\n";
    // USE LOOP

    cout << "1. push" << endl;
    cout << "2. pop" << endl;
    cout << "3. display" << endl;
    cout << "4. Check for Empty" << endl;
    cout << "5. display Top of stack" << endl;
    cout << "6. BACK" << endl;
    cout << "0. EXIT" << endl;

    int num;
    cin >> num;

    switch (num)
    {
    case 1:
    {
        s->push();
        stack_using_array_options(s);
        break;
    }
    case 2:
    {
        s->pop();
        stack_using_array_options(s);
        break;
    }
    case 3:
    {
        s->printStack();
        stack_using_array_options(s);
        break;
    }
    case 4:
    {
        s->isEmpty();
        stack_using_array_options(s);
        break;
    }
    case 5:
    {
        s->returnTop();
        stack_using_array_options(s);
        break;
    }
    case 6:
    {
        delete s;
        s = nullptr;
        stack_options();
        break;
    }

    case 0:
    {
        cout << "EXIT" << endl;
        exit(0);
    }
    default:
    {
        cout << "INVALID ENTRY\n";
        stack_using_array_options(s);
        break;
    }
    }
}

void stack_using_array()
{
      
    cout << "Enter the Size of Stack Array\n";
    int len;
    cin >> len;
    myArrayStack* s = new myArrayStack(len);

    cout << "Stack created of length : " << len << endl;

    stack_using_array_options(s);
    
}

    void stack_options()
    {
         

        cout << "1. Implement using dynamic Array\n";
        cout << "2. Implement using linked list\n";
        cout << "9. BACK\n";
        cout << "0. EXIT\n";

        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            stack_using_array();
            break;
        case 2:
            stack_using_ll();
            break;
        case 9:
            group1_options();
            break;
        case 0:
            cout << "EXIT EXECUTED\n";
            exit(0);
            break;

        default:
            cout << "INVALID ENTRY\n";
            stack_options();
            break;
        }
    }
    //         STACK ENDS

    void group1_options()
    {
         
         
        cout <<flush ;
        cout << "1. Linked List" << endl;
        cout << "2. Stack" << endl;
        cout << "3. BACK" << endl;
        cout << "0. EXIT" << endl;

        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            linked_list_options();
            break;
        case 2:
            stack_options();
            break;
        case 3:
            menu();
            break;
        case 0:
            cout << "EXIT EXECUTED\n";
            exit(0);

        default:
            cout << "INVALID ENTRY\n"
                 << endl;
                group1_options();
            break;
        }
    }


void menu()
{
    cout << "Select any Number" << endl;
    cout << "1. GROUP_1" << endl;
    cout << "2. GROUP_2" << endl;
    cout << "0. Exit" << endl;
    int choice;

    cin >> choice;

    switch (choice){
    case 1:
        group1_options();
        break;
    case 2:
        group2_options();
        break;
    case 0:
            cout << "EXIT EXECUTED\n";
            exit(0);
        break;

    default:
        cout << "INVALID ENTRY" << endl;
        menu();
        break;
    }
}

    // START FUNCTION
    
};

int main()
{
    oneAnswer one;
    one.menu();

    
}

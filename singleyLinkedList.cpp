# Singley Linked List 
## All operations

```cpp
#include <bits/stdc++.h>
using namespace std;

// Linked List Structure
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

// Insertion -
// 1) At Head
// 2) In Middle -> By Value / By position
// 3) At Tail

// Notes
// &head because we dont want to make a new copy of LL and add a node

// 1)
void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
};

// 2)
void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
    // Same as
    // tail = temp;
}

// 3)
void insertAtPosition(Node *&head, int pos, int dataToAdd, Node *&tail)
{
    // Iterate Till pos
    Node *temp = head;
    int cnt = 1;

    // Starting
    if (pos == 1)
    {
        insertAtHead(head, dataToAdd);
    }
    // Middle
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // If temp->next == NULL then it is the last node
    if (temp->next == NULL)
    {
        insertAtTail(tail, dataToAdd);
    }
    Node *nodeToInsert = new Node(dataToAdd);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Traversing The Linked List
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Deletion
void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// IsCircular
bool isCircularList(Node *head)
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

// Loop detection -> Using Map
bool detectLoop(Node *head)
{

    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

// Loop detection using Floyd Method
Node *floydDetectLoop(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (slow != NULL && fast != NULL)
    {

        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }

        slow = slow->next;

        if (slow == fast)
        {
            cout << "present at " << slow->data << endl;
            return slow;
        }
    }

    return NULL;
}

// Get Starting Node
Node *getStartingNode(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *intersection = floydDetectLoop(head);
    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

// Remove Loop
void removeLoop(Node *head)
{

    if (head == NULL)
        return;

    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}

int main()
{
    // Creation of Node
    Node *node1 = new Node(40);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    // Insertion at Head
    insertAtHead(head, 30);
    print(head);

    insertAtHead(head, 20);
    print(head);

    insertAtHead(head, 10);
    print(head);

    insertAtTail(tail, 50);
    print(head);

    insertAtTail(tail, 60);
    print(head);

    insertAtPosition(head, 3, 100, tail);
    print(head);

    deleteNode(3, head);
    print(head);

    return 0;
}
```

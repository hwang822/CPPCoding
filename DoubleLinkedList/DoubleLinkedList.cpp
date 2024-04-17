// DoubleLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// structure to define a node of the doubly linked list
struct node {

    // part which will store data
    int data;
    // pointer to the previous node
    struct node* prev;
    // pointer to the next node
    struct node* next;

};


// function to add a new node with given data after a given node
void add_after_given_node(node* given_node, int data) {

    // create a new node with given data
    node* new_node = new node();
    new_node->data = data;

    // assign next pointer to next of given node
    new_node->next = given_node->next;

    // assign next pointer of given node to the new node
    given_node->next = new_node;

    // assign previous pointer of new node to the given node
    new_node->prev = given_node;

    // assign the next pointer of the node before the given node to new node
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }

    return;

}


void add_node_test() {

    // we will create a doubly linked list of size 2
    // create a pointer to the head node
    node* head = NULL;

    // create a pointer to end node
    node* end = NULL;

    // create the first node of the doubly linked list
    node* first_node = new node();
    // assign data to the first node
    first_node->data = 5;
    // assign prev pointer to the first node
    first_node->prev = NULL;

    head = first_node;

    // create the second node of the doubly linked list
    node* second_node = new node();
    // assign data to the second node
    second_node->data = 4;
    // assign prev pointer to the second node
    second_node->prev = first_node;
    // assign next pointer to the second node
    second_node->next = NULL;

    // assign this node to first node's next
    first_node->next = second_node;

    node* dumy = head;


    cout << "Double Linked List" << endl;


    while (dumy != NULL) {
        end = dumy;
        cout << dumy->data << " ";
        dumy = dumy->next;
    }

    cout << endl;


    // add a new node after the first node
    add_after_given_node(first_node, 1);

    cout << "add a new node after the first node" << endl;

    while (head != NULL) {
        end = head;
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;

}



// function to delete given node
void delete_given_node(node** head, node* given_node) {

    // if the given node is head node
    if (given_node == (*head)) {
        // change head to next node
        (*head) = given_node->next;
    }

    // set the node before given node to point to node after given node
    given_node->prev->next = given_node->next;

    // given node was last node
    if (given_node->next == NULL) {
        return;
    }

    // set the node after the given node to point to node before given node
    given_node->next->prev = given_node->prev;

    return;
}

void delete_node_test() {
    // we will create a doubly linked list of size 3
    // create a pointer to the head node
    node* head = NULL;

    // create a pointer to end node
    node* end = NULL;

    // create the first node of the doubly linked list
    node* first_node = new node();
    // assign data to the first node
    first_node->data = 5;
    // assign prev pointer to the first node
    first_node->prev = NULL;

    head = first_node;

    // create the second node of the doubly linked list
    node* second_node = new node();
    // assign data to the second node
    second_node->data = 4;
    // assign prev pointer to the second node
    second_node->prev = first_node;
    // assign next pointer to the second node
    second_node->next = NULL;

    // assign this node to first node's next
    first_node->next = second_node;

    // create the third node of the doubly linked list
    node* third_node = new node();
    // assign data to the third node
    third_node->data = 7;
    // assign prev pointer to the third node
    third_node->prev = second_node;
    // assign next pointer to the third node
    third_node->next = NULL;

    // assign this node to second node's next
    second_node->next = third_node;

    node* dumy = head;

    cout << "Double Linked List" << endl;


    while (dumy != NULL) {
        end = dumy;
        cout << dumy->data << " ";
        dumy = dumy->next;
    }

    cout << endl;

    // delete second node
    delete_given_node(&head, second_node);

    // print the list in forward direction
    cout << "delete second node" << endl;
    
    while (head != NULL) {
        end = head;
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;

}

int forwardTavel_Test() {

    // we will create a doubly linked list of size 2

    // create a pointer to the head node
    node* head = NULL;

    // create a pointer to end node
    node* end = NULL;

    // create the first node of the doubly linked list
    node* first_node = new node();
    // assign data to the first node
    first_node->data = 5;
    // assign prev pointer to the first node
    first_node->prev = NULL;

    head = first_node;

    // create the second node of the doubly linked list
    node* second_node = new node();
    // assign data to the second node
    second_node->data = 4;
    // assign prev pointer to the second node
    second_node->prev = first_node;
    // assign next pointer to the second node
    second_node->next = NULL;

    // assign this node to first node's next
    first_node->next = second_node;

    // print the list in forward direction
    cout << "In forward direction:" << endl;

    while (head != NULL) {
        end = head;
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
    return 0;
}

int backwardTavel_Test() {

    // we will create a doubly linked list of size 2

    // create a pointer to the head node
    node* head = NULL;

    // create a pointer to end node
    node* end = NULL;

    // create the first node of the doubly linked list
    node* first_node = new node();
    // assign data to the first node
    first_node->data = 5;
    // assign prev pointer to the first node
    first_node->prev = NULL;

    head = first_node;

    // create the second node of the doubly linked list
    node* second_node = new node();
    // assign data to the second node
    second_node->data = 4;
    // assign prev pointer to the second node
    second_node->prev = first_node;
    // assign next pointer to the second node
    second_node->next = NULL;

    // assign this node to first node's next
    first_node->next = second_node;

    // print the list in backward direction
    cout << "In backward direction:" << endl;

    while (head != NULL)
    {
        end = head;
        head = head->next;
    }

    while (end != NULL) {
        cout << end->data << " ";
        end = end->prev;
    }
    cout << endl;

    return 0;
}



int main()
{

    add_node_test();
    delete_node_test();
    forwardTavel_Test();
    backwardTavel_Test();
}


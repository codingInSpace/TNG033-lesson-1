/*************************************************
* TNG033, F� 5                                   *
* Definition of functions declared in node.h     *
* ************************************************/

#include "list.h"


//Insert n in the beginning of the list L
void insert(List& L, int n)
{
    Node *newNode = new Node;

    newNode->value = n;
    newNode->next = L; //link the new node to the first node of list L
    L = newNode; //update L to point to the new node
}


//Remove the node storing n from list L
//If n is not in the list L then L is not modified
void remove(List& L, int n)
{
    if (!L) //empty list
        return;

    //remove first node of the list
    if (L->value == n )
    {
        Node* node = L; //point to first node
        L = L->next;

        delete node; //delete first node
    }
    else
    {
        Node *ptr = L;  //L is not empty

        //1. Find the node before the node to be removed
        while( (ptr->next != nullptr) && (ptr->next->value != n) )
            ptr = ptr->next;

        if (!ptr->next)  //n not found
            return;

        //2. Remove
        Node *node = ptr->next;

        ptr->next = node->next;
        delete node; //deallocate
    }
}


//Search for a value n in the list
//Return a pointer to the node storing n, if n found
//otherwise, return nullptr
Node* search(List L, int n)
{
    Node *p = L;

    while( (p != nullptr) && (p->value != n) )
        p = p->next;

    //for(p = L; p && (p->value != n); p = p->next) ;

    return p;
}


//overloaded operator<<
ostream& operator<<(ostream& out, const List L)
{

    if (!L)
        cout << "List is empty!!" << endl;
    else
    {
        for(Node *p = L; p; p = p->next)
            out << p->value << "->";

        out << endl;
    }

    return out;
}



//Lesson 1: exercise 3

//Insert n in the end of the list
void insert_last(List& L, int n)
{
    //ADD CODE
}



//Insert n in a sorted list L
//After insertion L should remain sorted
void insert_sorted(List& L, int n)
{
    //ADD CODE
}





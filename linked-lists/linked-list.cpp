#include "linked-list.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
    tail = NULL;
    length = 0;
}

LinkedList::LinkedList(Node* h, Node* t, int l)
{
    head = h;
    tail = t;
    length = l;
}

/**
 * This method takes in a value, and adds it to the tail of the list
 *
 * @param int val
 * @return Node*
 */
Node* LinkedList::addNode(int val)
{
    Node* node = new Node(val);

    return this->addNode(node);
}

Node* LinkedList::addNode(Node* node)
{
    if (!tail)
    {
        head = node;

        tail = node;
    }
    else
    {
        tail->next = node;

        tail = node;
    }

    length++;

    return node;
}

/**
 * This method takes in a value, and adds it to the head of the list
 *
 * @param int val
 * @return void
 */
void LinkedList::insertHead(int val)
{
    Node* node = new Node(val);

    if (!head)
    {
        head = node;

        tail = node;
    }
    else
    {
        node->next = head;

        head = node;
    }
}

/**
 * Takes a node that is not head, or tail of the list
 * Removes the node from the list and ensures list in order
 *
 * @param Node* node
 * @return void
 */
void LinkedList::deleteMiddle(Node* node)
{
    swap(node->next->val, node->val);

    Node* nodeToDelete = node->next;

    if (nodeToDelete == tail) tail = node;

    node->next = nodeToDelete->next;

    nodeToDelete->next = NULL;

    delete(nodeToDelete);
}

void LinkedList::printList()
{
    Node* curr = head;

    while (curr)
    {
        cout << curr->val << " ";

        curr = curr->next;
    }

    cout << endl;
}

int LinkedList::getLength()
{
    return length;
}

Node* LinkedList::getHead()
{
    return head;
}

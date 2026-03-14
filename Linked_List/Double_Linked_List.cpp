#include <iostream>

class Double_Linked_List
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
    };
    Node *head = NULL;
    Node *tail = NULL; // stores last node's address

public:
    void InsertEnd(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->prev = NULL;
            newNode->next = NULL;
            return;
        }
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void PrintForward()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL";
    }

    void PrintReverse()
    {
        Node *temp = tail;
        std::cout << "NULL";
        while (temp != NULL)
        {
            std::cout << " <- " << temp->data;
            tail = tail->prev;
        }
    }

    void AddBegin(int data)
    {
        if (head == NULL)
        {
            std::cout << "List has no members to add in beginning\n";
            return;
        }
        Node *newNode = new Node();
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void InsertPos(int data, int pos)
    {
        Node *newNode = new Node();
        newNode->data = data;
        if (pos == 0)
        {
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
                newNode->next = NULL;
                newNode->prev = NULL;
            }
            else
            {
                newNode->prev = NULL;
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            return;
        }

        Node *temp = head;

        for (int i = 0; (i < pos - 1) && (temp != NULL); i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            std::cout << "Position out of bounds\n";
            delete newNode;
            return;
        }

        if (temp->next == NULL)
        { // if want to insert in end
            newNode->prev = temp;
            newNode->next = NULL;
            temp->next = newNode;
            tail = newNode;
        }
        else
        {
            Node *temp2 = temp->next;
            newNode->prev = temp;
            newNode->next = temp->next;
            temp->next = newNode;
            temp2->prev = newNode;
        }
    }

    void DeleteBegin()
    {
        if (head == NULL)
        { // when there are 0 elements
            std::cout << "There is nothing to delete\n";
            return;
        }

        Node *temp;
        temp = head;
        head = head->next;

        if (head != NULL)
        { // This check is for when there is one element
            head->prev = NULL;
        }

        delete temp;
    }

    void DeleteEnd()
    {
        if (head == NULL)
        { // when there are 0 elements
            std::cout << "There is nothing to delete\n";
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        if (tail != NULL)
        { // check for single element list
            tail->next = NULL;
        }
        else
        {
            head = NULL;
        }
        delete temp;
    }

    void DeletePos(int data)  //Needed to be completed
    {
        if (head == NULL)
        { // when there are 0 elements
            std::cout << "There is nothing to delete\n";
            return;
        }
        Node *temp = head;

        while (temp->data != data)
        {
            temp = temp->next;
        }

        Node *temp2 = temp->next;
        Node *temp1 = temp->prev;
        temp1->next = temp2;
        temp2->prev = temp1;
        delete temp;
    }
};
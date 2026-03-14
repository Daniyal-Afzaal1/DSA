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

        while (temp != NULL)
        {
            std::cout<< temp->data<< " -> " ;
            temp = temp->prev;
        }
        std::cout << "NULL";
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

    void DeletePos(int data)
    {
        if (head == NULL)
        {
            std::cout << "There is nothing to delete\n";
            return;
        }

        Node *temp = head;

        while (temp != NULL && temp->data != data) //temp != NULL, in case data not exists
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            std::cout << "Data not found\n";
            return;
        }

        if (temp == head)
        {
            DeleteBegin();
            return;
        }

        if (temp == tail)
        {
            DeleteEnd();
            return;
        }

        Node *temp1 = temp->prev;
        Node *temp2 = temp->next;

        temp1->next = temp2;
        temp2->prev = temp1;

        delete temp;
    }
};

int main()
{
    Double_Linked_List list;

    
    std::cout << "Inserting at end:\n";

    list.InsertEnd(10);
    list.PrintForward(); std::cout << std::endl;

    list.InsertEnd(20);
    list.PrintForward(); std::cout << std::endl;

    list.InsertEnd(30);
    list.PrintForward(); std::cout << std::endl;

    list.InsertEnd(40);
    list.PrintForward(); std::cout << std::endl;

    std::cout << "Forward: ";
    list.PrintForward();
    std::cout << std::endl;

    std::cout << "Reverse: ";
    list.PrintReverse();
    std::cout << std::endl;

    std::cout << "\nInsert 5 at beginning\n";
    list.AddBegin(5);
    list.PrintForward();
    std::cout << std::endl;

    std::cout << "\nInsert 25 at position 3\n";
    list.InsertPos(25, 3);
    list.PrintForward();
    std::cout << std::endl;

    std::cout << "\nDelete Begin\n";
    list.DeleteBegin();
    list.PrintForward();
    std::cout << std::endl;

    std::cout << "\nDelete End\n";
    list.DeleteEnd();
    list.PrintForward();
    std::cout << std::endl;

    std::cout << "\nDelete data 25\n";
    list.DeletePos(25);
    list.PrintForward();
    std::cout << std::endl;

    return 0;
}
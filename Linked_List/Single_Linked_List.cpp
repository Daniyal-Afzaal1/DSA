#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
    };
    Node *head = NULL;

public:
    void InsertEnd(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        Node *temp = head;

        if (head == NULL)
        { // if list is empty
            head = newNode;
            return;
        }

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode; // make the lastnode point to new nodee
    }

    void InsertBeg(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    void insertAtSpecificPosition(int data, int position)
    {
        Node *newNode = new Node();
        newNode->data = data;

        if (position == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;

        for (int i = 0; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        { // if there are 4 values and we want to insert at 6 position
            std::cout << "Position out of bounds\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void Delete(int position)
    {
        if (head == NULL)
            return;

        Node *temp1 = head;

        if (position == 0)
        {
            head = temp1->next;
            delete (temp1);
            return;
        }

        for (int i = 0; i < position - 1 && temp1 != NULL; i++)
        {
            temp1 = temp1->next;
        }

        if (temp1 == NULL || temp1->next == NULL)
        {
            std::cout << "Position out of bounds\n";
            return;
        }

        Node *temp2 = temp1->next;
        temp1->next = temp2->next;

        delete (temp2);
    }

    void Display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }
};

int main()
{
    LinkedList list;

    list.InsertEnd(10);
    list.InsertEnd(20);
    list.InsertEnd(30);

    std::cout << "After Inserting 3 elements:\n";
    list.Display();

    list.InsertBeg(5);

    std::cout << "After Inserting at Beginning:\n";
    list.Display();

    list.insertAtSpecificPosition(15, 2);

    std::cout << "After inserting 15 at position 2:\n";
    list.Display();

    list.Delete(3);

    std::cout << "After deleting position 3:\n";
    list.Display();

    return 0;
}
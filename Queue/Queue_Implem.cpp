#include <iostream>

class queue
{
private:
    int Front = -1;
    int Rear = -1;
    int Maxsize;
    int *arr;

public:
    queue(int size)
    {
        this->Maxsize = size;
        arr = new int[size];
    }

    ~queue()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (Rear == Maxsize - 1)
        {
            std::cout << "Overflow!\n";
            return;
        }
        if (Front == -1)
        {
            Front = 0;
        }
        Rear++;
        arr[Rear] = value;
    }

    void pop()
    {
        if (Front == -1)
        {
            std::cout << "Queue is Empty\n";
            return;
        }
        if (Front == Rear)
        {
            Front = Rear = -1;
        }
        else
        {
            Front++;
        }
    }

    int size()
    {
        if (Front == -1)
            return 0;
        return Rear - Front + 1; // for the case when we start popping
    }

    int front()
    {
        if (Front == -1)
        {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        return arr[Front];
    }

    int back()
    {
        if (Rear == -1)
        {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        return arr[Rear];
    }

    bool isEmpty()
    {
        return Front == -1;
    }
};

int main()
{
    queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6); //overflow

    std::cout << "Size: " << q.size() << "\n";

    q.pop();
    q.pop();
    q.pop();

    std::cout << "Size: " << q.size() << "\n";
    std::cout << "Front Value: " << q.front() << "\n";
    std::cout << "Rear Value: " << q.back() << "\n";
    std::cout << "Is Empty: " << q.isEmpty() << "\n";

    q.pop();
    q.pop();

    std::cout << "Size After deleting all: " << q.size() << "\n";

    q.push(1);
    q.push(2);

    std::cout<<"Size after adding: "<<q.size()<<"\n";

    return 0;
}
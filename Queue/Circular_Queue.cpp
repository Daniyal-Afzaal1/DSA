#include <iostream>

class Circular_Queue
{
private:
    int Front = -1;
    int rear = -1;
    int MaxSize;
    int *arr;

public:
    Circular_Queue(int size)
    {
        this->MaxSize = size;
        arr = new int[size];
    }

    ~Circular_Queue()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if ((Front == 0 && rear == MaxSize - 1) || (Front == rear + 1))
        {
            std::cout << "Queue Overflow\n";
            return;
        }
        if (Front == -1)
        {
            Front = 0;
            rear = 0;
        }
        else if (rear == MaxSize - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
    }

    void pop()
    {
        if (Front == -1)
        {
            std::cout << "Circular Queue is Empty\n";
            return;
        }
        else
        {
            if (Front == rear)
            {
                Front = -1;
                rear = -1;
            }
            else if (Front == MaxSize - 1)
            {
                Front = 0;
            }
            else
            {
                Front++;
            }
        }
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
        if (rear == -1)
        {
            std::cout << "Queue is Empty\n";
            return -1;
        }
        return arr[rear];
    }

    int size()
    {
        if (Front == -1)
            return 0;

        if (rear >= Front)
            return rear - Front + 1;

        return MaxSize - Front + rear + 1; // when rear is before front
    }

    bool isEmpty()
    {
        return Front == -1;
    }
};

int main()
{
    Circular_Queue q(5);

    std::cout << "Pushing elements\n";
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    std::cout << "Front: " << q.front() << "\n";
    std::cout << "Back: " << q.back() << "\n";
    std::cout << "Size: " << q.size() << "\n";

    std::cout << "\nPopping two elements\n";
    q.pop();
    q.pop();

    std::cout << "Front: " << q.front() << "\n";
    std::cout << "Back: " << q.back() << "\n";
    std::cout << "Size: " << q.size() << "\n";

    std::cout << "\nAdding elements again (testing circular behavior)\n";
    q.push(60);
    q.push(70);

    std::cout << "Front: " << q.front() << "\n";
    std::cout << "Back: " << q.back() << "\n";
    std::cout << "Size: " << q.size() << "\n";

    std::cout << "Queue empty: " << q.isEmpty() << "\n";

    return 0;
}
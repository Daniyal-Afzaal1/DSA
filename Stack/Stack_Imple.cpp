#include <iostream>

class stack
{
private:
    int topIndx = -1;
    int MaxSize;
    int *arr;

public:
    stack(int size)
    {
        this->MaxSize = size;
        arr = new int[size];
    }

    ~stack()
    {
        delete[] arr;
    }

    void push(int value)
    {
        if (topIndx == MaxSize - 1)
        {
            std::cout << "stack overflow!\n";
            return;
        }
        topIndx++;
        arr[topIndx] = value;
    }

    void pop()
    {
        if (topIndx == -1)
        {
            std::cout << "stack is empty!\n";
            return;
        }
        topIndx--;
    }

    int top()
    {
        if (topIndx == -1)
        {
            std::cout << "stack is empty!\n";
            return -1;
        }
        return arr[topIndx];
    }

    int size()
    {
        return topIndx + 1;
    }

    int Empty()
    {
        if (topIndx == -1)
        {
            return 1;
        }
        return 0;
    }
};

int main(){
    stack s1(3);

    s1.pop();             //empty
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);          //overflow

    std::cout<<"Top Value"<<s1.top()<<"\n";
    std::cout<<"Empty or Not: "<<s1.Empty()<<"\n";
    std::cout<<"Total Elements: "<<s1.size()<<"\n";
    
    s1.pop();           //removes 3
    std::cout<<"Top Value: "<<s1.top()<<"\n";
}
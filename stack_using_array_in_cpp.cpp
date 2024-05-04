#include <iostream>

using namespace std;

class stack
{
    int size, index, *arr;

    public:
        stack()
        {
            index = -1;
        }

        void stack_init(int size)
        {
            this->size = size;
        }

        void push(int data)
        {
            if (index == size -1)
            {
                cout << "\nError! Cannot add elements as the stack is full!\n";
            }
            else
            {
                index++;
                arr[index] = data;
            }
        }

        void pop()
        {
            if(index < 0)
            {
                cout << "\nError! Stack is empty! No elements to pop!";
            }
            else
            {
                index--;
            }
        }

        void getdata()
        {
            for (int i = 0; i <= index; i++)
            {
                cout << arr[i] << "\n";
            }
        }

        ~stack();
};

int main()
{
    stack *s = new stack;
    s->stack_init(5);

    s->push(0);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);

    cout << "before popping:\n";
    s->getdata();

    s->pop();
    s->pop();

    cout << "After popping:\n";
    s->getdata();
    
    return 0;
}

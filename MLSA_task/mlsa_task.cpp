#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~node() {}
};

class Q
{
public:
    node* front;
    node* rear;

    Q()
    {
        front = rear = NULL;
    }
    ~Q() {}

    void enqueue(int val)
    {
        node* temp = new node(val);

        if (front == NULL && rear == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            // node *ptr = rear;
            // while (ptr->next != NULL)
            //{
            //     ptr = ptr->next;
            // }
            // ptr->next = temp;

            rear->next = temp;  // storing new temp at tail next
            rear = rear->next;  // putting rare at end
            rear->next = front; // storing the address of front in the next of the tail

            // rear = temp;
        }
    }


    void dequeue()
    {
        if (front == NULL || rear == NULL)
        {
            cout << "Queue is empty Mr Tariq," << endl;
        }
        else
        {
            // node *ptr = front;
            rear->next = front->next; // moving the front in the rear when dequeing
            front = front->next;      // also moving the front to forward
            // ptr = NULL;
            // delete ptr;
        }
    }

    void display()
    {
        node* ptr = front;
        while (ptr->next != front)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << ptr->data << endl;
    }
};

int main()
{
    Q q1;

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);

    q1.display();

    q1.dequeue();
    q1.display();
}

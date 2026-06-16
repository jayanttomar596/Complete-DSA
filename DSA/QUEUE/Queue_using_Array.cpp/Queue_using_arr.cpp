#include <iostream>
using namespace std;


class Queue 
{
    int *arr ;
    int front ;
    int rear ;
    int size ;

public :
    Queue()
    {
        size = 100001 ;
        arr = new int[size] ;
        front = 0 ;
        rear = 0 ;
    }    


    bool isEmpty()
    {
        if(front == rear)
        {
            return true ;
        }
        else
        {
            return false ;
        }
    }


    void enqueue(int data)
    {
        if (rear == size)
        {
            cout << "Queue is FULL "<< endl;
        }
        else
        {
            arr[rear] = data ;
            rear++ ;
        }
    }


    int dequeue()
    {
        if (front == rear)
        {
            return -1 ;
        }
        else
        {
            int ans = arr[front] ;
            arr[front] = -1 ;
            front++ ;
            if (front == rear)
            {
                front = 0 ;
                rear = 0 ;
            }

            return ans ;
        }
    }


    int queue_front()
    {
        if(front == rear)
        {
            return -1 ;
        }
        else
        {
            return arr[front];
        }
    }
};



int main() {

    Queue queue ;

    queue.enqueue(1) ;
    queue.enqueue(2) ;
    queue.enqueue(3) ;
    queue.enqueue(4) ;
    queue.enqueue(5) ;
    
    cout << queue.queue_front() << endl; 
    queue.dequeue() ;
    cout << queue.queue_front() << endl; 
    cout << "Is Empty : " << queue.isEmpty() << endl;

    return 0;
}
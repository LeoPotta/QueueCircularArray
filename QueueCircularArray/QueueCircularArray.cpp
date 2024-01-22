#include <iostream>
#include<cassert>
using namespace std;
template<class t>
class ArrayQueueType
{
    int rear;  //represent the last value entered
    int front;  //represent the first value entered 
    int length;  //represent how much there are values in the queue
    t* arr;       //array for the queue values 
    int maxSize;  //represent the capacity for the array
public:
    ArrayQueueType(int size)
    {
        if (size <= 0) maxSize = 100; //should be at least 1 space in array
        else maxSize = size;
        front = 0; 
        rear = maxSize - 1;
        length = 0;
        arr = new t[maxSize];
    }
    bool isEmpty() { return length = 0; }
    bool isFull() { return length == maxSize; }

    void addQueue(t element)
    {
        if (isFull()) { cout << " addQueue() : Queue is Full , Cant enqueue! "; }
        else {
            rear = (rear + 1) % maxSize;
            arr[rear] = element;
            length++;
        }
    }
    void deleteQueue()
    {
        if (isEmpty()) { cout << " deleteQueue() : Queue is Empty , Cant DeQueue! "; }
        else
        {
            front = (front + 1) % maxSize;
            length--;
        }
    }
    int frontQueue()
    {
        assert(!isEmpty()); //to make sure queue is NOT empty , if is empty will throw exception
        return arr[front];  //returns the item in this index where front pointing on
    }
    int rearQueue()
    {
        assert(!isEmpty()); //to make sure queue is NOT empty , if is empty will throw exception
        return arr[rear]; //returns the item in this index where rear pointing on
    }
    void print() 
    {
        if(!isEmpty())
        {
            for (int i = front;i != rear;i = (i + 1) % maxSize)
            {
                cout << arr[i]<<" ";
            }
            cout << arr[rear];
        }
        else
        {
            cout << " print() : Queue is Empty ";
        }
    }
    int QueueSearch(t element)
    {
        int pos=-1;
        for(int i=front ; i!=rear ; i=(i+1)%maxSize )
        {
            if (arr[i] == element) 
            {
                pos = i;
                break;
            }
            if(pos == -1)
            {
                if (arr[rear] == element)
                    pos = rear;
            }
            else
            {
                cout << " Queue is Empty ";
            }
            
        }return pos;
    }

};
int main()
{
    ArrayQueueType <int> s(5);
    s.addQueue(10);
    s.addQueue(20);
    s.addQueue(30);
    s.addQueue(40);
    s.deleteQueue(); // 10 will be deleted , because first in first out
    //s.print();
    //cout << s.frontQueue();
    cout<<s.QueueSearch(50);
}

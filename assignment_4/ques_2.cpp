#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)); }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL\n"; return;
        }
        if (front == -1) front = rear = 0;
        else if (rear == SIZE - 1 && front != 0) rear = 0;
        else rear++;

        arr[rear] = x;
        cout << x << " enqueued\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue is EMPTY\n"; return; }
        cout << arr[front] << " dequeued\n";
        if (front == rear) front = rear = -1;
        else if (front == SIZE - 1) front = 0;
        else front++;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is EMPTY\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) { cout << "Queue is EMPTY\n"; return; }
        cout << "Queue: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        } else {
            for (int i = front; i < SIZE; i++) cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++) cout << arr[i] << " ";
        }
        cout << endl;
    }
};

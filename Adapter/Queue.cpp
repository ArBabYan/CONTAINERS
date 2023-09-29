#include <iostream>


template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* previous;
    Node(const T& value) : data(value), next(nullptr), previous(nullptr) {}
};

template <typename T>
class LinkedList {
public:
    int size = 0;
    Node<T>* head = nullptr;

    void Next() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current = next;
        }
    }
    void Previous() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* previous = current->previous;
            current = previous;
        }
    }
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        newNode->previous = head;
        head = newNode;
        size++;
    }
    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

template<typename T>
class Queue : private LinkedList<T> {
    LinkedList<T> list;

public:
    void enqueue(const T& value) {
        this->push_back(value);
    }
    void dequeue() {
        if (this->head == nullptr) {
            std::cout << "Queue is empty";
        }
        else {
            Node<T>* front = this->head;
            this->head = front->next;

            if (this->head != nullptr) {
                this->head->previous = nullptr;
            }
            delete front;
        }
    }
};

int main() {
    Queue<int> queue;
    LinkedList<int> linked_list;
    linked_list.Next();
    linked_list.Previous();
    linked_list.push_back(8);
    linked_list.push_back(16);
    linked_list.push_back(32);
    linked_list.print();
    queue.enqueue(8);
    queue.enqueue(16);
    queue.enqueue(32);
    queue.dequeue();
    queue.dequeue();

    return 0;
}

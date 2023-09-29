#include <iostream>


template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList
{
    Node<T>* head = nullptr;
    int size = 0;

public:

    void f() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current = next;
        }

    }

    void insert(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        size++;
        Node<T>* current = head;
        std::cout << current->data<<std::endl; 
    }

};
int main()
{
    LinkedList<int> List;
    List.f();
    List.insert(8);
    List.insert(16);
    List.insert(32);
    List.insert(64);
}


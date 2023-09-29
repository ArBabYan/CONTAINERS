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
class LinkedList
{

    Node<T>* head = nullptr;
    int size = 0;

public:

    void Next() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            current = next;
        }
    }

    void Previous()
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            Node<T>* previous = current->previous;
            current = previous;
        }
    }

    void push_back(const T& value)
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        newNode->previous = head;

        head = newNode;
        size++;
        Node<T>* current = head;
        std::cout << current->data<<std::endl; 
    }

};
int main()
{
    LinkedList<int> Double_linked_list;
    Double_linked_list.Next();
    Double_linked_list.Previous();
    Double_linked_list.push_back(8);
    Double_linked_list.push_back(16);
    Double_linked_list.push_back(64);
    
}
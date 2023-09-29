#include <iostream>

class Vector {
    int* arr;
    int capacity;
    int current;

public:
    Vector() {
        arr = new int[1];
        capacity = 1;
        current = 0;
    }
    ~Vector() {
        delete[] arr;
    }
    void push(int data) {
        if (current == capacity) {
            int* temp = new int[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }
    void push(int data, int index) {
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }
    int get(int index) {
        if (index < current)
            return arr[index];
    }
    void pop() {
        current--;
    }
    int size() {
        return current;
    }
    int getCapacity() {
        return capacity;
    }
    void print() {
        for (int i = 0; i < current; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {

    Vector v;
    v.push(2);
    v.push(4);
    v.push(8);
    v.push(16);
    v.push(32);
    std::cout << "Vector size " << v.size() << std::endl;
    std::cout << "Vector capacity " << v.getCapacity() << std::endl;
    std::cout << "Vector elements ";
    v.print();
    v.push(888, 1);
    std::cout << "After updating 1st index" << std::endl;
    std::cout << "Vector elements " << std::endl;
    v.print();
    std::cout << "Element at 1st index " << v.get(1) << std::endl;
    v.pop();
    std::cout << "After deleting last element" << std::endl;
    std::cout << "Vector size " << v.size() << std::endl;
    std::cout << "Vector capacity " << v.getCapacity() << std::endl;
    std::cout << "Vector elements ";
    v.print();

    return 0;
}
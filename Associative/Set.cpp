#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class MySet {
private:
    std::vector<T> elements;

public:
    void insert(T element) {
        if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
            elements.push_back(element);
        }
    }
    void sort() {
        std::sort(elements.begin(), elements.end());
    }
    void remove(T element) {
        for (typename std::vector<T>::iterator it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                return;
            }
        }
    }
    void print() const {
        for (const T& element : elements) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
};

int main() {

    MySet<int> set;
    set.insert(2);
    set.insert(4);
    set.insert(8);
    set.insert(16);
    set.insert(32);
    set.insert(64);
    set.sort();
    set.print();
    set.remove(4);
    set.print();

    return 0;
}

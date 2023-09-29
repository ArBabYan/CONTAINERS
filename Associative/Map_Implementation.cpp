#include <iostream>
#include <string>


const int max_digits = 10; 
class Map {
private:
    int keys[max_digits];
    std::string values[max_digits];
    int size;
public:
    Map() : size(0) {}

    void insert(int key, const std::string& value) {
        if (size < max_digits) {
            keys[size] = key;
            values[size] = value;
            size++;
        }
        else {
            std::cout << "Map is full" << std::endl;
        }
    }

    std::string* Find_Val(int key) {
        for (int i = 0; i < size; i++) {
            if (keys[i] == key) {
                return &values[i];
            }
        }
        return nullptr;
    }
};

int main() {
    Map m;
    m.insert(1, "Arame");
    m.insert(2, "Ani");
    m.insert(3, "Vahagn");
    std::string* value = m.Find_Val(1);
    if (value)
    {
        std::cout << "Key 1 maps to " << *value << std::endl;
    }
    else {
        std::cout << "Key 1 not found " << std::endl;
    }

    return 0;
}
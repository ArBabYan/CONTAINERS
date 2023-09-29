#include <iostream>
#include <string>

template <typename T>
class My_Vec
{
    T* arr = nullptr;
    int size = 0;
    int capacity = 0;

public:

    My_Vec() {}

    My_Vec(int size)
    {
        this->size = size;
        arr = new T[size];
    }

    My_Vec(const My_Vec& obj)
    {
        this->size = obj.size;
        arr = new T[size];
    }

    My_Vec& operator=(const My_Vec& obj)
    {
        if (this != &obj)
        {
            delete[] arr;
            this->size = obj.size;
            arr = new T[size];
        }
        return *this;
    }

    My_Vec(My_Vec&& obj) noexcept
    {
        size = obj.size;
        arr = obj.arr;
        obj.size = 0;
        obj.arr = nullptr;
    }

    My_Vec& operator=(My_Vec&& obj) noexcept
    {
        if (this != &obj)
        {
            delete[] arr;
            size = obj.size;
            arr = obj.arr;
            obj.size = 0;
            obj.arr = nullptr;
        }
        return *this;
    }

    void get_element()
    {
        for (int i = 0; i < size; ++i)
        {
            arr[i] = 1;
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
    void push_back(const T& value) noexcept
    {
        if (size == capacity)
        {
            int newCapacity;
            if (capacity == 0)
            {
                newCapacity = 1;
            }
            else
            {
                newCapacity = capacity * 2;
            }
            T* newarr = new T[newCapacity];

            for (int i = 0; i < size; ++i)
            {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            capacity = newCapacity;
        }
        arr[size] = value;
        ++size;

        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
    void pop_back()
    {
        if (size > 0)
        {
            --size;
        }

        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
    void insert(int index, const T& value)
    {
        if (index < 0 || index > size)
        {
            std::cout << "error" << std::endl;
            return;
        }
        if (size == capacity)
        {
            int newCapacity;
            if (capacity == 0)
            {
                newCapacity = 1;
            }
            else
            {
                newCapacity = capacity * 2;
            }
            T* newarr = new T[newCapacity];

            for (int i = 0; i < size; ++i)
            {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
            capacity = newCapacity;
        }
        for (int i = size; i > index; --i)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        ++size;
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
    void erase(int index)
    {
        if (index < 0 || index >= size)
        {
            std::cout << "error" << std::endl;
            return;
        }
        for (int i = index; i < size - 1; ++i)
        {
            arr[i] = arr[i + 1];
        }
        --size;
        for (int i = 0; i < size; ++i)
        {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
    ~My_Vec()
    {
        delete[] arr;
    }

};


template<typename T>
class Stack : private My_Vec<T> {

public:
    void push_back(const T& value)
    {
        this->push_back(value);

    }
    void pop_back()
    {

        this->pop_back();

    }
    void top()
    {
        if (this->size > 0)
        {
            return this->arr[this->size - 1];
        }
    }
};


int main()
{
    int size = 8;
    My_Vec<int> vec(size);
    My_Vec<int> vec1 = vec;
    vec.get_element();
    vec.push_back(1);
    vec.pop_back();
    vec.insert(5, 5);
    vec.erase(1);
    Stack<int> st;
    st.push_back(1);
    st.push_back(2);
    st.push_back(3);
    st.pop_back();
    My_Vec<int> vec2 = std::move(vec);
    My_Vec<int> b;
    b = std::move(My_Vec<int>(2));

    return 0;
}
#include <iostream>
#include <new>

template <typename T>
class StackBasedOnUnidirectionalLinkedList {
private:
    template <typename T>
    class Node {
    public:
        T data;
        Node* next;

        Node(T data = T(), Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };

    Node<T>* top;
    int size;

public:

    int GetSize() const {
        return size;
    };

    void clear();

    bool Push(const T& element);

    bool Pop(T& element);

    bool Peek(T& element) const;

    StackBasedOnUnidirectionalLinkedList();

    StackBasedOnUnidirectionalLinkedList(const StackBasedOnUnidirectionalLinkedList<T>& other);

    StackBasedOnUnidirectionalLinkedList(StackBasedOnUnidirectionalLinkedList<T>&& other);

    StackBasedOnUnidirectionalLinkedList(std::initializer_list<T> ilist);

    ~StackBasedOnUnidirectionalLinkedList();

    StackBasedOnUnidirectionalLinkedList<T>& operator=(const StackBasedOnUnidirectionalLinkedList<T>& other);

    StackBasedOnUnidirectionalLinkedList<T>& operator=(StackBasedOnUnidirectionalLinkedList<T>&& other);

    StackBasedOnUnidirectionalLinkedList<T>& operator=(std::initializer_list<T> ilist);
};

template<typename T>
StackBasedOnUnidirectionalLinkedList<T>::StackBasedOnUnidirectionalLinkedList()
{
    size = 0;
    top = nullptr;
}

template<typename T>
StackBasedOnUnidirectionalLinkedList<T>::~StackBasedOnUnidirectionalLinkedList() {
    clear();
}

template <typename T>
StackBasedOnUnidirectionalLinkedList<T>::StackBasedOnUnidirectionalLinkedList(const StackBasedOnUnidirectionalLinkedList<T>& other) : top(nullptr), size(0) {
    *this = other;
}

template <typename T>
StackBasedOnUnidirectionalLinkedList<T>::StackBasedOnUnidirectionalLinkedList(StackBasedOnUnidirectionalLinkedList<T>&& other) : top(nullptr), size(0) {
    *this = std::move(other);
}

template <typename T>
StackBasedOnUnidirectionalLinkedList<T>::StackBasedOnUnidirectionalLinkedList(std::initializer_list<T> ilist) : top(nullptr), size(0) {
    *this = ilist;
}

template <typename T>
StackBasedOnUnidirectionalLinkedList<T>& StackBasedOnUnidirectionalLinkedList<T>::operator=(const StackBasedOnUnidirectionalLinkedList<T>& other) {

    if (this == &other)
        return *this;

    clear();

    if (other.top != nullptr) {

        Node<T>* currentOther = other.top->next;

        do {

            if (!Push(currentOther->data)) {

                clear();
                throw std::bad_alloc();
            }
            currentOther = currentOther->next;
        } while (currentOther);
    }

    return *this;
}

template <typename T>
StackBasedOnUnidirectionalLinkedList<T>& StackBasedOnUnidirectionalLinkedList<T>::operator=(StackBasedOnUnidirectionalLinkedList<T>&& other) {
    if (this == &other)
        return *this;

    clear();

    top = other.top;
    size = other.size;

    other.top = nullptr;
    other.size = 0;

    return *this;
}

template <typename T>
StackBasedOnUnidirectionalLinkedList<T>& StackBasedOnUnidirectionalLinkedList<T>::operator=(std::initializer_list<T> ilist) {
    clear();

    for (const T& item : ilist) {
        Push(item);
    }

    return *this;
}

template<typename T>
void StackBasedOnUnidirectionalLinkedList<T>::clear() {
    Node<T>* nextNode;
    while (size > 0) {
        nextNode = top->next;
        delete top;
        top = nextNode;
        --size;
    }
    top = nullptr;
}

template<typename T>
bool StackBasedOnUnidirectionalLinkedList<T>::Push(const T& element) {

    Node<T>* newNode = new(std::nothrow) Node<T>(element);

    if (newNode == nullptr) {

        return false;
    }

    if (size > 0) {
        newNode->next = top;

    }

    top = newNode;
    size++;
    return true;
}

template<typename T>
bool StackBasedOnUnidirectionalLinkedList<T>::Pop(T& element) {

    if (size == 0) {

        return false;
    }

    element = top->data;

    Node<T>* toDelete = top;

    if (size == 1) {
        top = nullptr;
    }
    else {
        top = top->next;
    }

    delete toDelete;
    --size;
    return true;
}

template<typename T>
bool StackBasedOnUnidirectionalLinkedList<T>::Peek(T& element) const {
    if (top == nullptr) {
        return false;
    }
    element = top->data;

    return true;
}

template<typename T>
void printStack(const StackBasedOnUnidirectionalLinkedList<T>& other)
{
    StackBasedOnUnidirectionalLinkedList<T> new_stack = other;
    T data;

    while (new_stack.GetSize() > 0)
    {
        new_stack.Pop(data);
        std::cout << data << std::endl;
    };

    std::cout << std::endl;
}

int main() {
    StackBasedOnUnidirectionalLinkedList<int>* new_stack = new StackBasedOnUnidirectionalLinkedList<int>();
    for (int i = 0; i <= 10; i++)
    {
        new_stack->Push(i);

    }
    printStack(*new_stack);
    StackBasedOnUnidirectionalLinkedList<int>* new_stack1 = new StackBasedOnUnidirectionalLinkedList<int>();
    for (int i = 11; i <= 15; i++)
    {
        new_stack1->Push(i);

    }
    std::swap(new_stack, new_stack1);
    int data;
    new_stack->Peek(data);
    printStack(*new_stack);
    std::cout << data;

    return 0;
}

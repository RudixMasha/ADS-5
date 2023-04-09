// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T>
class TStack {
 private:
    T arr[100];
    int top;

 public:
    TStack() :top(-1) {}
    void push(T value) {
        if (isfull())
            throw std::string("Full");
        else
            arr[++top] = value;
    }
    const T& pop() {
        if (isempty())
            throw std::string("Empty");
        else
            return arr[top--];
    }
    const T& get() {
        return arr[top];
    }
    bool isempty() {
        return top == -1;
    }
    bool isfull() {
        return top == 100;
    }
};

#endif  // INCLUDE_TSTACK_H_

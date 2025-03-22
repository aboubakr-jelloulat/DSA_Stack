# Stack Implementation using Linked List 🔄

## Overview 📚

This project implements a custom stack data structure (`clsMyStack`) using a linked list. The implementation inherits from a queue class (`clsMyQueue`) and overrides/adds necessary functionality to behave like a stack.

## Table of Contents 📋

| Section | Description |
|---------|-------------|
| [Introduction](#introduction) | Brief overview of the project |
| [Features](#features) | Key capabilities of the stack implementation |
| [Implementation Details](#implementation-details) | Technical details of the code |
| [OOP Concepts Used](#oop-concepts-used) | Explanation of OOP principles applied |
| [Usage Examples](#usage-examples) | Code examples showing how to use the stack |
| [Performance](#performance) | Time and space complexity |
| [Resources](#resources) | Learning materials and references |

## Introduction 🚀

A stack is a fundamental data structure that follows the Last-In-First-Out (LIFO) principle. This implementation leverages an existing queue class by inheriting from it and customizing the behavior to function as a stack.

## Features ✨

- Generic implementation using C++ templates
- Push operation to add elements to the stack
- Top operation to view the most recently added element
- Bottom operation to view the first element added
- Inherited pop and other utility functions from the queue class

## Implementation Details 🛠️

The stack is implemented in the `clsMyStack` class, which inherits from `clsMyQueue`. The core of the implementation is a linked list (`_MyList`) that is provided by the queue class.

Key aspects of the implementation:

```cpp
#pragma once
#include "clsMyQueue.h"
#include <iostream>
using namespace std;
template <class T>
class clsMyStack : public clsMyQueue<T>
{
public:
    void push(T Item)
    {
        clsMyQueue<T>::_MyList.InsertAtBeginning(Item);
    }
    
    T Top()
    {
        return clsMyQueue<T>::front();
    }
    
    T Bottom()
    {
        return clsMyQueue<T>::back();
    }
};
```

## OOP Concepts Used 🧩

### Inheritance 🔄

The class `clsMyStack<T>` inherits from `clsMyQueue<T>`, which allows it to reuse functionality from the queue class. This demonstrates the "is-a" relationship - a stack can be considered a specialized type of queue with different access patterns.

### Method Overriding 🔀

While not explicitly overriding methods in the traditional sense, the implementation essentially overrides the conceptual behavior of the queue. In a queue, elements are typically added at the end and removed from the front (FIFO). However, in this stack implementation:

- Elements are added at the beginning (`InsertAtBeginning`) rather than the end
- The `Top()` method uses the queue's `front()` method, but due to the insertion at the beginning, this returns the most recently added element (LIFO behavior)

### Templates 📐

The implementation uses C++ templates (`template <class T>`) to create a type-agnostic stack that can store elements of any data type.

## Usage Examples 📝

```cpp
#include "clsMyStack.h"
#include <iostream>
#include <string>

int main() {
    // Integer stack
    clsMyStack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    
    std::cout << "Top element: " << intStack.Top() << std::endl;  // Output: 30
    std::cout << "Bottom element: " << intStack.Bottom() << std::endl;  // Output: 10
    
    // String stack
    clsMyStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    
    std::cout << "Top element: " << stringStack.Top() << std::endl;  // Output: World
    
    return 0;
}
```

## Performance ⚡

- Time Complexity:
  - Push: O(1)
  - Top: O(1)
  - Bottom: O(n)
  - Pop (inherited): O(1)

- Space Complexity: O(n) where n is the number of elements in the stack

## Resources 📖

- [Stacks and Queues in C++](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/)
- [C++ Templates](https://www.cplusplus.com/doc/oldtutorial/templates/)
- [Inheritance in C++](https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm)
- [Data Structures and Algorithms with C++](https://www.amazon.com/Data-Structures-Algorithms-Michael-Goodrich/dp/0470383275)
- [C++ Standard Template Library (STL)](https://www.cplusplus.com/reference/stl/)

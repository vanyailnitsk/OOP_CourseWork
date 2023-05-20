#ifndef LIST_H
#define LIST_H


#include <iostream>
using namespace std;

template<typename T>
class List {
    int size;
    int capacity;
    T *array;
public:
    List(int capacity) : capacity(capacity) {
        size=0;
        array=new T[capacity];
    }
    List() {
        size=0;
        capacity=10;
        array= new T[capacity];
    }
    List(T *ref,int refSize) {
        capacity=refSize;
        size=refSize;
        array = new T[refSize];
        for (int i = 0; i < refSize; i++) {
            array[i] = ref[i];
        }
    }
    List(const List &refList) {
        size=refList.size;
        capacity=refList.capacity;
        array=new T[capacity];
        for (int i = 0; i < size; i++) {
            array[i]= refList.array[i];
        }
    }
    void clear() {
        delete [] array;
        size = 0;
        capacity = 10;
        array = new T[capacity];
    }
    T get (int index) {
        if (index<size&&index>=0) {
            return array[index];
        }
        else {
            cout << index << endl;
            throw string("ArrayIndexOutOfBoundsException");
        }
    }
    int getSize() const {
            return size;
        }
    void set(int index, T elem) {
        if (index<size||index>=0) {
            array[index] = elem;
        }
        else {
            throw string("ArrayIndexOutOfBoundsException");
        }
    }
    void print() {
        if (size==0) {
            cout << "Empty List" << endl;
        }
        else {
            cout << "Elements of list: ";
            for (int i = 0; i < size; i++) {
                cout << array[i]<<" ";
            }
            cout << endl;
        }
    }
    void add(T elem) {
        if (size==capacity) {
            T *newArray = new T[capacity*2];
            for (int i = 0; i < size; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            capacity *= 2;
            newArray[size] = elem;
            array = newArray;
            size++;
        }
        else {
            array[size] = elem;
            size++;
        }
    }
    void add(T elem,int index) {
        T *newArray;
        if (size==capacity) {
            capacity*=2;
            newArray = new T[capacity];
        }
        else {
            newArray = new T[capacity];
        }
        for (int i = 0; i < index; i++) {
            newArray[i]=array[i];
        }
        newArray[index] = elem;
        for (int i = index + 1; i < 1 + size; i++) {
            newArray[i] = array[i - 1];
        }
        delete[] array;
        array=newArray;
        size+=1;
    }

    void addAll(T *refArray,int index, int length) {
        T *newArray;
        if (capacity <= length + size) {
            newArray = new T[capacity];
        } else {
            capacity*=2;
            newArray = new T[capacity];
        }
        for (int i = 0; i < index; i++) {
            newArray[i] = array[i];
        }
        for (int i = index; i < index + length; i++) {
            newArray[i] = refArray[i - index];
        }
        for (int i = index + length; i < length + size; i++) {
            newArray[i] = array[i - length];
        }
        delete []array;
        array = newArray;
        size += length;
    }
    T* toArray() {
       T *copy = new T[size];
        for (int i = 0; i < size; i++) {
            copy[i] = array[i];
        }
        return copy;
    }

    virtual ~List() {
        delete[] array;
    }
};

#endif // LIST_H

//
//  main.cpp
//  Heap
//
//  Created by zw896 on 3/09/2016.
//  Copyright © 2016 UOW. All rights reserved.
//

#include <iostream>

void swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void siftUp(int H[],int i)
{
    bool done = false;
    if (i != 0) {
        while (!done && i != 0) {
            if (H[i] > H[(i - 1) / 2])
                swap(H[i], H[(i - 1) / 2]);
            else done = true;
            i = (i - 1) / 2;
        }
    }
}


void siftDown(int H[],int n,int i)
{
    bool done = false;
    while (!done && ((i = 2 * i + 1) < n)) {
        if ((i + 1 < n) && (H[i + 1] > H[i]))
            i = i + 1;
        if (H[(i - 1) / 2] < H[i])
            swap(H[(i-1)/2], H[i]);
        else done = true;
    }
}

void makeHeap(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftDown(array, n, i);
    }
}

void heapSort(int A[],int n)
{
    makeHeap(A, n);
    for (int i = n - 1; i > 0; i--) {
        swap(A[0], A[i]);
        siftDown(A, i, 0);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int array[8];
    
    for (int i = 0; i < 8; i++) {
        std::cout << "Insert a number: ";
        std::cin >> array[i];
    }
    
    for (int i = 0; i < 8; i++) {
        //std::cout << "Insert a number" << std::endl;
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    heapSort(array, 8);
    
    std::cout << "after: ";
    for (int i = 0; i < 8; i++) {
        //std::cout << "Insert a number" << std::endl;
        std::cout  << array[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}



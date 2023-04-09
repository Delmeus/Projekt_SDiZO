//
// Created by Antek on 27.03.2023.
//

#ifndef INC_1_HEAP_H
#define INC_1_HEAP_H


class Heap {
public:
    Heap();

    virtual ~Heap();

    int *pointer;
    int size;
    void createHeap();
    void deleteElement();
    void showHeap() const;
    void insertElement(int value);
    bool findValue(int value);

private:
    static int parent(int i);
    static void swap(int *a,int *b);

};


#endif //INC_1_HEAP_H

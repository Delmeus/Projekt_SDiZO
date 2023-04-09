//
// Created by Antek on 23.03.2023.
//

#ifndef INC_1_LIST_H
#define INC_1_LIST_H

#include "ListElement.h"


class List {
public:
    List();

    ~List();

    int size;

    void createList();
    void addElementBeginning(int value);
    void addElementEnd(int value);
    void addElementPosition(int value, int position);
    void deleteFirstElement();
    void deleteLastElement();
    void deleteElementPosition(int position);
    bool findValue(int value);
    void showList();

private:
    ListElement *firstElement;
    ListElement *lastElement;
    ListElement *currentElement;
};


#endif //INC_1_LIST_H

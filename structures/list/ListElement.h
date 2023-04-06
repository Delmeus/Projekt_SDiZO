//
// Created by Antek on 23.03.2023.
//

#ifndef INC_1_LISTELEMENT_H
#define INC_1_LISTELEMENT_H


class ListElement {
public:
    ListElement *next;
    ListElement *previous;
    int value;

    ListElement(int value, ListElement *next, ListElement *previous);
};


#endif //INC_1_LISTELEMENT_H

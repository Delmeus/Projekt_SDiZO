//
// Created by Antek on 23.03.2023.
//

#include "ListElement.h"

ListElement::ListElement(int value, ListElement *next, ListElement *previous) {
    ListElement::value = value;
    ListElement::next = next;
    ListElement::previous = previous;
}

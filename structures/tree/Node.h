//
// Created by Antek on 28.03.2023.
//
#ifndef INC_1_NODE_H
#define INC_1_NODE_H


class Node {
public:
    explicit Node(int value);

    Node *left;
    Node *right;
    int value;
};


#endif //INC_1_NODE_H

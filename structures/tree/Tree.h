//
// Created by Antek on 28.03.2023.
//

#ifndef INC_1_TREE_H
#define INC_1_TREE_H
#include "Node.h"


class Tree {
public:
    Tree();

    ~Tree();

    int size;
    Node *root;

    void createTree();
    int getSize(Node *node);
    void insertNode(int value);
    Node *deleteNode(int value, Node *node);
    Node *searchForNode(int value, Node *node);
    void showTree(Node *, int space);

private:
    static Node *findMin(Node *node);
};


#endif //INC_1_TREE_H

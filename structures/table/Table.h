//
// Created by Antek on 21.03.2023.
//

#ifndef INC_1_TABLE_H
#define INC_1_TABLE_H


class Table {
public:
    int *pointer;
    int size;

    Table();
    ~Table();

    void createTable();
    void addElementBeginning(int value);
    void addElementEnd(int value);
    void addElementPosition(int value, int position);
    void deleteElementBeginning();
    void deleteElementEnd();
    void deleteElementPosition(int position);
    void showTable() const;
    void saveTableToFile() const;
    bool doesExist() const;
};


#endif //INC_1_TABLE_H

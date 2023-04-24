//
// Created by Antek on 21.03.2023.
//

#include "Tester.h"
#include "iostream"
#include "../structures/table/Table.h"
#include "../utils/Timer.h"
#include "../structures/list/List.h"
#include "../structures/heap/Heap.h"
#include "../structures/tree/Tree.h"

Tester::Tester() = default;

void Tester::testTable() {
    auto table = Table();
    auto timer = Timer();
    table.createTable();
    int answer, *value;
    do{
        std::cout << "\nTable test, what do you want to do?\n"
                     "1. Show Table\n"
                     "2. Clear screen\n"
                     "3. Add element at the beginning\n"
                     "4. Add element at given position\n"
                     "5. Add element at the end\n"
                     "6. Delete element at the beginning\n"
                     "7. Delete element at given position\n"
                     "8. Delete element at the end\n"
                     "9. Search for element\n"
                     "10. Exit test\n";

        value = new int[2]; //value[0] - wartość value[1] - pozycja
        std::cin >> answer;
        switch (answer) {
            case 1:{
                table.showTable();
                break;
            }
            case 2: {
                system("CLS");
                break;
            }
            case 3:{
                std::cout << "Value: ";
                std::cin >> value[0];
                timer.start();
                table.addElementBeginning(value[0]);
                timer.stop();
                std::cout << "Time taken to perform last operation: " << timer.nano() << " nanoseconds or " << timer.micro() << " microseconds\n";
                break;
            }
            case 4:{
                std::cout << "Position: ";
                std::cin >> value[1];
                if(value[1] > 0 && value[1] < table.size){
                    getchar();
                    std::cout <<"Value: ";
                    std::cin >> value[0];
                    timer.start();
                    table.addElementPosition(value[0], value[1]);
                    timer.stop();
                    std::cout << "Time taken to perform last operation: " << timer.nano() << " nanoseconds or " << timer.micro() << " microseconds\n";
                }
                else std::cout << "There is no such position";
                break;
            }
            case 5:{
                std::cout << "Value: ";
                std::cin >> value[0];
                timer.start();
                table.addElementEnd(value[0]);
                timer.stop();
                std::cout << "Time taken to perform last operation: " << timer.nano() << " nanoseconds or " << timer.micro() << " microseconds\n";
                break;
            }
            case 6:{
                timer.start();
                table.deleteElementBeginning();
                timer.stop();
                std::cout << "\nTime taken to perform last operation: " << timer.nano() << " nanoseconds or " << timer.micro() << " microseconds\n";
                break;
            }
            case 7:{
                std::cout << "Position: ";
                std::cin >> value[1];
                timer.start();
                table.deleteElementPosition(value[1]);
                timer.stop();
                std::cout << "\nTime taken to perform last operation: " << timer.nano() << " nanoseconds or " << timer.micro() << " microseconds\n";
                break;
            }
            case 8:{
                timer.start();
                table.deleteElementEnd();
                timer.stop();
                std::cout << "\nTime taken to perform last operation: " << timer.nano() << " nanoseconds or " << timer.micro() << " microseconds\n";
                break;
            }
            case 9:{
                std::cout << "Value: ";
                std::cin >> value[0];
                timer.start();
                table.findValue(value[0]);
                timer.stop();
                std::cout << "Time taken to perform last operation: " << timer.nano() << " nanoseconds or " << timer.micro() << " microseconds\n";
            }
            case 10:
                break;
            default:{
                std::cout << "\nWrong choice, try again\n";
                break;
            }

        }

        delete[] value;
    }while(answer != 10);

}

void Tester::testList() {
    auto list = List();
    list.createList();
    auto timer = Timer();
    int answer, *value;
    do {
        std::cout << "\nList test, what do you want to do?\n"
                     "1. Show list\n"
                     "2. Clear screen\n"
                     "3. Add element at the beginning\n"
                     "4. Add element at given position\n"
                     "5. Add element at the end\n"
                     "6. Delete element at the beginning\n"
                     "7. Delete element at given position\n"
                     "8. Delete element at the end\n"
                     "9. Search for element\n"
                     "10. Exit test\n";
        value = new int[2];
        std::cin >> answer;
        switch (answer) {
            case 1: {
                list.showList();
                break;
            }
            case 2: {
                system("CLS");
                break;
            }
            case 3:{
                std::cout << "\nValue: ";
                std::cin >> value[0];
                timer.start();
                list.addElementBeginning(value[0]);
                timer.stop();
                std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano() << " nanoseconds\n";
                break;
            }
            case 4:{
                std::cout << "\nPosition: ";
                std::cin >> value[1];
                std::cout << "\nValue: ";
                std::cin >> value[0];
                if(value[1] >=0 && value[1] < list.size) {
                    timer.start();
                    list.addElementPosition(value[0], value[1]);
                    timer.stop();
                    std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano()
                              << " nanoseconds\n";
                }
                else std::cout << "\nNo such position in the list!\n";
                break;
            }
            case 5:{
                std::cout << "\nValue: ";
                std::cin >> value[0];
                timer.start();
                list.addElementEnd(value[0]);
                timer.stop();
                std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano() << " nanoseconds\n";
                break;
            }
            case 6:{
                timer.start();
                list.deleteFirstElement();
                timer.stop();
                std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano() << " nanoseconds\n";
                break;
            }
            case 7:{
                std::cout << "\nPosition: ";
                std::cin >> value[1];
                if(value[1] >=0 && value[1] < list.size) {
                    timer.start();
                    list.deleteElementPosition(value[1]);
                    timer.stop();
                    std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano()
                              << " nanoseconds\n";
                }
                else std::cout << "\nNo such position in the list!\n";
                break;
            }
            case 8:{
                list.deleteLastElement();
                break;
            }
            case 9: {
                std::cout << "Value: ";
                std::cin >> value[0];
                timer.start();
                list.findValue(value[0]);
                timer.stop();
                std::cout << "Time taken to perform last operation: " << timer.nano() << " nanoseconds or " << timer.micro() << " microseconds\n";
            }
            case 10:
                break;
            default:{
                std::cout << "\nWrong choice, try again\n";
                break;
            }
        }
        free(value);
    }while(answer != 10);
}

void Tester::testHeap() {
    auto heap = Heap();
    heap.createHeap();
    auto timer = Timer();
    int answer, *value;
    do {
        std::cout << "\nHeap test, what do you want to do?\n"
                     "1. Show heap\n"
                     "2. Clear screen\n"
                     "3. Add element\n"
                     "4. Delete element\n"
                     "5. Find element\n"
                     "6. Exit test\n";
        value = new int;
        std::cin >> answer;
        switch (answer) {
            case 1:{
                heap.showHeap(0,0);
                break;
            }
            case 2:{
                system("cls");
                break;
            }
            case 3:{
                std::cout << "\nValue: ";
                std::cin >> *value;
                timer.start();
                heap.insertElement(*value);
                timer.stop();
                std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano() << " nanoseconds\n";
                free(value);
                break;
            }
            case 4:{
                timer.start();
                heap.deleteElement();
                timer.stop();
                std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano() << " nanoseconds\n";
                free(value);
                break;
            }
            case 5:{
                std::cout << "\nValue: ";
                std::cin >> *value;
                timer.start();
                heap.findValue(*value);
                timer.stop();
                std::cout << "Time taken to perform last operation: " << timer.nano() << " nanoseconds or " << timer.micro() << " microseconds\n";
            }
            case 6:{
                break;
            }
            default:{
                std::cout << "\nWrong choice, try again\n";
                break;
            }
        }
    } while (answer != 6);
}

void Tester::testBST() {
    auto tree = Tree();
    auto timer = Timer();
    tree.createTree();
    int answer, value;
    do {
        std::cout << "\nBST tree test, what do you want to do?\n"
                     "1. Show tree\n"
                     "2. Clear screen\n"
                     "3. Add element\n"
                     "4. Delete element\n"
                     "5. Search for element\n"
                     "6. Exit test\n";
        std::cin >> answer;
        switch (answer) {
            case 1:{
                tree.showTree(tree.root, tree.size);
                break;
            }
            case 2:{
                system("cls");
                break;
            }
            case 3:{
                std::cout << "\nValue: ";
                std::cin >> value;
                timer.start();
                tree.insertNode(value);
                timer.stop();
                std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano() << " nanoseconds\n";
                break;
            }
            case 4:{
                std::cout << "\nValue: ";
                std::cin >> value;
                auto node = tree.searchForNode(value, tree.root);
                timer.start();
                if(node != nullptr) tree.deleteNode(value, tree.root);
                timer.stop();
                std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano() << " nanoseconds\n";
                break;
            }
            case 5:{
                std::cout << "\nValue: ";
                std::cin >> value;
                timer.start();
                tree.searchForNode(value, tree.root);
                timer.stop();
                std::cout << "Last operation took " << timer.micro() << " microseconds or " << timer.nano() << " nanoseconds\n";
                break;
            }
            case 6:{
                break;
            }
            default:{
                std::cout << "\nWrong choice, try again\n";
                break;
            }
        }
    } while (answer != 6);
}

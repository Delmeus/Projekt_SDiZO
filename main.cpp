#include <iostream>
#include "utils/FileRandomizer.h"
#include "testers/Tester.h"
#include "testers/AutomaticTester.h"
int main() {

    int size;
    std::cout << "Give size of structure: ";
    std::cin >> size;
    while(size <= 0){
        std::cout << "Wrong answer, try again:\n";
        std::cin >> size;
    }
    int answer;
    do {
        FileRandomizer writer;
        writer.knownSizeWrite(size);
        std::cout << "\nWhat structure do you want to test on?\n1. Table\n2. List\n3. Binary Heap\n4. BST tree\n5. Table (Automatic)\n6. List (Automatic)\n7. Binary Heap (Automatic)\n8. BST tree (Automatic)\n9. Exit program\n";
        std::cin >> answer;
        switch (answer) {
            case 1: {
                std::cout << "\nBeginning table test\n";
                Tester::testTable();
                break;
            }
            case 2: {
                std::cout << "\nBeginning list test\n";
                Tester::testList();
                break;
            }
            case 3: {
                std::cout << "\nBeginning heap test\n";
                Tester::testHeap();
                break;
            }
            case 4: {
                std::cout << "\nBeginning BST tree test\n";
                Tester::testBST();
                break;
            }
            case 5: {
                std::cout << "\nBeginning automatic table test\n";
                AutomaticTester::testTable();
                break;
            }
            case 6: {
                std::cout << "\nBeginning automatic list test\n";
                AutomaticTester::testList();
                break;
            }
            case 7: {
                std::cout << "\nBeginning automatic heap test\n";
                AutomaticTester::testHeap();
                break;
            }
            case 8: {
                std::cout << "\nBeginning automatic BST tree test\n";
                AutomaticTester::testBST();
                break;
            }
            case 9:
                break;
            default: {
                std::cout << "\nWrong answer\n";
                break;
            }
        }
    } while (answer != 9);

    return 0;
}

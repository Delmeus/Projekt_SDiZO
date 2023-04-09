#include <iostream>
#include "utils/FileRandomizer.h"
#include "testers/Tester.h"
#include "testers/AutomaticTester.h"
int main() {
    int size;
    std::cout << "Give size of structure: ";
    std::cin >> size;
    while(size <= 0){
        std::cout << "Wrong answer, try again\n";
        std::cin >> size;
    }
    int answer;
    do {
        std::cout << "\nWhat structure do you want to test on?\n1. Table\n2. List\n3. Binary Heap\n4. BST tree\n5. Table (Automatic)\n6. List (Automatic)\n7. Binary Heap (Automatic)\n8. BST tree (Automatic)\n9. Change size\n10. Exit program\n";
        std::cin >> answer;
        switch (answer) {
            case 1: {
                std::cout << "\nBeginning table test\n";
                FileRandomizer::knownSizeWrite(size);
                Tester::testTable();
                std::cout << "\n\nEnd of test, press ENTER to continue..." << std::endl;
                std::cin.ignore(10000, '\n');
                getchar();
                break;
            } //ręczny test tablicy
            case 2: {
                std::cout << "\nBeginning list test\n";
                FileRandomizer::knownSizeWrite(size);
                Tester::testList();
                std::cout << "\n\nEnd of test, press ENTER to continue..." << std::endl;
                std::cin.ignore(10000, '\n');
                getchar();
                break;
            } //ręczny test listy
            case 3: {
                std::cout << "\nBeginning heap test\n";
                FileRandomizer::knownSizeWrite(size);
                Tester::testHeap();
                std::cout << "\n\nEnd of test, press ENTER to continue..." << std::endl;
                std::cin.ignore(10000, '\n');
                getchar();
                break;
            } //ręczny test kopca
            case 4: {
                std::cout << "\nBeginning BST tree test\n";
                FileRandomizer::knownSizeWrite(size);
                Tester::testBST();
                std::cout << "\n\nEnd of test, press ENTER to continue..." << std::endl;
                std::cin.ignore(10000, '\n');
                getchar();
                break;
            } //ręczny test BST
            case 5: {
                long results[7] = {0, 0, 0,0, 0, 0, 0};
                std::cout << "\nBeginning automatic table test\n";
                for(int i = 0; i < 15; i++) {
                    std::cout << "\nTest nr: " << i + 1;
                    FileRandomizer::knownSizeWrite(size);
                    AutomaticTester::testTable(results, i + 1);
                } //wykonujemy 15 niezależnych testów a następnie podajemy średnie wyniki
                std::cout << "\nTable test average results" << std::endl;
                std::cout << "Adding element beginning: " << results[0]/15000000 << " ms " << results[0]/15000 << " microseconds " << results[0]/15 << " ns\n";
                std::cout << "Adding element  position: " << results[1]/15000000 << " ms " << results[1]/15000 << " microseconds " << results[1]/15 << " ns\n";
                std::cout << "Adding    element    end: " << results[2]/15000000 << " ms " << results[2]/15000 << " microseconds " << results[2]/15 << " ns\n";
                std::cout << "Removing  first  element: " << results[3]/15000000 << " ms " << results[3]/15000 << " microseconds " << results[3]/15 << " ns\n";
                std::cout << "Removing  given  element: " << results[4]/15000000 << " ms " << results[4]/15000 << " microseconds " << results[4]/15 << " ns\n";
                std::cout << "Removing  last   element: " << results[5]/15000000 << " ms " << results[5]/15000 << " microseconds " << results[5]/15 << " ns\n";
                std::cout << "Searching for    element: " << results[6]/15000000 << " ms " << results[6]/15000 << " microseconds " << results[6]/15 << " ns\n";
                std::cout << "\n\nEnd of test, press ENTER to continue..." << std::endl;
                std::cin.ignore(10000, '\n');
                getchar();
                break;
            } //automatyczny test tablicy
            case 6: {
                long results[7] = {0, 0, 0,0, 0, 0,0};
                std::cout << "\nBeginning automatic list test\n";
                for(int i = 0; i < 15; i++) {
                    std::cout << "\nTest nr: " << i + 1;
                    FileRandomizer::knownSizeWrite(size);
                    AutomaticTester::testList(results, i + 1) ;
                }
                std::cout << "\nList test average results" << std::endl;
                std::cout << "Adding element beginning: " << results[0]/15000000 << " ms " << results[0]/15000 << " microseconds " << results[0]/15 << " ns\n";
                std::cout << "Adding element  position: " << results[1]/15000000 << " ms " << results[1]/15000 << " microseconds " << results[1]/15 << " ns\n";
                std::cout << "Adding    element    end: " << results[2]/15000000 << " ms " << results[2]/15000 << " microseconds " << results[2]/15 << " ns\n";
                std::cout << "Removing  first  element: " << results[3]/15000000 << " ms " << results[3]/15000 << " microseconds " << results[3]/15 << " ns\n";
                std::cout << "Removing  given  element: " << results[4]/15000000 << " ms " << results[4]/15000 << " microseconds " << results[4]/15 << " ns\n";
                std::cout << "Removing  last   element: " << results[5]/15000000 << " ms " << results[5]/15000 << " microseconds " << results[5]/15 << " ns\n";
                std::cout << "Searching for    element: " << results[6]/15000000 << " ms " << results[6]/15000 << " microseconds " << results[6]/15 << " ns\n";
                std::cout << "\n\nEnd of test, press ENTER to continue..." << std::endl;
                std::cin.ignore(10000, '\n');
                getchar();
                break;
            } //automatyczny test listy
            case 7: {
                std::cout << "\nBeginning automatic heap test\n";
                long results[3] = {0, 0,0};
                for(int i = 0; i < 15; i++) {
                    std::cout << "\nTest nr: " << i + 1;
                    FileRandomizer::knownSizeWrite(size);
                    AutomaticTester::testHeap(results, i + 1);
                }
                std::cout << "\nHeap test average results" << std::endl;
                std::cout << "Adding        element: " << results[0]/15000000 << " ms " << results[0]/15000 << " microseconds " << results[0]/15 << " ns\n";
                std::cout << "Removing      element: " << results[1]/15000000 << " ms " << results[1]/15000 << " microseconds " << results[1]/15 << " ns\n";
                std::cout << "Searching for element: " << results[2]/15000000 << " ms " << results[2]/15000 << " microseconds " << results[2]/15 << " ns\n";
                std::cout << "\n\nEnd of test, press ENTER to continue..." << std::endl;
                std::cin.ignore(10000, '\n');
                getchar();
                break;
            } //automatyczny test kopca
            case 8: {
                std::cout << "\nBeginning automatic BST tree test\n";
                long results[3] = {0, 0, 0};
                for(int i = 0; i < 15; i++) {
                    std::cout << "\nTest nr: " << i + 1;
                    FileRandomizer::knownSizeWrite(size);
                    AutomaticTester::testBST(results, i + 1);
                }
                std::cout << "\nBST test average results" << std::endl;
                std::cout << "Searching for element: " << results[0]/15000000 << " ms " << results[0]/15000 << " microseconds " << results[0]/15 << " ns\n";
                std::cout << "Adding        element: " << results[1]/15000000 << " ms " << results[1]/15000 << " microseconds " << results[1]/15 << " ns\n";
                std::cout << "Deleting      element: " << results[2]/15000000 << " ms " << results[2]/15000 << " microseconds " << results[2]/15 << " ns\n";
                std::cout << "\n\nEnd of test, press ENTER to continue..." << std::endl;
                std::cin.ignore(10000, '\n');
                getchar();
                break;
            } //automatyczny test BST
            case 9:
                std::cout << "Give size of structure: ";
                std::cin >> size;
                while(size <= 0){
                    std::cout << "Wrong answer, try again\n";
                    std::cin >> size;
                }
            case 10:
                break;
            default: {
                std::cout << "\nWrong answer, try again\n";
                break;
            }
        }
    } while (answer != 10);

    return 0;
}

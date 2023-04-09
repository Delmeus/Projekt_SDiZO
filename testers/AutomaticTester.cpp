//
// Created by Antek on 23.03.2023.
//

#include "AutomaticTester.h"
#include "random"
#include "../utils/Timer.h"
#include "fstream"
#include "../structures/table/Table.h"
#include "iostream"
#include "../structures/list/List.h"
#include "../structures/heap/Heap.h"
#include "../structures/tree/Tree.h"


AutomaticTester::AutomaticTester() = default;

void AutomaticTester::testTable(long results[6], int i) {
    //utworzenie struktury
    auto table = Table();
    //utworzenie stopera
    auto timer = Timer();
    timer.start();
    table.createTable();
    timer.stop();
    //wyznaczenie ścieżki pliku z wynikami
    std::string s1 = std::to_string(table.size);
    std::string s2 = "results/table/table" + s1 + ".txt";
    std::ofstream file;
    //jeżeli wykonujemy test nr 1 to otwieramy plik w trybie nadpisywania
    if(i == 1) file.open(s2);
    //w innym przypadku dopisujemy dane
    else file.open(s2, std::ios::app);
    if (file.is_open()) {
        int value, position;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 1000000);
        std::uniform_int_distribution<> distribution(1, table.size);

        //wylosowanie wartosci
        value = dis(gen);
        file << "Test nr: " << i << std::endl;

        file << "CZAS TWORZENIA TABLICY " << timer.mili() << " milisekund\n";
        std::cout << "\nCreation of table:                  " << timer.mili() << " miliseconds";

        //test dodawania wartosci na początek tablicy
        timer.start();
        table.addElementBeginning(value);
        timer.stop();
        std::cout << "\nAdding element at the beginning:    " << timer.micro() << " microseconds\n";
        file << "Dodawanie elementu na początek " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[0] += timer.nano();

        //test dodawania wartosci na podaną pozycję tablicy
        position = distribution(gen);
        timer.start();
        table.addElementPosition(value, position);
        timer.stop();
        std::cout << "Adding element at given position:   "<< timer.micro() << " microseconds\n";
        file << "Dodawanie elementu na pozycje  " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[1] += timer.nano();

        //test dodawania wartosci na koniec tablicy
        value = dis(gen);
        timer.start();
        table.addElementEnd(value);
        timer.stop();
        std::cout << "Adding element at the end:          " << timer.micro() << " microseconds\n";
        file << "Dodawanie elementu na koniec   " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[2] += timer.nano();

        //test usuwania elementu z początku
        timer.start();
        table.deleteElementBeginning();
        timer.stop();
        std::cout << "Deleting first element:             " << timer.micro() << " microseconds\n";
        file << "Usuwanie elementu z poczatku   " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[3] += timer.nano();

        //test usuwania elementu z pozycji
        position = distribution(gen);
        timer.start();
        table.deleteElementPosition(position);
        timer.stop();
        std::cout << "Deleting element from position:     " << timer.micro() << " microseconds\n";
        file << "Usuwanie elementu z pozycji    " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[4] += timer.nano();

        //test usuwania elementu z końca
        timer.start();
        table.deleteElementEnd();
        timer.stop();
        std::cout << "Deleting element from the end:      "<< timer.micro() << " microseconds\n";
        file << "Usuwanie elementu z konca      " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[5] += timer.nano();

        file.close();
    }

}

void AutomaticTester::testList(long results[6], int i) {
    //utworzenie listy
    auto list = List();
    auto timer = Timer();
    timer.start();
    list.createList();
    timer.stop();
    std::string s1= std::to_string(list.size);
    std::string s2 = "results/list/list" + s1 + ".txt";
    std::ofstream file;
    //jeżeli wykonujemy test nr 1 to otwieramy plik w trybie nadpisywania
    if(i == 1) file.open(s2);
    //w innym przypadku dopisujemy dane
    else file.open(s2, std::ios::app);
    if (file.is_open()) {

        int value, position;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 1000000);
        std::uniform_int_distribution<> distribution(1, list.size);

        value = dis(gen);
        file << "Test nr: " << i << std::endl;

        file << "CZAS TWORZENIA LISTY " << timer.mili() << " milisekund\n";
        std::cout << "\nCreation of list:                   " << timer.mili() << " miliseconds\n";
        //test dodawania wartosci na początek
        timer.start();
        list.addElementBeginning(value);
        timer.stop();
        std::cout << "\nAdding element at the beginning:    " << timer.nano() << " nanoseconds\n";
        file << "Dodawanie elementu na początek " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[0] += timer.nano();

        //test dodawania wartosci na podaną pozycję
        position = distribution(gen);
        timer.start();
        list.addElementPosition(value, position);
        timer.stop();
        std::cout << "Adding element at given position:   "<< timer.micro() << " microseconds\n";
        file << "Dodawanie elementu na pozycje  " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[1] += timer.nano();

        //test dodawania wartosci na koniec
        value = dis(gen);
        timer.start();
        list.addElementEnd(value);
        timer.stop();
        std::cout << "Adding element at the end:          " << timer.nano() << " nanoseconds\n";
        file << "Dodawanie elementu na koniec   " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[2] += timer.nano();

        //test usuwania elementu z początku
        timer.start();
        list.deleteFirstElement();
        timer.stop();
        std::cout << "Deleting first element:             " << timer.nano() << " nanoseconds\n";
        file << "Usuwanie elementu z poczatku   " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[3] += timer.nano();

        //test usuwania elementu z pozycji
        position = distribution(gen);
        timer.start();
        list.deleteElementPosition(position);
        timer.stop();
        std::cout << "Deleting element from position:     " << timer.micro() << " microseconds\n";
        file << "Usuwanie elementu z pozycji    " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[4] += timer.nano();

        //test usuwania elementu z końca
        timer.start();
        list.deleteLastElement();
        timer.stop();
        std::cout << "Deleting element from the end:      "<< timer.nano() << " nanoseconds\n";
        file << "Usuwanie elementu z konca      " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[5] += timer.nano();

        file.close();
    }
}

void AutomaticTester::testHeap(long results[2], int i) {
    //tworzenie kopca
    auto heap = Heap();
    auto timer = Timer();
    timer.start();
    heap.createHeap();
    timer.stop();

    std::string s1 = std::to_string(heap.size);
    std::string s2 = "results/heap/heap" + s1 + ".txt";
    std::ofstream file;
    //jeżeli wykonujemy test nr 1 to otwieramy plik w trybie nadpisywania
    if(i == 1) file.open(s2);
    //w innym przypadku dopisujemy dane
    else file.open(s2, std::ios::app);
    if (file.is_open()) {

        int value;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 1000000);

        file << "Test nr: " << i << std::endl;

        std::cout << "\nCreation of heap: " << timer.mili() << " milisekund\n";
        file << "CZAS TWORZENIA KOPCA " << timer.mili() << " milisekund\n";
        //test dodawania elementu
        value = dis(gen);
        timer.start();
        heap.insertElement(value);
        timer.stop();
        std::cout << "Adding element: " << timer.micro() << " microseconds " << timer.nano() << " n\n";
        file << "Dodawanie elementu " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[0] += timer.nano();

        //test usuwania elementu
        timer.start();
        heap.deleteElement();
        timer.stop();
        std::cout << "Deleting element: " << timer.micro() << " microseconds " << timer.nano() << " ns\n";
        file << "Usuwanie elementu " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[1] += timer.nano();

    }
}

void AutomaticTester::testBST(long results[3], int i) {
    //tworzenie drzewa
    auto tree = Tree();
    auto timer = Timer();
    timer.start();
    tree.createTree();
    timer.stop();
    std::string s1= std::to_string(tree.getSize(tree.root));
    std::string s2 = "results/tree/tree" + s1 + ".txt";
    std::ofstream file;
    //jeżeli wykonujemy test nr 1 to otwieramy plik w trybie nadpisywania
    if(i == 1) file.open(s2);
    //w innym przypadku dopisujemy dane
    else file.open(s2, std::ios::app);
    if (file.is_open()) {

        int value;
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 1000000);

        file << "Test nr: " << i << std::endl;

        file << "CZAS TWORZENIA DRZEWA BST: " << timer.mili() << " milisekund" << std::endl;
        std::cout << "\nCreation of BST tree: " << timer.mili() << " miliseconds";

        //test wyszukiwania elementu
        value = dis(gen);
        timer.start();
        tree.searchForNode(value, tree.root);
        timer.stop();
        std::cout << "\nSearching for element " << timer.micro() << " microseconds " << timer.nano() << " nanoseconds";
        file << "Wyszukiwanie elementu " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[0] += timer.nano();

        //test dodawania elementu
        value = dis(gen);
        timer.start();
        tree.insertNode(value);
        timer.stop();
        std::cout << "\nAdding element        " << timer.micro() << " microseconds " << timer.nano() << " nanoseconds";
        file << "Dodawanie elementu " << timer.micro() << " mikrosekund " << timer.nano() << " nanosekund\n";
        results[1] += timer.nano();
        //pętla zapewniająca że podany element istnieje i można go usunąć
        do{
            value = dis(gen);
        }while(tree.searchForNode(value, tree.root) == nullptr);

        //test usuwania elementu
        timer.start();
        tree.deleteNode(value, tree.root);
        timer.stop();
        std::cout << "\nDeleting node         "  << timer.micro() << " microseconds " << timer.nano() << " nanoseconds\n";
        file << "Usuwanie elementu " << timer.micro() << " microseconds " << timer.nano() << " nanoseconds\n";
        results[2] += timer.nano();
    }
}

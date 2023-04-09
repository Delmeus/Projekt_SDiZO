//
// Created by Antek on 21.03.2023.
//
#include "string"
#include <iostream>
#include <fstream>
#include "sstream"
#include "Table.h"

Table::Table() {
    Table::pointer = nullptr;
    Table::size = 0;
}

Table::~Table() {
    //zwolnienie miejsca
    delete[] pointer;
    pointer = nullptr;
}
void Table::createTable() {

    std::ifstream file(R"(iofiles\structure.txt)");
    if (file.is_open()) {
        std::string line;
        int fileSize = 0;
        std::getline(file, line);
        //zczytanie rozmiaru struktury
        (std::istringstream(line)) >> fileSize;

        if(fileSize > 0) {

            int i = 0;
            pointer = new int[fileSize];
            int value;
            while (std::getline(file, line)) { //wpisywanie wartosci z pliku do tablicy
                std::istringstream iss(line);
                iss >> value;
                pointer[i] = value;
                i++;
            }

            size = fileSize;

        }
        file.close();

    }
}

void Table::addElementBeginning(int value) {
    //alokacja pamięci na tablicę tymczasową ze zmienionym rozmiarem
    int *tempPointer = new int[size + 1];
    tempPointer[0] = value;

    //spisywanie wartosci z tablciy przesuwając je o jeden w prawo
    for(int i = 0; i < size; i++){
        tempPointer[i + 1] = pointer[i];
    }

    //zwalnianie pamięci i przypisywanie pod zmienną pointer nową tablicę
    delete[] pointer;
    pointer = tempPointer;
    tempPointer = nullptr;
    delete[] tempPointer;
    //zwiększanie zmiennej przechowującej aktualny rozmiar
    size++;
}

void Table::addElementEnd(int value) {
    //alokacja pamięci na tablicę tymczasową ze zmienionym rozmiarem
    int *tempPointer = new int[size + 1];

    //spisywanie wartości z tablciy
    for(int i = 0; i < size; i++){
        tempPointer[i] = pointer[i];
    }

    tempPointer[size] = value;
    //zwalnianie pamięci i przypisywanie pod zmienną pointer nową tablicę
    delete[] pointer;
    pointer = tempPointer;
    tempPointer = nullptr;
    delete[] tempPointer;
    //zwiększanie zmiennej przechowującej aktualny rozmiar
    size++;
}

void Table::addElementPosition(int value, int position) {
    //sprawdzenie czy podany indeks nie jest pierwszym lub ostatnim
    //jesli jest to uzywamy odpowiadającej tej sytuacji metode
    if(position == 0) addElementBeginning(value);
    else if(position == size - 1) addElementEnd(value);

    else if(position > 0 && position < size){
        //alokacja pamięci na tablicę tymczasową ze zmienionym rozmiarem
        int *tempPointer = new int[size + 1];

        //spisywanie pierwszej części tablicy
        for (int i = 0; i < position; i++) {
            tempPointer[i] = pointer[i];
        }

        //spisywanie zadanej watosci na podany indeks
        tempPointer[position] = value;

        //spisywanie reszty
        for (int i = position + 1; i < size + 1; i++) {
            tempPointer[i] = pointer[i - 1];
        }

        //zwalnianie pamięci i przypisywanie pod zmienną pointer nową tablicę
        delete[] pointer;
        pointer = tempPointer;
        tempPointer = nullptr;
        delete[] tempPointer;
        //zwiększanie zmiennej przechowującej aktualny rozmiar
        size++;
    }
    else std::cout << "\nThere is no such position in table\n";
}

void Table::deleteElementBeginning() {
    if (size > 0) {
        //alokacja pamięci na tablicę tymczasową ze zmienionym rozmiarem
        int *tempPointer = new int[size - 1];

        //przepisywanie całej tablicy z wyjątkiem pierwszego elementu
        for (int i = 0; i < size - 1; i++) {
            tempPointer[i] = pointer[i + 1];
        }

        //zwalnianie pamięci i przypisywanie pod zmienną pointer nową tablicę
        delete[] pointer;
        pointer = tempPointer;
        tempPointer = nullptr;
        delete[] tempPointer;
        //zmniejszanie zmiennej przechowującej aktualny rozmiar
        size--;
    }
    else std::cout << "\nTable does not exist!";

}

void Table::deleteElementEnd() {
    if(size > 0) {
        //alokacja pamięci na tablicę tymczasową ze zmienionym rozmiarem
        int *tempPointer = new int[size - 1];

        //przepisywanie calej tablicy z wyjatkiem ostatniego elementu
        for (int i = 0; i < size - 1; i++) {
            tempPointer[i] = pointer[i];
        }

        //zwalnianie pamięci i przypisywanie pod zmienną pointer nową tablicę
        delete[] pointer;
        pointer = tempPointer;
        tempPointer = nullptr;
        delete[] tempPointer;
        //zmniejszanie zmiennej przechowującej aktualny rozmiar
        size--;
    }
    else std::cout << "\nTable does not exist!";

}

void Table::deleteElementPosition(int position) {
    //sprawdzenie czy podany indeks nie jest pierwszym lub ostatnim
    //jesli jest to uzywamy odpowiadającej tej sytuacji metode
    if(position == 0) deleteElementBeginning();
    else if(position == size - 1) deleteElementEnd();

    else if(position > 0 && position < size) {
        //alokacja pamięci na tablicę tymczasową ze zmienionym rozmiarem
        int *tempPointer = new int[size - 1];

        //pętla odpowiednio spisująca dane to tablicy tymczasowej, pomija indeks, który chcemy usunąć
        for (int i = 0; i < size; i++) {
            if (i < position) {
                tempPointer[i] = pointer[i];
            } else if (i > position) {
                tempPointer[i - 1] = pointer[i];
            }
        }

        //zwalnianie pamięci i przypisywanie pod zmienną pointer nową tablicę
        delete[] pointer;
        pointer = tempPointer;
        tempPointer = nullptr;
        delete[] tempPointer;
        //zmniejszanie zmiennej przechowującej aktualny rozmiar
        size--;
    }
    else std::cout << "\nThere is no such position in table\n";
}

void Table::showTable() const {
    if(doesExist()){
           for(int i = 0; i < size; i++){
               std::cout << i << ". | " << pointer[i] << std::endl;
           }
    } else std::cout << "\nTable does not exist!";
}

bool Table::doesExist() const {
    return pointer != nullptr;
}

//void Table::saveTableToFile() const{
//    std::ofstream file(R"(iofiles\output.txt)");
//    if(file.is_open() && pointer != nullptr){
//        for(int i = 0; i < size; i++){
//            file << pointer[i] << std::endl;
//        }
//    }
//    file.close();
//}
//

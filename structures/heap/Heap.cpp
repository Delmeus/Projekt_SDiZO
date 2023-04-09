//
// Created by Antek on 27.03.2023.
//

#include <sstream>
#include "Heap.h"
#include "iostream"
#include "fstream"

Heap::Heap() {
    pointer = nullptr;
    size = 0;
}

Heap::~Heap() {
    delete[] pointer;
    pointer = nullptr;
}

//funkcja obliczająca indeks rodzica
int Heap::parent(int i) { return (i-1)/2; }

void Heap::createHeap() {
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
            while (std::getline(file, line)) { //wpisywanie wartosci z pliku do kopca
                std::istringstream iss(line);
                iss >> value;
                //możemy użyć metody dodawania elementu, ponieważ metoda ta poprawia na bieżąco strukturę kopca
                insertElement(value);
                i++;
            }

            size = fileSize;

        }
        file.close();

    }
}

void Heap::insertElement(int value){
    //zwiększamy zmienną przechowującą rozmiar
    size++;
    int i = size - 1;
    //dodajemy nową wartość na końcu tablicy
    pointer[i] = value;

    //poprawiamy strukturę kopca
    while (i != 0 && pointer[parent(i)] > pointer[i])
    {
        swap(&pointer[i], &pointer[parent(i)]);
        i = parent(i);
    }
}

void Heap::deleteElement() {

    //alokacja pamięci na tablicę tymczasową ze zmienionym rozmiarem
    int *tempPointer = new int[size - 1];

    //przepisywanie calej tablicy z wyjatkiem ostatniego elementu
    for (int i = 0; i < size - 1; i++) {
        tempPointer[i] = pointer[i];
    }

    //zwalnianie pamięci i przypisywanie pod zmienną pointer nową tablicę
    delete[] pointer;
    pointer = tempPointer;

    //zmniejszanie zmiennej przechowującej aktualny rozmiar
    size--;

}

//wyswietlanie kopca
void Heap::showHeap() const {
    if (pointer != nullptr) {
        for (int i = 0; i < size; i++) {
            std::cout << pointer[i] << std::endl;
        }
    } else {
        std::cout << "\nNo elements";
    }
}

void Heap::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

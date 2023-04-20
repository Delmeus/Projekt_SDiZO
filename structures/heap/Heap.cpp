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
    maxSize = 10000000;
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
            pointer = new int[maxSize];
            int value;
            while (std::getline(file, line)) { //wpisywanie wartosci z pliku do kopca
                std::istringstream iss(line);
                iss >> value;
                //możemy użyć metody dodawania elementu, ponieważ metoda ta poprawia na bieżąco strukturę kopca
                insertElement(value);
                i++;
            }
            for(i; i < maxSize; i++) pointer[i] = 0;
            size = fileSize;

        }
        file.close();

    }
}

void Heap::insertElement(int value){
    //jeżeli rozmiar nie osiągnął maksymalnego
    if(size + 1 < maxSize) {
        //zwiększamy zmienną przechowującą rozmiar
        size++;
        int i = size - 1;

        //dodajemy nową wartość na końcu tablicy
        pointer[i] = value;

        //poprawiamy strukturę kopca
        while (i != 0 && pointer[i] < pointer[parent(i)]) {
            //zamieniamy wartość z ojcem
            swap(&pointer[i], &pointer[parent(i)]);
            i = parent(i);
        }
    }
    else std::cout << "\nSIZE LIMIT REACHED\n";

}

void Heap::deleteElement() {
    //jeśli są elementy w kopcu
    if(size > 0) {

        int lastElement = pointer[size - 1];
        //ustawiamy ostatni element na 0
        pointer[size - 1] = 0;
        //przypisujemy pierwszy element jako ostatni
        pointer[0] = lastElement;
        //zmniejszamy rozmiar
        size--;
        //poprawiamy strukturę kopca
        heapify(0);

    }
    else std::cout << "\nHeap has no elements!\n";

}


//wyswietlanie kopca
void Heap::showHeap(int space, int index){
    if(size > 0) {
        const int maxConsoleWidth = 120;

        space += 10;

        std::cout << std::endl;

        if (index * 2 + 2 < size) {
            showHeap(space, index * 2 + 2);
        }

        std::cout << std::endl;

        const int nodeValueLength = std::to_string(pointer[index]).length();
        for (int i = size; i < std::min(space, maxConsoleWidth - nodeValueLength); i++) {
            std::cout << " ";
        }
        std::cout << pointer[index] << std::endl;

        if (index * 2 + 1 < size) {
            showHeap(space, index * 2 + 1);
        }
    }
    else std::cout << "\nHeap has no elements!\n";

}

void Heap::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//wyszukiwanie elementu
bool Heap::findValue(int value) {
    //iterujemy po każdym elemencie
    for(int i = 0; i < size; i++){
        //jesli znaleziono element zwroc true
        if(pointer[i] == value) {
            std::cout << "\nValue was found\n";
            return true;
        }
    }
    //jesli nie znaleziono elementu zwroc false
    std::cout << "\nValue was not found\n";
    return false;
}

void Heap::heapify(int i) {
    //przypisujemy indeks najmniejszego elementu jako indeks podanego węzła
    int smallest = i;
    int left = 2 * smallest + 1;
    int right = 2 * smallest + 2;
    //sprawdzamy czy lewy syn jest mniejszy niż aktualny najmniejszy element
    if(left < size && pointer[left] < pointer[smallest]) smallest = left;
    //sprawdzamy czy prawy syn jest mniejszy niż aktualny najmniejszy element
    if(right < size && pointer[right] < pointer[smallest]) smallest = right;
    //jeśli najmniejszy element nie jest na swoim miejscu
    if(smallest != i){
        //zamieniamy elementy
        swap(&pointer[i], &pointer[smallest]);
        //poprawiamy strukturę poddrzewa
        heapify(smallest);
    }
}

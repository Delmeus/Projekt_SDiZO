//
// Created by Antek on 23.03.2023.
//

#include <sstream>
#include <iostream>
#include "List.h"
#include "fstream"

List::List() {
    firstElement = nullptr;
    lastElement = nullptr;
    currentElement = nullptr;
    size = 0;
}

List::~List() {

    for (int i = 0; i < size; i++) {
        //Przypisz następny element jako bieżący
        currentElement = firstElement->next;
        //Usuń pierwszy element
        delete firstElement;
        //ustaw bieżący element jako pierwszy
        firstElement = currentElement;
    }

}

void List::createList(){
    std::ifstream file(R"(iofiles\structure.txt)");
    if(file.is_open()){

        std::string line;
        int fileSize = 0;
        std::getline(file, line);
        (std::istringstream(line)) >> fileSize;
        if(fileSize > 0) {

            int value;

            while (std::getline(file, line)) { //wpisywanie wartosci
                std::istringstream iss(line);
                iss >> value;
                //dodajemy tutaj element na koniec, poniewaz
                //funkcja dodawania na koniec wykryje gdy nie ma pierwszego elementu
                addElementEnd(value);
            }
        }
        size = fileSize;
        file.close();
    }
}

void List::addElementBeginning(int value) {
    //sprawdzenie czy istnieje pierwszy element tablicy
    if(firstElement == nullptr){
        //utworzenie elementu i ustawienie go jako pierwszego
        firstElement = new ListElement(value, nullptr, nullptr);
        lastElement = firstElement;
    }
    else{
        currentElement = firstElement;
        firstElement = new ListElement(value, currentElement, nullptr);
        currentElement->previous = firstElement; // currentElement->previous = firstElement;
    }
    //zwiększamy zmienną przechowującą rozmiar
    size++;
}

void List::addElementEnd(int value) {
    //Sprawdź, czy istnieje element początkowy
    if (firstElement == nullptr) {
        //Utwórz nowy element i ustaw go jako element początkowy i końcowy
        lastElement = new ListElement(value, nullptr, nullptr);
        firstElement = lastElement;

    } else {
        //Ustaw element który był ostatnim jako aktualny
        currentElement = lastElement;
        //Zastąp ostatni element nowym
        //Ustaw jego wartość oraz element poprzedni na element aktualny (były ostatni)
        lastElement = new ListElement(value, nullptr, currentElement);
        currentElement->next = lastElement;
    }
    //zwiększamy zmienną przechowującą rozmiar
    size++;
}

void List::addElementPosition(int value, int position) {
    //Sprawdź czy wybrana pozycja jest pierwszą
    if (position == 0) {
        addElementBeginning(value);
        return;
    }

    //Sprawdź czy wybrana pozycja jest ostatnią
    if (position == size) {
        addElementEnd(value);
        return;
    }

    //Sprawdzenie w ktorej polowie listy znajduje sie wybrany indeks
    if (position < size / 2) { //liczone od indeksu zerowego

        //Przypisz za aktualny element pierwszy
        currentElement = firstElement;

        //Przesuń wszyskie elementy o jeden dalej
        for (int i = 1; i < position; i++) {
            currentElement = currentElement->next;
        }

    } else {

        //Przypisz za aktualny element ostatni
        currentElement = lastElement;

        //Przesuń wszystkie elementy o jedną pozycję wstecz
        for (int i = 0; i < size - position; i++) {
            currentElement = currentElement->previous;
        }

    }

    //Stwórz nowy element listy z podanymi parametrami
    auto *newListElement = new ListElement(value, currentElement->next,currentElement);

    //przypisz nowy element w odpowiednim miejscu tablicy
    currentElement->next->previous = newListElement;
    currentElement->next = newListElement;

    //delete newListElement;

    //zwiększamy zmienną przechowującą rozmiar
    size++;
}

void List::deleteFirstElement() {

    if(size == 1){
        firstElement = nullptr;
        lastElement = nullptr;
        currentElement = nullptr;
        size = 0;
    }
    else if(size > 1){
        //ustawiamy drugi element jako bieżący
        currentElement = firstElement->next;
        //usuwamy pierwszy element
        delete firstElement;
        //ustawiamy poprzedni element aktualnego jako null
        currentElement->previous = nullptr;
        //ustawiamy bieżący element jako pirwszy
        firstElement = currentElement;
        //zmniejszamy zmienną przechowującą rozmiar
        size--;
    }
    else std::cout << "\nThere is no list!\n";
}

void List::deleteLastElement() {

    //jeżeli rozmiar jest równy jeden to usuwamy listę
    if(size == 1){
        firstElement = nullptr;
        lastElement = nullptr;
        currentElement = nullptr;
        size = 0;
    }
    else if(size > 1){
        //jako bieżący element przypisujemy przedostatni element
        currentElement = lastElement->previous;

        //usuwamy ostatni element
        delete lastElement;
        //bieżącemu elementowi przypisujemy null jako następny element
        currentElement->next = nullptr;
        //ostatni element ustawiamy jako bieżący
        lastElement = currentElement;
        //zmniejszamy zmienną przechowującą rozmiar
        size--;
    }
    else std::cout << "\nThere is no list!\n";
}

void List::deleteElementPosition(int position) {

    //sprawdzenie czy podana pozycja nie znajduje się na którejś ze skrajnych pozycji
    //jeśli tak to wykonujemy odpowiednie funkcje
    if(position == 0) deleteFirstElement();
    else if(position == size - 1) deleteLastElement();

    else if(position < size){
        //sprawdzamy w której poóowie znajduje sió usuwany element aby szybciej do niego dotrzeó
        if(position < size/2){
            currentElement = firstElement;
            for(int i = 1; i < position; i++){
                currentElement = currentElement->next;
            }
        }
        else{
            currentElement = lastElement;
            for(int i = 0; i < size - position - 1; i++){
                currentElement = currentElement->previous;
            }
        }

        //ustawiamy elementom odpowiednie elementy następujace i poprzedzające
        currentElement->previous->next = currentElement->next;
        currentElement->next = currentElement->next->next;

        //usuwamy bieżący element
        delete currentElement;
        //zmniejszamy rozmiar
        size--;
    }
    else std::cout << "\nThere is no such index!\n";
}

//wyświetlanie listy
void List::showList() {
    if(size < 1){
        std::cout << "\nThere is no list!\n";
        return;
    }
    currentElement = firstElement;
    for(int i = 0; i < size; i++){
        std::cout << currentElement->value << std::endl;
        currentElement = currentElement->next;
    }
}

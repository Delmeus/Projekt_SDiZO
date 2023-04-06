//
// Created by Antek on 14.03.2023.
//

#include <iostream>
#include "FileRandomizer.h"
#include "fstream"
#include "random"

//ta kalsa odpowiedzialna jest za generowanie pseudolosowych liczb i wpisywanie ich do pliku structure.txt
//na podstawie tego pliku tworzone są struktury

void FileRandomizer::knownSizeWrite(int size) {

    //R"(E:\Studia\IV semestr\SDiZO\Projekt\projekt_pierwszy\structure.txt)"
    std::ofstream file(R"(E:\Studia\IV semestr\SDiZO\Projekt\projekt_pierwszy\iofiles\structure.txt)");
    int val;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000000);
    file << size << "\n";
    for (int i = 0; i < size; i++)
    {
        val = dis(gen); // wygeneruj liczbę
        file << val << "\n";
    }
    file.close();
}


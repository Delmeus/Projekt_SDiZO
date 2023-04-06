//
// Created by Antek on 28.03.2023.
//

#include <sstream>
#include "Tree.h"
#include "fstream"
#include "iostream"


Tree::Tree() {
    root = nullptr;
    size = 0;

}

Tree::~Tree() {
    //dopóki istnieje korzeń
    while(root) {
        //usunięcie korzenia
        deleteNode(root->value, root);
    }
    root = nullptr;
}

void Tree::createTree() {
    std::ifstream file(R"(E:\Studia\IV semestr\SDiZO\Projekt\projekt_pierwszy\iofiles\structure.txt)");
    if (file.is_open()) {

        std::string line;
        int fileSize = 0;
        std::getline(file, line);
        (std::istringstream(line)) >> fileSize;

        if(fileSize > 0) {

            while (std::getline(file, line)) { //wpisywanie wartosci z pliku do drzewa
                std::istringstream iss(line);
                int value;
                iss >> value;
                insertNode(value);
            }

        }
        size = getSize(root);
        file.close();
    }

}



void Tree::insertNode(int value) {
    //sprawdzamy czy istnieje korzeń
    if(root == nullptr){
        root = new Node(value);
        size = 1;
    }

    else{
        auto temp = root;
        while(temp != nullptr){
            //jeżeli isntnieje już zadana wartość
            if(value == temp->value){
                //sprawdzamy czy istnieje prawy syn
                if(temp->right == nullptr) {
                    //jeśli nie to tworzymy nowy element
                    temp->right = new Node(value);
                    return;
                }
                //jeśli istnieje prawy syn to przechodzimy dalej
                else temp = temp->right;
            }
            //jeżeli wartośc jest większa od aktualnego elementu, a element nie ma prawego syna to wpisujemy tą daną wartość
            else if(value > temp->value && temp->right == nullptr){
                temp->right = new Node(value);
                return;
            }
            //jeżeli wartośc jest większa od aktualnego elementu, a element ma prawego syna to aktualny element ustawiamy jako tego syna
            else if(value > temp->value) {
                temp = temp->right;
            }
            //jeżeli wartośc jest mniejsza od aktualnego elementu, a element nie ma lewego syna to wpisujemy tą daną wartość
            else if(value < temp->value && temp->left == nullptr){
                temp->left = new Node(value);
                return;
            }
            //jeżeli wartośc jest mniejsza od aktualnego elementu, a element ma lewego syna to aktualny element ustawiamy jako tego syna
            else {
                temp = temp->left;
            }
        }
    }
}

//znajdowanie minimum dla danego węzła
Node *Tree::findMin(Node *node){
    auto temp = node;
    while(temp && temp->left != nullptr) temp = temp->left;
    return temp;
}

//są problemy ale to chodzi chyba o wywołanie
Node *Tree::deleteNode(int value, Node *node) {

    //jeśli podany element nie istnieje
    if(node == nullptr) return node;
    //jesli podany element jest mniejszy niz aktualny, szukamy odpowiedniego elementu
    if(value < node->value) node->left = deleteNode(value, node->left);
    //jesli podany element jest większy niż aktualny, szukamy odpowiedniego elementu
    else if(value > node->value) node->right = deleteNode(value, node->right);
    else {
        //brak syna
        if(node->left == nullptr && node->right == nullptr){
            //sprawdzenie czy podany element nie jest korzeniem
            if(node == root) {
                root = nullptr;
            } else {
                delete node;
                node = nullptr;
            }
        }
        //syn po prawej stronie
        else if(node->left == nullptr){
            auto temp = node->right;
            //sprawdzenie czy podany element nie jest korzeniem
            if(node == root) {
                root = temp;
            } else {
                delete node;
                node = nullptr;
                return temp;
            }
        }
            //syn po lewej stronie
        else if(node->right == nullptr){
            auto temp = node->left;
            //sprawdzenie czy podany element nie jest korzeniem
            if(node == root) {
                root = temp;
            } else {
                delete node;
                node = nullptr;
                return temp;
            }
        }
            //2 synów
        else {
            //szukamy najmniejszej wartości prawego syna
            auto temp = findMin(node->right);
            //przypisujemy wartość owego minimum do naszego elementu
            node->value = temp->value;
            //usuwamy to minimum
            node->right = deleteNode(temp->value, node->right);
        }
    }
    return node;

}

//obliczanie rozmiaru
int Tree::getSize(Node *node){
    if(node == nullptr){
        return 0;
    }
    return 1 + getSize(node->left) + getSize(node->right);
}


Node *Tree::searchForNode(int value, Node *node) {
    if(node != nullptr){
        //jesli znaleziono wartosc to komunikujemy to
        if(value == node->value){
#ifdef test
            std::cout <<"\nValue was found!\n";
#endif
        }
        //jeśli wartość jest większa niż podana sprawdzamy prawego syna
        else if(value > node->value) node = searchForNode(value, node->right);
        //jeśli wartość jest mniejsza niż podana sprawdzamy lewego syna
        else node = searchForNode(value, node->left);
    }
    return node;
}

void Tree::showTree(Node *node, int space) { //drukuje od lewej do prawej

    if (node == nullptr) {
        return;
    }

    //ustawienie maksymalnego rozmiaru konsoli, bez tego program mógł się zcrashować
    const int maxConsoleWidth = 120;

    space += 10;
    //najpierw wyświetlamy prawego syna, będzie on wyświetlony u góry
    showTree(node->right, space);

    std::cout << std::endl;
    const int nodeValueLength = std::to_string(node->value).length();
    for (int i = getSize(root); i < std::min(space, maxConsoleWidth - nodeValueLength); i++) {
        std::cout << " ";
    }
    std::cout << node->value << std::endl;
    //lewi synowie będą na dole
    showTree(node->left, space);


}

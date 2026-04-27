// Lista.cpp - Exemplo de vector (equivalente a ArrayList)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // CRIANDO VECTOR (lista dinâmica)
    vector<string> nomes;
    
    // ADICIONANDO ELEMENTOS
    nomes.push_back("Ana");        // push_back() no final
    nomes.push_back("Bruno");
    nomes.insert(nomes.begin()+1, "Carla"); // insert(posição, elemento)
    
    // TAMANHO
    cout << "Tamanho: " << nomes.size() << endl;
    
    // PERCORRENDO COM FOR EACH (C++11)
    cout << "Nomes: ";
    for (string nome : nomes) {
        cout << nome << " ";
    }
    cout << endl;
    
    // ACESSANDO POR ÍNDICE
    cout << "Primeiro: " << nomes[0] << endl;
    cout << "Primeiro (seguro): " << nomes.at(0) << endl;
    
    // REMOVENDO
    nomes.erase(nomes.begin()+1); // erase por posição
    cout << "Após remoção: ";
    for (string n : nomes) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}

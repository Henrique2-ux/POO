// Construtor.cpp - Exemplo de construtores em C++
#include <iostream>
#include <string>
using namespace std;

class Construtor {
private:
    string nome;
    int idade;

public:
    // CONSTRUTOR PADRÃO (sem parâmetros)
    Construtor() {
        nome = "Anônimo";
        idade = 0;
        cout << "Construtor padrão chamado" << endl;
    }
    
    // CONSTRUTOR PARAMETRIZADO (sobrecarga)
    Construtor(string n, int i) {
        nome = n;
        idade = i;
        cout << "Construtor parametrizado chamado" << endl;
    }
    
    // Método para exibir
    void exibir() {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};

int main() {
    // Usando construtor padrão
    Construtor obj1;
    obj1.exibir();
    
    // Usando construtor parametrizado
    Construtor obj2("Maria", 25);
    obj2.exibir();
    
    return 0;
}

// Encapsulamento.cpp - Exemplo com private + getters/setters
#include <iostream>
#include <string>
using namespace std;

class Encapsulamento {
private:
    // ATRIBUTOS PRIVADOS (encapsulados)
    string marca;
    double preco;

public:
    // CONSTRUTOR
    Encapsulamento(string m, double p) {
        setMarca(m);
        setPreco(p);
    }
    
    // GETTERS (leitura)
    string getMarca() { return marca; }
    double getPreco() { return preco; }
    
    // SETTERS (escrita com validação)
    void setMarca(string m) {
        if (!m.empty()) {
            marca = m;
        } else {
            marca = "Sem marca";
        }
    }
    
    void setPreco(double p) {
        if (p > 0) {
            preco = p;
        } else {
            preco = 0.0;
        }
    }
    
    // Método público
    void exibir() {
        cout << "Carro: " << marca << ", Preço: R$ " << preco << endl;
    }
};

int main() {
    Encapsulamento carro("Toyota", 50000);
    carro.exibir();
    
    carro.setPreco(-100); // Validação bloqueia
    carro.exibir();
    
    return 0;
}

// Heranca.cpp - Exemplo completo de herança em C++
#include <iostream>
#include <string>
using namespace std;

// CLASSE BASE (Classe Pai/Mãe)
// Contém atributos e métodos comuns a todas as subclasses
class Animal {
protected:  // protected: acessível nas subclasses
    string nome;
    int idade;

public:
    // CONSTRUTOR DA CLASSE BASE
    Animal(string n, int i) {
        nome = n;
        idade = i;
        cout << "Animal criado: " << nome << endl;
    }
    
    // MÉTODOS PÚBLICOS DA CLASSE BASE (herdados)
    void setNome(string n) { nome = n; }
    string getNome() { return nome; }
    
    // MÉTODO VIRTUAL (permite sobrescrita nas subclasses)
    virtual void fazerSom() {
        cout << nome << " faz um som genérico" << endl;
    }
    
    // DESTRUTOR VIRTUAL (boa prática em classes base)
    virtual ~Animal() {
        cout << "Animal " << nome << " destruído" << endl;
    }
};

// CLASSE DERIVADA 1 (herda de Animal) - "É-um Animal"
class Cachorro : public Animal {  // public: mantém visibilidade
private:
    string raca;

public:
    // CONSTRUTOR DA SUBCLASSE
    // Chama construtor da classe base com : Animal()
    Cachorro(string n, int i, string r) : Animal(n, i) {
        raca = r;
        cout << "Cachorro criado: " << raca << endl;
    }
    
    // SOBRESCREVENDO método virtual da classe base
    void fazerSom() override {
        cout << nome << " late: AU AU!" << endl;
    }
    
    // MÉTODO PRÓPRIO DA SUBCLASSE
    void exibirRaca() {
        cout << "Raça: " << raca << endl;
    }
};

// CLASSE DERIVADA 2 (herda de Animal)
class Gato : public Animal {
public:
    // CONSTRUTOR chamando construtor da base
    Gato(string n, int i) : Animal(n, i) {
        cout << "Gato criado" << endl;
    }
    
    // SOBRESCREVENDO método virtual
    void fazerSom() override {
        cout << nome << " mia: Miau!" << endl;
    }
};

int main() {
    cout << "=== DEMONSTRAÇÃO DE HERANÇA ===" << endl;
    
    // CRIANDO OBJETOS DAS SUBCLASSES
    Cachorro rex("Rex", 3, "Pastor Alemão");
    Gato luna("Luna", 2);
    
    cout << "\n--- Sons dos animais ---" << endl;
    rex.fazerSom();    // Chama versão Cachorro
    luna.fazerSom();   // Chama versão Gato
    
    cout << "\n--- Informações específicas ---" << endl;
    rex.exibirRaca();
    
    // POLIMORFISMO (mesma chamada, comportamento diferente)
    cout << "\n--- Polimorfismo ---" << endl;
    Animal* animais[] = { &rex, &luna };  // Array de ponteiros para Animal
    
    for (int i = 0; i < 2; i++) {
        animais[i]->fazerSom();  // Chama versão correta automaticamente!
    }
    
    return 0;  // Destrutores chamados automaticamente
}

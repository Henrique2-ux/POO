#include <iostream>
#include <string>
using namespace std;


class Pessoa {
protected:
    string nome;
    string telefone;

public:
    Pessoa(string nome, string telefone) {
        this->nome = nome;
        this->telefone = telefone;
    }

    void exibirDados() {
        cout << "Nome: " << nome << endl;
        cout << "Telefone: " << telefone << endl;
    }
};

class Cliente : public Pessoa {
public:
    Cliente(string nome, string telefone)
        : Pessoa(nome, telefone) {}
};

class Funcionario : public Pessoa {
private:
    string cargo;

public:
    Funcionario(string nome, string telefone, string cargo)
        : Pessoa(nome, telefone), cargo(cargo) {}

    void exibirDados() {
        Pessoa::exibirDados();
        cout << "Cargo: " << cargo << endl;
    }
};

class Animal {
private:
    string nome;
    string especie;
    Cliente* tutor;

public:
    Animal(string nome, string especie, Cliente* tutor) {
        this->nome = nome;
        this->especie = especie;
        this->tutor = tutor;
    }

    void exibirInfo() {
        cout << "\n=== Animal ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Especie: " << especie << endl;
        cout << "Tutor:" << endl;
        tutor->exibirDados();
    }
};

class Produto {
private:
    string nome;
    float preco;

public:
    Produto(string nome, float preco) {
        this->nome = nome;
        this->preco = preco;
    }

    void exibir() {
        cout << "\n=== Produto ===" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Preco: R$ " << preco << endl;
    }
};

class Servico {
private:
    string descricao;
    Funcionario* responsavel;

public:
    Servico(string descricao, Funcionario* responsavel) {
        this->descricao = descricao;
        this->responsavel = responsavel;
    }

    void exibir() {
        cout << "\n=== Servico ===" << endl;
        cout << "Descricao: " << descricao << endl;
        cout << "Responsavel:" << endl;
        responsavel->exibirDados();
    }
};

int main() {
    Cliente cliente1("Joao Silva", "38 9988-5043");

    Funcionario func1("Arthur Henrique", "38 99971-2862", "Veterinaria");

    Animal animal1("Rex", "Cachorro", &cliente1);

    Produto produto1("Racao Premium", 120.50);

    Servico servico1("Consulta veterinaria", &func1);

    animal1.exibirInfo();
    produto1.exibir();
    servico1.exibir();

    return 0;
}

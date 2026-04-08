#include <iostream>
#include <string>
using namespace std;

// ===================== Pessoa =====================
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

// ===================== Cliente (Tutor) =====================
class Cliente : public Pessoa {
public:
    Cliente(string nome, string telefone)
        : Pessoa(nome, telefone) {}
};

// ===================== Funcionario =====================
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

// ===================== Animal =====================
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

// ===================== Produto =====================
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

// ===================== Servico =====================
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

// ===================== MAIN =====================
int main() {
    // Criando cliente (tutor)
    Cliente cliente1("Joao Silva", "99999-0000");

    // Criando funcionario
    Funcionario func1("Maria Souza", "98888-1111", "Veterinaria");

    // Criando animal
    Animal animal1("Rex", "Cachorro", &cliente1);

    // Criando produto
    Produto produto1("Racao Premium", 120.50);

    // Criando servico
    Servico servico1("Consulta veterinaria", &func1);

    // Exibindo tudo
    animal1.exibirInfo();
    produto1.exibir();
    servico1.exibir();

    return 0;
}

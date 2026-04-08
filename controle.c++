#include <iostream>
#include <string>
#include <list>

using namespace std;

// Classe Funcionario
class Funcionario {
public:
    Funcionario(string nome, int cpf, string funcao)
        : nome(nome), cpf(cpf), funcao(funcao) {}

    string getNome() const {
        return nome;
    }

    string getFuncao() const {
        return funcao;
    }

    int getCpf() const {
        return cpf;
    }

private:
    string nome;
    string funcao;
    int cpf;
};

// Classe Produto
class Produto {
public:
    Produto(int cod, string nome, string fabricante)
        : cod(cod), nome(nome), fabricante(fabricante) {}

    string getNome() const {
        return nome;
    }

    string getFabricante() const {
        return fabricante;
    }

    int getCodigo() const {
        return cod;
    }

private:
    int cod;
    string nome;
    string fabricante;
};

// Classe ItemMovimentado
class ItemMovimentado {
public:
    ItemMovimentado(Produto* produto, int quantidade)
        : produto(produto), quantidade(quantidade) {}

    Produto* getProduto() const {
        return produto;
    }

    int getQuantidade() const {
        return quantidade;
    }

private:
    Produto* produto;
    int quantidade;
};

// Classe Movimentacao
class Movimentacao {
public:
    Movimentacao(Funcionario* funcionario)
        : funcionario(funcionario) {}

    void adicionarItem(ItemMovimentado* item) {
        itens.push_back(item);
    }

    Funcionario* getFuncionario() const {
        return funcionario;
    }

    list<ItemMovimentado*> getItens() const {
        return itens;
    }

private:
    Funcionario* funcionario;
    list<ItemMovimentado*> itens;
};

// Exemplo de uso
int main() {
    // Criando funcionários
    Funcionario f1("João", 123456, "Gerente");
    Funcionario f2("Maria", 987654, "Caixa");

    // Criando produtos
    Produto p1(1, "Notebook", "Dell");
    Produto p2(2, "Mouse", "Logitech");

    // Criando itens movimentados
    ItemMovimentado im1(&p1, 3);
    ItemMovimentado im2(&p2, 10);

    // Criando movimentação
    Movimentacao mov(&f1);
    mov.adicionarItem(&im1);
    mov.adicionarItem(&im2);

    // Exibindo informações
    cout << "Movimentacao feita pelo funcionario: " << mov.getFuncionario()->getNome() << endl;
    for (auto item : mov.getItens()) {
        cout << "- Produto: " << item->getProduto()->getNome()
             << ", Quantidade: " << item->getQuantidade() << endl;
    }

    return 0;
}

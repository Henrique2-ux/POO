#include <iostream>
#include <string>
using namespace std;

class pessoa {
public:
    pessoa(string nome, int i) {
        this->nome = nome;
        this->idade = i;
        cout << "Pessoa sendo criada\n";
    }

    void fazAniversario() {
        idade++;
    }

    void fazAniversario(int ano, int acrescimo = 2) {
        idade += acrescimo;
    }

    int getIdade() {
        return idade;
    }

private:
    string nome;
    int idade = 0;
};

class funcionario : public pessoa {
public:
    funcionario(string nome, int i) : pessoa(nome, i) {
    }
};

int main() {

    funcionario eletr("Jose", 30);

    pessoa arthur("Arthur Silva", 19);
    arthur.fazAniversario();
    cout << "Idade do Arthur: " << arthur.getIdade() << endl;

    pessoa maria("Maria", 16);

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class jogador {
    private:
        int id;
        string nome;
    public:

    jogador(int id, string nome){
        this -> id = id;
        this -> nome = nome;
    }

    int getId(){
        return id;
    }

    string getNome(){
        return nome;
    }
};

class jogadorLinha : public jogador{
    public:
      jogadorLinha(int id, string nome) : jogador(id, nome) {}
};

class Goleiro : public jogador{
    public:
      Goleiro(int id, string nome) : jogador(id, nome) {}
};

class arbitro{
    private:
        string nome;
        string funcao;

    public:

    arbitro(string nome, string funcao){
        this -> nome = nome;
        this -> funcao = funcao;
    }

    string getNome(){
        return nome;
    }

    string getFuncao(){
        return funcao;
    }

};

int main(){

    jogadorLinha L(1, "Arthur");
    Goleiro G(2, "Alberto");

    cout << L.getNome() << endl;
    cout << G.getNome() << endl;

    return 0;
}
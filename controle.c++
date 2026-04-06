#include <iostream>
#include <string>
#include <map>
using namespace std;


class funcionario{
    public:
        funcionario(string nome, int cpf, string funcao){
            this->nome = nome;
            this->cpf = cpf;
            this->funcao = funcao;
        }
        string getNome(){
            return this->nome;
        }

        string getFuncao(){
            return this->funcao;
        }

        int getCpf(){
            return this->cpf;
        }
    
    private:
        string nome;
        string funcao;
        int cpf;

};

class produto{
    public:
        produto(int cod, string nome, string fabricante){
            this->nome = nome;
            this->fabricante = fabricante;
            this->cod = cod;
        }

        string getNome(){
            return this->nome;
        }

        string getFabricante(){
            return this->fabricante;
        }

        int getCodigo(){
            this->cod;
        }

    private:
        string nome;
        string fabricante;
        int cod;
};

class intemMovimentado{
    public:
        intemMovimentado(produto* Produto, int quantidade){
            this->Produto = Produto;
            this->quantidade = quantidade;
        }

        produto* getproduto(){
            return &Produto;
        }

        int getquantidade(){
            return this->quantidade;
        }

    private:
        produto* Produto;
        int quantidade;
};

class Movimentacao{
    public:
        Movimentacao(funcionario* funcionario){
            this->funcionario = funcionario;
        }
        
        list<intemMovimentado*> itens;

        funcionario* getFuncionario(){
            return funcionario;
        }

    private:
        funcionario* funcionario;
};

int main(){

    
    return 0;
}
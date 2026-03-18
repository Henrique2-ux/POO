#include <iostream>
#include <string>
#include <list>
#include <map> 

using namespace std;
class pleito;
class pessoa;
class eleitor;
class candidato;

class pessoa{
    public:
        string nome = "";
        pessoa(string nome){
            this->nome = nome;
        }
};

class eleitor : public pessoa{
    public:
        int titulo = 0;
        eleitor(string n) : pessoa(n){
        }
};

class candidato : public pessoa{
    public:
        pleito* eleicao;
        candidato(string n) : pessoa(n){

        }
};

class voto{
    public: 
        candidato* candidatoEscolhido;
        eleitor* votoEleitor;
        voto(candidato* c, eleitor* e){
            candidatoEscolhido = c;
            votoEleitor = e;
        }
};

class pleito{
    public:
        list<voto> votos;
        list<candidato> candidatos;
};

void apuracao(pleito eleicao){
    map<candidato*, int> contagem;
    for(candidato c : eleicao.candidatos){
        contagem[&c] = 0;
    }

    for(voto v : eleicao.votos){
        contagem[v.candidatoEscolhido]++;
    }
    for(auto c : contagem)
    cout << c.first->nome << ":" << c.second << endl;
};


int main() {
    std::cout << "eleicao 26";

    pleito eleicaosindicato;
    eleitor m1("Jose");
    eleitor m2("Joao");
    eleitor m3("maria");
    eleitor m4("marta");

    candidato c1("jose");
    candidato c2("maria");

    eleicaosindicato.candidatos.push_front(c1);
    eleicaosindicato.candidatos.push_front(c2);
    
    eleicaosindicato.votos.push_front(voto(&c1, &m1));
    eleicaosindicato.votos.push_front(voto(&c2, &m2));
    eleicaosindicato.votos.push_front(voto(&c2, &m3));
    eleicaosindicato.votos.push_front(voto(&c1, &m4));
    
    return 0;
}

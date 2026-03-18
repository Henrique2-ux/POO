#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pessoa{
protected:
    string nome;
    int cpf;
    string endereco;
    int titulo;

public:
    Pessoa(string n, int c, string e, int t){
        nome = n;
        cpf = c;
        endereco = e;
        titulo = t;
    }

    string getNome(){
        return nome;
    }
};

class Eleitor : public Pessoa{
private:
    bool votou;

public:
    Eleitor(string n,int c,string e,int t)
        : Pessoa(n,c,e,t){
        votou = false;
    }

    bool jaVotou(){
        return votou;
    }

    void registrarVoto(){
        votou = true;
    }
};

class Candidato{
private:
    string nome;
    int numero;
    int votos;

public:
    Candidato(string n,int num){
        nome = n;
        numero = num;
        votos = 0;
    }

    int getNumero(){
        return numero;
    }

    string getNome(){
        return nome;
    }

    int getVotos(){
        return votos;
    }

    void receberVoto(){
        votos++;
    }
};

class Urna{
private:
    vector<Candidato*> candidatos;

public:

    void adicionarCandidato(Candidato* c){
        candidatos.push_back(c);
    }

    void mostrarCandidatos(){
        cout << "\nCandidatos:\n";
        for(Candidato* c : candidatos){
            cout << c->getNumero() << " - " << c->getNome() << endl;
        }
    }

    void votar(Eleitor* e){

        if(e->jaVotou()){
            cout << "Eleitor ja votou!\n";
            return;
        }

        int numero;
        mostrarCandidatos();

        cout << "Digite o numero do candidato: ";
        cin >> numero;

        for(Candidato* c : candidatos){

            if(c->getNumero() == numero){

                c->receberVoto();
                e->registrarVoto();

                cout << "Voto registrado com sucesso!\n";
                return;
            }
        }

        cout << "Candidato nao encontrado!\n";
    }

    void resultado(){

        cout << "\nResultado da eleicao:\n";

        for(Candidato* c : candidatos){
            cout << c->getNome()
                 << " - votos: "
                 << c->getVotos() << endl;
        }
    }
};

class Eleicao{
private:
    vector<Eleitor*> eleitores;
    Urna urna;

public:

    void adicionarEleitor(Eleitor* e){
        eleitores.push_back(e);
    }

    Urna* getUrna(){
        return &urna;
    }

    Eleitor* buscarEleitor(string nome){

        for(Eleitor* e : eleitores){
            if(e->getNome() == nome){
                return e;
            }
        }

        return nullptr;
    }
};

int main(){

    Eleicao eleicao;

    // candidatos
    Candidato c1("Carlos",10);
    Candidato c2("Maria",20);
    Candidato c3("Joao",30);

    eleicao.getUrna()->adicionarCandidato(&c1);
    eleicao.getUrna()->adicionarCandidato(&c2);
    eleicao.getUrna()->adicionarCandidato(&c3);

    // eleitores
    eleicao.adicionarEleitor(new Eleitor("Arthur",111,"Rua A",1));
    eleicao.adicionarEleitor(new Eleitor("Ana",222,"Rua B",2));
    eleicao.adicionarEleitor(new Eleitor("Henrique",333,"Rua C",3));

    string nome;

    cout << "Digite o nome do eleitor: ";
    cin >> nome;

    Eleitor* e = eleicao.buscarEleitor(nome);

    if(e != nullptr){

        eleicao.getUrna()->votar(e);

    }else{

        cout << "Eleitor nao encontrado!\n";

    }

    eleicao.getUrna()->resultado();

    return 0;
}

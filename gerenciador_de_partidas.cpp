#include <iostream>
#include <string>
#include <vector>
using namespace std;

class jogador {
    private:
        int id;
        string nome;
    public:
    jogador(int id, string nome){ this -> id = id; this -> nome = nome; }
    int getId(){ return id; }
    string getNome(){ return nome; }
};

class JogadorLinha : public jogador{
    public:
      JogadorLinha(int id, string nome) : jogador(id, nome) {}
};

class Goleiro : public jogador{
    public:
      Goleiro(int id, string nome) : jogador(id, nome) {}
};

class Arbitro{
    private:
        string nome;
        string funcao;
    public:
    Arbitro(string nome, string funcao){ this -> nome = nome; this -> funcao = funcao; }
    string getNome(){ return nome; }
    string getFuncao(){ return funcao; }
};

class Time{
    private:
        string nome;
        Goleiro goleiro;
        vector<JogadorLinha> titulares;
    public:
        Time(string nome, Goleiro goleiro, vector<JogadorLinha> titulares) : goleiro(goleiro){
            this ->nome = nome;
            this -> titulares = titulares;
        }
        vector<JogadorLinha> getTitulares() {
            return titulares;
        }
        string getNome(){
            return nome;
        }
};

class Partida{
    private:
        Time timeA;
        Time timeB;
        int placarA;
        int placarB;
        Arbitro principal;
        Arbitro bandeirinha1;
        Arbitro bandeirinha2;
        bool iniciada;
        bool concluida;

    public:
        Partida(bool iniciada, bool concluida, int placarA, int placarB, Time timeA, Time timeB, Arbitro principal, Arbitro bandeirinha1, Arbitro bandeirinha2) : timeA(timeA), timeB(timeB), principal(principal), bandeirinha1(bandeirinha1), bandeirinha2(bandeirinha2) {
            this -> iniciada = iniciada;
            this -> concluida = concluida;
            this -> placarA = placarA;
            this -> placarB = placarB;
        }

        int incrementarPlacar(string time){
            if(time == "A"){
                placarA = placarA + 1;
                return placarA;
            } else{
                placarB = placarB + 1;
                return placarB;
            }
        }

        bool iniciar(){
            if(timeA.getTitulares().size() == 3 && timeB.getTitulares().size() == 3){
                iniciada = true;
                cout << "Partida Iniciada" << endl;
                return true;
            } else {
                iniciada = false;
                cout << "Nao e possivel Iniciar Partida" << endl;
                return false;
            }
        }

        bool concluir(){
            if(iniciada == true && concluida == false){
                concluida = true;
                cout << "Partida Encerrada" << endl;
                return true;
            } else{
                concluida = false;
                return false;
            }
        }

        bool getIniciada(){ return iniciada; }
        bool getConcluida(){ return concluida; }
        Time getTimeA(){ return timeA; }
        Time getTimeB(){ return timeB; }
};

class GerenciadorPartida {
    private:
        vector<Partida*> partidas;

    public:
        GerenciadorPartida(){}

        void cadastrarPartida(Partida* p){
            partidas.push_back(p);
        }

        int contarEmAndamento(){
            int contador = 0;
            for(Partida* p : partidas){
                if( p->getIniciada() == true && p->getConcluida() == false){
                    contador = contador + 1;
                }
            }
            return contador;
        }

        bool timejogando(Time* time){
            for(Partida* p : partidas){
                if((p->getIniciada() == true && p->getConcluida() == false) && (time->getNome() == p->getTimeA().getNome() || time->getNome() == p->getTimeB().getNome())){
                    return true;
                }
            }
            return false;
        }

        bool iniciarPartida(Partida* p){
            Time tA = p->getTimeA();
            Time tB = p->getTimeB();
            if (timejogando(&tA) || timejogando(&tB)) {
                cout << "Um dos times ja esta em outra partida em andamento." << endl;
                return false;
            }
            return p->iniciar();
        }
};

int main(){
    JogadorLinha L3(3, "Ribas");
    JogadorLinha L2(2, "Henrique");
    JogadorLinha L1(1, "Arthur");
    vector<JogadorLinha> titularesTimeA = {L1, L2, L3};
    Goleiro G(2, "Alberto");
    Time flamengo("Flamengo", G, titularesTimeA);

    JogadorLinha M1(4, "Bruno");
    JogadorLinha M2(5, "Carlos");
    JogadorLinha M3(6, "Diego");
    vector<JogadorLinha> titularesTimeB = {M1, M2, M3};
    Goleiro G2(7, "Eduardo");
    Time vasco("Vasco", G2, titularesTimeB);

    JogadorLinha X1(8, "Felipe");
    JogadorLinha X2(9, "Gustavo");
    JogadorLinha X3(10, "Hugo");
    vector<JogadorLinha> titularesTimeC = {X1, X2, X3};
    Goleiro G3(11, "Igor");
    Time botafogo("Botafogo", G3, titularesTimeC);

    Arbitro principal("Joao", "principal");
    Arbitro bandeira1("Pedro", "bandeirinha");
    Arbitro bandeira2("Lucas", "bandeirinha");

    GerenciadorPartida gp;

    // Partida 1: Flamengo x Vasco
    Partida p1(false, false, 0, 0, flamengo, vasco, principal, bandeira1, bandeira2);
    gp.cadastrarPartida(&p1);

    // Partida 2: Flamengo x Botafogo (Flamengo repetido de propósito!)
    Partida p2(false, false, 0, 0, flamengo, botafogo, principal, bandeira1, bandeira2);
    gp.cadastrarPartida(&p2);

    cout << "=== Tentando iniciar Partida 1 (Flamengo x Vasco) ===" << endl;
    bool r1 = gp.iniciarPartida(&p1);
    cout << "Resultado: " << (r1 ? "SUCESSO" : "FALHOU") << endl;

    cout << endl << "=== Tentando iniciar Partida 2 (Flamengo x Botafogo), com Flamengo JA jogando ===" << endl;
    bool r2 = gp.iniciarPartida(&p2);
    cout << "Resultado: " << (r2 ? "SUCESSO (ERRADO, nao deveria deixar)" : "FALHOU (esperado - Flamengo ja esta jogando)") << endl;

    cout << endl << "=== Concluindo Partida 1 ===" << endl;
    p1.concluir();

    cout << endl << "=== Tentando iniciar Partida 2 de novo, agora que Flamengo esta livre ===" << endl;
    bool r3 = gp.iniciarPartida(&p2);
    cout << "Resultado: " << (r3 ? "SUCESSO (esperado)" : "FALHOU") << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class jogador{
    protected:
    int id;
    string nome;
    
    public:
        jogador(int id, string nome){
            this-> id = id;
            this-> nome = nome;
        }

        string getNome(){
            return nome;
        }
};

class jogadorLinha : public jogador {
    public:
        jogadorLinha(int id, string nome): jogador(id,nome){

        }
};


class Goleiro : public jogador {
    public:
        Goleiro(int id, string nome): jogador(id,nome){

        }
};

class Arbitro{
    private:
        string nome;
        string funcao;

    public:
        Arbitro(string nome, string funcao){
            this -> nome = nome;
            this -> funcao = funcao;
        }
        
        string getNome(){
            return nome;
        }

        string getfuncao(){
            return funcao;
        }
};

class Time{
    private:
        string nome;
        vector<jogadorLinha> titulares;
        Goleiro* goleiro;
        bool emPartida;

    public: 
        Time(string nome){
            this -> nome = nome;
            goleiro = nullptr;
            emPartida = false;
        }

        void adicionarJogador(jogadorLinha jogador) {
            if(titulares.size() < 3){
                titulares.push_back(jogador);
            }
        }

        void definirGoleiro(Goleiro* g){
            goleiro = g;
        }

        bool estaCompleto(){
            return titulares.size() == 3 && goleiro != nullptr;
        }

        string getNome(){
            return nome;
        }

        bool isEmPartida(){
            return emPartida;
        }

        void setEmPartida(bool valor){
            emPartida = valor;
        }
};

class Partida{
    private:
        Time* time1;
        Time* time2;

        Arbitro* arbitro;

        vector<Arbitro*> bandeirinhas;

        int gols1;
        int gols2;

        bool iniciada;
    
    public:
        Partida(Time* t1, Time* t2, Arbitro* arb, vector<Arbitro*> bandeiras){
            
            time1 = t1;
            time2 = t2;
            arbitro = arb;
            bandeiras = bandeiras;

            gols1 = 0;
            gols2 = 0;
            iniciada = false;
        }
};
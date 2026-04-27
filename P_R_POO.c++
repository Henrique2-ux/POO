#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

/*  Class carta -> destinatatio, remetente e conteudo
    Class veiculo -> placa e cor
    Class malotes -> herda cartas e veiculo*/

class carta{
    protected:
        string destinatatio;
        string remetente;
    public: 
        carta(const string& D, const string& R, const string& C) : destinatatio(D), remetente(R), conteudo(C) {}
        string getDestinatario() const {
            return destinatatio;
        }
        string getRemetente() const {
            return remetente;
        }  
};

class veiculo{
    protected:
        string placa;
        string cor;
    public:
        veiculo(const string& P, const string& C) : placa(P), cor(C){
            string getPlaca() const{
                retunr placa;
            }
               string getCor() const{
                retunr cor;
            }
        }
};

class registroVeiculo{
    private:
        Carta* Carta;
        string Malote;
    public:
        alocacaomalote(Carta* C, Veiculo* V) : carta(C), veiculo(V){}
        Carta* getDestinatario() const {
                return destinatatio;
            }
        Carta* getRemetente() const {
                return remetente;
            }
        Veiculo* getPlaca() const {
            return placa;
        }
};

class registroMalote{
    private:
        list<cartasAlocadas*> registros;
    public:
        alocandoCarta(){
            for(auto* r : registros) delete r;
        }

};


void gerarRelatorio() const{
    count << "=== RELATORIO ===";
    for(auto* r : registros){
        count "Veiculo: "<< r->getPlaca()"|" r->getCor() << endl;
        count "Malote: "<< r->getDestinatario() "|" r-> getRemetente() << endl;
    } 
};


int main(){
    carta* C1 = new carta("Casa", "Arthur");
    mov.gerarRelatorio();

    delete C1;
    return 0;
}

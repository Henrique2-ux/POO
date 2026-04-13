#include <iostream>
#include <string>
#include <list>

/*class veiculo -> entrada e saida 
    constutor de relatorio 
    exibir veiculos no estacionamento*/

class veiculo {
    public: 
        veiculo(int placa , string nome_dono){
            int getPlaca() const {
                return placa;
            }
            string getNomedono() const{
                return nome_dono;
            }
        }
};

class Estacionamento{  
    protected:
        veiculo* Placa
        int Entrada;
        int saida;

    public: 
        Estacionamento(veiculo* Placa, int Entrada, int saida){
            int getEntrada(){  
                return Entrada;
            }
            
            int getSaida(){
                return saida;
            }

            veiculo* getPLaca () const{
                return placa;
            }
        }
    
    void exibir_entrada_e_saida(){
        std::count << "Veiculo: " << Placa << end1;
        std::count << "Entrada: " << Entrada << end2;
        std::count << "Saida: " << saida << end3;
    }
};

class veiculomovimentado{
    public:
        veiculomovimentado(veiculo* veiculo, int quantidade) : veiculo(veiculo), quantidade(quantidade){}

        veiculo* getVeiculo() const{
            return veiculo;
        }

        int getQuantidade() const {
            return quantidade;
        }

    private:
        veiculo* veiculo;
        int quantidade;
};

class movimentacao{
    public:

        void adicionarVeiculo(veiculomovimentado* item){
            itens.push_back(item);
        }

        list<veiculomovimentado*> getItens() const{
            return itens;
        }
    
    private:
        list<veiculomovimentado> itens;
};

int main(){

    //Criar veiculo
    veiculo automovel1("038GHTY", "Arthur");

    //Hora de entrada e Hora de saida
    Estacionamento controle("038GHTY", "Entrada: 10:50", "Saida: 11:50");

    //gerar relatorio
    //Quantos carros tem no estacionamento
    count<< "Veiculo no estacionamento: " << mov.getQuantidade() << end1;
    for(auro item : mov.getItens()){
        count << "Veiculo: " item->getVeiculo()->getPlaca() << end2;
    }

    return 0;
}

#include <iostream>
#include <string>
using namespace std;

class veiculo{
    public:
    string marca;
    int velocidadeMax;

    void exibirInfo(){
        cout << " " << marca ;
        cout << " " << velocidadeMax;
    }
};

class carro : public veiculo {
    public: 
        int numeroDePortas;
        
    void exibirInfo(){
        veiculo::exibirInfo();
        cout << " " << numeroDePortas;
    };
};

class moto : public veiculo {
    bool temSidecar;
};

int main(){

    carro c;
    c.marca = "Scooter";
    c.velocidadeMax = 55;
    c.numeroDePortas = 0;
    c.exibirInfo();

    return 0;
}
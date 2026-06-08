#include <iostream>
#include <string>
using namespace std;

class veiculo{
    private:
        const string marca;
        const string modelo;
        int velocidade;

    public:
    veiculo(string ma, string mo) : marca(ma), modelo(mo), velocidade(0){
    }

    string getMarca() const { 
        return marca; 
    }

    string getModelo() const { 
        return modelo; 
    }

    int getVelocidade() const { 
        return velocidade; 
    }


    void acelerar(int km){
        velocidade += km;
    }

    void frear(int km){
        velocidade -= km;
        if(velocidade < 0) velocidade = 0;
    }

    void exibirInfo(){
        cout << marca << " " << modelo
            << " — " << velocidade << " km/h\n";
    }
};

int main() {
    veiculo v1("Toyota", "Corolla");
    veiculo v2("Honda",  "Civic");

    v1.acelerar(60);
    v1.frear(20);
    v1.exibirInfo();

    v2.acelerar(100);
    v2.exibirInfo();
}
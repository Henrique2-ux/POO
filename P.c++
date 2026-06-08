#include <iostream>
#include <vector>

using namespace std;

class Forma{
    public:
        virtual double calcularArea() = 0;

};

class Retangulo : public Forma {
    public: 
        double largura, altura;

        double calcularArea() override {
            return largura * altura;
        }
};

class Circulo : public Forma {
    public: 
        double raio;

        double calcularArea() override {
            return 3.14 * (raio * raio);
        }
};

class triangulo : public Forma {
    public: 
        double base, altura;

        double calcularArea() override {
            return (base * altura)/ 2;
        }
};

int main(){
    vector <Forma*> formas;

    Retangulo* r = new Retangulo();
    r->largura = 5;
    r->altura = 3;

    Circulo* c = new Circulo();
    c->raio = 4;

       triangulo* t = new triangulo();
    t->base = 6;
    t->altura = 2;

    formas.push_back(r);
    formas.push_back(c);
    formas.push_back(t);

    for (Forma* f : formas) {
        cout << f->calcularArea() << endl;
    }

    return 0;
}
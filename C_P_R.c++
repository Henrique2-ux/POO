#include <iostream>
#include <string>
#include <list>

using namespace std;

class Carta {
private:
    string destinatario;
    string remetente;
    string conteudo;

public:
    Carta(const string& d, const string& r, const string& c)
        : destinatario(d), remetente(r), conteudo(c) {}

    string getDestinatario() const {
        return destinatario;
    }

    string getRemetente() const {
        return remetente;
    }

    string getConteudo() const {
        return conteudo;
    }
};

class Veiculo {
private:
    string placa;
    string cor;

public:
    Veiculo(const string& p, const string& c) : placa(p), cor(c) {}

    string getPlaca() const {
        return placa;
    }

    string getCor() const {
        return cor;
    }
};

class RegistroVeiculo {
private:
    Veiculo* veiculo;
    string malote;
    list<Carta*> cartas;

public:
    RegistroVeiculo(Veiculo* v, const string& m) : veiculo(v), malote(m) {}

    void adicionarCarta(Carta* c) {
        cartas.push_back(c);
    }

    Veiculo* getVeiculo() const {
        return veiculo;
    }

    string getMalote() const {
        return malote;
    }

    list<Carta*> getCartas() const {
        return cartas;
    }
};

class RegistroMalote {
private:
    list<RegistroVeiculo*> registros;

public:
    ~RegistroMalote() {
        for (auto* r : registros) {
            delete r;
        }
    }

    void adicionarRegistro(RegistroVeiculo* r) {
        registros.push_back(r);
    }

    void gerarRelatorio() const {
        cout << "=== RELATORIO ===" << endl;

        for (auto* r : registros) {
            cout << "Veiculo: " << r->getVeiculo()->getPlaca()
                 << " | Cor: " << r->getVeiculo()->getCor() << endl;
            cout << "Malote: " << r->getMalote() << endl;

            for (auto* c : r->getCartas()) {
                cout << "Carta -> Destinatario: " << c->getDestinatario()
                     << " | Remetente: " << c->getRemetente()
                     << " | Conteudo: " << c->getConteudo() << endl;
            }

            cout << "------------------------" << endl;
        }
    }
};

int main() {
    Carta* c1 = new Carta("Casa", "Arthur", "Documento");
    Carta* c2 = new Carta("Empresa", "Maria", "Contrato");

    Veiculo* v1 = new Veiculo("038GHTY", "Branco");

    RegistroVeiculo* rv1 = new RegistroVeiculo(v1, "Malote A");
    rv1->adicionarCarta(c1);
    rv1->adicionarCarta(c2);

    RegistroMalote mov;
    mov.adicionarRegistro(rv1);

    mov.gerarRelatorio();

    delete c1;
    delete c2;
    delete v1;

    return 0;
}

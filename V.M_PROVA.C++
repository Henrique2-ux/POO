#include <iostream>
#include <string>
#include <list>

using namespace std;

class Veiculo {
private:
    string placa;
    string nomeDono;

public:
    Veiculo(const string& p, const string& n) : placa(p), nomeDono(n) {}
    string getPlaca() const { return placa; }
    string getNomeDono() const { return nomeDono; }
};

class RegistroMovimento {
private:
    Veiculo* veiculo;
    string entrada;
    string saida;  // Vazio se ainda está dentro

public:
    RegistroMovimento(Veiculo* v, const string& e) : veiculo(v), entrada(e), saida("") {}
    Veiculo* getVeiculo() const { return veiculo; }
    string getEntrada() const { return entrada; }
    string getSaida() const { return saida; }
    bool estaNoEstacionamento() const { return saida.empty(); }
    void setSaida(const string& s) { saida = s; }
};

class Movimentacao {
private:
    list<RegistroMovimento*> registros;

public:
    ~Movimentacao() {
        for (auto* r : registros) delete r;
    }

    void entrada(Veiculo* v, const string& hora) {
        registros.push_back(new RegistroMovimento(v, hora));
    }

    void saida(const string& placa, const string& hora) {
        for (auto* r : registros) {
            if (r->estaNoEstacionamento() && r->getVeiculo()->getPlaca() == placa) {
                r->setSaida(hora);
                return;
            }
        }
    }

    int contarNoEstacionamento() const {
        int cnt = 0;
        for (auto* r : registros) if (r->estaNoEstacionamento()) cnt++;
        return cnt;
    }

    void exibirNoEstacionamento() const {
        cout << "
Carros no estacionamento (" << contarNoEstacionamento() << "):
";
        bool tem = false;
        for (auto* r : registros) {
            if (r->estaNoEstacionamento()) {
                tem = true;
                cout << r->getVeiculo()->getPlaca() << " - " << r->getVeiculo()->getNomeDono() << endl;
            }
        }
        if (!tem) cout << "(nenhum)
";
    }

    void gerarRelatorio() const {
        cout << "
=== RELATORIO COMPLETO ===
";
        for (auto* r : registros) {
            cout << r->getVeiculo()->getPlaca() << " (" << r->getVeiculo()->getNomeDono()
                 << "): " << r->getEntrada();
            if (r->estaNoEstacionamento()) cout << " (ainda dentro)";
            else cout << " -> " << r->getSaida();
            cout << endl;
        }
    }
};

int main() {
    Veiculo* v1 = new Veiculo("038GHTY", "Arthur");

    Movimentacao mov;
    mov.entrada(v1, "18:50");
    mov.exibirNoEstacionamento();  // 1 carro
    mov.gerarRelatorio();

    mov.saida("038GHTY", "19:50");
    mov.exibirNoEstacionamento();  // 0 carros
    mov.gerarRelatorio();

    delete v1;  // Movimentacao limpa os registros
    return 0;
}
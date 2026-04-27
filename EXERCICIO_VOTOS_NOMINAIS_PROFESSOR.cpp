#include <iostream>
#include <string>
#include <list>
#include <map> 
using namespace std;

// DECLARAÇÕES FORWARD (corrigidas)
class pessoa;
class eleitor;
class candidato;
class pleito;

// CLASSE BASE
class pessoa {
public:
    string nome;
    // CONSTRUTOR PADRÃO (obrigatório para list)
    pessoa() : nome("") {}
    pessoa(string n) : nome(n) {}
};

// ELEITOR HERDA DE PESSOA
class eleitor : public pessoa {
public:
    int titulo = 0;
    eleitor() {}
    eleitor(string n) : pessoa(n) {}
};

// CANDIDATO HERDA DE PESSOA
class candidato : public pessoa {
public:
    candidato() {}
    candidato(string n) : pessoa(n) {}
};

// VOTO (associação entre eleitor e candidato)
class voto {
public: 
    candidato* candidatoEscolhido;
    eleitor* eleitor;
    
    voto(candidato* c, eleitor* e) : candidatoEscolhido(c), eleitor(e) {}
};

// ELEIÇÃO (contém listas)
class pleito {
public:
    list<voto> votos;
    list<candidato> candidatos;  // ARMAZENA OBJETOS (não ponteiros)
};

// FUNÇÃO APURAÇÃO CORRIGIDA
void apuracao(const pleito& eleicao) {  // PASSA POR REFERÊNCIA
    map<string, int> contagem;  // CHAVE: NOME (string) ao invés de ponteiro
    
    // INICIALIZA CONTAGEM COM CANDIDATOS
    for(const auto& c : eleicao.candidatos) {
        contagem[c.nome] = 0;
    }
    
    // CONTA VOTOS
    for(const auto& v : eleicao.votos) {
        contagem[v.candidatoEscolhido->nome]++;
    }
    
    // EXIBE RESULTADO
    cout << "\n=== RESULTADO DA ELEIÇÃO ===" << endl;
    for(const auto& par : contagem) {
        cout << par.first << ": " << par.second << " votos" << endl;
    }
}

int main() {
    cout << "=== Eleição 2026 ===" << endl;
    
    // CRIANDO ELEIÇÃO
    pleito eleicaosindicato;
    
    // ELEITORES
    eleitor m1("Jose");
    eleitor m2("Joao"); 
    eleitor m3("Maria");
    eleitor m4("Marta");
    
    // CANDIDATOS
    candidato c1("Jose");
    candidato c2("Maria");
    
    // ADICIONANDO CANDIDATOS À ELEIÇÃO
    eleicaosindicato.candidatos.push_front(c1);
    eleicaosindicato.candidatos.push_front(c2);
    
    // REGISTRANDO VOTOS
    eleicaosindicato.votos.push_front(voto(&c1, &m1)); // Jose vota Jose
    eleicaosindicato.votos.push_front(voto(&c2, &m2)); // Joao vota Maria
    eleicaosindicato.votos.push_front(voto(&c2, &m3)); // Maria vota Maria
    eleicaosindicato.votos.push_front(voto(&c1, &m4)); // Marta vota Jose
    
    // APURANDO RESULTADO
    apuracao(eleicaosindicato);
    
    return 0;
}

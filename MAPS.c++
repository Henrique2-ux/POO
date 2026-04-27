// Map.cpp - Exemplo de unordered_map (equivalente a HashMap)
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // CRIANDO UNORDERED_MAP (chave: string, valor: int)
    unordered_map<string, int> notasAlunos;
    
    // ADICIONANDO PARES
    notasAlunos["Ana"] = 85;     // Operador [] cria/atualiza
    notasAlunos["Bruno"] = 72;
    notasAlunos["Ana"] = 90;     // Sobrescreve
    
    // OU USANDO insert
    notasAlunos.insert({"Carla", 98});
    
    // TAMANHO
    cout << "Total: " << notasAlunos.size() << endl;
    
    // ACESSANDO
    cout << "Ana: " << notasAlunos["Ana"] << endl;
    cout << "Diego: " << notasAlunos["Diego"] << endl; // 0 se não existe
    
    // VERIFICANDO CHAVE
    if (notasAlunos.find("Bruno") != notasAlunos.end()) {
        cout << "Bruno existe" << endl;
    }
    
    // PERCORRENDO
    cout << "Todas as notas: ";
    for (auto& par : notasAlunos) {
        cout << par.first << "=" << par.second << " ";
    }
    cout << endl;
    
    // REMOVENDO
    notasAlunos.erase("Carla");
    cout << "Após erase: ";
    for (auto& par : notasAlunos) {
        cout << par.first << "=" << par.second << " ";
    }
    cout << endl;
    
    return 0;
}

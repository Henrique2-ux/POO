#include <iostream>
#include <string>
using namespace std;
class pessoa{
    public:
        pessoa(){
            cout << "pessoa criada \n";
        }
        
       ~pessoa(){
           cout <<"pessoa morreu \n";       
       }
       string nome = "";
};

pessoa criarJose (){
    pessoa jose;
    return jose;
}

int main() {
    
    pessoa* maria = new pessoa();
    maria[0].nome = "Maria";
    cout << maria->nome;
    pessoa p  = criarJose();
    p.nome = "Jose silva";
    cout<<"tentativa de assasinato de jose\n";
    delete maria;

    return 0;
}

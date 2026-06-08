#include <iostream>

using namespace std;

class termostato{
    private: 
        double temperatura;

    public:

        termostato() {
        temperatura = 20;
        }

        void setTemperaura(double T){
            if (T < 16 || T > 30)
                cout << "Invalido \n";
            else
                temperatura = T;
        }

        double getTemperaura(){
            return temperatura;
        };
};

int main(){

    termostato  T;

    T.setTemperaura(14);
    cout << T.getTemperaura() << endl;

    return 0;
};
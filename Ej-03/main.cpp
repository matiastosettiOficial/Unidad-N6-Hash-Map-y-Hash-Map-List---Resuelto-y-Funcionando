#include <iostream>
#include "../HashMap/HashMap.h"
#include <string>

using namespace std;

unsigned int miHashFunc(int clave) {
    unsigned int sumDigit = 0, numEntero = clave;
    while(numEntero != 0) {
        sumDigit += numEntero % 10;
        numEntero /= 10;
    }
    return sumDigit;
}

int main() {
    cout << "Ejercicio 06/03\n" << endl;

    HashMap<int, string> TH(8, &miHashFunc); //Clave: clave UCC (int)
                                                //Valor: nombre alumno (string)

    try {
        TH.put(2113933, "Steve Rogers");
        TH.put(2012028, "Natasha Romanoff");
        TH.put(1902031, "Tony Stark");
        TH.put(1708162, "Wanda Maximoff");
        TH.put(2002700, "Clint Barton");
    } catch(int error) {
        if(error == 409) {
            cout << "[ERROR] Valor ya existente, genera una colision" << endl;
        } else {
            cout << "[ERROR] Causa desconocida" << endl;
        }
    }

    TH.print();

    cout << "\nEliminar registro (clave = 1708162)" << endl;
    TH.remove(1708162);

    cout << "Eliminar registro (clave = 2012028)\n" << endl;
    TH.remove(2012028);

    TH.print();

    return 0;
}
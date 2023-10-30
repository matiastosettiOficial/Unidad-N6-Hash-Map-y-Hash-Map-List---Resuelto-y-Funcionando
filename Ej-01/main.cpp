#include <iostream>
#include <string>
#include "../HashMap/HashMap.h"

using namespace std;
/**
 * Transformo los caracteres de la clave en números (uno x uno) (código ASCII) y los sumo
 * @param clave
 * @return
 */
unsigned int miHashFunc(string clave) { //
    unsigned int idx = 0;
    for(int i = 0; i < clave.length(); i++) {
        idx += clave[i];
    }
    cout << "Hash de la clave " << clave << ": " << idx << endl;
    return idx;
}

int main() {
    cout << "Ejercicio 06/01\n" << endl;

    HashMap<string, int> TH(8, &miHashFunc); //Clave: patente de un auto (string)
                                                //Valor: año de la patente (int)
    try {
        TH.put("abc123", 1995);
        TH.put("fpi293", 2006);
        TH.put("pkz111", 2016);
        TH.put("nzy200", 2009);
    } catch(int error) {
        if(error == 409) {
            cout << "[ERROR] Valor ya existente, genera una colision" << endl;
        } else {
            cout << "[ERROR] Causa desconocida" << endl;
        }
    }

    TH.print();

    try {
        cout << "Anio de patente 'abc123': " << TH.get("abc123") << endl;
        cout << "Anio de patente 'fpi293': " << TH.get("fpi293") << endl;
        cout << "Anio de patente 'sss234': " << TH.get("sss234") << endl;
    } catch(int error) {
        if(error == 404) {
            cout << "[ERROR] Patente no registrada en el sistema" << endl;
        } else {
            cout << "[ERROR] Causa desconocida" << endl;
        }
    }

    return 0;
}
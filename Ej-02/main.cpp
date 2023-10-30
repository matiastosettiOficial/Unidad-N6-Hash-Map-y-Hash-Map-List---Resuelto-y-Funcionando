#include <iostream>
#include "../HashMap/HashMapList.h"

using namespace std;

class Libro {
public:
    string nombre;
    string autor;
    string genero;
    string editorial;
    int nroPaginas;

    friend ostream &operator<<(ostream &os, const Libro &libro) {
        os << "-> Nombre: " << libro.nombre << ". Autor: " << libro.autor << ". Genero: " << libro.genero
           << ". Editorial: " << libro.editorial << ". Numero de paginas: " << libro.nroPaginas;
        return os;
    }
};

unsigned int miHashFunc(string clave) {
    unsigned int idx = 0;
    for(int i = 0; i < 3; i++) {
        idx += clave[i];
    }
    cout << "Hash de la clave " << clave << ": " << idx << endl;
    return idx;
}

int main() {
    cout << "Ejercicio 05/02\n" << endl;

    HashMapList<string, Libro> th(10, &miHashFunc);

    Libro l1 = {"Mujercitas", "Louisa May Alcott", "Clasicos", "Edimat", 320};
    Libro l2 = {"Harry Potter", "J K Rowling", "Fantasia", "Salamandra", 259};
    Libro l3 = {"Los juegos del hambre", "Suzanne Collins", "Distopia", "Molino", 396};
    Libro l4 = {"Narnia", "C S Lewis", "Fantasia", "Destino", 313};

    th.put(l1.genero, l1);
    th.put(l2.genero, l2);
    th.put(l3.genero, l3);
    th.put(l4.genero, l4);

    th.getList("Fantasia");

    return 0;
}
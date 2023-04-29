#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Comprador {
private:
    string nombre;
    string direccion;
    vector<string> historialCompras;

public:
    Comprador(const string& _nombre, const string& _direccion) {
        nombre = _nombre;
        direccion = _direccion;
    }
    void comprarLibro(const string& titulo) {
        int contador = 0;  
        cout << "Comprando libro: " << titulo <<" por "<<nombre<<endl;
        cout << "Enviando a la siguiente direccion: " << direccion << endl;
        historialCompras.push_back(titulo);
        contador++;  
        cout << "Total de libros comprados por: " <<nombre<<": "<< contador << endl;
    }


    void verHistorialCompras() {
        cout << "Mostrando historial de compras para " << nombre << endl;
        for (string& libro : historialCompras) {
            cout << "compro el libro: "<< libro << endl;
        }
    }

    string getNombre() const {
        return nombre;
    }
};

class Biblioteca {
private:
    vector<Comprador> listaCompradores;

public:
    void agregarComprador(const string& nombre, const string& direccion) {
        Comprador nuevoComprador(nombre, direccion);
        listaCompradores.push_back(nuevoComprador);
    }

    void comprarLibro(const string& titulo, const string& nombreComprador) {
        for (Comprador& comprador : listaCompradores) {
            if (comprador.getNombre() == nombreComprador) {
                comprador.comprarLibro(titulo);
                return;
            }
        }
        cout << "no ingresaron comprador: " << endl;
    }

    void mostrarHistorialCompras(const string& nombreComprador) {
        for ( Comprador& comprador : listaCompradores) {
            if(comprador.getNombre() == nombreComprador) {
                comprador.verHistorialCompras();
                return;
            }
        }
        cout << "no ingresado el comprador: " << endl;
    }
};

int main() {
    Biblioteca biblioteca;

    biblioteca.agregarComprador("Juan", " a una calle desconicida");
    biblioteca.agregarComprador("victor", "ala calle perdida");

    biblioteca.comprarLibro("romeo y julieta", "Juan");
    biblioteca.comprarLibro("don quijote", "victor");

    biblioteca.mostrarHistorialCompras("Juan");
    biblioteca.mostrarHistorialCompras("victor");

    
    return 0;
}

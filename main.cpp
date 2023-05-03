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

class Libro {
private:
    int stock;
    string nombre;
    double precio;
    int calificacion;

public:
    Libro(const int _stock, const string& _nombre, const double _precio, const int _calificacion) {
        stock = _stock;
        nombre = _nombre;
        precio = _precio;
        calificacion = _calificacion;
      }
int getStock() const {
        return stock;
    }

void setStock(int stock_libro) {
  stock = stock_libro;
}

void info_libro(){
  if(stock > 0){
    cout << nombre << " tiene " << stock << " unidad(es) en stock y su precio es " << precio << " soles."<<endl;
    cout << "Su calificación actual es: " << calificacion << " estrella(s)" << endl;
  } 
  else{
    cout << nombre << " está agotado."<<endl;
  }
  
}
};

class Cajero {
	
private:
    string nombre, titulo ;
    double descuento = 0  ;
    double costo = 0.0;
    double costofinal = 0;
      
public:
    Cajero(const string& _nombre ,double _costo ,double _descuento )  {
    	nombre = _nombre ;
    	costofinal = _costo;
    	costo = _costo ; 
    	descuento = _descuento;
    }
double aplicardescuento( ) {
    double final;
    	if( descuento>0 ){
    		  final = costo - ( costo *( descuento / 100 )  );
    	}    	
    	return final;
    }   	
    
void boleta() {
      costofinal = this->aplicardescuento();

    	cout << "BIBLIOTECA SABERES" << endl;
    	cout << "Costo del producto: " << costo << endl;
    	cout << "Descuento: " << descuento << "%" << endl;
    	cout << ".............................................................." << endl;
    	cout << "Precio final: " << costofinal << endl;
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

    Libro libro(10, "Romeo y Julieta", 40.80, 4);
    libro.info_libro();

    Cajero cajero("Juan", 40, 30);
    // cajero.aplicardescuento();
    cajero.boleta();
    
    
    
    return 0;
}
#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <iostream>

// Clase para manejar matrices de cualquier tipo (int, float, double, etc)
template <typename T>
class MatrizDinamica {
private:
    T **datos;      // puntero doble para la matriz
    int filas;      // numero de filas
    int columnas;   // numero de columnas

public:
    // Constructor: crea la matriz con el tamaño que le pasemos
    MatrizDinamica(int f, int c) {
        filas = f;
        columnas = c;
        
        // primero creo el arreglo de filas
        datos = new T*[filas];
        
        // ahora para cada fila creo las columnas
        for(int i = 0; i < filas; i++) {
            datos[i] = new T[columnas];
            // inicializo todo en 0 para que no tenga basura
            for(int j = 0; j < columnas; j++) {
                datos[i][j] = 0;
            }
        }
    }
    
    // Destructor: libera la memoria cuando ya no se necesita
    ~MatrizDinamica() {
        // primero borro las columnas de cada fila
        for(int i = 0; i < filas; i++) {
            delete[] datos[i];
        }
        // despues borro el arreglo de filas
        delete[] datos;
    }
    
    // Para obtener las filas
    int getFilas() const {
        return filas;
    }
    
    // Para obtener las columnas
    int getColumnas() const {
        return columnas;
    }
    
    // Metodo para poner un valor en una posicion especifica
    void setValor(int i, int j, T valor) {
        if(i >= 0 && i < filas && j >= 0 && j < columnas) {
            datos[i][j] = valor;
        }
    }
    
    // Metodo para obtener un valor de una posicion
    T getValor(int i, int j) const {
        if(i >= 0 && i < filas && j >= 0 && j < columnas) {
            return datos[i][j];
        }
        return 0;
    }
    
    // Metodo para redimensionar la matriz
    void redimensionar(int nuevaF, int nuevaC) {
        // creo una matriz temporal con el nuevo tamaño
        T **temp = new T*[nuevaF];
        for(int i = 0; i < nuevaF; i++) {
            temp[i] = new T[nuevaC];
            // inicializo en 0
            for(int j = 0; j < nuevaC; j++) {
                temp[i][j] = 0;
            }
        }
        
        // copio los valores que pueda de la matriz vieja a la nueva
        // solo copio hasta donde alcance en ambas matrices
        int filasACopiar = (filas < nuevaF) ? filas : nuevaF;
        int columnasACopiar = (columnas < nuevaC) ? columnas : nuevaC;
        
        for(int i = 0; i < filasACopiar; i++) {
            for(int j = 0; j < columnasACopiar; j++) {
                temp[i][j] = datos[i][j];
            }
        }
        
        // libero la memoria de la matriz vieja
        for(int i = 0; i < filas; i++) {
            delete[] datos[i];
        }
        delete[] datos;
        
        // asigno la nueva matriz
        datos = temp;
        filas = nuevaF;
        columnas = nuevaC;
    }
    
    // Funcion estatica para multiplicar dos matrices
    static MatrizDinamica<T> multiplicar(const MatrizDinamica<T>& A, const MatrizDinamica<T>& B) {
        // verifico que se puedan multiplicar
        // las columnas de A deben ser iguales a las filas de B
        if(A.columnas != B.filas) {
            std::cout << "ERROR: No se pueden multiplicar, dimensiones incompatibles!" << std::endl;
            return MatrizDinamica<T>(0, 0);
        }
        
        // la matriz resultado tiene las filas de A y las columnas de B
        MatrizDinamica<T> C(A.filas, B.columnas);
        
        // hago la multiplicacion usando la formula de siempre
        // C[i][j] = suma de A[i][k] * B[k][j]
        for(int i = 0; i < A.filas; i++) {
            for(int j = 0; j < B.columnas; j++) {
                T suma = 0;
                for(int k = 0; k < A.columnas; k++) {
                    suma += A.datos[i][k] * B.datos[k][j];
                }
                C.datos[i][j] = suma;
            }
        }
        
        return C;
    }
    
    // Metodo para imprimir la matriz bonita
    void imprimir() const {
        for(int i = 0; i < filas; i++) {
            std::cout << "| ";
            for(int j = 0; j < columnas; j++) {
                std::cout << datos[i][j] << " | ";
            }
            std::cout << std::endl;
        }
    }
};

#endif

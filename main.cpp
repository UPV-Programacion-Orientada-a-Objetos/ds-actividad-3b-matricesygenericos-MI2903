#include "MatrizDinamica.h"

// Programa principal
int main() {
    std::cout << "--- Sistema de Analisis de Transformaciones Lineales ---\n" << std::endl;
    
    // PRUEBA CON ENTEROS
    std::cout << ">> Prueba de Matriz ENTERA (Matriz A) <<" << std::endl;
    std::cout << "Creando Matriz A (Tipo INT) de 2x3...\n" << std::endl;
    
    MatrizDinamica<int> A(2, 3);
    
    std::cout << "Ingresar valores para A (2x3):" << std::endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            int valor;
            std::cout << "A[" << i << "," << j << "]: ";
            std::cin >> valor;
            A.setValor(i, j, valor);
        }
    }
    
    std::cout << "\n>> Matriz A original <<" << std::endl;
    A.imprimir();
    
    // Redimensiono la matriz
    std::cout << "\n>> Redimensionando Matriz A <<" << std::endl;
    std::cout << "Redimensionando A a 3x3. Datos conservados:" << std::endl;
    A.redimensionar(3, 3);
    A.imprimir();
    
    //PRUEBA CON FLOTANTES
    std::cout << "\n>> Prueba de Multiplicacion (Tipo FLOAT) <<" << std::endl;
    std::cout << "Creando Matriz B (Tipo FLOAT) de 3x2...\n" << std::endl;
    
    MatrizDinamica<float> B(3, 2);
    
    std::cout << "Ingrese valores para B (3x2):" << std::endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            float valor;
            std::cout << "B[" << i << "," << j << "]: ";
            std::cin >> valor;
            B.setValor(i, j, valor);
        }
    }
    
    std::cout << "\n>> Matriz B <<" << std::endl;
    B.imprimir();
    
    // Convierto A a float para poder multiplicar
    std::cout << "\n>> Convirtiendo A a tipo FLOAT para multiplicar <<" << std::endl;
    MatrizDinamica<float> A_float(3, 3);
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            A_float.setValor(i, j, (float)A.getValor(i, j));
        }
    }
    
    // Multiplico las matrices
    std::cout << "\nMatriz C = A(3x3) x B(3x2) ...\n" << std::endl;
    MatrizDinamica<float> C = MatrizDinamica<float>::multiplicar(A_float, B);
    
    std::cout << "Matriz C (Resultado 3x2, Tipo FLOAT):" << std::endl;
    C.imprimir();
    
    std::cout << "\nLiberando memoria de todas las matrices..." << std::endl;
    std::cout << "(Se hace automaticamente con los destructores)" << std::endl;
    
    return 0;
}

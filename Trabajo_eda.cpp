
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <string>
#include <fstream>

using namespace std;

template <class T>
double distancia(std::vector<T> A, std::vector<T> B, int N)
{
    double sumatoria = 0;
    double aux;
    for (int x = 0; x < N; x++)
    {
        aux = B[x] - A[x];
        sumatoria += pow(aux, 2);
    }
    return sqrt(sumatoria);
}

template <class T>
void imprimir(std::vector<T> A,int  N)
{
    for (int x = 0; x < N; x++)
    {
        cout << A[x] << " ";
    }
    cout << endl;
}

template <class T>
int func()
{
    int num;
    num = 1 + rand() % (1001 - 1);
    return num;
}

class Expr {
public:
    int cantidad;
    int tamanho;
    int resultados[25];
    int contador = 0;

    int conducir()
    {

        std::vector<double> A(tamanho);
        std::generate(A.begin(), A.end(), func<double>);

        std::vector<std::vector<double>> vectores(cantidad);


        for (int x = 0; x < cantidad; x++)
        {
            std::vector<double> B(tamanho);
            std::generate(B.begin(), B.end(), func<double>);
            vectores[x] = B;
        }


        std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
        start = std::chrono::high_resolution_clock::now();

        for (int x = 0; x < cantidad; x++)
        {

            distancia<double>(A, vectores[x],tamanho);
        }


        end = std::chrono::high_resolution_clock::now();
        int64_t duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); // duration is holding the elapsed time
        resultados[contador]=duration;
        contador++;
        return duration;
    }
};


int main()
{

    Expr obj1;
    ofstream fich("tmp.txt");
    obj1.cantidad = 10000;
    obj1.tamanho = 10;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 10000;
    obj1.tamanho = 20;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 10000;
    obj1.tamanho = 30;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 10000;
    obj1.tamanho = 40;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 10000;
    obj1.tamanho = 50;
    cout << obj1.conducir() << endl;

    obj1.cantidad = 20000;
    obj1.tamanho = 10;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 20000;
    obj1.tamanho = 20;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 20000;
    obj1.tamanho = 30;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 20000;
    obj1.tamanho = 40;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 20000;
    obj1.tamanho = 50;
    cout << obj1.conducir() << endl;

    obj1.cantidad = 30000;
    obj1.tamanho = 10;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 30000;
    obj1.tamanho = 20;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 30000;
    obj1.tamanho = 30;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 30000;
    obj1.tamanho = 40;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 30000;
    obj1.tamanho = 50;
    cout << obj1.conducir() << endl;

    obj1.cantidad = 40000;
    obj1.tamanho = 10;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 40000;
    obj1.tamanho = 20;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 40000;
    obj1.tamanho = 30;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 40000;
    obj1.tamanho = 40;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 40000;
    obj1.tamanho = 50;
    cout << obj1.conducir() << endl;

    obj1.cantidad = 50000;
    obj1.tamanho = 10;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 50000;
    obj1.tamanho = 20;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 50000;
    obj1.tamanho = 30;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 50000;
    obj1.tamanho = 40;
    cout << obj1.conducir() << endl;
    obj1.cantidad = 50000;
    obj1.tamanho = 50;
    cout << obj1.conducir() << endl;

    if (!fich)
    {
        cout << "Error al abrir ejemplo.dat\n";
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 25; ++i)
        fich << obj1.resultados[i] << endl;
    
}

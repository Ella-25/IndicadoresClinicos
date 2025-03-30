/* ------ TRABALHO 1 - TÉCNICAS DE PROGRAMAÇÃO II ------
   -----------------------------------------------------
    Mirella Morigene de Souza (2262349)
    Isabella Ramos Santos (2297183)
*/

#include <iostream>
#include <cmath> //biblioteca para funções matemáticas, reconhecerá o sqrt (raiz quadrada)
using namespace std;

const int linhas = 11;  //"const int" declara variável de valor que não pode ser alterado depois de iniciar
const int minColunas = 3;
const int maxColunas = 7;

//calculo da distancia euclidiana entre paciente 1 e 2
float distanciaEuclidiana(float paciente1[], float paciente2[], int colunas){
    float soma = 0.0;
    for (int n = 0; n < colunas; n++){
        soma += pow(paciente1[n] - paciente2[n], 2); //eleva a difereça dos valores do paciente 1 e 2 por 2 (elevação ao quadrado)
    }
    
    return sqrt(soma); //retorna a raiz quadrada da soma dos quadrados das diferenças -> dist. euclidiana

}

//para encontrar o paciente histórico mais próximo:
int encontrarPaciente(float matriz[][maxColunas + 1], int colunas) {
    int indiceMaisProximo = 0;
    float menorDistancia = distanciaEuclidiana(matriz[linhas - 1], matriz[0], colunas);

    for (int n = 1; n < linhas - 1; n++) {
        float distancia = distanciaEuclidiana(matriz[linhas - 1], matriz[n], colunas);
        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            indiceMaisProximo = n;
        }
    }
    return indiceMaisProximo;
}

//para exibir a matriz por pacientes
void exibirMatriz(float matriz[][maxColunas + 1], int colunas) {
    cout << "\nTabela de pacientes por indicadores:\n";
    for (int n = 0; n < linhas; n++) {
        for (int j = 0; j <= colunas; j++) {
            cout << matriz[n][j] << "\t";
        }
        cout << endl;
    }
}

int main(){
    int colunas;

    cout << "\n***Classificaçao de Pacientes com Base em Indicadores de Saude***\n" << endl;

    //pedir número de colunas
    do{
        cout << "Determine a quantidade de indicadores clinicos (de " << minColunas << " a " << maxColunas << "): ";
        cin >> colunas;
    } while (colunas < minColunas || colunas > maxColunas); // o || serve como "ou"

    float matriz[linhas][maxColunas + 1];

    //digitar os dados dos pacientes
    cout << "\nDigite os dados dos 10 pacientes historicos:\n";
    for (int n = 0; n < linhas - 1; n++) {
        cout << "Paciente " << n + 1 << "\n";
        for (int j = 0; j < colunas; j++) {
            cout << "Indicador " << j + 1 << ": ";
            cin >> matriz[n][j];
        }
        cout << "Classificaçao (1.0 = Saudavel, -1.0 = Doente): ";
        cin >> matriz[n][colunas];
    }

    //digitar os dados do novo paciente
    cout << "\nDigite os dados do novo paciente\n";
    for (int j = 0; j < colunas; j++) {
        cout << "Indicador " << j + 1 << ": ";
        cin >> matriz[linhas - 1][j];
    }

    //para encontrar o paciente mais próximo
    int indiceMaisProximo = encontrarPaciente(matriz, colunas);
    matriz[linhas - 1][colunas] = matriz[indiceMaisProximo][colunas];

    //mostra a matriz finalizada com o paciente classificado
    exibirMatriz(matriz, colunas);

    //resultado do novo classificado
    cout << "\nO novo paciente foi classificado como: " 
         << (matriz[linhas - 1][colunas] == 1.0 ? "Saudavel" : "Doente") << endl;

    return 0;
}
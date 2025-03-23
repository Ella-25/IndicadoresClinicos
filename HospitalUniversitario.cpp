/* ------ TRABALHO 1 - TÉCNICAS DE PROGRAMAÇÃO II ------
   -----------------------------------------------------
    Mirella Morigene de Souza (2262349)
    Isabella Ramos Santos (2297183)
*/

#include <iostream>
using namespace std;

const int linhas = 11;  //"const int" declara variável de valor que não pode ser alterado depois de iniciar
const int minColunas = 3;
const int maxColunas = 7;

//calculo da distancia euclidiana entre paciente 1 e 2
float distanciaEuclidiana(const vector<float>& paciente1, const vector<float>& paciente2, int colunas){
    float soma = 0;
    for (int n = 0; n < colunas - 1; n++){
    float dif = paciente1[n] - paciente2[n];
        soma += dif * dif //eleva a difereça dos valores do paciente 1 e 2 por 2 (elevação ao quadrado)
    }
    
    return sqrt(soma); //retorna a raiz quadrada da soma dos quadrados das diferenças -> dist. euclidiana

}

int main(){
    int colunas;

    cout << "***Classificação de Pacientes com Base em Indicadores de Saúde***" << endl;

    //pedir número de colunas
    do{
        cout << "Determine a quantidade de indicadores clínicos (de " << minColunas << " a " << maxColunas << "): ";
        cin >> colunas;
    }

    return 0;
}
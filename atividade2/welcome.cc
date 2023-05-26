#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "lista.h"

/*
* Autores do Trabalho:
* 
* Vinícius Eduardo de Souza Honório - 2021.1.08.024
*/

using namespace std;

int main(){
    int i;
    string leitura;
    /*Iniciação da Lista, Pilha e Fila*/
    topo* inicio = inicia();
    topopf* pilha = iniciapf();
    topopf* fila = iniciapf();
    cout << "< Lista Iniciada >" << endl;
    no* elemento;
    ifstream myfile("BD_veiculos.txt");
    /*Leitura dos Dados*/
    if(myfile.is_open()){
        while(!myfile.eof()){
            no* carro = new(no);
            myfile >> carro->modelo;
            myfile >> carro->marca;
            myfile >> carro->tipo;
            myfile >> carro->ano;
            myfile >> carro->km;
            myfile >> carro->potência_do_motor;
            myfile >> carro->combustível;
            myfile >> carro->câmbio;
            myfile >> carro->direção;
            myfile >> carro->cor;
            myfile >> carro->portas;
            myfile >> carro->placa;
            insere(inicio, carro);
        }
        cout << "< Leitura Concluída >" << endl;
        myfile.close();
    }
    else
        cout << "! Não foi possível fazer a leitura do catálogo !" << endl;
    /*Lista de Opções*/
    do{
        cout << endl << "Opções:" << endl;
        cout << "1-Incluir" << endl;
        cout << "2-Excluir" << endl;
        cout << "3-Buscar" << endl;
        cout << "4-Relatar" << endl;
        cout << "0-Sair" << endl << "> ";
        cin >> i;
        switch(i){
            case 0:
             break;
            
            case 1:
             /*Cria um nó, faz leitura das características e insere na Lista Principal.*/
             elemento = new(no);
             entrada(elemento);
             insere(inicio, elemento);
             cout << "Elemento Inserido" << endl;
             break;
             
            case 2:
             /*Remove algum veículo, caso exista, por informação de sua placa.*/
             cout << "Digite a placa do veículo que deseja remover: ";
             cin >> leitura;
             remove(inicio, leitura);
             break;
            
            case 3:
             do{
                cout << endl << "Opções(Busca):" << endl;
                cout << "1-Pilha" << endl;
                if (pilha->tamanho > 0){
                    cout << "11-Exibir (Pilha)" << endl;
                    cout << "12-Remover (Pilha)" << endl;
                }
                cout << "2-Fila" << endl;
                if (fila->tamanho > 0){
                    cout << "21-Exibir (Fila)" << endl;
                    cout << "22-Remover (Fila)" << endl;
                }
                cout << "0-Cancelar" << endl << "> ";
                cin >> i;
                switch(i){
                    case 1:
                     /*Reinicia a Pilha, caso necessário*/
                     if(pilha->tamanho > 0){
                         encerrapf(pilha);
                         pilha = iniciapf();
                     }
                     constroipf(inicio, pilha);
                     /*Leitura do Primeiro Critério de Busca*/
                     do{
                         if(i < 0 || i > 12)
                             cout << i << ": Opção Inválida!" << endl;
                         cout << endl << "Opções(Primeira Categoria):" << endl;
                         cout << "1- Modelo" << endl;
                         cout << "2- Marca" << endl;
                         cout << "3- Tipo" << endl;
                         cout << "4- Ano" << endl;
                         cout << "5- KM" << endl;
                         cout << "6- Potência do Motor" << endl;
                         cout << "7- Combustível" << endl;
                         cout << "8- Câmbio" << endl;
                         cout << "9- Direção" << endl;
                         cout << "10-Cor" << endl;
                         cout << "11-Portas" << endl;
                         cout << "12-Placa" << endl;
                         cout << "0- Vazia" << endl << "> ";
                         cin >> i;
                     }while(i < 0 || i > 12);
                     if(i != 0){
                        cout << "Digite o que deseja buscar: ";
                        cin >> leitura;
                     }
                     buscapf(pilha, i, leitura);
                     i = 1;
                     /*Leitura do Segundo Critério de Busca*/
                     do{
                         if(i < 0 || i > 12)
                             cout << i << ": Opção Inválida!" << endl;
                         cout << endl << "Opções(Segunda Categoria):" << endl;
                         cout << "1- Modelo" << endl;
                         cout << "2- Marca" << endl;
                         cout << "3- Tipo" << endl;
                         cout << "4- Ano" << endl;
                         cout << "5- KM" << endl;
                         cout << "6- Potência do Motor" << endl;
                         cout << "7- Combustível" << endl;
                         cout << "8- Câmbio" << endl;
                         cout << "9- Direção" << endl;
                         cout << "10-Cor" << endl;
                         cout << "11-Portas" << endl;
                         cout << "12-Placa" << endl;
                         cout << "0- Vazia" << endl << "> ";
                         cin >> i;
                     }while(i < 0 || i > 12);
                     if(i != 0){
                        cout << "Digite o que deseja buscar: ";
                        cin >> leitura;
                     }
                     buscapf(pilha, i, leitura);
                     i = 1;
                     break;

                    case 2:
                     /*Reinicia a Fila, caso necessário*/
                     constroipf(inicio, fila);
                     if(fila->tamanho > 0){                         
                         encerrapf(fila);
                         fila = iniciapf();
                     }
                     /*Leitura do Primeiro Critério de Busca*/
                     do{
                         if(i < 0 || i > 12)
                             cout << i << ": Opção Inválida!" << endl;
                         cout << endl << "Opções(Primeira Categoria):" << endl;
                         cout << "1- Modelo" << endl;
                         cout << "2- Marca" << endl;
                         cout << "3- Tipo" << endl;
                         cout << "4- Ano" << endl;
                         cout << "5- KM" << endl;
                         cout << "6- Potência do Motor" << endl;
                         cout << "7- Combustível" << endl;
                         cout << "8- Câmbio" << endl;
                         cout << "9- Direção" << endl;
                         cout << "10-Cor" << endl;
                         cout << "11-Portas" << endl;
                         cout << "12-Placa" << endl;
                         cout << "0- Vazia" << endl << "> ";
                         cin >> i;
                     }while(i < 0 || i > 12);
                     if(i != 0){
                        cout << "Digite o que deseja buscar: ";
                        cin >> leitura;
                     }
                     buscapf(fila, i, leitura);
                     i = 2;
                     /*Leitura do Segundo Critério de Busca*/
                     do{
                         if(i < 0 || i > 12)
                             cout << i << ": Opção Inválida!" << endl;
                         cout << endl << "Opções(Segunda Categoria):" << endl;
                         cout << "1- Modelo" << endl;
                         cout << "2- Marca" << endl;
                         cout << "3- Tipo" << endl;
                         cout << "4- Ano" << endl;
                         cout << "5- KM" << endl;
                         cout << "6- Potência do Motor" << endl;
                         cout << "7- Combustível" << endl;
                         cout << "8- Câmbio" << endl;
                         cout << "9- Direção" << endl;
                         cout << "10-Cor" << endl;
                         cout << "11-Portas" << endl;
                         cout << "12-Placa" << endl;
                         cout << "0- Vazia" << endl << "> ";
                         cin >> i;
                     }while(i < 0 || i > 12);
                     if(i != 0){
                        cout << "Digite o que deseja buscar: ";
                        cin >> leitura;
                     }
                     buscapf(fila, i, leitura);
                     i = 2;
                     break;
                    
                    case 11:
                     /*Exibe a Pilha*/
                     if(pilha->tamanho <= 0)
                         cout << "! A Pilha não foi inicializada !" << endl;
                     else{
                        cout << endl;
                        imprimepf(pilha);
                        cout << endl;
                     }
                     break;
                     
                    case 21:
                     /*Exibe a Fila*/
                     if(fila->tamanho <= 0)
                         cout << "! A Fila não foi inicializada !" << endl;
                     else{
                        cout << endl;
                        imprimepf(fila);
                        cout << endl;
                     }
                     break;
                     
                    case 12:
                     /*Remove um elemento (último) da Pilha*/
                     if(pilha->tamanho <= 0)
                         cout << "! A Pilha não foi inicializada !" << endl;
                     else{
                        cout << endl;
                        removep(pilha);
                        cout << endl;
                     }
                     break;
                        
                    case 22:
                     /*Remove um elemento (primeiro) da Fila*/
                     if(fila->tamanho <= 0)
                         cout << "! A Fila não foi inicializada !" << endl;
                     else{
                        cout << endl;
                        removef(fila);
                        cout << endl;
                     }
                     break;

                    case 0:
                     break;

                    default:
                     cout << i << ": Opção Inválida!" << endl;
                     break;
                }
             }while(i != 0);
             i = 3;
             break;
            
            case 4:
             /*Imprime a Lista Principal.*/
             imprime(inicio);
             break;
            
            default:
             cout << i << ": Opção Inválida!" << endl;
             break;
        }
    }while(i != 0);
    /*Atualização do Arquivo*/
    atualiza(inicio);
    /*Encerramento da Lista, Pilha e Fila*/
    encerra(inicio);
    encerrapf(pilha);
    encerrapf(fila);
    cout << "< Lista Encerrada >" << endl;
    cout << endl << "Esse programa foi desenvolvido por:" << endl;
    cout << "Brandon Afonso de Souza - 2021.1.08.045" << endl;
    cout << "Paulo Eduardo Souza de Melos - 2020.1.08.044" << endl;
    cout << "Vinícius Eduardo de Souza Honório - 2021.1.08.024" << endl;
    return 0;
}
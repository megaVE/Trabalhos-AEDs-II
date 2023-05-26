#include <iostream>
#include <fstream>
#include "listaarvore.h"

/*
* Autor do Trabalho:
* Vinícius Eduardo de Souza Honório - 2021.1.08.024
*/

/*
 *              ! OBSERVAÇÃO IMPORTANTE !
 * 
 * " A Árvore AVL não foi completamente implementada
 *  e não encontra-se funcional no código atual; mas
 *  existem rascunhos de funções por entre o código
 *  que representam como esse tipo de árvore poderia
 *  se comportar, no caso de sucesso da implementação
 *  de cada uma das funções. "
 * 
 *  " Reconheço que não foi entregue o que foi pedido,
 *    mas sugiro que os rascunhos também sejam avaliados,
 *    no momento da correção. "
 */

using namespace std;

int main(){
    int i;
    string leitura;
    /*Iniciação da Lista e das Árvores*/
    topo* lista = inicia();
    topoa* ab = iniciaa();
    topoa* avl = iniciaa();
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
            insere(lista, carro);
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
        cout << "4-Construir Árvore" << endl;
        cout << "5-Relatar" << endl;
        cout << "6-Relatar (Árvore)" << endl;
        cout << "0-Sair" << endl << "> ";
        cin >> i;
        cout << endl;
        switch(i){
            case 0:
             break;
            
            case 1:
             /*Cria um nó, faz leitura das características e insere na Lista Principal.*/
             elemento = new(no);
             entrada(elemento);
             insere(lista, elemento);
             if(ab->primeiro == NULL)
                 cout << "! Árvore Binária Não Inicializada !" << endl;
             else
                 ab->primeiro = inserea(ab->primeiro, elemento, 1, ab);
             /*if(avl->primeiro == NULL)
                 avl->primeiro = inserea(avl->primeiro, elemento, 1, avl);
             else{
                 rbalanceamento(buscaa(avl, elemento->placa));
                 //Deve verificar toda árvore por desbalanceamento.
                 if(verificab(avl->primeiro) != NULL){
                     rbalancear(avl, buscaa(avl, elemento->placa)); // Problemas aqui
                     tbalanceamento(avl->primeiro);
                 }
                 avl->mnivel = 0;
                 rnivel(avl, avl->primeiro, 1);
             }*/
             cout << "Elemento Inserido" << endl;
             break;
             
            case 2:
             /*Remove algum veículo, caso exista, por informação de sua placa.*/
             cout << "Digite a placa do veículo que deseja remover:" << endl << "> ";
             cin >> leitura;
             cout << "Binária:" << endl;
             if(buscaa(ab, leitura) != NULL){
                 removea(ab, leitura);
                 ab->mnivel = 0;
                 if(ab->primeiro != NULL)
                     rnivel(ab, ab->primeiro, 1);
                 cout << "Nível Máximo Atual: " << ab->mnivel << endl;
             }
             else
                 cout << "! Elemento Não Existente (Árvore Binária) !" << endl;
             /*cout << "AVL:" << endl;
             if(buscaa(ab, leitura) != NULL){
                 noa* aux = buscaapai(avl, leitura);
                 removea(avl, leitura);
                 while(verificab(avl->primeiro) != NULL){
                     rbalancear(avl, buscaa(avl, aux->placa)); // Problemas aqui
                     tbalanceamento(avl->primeiro);
                 }
                 avl->mnivel = 0;
                 if(avl->primeiro != NULL) 
                     rnivel(avl, avl->primeiro, 1);
                 cout << "Nível Máximo Atual: " << avl->mnivel << endl;
             }
             else
                 cout << "! Elemento Não Existente (Árvore AVL) !" << endl;*/
             remove(lista, leitura);
             break;
            
            case 3:
             /*Busca, com base na placa, algum veículo da Lista ou de alguma Árvore.*/
             cout << "Digite a placa do veículo que deseja buscar:" << endl << "> ";
             cin >> leitura;
             do{
                cout << endl << "Opções(Busca):" << endl;
                cout << "1-Lista Principal" << endl;
                cout << "2-Árvore Binária" << endl;
                cout << "3-Árvore AVL" << endl;
                cout << "0-Cancelar" << endl << "> ";
                cin >> i;
                cout << endl;
                switch(i){
                    case 1:
                     busca(lista, leitura);
                     break;
                     
                    case 2:
                     if(ab->primeiro == NULL)
                         cout << "! Árvore Binária Não Inicializada !" << endl;
                     else{
                        if(buscaa(ab, leitura) == NULL)
                            cout << "! Elemento Não Encontrado (Árvore Binária) !" << endl;
                        else
                            cout << "< Elemento Encontrado (Árvore Binária) >" << endl;
                     }
                     break;
                    
                    case 3:
                     if(avl->primeiro == NULL)
                         cout << "! Árvore AVL Não Inicializada !" << endl;
                     else{
                        if(buscaa(avl, leitura) == NULL)
                            cout << "! Elemento Não Encontrado (Árvore AVL) !" << endl;
                        else
                            cout << "< Elemento Encontrado (Árvore AVL) >" << endl;
                     }
                     break;
                    
                    case 0:
                     break;

                    default:
                     cout << i << ": Opção Inválida!" << endl;
                     break;     
                }
             } while(i < 0 || i > 3);
             i = 3;
             break;
             
            case 4:
             do{
                cout << endl << "Opções(Construção):" << endl;
                cout << "1-Árvore Binária" << endl;
                cout << "2-Árvore AVL" << endl;
                cout << "0-Cancelar" << endl << "> ";
                cin >> i;
                cout << endl;
                switch(i){
                    case 1:
                     if(lista->tamanho <= 0)
                         cout << "! A Lista está Vazia !" << endl;
                     else{
                         no* aux = lista->proximo;
                         while(aux != NULL){
                             ab->primeiro = inserea(ab->primeiro, aux, 1, ab);
                             aux = aux->proximo;
                         }
                         cout << endl << "Maior Nível: " << ab->mnivel << endl;
                         cout << "< Árvore Binária Criada >" << endl;
                     }
                     break;

                    case 2:
                     if(lista->tamanho <= 0)
                         cout << "! A Lista está Vazia !" << endl;
                     else{
                         cout << " !! Iniciação da Árvore AVL Não Implementada !! " << endl;
                         /*no* aux = lista->proximo;
                         while(aux != NULL){
                             avl->primeiro = inserea(avl->primeiro, aux, 1, avl);
                             rbalanceamento(buscaa(avl, aux->placa));
                             //Deve verificar toda árvore por desbalanceamento.
                             if(verificab(avl->primeiro) != NULL){
                                 rbalancear(avl, buscaa(avl, aux->placa)); // Problemas aqui
                                 tbalanceamento(avl->primeiro);
                             }
                             aux = aux->proximo;
                         }
                         avl->mnivel = 0;
                         rnivel(avl, avl->primeiro, 1);
                         cout << endl << "Maior Nível: " << avl->mnivel << endl;
                         cout << "< Árvore AVL Criada >" << endl;*/
                     }
                     break;

                    case 0:
                     break;

                    default:
                     cout << i << ": Opção Inválida!" << endl;
                     break;      
                }
             } while (i < 0 || i > 2);
             i = 4;
             break;
            
            case 5:
             /*Imprime a Lista Principal.*/
             imprime(lista);
             break;
             
            case 6:
             /*Imprime, em pré-ordem, as Árvores.*/
             do{
                cout << endl << "Opções(Impressão):" << endl;
                cout << "1-Árvore Binária" << endl;
                cout << "2-Árvore AVL" << endl;
                cout << "0-Cancelar" << endl << "> ";
                cin >> i;
                cout << endl;
                switch(i){
                    case 1:
                     imprimea(ab->primeiro, 1);
                     break;

                    case 2:
                     imprimea(avl->primeiro, 1);
                     break;

                    case 0:
                     break;

                    default:
                     cout << i << ": Opção Inválida!" << endl;
                     break;
                }
             } while (i < 0 || i > 2);
             i = 6;
             break;
            
            default:
             cout << i << ": Opção Inválida!" << endl;
             break;
        }
    }while(i != 0);
    /*Atualização do Arquivo*/
    atualiza(lista);
    /*Encerramento da Lista e das Árvores*/
    if(ab->primeiro != NULL){
        encerraa(ab->primeiro);
        cout << "< Árvore Binária Encerrada >" << endl;
    }
    if(avl->primeiro != NULL){
        encerraa(avl->primeiro);
        cout << "< Árvore AVL Encerrada >" << endl;
    }
    delete(ab);
    delete(avl);
    encerra(lista);
    cout << "< Lista Encerrada >" << endl;
    cout << endl << "Esse programa foi desenvolvido por:" << endl;
    cout << "- Vinícius Eduardo de Souza Honório - 2021.1.08.024" << endl;
    return 0;
}
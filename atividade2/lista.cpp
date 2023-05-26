/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

/*Declaração da estrutura dos nós da Lista Principal.*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

typedef struct no_{
    string modelo;
    string marca;
    string tipo;
    string ano;
    string km;
    string potência_do_motor;
    string combustível;
    string câmbio;
    string direção;
    string cor;
    string portas;
    string placa;
    struct no_ *proximo;
}no;

/*Declaração da estrutura dos nós da Pilha e da Fila de Busca.*/
typedef struct nopf{
    struct no_ *elemento;
    struct nopf *proximo;
}nofp;

/*Declaração da estrutura do primeiro nó da Lista Principal.*/
typedef struct topo{
    int tamanho;
    struct no_ *proximo;
    struct no_ *primeiro;
    struct no_ *ultimo;
};

/*Declaração da estrutura do primeiro nó da Pilha ou da Fila de Busca.*/
typedef struct topopf{
    int tamanho;
    struct nopf *proximo;
    struct nopf *primeiro;
    struct nopf *ultimo;
}topofp;

topo* inicia(){
    /*Inicia a Lista Principal pela inserção do primeiro nó.*/
    topo* inicio = new(topo);
    inicio->tamanho = 0;
    inicio->proximo = NULL;
    inicio->primeiro = NULL;
    inicio->ultimo = NULL;
    return inicio;
}

topopf* iniciapf(){
    /*Inicia a Pila ou Fila de busca pela inserção do primeiro nó.*/
    topopf* inicio = new(topopf);
    inicio->tamanho = 0;
    inicio->proximo = NULL;
    inicio->primeiro = NULL;
    inicio->ultimo = NULL;
    return inicio;
}

void encerra(topo* inicio){
    /*Desaloca a memória ocupada pela Lista Principal.*/
    no* ant;
    no* act = inicio->proximo;
    while(act != NULL){
        ant = act;
        act = act->proximo;
        delete(ant);
    }
    delete(inicio);
}

void encerrapf(topopf* inicio){
    /*Desaloca a memória ocupada pela Pilha ou Fila de Busca.*/
    nopf* ant;
    nopf* act = inicio->proximo;
    while(act != NULL){
        ant = act;
        act = act->proximo;
        delete(ant);
    }
    delete(inicio);
}

void insere(topo* inicio, no* insere){
    /*Insere um nó na Lista Principal, ordenado com base na placa.*/
    no *ant = NULL;
    no *act = inicio->proximo;
    while(act != NULL && act->placa < insere->placa){
        ant = act;
        act = act->proximo;
    }
    if(ant == NULL){
        inicio->proximo = insere;
        inicio->primeiro = insere;
    }
    else{
        ant->proximo = insere;
    }
    insere->proximo = act;
    if(act == NULL)
        inicio->ultimo = insere;
    inicio->tamanho++;
}

void constroipf(topo* iniciolista, topopf* inicio){
    /*Coloca todos os elementos da Lista Principal em uma Pilha ou Fila.*/
    no* lista = iniciolista->proximo;
    nopf* pf;
    if(iniciolista->tamanho > 0){
        nopf* aux = new(nopf);
        aux->elemento = lista;
        inicio->tamanho++;
        inicio->proximo = aux;
        inicio->primeiro = aux;
        pf = inicio->proximo;
        lista = lista->proximo;
    }
    while(lista != NULL){
        nopf* aux = new(nopf);
        aux->elemento = lista;
        aux->proximo = NULL;
        inicio->tamanho++;
        pf->proximo = aux;
        pf = pf->proximo;
        lista = lista->proximo;
    }
    inicio->ultimo = pf;
}

no* entrada(no* entrada){
    /*Recebe, do usuário, os dados de um nó; para inserção na Lista Principal.*/
    cout << "Insira o MODELO do veículo: ";
    cin >> entrada->modelo;
    cout << "Insira a MARCA do veículo: ";
    cin >> entrada->marca;
    cout << "Insira o TIPO do veículo: ";
    cin >> entrada->tipo;
    cout << "Insira o ANO do veículo: ";
    cin >> entrada->ano;
    cout << "Insira a QUILOMETRAGEM do veículo: ";
    cin >> entrada->km;
    cout << "Insira a POTÊNCIA do veículo: ";
    cin >> entrada->potência_do_motor;
    cout << "Insira o COMBUSTÍVEL do veículo: ";
    cin >> entrada->combustível;
    cout << "Insira o tipo de CÂMBIO do veículo: ";
    cin >> entrada->câmbio;
    cout << "Insira o tipo de DIREÇÃO do veículo: ";
    cin >> entrada->direção;
    cout << "Insira a COR do veículo: ";
    cin >> entrada->cor;
    cout << "Insira a quantidade de PORTAS do veículo: ";
    cin >> entrada->portas;
    cout << "Insira a PLACA do veículo: ";
    cin >> entrada->placa;
    cout << "< Elemento Registrado >" << endl;
    return entrada;
}

void buscapf(topopf* inicio, int codigo, string busca){
    /*Realiza buscas em uma Pilha ou Fila por meio da exclusão dos elementos não correspondentes ao critério selecioando.*/
    nopf* ant = NULL;
    nopf* act = inicio->proximo;
    switch(codigo){
        case 0:
         break;
        
        case 1:
         while(act != NULL && act->elemento->modelo != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->modelo != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
         
        case 2:
         while(act != NULL && act->elemento->marca != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->marca != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
         
        case 3:
         while(act != NULL && act->elemento->tipo != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->tipo != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
         
        case 4:
         while(act != NULL && act->elemento->ano != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->ano != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;

        case 5:
         while(act != NULL && act->elemento->km != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->km != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;

        case 6:
         while(act != NULL && act->elemento->potência_do_motor != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->potência_do_motor != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
         
        case 7:
         while(act != NULL && act->elemento->combustível != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->combustível != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
         
        case 8:
         while(act != NULL && act->elemento->câmbio != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->câmbio != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
         
        case 9:
         while(act != NULL && act->elemento->direção != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->direção != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
         
        case 10:
         while(act != NULL && act->elemento->cor != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->cor != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
         
        case 11:
         while(act != NULL && act->elemento->portas != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->portas != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
         
        case 12:
         while(act != NULL && act->elemento->placa != busca){
             ant = act;
             inicio->proximo = act->proximo;
             delete ant;
             ant = NULL;
             inicio->tamanho--;
             act = inicio->proximo;
             inicio->primeiro = inicio->proximo;
         }
         ant = act;
         act = act->proximo;
         while(act != NULL){
            if(act->elemento->placa != busca){
                ant->proximo = act->proximo;
                delete act;
                inicio->tamanho--;
                act = ant->proximo;
            }
            else{
                ant = act;
                act = act->proximo;
            }
         }
         break;
    }
}

void remove(topo* inicio, string remove){
    /*Remove um elemento da Lista Principal com base na placa.*/
    int i = 0;
    no* p = inicio->proximo;
    no* aux;
    if(p->placa == remove){
        i = 1;
        inicio->proximo = p->proximo;
        inicio->primeiro = inicio->proximo;
        delete p;
        inicio->tamanho--;
    }
    else{
        while(p->proximo != NULL && i == 0){
            if(p->proximo->placa == remove){
                i = 1;
            }
            else{
                p = p->proximo;
            }
        }
        if(p != NULL && i == 1){
            aux = p->proximo;
            p->proximo = aux->proximo;
            if(p->proximo == NULL)
                inicio->ultimo = p;
            delete aux;
            inicio->tamanho--;
        }
    }
    if(i == 1)
        cout << "< Elemento Removido >" << endl;
    else
        cout << "! Elemento Não Encontrado !" << endl;
}

void removep(topopf* inicio){
    /*Remove o último elemento da Pilha.*/
    nopf* aux;
    if(inicio->tamanho <= 0)
        cout << "! Nenhum Elemento Encontrado !" << endl;
    else{
        aux = inicio->proximo;
        if(inicio->tamanho == 1){
            delete aux;
            inicio->proximo = NULL;
            inicio->primeiro = NULL;
            inicio->ultimo = NULL;
        }
        else{
            while(aux->proximo->proximo != NULL)
                aux = aux->proximo;
            delete(aux->proximo);
            aux->proximo = NULL;
            inicio->ultimo = aux;
        }
        cout << "< Elemento Removido >" << endl;
        inicio->tamanho--;
    }
}

void removef(topopf* inicio){
    /*Remove o primeiro elemento da Fila.*/
    nopf* aux;
    if(inicio->tamanho <= 0)
        cout << "! Nenhum Elemento Encontrado !" << endl;
    else{
        aux = inicio->proximo;
        inicio->proximo = aux->proximo;
        inicio->primeiro = inicio->proximo;
        delete aux;
        cout << "< Elemento Removido >" << endl;
        inicio->tamanho--;
        if(inicio->tamanho == 0)
            inicio->ultimo = NULL;
    }
}

void imprime(topo* inicio){
    /*Imprime, na tela, um relatório com todos os elementos da Lista Principal.*/
    no *p = inicio->proximo;
    int i = 1;
    while(p != NULL){
        cout << "-" << i << "-" << endl << endl;
        cout << "Modelo: " << p->modelo << endl;
        cout << "Marca: " << p->marca << endl;
        cout << "Tipo: " << p->tipo << endl;
        cout << "Ano: " << p->ano << endl;
        cout << "KM: " << p->km << endl;
        cout << "Potência do Motor: " << p->potência_do_motor << endl;
        cout << "Combustível: " << p->combustível << endl;
        cout << "Câmbio: " << p->câmbio << endl;
        cout << "Direção: " << p->direção << endl;
        cout << "Cor: " << p->cor << endl;
        cout << "Portas: " << p->portas << endl;
        cout << "Placa: " << p->placa << endl << endl;
        p = p->proximo;
        i++;
    }
    cout << endl;
    cout << "- Número de Veículos Registrados: " << inicio->tamanho << endl;
    cout << "- Primeira Placa: " << inicio->primeiro->placa << endl;
    cout << "- Última Placa: " << inicio->ultimo->placa << endl << endl;
    cout << "< Lista Impressa >" << endl;
}

void imprimepf(topopf* inicio){
    /*Imprime, na tela, um relatório com todos os elementos buscados numa Pilha ou Fila.*/
    nopf *aux = inicio->proximo;
    no *p;
    int i = 1;
    while(aux != NULL){
        p = aux->elemento;
        cout << "-" << i << "-" << endl << endl;
        cout << "Modelo: " << p->modelo << endl;
        cout << "Marca: " << p->marca << endl;
        cout << "Tipo: " << p->tipo << endl;
        cout << "Ano: " << p->ano << endl;
        cout << "KM: " << p->km << endl;
        cout << "Potência do Motor: " << p->potência_do_motor << endl;
        cout << "Combustível: " << p->combustível << endl;
        cout << "Câmbio: " << p->câmbio << endl;
        cout << "Direção: " << p->direção << endl;
        cout << "Cor: " << p->cor << endl;
        cout << "Portas: " << p->portas << endl;
        cout << "Placa: " << p->placa << endl << endl;
        aux = aux->proximo;
        i++;
    }
    cout << endl;
    cout << "- Número de Veículos Encontrados: " << inicio->tamanho << endl << endl;
    cout << "- Primeira Placa: " << inicio->primeiro->elemento->placa << endl;
    cout << "- Última Placa: " << inicio->ultimo->elemento->placa << endl;
    cout << "< Busca Impressa >" << endl;
}

void atualiza(topo* inicio){
    /* Escreve, no Arquivo de Texto, os dados lidos, armazenados e modificados pelo programa.*/
    no* p = inicio->proximo;
    ofstream myfile("BD_veiculos.txt");
    if(myfile.is_open()){
        while(p != NULL){
            myfile << p->modelo << " ";
            myfile << p->marca << " ";
            myfile << p->tipo << " ";
            myfile << p->ano << " ";
            myfile << p->km << " ";
            myfile << p->potência_do_motor << " ";
            myfile << p->combustível << " ";
            myfile << p->câmbio << " ";
            myfile << p->direção << " ";
            myfile << p->cor << " ";
            myfile << p->portas << " ";
            myfile << p->placa;
            if(p->proximo != NULL)
                myfile << endl;
            p = p->proximo;
        }
        cout << "< Lista Atualizada >" << endl;
    }
    else
        cout << "! Não foi possível fazer a atualização do catálogo !" << endl;
}
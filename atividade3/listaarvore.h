/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   listaarvore.h
 * Author: vinih
 *
 * Created on 12 de abril de 2022, 23:38
 */
#include <iostream>
#include <fstream>

using namespace std;

#ifndef LISTAARVORE_H
#define LISTAARVORE_H

/*Declaração da estrutura dos nós da Lista Principal.*/
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

/*Declaração da estrutura do primeiro nó da Lista Principal.*/
struct topo{
    int tamanho;
    struct no_ *proximo;
    struct no_ *primeiro;
    struct no_ *ultimo;
};

/*Declaração da estrutura dos nós das Árvores*/
typedef struct noa_{
    int balanceamento;
    int nivel;
    struct no_ *elemento;
    struct noa_ *esquerdo;
    struct noa_ *direito;
}noa;

/*Declaração da estrutura do primeiro nó das Árvores.*/
struct topoa{
    int mnivel;
    struct noa_ *primeiro;
};

topo* inicia();
topoa* iniciaa();
void encerra(topo* inicio);
void encerraa(noa* inicio);
void insere(topo* inicio, no* insere);
noa* inserea(noa* inicio, no* insere, int nivel, topoa* nonivel);
void rnivel(topoa* inicio, noa* ajusta, int n);
int rnivelmod(noa* calcula, int h, int max);
void rbalanceamento(noa* ajusta);
void tbalanceamento(noa* ajusta);
no* entrada(no* entrada);
no* busca(topo* inicio, string parametro);
noa* buscaa(topoa* inicio, string parametro);
noa* buscaapai(topoa* inicio, string parametro);
void rsesquerda(topoa* inicio, noa* c);
void rsdireita(topoa* inicio, noa* a);
void rdesquerda(topoa* inicio, noa* b);
void rddireita(topoa* inicio, noa* b);
void rbalancear(topoa* inicio, noa* ultimo);
noa* verificab(noa* inicio);
void remove(topo* inicio, string remove);
void removea(topoa* inicio, string parametro);
void imprime(topo* inicio);
void imprimea(noa* inicio, int valor);
void atualiza(topo* inicio);

#endif /* LISTAARVORE_H */


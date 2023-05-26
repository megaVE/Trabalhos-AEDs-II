/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   lista.h
 * Author: vinih
 *
 * Created on 29 de março de 2022, 18:45
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

#ifndef LISTA_H
#define LISTA_H

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

topo* inicia();
topopf* iniciapf();
void encerra(topo* inicio);
void encerrapf(topopf* inicio);
void insere(topo* inicio, no* insere);
void constroipf(topo* iniciolista, topopf* inicio);
no* entrada(no* entrada);
void buscapf(topopf* inicio, int codigo, string busca);
void remove(topo* inicio, string remove);
void removep(topopf* inicio);
void removef(topopf* inicio);
void imprime(topo* inicio);
void imprimepf(topopf* inicio);
void atualiza(topo* inicio);

#endif /* LISTA_H */


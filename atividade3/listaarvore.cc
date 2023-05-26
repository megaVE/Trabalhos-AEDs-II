#include <iostream>
#include <fstream>

using namespace std;

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

topo* inicia(){
    /*Inicia a Lista Principal pela inserção do primeiro nó.*/
    topo* inicio = new(topo);
    inicio->tamanho = 0;
    inicio->proximo = NULL;
    inicio->primeiro = NULL;
    inicio->ultimo = NULL;
    return inicio;
}

topoa* iniciaa(){
    /*Inicia uma Árvore pela inserção do primeiro nó.*/
    topoa* inicio = new(topoa);
    inicio->mnivel = 0;
    inicio->primeiro = NULL;
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

void encerraa(noa* inicio){
    /*Desaloca a memória ocupada por uma Árvore.*/
    if(inicio->esquerdo != NULL)
        encerraa(inicio->esquerdo);
    if(inicio->direito != NULL)
        encerraa(inicio->direito);
    if(inicio != NULL)
        delete(inicio);
}

void insere(topo* inicio, no* insere){
    /*Insere um nó na Lista Principal, ordenado com base na ordem das informações do arquivo.*/
    no* aux;
    if (inicio->proximo == NULL)
        inicio->proximo = insere;
    else{
        no* aux = inicio->proximo;
        while(aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = insere;
    }
    if(inicio->tamanho == 0)
        inicio->primeiro = insere;
    inicio->ultimo = insere;
    inicio->tamanho++;
}

noa* inserea(noa* inicio, no* insere, int nivel, topoa* nonivel){
    /*Insere um nó em alguma das Árvores, ordenado com base na placa do veículo.*/
    if(inicio == NULL){
        noa* novo = new(noa);
        novo->elemento = insere;
        novo->balanceamento = 0;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->nivel = nivel;
        nonivel->primeiro = novo;
        if(nivel > nonivel->mnivel)
            nonivel->mnivel = nivel;
        return novo;
    }
    else{
        nivel++;
        if(insere->placa < inicio->elemento->placa){
            inicio->balanceamento++;
            inicio->esquerdo = inserea(inicio->esquerdo, insere, nivel, nonivel);
        }
        else{
            inicio->balanceamento--;
            inicio->direito = inserea(inicio->direito, insere, nivel, nonivel);
        }
    }
    return inicio;
}

void rnivel(topoa* inicio, noa* ajusta, int n){
    /*Re-escreve os níveis de cada nó da árvore, após uma remoção ou operação de balanceamento.*/
    ajusta->nivel = n;
    if(n > inicio->mnivel)
        inicio->mnivel = n;
    if(ajusta->esquerdo != NULL)
        rnivel(inicio, ajusta->esquerdo, n+1);
    if(ajusta->direito != NULL)
        rnivel(inicio, ajusta->direito, n+1);
}

int rnivelmod(noa* calcula, int h, int max){
    /*Calcula o máximo nível relativo de uma subárvore, para balanceamento (Árvore AVL).*/
    if(h > max)
        max = h;
    if(calcula->esquerdo != NULL)
        rnivelmod(calcula->esquerdo, h+1, max);
    if(calcula->direito != NULL)
        rnivelmod(calcula->direito, h+1, max);
    return max;
}

void rbalanceamento(noa* ajusta){
    /*Define ou redefine o valor de balanceamento de um nó (Árvore AVL).*/
    int i = 0;
    if(ajusta->esquerdo != NULL)
        i = i + rnivelmod(ajusta->esquerdo, 1, 1);
    if(ajusta->direito != NULL)
        i = i - rnivelmod(ajusta->direito, 1, 1);
    ajusta->balanceamento = i;
}

void tbalanceamento(noa* ajusta){
    /*Define ou redefine o valor de balanceamento de cada um dos nós (Árvore AVL).*/
    rbalanceamento(ajusta);
    if(ajusta->esquerdo != NULL)
        tbalanceamento(ajusta->esquerdo);
    if(ajusta->direito != NULL)
        tbalanceamento(ajusta->direito);
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

no* busca(topo* inicio, string parametro){
    /*Busca, na Lista Principal, algum elemento; com base na placa.*/
    no* busca = inicio->proximo;
    while(busca != NULL && busca->placa != parametro)
        busca = busca->proximo;
    if(busca == NULL)
        cout << "! Elemento Não Encontrado (Lista) !" << endl;
    else
        cout << "< Elemento Encontrado (Lista) >" << endl;
    return busca;
}

noa* buscaa(topoa* inicio, string parametro){
    /*Busca, em uma das árvores, algum elemento; com base na placa.*/
    noa* busca = inicio->primeiro;
    while(busca != NULL && busca->elemento->placa != parametro){
        if(busca->elemento->placa > parametro)
            busca = busca->esquerdo;
        else
            busca = busca->direito;
    }
    return busca;
}

noa* buscaapai(topoa* inicio, string parametro){
    /*Busca, em uma das árvores, o pai de algum elemento; com base na placa (Função Auxiliar).*/
    if(buscaa(inicio, parametro) == NULL || inicio->primeiro->elemento->placa == parametro){
        /*Não existe pai caso o elemento não exista ou seja a raiz.*/
        return NULL;
    }
    else{
        noa* busca = inicio->primeiro;
        /*Nota: As condições "redundantes" evitam erro stackdumping.*/
        while((busca->esquerdo == NULL || busca->esquerdo->elemento->placa != parametro) && (busca->direito == NULL || busca->direito->elemento->placa != parametro)){
            if(busca->elemento->placa > parametro)
                busca = busca->esquerdo;
            else
                busca = busca->direito;
        }
        return busca;
    }
}

void rsesquerda(topoa* inicio, noa* c){
    /*Rotação Simples à Esquerda.*/
    noa* b = buscaapai(inicio, c->elemento->placa);
    noa* a = buscaapai(inicio, b->elemento->placa);
    noa* d = buscaapai(inicio, a->elemento->placa);
    if(d == NULL)
        inicio->primeiro = b;
    else{
        if(d->esquerdo == a)
            d->esquerdo = b;
        else
            d->direito = b;   
    }
    b->esquerdo = a;
}

void rsdireita(topoa* inicio, noa* a){
    /*Rotação Simples à Direita.*/
    noa* b = buscaapai(inicio, a->elemento->placa);
    noa* c = buscaapai(inicio, b->elemento->placa);
    noa* d = buscaapai(inicio, c->elemento->placa);
    if(d == NULL)
        inicio->primeiro = b;
    else{
        if(d->esquerdo == c)
            d->esquerdo = b;
        else
            d->direito = b;
    }
    b->direito = c;
}

void rdesquerda(topoa* inicio, noa* b){
    /*Rotação Dupla à Esquerda.*/
    noa* c = buscaapai(inicio, b->elemento->placa);
    noa* a = buscaapai(inicio, c->elemento->placa);
    noa* d = buscaapai(inicio, a->elemento->placa);
    if(d == NULL)
        inicio->primeiro = b;
    else{
        if(d->esquerdo == a)
            d->esquerdo = b;
        else
            d->direito = b;
    }
    b->esquerdo = a;
    b->direito = c;
    c->esquerdo = NULL;
    a->direito = NULL;
}

void rddireita(topoa* inicio, noa* b){
    /*Rotação Dupla à Direita.*/
    noa* a = buscaapai(inicio, b->elemento->placa);
    noa* c = buscaapai(inicio, a->elemento->placa);
    noa* d = buscaapai(inicio, c->elemento->placa);
    if(d = NULL)
        inicio->primeiro = b;
    else{
        if(d->esquerdo == c)
            d->esquerdo = b;
        else
            d->direito = b;
    }
    b->esquerdo = a;
    b->direito = c;
    c->esquerdo = NULL;
    a->direito = NULL;
}

void rbalancear(topoa* inicio, noa* ultimo){
    /*Realiza alguma das 4 operações de balanceamento, no caso de uma inserção ou remoção causar desbalanceamento (Árvore AVL).*/
    noa* aux = inicio->primeiro;
    while(aux->balanceamento <= 1 && aux->balanceamento >= -1){
        if(aux->elemento->placa > ultimo->elemento->placa)
            aux = aux->esquerdo;
        else
            aux = aux->direito;
    }
    if(aux->elemento->placa > ultimo->elemento->placa){
        aux = aux->esquerdo;
        if(aux->elemento->placa > ultimo->elemento->placa){
            rsdireita(inicio, aux);
        }
        else{
            rddireita(inicio, aux);
        }
    }
    else{
        aux = aux->direito;
        if(aux->elemento->placa > ultimo->elemento->placa){
            rdesquerda(inicio, aux);
        }
        else{
            rsesquerda(inicio, aux);
        }
    }
}

noa* verificab(noa* inicio){
    /*Retorna o primeiro nó desbalanceado encontrado ou nulo, caso não encontre (Árvore AVL).*/
    if(inicio != NULL && (inicio->balanceamento < -1 || inicio->balanceamento > 1))
        return inicio;
    if(inicio->esquerdo != NULL)
        verificab(inicio->esquerdo);
    if(inicio->direito != NULL)
        verificab(inicio->direito);
    return NULL;
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
        cout << "< Elemento Removido (Lista) >" << endl;
    else
        cout << "! Elemento Não Encontrado (Lista) !" << endl;
}

void removea(topoa* inicio, string parametro){
    /*Remove um elemento de alguma das Árvores com base na placa.*/
    noa* busca = buscaa(inicio, parametro);
    noa* pai = buscaapai(inicio, parametro);
    if(busca->esquerdo == NULL || busca->direito == NULL){
        /*Caso o nó não tenha um dos filhos, basta redirecionar o ponteiro do pai.*/
        if(pai == NULL){
            if(busca->direito == NULL)
                inicio->primeiro = busca->esquerdo;
            else
                inicio->primeiro = busca->direito;
        }
        else{
            if(pai->esquerdo == busca && busca->direito == NULL)
                pai->esquerdo = busca->esquerdo;
            if(pai->esquerdo == busca && busca->esquerdo == NULL)
                pai->esquerdo = busca->direito;
            if(pai->direito == busca && busca->direito == NULL)
                pai->direito = busca->esquerdo;
            if(pai->direito == busca && busca->esquerdo == NULL)
                pai->direito = busca->direito;
        }
    }
    /*Caso o nó tenha ambos os filhos, ele será substituído.*/
    else{
        /*Coleta o nó substituto.*/
        noa* sub = busca->esquerdo;
        noa* aux;
        while(sub->direito != NULL)
            sub = sub->direito;
        aux = buscaapai(inicio, sub->elemento->placa);
        if(aux->esquerdo == sub && sub->direito == NULL)
            aux->esquerdo = sub->esquerdo;
        if(aux->esquerdo == sub && sub->esquerdo == NULL)
            aux->esquerdo = sub->direito;
        if(aux->direito == sub && sub->direito == NULL)
            aux->direito = sub->esquerdo;
        if(aux->direito == sub && sub->esquerdo == NULL)
            aux->direito = sub->direito;
        /*Troca o nó a ser removido pelo substituto.*/
        sub->esquerdo = busca->esquerdo;
        sub->direito = busca->direito;
        if(pai == NULL)
            inicio->primeiro = sub;
        else{
            if(pai->esquerdo == NULL)
                pai->direito = sub;
            if(pai->direito == NULL)
                pai->esquerdo = sub;
        }
    }
    delete(busca);
    cout << "< Elemento Removido (Árvore) >" << endl;
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

void imprimea(noa* inicio, int valor){
    /*Imprime, na tela, um relatório com todos os elementos de alguma Árvore; em pré-ordem.*/
    if(inicio == NULL){
        cout << "! Árvore Vazia ou Não Criada !" << endl;
        return;
    }
    else{
        cout << "Nível: " << inicio->nivel << endl;
        cout << "Balanceamento: " << inicio->balanceamento << endl << endl;
        cout << "Modelo: " << inicio->elemento->modelo << endl;
        cout << "Marca: " << inicio->elemento->marca << endl;
        cout << "Tipo: " << inicio->elemento->tipo << endl;
        cout << "Ano: " << inicio->elemento->ano << endl;
        cout << "KM: " << inicio->elemento->km << endl;
        cout << "Potência do Motor: " << inicio->elemento->potência_do_motor << endl;
        cout << "Combustível: " << inicio->elemento->combustível << endl;
        cout << "Câmbio: " << inicio->elemento->câmbio << endl;
        cout << "Direção: " << inicio->elemento->direção << endl;
        cout << "Cor: " << inicio->elemento->cor << endl;
        cout << "Portas: " << inicio->elemento->portas << endl;
        cout << "Placa: " << inicio->elemento   ->placa << endl << endl;
        if(inicio->esquerdo != NULL){
            imprimea(inicio->esquerdo, ++valor);
        }
        if(inicio->direito != NULL){
            imprimea(inicio->direito, ++valor);
        }
    }
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
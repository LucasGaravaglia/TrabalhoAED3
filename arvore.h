#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include "arquivo.h"
#include "estruturaArvore.h"

using namespace std;

class BMais{
private:
    NoBMais no;          //Variável que guarda o nó que está sendo manipulado
    CabecalhoArvore cab; //Variavel que manipula o cabeçalho do arquivo arvore.bin
    int pos;             //Posição do nó que está carregado na memória no arquivo
public:
    Arquivo arquivo;     //Variavel que manipula o arquivo arvore.bin

    //contrutor da classe
    BMais();

    //setter da variavel no
    void setNo(NoBMais no);

    //setter da variavel cab
    void setCab(CabecalhoArvore cab);

    //get da variavel no
    NoBMais getNo();

    //get da variavel cab
    CabecalhoArvore getCab();

    //set da variavel pos
    void setPos(int pos);

    //get da variavel pos
    int getPos();

    /* Método que busca a posição em que está ou estaria a chave em um nó
     * Entrada:      Árvore b+, A chave, Ponteiro para a posição em que estaria a chave
     * Retorno:      true caso a chave esteja presente ou false caso contrário
     * Pré-condição: Nó não pode ser NULL
     * Pós-condição: Nenhuma
    */    
    bool buscarPos(int chave, int *pos);

    /* Método que faz o split de um nó interno(Não folha)
     * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
     * Retorno:      posição do novo nó no arquivo binario
     * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
     * Pós-condição: O nó sofre split e promove a chave mediana
    */
    int splitB(Chave *chavePromovida);

    /* Método que faz o split de um nó interno(Folha)
     * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
     * Retorno:      posição da nova folha no arquivo binario
     * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
     * Pós-condição: O nó sofre split e promove a chave mediana
    */
    int splitBMais(Chave *chavePromovida);

    /* Método que adiciona uma chave à direita de pos
     * Entrada:      Nó, posição, chave e filho da direita
     * Retorno:      Nenhum
     * Pré-condição: Nó não pode ser NULL
     * Pós-condição: A chave é adiciona à direita de pos
    */
    void adicionarDireita(int pos, Chave chave, int subarvore);

    /* Método que verifica se tem overflow no nó
     * Entrada:      Nenhuma
     * Retorno:      True se houver overflow false caso contrario
     * Pre-condicao: No não null
     * Pos-condicao: Nenhuma
    */
    bool overflow();

    /* Método auxiliar para inserir uma chave
     * Entrada:      Arvore b+ e chave a ser inserida
     * Retorno:      Nenhum
     * Pré-condição: A árvore não pode ser NULL
     * Pós-condição: A chave é inserida na árvore
    */
    void inserirAux(Chave chave);

    /* Método que insere uma chave na arvore , fazendo split caso necessario
     * Entrada:      chave a ser inserida
     * Retorno:      Nenhum
     * Pre-condicao: Nenhum
     * Pos-condicao: Nenhum
    */
    void inserir(Chave chave);

    /* Método que imprime um vetor da árvore B+
     * Entrada:      Vetor e tamanho do vetor
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    void printVetBMais(Chave *v, int n);

    /* Método que imprime um nivel da árvore b+
     * Entrada:      Nível a ser impresso e nível atual
     * Retorno:      Nenhum
     * Pré-condição: Raiz não nula
     * Pós-condição: O nível é impresso por nível.
    */
    void imprimirPorNivel(int nivel, int atual);

    /* Método que calcula a altura da árvore B+
     * Entrada:      Nenhuma
     * Retorno:      Altura da árvore B+
     * Pré-condição: Raiz não nula
     * Pós-condição: A altura da árvore é calculada e retornada
    */
    int altura();

    /* Método que imprime todos os níveis da árvore b+
     * Entrada:      Nenhuma
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: Todos os níveis da árvore são impressos
    */
    void imprimirTodoOsNiveis();

    /* Método que muda o nó que está carregado na classe
     * Entrada:      Posição do nó que será carregado do arquivo
     * Retorno:      Nenhum
     * Pré-condição: Nenhum
     * Pós-condição: O nó é carregado para a classe
    */
    void mudarNo(int posNo);

    /* Método usado para ler todas as informações de um nó inseridoo no arquivo
     * Entrada:      Posição do nó no arquivo
     * Retorno:      Nenhum
     * Pre-condicao: Nenhum
     * Pos-condicao: Nenhum
    */
    void DeBug(int pos);

    /* Método que busca em qual nó FOLHA está uma chave
     * Entrada:      Chave a ser procurada e ponteiro para a chave no vetor
     * Retorno:      Nó em que a chave foi encontrada ou no.numChaves 1 caso não a ache
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    NoBMais buscarChave(Chave chave, int *pos);

    /* Método que busca em qual nó FOLHA está uma chave
     * Entrada:      Chave a ser procurada, ponteiro para a chave no vetor e para o nó no arquivo
     * Retorno:      Nó em que a chave foi encontrada ou no.numChaves 1 caso não a ache
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    NoBMais buscarChave(Chave chave, int *posChave, int *posNo);

    /* Método que busca em qual nó FOLHA está uma chave
     * Entrada:      Chave a ser procurada, ponteiro para a chave no vetor e para o nó no arquivo
     * Retorno:      Posição do livro no arquivo de dados  ou -1 caso não encontre
     * Pré-condição: Chave existente
     * Pós-condição: Nenhuma
    */
    int buscarChave(Chave chave);

    /* Método que retorna a posição do folha mais à esquerda
     * Entrada:      Nenhuma
     * Retorno:      Posição da primeira folha no arquivo de nós ou -1 caso não tenha
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    int pegarPrimeiraFolha();

    /* Métod que checa se um nó está em underflow
     * Entrada:      Nenhuma
     * Retorno:      True caso o nó esteja em uderflow ou False caso contrário
     * Pré-condição: Nó não nulo
     * Pós-condição: Nenhuma
    */
    bool underflow();

    /* Método que arrasta tudo que está à direita de pos para pós no vetor de chaves
     * Entrada:      Posição que será apagada
     * Retorno:      Nenhum
     * Pré-condição: O nó que está sendo manipulado deve estar carregado na classe
     * Pós-condição: A chave na posição pos é retirada do vetor
    */
    void arrastaPraEsquerda(int pos){

    /* Método que remove uma chave de um nó folha
     * Entrada:      Chave a ser removida
     * Retorno:      Posição do livro no arquivo de livros da chave que foi removida
     * Pré-condição: Nó não nulo. Nó em que a chave será removida deve estar na classe
     * Pós-condição: A chave é removida do nó
    */
    int removerChaveNaFolha(Chave chave);

    //destrutor da classe
    ~BMais();
};

#endif
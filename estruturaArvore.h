#ifndef ESTRUTURAARVORE_H
#define ESTRUTURAARVORE_H

#include <iostream>

using namespace std;
#define ORDEM 5

//Estrutura para árvore B+
typedef struct{
    int posLivro[ORDEM]; //Posição dos livros no arquivo binário de livros
    int  filhos[ORDEM+1]; //ORDEM é o ponteiro para o irmão
    int    chave[ORDEM]; //Vetor de chaves
    int       numChaves;
    bool        ehFolha;
    int             pai;
}NoBMais;

typedef struct{
    int topo,posLivre,raiz;
}CabecalhoArvore;


//Classe para representar a árvore B+
class BMais{
private:
    NoBMais no;
    CabecalhoArvore cab;
public:
    //Construtor padrão da classe BMais
    BMais();

    //Construtor com os parâmetros do nó
    BMais(NoBMais no);

    /* Setter da variável no
     * Entrada:      No
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável nó recebe o valor do parâmetro
    */
    void setNo(NoBMais no);

    /* Getter da variável no
     * Entrada:      Nenhuma
     * Retorno:      Nó
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    NoBMais getNo();

    /* Setter da variável cab
     * Entrada:      Cabeçalho do arquivo de árvore
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável cabeçalho recebe o valor do parâmetro
    */
    void setCabecaloArvore(CabecalhoArvore cab);

    /* Getter da variável cab
     * Entrada:      Nenhuma
     * Retorno:      Cabeçalho do arquivo de árvore
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    CabecalhoArvore getCabecalhoArvore();

    /* Método que busca a posição em que está ou estaria a chave em um nó
     * Entrada:      Árvore b+, A chave, Ponteiro para a posição em que estaria a chave
     * Retorno:      1 caso a chave esteja presente ou 0 caso contrário
     * Pré-condição: Nó não pode ser NULL
     * Pós-condição: Nenhuma
    */
    int buscaPos(int chave, int *pos);

    /* Método que faz o split de um nó interno(Não folha)
     * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
     * Retorno:      Nó criado pelo split
     * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
     * Pós-condição: O nó sofre split e promove a chave mediana
    */
    NoBMais* splitB(int *chavePromovida);

    /* Método que faz o split de um nó interno(Não folha)
     * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
     * Retorno:      Nó criado pelo split
     * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
     * Pós-condição: O nó sofre split e promove a chave mediana
    */
    NoBMais* splitBMais(int *chavePromovida, int **ponteiroNovoNo);

    /* Método que adiciona uma chave à direita de pos
     * Entrada:      Nó, posição, chave e filho da direita
     * Retorno:      Nenhum
     * Pré-condição: Nó não pode ser NULL
     * Pós-condição: A chave é adiciona à direita de pos
    */
    void adicionaDireita(int pos, int chave, int subarvore);

    /* Método auxiliar para inserir uma chave
     * Entrada:      Arvore b+ e chave a ser inserida
     * Retorno:      Nenhum
     * Pré-condição: A árvore não pode ser NULL
     * Pós-condição: A chave é inserida na árvore
    */
    void insereAux(int chave);

    //Destrutor da classe BMais
    ~BMais();
};

#endif
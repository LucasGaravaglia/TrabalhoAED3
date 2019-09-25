#ifndef ESTRUTURALIVRO_H
#define ESTRUTURALIVRO_H

#include <iostream>
#include <string.h>

using namespace std;

//Estrutura para armazenar as informações de um livro
typedef struct{
    int codigo,quantidade;
    char titulo[1250],autor[1250];
}InfoLivro;

//Estrutura para armazenar o cabeçalho do arquivo de livros
typedef struct{
    int topo,posLivre;
}CabecalhoLivro;

//Classe que mantém um livro
class Livro{
private:
    InfoLivro livro;
    CabecalhoLivro cab;
public:
    //Construtor padrão da classe Livro
    Livro();

    //Construtor completo da classe Livro
    Livro(int quantidade, int codigo, char* titulo, char* autor);

    //Construtor que recebe o livro
    Livro(InfoLivro livro);

    /* Setter do livro
     * Entrada:      Quantidade, Código, título e autor do livro
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: O livro é setado com as informações passadas
    */
    void setLivro(int quantidade, int codigo, char* titulo, char *autor);

    /* Getter do livro
     * Entrada:      Nenhuma
     * Retorno:      Struct contendo as informações do livro
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    InfoLivro getLivro();

    /* Setter do cabeçalho do arquivo de livros
     * Entrada:      Topo e posição livre
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: O cabeçalho do livro é setado com as informações passadas
    */
    void setCab(int topo, int posLivre);

    /* Getter do cabeçalho do livro
     * Entrada:      Nenhuma
     * Retorno:      Struct contendo as informações do cabeçalho do livro
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    CabecalhoLivro getCab();

    /* Método que monta a string representando o livro
     * Entrada:      Nenhuma
     * Retorno:      String contendo o livro
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    string toString();

    /* Método que permite alterar o número de exemplares de um livro
     * Entrada:      Quantidade de livros
     * Retorno:      Nenhum
     * Pré-condição: O livro do qual se deseja alterar o número de exemplares deve estar carregado
     * Pós-condição: A quantidade de exemplares do livro carregado é alterada
    */
    void atualizarExemplares(int quantidade);

    //Destrutor da classe Livro
    ~Livro();
};

#endif
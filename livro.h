#ifndef LIVRO_H
#define LIVRO_H

#include <iostream>
#include <string.h>
#include "estruturaLivro.h"
#include "arquivo.h"

using namespace std;

//Classe que mantém um livro
class Livro{
private:
    InfoLivro livro;
    CabecalhoLivro cab;
public:
    Arquivo arquivo;
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

    /* Setter do livro
     * Entrada:      Livro
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: O livro é setado com as informações passadas
    */
    void setLivro(InfoLivro livro);

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

    /* Método que insere um livro no arquivo de dados
     * Entrada:      Struct de livro
     * Retorno:      posição inserida no arquivo
     * Pre-condicao: Nenhum
     * Pos-condicao: Nenhum
    */
    int insereLivro(InfoLivro livro);

    /* Método que remove um livro do arquivo de dados
     * Entrada:      Posição do livro no arquivo
     * Retorno:      Nenhum
     * Pre-condicao: Nenhum
     * Pos-condicao: Nenhum
    */
    void removeLivro(int pos);

    //Destrutor da classe Livro
    ~Livro();
};

#endif
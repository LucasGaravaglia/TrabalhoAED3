#ifndef INTERACA_H
#define INTERACA_H

#include "gerenciamento.h"
#include "arquivo.h"
#include <iostream>

class Interacao{
private:
    Gerente gerente;
public:

    //Contrutor da classe Interacao
    Interacao();

    //Setter da variavel gerente
    void setGerente(Gerente gerente);

    //Getter da variavel gerente
    Gerente getGerente();

    /* Método que recebe uma string e remove os espaços excedentes
     * Entrada:      String a ser alterada
     * Retorno:      Nenhum
     * Pre-condicao: String não null
     * Pos-condicao: Nenhum
    */
    //void removeSpaces(char *s);

    //InfoLivro Interacao::criaLivro(char *linha);

    // /* Carrega o arquivo inicial
    //  * Entrada:      Nenhum
    //  * Retorno:      Nenhum
    //  * Pré-condição: Nenhum
    //  * Pós-condição: Nenhum
    // */
    // void loadStartFile();

    /* Faz a interação com o usuario para inserir um livro
     * Entrada:      Nenhum
     * Retorno:      Nenhum
     * Pré-condição: Nenhum
     * Pós-condição: Nenhum
    */
    void insereLivro();

    /* Faz a interação com o usuario para remover um livro
     * Entrada:      Nenhum
     * Retorno:      Nenhum
     * Pré-condição: Nenhum
     * Pós-condição: Nenhum
    */
    void removeLivro();

    /* Faz interação com o usuario para atualizar os exemplares
     * Entrada:      Nenhum
     * Retorno:      Nenhum
     * Pré-condição: Nenhum
     * Pós-condição: Nenhum
    */
    void atualizaExemplares();

    //Destrutor da classe interacao
    ~Interacao();

};

#endif
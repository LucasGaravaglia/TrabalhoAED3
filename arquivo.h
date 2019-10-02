#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <string.h>
#include "estruturaLivro.h"
#include "estruturaArvore.h"

using namespace std;

class Arquivo{
private:
    FILE* entrada;
    FILE* saida;
    string nomeEntrada,nomeSaida;
public:
    //Construtor da classe Arquivo
    Arquivo(string nomeEntrada, string nomeSaida);

    //Construtor da classe Arquivo
    Arquivo();

    //Setter do nome do arquivo de entrada
    void setNomeEntrada(string nomeEntrada);

    //Setter do nome do arquivo de saida
    void setNomeSaida(string nomeSaida);

    //Getter do arquivo de entrada
    FILE* getEntrada();

    //Getter do nome do arquivo de entrada
    string getNomeEntrada();

    //Getter do arquivo de saida
    FILE* getSaida();

    //Getter do nome do arquivo de saida
    string getNomeSaida();

    /* Método que escreve o cabeçalho no arquivo binário de livros
     * Entrada:      Cabeçalho de livros
     * Retorno:      Nenhum
     * Pré-condição: A variavel nomeSaida deve possuir o nome correto do arquivo de saida
     * Pós-condição: O cabeçalho é escrito no arquivo binário de livros
    */
    void escreverCabecalhoLivro(CabecalhoLivro cab);

    /* Método que lê o cabeçalho no arquivo binário de livros
     * Entrada:      Nenhuma
     * Retorno:      Cabeçalho lido ou -1 no cab.topo caso não consiga ler
     * Pré-condição: A variável nomeEntrada deve possuir o nome correto do arquivo de entrada
     * Pós-condição: O cabeçalho é lido do arquivo binário de livros
    */
    CabecalhoLivro lerCabecalhoLivro();

    /* Método que escreve o cabeçalho no arquivo binário de árvore
     * Entrada:      Cabeçalho de árvore
     * Retorno:      Nenhum
     * Pré-condição: A variavel nomeSaida deve possuir o nome correto do arquivo de saida
     * Pós-condição: O cabeçalho é escrito no arquivo binário de árvore
    */
    void escreverCabecalhoArvore(CabecalhoArvore cab);

    /* Método que lê o cabeçalho no arquivo binário de árvore
     * Entrada:      Nenhuma
     * Retorno:      Cabeçalho lido ou cab.topo -1 caso não consiga ler
     * Pré-condição: A variável nomeEntrada deve possuir o nome correto do arquivo de entrada
     * Pós-condição: O cabeçalho é lido do arquivo binário de árvore
    */
    CabecalhoArvore lerCabecalhoArvore();

    /* Método que escreve o arquivo binário vazio de livros
     * Entrada:      Nenhuma
     * Retorno:      Nenhum
     * Pré-condição: A variável nomeSaida deve possuir o nome correto do arquivo de saida
     * Pós-condição: O arquivo binário vazio de livros é escrito
    */
    void escreverArquivoLivrosVazio();

    /* Método que escreve o arquivo binário vazio de árvore
     * Entrada:      Nenhuma
     * Retorno:      Nenhum
     * Pré-condição: A variável nomeSaida deve possuir o nome correto do arquivo de saida
     * Pós-condição: O arquivo binário vazio de árvore é escrito
    */
    void escreverArquivoArvoreVazio();

    /* Método que escreve um livro na posição indicada no arquivo binário de livros
     * Entrada:      Livro a ser escrito e posição em que será escrita
     * Retorno:      Nenhum
     * Pré-condição: A variável nomeSaida deve possuir o nome correto do arquivo de saída
     * Pós-condição: O livro é escrito no arquivo binário de livros
    */
    void escreverLivro(InfoLivro livro, int pos);

    /* Método que lê um livro do arquivo binário de livros
     * Entrada:      Posição da qual será lida o livro no arquivo
     * Retorno:      Livro lido ou livro.quantidade -1 caso não consiga ler
     * Pré-condição: A variável nomeEntrada deve possuir o nome correto do arquivo de entrada
     * Pós-condição: O livro na posição fornecida é lido e retornado
    */
    InfoLivro lerLivro(int pos);

    /* Método que escreve um nó na posição indicada no arquivo binário de árvore
     * Entrada:      Nó a ser escrito e posição em que será escrito
     * Retorno:      Nenhum
     * Pré-condição: A variável nomeSaida deve possuir o nome correto do arquivo de saída
     * Pós-condição: O nó é escrito no arquivo binário de árvore
    */
    void escreverNo(NoBMais no, int pos);

    /* Método que lê um nó do arquivo binário de árvore
     * Entrada:      Posição da qual será lida o nó no arquivo
     * Retorno:      Nó lido ou no.numChaves -1 caso não consiga ler
     * Pré-condição: A variável nomeEntrada deve possuir o nome correto do arquivo de entrada
     * Pós-condição: O nó na posição fornecida é lido e retornado
    */
    NoBMais lerNo(int pos);

    //Destrutor da class Arquivo
    ~Arquivo();
};

#endif
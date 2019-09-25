#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <iostream>
#include <cstring>
#include "estruturaLivro.h"
#include "estruturaArvore.h"
#include "utilizaveis.h"

using namespace std;

class Arquivo{
private:
    FILE*   saida;
    FILE* entrada;
    string nomeSaida,nomeEntrada;
    bool sucessoNaLeitura,saidaAberta,entradaAberta;
    Log log;
public:
    //Construtor padrão da classe Arquivo
    Arquivo();

    //Construtor que recebe o nome do arquivo de entrada
    Arquivo(string nomeEntrada);

    //Construtor que recebe o nome do arquivo de entrada e o de saida
    Arquivo(string nomeEntrada, string nomeSaida);

    /* Setter da variável nomeSaida
     * Entrada:      Nome do arquivo de saida
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável nomeSaida é atualizada com o parâmetro passado
    */
    void setNomeSaida(string nomeSaida);

    /* Getter da variável nomeSaida
     * Entrada:      Nenhuma
     * Retorno:      Nome do arquivo de saida
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    string getNomeSaida();

    /* Setter da variável nomeEntrada
     * Entrada:      Nome do arquivo de entrada
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável nomeEntrada é atualizada com o parâmetro passado
    */
    void setNomeEntrada(string nomeEntrada);

    /* Getter da variável nomeEntrada
     * Entrada:      Nenhuma
     * Retorno:      Nome do arquivo de entrada
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    string getNomeENtrada();

    /* Setter da variável saida
     * Entrada:      Ponteiro para o arquivo de saida
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável saida é atualizada com o parâmetro passado
    */
    void setSaida(FILE* saida);

    /* Getter da variável saida
     * Entrada:      Nenhuma
     * Retorno:      Ponteiro para o arquivo de saida
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    FILE* getSaida();

    /* Setter da variável entrada
     * Entrada:      Ponteiro para o arquivo de entrada
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável entrada é atualizada com o parâmetro passado
    */
    void setEntrada(FILE* entrada);

    /* Getter da variável entrada
     * Entrada:      Nenhuma
     * Retorno:      Ponteiro para o arquivo de entrada
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    FILE* getEntrada();

    /* Setter da variável sucessoNaLeitura
     * Entrada:      Boolean
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: O valor da variável sucessoNaLeitura é atualizado
    */
    void setSucesso(bool sucesso);

    /* Getter da variável sucessoNaLeitura
     * Entrada:      Nenhuma
     * Retorno:      Verdadeiro ou falso
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    bool getSucesso();

    /* Setter da variável saidaAberta
     * Entrada:      True ou false
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável é setada para o valor do parâmetro
    */
    void setSaidaAberta(bool saidaAberta);

    /* Getter da varável saidaAberta
     * Entrada:      Nenuma
     * Retorno:      True ou false
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    bool getSaidaAberta();

    /* Setter da variável entradaAberta
     * Entrada:      True ou false
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável é setada para o valor do parâmetro
    */
    void setEntradaAberta(bool entradaAberta);

    /* Getter da varável entradaAberta
     * Entrada:      Nenuma
     * Retorno:      True ou false
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */  
    bool getEntradaAberta();

    /* Método que abre o arquivo de saida para a escrita
     * Entrada:      Nome do arquivo de saida
     * Retorno:      True caso consiga abrir ou false caso contrário
     * Pré-condição: Nenhuma
     * Pós-condição: O arquivo saida é aberto para escrita com a opção "r+b"
    */
    bool abrirSaida(char* arquivo);

    /* Método que fecha o arquivo de saida
     * Entrada:      Nenhuma
     * Retorno:      True caso consiga fechar ou false caso contrário
     * Pré-condição: O arquivo deve estar aberto
     * Pós-condição: O arquivo é fechado
    */
    bool fecharSaida();

    /* Método que abre o arquivo de entrada para a leitura
     * Entrada:      Nome do arquivo de entrada
     * Retorno:      True caso consiga abrir ou false caso contrário
     * Pré-condição: Nenhuma
     * Pós-condição: O arquivo entrada é aberto para leitura
    */
    bool abrirEntrada(char* arquivo);

    /* Método que fecha o arquivo de entrada
     * Entrada:      Nenhuma
     * Retorno:      True caso consiga fechar ou false caso contrário
     * Pré-condição: O arquivo deve estar aberto
     * Pós-condição: O arquivo é fechado
    */
    bool fecharEntrada();

    /* Método que escreve o cabeçalho no arquivo de livros
     * Entrada:      Ponteiro para a struct que contém o cabeçalho do arquivo de livros a ser escrito
     * Retorno:      True caso tenha dado certo ou false caso contrário
     * Pré-condição: A variável nomeSaida deve estar preenchida com nome correto.
     * Pós-condição: O cabeçalho é escrito no arquivo de saída
    */
    bool escreverCabecalhoLivros(CabecalhoLivro* cab);

    /* Método que lê o cabeçalho no arquivo de livros
     * Entrada:      Nenhuma
     * Retorno:      Struct do cabeçalho lido ou NULL caso não leia
     * Pré-condição: A variável entrada deve estar preenchida com o nome correto.
     * Pós-condição: O cabeçalho é lido e retornado do arquivo de entrada
    */
    CabecalhoLivro* lerCabecalhoLivros();

    /* Método que cria um arquivo de livros vazio
     * Entrada:      Nenhuma
     * Retorno:      True caso tenha dado certo ou false caso contrário
     * Pré-condição: A variavel nomeSaida deve possuir o nome correto
     * Pós-condição: O arquivo de livros é inicializado
    */
    bool criarArquivoLivrosVazio();

    /* Método que escreve o cabeçalho no arquivo de árvore
     * Entrada:      Cabeçalho do arquivo de árvore
     * Retorno:      True caso consiga escrever ou false caso contrário
     * Pré-condição: A variável nomeSaida deve estar com o nome corereto
     * Pós-condição: O cabeçalho é escrito no arquivo de saida
    */
    bool escreverCabecalhoArvore(CabecalhoArvore* cab);

    /* Método que lê o cabeçalho no arquivo de árvore
     * Entrada:      Nenhuma
     * Retorno:      Struct do cabeçalho lido ou NULL caso não leia
     * Pré-condição: A variável entrada deve estar preenchida com o nome correto.
     * Pós-condição: O cabeçalho é lido e retornado do arquivo de entrada
    */
    CabecalhoArvore* lerCabecalhoArvore();

    /* Método que cria um arquivo de árvore vazio
     * Entrada:      Nenhuma
     * Retorno:      True caso tenha dado certo ou false caso contrário
     * Pré-condição: A variavel nomeSaida deve possuir o nome correto
     * Pós-condição: O arquivo de árvore é inicializado
    */
    bool criarArquivoArvoreVazio();

    //Destrutor padrão da classe Arquivo
    ~Arquivo();
};

#endif
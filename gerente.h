#ifndef GERENTE_H
#define GERENTE_H
#include "arquivo.h"
#include "arvore.h"
#include "livro.h"

class Gerente{
private:
    Livro livro;
    NoBMais arvore;
public:
    
    //Contrutor da classe gerente
    Gerente();
    
    //Setter da classe Livro
    void setLivro(Livro livro);
    
    //Getter da classe Livro
    Livro getLivro();
    
    //Setter da classe NoBMais
    void setArvore(NoBMais arvore);
    
    //Getter da classe NoBMais
    NoBMais getArvore();

    /* Método que insere um livro no arquivo de arvore, e no arquivo de dados
     * Entrada:      classe livro, e classe arvore
     * Retorno:      True se foi inserido, false caso contrario
     * Pre-condicao: Classe instanciada
     * Pos-condicao: Nenhum
    */

    bool inserir(Livro livro,NoBMais arvore);

    /* Métdo que remove um livro do arquivo de arvore e do arquivo de dados
     * Entrada:      classe livro, e classe arvore
     * Retorno:      True se removeu, false caso contrario
     * Pre-condicao: Classe instanciada
     * Pos-condicao: Nenhum
    */
    bool remover(Livro livro,NoBMais arvore);

    /* Método que altera a quantidade de livros
     * Entrada:      sei la, arrumar
     * Retorno:      ?
     * Pre-condicao: ?
     * Pos-condicao: ?
    */
    bool alterar(Livro livro,NoBMais arvore);

};
#endif
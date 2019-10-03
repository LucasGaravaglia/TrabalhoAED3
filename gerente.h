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
    /*
     * Entrada:      
     * Retorno:      
     * Pre-condicao: 
     * Pos-condicao: 
    */
    Gerente();
    /*
     * Entrada:      
     * Retorno:      
     * Pre-condicao: 
     * Pos-condicao: 
    */
    void setLivro(Livro livro);
    /*
     * Entrada:      
     * Retorno:      
     * Pre-condicao: 
     * Pos-condicao: 
    */
    Livro getLivro();
    /*
     * Entrada:      
     * Retorno:      
     * Pre-condicao: 
     * Pos-condicao: 
    */
    void setArvore(NoBMais arvore);
    /*
     * Entrada:      
     * Retorno:      
     * Pre-condicao: 
     * Pos-condicao: 
    */
    NoBMais getArvore();
    /*
     * Entrada:      
     * Retorno:      
     * Pre-condicao: 
     * Pos-condicao: 
    */
    bool inserir(Livro livro,NoBMais arvore);
    /*
     * Entrada:      
     * Retorno:      
     * Pre-condicao: 
     * Pos-condicao: 
    */
    bool remover(Livro livro,NoBMais arvore);
    /*
     * Entrada:      
     * Retorno:      
     * Pre-condicao: 
     * Pos-condicao: 
    */
    bool alterar(Livro livro,NoBMais arvore);

};
#endif
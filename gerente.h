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
    Gerente();
    void setLivro(Livro livro);
    Livro getLivro();
    void setArvore(NoBMais arvore);
    NoBMais getArvore();
    bool inserir(Livro livro,NoBMais arvore);
    bool remover(Livro livro,NoBMais arvore);
    bool alterar(Livro livro,NoBMais arvore);





};
#endif
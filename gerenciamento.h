#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H
#include "arvore.h"
#include "livro.h"

class Gerente{
private:
    Livro livro;
    BMais arvore;
public:
    
    //Contrutor da classe gerente
    Gerente();
    
    //Setter da classe Livro
    void setLivro(Livro livro);
    
    //Getter da classe Livro
    Livro getLivro();
    
    //Setter da classe NoBMais
    void setArvore(BMais arvore);
    
    //Getter da classe NoBMais
    BMais getArvore();

    /* Método que insere um livro no arquivo de arvore, e no arquivo de dados
     * Entrada:      Struct de dados
     * Retorno:      True caso inseriu, false caso contrario
     * Pre-condicao: Struct de dados valida
     * Pos-condicao: Nenhum
    */
    bool inserirLivro(InfoLivro livro);

    /* Métdo que remove um livro do arquivo de arvore e do arquivo de dados
     * Entrada:      Chave que sera removida
     * Retorno:      true caso removeu, false caso contrario
     * Pre-condicao: Struct de dados valida
     * Pos-condicao: Nenhum
    */
    bool removerLivro(Chave chave);

    /* Método que altera a quantidade de livros
     * Entrada:      Codigo do livro que deseja alterar, Nova quantidade de livros
     * Retorno:      true caso alterou, false caso contrario
     * Pre-condicao: Nenhum
     * Pos-condicao: Nenhum
    */
    bool alterarQuantidadeLivros(int chave, int novaQuantidade);

    /* Método que imprime o acervo de livros, ordenado em ordem crescente pro chave
     * Entrada:      Nenuma
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: O acervo é impresso
    */
    void imprimirAcervo();

    //Destrutor da classe Gerente
    ~Gerente();

};
#endif
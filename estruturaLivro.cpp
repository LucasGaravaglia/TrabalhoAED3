#include "estruturaLivro.h"

//Construtor padrão da classe Livro
Livro::Livro(){
    this->livro.codigo     =    0;
    this->livro.quantidade =    0;
    this->cab.topo         =    0;
    this->cab.posLivre     =   -1;
    strcpy(this->livro.titulo,"");
    strcpy(this->livro.autor,"") ;
}

//Construtor completo da classe Livro
Livro::Livro(int quantidade, int codigo, char* titulo, char* autor){
    this->livro.codigo     =     codigo;
    this->livro.quantidade = quantidade;
    this->cab.topo         =          0;
    this->cab.posLivre     =         -1;
    strcpy(this->livro.titulo,titulo)  ;
    strcpy(this->livro.autor,autor)    ;
}

//Construtor que recebe o livro
Livro::Livro(InfoLivro livro){
    this->livro = livro;
}

/* Setter do livro
 * Entrada:      Quantidade, Código, título e autor do livro
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O livro é setado com as informações passadas
*/
void Livro::setLivro(int quantidade, int codigo, char* titulo, char *autor){
    this->livro.codigo     =     codigo;
    this->livro.quantidade = quantidade;
    strcpy(this->livro.titulo,titulo)  ;
    strcpy(this->livro.autor,autor)    ;
}

 /* Getter do livro
 * Entrada:      Nenhuma
 * Retorno:      Struct contendo as informações do livro
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
InfoLivro Livro::getLivro(){
    return this->livro;
}

/* Setter do cabeçalho do arquivo de livros
 * Entrada:      Topo e posição livre
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O cabeçalho do livro é setado com as informações passadas
*/
void Livro::setCab(int topo, int posLivre){
    this->cab.topo     =     topo;
    this->cab.posLivre = posLivre;
}

/* Getter do cabeçalho do livro
 * Entrada:      Nenhuma
 * Retorno:      Struct contendo as informações do cabeçalho do livro
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
CabecalhoLivro Livro::getCab(){
    return this->cab;
}

/* Método que monta a string representando o livro
 * Entrada:      Nenhuma
 * Retorno:      String contendo o livro
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
string Livro::toString(){
    return 
    to_string(this->livro.quantidade)   + ";"
    + this->livro.titulo                + ";"
    + this->livro.autor                 + ";"
    + to_string(this->livro.codigo);
}

/* Método que permite alterar o número de exemplares de um livro
 * Entrada:      Quantidade de livros
 * Retorno:      Nenhum
 * Pré-condição: O livro do qual se deseja alterar o número de exemplares deve estar carregado
 * Pós-condição: A quantidade de exemplares do livro carregado é alterada
*/
void Livro::atualizarExemplares(int quantidade){
    this->livro.quantidade = quantidade;
}

//Destrutor da classe Livro
Livro::~Livro(){

}
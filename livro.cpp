#include "livro.h"

//Construtor padrão da classe Livro
Livro::Livro(){
    this->livro.codigo     =    0;
    this->livro.quantidade =    0;
    this->cab.topo         =    0;
    this->cab.posLivre     =   -1;
    strcpy(this->livro.titulo,"");
    strcpy(this->livro.autor,"") ;
    this->arquivo.setNomeEntrada("livros.bin");
    this->arquivo.setNomeSaida("livros.bin");
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

/* Setter do livro
 * Entrada:      Livro
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O livro é setado com as informações passadas
*/
void Livro::setLivro(InfoLivro livro){
    this->livro = livro;
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
    "\t" + to_string(this->livro.codigo)   + ";"
    + this->livro.titulo                + ";"
    + this->livro.autor                 + ";"
    + to_string(this->livro.quantidade);
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

/* Método que insere um livro no arquivo de dados
 * Entrada:      Struct de livro
 * Retorno:      posição inserida no arquivo
 * Pre-condicao: Nenhum
 * Pos-condicao: Nenhum
*/
int Livro::insereLivro(InfoLivro livro){
    int posLivro;
    this->cab = this->arquivo.lerCabecalhoLivro();
    if(this->cab.posLivre == -1){
        this->arquivo.escreverLivro(livro,this->cab.topo);
        posLivro = this->cab.topo;
        this->cab.topo++;
        this->arquivo.escreverCabecalhoLivro(this->cab);
    }else{
        InfoLivro temp = this->arquivo.lerLivro(this->cab.posLivre);
        this->arquivo.escreverLivro(livro,this->cab.posLivre);
        posLivro = this->cab.posLivre;
        this->cab.posLivre = temp.quantidade;
        this->arquivo.escreverCabecalhoLivro(this->cab);
    }
    return posLivro;
}

/* Método que remove um livro do arquivo de dados
 * Entrada:      Posição do livro no arquivo
 * Retorno:      Nenhum
 * Pre-condicao: Nenhum
 * Pos-condicao: Nenhum
*/
void Livro::removeLivro(int pos){
    this->cab = this->arquivo.lerCabecalhoLivro();
    this->livro = this->arquivo.lerLivro(pos);
    this->livro.quantidade = this->cab.posLivre; 
    this->arquivo.escreverLivro(this->livro,pos);
    this->cab.posLivre = pos;
    this->arquivo.escreverCabecalhoLivro(this->cab);
}


//Destrutor da classe Livro
Livro::~Livro(){

}
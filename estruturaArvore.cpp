#include "estruturaArvore.h"

//Construtor padrão da classe BMais
BMais::BMais(){
    this->no.numChaves =     0;
    this->no.pai        =     0;
    this->no.ehFolha   = false;
}

/* Setter da variável no
 * Entrada:      No
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A variável nó recebe o valor do parâmetro
*/
void BMais::setNo(NoBMais no){
    this->no = no;
}

/* Getter da variável no
 * Entrada:      Nenhuma
 * Retorno:      Nó
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
NoBMais BMais::getNo(){
    return this->no;
}

/* Setter da variável cab
 * Entrada:      Cabeçalho do arquivo de árvore
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: A variável cabeçalho recebe o valor do parâmetro
*/
void BMais::setCabecaloArvore(CabecalhoArvore cab){
    this->cab = cab;
}

/* Getter da variável cab
 * Entrada:      Nenhuma
 * Retorno:      Cabeçalho do arquivo de árvore
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
CabecalhoArvore BMais::getCabecalhoArvore(){
    return this->cab;
}

//Destrutor da classe BMais
BMais::~BMais(){

}
#include "arquivo.h"

//Construtor da classe Arquivo
Arquivo::Arquivo(string nomeEntrada, string nomeSaida){
    this->nomeEntrada = nomeEntrada;
    this->entrada     = NULL;
    this->nomeSaida   = nomeSaida;
    this->saida       = NULL;
}

//Construtor da classe Arquivo
Arquivo::Arquivo(){
    this->entrada     = NULL;
    this->saida       = NULL;
}

//Setter do nome do arquivo de entrada
void Arquivo::setNomeEntrada(string nomeEntrada){
    this->nomeEntrada = nomeEntrada;
}

//Setter do nome do arquivo de saida
void Arquivo::setNomeSaida(string nomeSaida){
    this->nomeSaida = nomeSaida;
}

//Getter do arquivo de entrada
FILE* Arquivo::getEntrada(){
    return this->entrada;
}

//Getter do nome do arquivo de entrada
string Arquivo::getNomeEntrada(){
    return this->nomeEntrada;
}

//Getter do arquivo de saida
FILE* Arquivo::getSaida(){
    return this->saida;
}

//Getter do nome do arquivo de saida
string Arquivo::getNomeSaida(){
    return this->nomeSaida;
}

/* Método que escreve o cabeçalho no arquivo binário de livros
 * Entrada:      Cabeçalho de livros
 * Retorno:      Nenhum
 * Pré-condição: A variavel nomeSaida deve possuir o nome correto do arquivo de saida
 * Pós-condição: O cabeçalho é escrito no arquivo binário de livros
*/
void Arquivo::escreverCabecalhoLivro(CabecalhoLivro cab){
    this->saida = fopen(this->nomeSaida.c_str(),"r+b");
    if(this->saida != NULL){
        fseek(this->saida,0,SEEK_SET);
        fwrite(&cab,sizeof(CabecalhoLivro),1,this->saida);
        fclose(this->saida);
    }else{
        printf("Erro ao abrir arquivo 2\n");
    }
}

/* Método que lê o cabeçalho no arquivo binário de livros
 * Entrada:      Nenhuma
 * Retorno:      Cabeçalho lido ou -1 no cab.topo caso não consiga ler
 * Pré-condição: A variável nomeEntrada deve possuir o nome correto do arquivo de entrada
 * Pós-condição: O cabeçalho é lido do arquivo binário de livros
*/
CabecalhoLivro Arquivo::lerCabecalhoLivro(){
    this->entrada = fopen(this->nomeEntrada.c_str(),"r+b");
    CabecalhoLivro cab;
    if(this->entrada != NULL){
        fseek(this->entrada,0,SEEK_SET);
        fread(&cab,sizeof(CabecalhoLivro),1,this->entrada);
        fclose(this->entrada);
        return cab;
    }
    cab.posLivre = -1;
    cab.topo     = -1;
    printf("Erro ao abrir arquivo\n");
    return cab;
}

/* Método que escreve o cabeçalho no arquivo binário de árvore
 * Entrada:      Cabeçalho de árvore
 * Retorno:      Nenhum
 * Pré-condição: A variavel nomeSaida deve possuir o nome correto do arquivo de saida
 * Pós-condição: O cabeçalho é escrito no arquivo binário de árvore
*/
void Arquivo::escreverCabecalhoArvore(CabecalhoArvore cab){
    this->saida = fopen(this->nomeSaida.c_str(),"r+b");
    if(saida != NULL){
        fseek(this->saida,0,SEEK_SET);
        fwrite(&cab,sizeof(CabecalhoArvore),1,this->saida);
        fclose(this->saida);
    }else{
        printf("Erro ao abrir arquivo\n");
    }
}

/* Método que lê o cabeçalho no arquivo binário de árvore
 * Entrada:      Nenhuma
 * Retorno:      Cabeçalho lido ou cab.topo -1 caso não consiga ler
 * Pré-condição: A variável nomeEntrada deve possuir o nome correto do arquivo de entrada
 * Pós-condição: O cabeçalho é lido do arquivo binário de árvore
*/
CabecalhoArvore Arquivo::lerCabecalhoArvore(){
    this->entrada = fopen(this->nomeEntrada.c_str(),"r+b");
    CabecalhoArvore cab;
    if(this->entrada != NULL){
        fseek(this->entrada,0,SEEK_SET);
        fread(&cab,sizeof(CabecalhoArvore),1,this->entrada);
        fclose(this->entrada);
        return cab;
    }
    cab.topo      = -1;
    cab.posLivre  = -1;
    cab.raiz      = -1;
    printf("Erro ao abrir arquivo\n");
    return cab;
}

/* Método que escreve o arquivo binário vazio de livros
 * Entrada:      Nenhuma
 * Retorno:      Nenhum
 * Pré-condição: A variável nomeSaida deve possuir o nome correto do arquivo de saida
 * Pós-condição: O arquivo binário vazio de livros é escrito
*/
void Arquivo::escreverArquivoLivrosVazio(){
    this->saida = fopen(this->nomeSaida.c_str(),"w+b");
    if(this->saida != NULL){
        CabecalhoLivro cab;
        cab.posLivre = -1;
        cab.topo     =  0;
        fseek(this->saida,0,SEEK_SET);
        fwrite(&cab,sizeof(CabecalhoLivro),1,this->saida);
        fclose(this->saida);
    }else{
        printf("Erro ao abrir arquivo\n");
    }
}

/* Método que escreve o arquivo binário vazio de árvore
 * Entrada:      Nenhuma
 * Retorno:      Nenhum
 * Pré-condição: A variável nomeSaida deve possuir o nome correto do arquivo de saida
 * Pós-condição: O arquivo binário vazio de árvore é escrito
*/
void Arquivo::escreverArquivoArvoreVazio(){
    this->saida = fopen(this->nomeSaida.c_str(),"w+b");
    if(this->saida != NULL){
        CabecalhoArvore cab;
        cab.posLivre = -1;
        cab.topo     =  0;
        cab.raiz     = -1;
        fseek(this->saida,0,SEEK_SET);
        fwrite(&cab,sizeof(CabecalhoArvore),1,this->saida);
        fclose(this->saida);
    }else{
        printf("Erro ao abrir arquivo\n");
    }
}

/* Método que escreve um livro na posição indicada no arquivo binário de livros
 * Entrada:      Livro a ser escrito e posição em que será escrita
 * Retorno:      Nenhum
 * Pré-condição: A variável nomeSaida deve possuir o nome correto do arquivo de saída
 * Pós-condição: O livro é escrito no arquivo binário de livros
*/
void Arquivo::escreverLivro(InfoLivro livro, int pos){
    this->saida = fopen(this->nomeSaida.c_str(),"r+b");
    if(this->saida != NULL){
        fseek(this->saida,sizeof(CabecalhoLivro) + (pos * sizeof(InfoLivro)),SEEK_SET);
        fwrite(&livro,sizeof(InfoLivro),1,this->saida);
        fclose(this->saida);
    }else{
        printf("Erro ao abrir arquivo\n");
    }
}

/* Método que lê um livro do arquivo binário de livros
 * Entrada:      Posição da qual será lida o livro no arquivo
 * Retorno:      Livro lido ou livro.quantidade -1 caso não consiga ler
 * Pré-condição: A variável nomeEntrada deve possuir o nome correto do arquivo de entrada
 * Pós-condição: O livro na posição fornecida é lido e retornado
*/
InfoLivro Arquivo::lerLivro(int pos){
    this->entrada = fopen(this->nomeEntrada.c_str(),"r+b");
        InfoLivro livro;
    if(this->entrada != NULL){
        fseek(this->entrada,sizeof(CabecalhoLivro) + (pos * sizeof(InfoLivro)),SEEK_SET);
        fread(&livro,sizeof(InfoLivro),1,this->entrada);
        fclose(this->entrada);
        return livro;
    }
    livro.quantidade = -1;
    printf("Erro ao abrir arquivo\n");
    return livro;
}

/* Método que escreve um nó na posição indicada no arquivo binário de árvore
 * Entrada:      Nó a ser escrito e posição em que será escrito
 * Retorno:      Nenhum
 * Pré-condição: A variável nomeSaida deve possuir o nome correto do arquivo de saída
 * Pós-condição: O nó é escrito no arquivo binário de árvore
*/
void Arquivo::escreverNo(NoBMais no, int pos){
    this->saida = fopen(this->nomeSaida.c_str(),"r+b");
    if(this->saida != NULL){
        fseek(this->saida,sizeof(CabecalhoArvore) + (pos * sizeof(NoBMais)),SEEK_SET);
        fwrite(&no,sizeof(NoBMais),1,this->saida);
        fclose(this->saida);
    }else{
        printf("Erro ao abrir arquivo\n");
    }
}

/* Método que lê um nó do arquivo binário de árvore
 * Entrada:      Posição da qual será lida o nó no arquivo
 * Retorno:      Nó lido ou no.numChaves -1 caso não consiga ler
 * Pré-condição: A variável nomeEntrada deve possuir o nome correto do arquivo de entrada
 * Pós-condição: O nó na posição fornecida é lido e retornado
*/
NoBMais Arquivo::lerNo(int pos){
    this->entrada = fopen(this->nomeEntrada.c_str(),"r+b");
    NoBMais no;
    if(this->entrada != NULL){
        fseek(this->entrada,sizeof(CabecalhoArvore) + (pos * sizeof(NoBMais)),SEEK_SET);
        fread(&no,sizeof(NoBMais),1,this->entrada);
        fclose(this->entrada);
        return no;
    }
    no.numChaves = -1;
    printf("Erro ao abrir arquivo\n");
    return no;
}

//Destrutor da class Arquivo
Arquivo::~Arquivo(){

}
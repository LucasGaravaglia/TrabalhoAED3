#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include "gerenciamento.h"
#include "estruturaLivro.h"
#include "interacao.h"
#include <fstream>

using namespace std;


//Contrutor da classe Interacao
Interacao::Interacao(){
    this->gerente = Gerente();
}

//Setter da variavel gerente
void Interacao::setGerente(Gerente gerente){
    this->gerente = gerente;
}

//Getter da variavel gerente
Gerente Interacao::getGerente(){
    return this->gerente;
}

/* Método que recebe uma string e remove os espaços excedentes
 * Entrada:      String a ser alterada
 * Retorno:      Nenhum
 * Pre-condicao: String não null
 * Pos-condicao: Nenhum
*/

string Interacao::removeSpaces(string &str){
    int i;
    int j = 0;
    int size = str.length();
    string newStr;
    bool spaceFlag = false;
    if(str[0] == ' ')
        i = 1;
    else
        i = 0;
    for(;i < size; i++){
        if(str[i] != ' ') {
            newStr += str[i];
        }else if(str[i] == ' ' && (i+1) != size && str[i+1] == ';'){
            continue;
        }else if(str[i] == ' ' && (i+1) != size && str[i+1] != ' '){
                newStr += str[i];
        }else{
            i++;
        }
    }
    str = newStr;
    return str;
}

/* Método que cria uma struct de dados a partir de uma linha lida no arquivo
 * Entrada:      Uma linha do arquivo
 * Retorno:      Struct montada
 * Pre-condicao: Linha não nulla
 * Pos-condicao: Nenhum
*/
InfoLivro Interacao::criaLivro(string linha){
    InfoLivro novoLivro;
    string aux;
    int valor=0,i=0,j;
    while(linha[i] != ';'){
        if(linha[i] >= 48 && linha[i] <= 48+9)
            valor = (valor * 10) + (linha[i++]-48);
        else i++;
    }
    j = i+1;
    novoLivro.codigo = valor;
    aux = "";
    while(linha[j] != ';')
        aux+=linha[j++];
    aux = this->removeSpaces(aux);
    strcpy(novoLivro.titulo,aux.c_str());
    aux = "";
    j++;
    while(linha[j] != ';')
        aux+=linha[j++];
    aux = this->removeSpaces(aux);
    strcpy(novoLivro.autor,aux.c_str());
    i=0;
    valor = 0;
    while(linha[j]){
       if(linha[j] >= 48 && linha[j] <= 48+9)
            valor = (valor * 10) + (linha[j++]-48);
        else j++;
    }
    novoLivro.quantidade = valor;
    return novoLivro;
}

/* Carrega o arquivo inicial
 * Entrada:      Nenhum
 * Retorno:      Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void Interacao::carregaArquivoInicial(){
    Arquivo aux = Arquivo("arvore.bin","arvore.bin");
    aux.escreverArquivoArvoreVazio();
    Arquivo aux2 = Arquivo("livros.bin","livros.bin");
    aux2.escreverArquivoLivrosVazio();
    string NomeArquivo;
    ifstream arquivo;
    InfoLivro novoLivro;
    string linha;
    cout << "Digite o nome do arquivo de entrada: ";
    getline(cin,NomeArquivo);
    arquivo.open(NomeArquivo);
    if(arquivo.is_open()){
        getline(arquivo,linha);
        while(!arquivo.eof()){
            linha = this->removeSpaces(linha);//Tira espaços em branco excedentes da linha
            novoLivro = this->criaLivro(linha);
            if(!this->gerente.inserirLivro(novoLivro))
                cout << "Erro ao inserir o arquivo de entrada" << endl;
            getline(arquivo,linha);
        }
    arquivo.close();
    }else{
        cout << "Erro ao abrir o arquivo" << endl;
    } 
}

/* Faz a interação com o usuario para inserir um livro
 * Entrada:      Nenhum
 * Retorno:      Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void Interacao::insereLivro(){
    InfoLivro novolivro;
    string temp;
    cout << endl <<"Digite o codigo do livro: ";
    cin >> novolivro.codigo;
    cout << endl << "Digite a quantidade de livros: ";
    cin >> novolivro.quantidade;
    cin.ignore();
    cout << endl << "Titulo do livro: ";
    getline(cin, temp);
    strcpy(novolivro.titulo,temp.c_str());
    cout << endl << "Autor do livro: ";
    getline(cin, temp);
    strcpy(novolivro.autor,temp.c_str());
    if(this->gerente.inserirLivro(novolivro)){
        cout << endl << "Livro inserido com sucesso." << endl;
    }else{
        cout << "Erro ao inserir o livro." << endl;
    }
}

/* Faz a interação com o usuario para remover um livro
 * Entrada:      Nenhum
 * Retorno:      Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void Interacao::removeLivro(){
    Chave chave;
    cout << "Digite o codigo do livro: ";
    cin >> chave.info;
    if(this->gerente.removerLivro(chave)){
        cout << endl << "Livro removido com sucesso." << endl;
    }else{
        cout << endl << "Erro ao remover o livro." << endl;
    }
}

/* Faz interação com o usuario para atualizar os exemplares
 * Entrada:      Nenhum
 * Retorno:      Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void Interacao::atualizaExemplares(){
    int chave;
    int quantidadeExemplares;
    cout << "Digite o codigo do livro: ";
    cin >> chave;
    cout << "Digite a nova quantidade de exemplares: ";
    cin >> quantidadeExemplares;
    if(this->gerente.alterarQuantidadeLivros(chave,quantidadeExemplares)){
        cout << endl << "Livro alterado com sucesso." << endl;
    }else{
        cout << endl << "Erro ao alterar livro." << endl;
    }
}

void Interacao::BuscarDadosLivro(){
    Chave chave;
    InfoLivro info;
    NoBMais temp;
    cout << "Qual livro voce deseja vizualizar?"<< endl <<"Codigo: ";
    cin >>chave.info;
    temp = this->gerente.getArvore().buscarChave(chave,&chave.posLivro);
    if(temp.numChaves != -1){
        chave.posLivro = temp.chave[chave.posLivro].posLivro;
        info = this->gerente.getLivro().arquivo.lerLivro(chave.posLivro);
        cout << "Codigo: " << info.codigo << endl;
        cout << "Título: " << info.titulo << endl;
        cout << "Autor:  " << info.autor << endl;
        cout << "Quantidade de exemplares: " << info.quantidade << endl;
    }else{
        cout << "Livro nao encontrado";
    }
}

//Destrutor da classe interacao
Interacao::~Interacao(){

}
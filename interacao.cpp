#include <stdio.h>
#include <iostream>
#include <string.h>
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
void Interacao::removeSpaces(char *s){
	char *temp = NULL;
	char novo[200];
    novo[0] = '\0';
	temp = strtok(s," ");
	while(temp != NULL){
		strcat(novo,temp);
		temp = strtok(NULL," ");
		if(temp != NULL) strcat(novo," ");
	}
	strcpy(s,novo);
}

/* Método que cria uma struct de dados a partir de uma linha lida no arquivo
 * Entrada:      Uma linha do arquivo
 * Retorno:      Struct montada
 * Pre-condicao: Linha não nulla
 * Pos-condicao: Nenhum
*/
InfoLivro Interacao::criaLivro(char *linha){
    InfoLivro novoLivro;
    char *temp;
    int valor=0,i=0;
    temp = strtok(linha,";");
    while(temp[i]){
        valor = (valor * 10) + (temp[i++]-48);
    }
    novoLivro.codigo = valor;
    

}

// /* Carrega o arquivo inicial
//  * Entrada:      Nenhum
//  * Retorno:      Nenhum
//  * Pré-condição: Nenhum
//  * Pós-condição: Nenhum
// */
// void Interacao::loadStartFile(){
//     string NomeArquivo;
//     ifstream arquivo;
//     InfoLivro novoLivro;
//     char linha[200];
//     cout << "Digite o nome do arquivo de entrada: ";
//     cin.ignore();
//     getline(cin,NomeArquivo);
//     arquivo.open(NomeArquivo);
//     if(arquivo.is_open()){
//         while(getline(arquivo,linha)){
//             linha = removeSpaces(linha);//Tira espaços em branco excedentes da linha
//             novoLivro = this->criaLivro(linha);
//             if(!this->gerente.inserirLivro(novoLivro))
//                 cout << "Erro ao inserir o arquivo de entrada" << endl;
//         }
//     }else{
//         cout << "Erro ao abrir o arquivo" << endl;
//     } 
// }

/* Faz a interação com o usuario para inserir um livro
 * Entrada:      Nenhum
 * Retorno:      Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: Nenhum
*/
void Interacao::insereLivro(){
    InfoLivro novolivro;
    string temp;
    cout << "Digite o codigo do livro: ";
    cin >> novolivro.codigo;
    cout << endl << "Digite a quantidade de livros: ";
    cin >> novolivro.quantidade;
    cout << endl << "Titulo do livro: ";
    cin.ignore('\n');
    getline(cin, temp);
    strcpy(novolivro.titulo,temp.c_str());
    cout << endl << "Autor do livro: ";
    cin.ignore('\n');
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

//Destrutor da classe interacao
Interacao::~Interacao(){

}
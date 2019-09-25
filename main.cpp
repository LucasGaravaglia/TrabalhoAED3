#include <iostream>
#include "estruturaLivro.h"
#include "arquivo.h"

using namespace std;

Arquivo* livros;
Arquivo* arvore;

void iniciarArquivos(){
    livros = new Arquivo("livros.bin","livros.bin");
    arvore = new Arquivo("arvore.bin","arvore.bin");

    livros->criarArquivoLivrosVazio(); //Deve ser executado antes de qualquer outra coisa
    arvore->criarArquivoArvoreVazio(); //Deve ser executado antes de qualquer outra coisa
    cout << "\n\n";
    
}

int main(){
    iniciarArquivos();
    delete livros; delete arvore;
    return 0;
}
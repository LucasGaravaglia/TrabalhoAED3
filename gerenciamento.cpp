#include "gerenciamento.h"
#include "arquivo.h"
#include "arvore.h"
#include "livro.h"

//Contrutor da classe gerente
Gerente::Gerente(){
    this->livro = Livro();
    this->arvore = BMais();
}

//Setter da classe Livro
void Gerente::setLivro(Livro livro){
    this->livro = livro;
}

//Getter da classe Livro
Livro Gerente::getLivro(){
    return this->livro;
}

//Setter da classe NoBMais
void Gerente::setArvore(BMais arvore){
    this->arvore = arvore;
}

//Getter da classe NoBMais
BMais Gerente::getArvore(){
    return arvore;
}

/* Método que insere um livro no arquivo de arvore, e no arquivo de dados
 * Entrada:      Struct de dados
 * Retorno:      True caso inseriu, false caso contrario
 * Pre-condicao: Struct de dados valida
 * Pos-condicao: Nenhum
*/
bool Gerente::inserirLivro(InfoLivro livro){
    int posLivro;
    Chave infoNo;
    infoNo.info = livro.codigo;
    int flag = this->arvore.buscarChave(infoNo);
    if(flag == -1){
        posLivro = this->livro.insereLivro(livro);
        infoNo.posLivro = posLivro;
        this->arvore.inserir(infoNo);
        return true;
    }else 
        return false;
}

/* Métdo que remove um livro do arquivo de arvore e do arquivo de dados
 * Entrada:      Chave que sera removida
 * Retorno:      true caso removeu, false caso contrario
 * Pre-condicao: Struct de dados valida
 * Pos-condicao: Nenhum
*/
bool Gerente::removerLivro(Chave chave){
    int pos = this->arvore.buscarChave(chave);
    if(pos != -1){
        this->livro.removeLivro(pos);
        this->arvore.remover(chave);
        return true;
    }else{
        return false;
    }
}
/* Método que altera a quantidade de livros
 * Entrada:      Codigo do livro que deseja alterar,  
 * Retorno:      true caso tenha alterado o livro, false caso contrario
 * Pre-condicao: Nenhum
 * Pos-condicao: Nenhum
*/
bool Gerente::alterarQuantidadeLivros(int codigo,int novaQuantidade){
    Chave chave;
    chave.info = codigo;
    InfoLivro livro;
    int pos = this->arvore.buscarChave(chave);
    if(pos != -1){
        livro = this->livro.arquivo.lerLivro(pos);
        livro.quantidade = novaQuantidade;
        this->livro.arquivo.escreverLivro(livro,pos);
        return true;
    }else return false;

}

/* Método que imprime o acervo de livros, ordenado em ordem crescente pro chave
 * Entrada:      Nenuma
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: O acervo é impresso
*/
void Gerente::imprimirAcervo(){
    cout <<endl<<endl;
    BMais aux;
    Livro l;
    int i;
    aux.mudarNo(this->arvore.pegarPrimeiraFolha());
    for(i=0;i<aux.getNo().numChaves;i++){
        l.setLivro(this->livro.arquivo.lerLivro(aux.getNo().chave[i].posLivro));
        cout << l.toString() << endl;
    }
    do{
        aux.mudarNo(aux.getNo().filhos[ORDEM]);
        for(i=0;i<aux.getNo().numChaves;i++){
            l.setLivro(this->livro.arquivo.lerLivro(aux.getNo().chave[i].posLivro));
            cout << l.toString() << endl;
        }
    }while(aux.getNo().filhos[ORDEM] != -1);
}

//Destrutor da classe Gerente
Gerente::~Gerente(){
    
}
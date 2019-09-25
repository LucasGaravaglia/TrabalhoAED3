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

/* Método que busca a posição em que está ou estaria a chave em um nó
 * Entrada:      Árvore b+, A chave, Ponteiro para a posição em que estaria a chave
 * Retorno:      1 caso a chave esteja presente ou 0 caso contrário
 * Pré-condição: Nó não pode ser NULL
 * Pós-condição: Nenhuma
*/
int BMais::buscaPos(int chave, int *pos){
    for((*pos) = 0; (*pos) < this->no.numChaves; (*pos)++){
        if(chave == this->no.chave[(*pos)])
            return 1;
        else if(chave < this->no.chave[(*pos)])
            break;
    }
    return 0;
}

/* Método que faz o split de um nó interno(Não folha)
 * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
 * Retorno:      Nó criado pelo split
 * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
 * Pós-condição: O nó sofre split e promove a chave mediana
*/
NoBMais* BMais::splitB(int *chavePromovida){
    NoBMais* novoNo    = new NoBMais;
    int metadeChaves   = this->no.numChaves/2,i;
    novoNo->numChaves  = this->no.numChaves - metadeChaves - 1;
    this->no.numChaves = metadeChaves;
    *chavePromovida    = this->no.chave[metadeChaves];
    novoNo->filhos[0]  = this->no.filhos[metadeChaves + 1];
    for(i=0;i < novoNo->numChaves;i++){
        novoNo->chave[i]    = this->no.chave[metadeChaves + 1 + i];
        novoNo->filhos[i+1] = this->no.filhos[metadeChaves + 2 + i];
    }
    return novoNo;
}

/* Método que faz o split de um nó interno(Não folha)
 * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
 * Retorno:      Nó criado pelo split
 * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
 * Pós-condição: O nó sofre split e promove a chave mediana
*/
NoBMais* BMais::splitBMais(int *chavePromovida, int **ponteiroNovoNo){
    NoBMais* novoNo          = new NoBMais;
    int metadeChaves         = this->no.numChaves/2,i,x;
    x                        = this->no.filhos[ORDEM];
    novoNo->numChaves        = this->no.numChaves - metadeChaves - 1;
    this->no.numChaves       = metadeChaves;
    (*ponteiroNovoNo)        = &(this->no.filhos[ORDEM]);
    *chavePromovida          = this->no.chave[metadeChaves];
    novoNo->filhos[0]        = this->no.filhos[metadeChaves + 1];
    for(i=0;i < novoNo->numChaves;i++){
        novoNo->chave[i]    = this->no.chave[metadeChaves + 1 + i];
        novoNo->filhos[i+1] = this->no.filhos[metadeChaves + 2 + i];
    }
    novoNo->filhos[ORDEM]   = x;
    return novoNo;
}

/* Método que adiciona uma chave à direita de pos
 * Entrada:      Nó, posição, chave e filho da direita
 * Retorno:      Nenhum
 * Pré-condição: Nó não pode ser NULL
 * Pós-condição: A chave é adiciona à direita de pos
*/
void BMais::adicionaDireita(int pos, int chave, int subarvore){
    int i;
    for(i=this->no.numChaves;i>pos;i--){
        this->no.chave[i]         = this->no.chave[i-1];
        this->no.filhos[i+1]      = this->no.filhos[i];
    }
    this->no.chave[pos]    = chave;
    this->no.filhos[pos+1] = subarvore;
    this->no.numChaves++;
}

/* Método auxiliar para inserir uma chave
 * Entrada:      Arvore b+ e chave a ser inserida
 * Retorno:      Nenhum
 * Pré-condição: A árvore não pode ser NULL
 * Pós-condição: A chave é inserida na árvore
*/
void BMais::insereAux(int chave){
    int pos;
    if(!this->buscaPos(chave,&pos)){ //Chave não está no nó atual
        if(this->no.ehFolha){
            adicionaDireita(pos,chave,NULL);
        }else{
            NoBMais novoNo;
            //Ler o novo nó do arquivo: no.filhos[pos]
            this->setNo(novoNo);
            this->insereAux(chave);
        }
    }
}

//Destrutor da classe BMais
BMais::~BMais(){

}
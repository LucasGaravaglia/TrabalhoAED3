#include "estruturaArvore.h"
#include "arquivo.h"

//construtor da classe
BMais::BMais(){
    this->no.numChaves = 0;
    this->no.pai       = 0;
    this->no.ehFolha   = true;
    this->cab.posLivre = -1;
    this->cab.topo     = -1;
    this->cab.raiz     = 0;
    this->pos          = 0;
    this->WHFile = new Arquivo("arvore.bin","arvore.bin");
}

//contrutor da classe
BMais::BMais(NoBMais no, CabecalhoArvore cab){
    this->no = no;
    this->cab = cab;
}

//setter da variavel no
void BMais::setNo(NoBMais no){
    this->no = no;
}

//setter da variavel cab
void BMais::setCab(CabecalhoArvore cab){
    this->cab = cab;
}

//get da variavel no
NoBMais BMais::getNo(){
    return this->no;
}

//get da variavel cab
CabecalhoArvore BMais::getCab(){
    return this->cab;
}

//set da variavel pos
void BMais::setPos(int pos){
    this->pos = pos;
}

//get da variavel pos
int BMais::getPos(){
    return this->pos;
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
int BMais::splitB(int *chavePromovida){
    NoBMais novoNo;
    int metadeChaves   = this->no.numChaves/2,i;
    novoNo.numChaves  = this->no.numChaves - metadeChaves - 1;
    this->no.numChaves = metadeChaves;
    *chavePromovida    = this->no.chave[metadeChaves];
    novoNo.filhos[0]  = this->no.filhos[metadeChaves + 1];
    for(i=0;i < novoNo.numChaves;i++){
        novoNo.chave[i]    = this->no.chave[metadeChaves + 1 + i];
        novoNo.filhos[i+1] = this->no.filhos[metadeChaves + 2 + i];
    }
    novoNo.pai = this->no.pai;
    //Escreve o antigo nó novamente
    this->WHFile.escreverNo(this->no,this->pos);
    if(this->cab.posLivre == -1){
        //Escrevo o novo no, alterando o topo do cabecalho
        this->WHFile.escreverNo(novoNo,this->cab.topo);
        this->cab.topo++;
        return (this->cab.topo-1);
    }else{
        //Escrevo o novo no, alterando a posLivre no cabecalho
        NoBMais* tempNo    = new NoBMais;
        this->WHFile.lerNo(this->cab.posLivre);
        int novaposLivre = tempNo->pai;
        int possplit = this->cab.posLivre;
        delete(tempNo);
        this->WHFile.escreverNo(novoNo,this->cab.posLivre);
        this->cab.posLivre = novaposLivre;
        return possplit;
    }
}

/* Método que faz o split de um nó interno(Não folha)
 * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
 * Retorno:      Nó criado pelo split
 * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
 * Pós-condição: O nó sofre split e promove a chave mediana
*/
int BMais::splitBMais(int *chavePromovida){
    NoBMais novoNo;
    int metadeChaves         = this->no.numChaves/2,i,x,posnovono;
    x                        = this->no.filhos[ORDEM];
    novoNo.numChaves        = this->no.numChaves - metadeChaves - 1;
    this->no.numChaves       = metadeChaves;
    //(*ponteiroNovoNo)        = &(this->no.filhos[ORDEM]);
    *chavePromovida          = this->no.chave[metadeChaves];
    novoNo.filhos[0]        = this->no.filhos[metadeChaves + 1];
    for(i=0;i < novoNo.numChaves;i++){
        novoNo.chave[i]    = this->no.chave[metadeChaves + 1 + i];
        novoNo.filhos[i+1] = this->no.filhos[metadeChaves + 2 + i];
    }
    novoNo.pai = this->no.pai;
    novoNo.filhos[ORDEM]   = x;
    if(this->cab.posLivre == -1){
        //Escrevo o novo no, alterando o topo do cabecalho
        this->WHFile.escreverNo(novoNo,this->cab.topo);
        this->no.filhos[ORDEM] = cab.topo;
        this->cab.topo++;
        posnovono = (this->cab.topo-1);
    }else{
        //Escrevo o novo no, alterando a posLivre no cabecalho
        NoBMais* tempNo    = new NoBMais;
        this->WHFile.lerNo(this->cab.posLivre);
        int novaposLivre = tempNo->pai;
        delete(tempNo);
        posnovono = this->cab.posLivre;
        this->WHFile.escreverNo(novoNo,this->cab.posLivre);
        this->no.filhos[ORDEM] = cab.posLivre;
        this->cab.posLivre = novaposLivre;
        delete(tempNo);
    }
    this->WHFile.escreverNo(this->no,this->pos);
    return posnovono;
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
    this->WHFile.escreverNo(this->no,this->pos);
}

/* Método que verifica se tem overflow no nó
 * Entrada:      Nenhuma
 * Retorno:      True se houver overflow false caso contrario
 * Pre-condicao: No não null
 * Pos-condicao: Nenhuma
*/
bool BMais::overflow(){
    if(this->no.numChaves == ORDEM) return true;
    return false;
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
            novoNo = this->WHFile.lerNo(this->no.filhos[pos]);
            this->setPos(this->no.filhos[pos]);
            this->setNo(novoNo);
            this->insereAux(chave);
            if(this->overflow()){
                int m;//valor da chave mediana
                int nosplit = this->splitBMais(&m);
                novoNo = this->WHFile.lerNo(this->no.pai);
                this->setNo(novoNo);
                this->adicionaDireita(pos,m,nosplit);
            }
            this->setPos(this->no.pai);
            novoNo = this->WHFile.lerNo(this->no.pai);
            this->setNo(novoNo);
        }
    }
}

/* Método que insere uma chave na arvore , fazendo split caso necessario
 * Entrada:      chave a ser inserida
 * Retorno:      Nenhum
 * Pre-condicao: Nenhum
 * Pos-condicao: Nenhum
*/
void BMais::insere(int chave){
    this->cab = this->WHFile.lerCabecalhoArvore();
    if(this->cab.topo == -1){
        this->cab.topo == 1;
        this->no.chave[0] = chave;
        this->no.filhos[0] = NULL;
        this->no.numChaves = 1;
    }else{
        this->WHFile.lerNo(this->cab.raiz);
        this->setPos(this->cab.raiz);
        this->insereAux(chave);
        if(this->overflow()){
            int m;
            int noSplit = this->splitBMais(&m);
            NoBMais novaRaiz;
            novaRaiz.chave[0] = m;
            novaRaiz.filhos[0] = this->pos;
            novaRaiz.filhos[1] = noSplit;
            novaRaiz.numChaves = 1;
            if(this->cab.posLivre == -1){
                this->WHFile.escreverNo(novaRaiz,this->cab.topo);
                this->no.pai = this->cab.topo;
                this->cab.topo++;
            }else{
                NoBMais *temp = new NoBMais;
                temp = this->WHFile.lerNo(this->cab.posLivre);
                this->WHFile.escreverNo(novaRaiz,this->cab.posLivre);
                this->no.pai = this->cab.posLivre;
                this->cab.raiz = this->cab.posLivre;
                this->cab.posLivre = temp->pai;
            }
        }
        this->WHFile.escreverNo(this->no,this->pos);
        this->WHFile.escreverCabecalhoArvore(this->cab);
    }
}

//destrutor da classe
BMais::~BMais(){

}
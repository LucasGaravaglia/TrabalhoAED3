#include "arvore.h"
#include "arquivo.h"
#include "estruturaArvore.h"

//construtor da classe
BMais::BMais(){
    this->no.numChaves     = 0;
    this->no.pai           = 0;
    this->no.ehFolha       = true;
    this->cab.posLivre     = -1;
    this->cab.topo         = 0;
    this->cab.raiz         =-1;
    this->no.filhos[ORDEM] = 0;
    this->pos              = 0;
    this->WHFile.setNomeEntrada("arvore.bin");
    this->WHFile.setNomeSaida("arvore.bin");

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
    for(i=metadeChaves;i < ORDEM;i++){
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
        NoBMais tempNo;
        tempNo = this->WHFile.lerNo(this->cab.posLivre);
        int novaposLivre = tempNo.pai;
        int possplit = this->cab.posLivre;
        this->WHFile.escreverNo(novoNo,this->cab.posLivre);
        this->cab.posLivre = novaposLivre;
        return possplit;
    }
}

/* Método que faz o split de um nó interno(Folha)
 * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
 * Retorno:      Nó criado pelo split
 * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
 * Pós-condição: O nó sofre split e promove a chave mediana
*/
int BMais::splitBMais(int *chavePromovida){
     NoBMais novoNo;
    int metadeChaves         = this->no.numChaves/2,i,x,posnovono;
    x                        = this->no.filhos[ORDEM];
    novoNo.numChaves         = this->no.numChaves - metadeChaves - 1;
    this->no.numChaves       = metadeChaves;
    *chavePromovida          = this->no.chave[metadeChaves];
    for(i=metadeChaves;i < ORDEM;i++){//alterado, revisar
        novoNo.chave[i+1]    = this->no.chave[metadeChaves + 1 + i];
    }
    novoNo.chave[0]    = this->no.chave[metadeChaves];
    novoNo.numChaves++;
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
        NoBMais tempNo;
        tempNo = this->WHFile.lerNo(this->cab.posLivre);
        int novaposLivre = tempNo.pai;
        posnovono = this->cab.posLivre;
        this->WHFile.escreverNo(novoNo,this->cab.posLivre);
        this->no.filhos[ORDEM] = cab.posLivre;
        this->cab.posLivre = novaposLivre;
    }
    //Escreve o antigo nó novamente
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
    return this->no.numChaves == ORDEM;
}

/* Método auxiliar para inserir uma chave
 * Entrada:      Arvore b+ e chave a ser inserida
 * Retorno:      Nenhum
 * Pré-condição: A árvore não pode ser NULL
 * Pós-condição: A chave é inserida na árvore
*/
void BMais::insereAux(int chave){
    int posChave;
    if(!this->buscaPos(chave,&posChave)){ //Chave não está no nó atual
        if(this->no.ehFolha){
            adicionaDireita(posChave,chave,-1);
        }else{ //Não é folha
            this->mudarNo(this->no.filhos[posChave]);
            this->insereAux(chave);
            if(this->overflow()){
                int m;//valor da chave mediana
                int nosplit;
                if(this->no.ehFolha){
                    nosplit = this->splitBMais(&m);
                }else{
                    nosplit = this->splitB(&m);
                }
                this->mudarNo(this->no.pai); //Volta o pai para o nó atual
                this->adicionaDireita(posChave,m,nosplit);
            }else{
                this->mudarNo(this->no.pai); //Volta o pai para o nó atual
            }
        }
    }else{
        printf("A chave já existe na árvore\n");
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
    int i;
    if(this->cab.topo == 0){ //Não tem raiz
        this->no.pai       = 0;
        this->cab.topo     = 1;
        this->cab.raiz     = 0;
        this->no.chave[0]  = chave;
        for(i=0;i<ORDEM;i++)
            this->no.filhos[i] = -1;
        this->no.numChaves = 1;
        this->setPos(0); //Posição em que foi inserida a raiz
    }else{
        this->mudarNo(this->cab.raiz); //Coloca a raiz no nó atual
        this->insereAux(chave);
        if(this->overflow()){
            int chavePromovida;
            int noSplit;
            if(this->no.ehFolha){
                noSplit = this->splitBMais(&chavePromovida);
            }else{
                noSplit = this->splitB(&chavePromovida);
            }
            NoBMais novaraiz;
            novaraiz.chave[0]  = chavePromovida;
            novaraiz.filhos[0] = this->pos;
            novaraiz.filhos[1] = noSplit;
            novaraiz.numChaves = 1;
            novaraiz.ehFolha   = false;
            if(this->cab.posLivre == -1){ //Inserir no topo
                novaraiz.pai = -1;
                this->WHFile.escreverNo(novaraiz,this->cab.topo); 
                this->cab.raiz = this->cab.topo;
                this->mudarNo(this->cab.topo); //Coloca a nova Raiz no nó atual
                this->cab.topo++;
            }else{ //Inserir no posLivre /* OLHAR DEPOIS */
                NoBMais temp;
                temp = this->WHFile.lerNo(this->cab.posLivre);
                this->WHFile.escreverNo(novaraiz,this->cab.posLivre);
                // this->no.pai = this->cab.posLivre;
                this->cab.raiz = this->cab.posLivre;
                novaraiz.pai = this->cab.raiz; /* INSERIR O NÓ NO ARQUIVO DEPOIS DISSO */
                this->cab.posLivre = temp.pai;
            }
            NoBMais filho;
            for(i=0;i<=this->no.numChaves+1;i++){ //Arrumando os ponteiros dos filhos para os pais
                filho = this->WHFile.lerNo(this->no.filhos[i]);
                filho.pai = this->pos;
                this->WHFile.escreverNo(filho,this->no.filhos[i]);
            }
        }
    }
    this->WHFile.escreverCabecalhoArvore(this->cab);
    this->WHFile.escreverNo(this->no,this->pos);
}

/* Método que imprime um vetor da árvore B+
 * Entrada:      Vetor e tamanho do vetor
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
void BMais::printVetBMais(int *v, int n){
    int i;
    printf("[");
    for(i=0;i<n;i++){
        if(i<n-1)
            printf("%d,",v[i]);
        else
            printf("%d",v[i]);
    }
    printf("]");
}

/* Método que imprime um nivel da árvore b+
 * Entrada:      Nível a ser impresso e nível atual
 * Retorno:      Nenhum
 * Pré-condição: Raiz não nula
 * Pós-condição: O nível é impresso por nível.
*/
void BMais::imprimirPorNivel(int nivel, int atual){
    if(nivel == atual){
        this->printVetBMais(this->no.chave,this->no.numChaves);
    }else{
        int i,posVoltar;
        BMais *aux = this;
        if(atual <= nivel){
            for(i=0;i<aux->no.numChaves+1 && aux->no.filhos[i] != -1;i++){
                aux->mudarNo(aux->no.filhos[i]); //Coloca o nó no próximo filho
                aux->imprimirPorNivel(nivel,atual+1);
                aux->mudarNo(aux->no.pai);
            }
        }
        delete aux;
    }
}

/* Método que calcula a altura da árvore B+
 * Entrada:      Nenhuma
 * Retorno:      Altura da árvore B+
 * Pré-condição: Raiz não nula
 * Pós-condição: A altura da árvore é calculada e retornada
*/
int BMais::altura(){
    int altura=0;
    BMais aux;
    CabecalhoArvore cab = this->WHFile.lerCabecalhoArvore();
    aux.no = this->WHFile.lerNo(cab.raiz);
    for(;aux.no.filhos[0] != -1;altura++){
        aux.no = this->WHFile.lerNo(this->no.filhos[0]);
    }
    return altura + 1;
}

/* Método que imprime todos os níveis da árvore b+
 * Entrada:      Nenhuma
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Todos os níveis da árvore são impressos
*/
void BMais::imprimirTodoOsNiveis(){
    int i,alt,posAtual;
    posAtual            = this->pos;
    CabecalhoArvore cab = this->WHFile.lerCabecalhoArvore();
    this->mudarNo(cab.raiz);
    alt                  = this->altura();
    for(i=0;i<alt;i++){
        this->imprimirPorNivel(i,0);
        printf("\n");
    }
    this->mudarNo(posAtual);
}

/* Método que muda o nó que está carregado na classe
 * Entrada:      Posição do nó que será carregado do arquivo
 * Retorno:      Nenhum
 * Pré-condição: Nenhum
 * Pós-condição: O nó é carregado para a classe
*/
void BMais::mudarNo(int posNo){
    NoBMais aux;
    aux = this->WHFile.lerNo(posNo);
    if(aux.numChaves != -1){ //Sucesso na leitura. Muda o nó que está na classe
        this->setPos(posNo);
        this->no = this->WHFile.lerNo(posNo);
    }else{
        printf("Erro, não foi possível ler a posição no arquivo arvore.bin\n");
    }
}
//
void BMais::DeBug(int pos){
    int i;
    this->mudarNo(pos);
    printf("pos   = %d\npai   = %d: \nfilho = ",pos,this->no.pai);//
    for(i=0;i<=this->no.numChaves;i++)
        printf("%d | ",this->no.filhos[i]);
    printf("\nchave = ");
    for(i=0;i<this->no.numChaves;i++)
        printf(" %d | ",this->no.chave[i]);
    printf("\n\n");    
}

//destrutor da classe
BMais::~BMais(){

}
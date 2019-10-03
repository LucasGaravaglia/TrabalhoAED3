#include "arvore.h"
#include "arquivo.h"
#include "estruturaArvore.h"

//construtor da classe
BMais::BMais(){
    this->no.numChaves     = 0;
    this->no.pai           = -1;
    this->no.ehFolha       = true;
    this->cab.posLivre     = -1;
    this->cab.topo         = 0;
    this->cab.raiz         = -1;
    this->no.filhos[ORDEM] = -1;
    this->pos              = 0;
    this->WRFile.setNomeEntrada("arvore.bin");
    this->WRFile.setNomeSaida("arvore.bin");

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
int BMais::buscarPos(int chave, int *pos){
    for((*pos) = 0; (*pos) < this->no.numChaves; (*pos)++){
        if(chave == this->no.chave[(*pos)].info)
            return 1;
        else if(chave < this->no.chave[(*pos)].info)
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
int BMais::splitB(Chave *chavePromovida){
    NoBMais novoNo;
    int metadeChaves   = this->no.numChaves/2,i,posnovono;
    novoNo.numChaves   = this->no.numChaves - metadeChaves - 1;
    this->no.numChaves = metadeChaves;
    *chavePromovida    = this->no.chave[metadeChaves];
    novoNo.filhos[0]   = this->no.filhos[metadeChaves + 1];
    novoNo.ehFolha = false;
    for(i=0;i < novoNo.numChaves;i++){
        novoNo.chave[i]    = this->no.chave[metadeChaves + 1 + i];
        novoNo.filhos[i+1] = this->no.filhos[metadeChaves + 2 + i];
    }
    novoNo.pai = this->no.pai;
    //Escreve o antigo nó novamente
    this->WRFile.escreverNo(this->no,this->pos);
    if(this->cab.posLivre == -1){
        //Escrevo o novo no, alterando o topo do cabecalho
        this->WRFile.escreverNo(novoNo,this->cab.topo);
        posnovono = (this->cab.topo);
        this->cab.topo++;
    }else{
        //Escrevo o novo no, alterando a posLivre no cabecalho
        NoBMais tempNo;
        tempNo = this->WRFile.lerNo(this->cab.posLivre);
        int novaposLivre = tempNo.pai;
        int possplit = this->cab.posLivre;
        this->WRFile.escreverNo(novoNo,this->cab.posLivre);
        this->cab.posLivre = novaposLivre;
        return possplit;/*  ARRUMAR OS FILHOS DO NOVO NO */
    }
    NoBMais filho;
    for(i=0;i<novoNo.numChaves+1;i++){
        filho = this->WRFile.lerNo(novoNo.filhos[i]);
        filho.pai = posnovono;
        this->WRFile.escreverNo(filho,novoNo.filhos[i]);
    }
    return posnovono;
}

/* Método que faz o split de um nó interno(Folha)
 * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
 * Retorno:      Nó criado pelo split
 * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
 * Pós-condição: O nó sofre split e promove a chave mediana
*/
int BMais::splitBMais(Chave *chavePromovida){
    NoBMais novoNo;
    int metadeChaves         = this->no.numChaves/2,i,x,posnovono;
    for(i=0;i<ORDEM;i++)
        novoNo.filhos[i] = -1;
    x                        = this->no.filhos[ORDEM];
    novoNo.numChaves         = this->no.numChaves - metadeChaves - 1;
    novoNo.ehFolha           = true;
    this->no.numChaves       = metadeChaves;
    *chavePromovida          = this->no.chave[metadeChaves];
    for(i=0;i < novoNo.numChaves;i++){//alterado, revisar
        novoNo.chave[i+1]    = this->no.chave[metadeChaves + 1 + i];
    }
    novoNo.chave[0]    = this->no.chave[metadeChaves];
    novoNo.numChaves++;
    novoNo.filhos[ORDEM]   = x;
    novoNo.pai = this->no.pai;
    if(this->cab.posLivre == -1){
        //Escrevo o novo no, alterando o topo do cabecalho
        this->WRFile.escreverNo(novoNo,this->cab.topo);
        this->no.filhos[ORDEM] = cab.topo;
        posnovono = (this->cab.topo);
        this->cab.topo++;
    }else{
        //Escrevo o novo no, alterando a posLivre no cabecalho
        NoBMais tempNo;
        tempNo = this->WRFile.lerNo(this->cab.posLivre);
        int novaposLivre = tempNo.pai;
        posnovono = this->cab.posLivre;
        this->WRFile.escreverNo(novoNo,this->cab.posLivre);
        this->no.filhos[ORDEM] = cab.posLivre;
        this->cab.posLivre = novaposLivre;
    }
    //Escreve o antigo nó novamente
    this->WRFile.escreverNo(this->no,this->pos);
    return posnovono;
}

/* Método que adiciona uma chave à direita de pos
 * Entrada:      Nó, posição, chave e filho da direita
 * Retorno:      Nenhum
 * Pré-condição: Nó não pode ser NULL
 * Pós-condição: A chave é adiciona à direita de pos
*/
void BMais::adicionarDireita(int pos, Chave chave, int subarvore){
    int i;
    for(i=this->no.numChaves;i>pos;i--){
        this->no.chave[i]         = this->no.chave[i-1];
        this->no.filhos[i+1]      = this->no.filhos[i];
    }
    this->no.chave[pos]    = chave;
    this->no.filhos[pos+1] = subarvore;
    this->no.numChaves++;
    this->WRFile.escreverNo(this->no,this->pos);
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
void BMais::inserirAux(Chave chave){
    int posChave;
    if(!this->buscarPos(chave.info,&posChave)){ //Chave não está no nó atual
        if(this->no.ehFolha){
            adicionarDireita(posChave,chave,-1);
        }else{ //Não é folha
            this->mudarNo(this->no.filhos[posChave]);
            this->inserirAux(chave);
            if(this->overflow()){
                Chave m;//valor da chave mediana
                int nosplit;
                if(this->no.ehFolha){
                    nosplit = this->splitBMais(&m);
                }else{
                    nosplit = this->splitB(&m);
                }
                this->mudarNo(this->no.pai); //Volta o pai para o nó atual
                NoBMais temp = this->WRFile.lerNo(nosplit);
                temp.pai = this->pos;
                this->WRFile.escreverNo(temp,nosplit);
                this->adicionarDireita(posChave,m,nosplit);
                
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
void BMais::inserir(Chave chave){
    this->cab = this->WRFile.lerCabecalhoArvore();
    int i;
    if(this->cab.topo == 0){ //Não tem raiz
        this->cab.topo     = 1;
        this->cab.raiz     = 0;
        this->no.chave[0]  = chave;
        for(i=0;i<ORDEM;i++)
            this->no.filhos[i] = -1;
        this->no.numChaves = 1;
        this->setPos(0); //Posição em que foi inserida a raiz
    }else{
        this->mudarNo(this->cab.raiz); //Coloca a raiz no nó atual
        this->inserirAux(chave);
        if(this->overflow()){
            Chave chavePromovida;
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
                this->WRFile.escreverNo(novaraiz,this->cab.topo); 
                this->cab.raiz = this->cab.topo;
                this->mudarNo(this->cab.topo); //Coloca a nova Raiz no nó atual
                this->cab.topo++;
            }else{ //Inserir no posLivre /* OLHAR DEPOIS */
                NoBMais temp;
                temp = this->WRFile.lerNo(this->cab.posLivre);
                this->WRFile.escreverNo(novaraiz,this->cab.posLivre);
                // this->no.pai = this->cab.posLivre;
                this->cab.raiz = this->cab.posLivre;
                novaraiz.pai = this->cab.raiz; /* INSERIR O NÓ NO ARQUIVO DEPOIS DISSO */
                this->cab.posLivre = temp.pai;
            }
            NoBMais filho;
            for(i=0;i<this->no.numChaves+1;i++){ //Arrumando os ponteiros dos filhos para os pais
                filho = this->WRFile.lerNo(this->no.filhos[i]);
                if(filho.numChaves != -1){
                    filho.pai = this->pos;
                    this->WRFile.escreverNo(filho,this->no.filhos[i]);
                }
            }
        }
    }
    this->WRFile.escreverCabecalhoArvore(this->cab);
    this->WRFile.escreverNo(this->no,this->pos);
}

/* Método que imprime um vetor da árvore B+
 * Entrada:      Vetor e tamanho do vetor
 * Retorno:      Nenhum
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
void BMais::printVetBMais(Chave v[], int n){
    int i;
    printf("[");
    for(i=0;i<n;i++){
        if(i<n-1)
            printf("%d,",v[i].info);
        else
            printf("%d",v[i].info);
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
        BMais aux = *this;
        if(atual <= nivel){
            for(i=0;i<aux.no.numChaves+1 && aux.no.filhos[i] != -1;i++){
                aux.mudarNo(aux.no.filhos[i]); //Coloca o nó no próximo filho
                aux.imprimirPorNivel(nivel,atual+1);
                aux.mudarNo(aux.no.pai);
            }
        }
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
    CabecalhoArvore cab = this->WRFile.lerCabecalhoArvore();
    aux.no = this->WRFile.lerNo(cab.raiz);
    for(;aux.no.filhos[0] != -1;altura++){
        aux.mudarNo(aux.no.filhos[0]);
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
    CabecalhoArvore cab = this->WRFile.lerCabecalhoArvore();
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
    aux = this->WRFile.lerNo(posNo);
    if(aux.numChaves != -1){ //Sucesso na leitura. Muda o nó que está na classe
        this->setPos(posNo);
        this->no = this->WRFile.lerNo(posNo);
    }else{
        printf("Erro, não foi possível ler a posição no arquivo arvore.bin\n");
    }
}

/* Método usado para ler todas as informações de um nó inseridoo no arquivo
 * Entrada:      Posição do nó no arquivo
 * Retorno:      Nenhum
 * Pre-condicao: Nenhum
 * Pos-condicao: Nenhum
*/

void BMais::DeBug(int pos){
    int i;
    this->mudarNo(pos);
    printf("pos   = %d\npai   = %d: \nfilho = ",pos,this->no.pai);//
    for(i=0;i<=this->no.numChaves;i++)
        printf("%d | ",this->no.filhos[i]);
    printf("\nchave = ");
    for(i=0;i<this->no.numChaves;i++)
        printf(" %d | ",this->no.chave[i]);
    if(this->no.ehFolha)
        printf("\nproxima folha = %d",this->no.filhos[ORDEM]);
    printf("\n\n");    
}

/* Método que busca em qual nó FOLHA está uma chave
 * Entrada:      Chave a ser procurada e ponteiro para a chave no vetor
 * Retorno:      Nó em que a chave foi encontrada ou no.numChaves 1 caso não a ache
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
NoBMais BMais::buscarChave(Chave chave, int *pos){
    int i;
    BMais *aux;
    CabecalhoArvore cab;
    NoBMais no;
    cab = this->WRFile.lerCabecalhoArvore();
    aux = new BMais();
    aux->mudarNo(cab.raiz);
    for(i=0;i < aux->no.numChaves && !aux->no.ehFolha;i++){ //Percorrimento da árvore
        if(chave.info < aux->no.chave[i].info) //Vai para a esquerda
            aux->mudarNo(aux->no.filhos[i]);
        else if(i == aux->no.numChaves-1) //Vai para a direita
            aux->mudarNo(aux->no.filhos[i+1]);
    }
    if(no.ehFolha){ //Achou o nó em que deveria estar a chave
        if(aux->buscarPos(chave.info,pos)){ //Achou a posição no vetor em que deveria estar a chave
            if(chave.info == aux->no.chave[*pos].info){ //Achou a chave
                no = aux->no;
                delete aux;
                return no;
            }
        }
    }//Não achou a chave
    printf("Chave não encontrada\n");
    no = aux->no;
    no.numChaves = -1;
    delete aux;
    return no;
}

/* Método que busca em qual nó FOLHA está uma chave
 * Entrada:      Chave a ser procurada, ponteiro para a chave no vetor e para o nó no arquivo
 * Retorno:      Nó em que a chave foi encontrada ou no.numChaves 1 caso não a ache
 * Pré-condição: Nenhuma
 * Pós-condição: Nenhuma
*/
NoBMais BMais::buscarChave(Chave chave, int *posChave, int *posNo){
    int i;
    BMais *aux;
    CabecalhoArvore cab;
    NoBMais no;
    cab = this->WRFile.lerCabecalhoArvore();
    aux = new BMais();
    aux->mudarNo(cab.raiz);
    for(i=0;i < aux->no.numChaves && !aux->no.ehFolha;i++){ //Percorrimento da árvore
        if(chave.info < aux->no.chave[i].info) //Vai para a esquerda
            aux->mudarNo(aux->no.filhos[i]);
        else if(i == aux->no.numChaves-1) //Vai para a direita
            aux->mudarNo(aux->no.filhos[i+1]);
    }
    if(no.ehFolha){ //Achou o nó em que deveria estar a chave
        if(aux->buscarPos(chave.info,posChave)){ //Achou a posição no vetor em que deveria estar a chave
            if(chave.info == aux->no.chave[*posChave].info){ //Achou a chave
                no = aux->no;
                *posNo = aux->pos;
                delete aux;
                return no;
            }
        }
    }//Não achou a chave
    printf("Chave não encontrada\n");
    no = aux->no;
    no.numChaves = -1;
    delete aux;
    return no;
}

//destrutor da classe
BMais::~BMais(){

}
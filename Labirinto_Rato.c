#include<stdio.h>
#include<stdlib.h>// srand
#include<time.h>// tempo
#include<windows.h>
#include<locale.h>

 
int lab[30][30], i, j;
 
typedef struct Nodo_Pilha
 {
 int elemento;
 struct Nodo_Pilha *prox;
 }NODOPTR;
 
void inicializaPilha(NODOPTR **pilha)
{
   *pilha=NULL;
}
NODOPTR *Cria_Nodo( )
{
 NODOPTR *p;
 p = (NODOPTR *) malloc(sizeof(struct Nodo_Pilha));
 if(!p)
 {
 printf("Problemas na Alocacao!!!");
 exit(0);
 }
 return p;
}
void push(int dado, NODOPTR **pilha) {
 NODOPTR *nodo;
 nodo= Cria_Nodo( );
 nodo->elemento = dado;
 nodo->prox = *pilha;
 *pilha = nodo;
}
int pop(NODOPTR **pilha){
 NODOPTR *nodo;
 if(!pilha)
 {
 printf("Nao a saida para este labirinto");
 return -1;
 }
 nodo = *pilha;
 //elem = nodo->elemento;
 *pilha = nodo->prox;
 free(nodo);
}
int stackpop(NODOPTR **N)
{
    int topo;
 
    if (*N == NULL)
    {
        printf("*****************************************\n");
        printf("*Nao a saida para este labirinto*\n");
        printf("*****************************************\n\n\n");
        return -1;
    }
    else
    {
        topo = (*N) -> elemento;
        return topo;
    }
}
void imprime_lista_ecandeada(NODOPTR *N)
{
 NODOPTR *aux;
 if(N == NULL)
 printf("\n A lista esta vazia!!");
 else
 {
 for(aux = N; aux != NULL; aux = aux->prox)
 printf("\n%d", aux->elemento);
 }
}
void paredelab(){
    i=0;
    for(j=0;j!=30;j++)
        lab[i][j]=1;
    i=29;
    for(j=0;j!=30;j++)
        lab[i][j]=1;
    j=0;
    for(i=1;i!=29;i++)
        lab[i][j]=1;
    j=29;
    for(i=1;i!=29;i++)
        lab[i][j]=1;
}
void recheiolab(){
    int numrand;
    srand(time(NULL));
    for(i=1;i!=29;i++)
        for(j=1;j!=29;j++){
        numrand = rand()%3;//33%
    if (numrand==0)
        lab[i][j]=1;
    else
        lab[i][j]=0;
    }
}
int saidalab(){
    int count=0, numrand;
    numrand = rand()%116;
    i=0;
    for(j=1;j!=29;j++){
        if(count==numrand){
            lab[i][j]=0;
            lab[i+1][j]=0;
            }
    count++;
    }
    i=29;
    for(j=1;j!=29;j++){
    if(count==numrand){
        lab[i][j]=0;
        lab[i-1][j]=0;
        }
    count++;
    }
    j=0;
    for(i=1;i!=29;i++){
        if(count==numrand){
            lab[i][j]=0;
            lab[i][j+1]=0;
        }
    count++;
    }
    j=29;
    for(i=1;i!=29;i++){
        if(count==numrand){
            lab[i][j]=0;
            lab[i][j-1]=0;
        }
        count++;
    }
 
}
 
int inicio_rat(){
    int numrand, count=-1, numero;
    numrand = rand()%784;
    for(i=1;i!=29;i++)
        for(j=1;j!=29;j++){
            count++;
            if (count==numrand){
                lab[i][j]=4;
                numero=i*100+j;
                //push(pilha, numero);
                return numero;
            }
        }
}
 
void printar_lab(int *Pespacos_n_visi, int *Pqtd_parede, int *Pqtd_beco){
    *Pespacos_n_visi=0;
    *Pqtd_parede=0;
    *Pqtd_beco=0;
    for(i=0;i!=30;i++){
        for(j=0;j!=30;j++){
        if (j==0)
        printf("\n");
        if (lab[i][j]==0){
            printf("%c",0);
            ++*Pespacos_n_visi;
        }
        else if (lab[i][j]==1){
            printf("%c",219);
            ++*Pqtd_parede;
        }
        else if (lab[i][j]==2){
            printf("%c",176);
            ++*Pqtd_beco;
        }
        else if (lab[i][j]==3){
            printf("%c",0);
            ++*Pespacos_n_visi;
        }
        else if (lab[i][j]==4)
            printf("%c",1);
        else if (lab[i][j]==5){
            printf(".");
        }
    }
}
}
void printa_parabens(){
    printf("*****************************************\n");
    printf("*Parabens para o rato, ele achou a saida!*\n");
    printf("*****************************************\n\n");
}
void main(){
    NODOPTR *pilha;
    int atual,b,saida,resultado_lab,op=1, total_passos, *Pespacos_n_visi, *Pqtd_parede, *Pqtd_beco, espacos_n_visi,
    qtd_parede, qtd_beco ;
    Pespacos_n_visi=&espacos_n_visi;
    Pqtd_parede=&qtd_parede;
    Pqtd_beco=&qtd_beco;
    while (op==1){
        total_passos=0;
        inicializaPilha(&pilha);
        paredelab();
        recheiolab();
        saidalab();
        atual=inicio_rat();
        push(atual, &pilha);
        printf("\n\n                                       MENU\n\n     (1)-Gerar um novo labirinto                         (2)-Sair");
        printf("\n\n DIGITE O NUMERO DA SUA OPCAO :");
        scanf("%d", &op);
        resultado_lab=0;
        system("cls");
        while(resultado_lab==0 && op==1){
        total_passos++;
        i = (atual / 100);
        j = atual%100;
        //0 = vazio, 1 = parede, 2 = beco
        if(lab[i][j+1]==0 && lab[i][j+1]!=2){
            atual=(i*100)+(j+1);
            push(atual, &pilha);
            lab[i][j+1]=4;
            lab[i][j]=5;
            if((j+1)==29){
                resultado_lab=1;
                printa_parabens();
            }
        }
        else if (lab[i+1][j]==0 && lab[i+1][j]!=2){
            atual=((i+1)*100)+(j);
            push(atual, &pilha);
            lab[i+1][j]=4;
            lab[i][j]=5;
            if((i+1)==29){
                resultado_lab=1;
                printa_parabens();
            }
        }
        else if(lab[i][j-1]==0 && lab[i][j-1]!=2){
            atual=(i*100)+(j-1);
            push(atual, &pilha);
            lab[i][j-1]=4;
            lab[i][j]=5;
            if((j-1)==0)
                {
                resultado_lab=1;
                printa_parabens();
            }
        }
        else if(lab[i-1][j]==0 && lab[i-1][j]!=2){
            atual=((i-1)*100)+(j);
            push(atual, &pilha);
            lab[i-1][j]=4;
            lab[i][j]=5;
            if((i-1)==0){
                resultado_lab=1;
                printa_parabens();
            }
        }
        else{
            lab[i][j]=2;
            pop(&pilha);
            atual = stackpop(&pilha);
            if(atual== -1)
                resultado_lab=2;
            i = (atual / 100);
            j = atual%100;
            lab[i][j]=4;
        }
        printar_lab( Pespacos_n_visi, Pqtd_parede, Pqtd_beco);
        printf("\n\n**********************************************\n");
        printf("   Quantidade de paredes:%d\n\n",  qtd_parede);
        printf("   Total de espacos ainda nao visitados :%d\n\n", espacos_n_visi);
        printf("   Quantidade de becos detectados:%d\n\n", qtd_beco);
        printf("   Total de casas andadas :%d", total_passos);
        printf("\n\n**********************************************\n\n\n\n");
        system("pause");
        system("cls");
 
    }
    }
}

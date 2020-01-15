#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 
typedef struct fila{
    char nome[30], telefone[10];
	int  grau;
    struct fila *prox;
} FILA;

typedef struct pos_fila {
    FILA *nodo;
    int pos;
} POS_FILA;

 
FILA* alocanodo()//aloca nodo e como é inserção no fim, sempre o novo->prox será NULL
{
    FILA *novo;
    novo = malloc(sizeof(struct fila));
    novo->prox = NULL;
    return novo;
}
 
void inicializa_fila(FILA **fila)
{
    *fila = NULL;
}
 
void freefila(FILA **fila)
{
    FILA *aux;
    aux = *fila;
    while(aux != NULL)
    {
        *fila = aux->prox;
        free(aux);
        aux = *fila;
    }
    free(*fila);
}

POS_FILA * busca_nome_fila(FILA *fila, char *nome) {
    if (fila == NULL)
        return NULL;

    POS_FILA *pos_fila = malloc(sizeof(POS_FILA));
    int i = 1;

    do {
        if (strcmp(nome, fila->nome) == 0) {
            pos_fila->nodo = fila;
            pos_fila->pos = i;
            return pos_fila;
        }

        fila = fila->prox;
        i++;
    } while (fila != NULL);

    return NULL;
}
 
void insere_fila(FILA **fila)
{
    FILA *novo, *atual, *anterior;
    novo = alocanodo();
    printf("Insira os dados do paciente\nNome:");
	char buff[10];
	fgets(buff, 10, stdin);
    fgets(novo->nome, 30, stdin);
    fflush(stdin);
    printf("\nTelefone:");
    fgets(novo->telefone, 10, stdin);
    fflush(stdin);
    printf("\nGrau de urgencia:");
    scanf("%d",&(novo->grau));
    fflush(stdin);
    novo->prox = NULL;
    atual = *fila;

    if(*fila == NULL)
    {
        *fila = novo;
    }else
    {
        anterior = NULL;
        atual = *fila;
        do {
            // Encontramos uma posicao da lista (atual)
            // onde o grau eh maior ou iagual ao novo!
            if (atual->grau <= novo->grau) {
                break;
            }
            anterior = atual;
            atual = atual->prox;
        } while(atual != NULL);
        
        // Insercao inicio da lista
        if (anterior == NULL) {
            printf("Inserind inicio fila\n");
            novo->prox = atual;
            *fila = novo;
        // Insercao fim da lista
        } else if (atual == NULL) {
            printf("Inserind fim fila\n");
            anterior->prox = novo;
        // Insercao meio da lista
        } else {
            printf("Inserind meio fila\n");
            anterior->prox = novo;
            novo->prox = atual;
        }
    }
 
}
 
void listanomes(FILA *inicio)
{
    int i;
    i=1;
    if( inicio == NULL)
    {
        printf("\nFILA VAZIA!\n");
    }
    else
    {
        while(inicio->prox != NULL)
        {
            printf("%d . ",i);
            i++;
            puts(inicio->nome);
            inicio = inicio->prox;
        }
        printf("%d . ",i);
        puts(inicio->nome);
    }
}
void listadados(FILA *fim)
{
	FILE *pont_arq;
	pont_arq= fopen("Pacientes_Transplante.txt","a");
	if (pont_arq == NULL){
		printf("Erro na abertura do arquivo!");
		return 1;
	}
	fprintf(pont_arq,"\nDADOS\n-Nome:%s\n-Telefone:%s\n-Grau de urgencia:%d\n",fim->nome,fim->telefone,fim->grau);
	fclose(pont_arq);
	
    system("cls");
    printf("\nDADOS\nNome:%s\nTelefone:%s\nGrau de urgencia:%d",fim->nome,fim->telefone,fim->grau);
    
}
 
int tamanho_fila (FILA *inicio)
{
    int i;
    i=1;
    while(inicio->prox != NULL)
    {
        i++;
        inicio = inicio->prox;
    }
    return i;
}
void remove_fila(FILA **inicio, int a)
{
    FILA *aux;
    listadados(*inicio);
    printf("\nTransplante aceito");
    if(a==1){
       aux = (*inicio)->prox;
       free(*inicio);
       *inicio = aux;
	}
}
 
void main()
{
	FILE *pont_arq;
    FILA *iniciotransplante;
    POS_FILA *pos_fila;
    int i=0, menu;
    char linha[20];
    while(i<2)
    {
        i=0;
        inicializa_fila(&iniciotransplante);
        while(i<1)
        {
            printf("\n      -----------------------------------MENU--------------------------------------------\n");
            printf(" 	1- Cadastrar Paciente (Nome, telefone e grau de urgência).                         \n");
            printf("	2- Buscar Paciente(Informa a posicao do paciente na fila e seu grau de urgencia).  \n");
            printf(" 	3- Proximo paciente a ser operado(retorna os dados do paciente e exclui da lista.  \n");
            printf(" 	4- Retorna o tamanho da fila.                                                      \n");
            printf(" 	5- Sair do programa.                                                               ");
             printf("\n      -----------------------------------------------------------------------------------\n");
            scanf("%d",&menu);
            fflush(stdin);
 
            switch(menu)
            {
            	  case 1://add paciente
                    system("cls");
                    insere_fila(&iniciotransplante);
                break;
                    case 2://Buscar Paciente
                    system("cls");
                    printf("Insira o nome do paciente");
                    char buff[10];
                    fgets(buff, 10, stdin);
                    char nome[32];
                    fgets(nome, 32, stdin);

                    pos_fila = busca_nome_fila(iniciotransplante, nome);
                    if (pos_fila != NULL) {
                        printf("nome: %s\n", pos_fila->nodo->nome);
                        printf("grau: %d\n", pos_fila->nodo->grau);
                        printf("posicao na fila: %d\n", pos_fila->pos);
                    } else {
                        printf("paciente \"%s\" nao encontrado!\n");
                    }
                break;
                case 3://autoriza o transplante e remove o paciente da fila
                    system("cls");
                    if(iniciotransplante==NULL)
                    {
                        printf("Fila de transplante vazia!\n");
                        break;
                    }
                    remove_fila(&iniciotransplante,1);//a passagem do numero 1 é para indicar transplante 
                break;
                case 4://Retorna o tamanho da fila
                    system("cls");
                    if(iniciotransplante==NULL)
                    {
                        printf("Fila de transplante vazia\n");
                        break;
                    }
                    printf(" %d paciente(s) aguarda(m) na fila para o transplante", tamanho_fila(iniciotransplante));
                break;
                case 5://sair do laço while externo, liberando espaço alocado e saindo do programa
                   i=2;
                break;
                default:
                    system("cls");
                    printf("\nEscolha invalida!\n");
            }
        }
        freefila(&iniciotransplante);
    }
}

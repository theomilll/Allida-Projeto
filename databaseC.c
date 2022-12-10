#include<stdio.h>
#include<stdlib.h>
#include <time.h>

 struct node
{
    struct node* ant;
    int dados;
    struct node* prox;
};

struct node* head = NULL;

void inserir(int);
void printar(int);
void printarTxt(int);

struct node* criar_lista(int);

int tamanho();
int main()
{
    int tam,info,queda_c,queda_f,nQuedas=0;
    int dados, position,batimentos,giroscopio,acelerometro;
    int batimentos_cmp,giroscopio_cmp,acelerometro_cmp,cont=0;

    while (1){                              
        printf("\nDigite a captacao do sensor de batimentos: ");
        scanf(" %d",&batimentos); 
      
        if (batimentos==0) 
            break;

      
      
        printf("Digite a captacao do giroscopio: ");
        scanf(" %d",&giroscopio);
        printf("Digite a captacao do acelerometro: ");
        scanf(" %d",&acelerometro);

  

        if ((batimentos-batimentos_cmp>=40||batimentos-batimentos_cmp<=-40)&& acelerometro-acelerometro_cmp>=5 && giroscopio-giroscopio_cmp>=5 && cont>0){
          printf("\nFoi detectada uma queda aqui!\n");
          nQuedas++;
          queda_c=(nQuedas*3)-3;
        
          
            FILE *fp;
            fp = fopen("fall.txt", "w");
            if (fp == NULL){
                printf("Error opening file!\n");
                exit(1);
            }
            fprintf(fp, "1");
            fclose(fp);
          
          inserir(batimentos-batimentos_cmp);
          inserir(acelerometro-acelerometro_cmp);
          inserir(giroscopio-giroscopio_cmp);
          printarTxt(queda_c);

        }
        batimentos_cmp=batimentos;
        giroscopio_cmp=giroscopio;
        acelerometro_cmp=acelerometro;
        cont++;
    }
    system("cls");

}

struct node* criar_lista(int dados)
{
    struct node* novo = (struct node*) malloc(sizeof(struct node));
 
    if (novo == NULL)
    {
        return NULL;
    }
    else
    {
        novo->ant = NULL;
        novo->dados = dados;
        novo->prox = NULL;
    }
}
void inserir(int dados)
{
    struct node* novo = criar_lista(dados);
 
    if (novo == NULL)
    {
        return;
    }
    else if (head == NULL)
    {
        head = novo;
    }
    else
    {
        struct node* temp = head;
        while (temp->prox != NULL)
        {
            temp = temp = temp->prox;
        }
        temp->prox = novo;
        novo->ant = temp;
    }
}


void printarTxt(int c)
{
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    struct node* aux = head;
    struct node* pivot = head;
    int cont2=0;
    FILE *file;
    file = fopen("fallHistory.txt", "a");

    while (aux != NULL)
    {  
        if(c==cont2){
        fprintf (file,"\nData e horário da queda: %s \n", asctime (timeinfo) );
        fprintf(file,"Variacao dos batimentos cardiacos: %d  \n", aux->dados);
        aux = aux->prox;
        fprintf(file,"Variacao do acelerometro: %d  \n", aux->dados);
        aux = aux->prox; 
        fprintf(file,"Variacao do giroscopio: %d  \n \n \n", aux->dados);
        fprintf(file,"---------------------------------------------------");
        aux = aux->prox;
        fclose(file);
    }
    aux = aux->prox;
        cont2++;

    }
    *head = *pivot;
}

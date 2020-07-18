#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_Livro 100
#define True 1

typedef struct{
        char titulo[30];
        char editora[10];
        char autor[20];
        char  ISBN[10];
        int  caixa;
        int  edicao;
        int  ano;    
        int  qtd;
        int  UID ; //verifica se esta ativo

}livro;

livro Clivro[MAX_Livro],Crevista[MAX_Livro];


void  Input(){
    FILE* revistas;
    FILE*  livros;

    revistas = fopen("revistas.txt","a");
    livros   = fopen("livros.txt","a");

    if(revistas == NULL && livros == NULL){
        printf("Erro ao abrir arquivo!!\n");
    }
    for(int i=0;i<MAX_Livro;i++){  
        if(Clivro[i].UID == 1){
            fprintf(livros, "Caixa : %d\n",Clivro->caixa);
            fprintf(livros, "Titulo: %s",Clivro->titulo);
            fprintf(livros, "Autor: %s",Clivro->autor);
            fprintf(livros, "Editora: %s",Clivro->editora);
            fprintf(livros, "Edicao: %dº\n",Clivro->edicao);
            fprintf(livros, "ISBN: %s",Clivro->ISBN);
            fprintf(livros, "Ano: %d\n",Clivro->ano);
            fprintf(livros, "Quantidade: %d\n\n",Clivro->qtd);
        }
        if(Crevista[i].UID == 1){
            fprintf(revistas, "Caixa: %d\n",Crevista->caixa);
            fprintf(revistas, "Titulo: %s",Crevista->titulo);
            fprintf(revistas, "Autor: %s",Crevista->autor);
            fprintf(revistas, "Editora: %s",Crevista->editora);
            fprintf(revistas, "Edicao: %dº\n",Crevista->edicao);
            fprintf(revistas, "ISBN: %s",Crevista->ISBN);
            fprintf(revistas, "Ano: %d\n",Crevista->ano);
            fprintf(revistas, "Quantidade: %d\n\n",Crevista->qtd);

        }
    }
    fclose(revistas);
    fclose(livros);
}


void ListarLivros(void){
    system("clear");
    printf("Lista de livros\n");
    char texto[MAX_Livro];
    FILE* arquivo;
    arquivo = fopen("livros.txt","r");
    if(arquivo== NULL){
        printf("Erro ao abrir arquivo!!\n");
        exit(1);
    } 
    while(fgets(texto,sizeof(texto),arquivo)!= NULL){
            printf("%s",texto);
        
    }
    fclose(arquivo);
}


void ListarRevista(void){
    system("clear");
    printf("Lista de revistas\n");
    char texto[MAX_Livro];
    FILE* arquivo;
    arquivo = fopen("revistas.txt","r");
    if(arquivo== NULL){
        printf("Erro ao abrir arquivo!!\n");
        exit(1);
    } 
    while(fgets(texto,sizeof(texto),arquivo)!= NULL){
            printf("%s",texto);      
    }
    fclose(arquivo);
}

void ListarCaixa(void){
    system("clear");
    printf("Lista de Caixas\n");
    
    char texto[MAX_Livro];
    /*printf("Informe qual caixa a ser pesquisada:\n");
    __fpurge(stdin);
    scanf("%c",&caixa);*/
    FILE* livro;

   
    livro   = fopen("livros.txt","r");

    if (livro == NULL){
        printf("Erro ao abrir o arquivo!!\n");
        exit(1);
    }
    char ponto;
    int num;
   /* fgets(texto,sizeof(texto),livro);
        printf("%s\n",texto);*/
    
    while(fscanf(livro, "%s %c %d",texto,&ponto,&num )!=EOF){
        if(strcmp(texto,"Caixa")==0){
            printf("%s %c %d\n",texto,ponto,num);
        }
      /* printf("%s %c %d\n",texto,ponto,num);*/ 
    }
    
    
    fclose(livro);

}
void Cadastrar(void){
    char titulo[30];
    char editora[10];
    char autor[20];
    char  ISBN[10];    
    int  caixa;
    int  edicao;
    int  ano;
    int  qtd;
    int  opcao;
    system("clear");
    
    do{
        printf("   -------------------------\n");
        printf("  |1- Cadastrar livro       |\n");
        printf("  |2- Cadastrar revista     |\n");    
        printf("  |3- Sair                  |\n");
        printf("   -------------------------\n");
        scanf("%d",&opcao);
        switch(opcao){
            case 1:
                system("clear");
                printf("Titulo:\n");
                __fpurge(stdin);
                fgets(titulo,sizeof(titulo),stdin);
                
                printf("Autor:\n");
                __fpurge(stdin);
                fgets(autor,sizeof(autor),stdin);
                
                printf("Editora:\n");
                __fpurge(stdin);
                fgets(editora,sizeof(editora),stdin);
                
                printf("Edicao:\n");
                __fpurge(stdin);
                scanf("%d",&edicao);
                
                printf("Ano:\n");
                __fpurge(stdin);
                scanf("%d",&ano);

                printf("ISBN:\n");
                __fpurge(stdin);
                fgets(ISBN,sizeof(ISBN),stdin);

                printf("Caixa:\n");
                __fpurge(stdin);
                scanf("%d",&caixa);

                printf("Quantidade:\n");
                __fpurge(stdin);
                scanf("%d",&qtd);

                for(int i=0; i< MAX_Livro;i++){
                    if(Clivro[i].UID == 0){
                        strcpy(Clivro[i].titulo,titulo);
                        strcpy(Clivro[i].autor,autor);
                        strcpy(Clivro[i].editora,editora);
                        Clivro[i].edicao = edicao;
                        Clivro[i].ano = ano;
                        strcpy(Clivro[i].ISBN,ISBN);
                        Clivro[i].caixa = caixa;
                        Clivro[i].qtd = qtd;
                        Clivro[i].UID = 1;
                        break;
                    }
                }
    
                break;
            case 2:
                 system("clear");
                printf("Titulo:\n");
                __fpurge(stdin);
                fgets(titulo,sizeof(titulo),stdin);
                
                printf("Autor:\n");
                __fpurge(stdin);
                fgets(autor,sizeof(autor),stdin);
                
                printf("Editora:\n");
                __fpurge(stdin);
                fgets(editora,sizeof(editora),stdin);
                
                printf("Edicao:\n");
                __fpurge(stdin);
                scanf("%d",&edicao);
                
                printf("Ano:\n");
                __fpurge(stdin);
                scanf("%d",&ano);

                printf("ISBN:\n");
                __fpurge(stdin);
                fgets(ISBN,sizeof(ISBN),stdin);

                printf("Caixa:\n");
                __fpurge(stdin);
                scanf("%d",&caixa);

                printf("Quantidade:\n");
                __fpurge(stdin);
                scanf("%d",&qtd);
                 
                for(int i=0; i< MAX_Livro;i++){
                    if(Crevista[i].UID == 0){
                        strcpy(Crevista[i].titulo,titulo);
                        strcpy(Crevista[i].autor,autor);
                        strcpy(Crevista[i].editora,editora);
                        Crevista[i].edicao = edicao;
                        Crevista[i].ano = ano;
                        strcpy(Crevista[i].ISBN,ISBN);
                        Crevista[i].caixa = caixa;
                        Crevista[i].qtd = qtd;
                        Crevista[i].UID = 1;
                        break;
                    }
                }
                break;
        }
        
        system("clear");
    }while(opcao!=3);
    system("clear");
}



void menu(void){
    int opcao;
    
    do{
        printf("\t --------------\n");
        printf("\t|Nome Anderson |\n");
        printf("\t|RA 0000009-9  |\n");
        printf("\t --------------\n");

        printf("   -------------------------\n");
        printf("  |1- Cadastrar             |\n");
        printf("  |2- Listar livros         |\n");
        printf("  |3- Listar revistas       |\n");
        printf("  |4- Listar obras por caixa|\n");
        printf("  |5- Sair                  |\n");
        printf("   -------------------------\n");
        scanf("%d",&opcao);
        switch (opcao){
            case 1:
               Cadastrar();
               Input();
                break;
            case 2:
                ListarLivros();
                break;
            case 3:
                ListarRevista();
                break;
            case 4:
                ListarCaixa();
                break;             
        }
    }while(opcao!=5);
}

int main(void){

    menu();
    
    system("clear");
    return 0;
}

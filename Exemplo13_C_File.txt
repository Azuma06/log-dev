#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct Livro
{
    char Titulo[50];
    char Autor[50];
    short NumReg;
    double Preco;
} Livro;

Livro GetLivro()
{
    Livro livro;
    printf("\n\tDigite o titulo: ");
    fflush(stdin);
    gets(livro.Titulo);
    printf("\tDigite o nome do autor: ");
    fflush(stdin);
    gets(livro.Autor);
    printf("\tDigite o número do registro: ");
    scanf("%hd", &livro.NumReg);
    printf("\tDigite o preco: ");
    scanf("%lf", &livro.Preco);
    return livro;
}

void PrintLivro(Livro livro)
{
    printf("\n\tTitulo: %s\n", livro.Titulo);
    printf("\tAutor: %s\n", livro.Autor);
    printf("\tNr.Registro: %hd\n", livro.NumReg);
    printf("\tPreco: %.2lf\n", livro.Preco);
}

void ConsultarLivros(FILE *fptr, char opcao)
{
    Livro livro;
    char busca[50];
    int encontrado = 0;

    rewind(fptr);
    printf("\nDigite o valor para consulta: ");
    fflush(stdin);
    gets(busca);

    while (fread(&livro, sizeof(Livro), 1, fptr) == 1)
    {
        switch (opcao)
        {
        case '1':
            if (strcmp(livro.Titulo, busca) == 0)
            {
                PrintLivro(livro);
                encontrado = 1;
            }
            break;
        case '2':
            if (strcmp(livro.Autor, busca) == 0)
            {
                PrintLivro(livro);
                encontrado = 1;
            }
            break;
        case '3':
            if (livro.NumReg == atoi(busca))
            {
                PrintLivro(livro);
                encontrado = 1;
            }
            break;
        }
    }

    if (!encontrado)
        printf("\nNenhum registro encontrado.\n");
}

int main()
{
    Livro livro;
    char opcao, confirmacao;
    FILE *fptr;

    if ((fptr = fopen("Livros.dat", "rb+")) == NULL)
    {
        if ((fptr = fopen("Livros.dat", "wb+")) == NULL)
        {
            printf("Erro ao criar arquivo!");
            exit(1);
        }
    }

    do
    {
        printf("\n\n****** MENU ******\n");
        printf("1. Inserir registro\n");
        printf("2. Consultar registro\n");
        printf("3. Excluir todos\n");
        printf("4. Fim\n");
        printf("Digite sua opcao: ");
        opcao = getche();

        switch (opcao)
        {
        case '1':
            livro = GetLivro();
            fwrite(&livro, sizeof(Livro), 1, fptr);
            break;
        case '2':
            printf("\nConsultar por:\n");
            printf("1. Titulo\n");
            printf("2. Autor\n");
            printf("3. Numero do Registro\n");
            printf("Digite sua opcao: ");
            opcao = getche();
            ConsultarLivros(fptr, opcao);
            break;
        case '3':
            printf("\nTem certeza que deseja excluir todos os registros? (s/n) ");
            confirmacao = getche();
            if (confirmacao == 's' || confirmacao == 'S')
            {
                fclose(fptr);
                remove("Livros.dat");
                if ((fptr = fopen("Livros.dat", "wb+")) == NULL)
                {
                    printf("Erro ao criar arquivo!");
                    exit(1);
                }
            }
            break;
        case '4':
            break;
        default:
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != '4');

    fclose(fptr);
    return 0;
}
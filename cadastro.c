#include <stdio.h>
//Struct Inicial
struct Aluno
{
    int id;
    char nome[150];
    int idade;
    float nota;
};

int main()
{
    struct Aluno alunos[100];
    int opcao;
    int quantidade = 0;
    int c;
    do
    {
        //Tela Inicial
        printf("\n===== SISTEMA DE CADASTRO =====\n");
        printf("1- Cadastrar Aluno\n");
        printf("2- Listar Aluno\n");
        printf("3- Buscar Aluno\n");
        printf("4- Calcular media\n");
        printf("0- Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
            //CADASTRO DE ALUNO
        case 1:
            printf("Opcao de cadastro selecionada.\n");
            if (quantidade < 100)
            {
                printf("Digite o ID do aluno: ");
                scanf("%d", &alunos[quantidade].id);
                while ((c = getchar()) != '\n' && c != EOF)
                {
                }
                printf("Digite o nome do aluno: ");
                fgets(alunos[quantidade].nome, sizeof(alunos[quantidade].nome), stdin);
                printf("Digite a idade do aluno: ");
                scanf("%d", &alunos[quantidade].idade);
                printf("Digite a nota do aluno: ");
                scanf("%f", &alunos[quantidade].nota);
                quantidade++;
                printf("O Aluno Foi Cadastrado com sucesso!");
            }
            else
            {
                printf("Limite de alunos atingido!\n");
            }
            break;

        case 2:
        //LISTAR 
            printf("Opcao de listagem selecionada.\n");
            if (quantidade == 0)
            {
                printf("Nao ha alunos cadastrados!");
            }
            else
            {
                for (int i = 0; i < quantidade; i++)
                {
                    printf("ID: %d\n", alunos[i].id);
                    printf("Idade: %d\n", alunos[i].idade);
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Nota: %.2f\n", alunos[i].nota);
                }
            }
            break;

        case 3:
        //BUSCAR POR ID
            printf("Opcao de busca selecionada.\n");
            int id_digitado;
            int id_encontrado = 0;
            printf("Digite o ID do aluno que deseja buscar: ");
            scanf("%d", &id_digitado);

            for (int i = 0; i < quantidade; i++) {
                if (id_digitado == alunos[i].id) {
                    printf("\nAluno encontrado!\n");
                    printf("ID: %d\n", alunos[i].id);
                    printf("Idade: %d\n", alunos[i].idade);
                    printf("Nome: %s\n", alunos[i].nome);
                    printf("Nota: %.2f\n", alunos[i].nota);

                    id_encontrado = 1;
                    break;
                }
            }

            if(id_encontrado == 0) {
                printf("Aluno não encontrado\n");
            }

            break;

        case 4:
        //CALCULAR A MÉDIA
            printf("Opcao de media selecionada.\n");
            if (quantidade == 0) {
                printf("\nNão existe média para calcular!");
            }
            else {
                float soma = 0.0;
                for (int i = 0; i < quantidade; i++) {
                   soma+=alunos[i].nota;
                }

                float media = soma / quantidade;
                printf("A Média do aluno: %.2f\n", media);
            }
            break;

        case 0:
        //ENCERRA O PROGRAMA
            printf("Encerrando o sistema...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
#include <stdio.h>

int main()
{
    int inicio_h, inicio_m, fim_h, fim_m, duracao_h, duracao_m;

    printf("Digite a hora (apenas hora) de início do jogo: ");
    scanf("%d", &inicio_h);
    printf("Digite o minuto (apenas minuto) de início do jogo: ");
    scanf("%d", &inicio_m);

    printf("Digite a hora (apenas hora) de término do jogo: ");
    scanf("%d", &fim_h);
    printf("Digite o minuto (apenas minuto) de término do jogo: ");
    scanf("%d", &fim_m);
    

    duracao_h = fim_h - inicio_h;
    duracao_m = fim_m - inicio_m;

    if (duracao_m < 0)
    {
        duracao_m = 60 + duracao_m;
        duracao_h--;
    }

    if (duracao_h < 0)
    {
        duracao_h = 24 + duracao_h;
    }

    printf("O jogo durou %d hora(s) e %d minuto(s).", duracao_h, duracao_m);

    return 0;
}
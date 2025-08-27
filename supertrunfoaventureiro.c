// Incluí as bibliotecas que eu preciso pra fazer o programa funcionar
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Criei essa função pra resolver aquele problema do 'Enter' que sobra
// depois que eu uso o scanf pra ler um número. Ela limpa a entrada.
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Aqui é o "molde" da minha carta de país, com todos os dados que ela precisa ter.
struct CartaPais {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

// Aqui começa meu programa de verdade
int main() {
    // Declaro as duas cartas que vou usar no jogo
    struct CartaPais carta1, carta2;
    // Criei variáveis pra guardar as duas escolhas do jogador
    int escolha1 = 0, escolha2 = 0;
    // E mais variáveis pra guardar os valores dos atributos e a soma deles
    float valorAttr1_C1, valorAttr2_C1, valorAttr1_C2, valorAttr2_C2;
    float somaCarta1, somaCarta2;

    // --- CADASTRO DAS CARTAS ---
    // Agora, vou pedir pro usuário digitar os dados do primeiro país
    printf("--- DADOS DO PAIS 1 ---\n");
    printf("Nome: ");
    fgets(carta1.nome, sizeof(carta1.nome), stdin); // Uso fgets pra poder escrever nome com espaço
    carta1.nome[strcspn(carta1.nome, "\n")] = 0; // E aqui eu tiro o 'Enter' do final do nome

    printf("Populacao: ");
    scanf("%d", &carta1.populacao); // Uso scanf pra ler o número da população
    limpar_buffer(); // Chamo minha função pra limpar o 'Enter' que sobrou

    printf("Area: ");
    scanf("%f", &carta1.area); // Faço a mesma coisa pra área
    limpar_buffer();

    printf("PIB: ");
    scanf("%f", &carta1.pib); // Pro PIB também
    limpar_buffer();

    printf("Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos); // E pros pontos turísticos
    limpar_buffer();

    // Faço a mesma coisa pro segundo país
    printf("\n--- DADOS DO PAIS 2 ---\n");
    printf("Nome: ");
    fgets(carta2.nome, sizeof(carta2.nome), stdin);
    carta2.nome[strcspn(carta2.nome, "\n")] = 0;

    printf("Populacao: ");
    scanf("%d", &carta2.populacao);
    limpar_buffer();

    printf("Area: ");
    scanf("%f", &carta2.area);
    limpar_buffer();

    printf("PIB: ");
    scanf("%f", &carta2.pib);
    limpar_buffer();

    printf("Pontos Turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    limpar_buffer();

    // Com os dados em mãos, calculo a densidade de cada país
    carta1.densidade = carta1.populacao / carta1.area;
    carta2.densidade = carta2.populacao / carta2.area;

    // --- MENUS DE ESCOLHA ---
    // Mostro o menu pra primeira escolha do jogador
    printf("\n---------------------------------------\n");
    printf("JOGADOR 1, ESCOLHA O PRIMEIRO ATRIBUTO:\n");
    printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica (menor vence)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha1);
    limpar_buffer();

    // Criei um loop pra garantir que a segunda escolha seja diferente da primeira
    do {
        printf("\nJOGADOR 1, ESCOLHA O SEGUNDO ATRIBUTO (diferente do primeiro):\n");
        // Com esses 'if's, eu só mostro a opção se ela não foi a primeira que eu escolhi
        if (escolha1 != 1) { printf("1 - Populacao\n"); }
        if (escolha1 != 2) { printf("2 - Area\n"); }
        if (escolha1 != 3) { printf("3 - PIB\n"); }
        if (escolha1 != 4) { printf("4 - Pontos Turisticos\n"); }
        if (escolha1 != 5) { printf("5 - Densidade Demografica (menor vence)\n"); }
        printf("Digite sua escolha: ");
        scanf("%d", &escolha2);
        limpar_buffer();

        // Se eu escolher a mesma, ele avisa e o loop me faz escolher de novo
        if (escolha1 == escolha2) { printf("\nERRO: Voce nao pode escolher o mesmo atributo. Tente novamente.\n"); }
    } while (escolha1 == escolha2);

    // --- LÓGICA DA SOMA ---
    // Agora eu preciso pegar os valores dos atributos que escolhi para poder somar.
    // Esse primeiro switch pega os valores do primeiro atributo escolhido.
    switch (escolha1) {
        case 1: valorAttr1_C1 = carta1.populacao; valorAttr1_C2 = carta2.populacao; break;
        case 2: valorAttr1_C1 = carta1.area; valorAttr1_C2 = carta2.area; break;
        case 3: valorAttr1_C1 = carta1.pib; valorAttr1_C2 = carta2.pib; break;
        case 4: valorAttr1_C1 = carta1.pontosTuristicos; valorAttr1_C2 = carta2.pontosTuristicos; break;
        // Se for densidade, eu inverto o valor pra soma fazer sentido (menor densidade = mais pontos)
        case 5: valorAttr1_C1 = 1000.0 / carta1.densidade; valorAttr1_C2 = 1000.0 / carta2.densidade; break;
        default: valorAttr1_C1 = 0; valorAttr1_C2 = 0; break;
    }
    // Esse segundo switch faz a mesma coisa pro segundo atributo.
    switch (escolha2) {
        case 1: valorAttr2_C1 = carta1.populacao; valorAttr2_C2 = carta2.populacao; break;
        case 2: valorAttr2_C1 = carta1.area; valorAttr2_C2 = carta2.area; break;
        case 3: valorAttr2_C1 = carta1.pib; valorAttr2_C2 = carta2.pib; break;
        case 4: valorAttr2_C1 = carta1.pontosTuristicos; valorAttr2_C2 = carta2.pontosTuristicos; break;
        case 5: valorAttr2_C1 = 1000.0 / carta1.densidade; valorAttr2_C2 = 1000.0 / carta2.densidade; break;
        default: valorAttr2_C1 = 0; valorAttr2_C2 = 0; break;
    }

    // Com os valores em mãos, aqui eu somo os "poderes" de cada carta.
    somaCarta1 = valorAttr1_C1 + valorAttr2_C1;
    somaCarta2 = valorAttr1_C2 + valorAttr2_C2;

    // --- PLACAR FINAL ---
    // Mostro o placar detalhado de cada carta
    printf("\n--- PLACAR DA RODADA ---\n");
    // Criei umas strings pra guardar os nomes dos atributos e mostrar no placar
    char nomeAttr1[30], nomeAttr2[30];
    switch(escolha1) { case 1: strcpy(nomeAttr1, "Populacao"); break; case 2: strcpy(nomeAttr1, "Area"); break; case 3: strcpy(nomeAttr1, "PIB"); break; case 4: strcpy(nomeAttr1, "Pontos Turisticos"); break; case 5: strcpy(nomeAttr1, "Densidade"); break; default: strcpy(nomeAttr1, "Invalido"); break; }
    switch(escolha2) { case 1: strcpy(nomeAttr2, "Populacao"); break; case 2: strcpy(nomeAttr2, "Area"); break; case 3: strcpy(nomeAttr2, "PIB"); break; case 4: strcpy(nomeAttr2, "Pontos Turisticos"); break; case 5: strcpy(nomeAttr2, "Densidade"); break; default: strcpy(nomeAttr2, "Invalido"); break; }
    
    printf("Atributos escolhidos: %s e %s\n\n", nomeAttr1, nomeAttr2);
    
    // Placar da primeira carta
    printf("--- %s ---\n", carta1.nome);
    // Aqui eu verifico se era densidade. Se for, mostro o valor original, não o invertido.
    printf("%s: %.2f\n", nomeAttr1, (escolha1 == 5) ? carta1.densidade : valorAttr1_C1);
    printf("%s: %.2f\n", nomeAttr2, (escolha2 == 5) ? carta1.densidade : valorAttr2_C1);
    printf("SOMA DE PODER: %.2f\n\n", somaCarta1);

    // Placar da segunda carta
    printf("--- %s ---\n", carta2.nome);
    printf("%s: %.2f\n", nomeAttr1, (escolha1 == 5) ? carta2.densidade : valorAttr1_C2);
    printf("%s: %.2f\n", nomeAttr2, (escolha2 == 5) ? carta2.densidade : valorAttr2_C2);
    printf("SOMA DE PODER: %.2f\n\n", somaCarta2);

    // Veredito final
    printf("---------------------------------------\n");
    // Usei esse operador ternário que é tipo um if/else numa linha só pra decidir o vencedor
    char* vencedor = (somaCarta1 > somaCarta2) ? carta1.nome : (somaCarta2 > somaCarta1) ? carta2.nome : "Empate!";
    
    // No final, eu só vejo o que está na variável 'vencedor' e mostro a mensagem certa.
    if (strcmp(vencedor, "Empate!") == 0) {
        printf("Resultado: EMPATE!\n");
    } else {
        printf("Resultado: O GRANDE VENCEDOR E %s!\n", vencedor);
    }
    printf("---------------------------------------\n");

    return 0; // Fim do programa!
}
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
   


int main(){

 typedef struct { //variaveis usando o comando struct que serve pra juntar as informaçoes ao invez de separa-las
    char pais[50];
    char estado;
    char cidade[50];
    unsigned int populacao;
    float area;
    float pib;
    int pontosturisticos;
    char codigo[5];
    float densidade;
    float pibpercapta;
    unsigned int poder;
 }cartas;
 
  srand(time(NULL));// inicializa o gerador de numeros aleatorios com base no tempo atual do pc
    
    int atributo[2]; // variavel para guardar
    int vencedor[2];
    cartas carta[2];
    int escolhaPC;
    int indice = 0;
    int pontosjogador = 0;
    int pontospc = 0;

    // Carta 1 (computador) recebe valores aleatórios
    escolhaPC = 1; // só para indicar que é a carta do PC
    carta[1].populacao = rand() % 10000000 +1;     // até 10 milhões
    carta[1].area = rand() % 10000 + 1;             // até 10 mil km²
    carta[1].pib = rand() % 1000000 + 1;            // até 1 milhão
    carta[1].pontosturisticos = rand() % 100 + 1;   // até 100 pontos turísticos
    carta[1].densidade = (float)carta[1].populacao / (carta[1].area + 1); // evita divisão por zero
    carta[1].pibpercapta = (float)carta[1].pib / (carta[1].populacao + 1);
    carta[1].poder = carta[1].pib + carta[1].area + carta[1].pibpercapta + carta[1].pontosturisticos + carta[1].densidade;


    char estados[] = {'A','B'};// array com as letras pra formar o codigo do estado
    int menu = 0;
    int sair = 0;

 while (!sair) {   // mantém o programa rodando até sair


  printf("***Menu*** \n");
  printf("1.Iniciar jogo! \n");
  printf("2.Regras\n");
  printf("3.Sair do jogo...\n");
  scanf("%d", &menu);

  getchar();

switch(menu){
case 1:
      /*descobri essa função chamada sprintf que 
      mostra a informação na tela mas tambem salva em string*/
      // aqui é para pedir os dados das cartas
      //usei o fgets para ler strings com espaços
      carta[indice].estado = estados[indice];

      sprintf(carta[indice].codigo, "%c%02d", estados[indice], indice + 1);

      printf("Qual o nome do pais?: \n");
      fgets(carta[indice].pais, sizeof(carta[indice].pais), stdin);
      carta[indice].pais[strcspn(carta[indice].pais, "\n")] = '\0';

      printf("Digite o nome da cidade: \n");
      fgets(carta[indice].cidade, sizeof(carta[indice].cidade), stdin);
      carta[indice].cidade[strcspn(carta[indice].cidade, "\n")] = '\0'; // Remove o caractere de nova linha lido pelo fgets

      printf("Qual a população da cidade?: \n");
      scanf("%u", &carta[indice].populacao);

      getchar(); // Limpa o buffer do teclado

      printf("Qual a area em KM² da cidade?: \n");
      scanf("%f", &carta[indice].area);
            
      getchar(); // Limpa o buffer do teclado

      printf("Digite o PIB: \n");
      scanf("%f", &carta[indice].pib);
            
      getchar(); // Limpa o buffer do teclado

      printf("Numero de pontos turísticos?: \n");
      scanf("%d", &carta[indice].pontosturisticos);
 
      getchar(); // Limpa o buffer do teclado 

     carta[0].densidade = (float)carta[0].populacao / (carta[0].area + 1);
     carta[0].pibpercapta = (float)carta[0].pib / (carta[0].populacao + 1);
     carta[0].poder = carta[0].pib + carta[0].area + carta[0].pibpercapta + carta[0].pontosturisticos + carta[0].densidade;


     
   //mostrar a carta cadastrada do jogador     
    printf("\n--- Sua Carta ---\n");
    printf("População: %u \n", carta[0].populacao);
    printf("Área: %.2f km²\n", carta[0].area);
    printf("PIB: %.2f \n", carta[0].pib);
    printf("Pontos turísticos: %d\n", carta[0].pontosturisticos);
    printf("Densidade: %.2f \n", carta[0].densidade);
    printf("PIB per capita: %.2f  \n", carta[0].pibpercapta);
    printf("Poder: %u \n", carta[0].poder);
    printf("--------------------------------\n");



    //Jogador escolhe um atributo para ser comparado contra o pc
    printf("Escolha um atributo para comparar: \n");
    printf("1.População: \n");
    printf("2.Área: \n");
    printf("3.PIB: \n");
    printf("4.Pontos Turísticos: \n");
    printf("5.Densidade Populacional é : \n");
    printf("6.Pib per capta é: \n");
    printf("7.o nivel de poder total é: \n");
    printf("-------------------------\n");  
    
    for (int i = 0; i < 2; i++) {
    printf("Escolha um atributo para comparar (1 a 7): ");
    scanf("%d", &atributo[i]);

    // Verifica se o jogador escolheu o mesmo atributo duas vezes
      if (i == 1 && atributo[0] == atributo[1]) {
        printf("Você escolheu 2 atributos iguais!! Tente novamente...\n");
        i--; // volta uma posição para pedir de novo
        continue;
    }
      switch (atributo[i]) {
        case 1:
            printf("População foi escolhida!\n");
            vencedor[i] = (carta[0].populacao > carta[1].populacao) ? 1 : 2;
            break;
        case 2:
            printf("Área foi escolhida!\n");
            vencedor[i] = (carta[0].area > carta[1].area) ? 1 : 2;
            break;
        case 3:
            printf("PIB foi escolhido!\n");
            vencedor[i] = (carta[0].pib > carta[1].pib) ? 1 : 2;
            break;
        case 4:
            printf("Pontos turísticos foi escolhido!\n");
            vencedor[i] = (carta[0].pontosturisticos > carta[1].pontosturisticos) ? 1 : 2;
            break;
        case 5:
            printf("Densidade foi escolhida!\n");
            vencedor[i] = (carta[0].densidade < carta[1].densidade) ? 1 : 2;
            break;
        case 6:
            printf("PIB per capita foi escolhido!\n");
            vencedor[i] = (carta[0].pibpercapta > carta[1].pibpercapta) ? 1 : 2;
            break;
        case 7:
            printf("Poder total foi escolhido!\n");
            vencedor[i] = (carta[0].poder > carta[1].poder) ? 1 : 2;
            break;
        default:
            printf("Opção inválida!\n");
            vencedor[i] = 0;
            break;
    }
  }   

    //mostrar a carta cadastrada do jogador     
    printf("\n--- Carta do PC ---\n");
    printf("População: %u \n", carta[1].populacao);
    printf("Área: %.2f km²\n", carta[1].area);
    printf("PIB: %.2f\n", carta[1].pib);
    printf("Pontos turísticos: %d\n", carta[1].pontosturisticos);
    printf("Densidade: %.2f\n", carta[1].densidade);
    printf("PIB per capita: %.2f\n", carta[1].pibpercapta);
    printf("Poder: %u \n", carta[1].poder);
    printf("--------------------------------\n");

    for(int i; i < 2; i++){
    if (vencedor[i] == 1)pontosjogador++;
    else if (vencedor[i] == 2)pontospc++;
   }
    if(pontosjogador > pontospc)
    {
        printf("Jogador venceu!! \n");
    }
    else if (pontosjogador < pontospc)
    {
      printf("Computador venceu!! \n");
    }
    else
    {
      printf("Empate!!! \n");
    }

   break;
case 2:

  printf("###As regras são###\n");
  printf("Você responde corretamente as informaçoes de acordo \ncom a cidade que vc escolheu...\n");
  printf("O computador vai escolher valores aletorios \n ");
  printf("Você escolhera 2 desses valores para comparar contra o PC \n");
  printf("Se seu valor for maior (menos no caso \nda densidade populacional que deve ser menor que o do pc) você ganha!!\n");
  printf("###############################\n");
  
    break;
  case 3:

      printf("Saindo do jogo...\n");
      sair = 1; // encerra o while2
   break;
  default:

  printf("Opção invalida...");

 break;
}
}
}
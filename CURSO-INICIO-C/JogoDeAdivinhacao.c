#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double pontos = 1000;
int numerosecreto;
int numerodetentativas;

void cabecalho();
int escolhadonivel();
void processamento(int numerodedetentativas, int numerosecreto);
int lerchutes();
double calculopontos(int chute);

int main(){
	srand(time(0)); //semente do número randômico - data EPOCH
	numerosecreto = rand() % 100; //para limitar entre 0 e 99

	cabecalho();

	numerodetentativas = escolhadonivel();

	processamento(numerodetentativas, numerosecreto);

	printf("Voce fez: %.1f/1000.0 pontos\n", pontos);
	return 0;
}

void cabecalho () {
    printf("******************************************\n");
    printf("*            JOGO DE ADIVINHACAO         *\n");
    printf("*               BEM-VINDO!               *\n");
    printf("******************************************\n");
}

int escolhadonivel () {
	int nivel = 0;
	while (nivel != 1 && nivel != 2 && nivel != 3) {
		printf("Qual o nivel de dificuldade?\n\n");
		printf("(1) Facil: 20 tentativas\n(2) Medio: 15 tentativas\n(3) Dificil: 6 tentativas\n\n");
		printf("Escolha um numero correspondente ao nivel: ");
		if (scanf("%d", &nivel)!= 1 || nivel < 1 || nivel > 3) {
			printf("Entrada invalida. Escolha um numero de 1 a 3.\n");
			while(getchar() != '\n');
			continue;
		}
		switch (nivel) {
			case 1: numerodetentativas = 20; break;
			case 2: numerodetentativas = 15; break;
			case 3: numerodetentativas = 6; break;
		}
	}
	return numerodetentativas;
}

int lerchute () {
	int num;
	while(1) {
		printf("Qual o seu chute? ");
		if (scanf("%d", &num) != 1) { //scanf retorna 0 se user digitar alguma entrada inválida
			printf("Entrada invalida. Por favor, digite um numero entre 0 e 99.\n");
			while(getchar() != '\n'); //getchar faz a leitura do buffer de entrada até encontrar um enter e realiza a limpeza
			continue;
		}
		if (num < 0) {
			printf("Voce nao pode chutar numeros negativos! Por favor, digite um numero entre 0 e 99.\n");
			continue;
		}
		break; //saia do loop se a entrada for válida
	}
	return num;
}

void processamento (int numerodetentativas, int numerosecreto) { //entrada e tratamento de dados, comparação, cálculo e exibição de dados
	int chute = 0;
	int acertou = 0;

	for (int i=1; i<=numerodetentativas; i++) {
		printf("\nTentativa %d\n",i);
		chute = lerchute();
		
		acertou = chute == numerosecreto; //guarda um valor booleano: 0 ou 1
		int maior = chute > numerosecreto;

		//comparação
		if (acertou) {
			printf("Parabens! Voce acertou!\n");
			printf("     ..-\"\"\"\"\"\"-.\n");
			printf("   .'          '.\n");
			printf("  /   O    -=-   \\\n");
			printf(" :                :\n");
			printf(" |                |  \n");
			printf(" : ',          ,' :\n");
			printf("  \\  '-.....-'   /\n");
			printf("   '.          .'\n");
			printf("    '-.......-'\n");        
			printf("Obrigada por jogar!!\n");
			printf("Voce acertou em %d tentativas!\n", i);
			break;
		} else if (maior) {
			printf("Seu chute foi maior que o numero secreto\n");
		} else {
			printf("Seu chute foi menor que o numero secreto\n");
		}

		calculopontos(chute); //att pontos após cada tentativa
		printf("Voce tem: %.1f/1000.0 pontos\n", pontos);
	}

	if (!acertou) {
				printf("O numero secreto era %d\n", numerosecreto);
				printf("Voce perdeu! Tente novamente!\n");
			    printf("       \\|/ ____ \\|/       \n");
    			printf("        @~/ ,. \\~@         \n");
    			printf("       /_( \\__/ )_\\       \n");
    			printf("          \\__U_/          \n\n");
	}
}

double calculopontos (int chute) {
		double pontosperdidos = abs(chute - numerosecreto) / (double)2;
		pontos = pontos - pontosperdidos;
		return pontos;
}
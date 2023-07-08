//Mateus de Almeida
//Paulo Henrique
//Ariel

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int largura = 600, altura = 600;
int translacao_y = 50, translacao_x = 0, rotacao=0, i = 0;
int pontuacao = 0, vidas = 3, estado = 1;

void Menu(int option);
void MenuFechar() ;
void TelaInicial(void);
void GameOver(void);
//Declaração das funções que usam teclado e mouse
void teclado(unsigned char key, int x, int y);
void setas(int key, int x, int y);
void mouse(int button, int state, int x, int y);

//Declaração da função de texto para pontos
void Texto(float x, float y, void *font, const char *string);

//Função que faz os objetos descerem
void AtualizarTranslacao(int value) {
	int direcao;
    if (translacao_y > -50 && estado == 2){
    	direcao = -1;
    	translacao_y += 4 * direcao;
	}

    glutPostRedisplay();  // Redesenha a cena
    glutTimerFunc(50, AtualizarTranslacao, 0);  // Chama a função novamente após 1 segundo
}

void Inicializa(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

//Função responsavel por redimensionar a tela e centralizar
void Redimensionar(int width, int height) {
	int x = 0;
    if (height < width) {
    	x = (width - height) / 2;
        width = height;
    }
    
    largura = width;
    altura = height;

    glViewport(x, 0, width, height);
    x=0;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50, 50, -50, 50);
}

//Função que desenha o cenário e os objetos na tela
void DesenhaTela(void) {
	
	char pontos2[20];
	char vidas2[20];
	//compensações na mudança de hitbox
	int comp1 = 0, comp2 = 0;
	//pontuação
	int pontos = 0;
	//Limitações de translação;
	int translacaox_max[2][5] = {{46,42,46,44,46},{46,48,44,44,46}};
	//Coloca todas as formas para começar do ponto 50;
	int offset[2][5] = {{4,2,6,6,2},{4,8,4,2,4}};
	//1- Quadrado, 2- Barra, 3-FormaZ, 4- FormaT, 5-FormaL
	int vetor_formas[5] = {0,1,2,3,4};
	
	//Definição da hitbox das formas geometricas
	int hitbox_quadrado[4] = {-4,4,-4,4};
	int hitbox_barra[2][4] = {{-8,8,-2,2},{-2,2,-8,8}};
	int hitbox_FormaZ[2][4] = {{-2,4,-6,6}, {-6,2,-4,4}};
	int hitbox_FormaT[2][4] = {{-2,2,-6,6},{-6,6,-2,6}};
	int hitbox_FormaL[4][4] = {{-4,4,-2,6},{-10,2,-4,4},{0,4,-2,6},{-2,2,-4,4}};
	
	//variaveis de controle da rotação, offset e hitbox
	int l;
	int j;
	int r;
	int of;
	
	if(rotacao == 0){
		j = 0;
		r = 0;
		l = 0;
	}

	if(rotacao == 90){
		j = 1;
		r = 0;
		l = 1;
	}

	if(rotacao == 180){
		j = 0;
		r = 1;
		l = 2;
	}

	if(rotacao == 270){
		j = 1;
		r = 0;
		l = 3;
	}
	
	if(vetor_formas[i] != 3 && vetor_formas[i] != 4){
		of = j;
	}

	else if(vetor_formas[i] == 3){
			of = r;
			if(rotacao == 90)
				comp1 = -4;
			if(rotacao == 270)
				comp2 = 4;
		}
		else{
			of = j;
			if(rotacao == 90){
				comp1 = 6;
				comp2 = 2;
			}
			if(rotacao == 270){
				comp1 = -2;
				comp2 = -6;
			}
		}

		
    glClear(GL_COLOR_BUFFER_BIT);

    FundoTela();
	
		
		glPushMatrix();
		
		if (translacao_x >= translacaox_max[j][i] + comp2) {
			translacao_x = translacaox_max[j][i] + comp2;
    		glTranslatef(translacao_x, translacao_y + offset[of][i], 0.0f);
		} 
		else if (translacao_x <= -translacaox_max[j][i] + comp1) {
			translacao_x = -translacaox_max[j][i] + comp1;
    		glTranslatef(translacao_x, translacao_y + offset[of][i], 0.0f);
		} 
			else {
   				glTranslatef(translacao_x, translacao_y + offset[of][i], 0.0f);
			}
		
		glRotatef(rotacao, 0.0f, 0.0f, 1.0f);
		
		switch(vetor_formas[i]){
			case 0: Quadrado();
					if(hitbox_quadrado[0] + translacao_x >= -50
    				&& hitbox_quadrado[1] + translacao_x <= -30
					&& hitbox_quadrado[2] + translacao_y + offset[of][i] < -48)
    					pontos++;
			break;
			case 1: Barra();
					if(hitbox_barra[j][0] + translacao_x >= -30
    				&& hitbox_barra[j][1] + translacao_x <= -10
					&& hitbox_barra[j][2] + translacao_y + offset[of][i] < -48)
    					pontos++;
			break;
			case 2: FormaZ();
    				if(hitbox_FormaZ[j][0] + translacao_x >= -10
    				&& hitbox_FormaZ[j][1] + translacao_x <= 10
					&& hitbox_FormaZ[j][2] + translacao_y + offset[of][i] < -48)
    					pontos++;
			break;
			case 3: FormaT();
					if(hitbox_FormaT[r][0] + translacao_x >= 10
    				&& hitbox_FormaT[r][1] + translacao_x <= 30
					&& hitbox_FormaT[r][2] + translacao_y + offset[of][i] < -48)
    					pontos++;
			break;
			case 4: FormaL();
					if(hitbox_FormaL[l][0] + translacao_x >= 30
    				&& hitbox_FormaL[l][1] + translacao_x <= 50
					&& hitbox_FormaL[l][2] + translacao_y + offset[of][i] < -48)
    					pontos++;
			break;
		}
    	glPopMatrix();
    	
    	if (pontos>0)
    		pontuacao++;
    		
    	if(translacao_y == -50){
    		i++;
    		rotacao = 0;
    		
    		if(pontos<=0){
    			vidas--;
			}
    		
    		if(i == 5)
    			i = 0;
    			
    		translacao_y = 50;
		} 
		sprintf(pontos2, "Pontos: %d",pontuacao);
		sprintf(vidas2, "Vidas: %d",vidas);
		Texto(-45, 40, GLUT_BITMAP_TIMES_ROMAN_24,pontos2);
		Texto(-45, 35, GLUT_BITMAP_TIMES_ROMAN_24,vidas2);
		
		if(vidas<=0){
			
			glutDisplayFunc(GameOver);
		}
		glFlush();
		
}

int main(void) {
	
	printf("Para movimentar as formas use as setas do teclado\n");
	printf("Para girar as formas use a tecla espaco\n");
	
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    //Definição da Janela
    glutInitWindowSize(largura, altura);
    glutCreateWindow("Tetris");
    
    //Uso do teclado e mouse
    glutSpecialFunc(setas);
    glutKeyboardFunc(teclado);
    glutMouseFunc(mouse);
    
	//Redimensionamento 
    glutReshapeFunc(Redimensionar);
    
    //Menu
    MenuFechar();
    
    //Desenho na Tela
    glutDisplayFunc(TelaInicial);
    Inicializa();
	
	//Função que desce os objetos
    glutTimerFunc(50, AtualizarTranslacao, 0);  
    glutMainLoop();
}


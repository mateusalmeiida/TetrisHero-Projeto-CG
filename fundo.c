#include <GL/glut.h>

extern int estado;
extern int vidas;

void Texto(float x, float y, void *font, const char *string);

void Espaco(void){
	
	glBegin(GL_QUADS);
	glColor3f(0,0,0);
		glVertex3f(-50.0,-50.0,0);
	glColor3f(0,0,0.2);
		glVertex3f(50.0,-50.0,0);
	glColor3f(0,0,0);
		glVertex3f(50.0,50.0,0);
	glColor3f(0,0,0.2);
		glVertex3f(-50.0,50.0,0);
	glEnd();
}

void Borda(void){
	
	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3f(1,1,1);
		glVertex3f(-50,50.0,0);
		glVertex3f(-50,-50,0);
		glVertex3f(50,-50,0);
		glVertex3f(50.0,50.0,0);
	glEnd();
}

void Locais_ponto(void){
	
	glPushMatrix();
	glTranslatef(-40,-49, 0.0f);
	glColor3f(0,1,0);
	Build_Retangulo(0,20,2);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,20,2,1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-20,-49, 0.0f);
	glColor3f(1,0,0);
	Build_Retangulo(0,20,2);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,20,2,1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,-49, 0.0f);
	glColor3f(0.2,0.5,1);
	Build_Retangulo(0,20,2);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,20,2,1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(20,-49, 0.0f);
	glColor3f(1,0,0.5);
	Build_Retangulo(0,20,2);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,20,2,1);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(40,-49, 0.0f);
	glColor3f(1,1,0);
	Build_Retangulo(0,20,2);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,20,2,1);
	glPopMatrix();
}

void FundoTela(void){
	Espaco();
	Locais_ponto();
	Borda();
}

//Tela de Game over
void GameOver(void){
	glClear(GL_COLOR_BUFFER_BIT);
	Espaco();
	Borda();
	glColor3f(1,1,1);
	Texto(-10, 0, GLUT_BITMAP_TIMES_ROMAN_24,"GAME OVER");
	
	glFlush();
}

void TelaInicial(void){
	glClear(GL_COLOR_BUFFER_BIT);
	Espaco();
	Borda();
	//Botão de Jogar
	glColor3f(0.2,0.5,1);
	Build_Retangulo(0,30,10);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,30,10,3);
	Texto(-6.5, -1, GLUT_BITMAP_TIMES_ROMAN_24,"JOGAR");
	
	//Desenho do T
	glPushMatrix();
	glTranslatef(0,25, 0.0f);
	glColor3f(1,0,0.5);
	Build_Retangulo(0,6,20);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,6,20,3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0,32, 0.0f);
	glColor3f(1,0,0.5);
	Build_Retangulo(0,20,6);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,20,6,3);
	glPopMatrix();
	
	//Quadrados coloridos
	glPushMatrix();
	glTranslatef(-3.5,-25, 0.0f);
	glColor3f(1,0,0.5);
	Build_Retangulo(0,7,7);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,7,7,3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(4,-25, 0.0f);
	glColor3f(0.2,0.5,1);
	Build_Retangulo(0,7,7);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,7,7,3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(4,-18, 0.0f);
	glColor3f(1,0,0);
	Build_Retangulo(0,7,7);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,7,7,3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-3.5,-18, 0.0f);
	glColor3f(0,1,0);
	Build_Retangulo(0,7,7);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,7,7,3);
	glPopMatrix();
	
	
	if(estado == 2)
		DesenhaTela();
	glFlush();
}

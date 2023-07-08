#include <GL/glut.h>

// 1- Quadrado, 2- Barra, 3-FormaZ, 4- FormaT, 5-FormaL
void Barra()
{
	//Construção da forma solida e bordas
	glColor3f(1,0,0);
	Build_Retangulo(0,16,4);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,16,4,3);
	
	//Linhas Brancas dentro das formas
	glBegin(GL_LINES);
		glVertex3f(-4,2,0);
		glVertex3f(-4,-2,0);
		
		glVertex3f(0,2,0);
		glVertex3f(0,-2,0);
		
		glVertex3f(4,2,0);
		glVertex3f(4,-2,0);	
	glEnd();
}

void Quadrado()
{
	//Construção da forma solida e bordas
	glColor3f(0,1,0);
	Build_Retangulo(0,8,8);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,8,8,3);
	
	//Linhas Brancas dentro das formas
	glBegin(GL_LINES);
		glVertex3f(0,4,0);
		glVertex3f(0,-4,0);
		
		glVertex3f(-4,0,0);
		glVertex3f(4,0,0);		
	glEnd();
}

void FormaL()
{
	//Construção da forma solida e bordas
	glColor3f(1,1,0);
	Build_Retangulo(0,8,4);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,8,4,3);
	
	glPushMatrix();
	glTranslatef(-2.0,6.0f, 0.0f);
	glColor3f(1,1,0);
	Build_Retangulo(0,4,8);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,4,8,3);
	glPopMatrix();
	
	//Linhas Brancas dentro das formas
	glBegin(GL_LINES);
		glVertex3f(0,-2,0);
		glVertex3f(0,2,0);
		
		glVertex3f(-4,6,0);
		glVertex3f(0,6,0);
	glEnd();
}

void FormaZ (){
	
	//Construção da forma solida e bordas
	glColor3f(0.2,0.5,1);
	Build_Retangulo(0,8,4);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,8,4,3);

	
	glPushMatrix();
	glTranslatef(-2.0,4.0f, 0.0f);
	glColor3f(0.2,0.5,1);
	Build_Retangulo(0,4,4);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,4,4,3);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(2.0,-4.0f, 0.0f);
	glColor3f(0.2,0.5,1);
	Build_Retangulo(0,4,4);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,4,4,3);
	glPopMatrix();
	
	//Linhas Brancas dentro das formas
	glBegin(GL_LINES);
		glVertex3f(0,-2,0);
		glVertex3f(0,2,0);
	glEnd();
	
}

void FormaT(){
	
	//Construção da forma solida e bordas
	glColor3f(1,0,0.5);
	Build_Retangulo(0,12,4);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,12,4,3);
	
	//Linhas Brancas dentro das formas
	glBegin(GL_LINES);
		glVertex3f(-2,-2,0);
		glVertex3f(-2,2,0);
		
		glVertex3f(2,-2,0);
		glVertex3f(2,2,0);	
	glEnd();

	//Construção da forma solida e bordas
	glPushMatrix();
	glTranslatef(0,-4.0f, 0.0f);
	glColor3f(1,0,0.5);
	Build_Retangulo(0,4,4);
	glColor3f(1,1,1);
	Build_Borda_Retangulo(0,4,4,3);
	glPopMatrix();
	
}



#include <GL/glut.h>

void Build_Retangulo(int centro, int largura, int altura){
	glBegin(GL_QUADS);
		glVertex3f(-largura/2 + centro, altura/2 + centro ,0);
		glVertex3f(-largura/2 + centro, -altura/2 + centro ,0);
		glVertex3f(largura/2 + centro , -altura/2 + centro ,0);
		glVertex3f(largura/2 + centro , altura/2 + centro ,0);
	glEnd();
}

void Build_Borda_Retangulo(int centro, int largura, int altura, int espessura){
	
	glLineWidth(espessura);
	glBegin(GL_LINE_LOOP);
		glVertex3f(-largura/2 + centro, altura/2 + centro ,0);
		glVertex3f(-largura/2 + centro, -altura/2 + centro ,0);
		glVertex3f(largura/2 + centro , -altura/2 + centro ,0);
		glVertex3f(largura/2 + centro , altura/2 + centro ,0);
	glEnd();
}


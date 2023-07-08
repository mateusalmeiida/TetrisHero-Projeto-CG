#include <stdlib.h>
#include <GL/glut.h>

extern int rotacao;
extern int translacao_y;
extern int translacao_x;
extern int estado;
extern int restart;

// 1- Quadrado, 2- Barra, 3-FormaZ, 4- FormaT, 5-FormaL

void teclado(unsigned char key, int x, int y) {
	
    if (key == ' ') {
    	if(translacao_y>-50)
        	rotacao += 90;
		if(rotacao == 360)
			rotacao = 0;
        glutPostRedisplay();    // Marcar a janela para ser redesenhada
    }
    else if (key == 27) {
        exit(0);  // Tecla ESC para sair do programa
    }
    
}

void setas(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
        	if(translacao_y>-50)
        		if(translacao_x > -50){
        			translacao_x -= 4;
        			glutPostRedisplay();
				}

            break;
        case GLUT_KEY_RIGHT:
        	if(translacao_y>-50)
            	if(translacao_x < 50){
            		translacao_x += 4;
            		glutPostRedisplay();
				}

			break;
    } 
}

void mouse(int button, int state, int x, int y) {
	float mouseX = ((float)x / glutGet(GLUT_WINDOW_WIDTH)) * 100.0 - 50.0;
    float mouseY = ((float)(glutGet(GLUT_WINDOW_HEIGHT) - y) / glutGet(GLUT_WINDOW_HEIGHT)) * 100.0 - 50.0;
	//clique do botão esquerdo do mouse pressionado
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    	if(mouseX<=15 && mouseX>=-15 && mouseY<=5 && mouseY>=-5)
			estado = 2;
}



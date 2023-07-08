#include <GL/glut.h>
#include <stdlib.h>

int menuID;
extern int estado;

void Texto(float x, float y, void *font, const char *string)
{
	glRasterPos2f(x, y);
	while (*string)
	{
		glutBitmapCharacter(font, *string);
		string++;
	}
}

void Menu(int option) {
    switch (option) {
        case 1:
        	estado = 1;
        	exit(1);
            break;
	}
}

// Fun��o de inicializa��o
void MenuFechar() {
    // Cria��o do menu
    menuID = glutCreateMenu(Menu);
    glutAddMenuEntry("Fechar", 1);
    // Vincula��o do menu ao bot�o direito do mouse
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
}


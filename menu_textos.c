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

// Função de inicialização
void MenuFechar() {
    // Criação do menu
    menuID = glutCreateMenu(Menu);
    glutAddMenuEntry("Fechar", 1);
    // Vinculação do menu ao botão direito do mouse
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
}


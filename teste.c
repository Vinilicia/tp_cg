#include <GL/glut.h>

// Variável para alternar entre Gouraud e tonalização constante
int shadeModel = GL_SMOOTH;

// Inicializa a iluminação e as propriedades dos materiais
void initLighting() {
    // Ativa a iluminação
    glEnable(GL_LIGHTING);
    
    // Fonte de luz pontual (GL_LIGHT0)
    GLfloat lightPos0[] = {1.0f, 1.0f, 1.0f, 1.0f};  // Posição da luz (x, y, z, w)
    GLfloat lightDiffuse0[] = {1.0f, 1.0f, 1.0f, 1.0f};  // Cor difusa (branco)
    GLfloat lightSpecular0[] = {1.0f, 1.0f, 1.0f, 1.0f};  // Cor especular (branco)
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular0);
    glEnable(GL_LIGHT0);
    
    // Fonte de luz spotlight (GL_LIGHT1)
    GLfloat lightPos1[] = {0.0f, 5.0f, 0.0f, 1.0f};  // Posição da luz (x, y, z, w)
    GLfloat lightDiffuse1[] = {1.0f, 0.0f, 0.0f, 1.0f};  // Cor difusa (vermelho)
    GLfloat lightDirection1[] = {0.0f, -1.0f, 0.0f};  // Direção do spotlight
    
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse1);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, lightDirection1);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0f);  // Ângulo do cone de luz
    glEnable(GL_LIGHT1);
    
    // Propriedades do material
    GLfloat matAmbient[] = {0.2f, 0.2f, 0.2f, 1.0f};  // Luz ambiente refletida
    GLfloat matDiffuse[] = {0.8f, 0.5f, 0.2f, 1.0f};  // Luz difusa refletida
    GLfloat matSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};  // Reflexão especular
    GLfloat matShininess[] = {50.0f};  // Brilho
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, matAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShininess);
}

// Função para desenhar uma cena simples
void drawScene() {
    // Limpa o buffer de cor e o buffer de profundidade
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Define o modelo de tonalização
    glShadeModel(shadeModel);
    
    // Desenha uma esfera no centro
    glutSolidSphere(1.0, 50, 50);
    
    // Troca os buffers
    glutSwapBuffers();
}

// Inicializa a janela e os parâmetros de renderização
void init() {
    // Define a cor de fundo (preto)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    // Ativa o teste de profundidade
    glEnable(GL_DEPTH_TEST);
    
    // Inicializa a iluminação
    initLighting();
}

// Função para alternar entre tonalização Gouraud e constante
void keyboard(unsigned char key, int x, int y) {
    if (key == 'g' || key == 'G') {
        shadeModel = GL_SMOOTH;  // Gouraud
    } else if (key == 'f' || key == 'F') {
        shadeModel = GL_FLAT;  // Tonalização constante
    }
    
    glutPostRedisplay();  // Redesenha a cena
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Iluminação e Tonalização");
    
    init();
    
    // Define a função de exibição e de teclado
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(keyboard);
    
    glutMainLoop();
    
    return 0;
}

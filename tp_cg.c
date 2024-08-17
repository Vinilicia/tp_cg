// Alunos: Dyego Eduardo Cássio Santos Silva -- 222050025
//         Vinícius de Souza Oliveira        -- 222050028

// Chão, mesa, taças, garrafas e cadeiras serão desenhados

#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#define CHAO 1
#define MESA 2
#define TACA 3
#define GARRAFA_COM_ROLHA 4
#define GARRAFA_SEM_ROLHA 5
#define CADEIRA 6

// 0 -> Visão perspectiva    1 -> Visão de Cima
// 2 -> Visão Frontal 
int visao = 2;

GLUquadricObj *q;

void initChao(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // Inicializa display lists do chão
    glNewList(CHAO, GL_COMPILE); // Chão
    glScalef(9.0, 0.1, 6.0);
    glTranslatef(0.0, 0.0, 0.0);
    glutWireCube(10.0); // Cria um cubo representando o chão
    glEndList();
}

void initMesa(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // Inicializa display lists da mesa
    glNewList(MESA, GL_COMPILE); // MESA

    glScalef(4.0, 0.1, 4.0);
    glutWireCube(10.0); // Cria um cubo representando a parte de cima da mesa

    // Pés da mesa, cada um é feito a partir de um cubo
        // Primeiro pé
        glPushMatrix();
        glTranslatef(-4.5, -40, 4.5);
        glScalef(0.5, 80.0, 0.5);
        glutWireCube(1.0);
        glPopMatrix();

        // Segundo pé
        glPushMatrix();
        glTranslatef(4.5, -40, 4.5);
        glScalef(0.5, 80.0, 0.5);
        glutWireCube(1.0);
        glPopMatrix();

        // Terceiro pé
        glPushMatrix();
        glTranslatef(4.5, -40, -4.5);
        glScalef(0.5, 80.0, 0.5);
        glutWireCube(1.0);
        glPopMatrix();

        // Quarto pé
        glPushMatrix();
        glTranslatef(-4.5, -40, -4.5);
        glScalef(0.5, 80.0, 0.5);
        glutWireCube(1.0);
        glPopMatrix();

    glEndList();
}

void initTaca(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    q = gluNewQuadric();
    // Inicializa display lists da Taça
    glNewList(TACA, GL_COMPILE); // Taça

    // Todas as partes da taça são feitas a partir de cilindros

    // Corpo da Taça
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.1, 0.1, 2, 10, 10);
        glPopMatrix();

    // Base da Taça
        glPushMatrix();
        glTranslatef(0, -2, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.1, 0.8, 0.5, 15, 10);
        glPopMatrix();

    // Boca da Taça
        glPushMatrix();
        glTranslatef(0, 1, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 1.5, 0.1, 1, 15, 20);
        glPopMatrix();
    
    glEndList();
}

void initGarrafaSemRolha(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    q = gluNewQuadric();
    // Inicializa display lists da Garrafa
    glNewList(GARRAFA_SEM_ROLHA, GL_COMPILE); // Garrafa sem rolha

    // Todas as partes da garrafa são feitas a partir de cilindros

    // Corpo da Garrafa
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 1.5, 1.5, 5, 20, 20);
        glPopMatrix();

    // Curva da Garrafa
        glPushMatrix();
        glTranslatef(0, 0.33, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 1.1, 1.52, 0.3, 10, 2);
        glPopMatrix();

    // Curva da Garrafa
        glPushMatrix();
        glTranslatef(0, 0.56, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.4, 1.1, 0.2, 10, 2);
        glPopMatrix();
    
    // Pescoço da Garrafa
        glPushMatrix();
        glTranslatef(0, 2.7, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.38, 0.4, 2.1, 10, 10);
        glPopMatrix();
    
    // Conteúdo cobrindo metade da garrafa
        glColor3f(0.9, 0.0, 1.0);
        glPushMatrix();
        glTranslatef(0, -2.7, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 1.2, 1.2, 2, 20, 20);
        glPopMatrix();

        glColor3f(0.9, 0.0, 1.0);
        glPushMatrix();
        glTranslatef(0, -4.7, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.01, 1.2, 0.1, 20, 20);
        glPopMatrix();

        glColor3f(0.9, 0.0, 1.0);
        glPushMatrix();
        glTranslatef(0, -2.7, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.01, 1.2, 0.1, 20, 20);
        glPopMatrix();

    glEndList();
}

void initGarrafaComRolha(void){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    q = gluNewQuadric();
    // Inicializa display lists da Garrafa
    glNewList(GARRAFA_COM_ROLHA, GL_COMPILE); // Garrafa com rolha

    // Todas as partes da garrafa são feitas a partir de cilindros

    // Corpo da Garrafa
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 1.5, 1.5, 5, 20, 20);
        glPopMatrix();

    // Curva da Garrafa
        glPushMatrix();
        glTranslatef(0, 0.33, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 1.1, 1.52, 0.3, 10, 2);
        glPopMatrix();

    // Curva da Garrafa
        glPushMatrix();
        glTranslatef(0, 0.56, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.4, 1.1, 0.2, 10, 2);
        glPopMatrix();
    
    // Pescoço da Garrafa
        glPushMatrix();
        glTranslatef(0, 2.7, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.38, 0.4, 2.1, 10, 10);
        glPopMatrix();

    // Rolha da Garrafa
        glPushMatrix();
        glTranslatef(0, 3, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.3, 0.3, 0.5, 10, 100);
        gluCylinder(q, 0.3, 0.01, 0.01, 10, 100); // Fechar a rolha
        glPopMatrix();

    // Conteúdo cobrindo toda a garrafa
        glColor3f(0.9, 0.0, 1.0);
        glPushMatrix();
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 1.2, 1.2, 4.8, 20, 20);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0, 0.4, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.4, 1.2, 0.4, 10, 6);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0, 1.6, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.3, 0.3, 1.0, 10, 10);
        glPopMatrix();

        glColor3f(0.9, 0.0, 1.0);
        glPushMatrix();
        glTranslatef(0, -4.7, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.01, 1.2, 0.1, 20, 20);
        glPopMatrix();

        glColor3f(0.9, 0.0, 1.0);
        glPushMatrix();
        glTranslatef(0, 1.6, 0);
        glRotatef(90, 1, 0, 0);
        gluCylinder(q, 0.01, 0.3, 0.05, 20, 20);
        glPopMatrix();


    glEndList();
}

void initCadeira(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    // Inicializa display lists da cadeira
    glNewList(CADEIRA, GL_COMPILE); // cadeira

    // Todas as partes da cadeira são feitas a partir de cubos

    glScalef(3.5, 0.2, 4.0);
    glutWireCube(2.0); // Cria um cubo representando o assento da cadeira

    // Pés da cadeira
        // Primeiro pé
        glPushMatrix();
        glTranslatef(-0.8, -13, 0.8);
        glScalef(0.2, 28, 0.2);
        glutWireCube(1.0);
        glPopMatrix();

        // Segundo pé
        glPushMatrix();
        glTranslatef(0.8, -13, 0.8);
        glScalef(0.2, 28, 0.2);
        glutWireCube(1.0);
        glPopMatrix();

        // Terceiro pé
        glPushMatrix();
        glTranslatef(0.8, 7, -0.8);
        glScalef(0.2, 69, 0.2);
        glutWireCube(1.0);
        glPopMatrix();

        // Quarto pé
        glPushMatrix();
        glTranslatef(-0.8, 7, -0.8);
        glScalef(0.2, 69, 0.2);
        glutWireCube(1.0);
        glPopMatrix();

    // Encosto da cadeira
    glPushMatrix();
    glScalef(0.9, 11, 0.1);
    glTranslatef(0, 2.5, -8);
    glutWireCube(2.0);
    glPopMatrix();

    glEndList();
}

void init(void)
{
    initChao();
    initMesa();
    initTaca();
    initGarrafaComRolha();
    initGarrafaSemRolha();
    initCadeira();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Mostrar Chão
        glColor3f(1.0, 1.0, 1.0);
        glLoadIdentity();
        glPushMatrix();
        glCallList(CHAO);
        glPopMatrix();

    // Mostrar Mesa
        glColor3f(1.0, 0.0, 0.0);
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(0.0, 8.6, 0.0);
        glCallList(MESA);
        glPopMatrix();

    // Mostrar Taças
        glColor3f(0.0, 0.0, 1.0);
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(8, 11.6, 16);
        glCallList(TACA);
        glPopMatrix();

        glColor3f(0.0, 0.0, 1.0);
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(14, 11.6, 14);
        glCallList(TACA);
        glPopMatrix();

        // Duas taças viradas
            glColor3f(0.0, 0.0, 1.0);
            glLoadIdentity();
            glPushMatrix();
            glTranslatef(-10, 10.2, 2.2);
            glRotatef(180, 0, 0, 1);
            glCallList(TACA);
            glPopMatrix();

            glColor3f(0.0, 0.0, 1.0);
            glLoadIdentity();
            glPushMatrix();
            glTranslatef(-10, 10.2, -2);
            glRotatef(180, 0, 0, 1);
            glCallList(TACA);
            glPopMatrix();

    // Mostrar garrafa sem Rolha
        glColor3f(0.0, 1.0, 0.0);
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(11, 14.1, 6);
        glCallList(GARRAFA_SEM_ROLHA);
        glPopMatrix();
    
    // Mostrar garrafa com Rolha
        glColor3f(0.0, 1.0, 0.0);
        glLoadIdentity();
        glPushMatrix();
        glTranslatef(-6, 14.1, 0);
        glCallList(GARRAFA_COM_ROLHA);
        glPopMatrix();

    // Mostrar Cadeiras
            glColor3f(1.0, 1.0, 0.0);
            glLoadIdentity();
            glPushMatrix();
            glTranslatef(0, 6, -18);
            glCallList(CADEIRA);
            glPopMatrix();

            glColor3f(1.0, 1.0, 0.0);
            glLoadIdentity();
            glRotatef(191, 0, 1, 0);
            glTranslatef(-6, 6, -24);
            glPushMatrix();
            glCallList(CADEIRA);
            glPopMatrix();

            glColor3f(1.0, 1.0, 0.0);
            glLoadIdentity();
            glRotatef(85, 0, 1, 0);
            glTranslatef(0, 6, -18);
            glPushMatrix();
            glCallList(CADEIRA);
            glPopMatrix();

            glColor3f(1.0, 1.0, 0.0);
            glLoadIdentity();
            glRotatef(-99, 0, 1, 0);
            glTranslatef(9, 6, -20);
            glPushMatrix();
            glCallList(CADEIRA);
            glPopMatrix();


    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    switch (visao)
    {
    case 0:
        //projeção perspectiva
        gluPerspective(60.0, (GLfloat)w/(GLfloat)h, 1.0, 100.0);
        gluLookAt(-10.0, 30.0, 50.0,0.0, 10.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 1:
        //projeção ortográfica
        glOrtho(-30.0,30.0, -30.0,30.0, 1.0,250.0);
        // vista de cima
        gluLookAt(0.0, 250.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    case 2:
        //projeção ortográfica
        glOrtho(-30.0,30.0, 0.0,30.0, 1.0,250.0);
        // vista frontal
        gluLookAt(0.0, 0.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        break;
    default:
        perror("Valor errado de visao!\n");
        exit(1);
    }
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 27: exit(0); break;
    }
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1400, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Trabalho CG");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

#include <GL/glut.h> // inclui a biblioteca glut
#include <corecrt_math.h>

// Função para desenhar quadrados
void drawSquare(float x, float y, float size) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}

// Função para desenhar triângulos
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Função para desenhar o satélite
void drawSatellite(float size, float angle) {
    float x = 0.5, y = 0.5; // coordenadas do centro do satélite
    float x1, y1, x2, y2, x3, y3; // coordenadas dos vértices dos triângulos

    // desenha os quadrados
    glColor3f(1.0, 1.0, 1.0); // branco
    drawSquare(x - size / 2, y - size / 2, size);
    glColor3f(0.0, 0.0, 0.0); // preto
    drawSquare(x - size / 2 * 0.75, y - size / 2 * 0.75, size * 0.25);

    // desenha os triângulos
    float r = size * sqrt(2) / 2; // raio da circunferência circunscrita aos triângulos
    x1 = x - r * cos(angle);
    y1 = y - r * sin(angle);
    x2 = x + r * sin(angle);
    y2 = y - r * cos(angle);
    x3 = x + r * cos(angle);
    y3 = y + r * sin(angle);
    glColor3f(0.0, 0.0, 1.0); // azul
    drawTriangle(x1, y1, x2, y2, x3, y3);
    glColor3f(0.0, 1.0, 0.0); // verde
    drawTriangle(x1, 1 - y1, x2, 1 - y2, x3, 1 - y3);
}


// Função para desenhar a cena
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpa a janela de visualização com a cor de fundo e o buffer de profundidade

    /* 
    
    // Desenha os quadrados
    glColor3f(1.0, 0.0, 0.0); // vermelho
    //drawSquare(0.1, 0.1, 0.3);
    drawSquare(0.6, 0.1, 0.3);
    drawSquare(0.1, 0.6, 0.3);
    drawSquare(0.6, 0.6, 0.2); // triangulo superior direito

    glColor3f(1.0, 0.0, 0.0); // vermelho
    glPushMatrix(); // salva a matriz de transformação atual
    glTranslatef(0.2, 0.2, 0.0); // translada para o centro do quadrado
    glRotatef(45.0, 0.0, 0.0, 1.0); // rotaciona em torno do eixo Z
    glTranslatef(-0.2, -0.2, 0.0); // translada de volta para a posição original
    drawSquare(0.1, 0.1, 0.3);
    glPopMatrix(); // restaura a matriz de transformação original

    // Desenha os triângulos
    glColor3f(0.0, 0.0, 1.0); // azul
    drawTriangle(-0.1, -0.1, 0.5, -0.1, 0.2, 0.3); //
    drawTriangle(1.1, -0.1, 0.5, -0.1, 0.8, 0.3); // Tringulo inferior Direito
    drawTriangle(-0.1, 1.1, 0.5, 1.1, 0.2, 0.5);
    drawTriangle(1.1, 1.1, 0.5, 1.1, 0.8, 0.5); // Tringulo superior Direito

    */
    

    // quadrado inferior da casa
    rectangle(100, 300, 300, 500);

    // triângulo superior da casa
    int x[3] = { 100, 200, 300 };
    int y[3] = { 300, 200, 300 };
    drawpoly(3, x, y);

    // quadrado do telhado
    rectangle(125, 200, 275, 300);

    // triângulo do telhado
    int a[3] = { 100, 250, 300 };
    int b[3] = { 200, 150, 200 };
    drawpoly(3, a, b);

    // quadrado da porta
    rectangle(175, 400, 225, 500);

    // triângulo da chaminé
    int c[3] = { 250, 150, 250 };
    int d[3] = { 200, 150, 250 };
    drawpoly(3, c, d);

   
    glFlush(); // Processa todas as operações OpenGL pendentes
}

// Função para inicialização
void init() {
    
    glClearColor(1.0, 1.0, 1.0, 0.0); // Define a cor de fundo
    glMatrixMode(GL_PROJECTION); // Define o modo de matriz para a matriz de projeção
    glLoadIdentity(); // Carrega a matriz identidade
    gluOrtho2D(0.0, 1.0, 0.0, 1.0); // Define a janela de visualização
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa a biblioteca glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Define o modo de exibição
    glutInitWindowSize(500, 500); // Define o tamanho da janela
    glutInitWindowPosition(100, 100); // Define a posição da janela
    glutCreateWindow("Quadrados e Triângulos ao Quadrado"); // Cria a janela
    init(); // Chama a função de inicialização
    glutDisplayFunc(display); // Registra a função de desenho
    glutMainLoop();   
    return 0;
}

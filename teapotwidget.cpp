#include "teapotwidget.h"
#include "ui_teapotwidget.h"
#include <GL/glut.h>

teapotWidget::teapotWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::teapotWidget)
{
    ui->setupUi(this);
}

void teapotWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void teapotWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void teapotWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(30.0, 1.0, 0.0, 0.0);

    GLfloat material_ambient[] = { 0.5, 0.2, 0.2, 1.0 };
    GLfloat material_diffuse[] = { 0.8, 0.4, 0.4, 1.0 };
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_shininess[] = { 50.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);

    glColor3f(1.0, 1.0, 1.0);
    glutSolidTeapot(1.0);

    glPopMatrix();
}


teapotWidget::~teapotWidget()
{
    delete ui;
}


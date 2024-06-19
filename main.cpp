#include "teapotwidget.h"
#include <QApplication>
#include <GL/glut.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    glutInit(&argc, argv);

    teapotWidget teapotW;
    teapotW.show();

    return a.exec();
}


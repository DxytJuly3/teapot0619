#ifndef TEAPOTWIDGET_H
#define TEAPOTWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

QT_BEGIN_NAMESPACE
namespace Ui { class teapotWidget; }
QT_END_NAMESPACE

class teapotWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    teapotWidget(QWidget *parent = nullptr);
    ~teapotWidget();

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    Ui::teapotWidget *ui;
};
#endif // TEAPOTWIDGET_H

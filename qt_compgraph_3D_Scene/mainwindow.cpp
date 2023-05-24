#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
#include <QColor>
enum Objects{ //перечесление примитивов
    cube,
    cone,
    sphere,
    pyramid
};

enum Axis{ //перечесление примитивов
    X,
    Y,
    Z,
};
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->objectTool = this->ui->GLwidget->cubemodel;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cube_button_clicked()
{
    this->ui->GLwidget->type_model = cube;
    this->objectTool = this->ui->GLwidget->cubemodel;
}

void MainWindow::on_pyramid_button_clicked()
{
    this->ui->GLwidget->type_model = pyramid;
    this->objectTool = this->ui->GLwidget->pyramidmodel;
}

void MainWindow::on_cone_button_clicked()
{
    this->ui->GLwidget->type_model = cone;
    this->objectTool = this->ui->GLwidget->conemodel;
}

void MainWindow::on_sphere_button_clicked()
{
    this->ui->GLwidget->type_model = sphere;
    this->objectTool = this->ui->GLwidget->spheremodel;
}

void MainWindow::on_cone_partition_valueChanged(int value)
{
    this->ui->GLwidget->conemodel->partition = value;
    this->ui->GLwidget->conemodel->buildCoords();
}

void MainWindow::on_pyramid_partition_valueChanged(int value)
{
    this->ui->GLwidget->pyramidmodel->partition = value;
    this->ui->GLwidget->pyramidmodel->buildCoords();
}

void MainWindow::on_cube_side_valueChanged(int value)
{
    double res = (double)value/10.0;
    this->ui->GLwidget->cubemodel->a = res;
    this->ui->GLwidget->cubemodel->buildCoords();
    2 + 3;
}

void MainWindow::on_cone_radius_valueChanged(int value)
{
    double res = (double)value / 10.0;
    this->ui->GLwidget->conemodel->r = res;
    this->ui->GLwidget->conemodel->buildCoords();
}

void MainWindow::on_pyramid_radius_valueChanged(int value)
{
    double res = (double)value / 10.0;
    this->ui->GLwidget->pyramidmodel->r = res;
    this->ui->GLwidget->pyramidmodel->buildCoords();
}

void MainWindow::on_cone_height_valueChanged(int value)
{
    double res = (double)value / 10.0;
    this->ui->GLwidget->conemodel->h = res;
}

void MainWindow::on_pyramid_height_valueChanged(int value)
{
    double res = (double)value / 10.0;
    this->ui->GLwidget->pyramidmodel->h = res;
}

void MainWindow::on_sphere_slices_valueChanged(int value)
{
    this->ui->GLwidget->spheremodel->slices = value;
    this->ui->GLwidget->spheremodel->buildCoords();
}

void MainWindow::on_sphere_stacks_valueChanged(int value)
{
    this->ui->GLwidget->spheremodel->stacks = value;
    this->ui->GLwidget->spheremodel->buildCoords();
}

void MainWindow::on_sphere_r_valueChanged(int value)
{
    this->ui->GLwidget->spheremodel->R = (double)value / 10.0;
    this->ui->GLwidget->spheremodel->buildCoords();
}

void MainWindow::on_radioButton_8_clicked()
{
    this->ui->GLwidget->type_axis = X;
}

void MainWindow::on_Y_button_clicked()
{
    this->ui->GLwidget->type_axis = Y;
}

void MainWindow::on_Z_button_clicked()
{
    this->ui->GLwidget->type_axis = Z;
}

void MainWindow::on_rotate_slider_valueChanged(int value)
{
    switch(this->ui->GLwidget->type_axis){
    case X:
        this->objectTool->rotate.x = 1;
        this->objectTool->rotate.y = 0;
        this->objectTool->rotate.z = 0;
        this->objectTool->angle = value;
        break;
    case Y:
        this->objectTool->rotate.x = 0;
        this->objectTool->rotate.y = 1;
        this->objectTool->rotate.z = 0;
        this->objectTool->angle = value;
        break;
    case Z:
        this->objectTool->rotate.x = 0;
        this->objectTool->rotate.y = 0;
        this->objectTool->rotate.z = 1;
        this->objectTool->angle = value;
        break;
    }
}

void MainWindow::on_shift_slider_valueChanged(int value)
{
    double cur;
    cur =  value - 50;
            switch(this->ui->GLwidget->type_axis){
            case X:
                this->objectTool->shift.x = cur;
                break;
            case Y:
                this->objectTool->shift.y = cur;
                break;
            case Z:
                this->objectTool->shift.z = cur;
                break;
            }
}

void MainWindow::on_scale_slider_valueChanged(int value)
{
    double cur;
    cur =  value - 50;

            switch(this->ui->GLwidget->type_axis){
            case X:
                this->objectTool->scale.x = cur;
                break;
            case Y:
                this->objectTool->scale.y = cur;
                break;
            case Z:
                this->objectTool->scale.z = cur;
                break;
            }
}

void MainWindow::on_fill_clicked()
{
    this->ui->GLwidget->type_draw = GL_FILL;
}

void MainWindow::on_unfill_clicked()
{
     this->ui->GLwidget->type_draw = GL_LINE;
}

void MainWindow::on_spot_exponent_valueChanged(int value)
{
    this->ui->GLwidget->lightmodel->spot_exponent = value;
}

void MainWindow::on_spot_cutoff_valueChanged(int value)
{
    this->ui->GLwidget->lightmodel->spot_cutoff = (float)value;
}

void MainWindow::on_ambient_color_clicked()
{
    this->ui->GLwidget->lightmodel->ambient_color =  QColorDialog::getColor(Qt::black,this);
}

void MainWindow::on_diffuse_color_clicked()
{
    this->ui->GLwidget->lightmodel->diffuse_color =  QColorDialog::getColor(Qt::black,this);
}

void MainWindow::on_specular_color_clicked()
{
    this->ui->GLwidget->lightmodel->specular_color =  QColorDialog::getColor(Qt::black,this);
}

void MainWindow::on_constant_attenuation_valueChanged(int value)
{
    this->ui->GLwidget->lightmodel->kc = (float) value / 10.0f;
}

void MainWindow::on_linear_attenuation_valueChanged(int value)
{
    this->ui->GLwidget->lightmodel->kl = (float) value / 10.0f;
}

void MainWindow::on_quadric_attenuation_valueChanged(int value)
{
    this->ui->GLwidget->lightmodel->kq = (float) value / 10.0f;
}

void MainWindow::on_local_viewer_true_clicked()
{
     this->ui->GLwidget->lightmodel->local_viewer = GL_TRUE;
}

void MainWindow::on_local_viewer_false_clicked()
{
     this->ui->GLwidget->lightmodel->local_viewer = GL_FALSE;
}

void MainWindow::on_two_side_true_clicked()
{
    this->ui->GLwidget->lightmodel->two_side_model = GL_TRUE;
}

void MainWindow::on_two_side_false_clicked()
{
    this->ui->GLwidget->lightmodel->two_side_model = GL_FALSE;
}

void MainWindow::on_global_ambient_clicked()
{
    this->ui->GLwidget->lightmodel->global_ambient =  QColorDialog::getColor(Qt::black,this);
}

void MainWindow::on_color_control_true_clicked()
{
    this->ui->GLwidget->lightmodel->model_control= GL_SEPARATE_SPECULAR_COLOR;
}

void MainWindow::on_color_control_false_clicked()
{
    this->ui->GLwidget->lightmodel->model_control= GL_SINGLE_COLOR;
}

void MainWindow::on_ambient_material_clicked()
{
    this->ui->GLwidget->lightmodel->ambient_material =  QColorDialog::getColor(Qt::black,this);
}

void MainWindow::on_diffuse_material_clicked()
{
    this->ui->GLwidget->lightmodel->diffuse_material =  QColorDialog::getColor(Qt::black,this);
}

void MainWindow::on_specular_material_clicked()
{
    this->ui->GLwidget->lightmodel->specular_material =  QColorDialog::getColor(Qt::black,this);
}

void MainWindow::on_shininess_valueChanged(int value)
{
    this->ui->GLwidget->lightmodel->shininess = value;
}

void MainWindow::on_emission_material_clicked()
{
    this->ui->GLwidget->lightmodel->emission_material =  QColorDialog::getColor(Qt::black,this);
}

void MainWindow::on_light_axis_x_clicked()
{
    this->ui->GLwidget->type_light_axis = X;
}

void MainWindow::on_light_axis_y_clicked()
{
    this->ui->GLwidget->type_light_axis = Y;
}

void MainWindow::on_light_axis_z_clicked()
{
    this->ui->GLwidget->type_light_axis = Z;
}

void MainWindow::on_shift_slider_light_valueChanged(int value)
{
    double cur;
    cur =  value - 50;
    QTextStream out(stdout);

    out << cur << endl;
            switch(this->ui->GLwidget->type_light_axis){
            case X:
                this->ui->GLwidget->lightmodel->shift.x = cur;
                break;
            case Y:
                this->ui->GLwidget->lightmodel->shift.y = cur;
                break;
            case Z:
                this->ui->GLwidget->lightmodel->shift.z = cur;
                break;
            }
}

void MainWindow::on_shift_slider_direction_valueChanged(int value)
{
    double cur;
    cur =  value - 50;
    QTextStream out(stdout);

    out << cur << endl;
            switch(this->ui->GLwidget->type_light_axis){
            case X:
                this->ui->GLwidget->lightmodel->shift_direction.x = cur;
                break;
            case Y:
                this->ui->GLwidget->lightmodel->shift_direction.y = cur;
                break;
            case Z:
                this->ui->GLwidget->lightmodel->shift_direction.z = cur;
                break;
            }
}

void MainWindow::on_front_face_clicked()
{
    this->ui->GLwidget->lightmodel->type_edge = GL_FRONT;
}

void MainWindow::on_back_face_clicked()
{
    this->ui->GLwidget->lightmodel->type_edge = GL_BACK;
}

void MainWindow::on_front_and_back_face_clicked()
{
    this->ui->GLwidget->lightmodel->type_edge = GL_FRONT_AND_BACK;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "modeltool.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_cube_button_clicked();

    void on_pyramid_button_clicked();

    void on_cone_button_clicked();

    void on_sphere_button_clicked();

    void on_cone_partition_valueChanged(int value);

    void on_pyramid_partition_valueChanged(int value);

    void on_cube_side_valueChanged(int value);

    void on_cone_radius_valueChanged(int value);

    void on_pyramid_radius_valueChanged(int value);

    void on_cone_height_valueChanged(int value);

    void on_pyramid_height_valueChanged(int value);

    void on_sphere_slices_valueChanged(int value);

    void on_sphere_stacks_valueChanged(int value);

    void on_sphere_r_valueChanged(int value);

    void on_radioButton_8_clicked();

    void on_Y_button_clicked();

    void on_Z_button_clicked();

    void on_rotate_slider_valueChanged(int value);

    void on_shift_slider_valueChanged(int value);

    void on_scale_slider_valueChanged(int value);

    void on_fill_clicked();

    void on_unfill_clicked();

    void on_spot_exponent_valueChanged(int value);

    void on_spot_cutoff_valueChanged(int value);

    void on_ambient_color_clicked();

    void on_diffuse_color_clicked();

    void on_specular_color_clicked();

    void on_constant_attenuation_valueChanged(int value);

    void on_linear_attenuation_valueChanged(int value);

    void on_quadric_attenuation_valueChanged(int value);

    void on_local_viewer_true_clicked();

    void on_local_viewer_false_clicked();

    void on_two_side_true_clicked();

    void on_two_side_false_clicked();

    void on_global_ambient_clicked();

    void on_color_control_true_clicked();

    void on_color_control_false_clicked();

    void on_ambient_material_clicked();

    void on_diffuse_material_clicked();

    void on_specular_material_clicked();

    void on_shininess_valueChanged(int value);

    void on_emission_material_clicked();

    void on_light_axis_x_clicked();

    void on_light_axis_y_clicked();

    void on_light_axis_z_clicked();

    void on_shift_slider_light_valueChanged(int value);

    void on_shift_slider_direction_valueChanged(int value);

    void on_front_face_clicked();

    void on_back_face_clicked();

    void on_front_and_back_face_clicked();

private:
    Modeltool * objectTool;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H


#include <GLUT/glut.h>
#include <iostream>

#ifndef TEAPOT_H
#define TEAPOT_H

struct Teapot {

    int size;
    double * coordinate, * rotation, * color, angle_degree;
    bool isShow;
    std::string type;

    Teapot ( const int size, const std::string type = "solid" );
    ~Teapot ();

    void render ();

    void translateX ( const double value );
    void translateY ( const double value );
    void translateZ ( const double value );

    void rotateX ( const double value );
    void rotateY ( const double value );
    void rotateZ ( const double value );

    void setColor ( const double r, const double g, const double b );

    void toggleShow ();

};

#endif

#include "teapot.h"

Teapot::Teapot ( const int size, const std::string type )
:
size ( size ),
isShow ( false ),
angle_degree ( 0 ),
type ( type ),
coordinate ( new double [ 3 ] { .0, .0, .0 } ),
rotation ( new double [ 3 ] { .0, .0, .0 } ),
color ( new double [ 3 ] { .0, .0, .0 } ) {

};

Teapot::~Teapot () {

    delete [] this -> coordinate;
    delete [] this -> rotation;
    delete [] this -> color;

};

void Teapot::render () {

    glPushMatrix ();

        glColor3d (

            this -> color [ 0 ],
            this -> color [ 1 ],
            this -> color [ 2 ]

        );

        glTranslated (

            this -> coordinate [ 0 ],
            this -> coordinate [ 1 ],
            this -> coordinate [ 2 ]
            
        );

        glRotated (

            this -> angle_degree,
            this -> rotation [ 0 ],
            this -> rotation [ 1 ],
            this -> rotation [ 2 ]

        );

        this -> type == "solid" ?
            glutSolidTeapot ( this -> size )
            :
            glutWireTeapot ( this -> size );

    glPopMatrix ();

};

void Teapot::translateX ( const double value ) {

    this -> coordinate [ 0 ] += value;

};

void Teapot::translateY ( const double value ) {

    this -> coordinate [ 1 ] += value;

};

void Teapot::translateZ ( const double value ) {

    this -> coordinate [ 2 ] += value;

};

void Teapot::rotateX ( const double value ) {

    this -> angle_degree += value;
    this -> rotation [ 0 ] = 1.0;
    // this -> rotation [ 1 ] = .0;
    // this -> rotation [ 2 ] = .0;
    // glRotated ( value, 1.0, .0, .0 );

};

void Teapot::rotateY ( const double value ) {

    this -> angle_degree += value;
    // this -> rotation [ 0 ] = .0;
    this -> rotation [ 1 ] = 1.0;
    // this -> rotation [ 2 ] = .0;
    // glRotated ( value, .0, 1.0, .0 );

};

void Teapot::rotateZ ( const double value ) {

    this -> angle_degree += value;
    // this -> rotation [ 0 ] = .0;
    // this -> rotation [ 1 ] = .0;
    this -> rotation [ 2 ] = 1.0;
    // glRotated ( value, .0, .0, 1.0 );

};

void Teapot::toggleShow () {

    this -> isShow = ! this -> isShow;

};

void Teapot::setColor ( const double r, const double g, const double b ) {

    this -> color [ 0 ] = r;
    this -> color [ 1 ] = g;
    this -> color [ 2 ] = b;

};
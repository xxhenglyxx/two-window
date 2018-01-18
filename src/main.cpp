
#include <OpenGL/gl.h>
#include "teapot.h"

// global vars
Teapot solidTeapot ( 20, "solid" );
Teapot wireTeapot ( 20, "wire" );

// forward declares
void mainMenu ( int value );
void menuOne ();
void menuTwo ();
void renderOne ();
void renderTwo ();
void windowOnChange ( int width, int height );

void rotateOne ( int value );
void rotateTwo ( int value );
void translateOne ( int value );
void translateTwo ( int value );

// main
int main ( int args_len, char ** args_context ) {

    glutInit ( &args_len, args_context );
    glutInitDisplayMode ( GLUT_SINGLE );
    glutInitWindowSize ( 800, 800 );
    glutInitWindowPosition ( 100, 100 );
    glutCreateWindow ( "Two Window - OpenGL2" );

    // models setup
    solidTeapot.translateZ ( -100.0 );
    wireTeapot.translateZ ( -100.0 );

    solidTeapot.setColor ( .0, .0, 1.0 );

    solidTeapot.toggleShow ();
    wireTeapot.toggleShow ();

    menuOne ();

    glutDisplayFunc ( renderOne );
    glutReshapeFunc ( windowOnChange );

    ////////////// second window ///////////////

    glutInitWindowSize ( 800, 800 );
    glutInitWindowPosition ( 1000, 100 );
    glutCreateWindow ( "Two Window - OpenGL2" );

    menuTwo ();

    glutDisplayFunc ( renderTwo );
    glutReshapeFunc ( windowOnChange );

    glutMainLoop ();

    return 0;

};

// definitions
void renderOne () {

    glClearColor ( .2, .3, .5, .8 );
    glClear ( GL_COLOR_BUFFER_BIT );

    if ( solidTeapot.isShow ) {

        solidTeapot.render ();

    }

    glFlush ();

};

void renderTwo () {

    glClearColor ( .2, .3, .5, .8 );
    glClear ( GL_COLOR_BUFFER_BIT );

    if ( wireTeapot.isShow ) {

        wireTeapot.render ();

    }

    glFlush ();

};

void windowOnChange ( int width, int height ) {

    glViewport ( 0, 0, width, height );
    glMatrixMode ( GL_PROJECTION );
    glLoadIdentity ();

    gluPerspective ( 60, ( GLfloat ) width / ( GLfloat ) height, .6, 200.0 );
    glMatrixMode ( GL_MODELVIEW );

};

void rotateOne ( int value ) {

    switch ( value ) {

        case 0: {

            solidTeapot.rotateX ( 10.0 );
            break;

        }

        case 1: {

            solidTeapot.rotateY ( 10.0 );
            break;

        }

        case 2: {

            solidTeapot.rotateZ ( 10.0 );
            break;

        }

    }

    glutPostRedisplay ();

};

void rotateTwo ( int value ) {

    switch ( value ) {

        case 0: {

            wireTeapot.rotateX ( 10.0 );
            break;

        }

        case 1: {

            wireTeapot.rotateY ( 10.0 );
            break;

        }

        case 2: {

            wireTeapot.rotateZ ( 10.0 );
            break;

        }

    }

    glutPostRedisplay ();

};

void translateOne ( int value ) {

    switch ( value ) {

        case 0: {

            solidTeapot.translateX ( 10.0 );
            break;

        }

        case 1: {

            solidTeapot.translateY ( 10.0 );
            break;

        }

        case 2 : {

            solidTeapot.translateZ ( 10.0 );
            break;

        }

    }

    glutPostRedisplay ();

};

void translateTwo ( int value ) {

    switch ( value ) {

        case 0: {

            wireTeapot.translateX ( 10.0 );
            break;

        }

        case 1: {

            wireTeapot.translateY ( 10.0 );
            break;

        }

        case 2 : {

            wireTeapot.translateZ ( 10.0 );
            break;

        }

    }

    glutPostRedisplay ();

};

void mainMenu ( int value ) {

};

void menuOne () {

    int rotation = glutCreateMenu ( rotateOne );

    glutAddMenuEntry ( "Rotate X", 0 );
    glutAddMenuEntry ( "Rotate Y", 1 );
    glutAddMenuEntry ( "Rotate Z", 2 );

    int translate = glutCreateMenu ( translateOne );

    glutAddMenuEntry ( "Translate X", 0 );
    glutAddMenuEntry ( "Translate Y", 1 );
    glutAddMenuEntry ( "Translate Z", 2 );

    int main = glutCreateMenu ( mainMenu );

    glutAddSubMenu ( "Rotate", rotation );
    glutAddSubMenu ( "Translate", translate );

    glutAttachMenu ( GLUT_RIGHT_BUTTON );

};

void menuTwo () {

    int rotation = glutCreateMenu ( rotateTwo );

    glutAddMenuEntry ( "Rotate X", 0 );
    glutAddMenuEntry ( "Rotate Y", 1 );
    glutAddMenuEntry ( "Rotate Z", 2 );

    int translate = glutCreateMenu ( translateTwo );

    glutAddMenuEntry ( "Translate X", 0 );
    glutAddMenuEntry ( "Translate Y", 1 );
    glutAddMenuEntry ( "Translate Z", 2 );

    int main = glutCreateMenu ( mainMenu );

    glutAddSubMenu ( "Rotate", rotation );
    glutAddSubMenu ( "Translate", translate );

    glutAttachMenu ( GLUT_RIGHT_BUTTON );

};
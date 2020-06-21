/***************************************************************************//**
 * @file util.h
 *
 * OpenGL graphics program, illustrating use of GLUT and callback functions.
 *
 * @author Eli Fox
 *         Sharvil Pai Raiker
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 2/14/2020
 ******************************************************************************/
#ifndef __UTIL_H
#define __UTIL_H

// the GLUT header automatically includes gl.h and glu.h
#include <GL/freeglut.h>
#include "event.h"

//GLUT Initializer function
void initOpenGL(int argc, char **argv);
//Function to dispatch events
void dispatch(Event *);
//Function to reshape the window
void reshape(const int w, const int h);

#endif

/***************************************************************************//**
 * @file graphics.h
 *
 * OpenGL graphics program, illustrating use of GLUT and callback functions.
 *
 * @author John M. Weiss, Ph.D.
 *         Sharvil Pai Raiker
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: PJH 9/5/2016
 *    * Added doxygen style comments: SPR 2/14/2020
 ******************************************************************************/
#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include <string>
// the GLUT header automatically includes gl.h and glu.h
#include <GL/freeglut.h>

/// Define the Black color
const float Black[] = { 0.0, 0.0, 0.0 };
/// Define the Red color
const float Red[] = { 1.0, 0.0, 0.0 };
///Define the gradient Red color
const float Dred[] = {0.5, 0.0, 0.0};
/// Define the Green color
const float Green[] = { 0.0, 1.0, 0.0 };
///Define the Gradient Green color
const float Dgreen[] = { 0.0, 0.5, 0.0 };
/// Define the Blue color
const float Blue[]  = { 0.0, 0.0, 1.0 };
///Define the gradient blue color
const float Dblue[]  = { 0.0, 0.0, 0.5 };
/// Define the Magenta color
const float Magenta[]   = { 1.0, 0.0, 1.0 };
/// Define the gradient Magenta color
const float Dmagenta[]   = { 0.5, 0.0, 0.5 };
/// Define the Cyan color
const float Cyan[]  = { 0.0, 1.0, 1.0 };
/// Define the gradient magenta color
const float Dcyan[]  = { 0.0, 0.5, 0.5 };
/// Define the Yellow color
const float Yellow[] = { 1.0, 1.0, 0.0 };
/// Define the gradient yellow color
const float Dyellow[] = { 0.5, 0.5, 0.0 };
/// Define the White color
const float White[] = { 1.0, 1.0, 1.0 };
/// Define the gradient white color
const float Dwhite[] = {0.5, 0.5, 0.5};
/// Define the gray color
const float Gray[] = {0.5, 0.5, 0.5};
/// Define the gradient gray color
const float Dgray[] = {0.25, 0.25, 0.25};
/// Define the Orange color
const float Orange[] = {1.0, 0.6, 0.2};
/// Define the gradient orange color
const float Dorange[] = {0.5, 0.3, 0.1};
/// Define the Purple color
const float Purple[] = {0.4, 0, 0.788};
/// Define the gradient purple color
const float Dpurple[] = {0.2, 0, 0.394};
/// DrawLine function
void DrawLine( float x1, float y1, float x2, float y2, const float color[] );
/// DrawRectangle function
void DrawRectangle( float x1, float y1, float x2, float y2, const float color[] );
/// DrawFilledRectangle function
void DrawFilledRectangle( float x1, float y1, float x2, float y2, const float color[] );
/// DrawEllipse function
void DrawEllipse( float xRadius, float yRadius, int x, int y, const float color[] );
/// DrawFilledEllipse function
void DrawFilledEllipse( float xRadius, float yRadius, int x, int y, const float color[] );
/// DrawTextString function
//void DrawTextString( std::string str, int x, int y, const float color[] );

#endif


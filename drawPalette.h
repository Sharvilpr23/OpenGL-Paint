/***************************************************************************//**
 * @file drawPalette.h
 *
 * @brief header file for palette functions
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

#ifndef DRAW_PALATTE
#define DRAW_PALATTE

#include<iostream>
// the GLUT header automatically includes gl.h and glu.h
#include<GL/freeglut.h>

//Palette function
void palette();
//Function to design a grid for the palette
void paletteGrid();
//Function to display the colors on the palette
void paletteColors();
//Function to display the shapes on the palette
void paletteShapes();

#endif

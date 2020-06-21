/**************************************************************************//**
 * @file ellipse.cpp
 *
 * @brief Implementation of class Ellipse
 *
 * @author: Sharvil Pai Raiker
 *
 * @par Class: CSC315 Data Structures
 *
 * @date:   Spring 2020
 *
 * @par Modifications:
 *    * Added doxygen style comments : SPR 2/21/2020
 ******************************************************************************/
#include "ellipse.h"
#include<GL/freeglut.h>
#include "graphics.h"
#include <cmath>

/**************************************************************************//**
* @author  Sharvil Pai Raiker
*
*@par Description:
*  constructor of class Ellipse
*
* @param [in]  elps - Ellipse attributes
*
* @returns Ellipse - Ellipse class instance
******************************************************************************/
Ellipse::Ellipse(Attributes &elps)
:Shape(elps)
{}

/**************************************************************************//**
* @author  Sharvil Pai Raiker
*
*@par Description:
*  constructor of class FilledEllipse
*
* @param [in]  felps - FilledEllipse attributes
*
* @returns FilledEllipse - FilledEllipse class instance
******************************************************************************/
FilledEllipse::FilledEllipse(Attributes &felps)
:Ellipse(felps)
{}

/***************************************************************************//**
 * @brief Draws an outlined ellipse
 *
 ******************************************************************************/
void Ellipse::draw() const
{
  //Calculates the x center of the ellipse
  int x_center = (shape.xStart + shape.xEnd) / 2;
  //Calculates the y center of the ellipse
  int y_center = (shape.yStart + shape.yEnd) / 2;

  //Calculates the x radius of the ellipse
  int x_radius = abs(x_center -shape. xStart);
  //Calculates the y radius of the ellipse
  int y_radius = abs(y_center - shape.yStart);

  //gets the window width
  int w = glutGet(GLUT_WINDOW_WIDTH);
  //gets the window height
  int h = glutGet(GLUT_WINDOW_HEIGHT);

//Black rectangle on the palette box
  DrawFilledRectangle(w/22 + 1, 14*h/15 + 1, w/11 - 1, h - 1, Black);
  //Creates a preview of the shape on the palette
  DrawEllipse(w/80, h/40, 3*w/44, 29*h/30, shape.borderColor);
  //Creates the requested ellipse on the canvas
  DrawEllipse(x_radius, y_radius, x_center, y_center, shape.borderColor);
}


/**************************************************************************//**
* @author  Sharvil Pai Raiker
*
*@par Description:
*  draws a filled ellipse
*
******************************************************************************/

void FilledEllipse::draw() const
{
  //Calculates the x center of the ellipse
  int x_center = (shape.xStart + shape.xEnd) / 2;
  //Calculates the y center of the ellipse
  int y_center = (shape.yStart + shape.yEnd) / 2;

//Calculates the x radius of the ellipse
  int x_radius = abs(x_center -shape. xStart);
  //Calculates the y radius of the ellipse
  int y_radius = abs(y_center - shape.yStart);

//gets the window width
  int w = glutGet(GLUT_WINDOW_WIDTH);
  //gets the window height
  int h = glutGet(GLUT_WINDOW_HEIGHT);

//Black rectangle on the palette box
  DrawFilledRectangle(w/22 + 1, 14*h/15 + 1, w/11 - 1, h - 1, Black);
  //Draws a preview on the palettes
  DrawFilledEllipse(w/80, h/40, 3*w/44, 29*h/30, shape.fillColor);
  //draws the requested filled ellipse
  DrawFilledEllipse(x_radius, y_radius, x_center, y_center, shape.fillColor);
  //Draws the outline of the ellipse on the palette
  DrawEllipse(w/80, h/40, 3*w/44, 29*h/30, shape.borderColor);
  //Draws the outline of the requested ellipse
  DrawEllipse(x_radius, y_radius, x_center, y_center, shape.borderColor);
}

/**************************************************************************//**
* @author  Sharvil Pai Raiker
*
*@par Description:
*  checks to see if the point lies in the ellipse
*
* @param [in]   x - x cordinate
* @param [in]    y - y cordninate
*
* @returns  true - if point is within shapes
* @returns  false - if point is not within shape
******************************************************************************/

bool Ellipse::contains(int x, int y) const
{
  //Calculates the x center of the ellipse
  int x_center = (shape.xStart + shape.xEnd) / 2;
  //Calculates the y center of the ellipse
  int y_center = (shape.yStart + shape.yEnd) / 2;

//Calculates the x radius of the ellipse
  int x_radius = abs(x_center -shape. xStart);
  //Calculates the y radius of the ellipse
  int y_radius = abs(y_center - shape.yStart);

  int X = x - x_center;
  int Y = y - y_center;

  float A = float (pow(X, 2)) / pow(x_radius, 2);
  float B = float (pow(Y, 2)) / pow(y_radius, 2);

  //If the point satisfies the equation
  return((A + B) <= 1);
}
/**************************************************************************//**
 * @author  Sharvil Pai Raiker
 *
 *@par Description:
 *  checks to see if x and y match with the contents of the shape
 *
 * @param [in]    x - x cordinate
 * @param [in]    y - y cordninate
 *
 * @returns  true - if point is within shapes
 * @returns  false - if point is not within shape
 ******************************************************************************/

bool FilledEllipse::contains(int x, int y) const
{
  //Calculates the x center of the ellipse
  int x_center = (shape.xStart + shape.xEnd) / 2;
  //Calculates the y center of the ellipse
  int y_center = (shape.yStart + shape.yEnd) / 2;

  //Calculates the x radius of the ellipse
  int x_radius = abs(x_center -shape. xStart);
  //Calculates the y radius of the ellipse
  int y_radius = abs(y_center - shape.yStart);

  int X = x - x_center;
  int Y = y - y_center;

  float A = float (pow(X, 2)) / pow(x_radius, 2);
  float B = float (pow(Y, 2)) / pow(y_radius, 2);

    //If the point satisfies the equation
  return((A + B) <= 1);
}

/***************************************************************************//**
 * @file shape.cpp
 *
 * @brief functions for rectangle implementations
 *
 * @author Sharvil Pai Raiker

 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 2/21/2020
 ******************************************************************************/
#include "rectangle.h"
#include<GL/freeglut.h>
#include "graphics.h"
#include <iostream>

/**************************************************************************//**
* @author  Sharvil Pai Raiker
*
*@par Description:
*  constructor for a rectangle
*
* @param [in,out]  rect     rectangle attributes
******************************************************************************/
Rectangle::Rectangle(Attributes &rect)
:Shape(rect)
{}
  /**************************************************************************//**
  * @author  Sharvil Pai Raiker
  *
  *@par Description:
  *  constructor for a filled rectangle
  *
  * @param [in]  frect     rectangle attributes
  ******************************************************************************/
FilledRectangle::FilledRectangle(Attributes &frect)
:Rectangle(frect)
{}

/**************************************************************************//**
* @author  Sharvil Pai Raiker
*
*@par Description:
*  draws the shape into the palette tab
*
******************************************************************************/
void Rectangle::draw() const
{
  int w = glutGet(GLUT_WINDOW_WIDTH);
  int h = glutGet(GLUT_WINDOW_HEIGHT);

  DrawFilledRectangle(w/22 + 1, 12*h/13 + 1, w/11 - 1, h - 1, Black);
  DrawRectangle(shape.xStart, shape.yStart,shape.xEnd, shape.yEnd,
     shape.borderColor);
  DrawRectangle(5*w/88, 57*h/60, 7*w/88, 59*h/60, shape.borderColor);
}

/**************************************************************************//**
* @author  Sharvil Pai Raiker
*
*@par Description:
*  draws the shape into the palette tab
*
******************************************************************************/
void FilledRectangle::draw() const
{
  int w = glutGet(GLUT_WINDOW_WIDTH);
  int h = glutGet(GLUT_WINDOW_HEIGHT);

  DrawFilledRectangle(w/22 + 1, 12*h/13 + 1, w/11 - 1, h - 1, Black);
  DrawFilledRectangle(shape.xStart, shape.yStart,shape.xEnd, shape.yEnd, shape.fillColor);
  DrawRectangle(shape.xStart, shape.yStart,shape.xEnd, shape.yEnd, shape.borderColor);
  DrawFilledRectangle(5*w/88, 57*h/60, 7*w/88, 59*h/60, shape.borderColor);
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
bool Rectangle::contains(int x, int y) const
{
  if(x < shape.xStart || y < shape.yStart || x > shape.xEnd || y > shape.yEnd)
  {
    return false;
  }
  return true;
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

bool FilledRectangle::contains(int x, int y) const
{
  if(x < shape.xStart || y < shape.yStart || x > shape.xEnd || y > shape.yEnd)
  {
    return false;
  }
  return true;
}

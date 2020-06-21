/***************************************************************************//**
 * @file line.cpp
 *
 * @brief functions for line implementation
 *
 * @author Sharvil Pai Raiker
            Eli Fox
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 2/21/2020
 ******************************************************************************/

#include "line.h"
#include<GL/freeglut.h>
#include "graphics.h"
#include "event.h"

/**************************************************************************//**
* @author  Sharvil Pai Raiker
*
*@par Description:
*  Constructor for Line
*
* @param [in]  line     line attributes
******************************************************************************/
Line::Line(Attributes &line)
:Shape(line)
{}

  /**************************************************************************//**
  * @author  Sharvil Pai Raiker
  *
  *@par Description:
  *  Function to draw a line in the focused shape box and on the canvas
  *
  ******************************************************************************/

void Line::draw() const
{
  int w = glutGet(GLUT_WINDOW_WIDTH);
  int h = glutGet(GLUT_WINDOW_HEIGHT);

  DrawFilledRectangle(w/22 + 1,12*h/13 + 1,w/11 - 1, h - 1, Black);
  DrawLine(shape.xStart, shape.yStart,shape.xEnd, shape.yEnd, shape.borderColor);
  DrawLine(5*w/88, 49*h/52, 7*w/88, 59*h/60, shape.borderColor);
}

/**************************************************************************//**
* @author  Sharvil Pai Raiker
*
*@par Description:
*  Checks if the point is on the line
*
* @param [in]    x - x cordinate
* @param [in]    y - y cordninate
*
* @returns  true - if point is within shapes
* @returns  false - if point is not within shape
******************************************************************************/
bool Line::contains(int x, int y) const
{
  //Calculates the slope of the line
  float slope = float(shape.yEnd - shape.yStart) / (shape.xEnd - shape.xStart);

  //Returns true if the point is on the line
  return((y - shape.yStart) == slope * (x - shape.xStart));

}

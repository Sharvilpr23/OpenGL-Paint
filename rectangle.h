/***************************************************************************//**
 * @file line.h
 *
 * @brief
 *      Contains a class for rectangle and filled rectangle
 *
 * @author Sharvil Pai Raiker
 *
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 2/21/2020
 ******************************************************************************/
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include<GL/freeglut.h>


/*!
* @brief contains data for ractangle, its attributes, how to draw, and its points.
*/
class Rectangle : public Shape
{
public:
  Rectangle(Attributes &);
  bool contains(int, int)const; /*!< function for the contents of rectangles */
  void draw() const;
};


/*!
* @brief contains data for filled Rectangle,
* its attributes, how to draw, and its points.
*/
class FilledRectangle : public Rectangle
{
public:
  FilledRectangle(Attributes &);
  bool contains(int, int) const;
  void draw() const;
};


#endif

/***************************************************************************//**
 * @file line.h
 *
 * @brief
 *      Contains a class for Line
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

#ifndef LINE_H
#define LINE_H

#include "shape.h"
#include "event.h"
#include "dragOperations.h"
#include <GL/freeglut.h>

/*!
* @brief contains data for ellipse, its attributes, how to draw, and its points.
*/
class Line : public Shape
{
public:
  Line(Attributes &);
  bool contains(int, int)const;  /*!< checks what cordinates a shape contains */
  void draw()const;
};

#endif

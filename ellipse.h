/***************************************************************************//**
 * @file ellipse.h
 *
 * @brief
 *      Contains an ellipse and filled ellipse class
 *
 * @author Eli Fox
 *         Sharvil Pai Raiker
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 2/21/2020
 ******************************************************************************/
#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"


/*!
* @brief contains data for ellipse, its attributes, how to draw, and its points.
*/
class Ellipse : public Shape
{
public:
  Ellipse(Attributes &);
  void draw() const;
  bool contains(int, int) const;
};


/*!
* @brief contains data for making a filled ellipse, its attributes,
*  how to draw, and its points.
*/
class FilledEllipse : public Ellipse
{
public:
  FilledEllipse(Attributes &);
  void draw() const;
  bool contains(int, int) const;
};

#endif

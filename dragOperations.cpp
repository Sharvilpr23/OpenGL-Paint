/**************************************************************************//**
 * @file dragOperations.cpp
 *
 * @brief Contains a function to create a shape
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
#include "dragOperations.h"
#include "shape.h"
#include "attributes.h"
#include "rectangle.h"
#include "ellipse.h"
#include "line.h"
#include "event.h"
#include <vector>
#include <GL/freeglut.h>


/***************************************************************************//**
 * @brief Pushes the shape on the vector according to the shapetype
 *
 * @param[in,out] a - struct of attributes for shapes
 * @param[in,out] shapes   - vector of shapes
 ******************************************************************************/
void createShape(Attributes &a, vector<Shape *> &shapes)
{
  if(a.shapeType == 1)
  {
    //Pushes a line on the vector
    shapes.push_back(new Line(a));
  }
  else if(a.shapeType == 2)
  {
    //Pushes a rectangle on the vector
    shapes.push_back(new Rectangle(a));
  }
  else if(a.shapeType == 3)
  {
    //Pushes a filled rectangle on the vector
    shapes.push_back(new FilledRectangle(a));
  }
  else if(a.shapeType == 4)
  {
    //Pushes an ellipse on the vector
    shapes.push_back(new Ellipse(a));
  }
  else if(a.shapeType == 5)
  {
    //Pushes a filled ellipse on the vector
    shapes.push_back(new FilledEllipse(a));
  }
}

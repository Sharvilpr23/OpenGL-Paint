/***************************************************************************//**
 * @file shape.cpp
 *
 * @brief functions for shape implementations
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
#include "shape.h"

using namespace std;

/***************************************************************************//**
 * @brief A constructor for class Shape
 *
 * @param[in] a - shape features
 *
 * @returns Shape - instance of class Shape
 ******************************************************************************/
Shape::Shape(Attributes &a)
:shape(a)
{}

//Destrutor
Shape::~Shape()
{}

  /***************************************************************************//**
   * @brief Gets the features of the shape
   *
   *
   * @returns Attributes - Returns a structure of type Attribute
   ******************************************************************************/
Attributes Shape::getShape()
{
  return shape;
}

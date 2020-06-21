/***************************************************************************//**
 * @file setShape.h
 *
 * @brief header file for set shape Class
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
#ifndef SHAPE_H
#define SHAPE_H

#include "attributes.h"

/*!
* @brief contains data nessecary to descibe and draw shapes
*/

class Shape
{
protected:
  Attributes shape; /*!< instance of shape created to attributes */
public:
   Shape(Attributes &); /*!< construct shape in realtion to attribute*/
   Attributes getShape(); /*!< get shapes attributes */
   virtual bool contains(int , int) const = 0; /*!< vitual contents of shape*/
   virtual void draw() const = 0; /*!< virtual draw shape function */
   virtual ~Shape();
};

#endif

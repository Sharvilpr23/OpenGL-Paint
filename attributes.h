/***************************************************************************//**
 * @file attributes.h
 *
 * @brief
 *      Contains a structure storing the features of the shape
 *
 * @author Eli Fox
 *         Sharvil Pai Raiker
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 2/21/2020
 *    * Added doxygen style comments: EF 2/21/2020
 ******************************************************************************/
#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

#include <iostream>

/*!
* @brief contains data that is used to describe shape features
*/
struct Attributes
{
  int xStart /*!< four corners needed to create a shape */
  , yStart /*!< four corners needed to create a shape */
  , xEnd /*!< four corners needed to create a shape */
  , yEnd; /*!< four corners needed to create a shape */

  int shapeType;  /*!< used to select shapes from palette */
  const float *borderColor; /*!< selects border color for drawn shape */
  const float *fillColor;   /*!< selected color to fill drawn shape */
  Attributes();
  Attributes(int, int, int, int, int, const float*, const float *);
  /*!< attributes needed for shape drawing */ 
};

#endif

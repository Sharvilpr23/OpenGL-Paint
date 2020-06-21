/**************************************************************************//**
 * @file attributes.cpp
 *
 * @brief Implementation of Attributes structure
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
#include "attributes.h"

/***************************************************************************//**
 * @brief A constructor for Attributes struct
 *
 *
 * @returns Attributes - Returns a structure of type Attributes
 ******************************************************************************/
Attributes::Attributes()
{}

  /***************************************************************************//**
   * @brief A constructor for Attributes struct
   *
   * @param[in] xStart - x1 of a shape
   * @param[in] yStart - y1 of a shape
   * @param[in] xEnd - x2 of a shape
   *  @param[in]  yEnd - y2 of a shape
   *  @param[in]     shapeType - Stores the type of shape
   *   @param[in]     borderColor - stores the bordercolor of the shape
   *  @param[in]     fillColor - stores the fill color of the shape
   *
   * @returns Attributes - Returns a structure of type Attributes
   ******************************************************************************/
Attributes::Attributes(int xStart, int yStart, int xEnd, int yEnd, int shapeType, const float *borderColor, const float *fillColor)
:xStart(xStart), yStart(yStart), xEnd(xEnd), yEnd(yEnd), shapeType(shapeType), borderColor(borderColor), fillColor(fillColor)
{}

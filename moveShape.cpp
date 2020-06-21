/***************************************************************************//**
 * @file moveShape.cpp
 *
 * @brief immplementation for move shape function
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
#include "moveShape.h"
#include "shape.h"
#include "dragOperations.h"
#include "attributes.h"
#include "graphics.h"
#include <vector>

using namespace std;


/*************************************************************************//**
 * @brief A function to do certain actions like clearing the buffer, printing
 *        the palette and swapping buffer associated with the event.
 *
 * @par Description
 *   The function clears the back buffer and call the palette function. The
 *   palette is printed and the buffers are swapped.
 *
 * @param [in] x-  x cordinate of mouse location
 * @param [in] y-  y cordinate of mouse location
 * @param [in,out] shapes- vector of all shapes
 *
 * @returns a - An attribute storing the features of the focused shape
 ****************************************************************************/
Attributes shapeFocus(int x, int y, vector<Shape *> &shapes)
{
  int i = 0;

    Attributes a;
  for(i = shapes.size() - 1; i >= 0 && !shapes[i]->contains(x, y); i--){}

  if(i >= 0)
  {
    //Copy the shape features
    a.xStart = shapes[i]->getShape().xStart;
    a.yStart = shapes[i]->getShape().yStart;
    a.xEnd = shapes[i]->getShape().xEnd;
    a.yEnd = shapes[i]->getShape().yEnd;
    a.shapeType = shapes[i]->getShape().shapeType;
    a.fillColor = shapes[i]->getShape().fillColor;
    a.borderColor = shapes[i]->getShape().borderColor;

    //Delete the selected shape
    shapes.erase(shapes.begin() + i);

  }
  else
  {
    //Flag case
    a.xStart = x;
    a.yStart = 0;
    a.xEnd = x;
    a.yEnd = 0;
    a.shapeType = 1;
    a.fillColor = Black;
    a.borderColor = Black;
  }
return a;
}

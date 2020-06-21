/***************************************************************************//**
 * @file setColor.cpp
 *
 * @brief immplementation for set color function
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
#include "setColor.h"
#include "graphics.h"


/**************************************************************************//**
* @author  Sharvil Pai Raiker, Eli Fox
*
*@par Description:
*  sets the color based on palette selections
*
* @param [in] x-  x cordinate of mouse location
* @param [in] y-  y cordinate of mouse location
* @param [in] w-  Width of the current window
* @param [in] h-  height of the current window
*
* @returns float  one of 20 color options or Black
*
******************************************************************************/
const float* setColor(int x, int y, int w, int h)
{
  if (x < w/20)
  {
    if (y < (h/13))
      return Gray;
    else if (y < (2*h/13))
      return Purple;
    else if (y < (3*h/13))
      return Blue;
    else if (y < (4*h/13))
      return Cyan;
    else if (y < (5*h/13))
      return Green;
    else if (y < (6*h/13))
      return Yellow;
    else if (y < (7*h/13))
      return Orange;
    else if (y < (8*h/13))
      return Red;
    else if (y < (9*h/13))
      return Magenta;
    else if (y < (10*h/13))
      return White;
  }
  else if (x < (w/10))
  {
    //returns darker versions of the colors
    if (y < (h/13))
      return Dgray;
    else if (y < (2*h/13))
      return Dpurple;
    else if (y < (3*h/13))
      return Dblue;
    else if (y < (4*h/13))
      return Dcyan;
    else if (y < (5*h/13))
      return Dgreen;
    else if (y < (6*h/13))
      return Dyellow;
    else if (y < (7*h/13))
      return Dorange;
    else if (y < (8*h/13))
      return Dred;
    else if (y < (9*h/13))
      return Dmagenta;
    else if (y < (10*h/13))
      return Dwhite;
  }
  return Black;
}

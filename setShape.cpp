/***************************************************************************//**
 * @file setShape.cpp
 *
 * @brief immplementation for set shape function
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
#include "setShape.h"

/**************************************************************************//**
* @author  Sharvil Pai Raiker, Eli Fox
*
*@par Description:
*  sets the shape to be drawn based on palette selection
*
* @param [in] x-  x cordinate of mouse location
* @param [in] y-  y cordinate of mouse location
* @param [in] w-  Width of the current window
* @param [in] h-  height of the current window
*
* @returns 1-10   number to identify which shape was selected
*
******************************************************************************/
int setShape(int x, int y, int w, int h)
{
    if(x < (w/22))
    {
      //Outlined ellipse
      if (y > (10 * h/13) && y < (11 * h/13))
      {
        return 4;
      }
      //outlined rectangle
      else if (y > (11*h/13) && y < (12*h/13))
      {
        return 2;
      }
      //line
      else if (y > (12*h/13))
      {
        return 1;
      }
    }
    if (x < (w/11))
    {
      //filled ellipse
      if(y > (10*h /13) && y < (11*h/13))
      {
        return 5;
      }
    }
    //filled rectangle
return 3;
}

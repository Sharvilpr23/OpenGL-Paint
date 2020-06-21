/**************************************************************************//**
 * @file drawPalette.cpp
 *
 * @brief Function to print the palette to the screen
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

#include "drawPalette.h"
#include "graphics.h"
using namespace std;

/*************************************************************************//**
 * @brief A function to print the palette to the window
 *
 * @par Description
 *   The function calls 3 function that together creates the palette
 *
 ****************************************************************************/
void palette()
{
  //Calls the paletteColor() function
 paletteColors();
 //Calls the paletteGrid() function
 paletteGrid();
 //Calls the paletteShapes functin
 paletteShapes();
}

/*************************************************************************//**
 * @brief A function display the available shapes to the palette
 *
 * @par Description
 *   The function uses glut draw functions to print the shapes to the palette
 *
 ****************************************************************************/
void paletteShapes()
{
  //Stores the width of the window
  int x = glutGet(GLUT_WINDOW_WIDTH);
  //Stores the height of the window
  int y = glutGet(GLUT_WINDOW_HEIGHT);

  //Draw a line
  DrawLine(x/88,49*y/52,3*x/88,51*y/52, White);
  //Draw a rectangle outline
  DrawRectangle(x/88, 45*y/52, 3*x/88 , 47*y/52, White);
  //Draw a filled rectangle
  DrawFilledRectangle(5*x/88, 45*y/52, 7*x/88, 47*y/52 , White );
  //Draw an ellipse outline
  DrawEllipse(x/64, y/32, x/44, 21*y/26, White);
  //Draw a filled ellipse
  DrawFilledEllipse(x/64, y/32, 3*x/44, 21*y/26, White);
}

/*************************************************************************//**
 * @brief A function to display the available colors to the palette
 *
 * @par Description
 *   The function uses glut draw functions to print the colors to the palette
 *
 ****************************************************************************/
void paletteColors()
{
  //Stores the width of the window
  int x = glutGet(GLUT_WINDOW_WIDTH);
  //Stores the height of the window
  int y = glutGet(GLUT_WINDOW_HEIGHT);
  //Draws a gray filled rectangle
  DrawFilledRectangle(0, 0 , x/22 , y/13 , Gray);
  //Draws a gradient gray filled rectangle
  DrawFilledRectangle(x/22, 0 , x/11 , y/13 , Dgray);
    //Draws a Purple filled rectangle
  DrawFilledRectangle(0, y/13 , x/22 , 2*y/13 , Purple );
    //Draws a gradient purple filled rectangle
  DrawFilledRectangle(x/22, y/13 , x/11 , 2*y/13 , Dpurple );
    //Draws a blue filled rectangle
  DrawFilledRectangle(0, 2*y/13 , x/22 , 3*y/13 , Blue );
    //Draws a gradient blue filled rectangle
  DrawFilledRectangle(x/22, 2*y/13 , x/11 , 3*y/13 , Dblue );
    //Draws a cyan filled rectangle
  DrawFilledRectangle(0, 3*y/13 , x/22 , 4*y/13 , Cyan );
    //Draws a gradient cyan filled rectangle
  DrawFilledRectangle(x/22, 3*y/13 , x/11 , 4*y/13 , Dcyan );
    //Draws a green filled rectangle
  DrawFilledRectangle(0, 4*y/13 , x/22 , 5*y/13 , Green );
    //Draws a gradient green filled rectangle
  DrawFilledRectangle(x/22, 4*y/13 , x/11 , 5*y/13 , Dgreen );
    //Draws a yellow filled rectangle
  DrawFilledRectangle(0, 5*y/13 , x/22 , 6*y/13 , Yellow );
    //Draws a gradient yellow filled rectangle
  DrawFilledRectangle(x/22, 5*y/13 , x/11 , 6*y/13 , Dyellow );
    //Draws a orange filled rectangle
  DrawFilledRectangle(0, 6*y/13 , x/22, 7*y/13 , Orange );
    //Draws a gradient orange filled rectangle
  DrawFilledRectangle(x/22, 6*y/13 , x/11 , 7*y/13 , Dorange );
    //Draws a red filled rectangle
  DrawFilledRectangle(0,7*y/13, x/22, 8*y/13, Red);
    //Draws a gradient red filled rectangle
  DrawFilledRectangle(x/22 ,7*y/13, x/11, 8*y/13, Dred);
    //Draws a magenta filled rectangle
  DrawFilledRectangle(0, 8*y/13 , x/22, 9*y/13 , Magenta );
    //Draws a gradient magenta filled rectangle
  DrawFilledRectangle(x/22, 8*y/13 , x/11 , 9*y/13 , Dmagenta );
    //Draws a white filled rectangle
  DrawFilledRectangle(0,9*y/13, x/22, 10*y/13, White);
    //Draws a gradient white filled rectangle
  DrawFilledRectangle(x/22 ,9*y/13, x/11, 10*y/13, Dwhite);
}

/*************************************************************************//**
 * @brief A function to display the grid for the palette
 *
 * @par Description
 *   The function uses glut draw functions to print the grid for the palette
 *
 ****************************************************************************/
void paletteGrid()
{
  //Stores the width of the window
  int x = glutGet(GLUT_WINDOW_WIDTH);
  //Stores the height of the window
  int y = glutGet(GLUT_WINDOW_HEIGHT);

  //Draws a white line
  DrawLine(x/22,0,x/22,y,White);
  //Draws a black line
  DrawLine(x/22, 9*y/13, x/22, 10*y/13, Black);
  //Draws a white line
  DrawLine(x/11,0,x/11,y,White);
  //Draws a white line
  DrawLine(0,0,x/11,0,White);
  //Draws a white line
  DrawLine(0,y/13,x/11,y/13,White);
  //Draws a white line
  DrawLine(0,2*y/13,x/11,2*y/13,White);
    //Draws a white line
  DrawLine(0,3*y/13,x/11,3*y/13,White);
    //Draws a white line
  DrawLine(0,4*y/13,x/11,4*y/13,White);
    //Draws a white line
  DrawLine(0,5*y/13,x/11,5*y/13,White);
    //Draws a white line
  DrawLine(0,6*y/13,x/11,6*y/13,White);
    //Draws a white line
  DrawLine(0,7*y/13,x/11,7*y/13,White);
    //Draws a white line
  DrawLine(0,8*y/13,x/11,8*y/13,White);
    //Draws a white line
  DrawLine(0,9*y/13,x/11,9*y/13,White);
    //Draws a white line
  DrawLine(0,10*y/13,x/11,10*y/13,White);
    //Draws a white line
  DrawLine(0,11*y/13,x/11,11*y/13,White);
    //Draws a white line
  DrawLine(0,12*y/13,x/11,12*y/13,White);
}

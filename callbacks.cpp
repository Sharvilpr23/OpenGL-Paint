/**************************************************************************//**
 * @file callbacks.cpp
 *
 * @brief Implementation of callback functions
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
#include "callbacks.h"
#include "drawPalette.h"
#include "attributes.h"

/***************************************************************************//**
 * @brief A callback function for display
 *
 ******************************************************************************/
void display()
{
  //Dispatches a display event
   dispatch(new DisplayEvent());
}

/***************************************************************************//**
 * @brief A callback function for handling keyboard input
 *
 * @param[in] key - the key that was pressed
 * @param[in] x   - the x-coordinate when the key was pressed
 * @param[in] y   - the y-coordinate when the key was pressed
 ******************************************************************************/
void keyboard(unsigned char key, int x, int y)
{
  //Dispatches a keyboard event
   dispatch(new KeyboardEvent(key, x, y));
}


/***************************************************************************//**
 * @brief A callback function for handling mouse click events
 *
 * @param[in] button - the mouse button pushed
 * @param[in] state  - the state of the button (i.e. GLUT_UP, GLUT_DOWN)
 * @param[in] x      - the x-coordinate when the button is pressed
 * @param[in] y      - the y-coordinate when the button is pressed
 ******************************************************************************/
void mouse(int button, int state, int x, int y)
{
  //Dispatches a mouse event
   dispatch(new MouseEvent(button, state, x, y));
}

/***************************************************************************//**
 * @brief A callback function for handling reshape events
 *
 * @param[in] w      - the width of the newly reshaped window
 * @param[in] h      - the height of the newly reshaped window
 ******************************************************************************/
void reshape(const int w, const int h)
{
    glMatrixMode( GL_PROJECTION );      // use an orthographic projection
    glLoadIdentity();                   // initialize transformation matrix
    gluOrtho2D( 0.0, w, 0.0, h );       // make OpenGL coordinates
    glViewport( 0, 0, w, h );           // the same as the screen coordinates
}

/***************************************************************************//**
 * @brief A callback function for handling mouse drag events
 *
 * @param[in] x      - current x - cordinate of mouse
 * @param[in] y      - current y - cordinate of mouse
 ******************************************************************************/
void motion(int x, int y)
{
  //Dispatches a flagged mouse event to indicate drag
    dispatch(new MouseEvent(-1, -1, x, y));
}

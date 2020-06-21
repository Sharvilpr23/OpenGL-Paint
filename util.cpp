/**************************************************************************//**
 * @file util.cpp
 *
 * @brief OpenGL graphics program, illustrating use of GLUT and callback
 * functions.
 *
 * @author: Eli Fox
 *          Sharvil Pai Raiker
 *
 * @par Class:
 * CSC315 Data Structures and Algorithm Analysis
 *
 * @date:   Spring 2020
 *
 * @par Modifications:
 *    * Added doxygen style comments : SPR 02/14/2020
 ******************************************************************************/

#include "util.h"
#include "callbacks.h"
#include "shape.h"

/*************************************************************************//**
 * @brief A function to call the usual set of initialization routines
 *
 * @par Description
 *   * Initializes the glut system
 *   * Sets the initial display mode
 *   * Sets the initial window size
 *   * Sets the initial window position
 *   * Creates the window and sets the window title
 *   * Sets the DisplayFunc callback
 *   * Sets the KeyboardFunc callback
 *   * Sets the MouseFunc callback
 *
 * @param[in] argc      - Number of Command line arguments
 * @param[in] argv - The commandline arguments
 *
 ****************************************************************************/
void initOpenGL(int argc, char **argv)
{
   // Initialize GLUT (OpenGL Utility Toolkit)
   glutInit(&argc, argv);

   // Set the display mode [double buffering, 4-channel red,green,blue,alpha]
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

   // Make the window 100 columns x 100 rows of pixels
   glutInitWindowSize(100, 100);

   // Start the window at 100 pixels down and 100 pixels right of upper-left
   glutInitWindowPosition(100,100);

   // Give the window a title
   glutCreateWindow("paint");

 // Set the function to call for reshaping of the window
   glutReshapeFunc(reshape);
   // Set the function for the glutMainLoop to call when refreshing window
   glutDisplayFunc(display);
   // Set the function to call in response to keyboard events
   glutKeyboardFunc(keyboard);
    // Set the function to call for mouse events
   glutMouseFunc(mouse);

   glutMotionFunc(motion);
}

/*************************************************************************//**
 * @brief A function to dispatch all the events from the event vector
 *
 * @par Description
 *   This function dispatches all the events stored in the static event array
 *
 * @param[in] event - An object of class Event
 *
 ****************************************************************************/
void dispatch(Event *event)
{
  //Vector storing all the events
   static vector<Event *> events;
   static vector<Shape *> shapes;

  //calls teh doAction function of each event
   event->doAction(events, shapes);
}

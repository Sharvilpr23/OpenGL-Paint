/*************************************************************************//**
 * @file
 *
 * @mainpage Paint Program
 *
 * @section course_section Course Information
 *
 * @authors Sharvil Pai Raiker, Eli Fox
 *
 * @date Feb. 14 2020
 *
 * @par Course:
 *      CSC 315- Spring 2020
 *
 * @details This program creates a paint progam similar to ms Paint.
 *  It is capable of creating a number of shapes, either filled or unfilled
 *  as well as lines. colors can also be selected, to color the outline, or fill
 *  color for the shapes. The shapes and color can be selected from the palette
 *  menu on the left. the shapes can also be be seelcted with the right click
 *  button. pressing d will delete the top object, pressing c will clear the
 *  screen. Pressing "esc" or "q" will exit the program.
 *    Creates a window, tracks mouse and keyboard events
 *
 * @section compile_section Compiling and Usage
*
* @par Compiling Instructions:
*      None
*
* @par Usage:
  @verbatim
  ./main

  @endverbatim
*
* @section todo_bugs_modification_section Todo, Bugs, and Modifications
*           Found a weird bug when I make the window very small and
*           then try to draw a filled rectangle
*
* @par
*    None
*
* @par Modifications and Development Timeline:

  <a href =
  "https://gitlab.mcs.sdsmt.edu/7509329/csc315_spring2020_project1/commits/master">
  Click here for commit log</a>


 ****************************************************************************/

#include "util.h"

/*************************************************************************//**
 * @brief main function
 *
 * @param[in] argc - number of command line arguments
 * @param[in] argv - array of C strings representing the command line
 *  arguments
 *
 * @return main does not return due to the glutMainLoop function not
 * returning
 ****************************************************************************/
int main(int argc, char** argv)
{
   // Call the glut functions to initialize everythin
   initOpenGL(argc, argv);

   //Runs the glut Main loop
   glutMainLoop();

   return 0;
}

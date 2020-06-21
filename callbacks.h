/***************************************************************************//**
 * @file callbacks.h
 *
 * @brief
 *      Header file for all the callbackk functions
 *
 * @author Eli Fox
 *         Sharvil Pai Raiker
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: EF 2/14/2020
 *    * Added doxygen style comments: SPR 2/14/2020
 ******************************************************************************/

#ifndef __CALLBACKS_H
#define __CALLBACKS_H
#include <iostream>
#include "util.h"

//Display Callback functions
void display();
//Keyboard Callback function
void keyboard(unsigned char, int, int);
//Mouse callback function
void mouse(int button, int state, int x, int y);
//Motion callback function
void motion(int x, int y);

#endif

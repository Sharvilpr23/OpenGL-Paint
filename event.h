/***************************************************************************//**
 * @file event.h
 *
 * @brief Contains event class
 *
 * @author Eli Fox
 *         Sharvil Pai Raiker
 * @par Class
 *    CSC315 Data Structures
 * @date Spring 2020
 *
 * Modifications:
 *    * Added doxygen style comments: SPR 2/14/2020
 ******************************************************************************/
#ifndef _EVENT_H_
#define _EVENT_H_
#include <iostream>
#include <GL/freeglut.h>
#include <sstream>
#include <vector>
#include "shape.h"

using namespace std;

/// A mnemonic name for the ascii value of the escape key
#define ESCAPE_KEY 27

/***************************************************************************//**
 * @class Event
 ******************************************************************************/
 /*!
 * @brief contains data for events. actions and drawing
 */
class Event
{
public:
   //Pure virtual function to create new events
   virtual void doAction(vector<Event *>&, vector<Shape *>&) = 0; /*!< virtual
   function to do actions with shapes and Events */
   virtual void draw() = 0; /*!< virtual function to draw new shapes */
   //Event Destructor
   virtual ~Event();
};

/***************************************************************************//**
 * @class MouseEvent
 ******************************************************************************/
 /*!
 * @brief contains data for events. related to the display
 */
class DisplayEvent : public Event
{
public:
  //Function to add DisplayEvents to Event vector
   void doAction(vector<Event *>&, vector<Shape *>&);

   void draw(); /*!< function to draw in display */
};

/***************************************************************************//**
 * @class KeyboardEvent
 ******************************************************************************/
 /*!
 * @brief contains data for events. related to the keyboard
 */
class KeyboardEvent : public Event
{
   unsigned char key; //Store the key pressed
   int x, y; //Stores the position of the key pressed
public:

   KeyboardEvent(unsigned char, int, int); /*!< constructor for keyboard event */
   //Function to add Keyboard Events to the Event vector
   void doAction(vector<Event *>&, vector<Shape *>&);
   void draw();
};

/***************************************************************************//**
 * @class MouseEvent
 ******************************************************************************/
 /*!
 * @brief contains data for events. related to the mouse
 */
class MouseEvent : public Event
{
   int button; //Stores the mouse button that is clicked
   int state; //Stores the state of the button clicked
   int x, y; //Stores the position of the button clicked
public:
  //Constructor for MouseEvent
   MouseEvent(int, int, int, int); /*!< mouse events and mouse buttons */

   void doAction(vector<Event *>&,
      vector<Shape *>&); /*!< function to add mouse events to the event vector */
   void draw();  /*!< function to draw a shape */
};

#endif

/**************************************************************************//**
 * @file event.cpp
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

#include "event.h"
#include "moveShape.h"
#include "drawPalette.h"
#include "setColor.h"
#include "setShape.h"
#include <iostream>
#include "graphics.h"
#include "shape.h"
#include "attributes.h"
#include "line.h"
#include "rectangle.h"
#include "dragOperations.h"

//Destructor
Event::~Event() {}

/*************************************************************************//**
 * @brief A function to do certain actions like clearing the buffer, printing
 *        the palette and swapping buffer associated with the event.
 *
 * @par Description
 *   The function clears the back buffer and call the palette function. The
 *   palette is printed and the buffers are swapped.
 *
 * @param[in,out] events - a vector of all the events
 * @param [in,out] shapes - a vector of drawn shapes
 *
 ****************************************************************************/
void DisplayEvent::doAction(vector<Event *>&events, vector<Shape *> &shapes)
{
  //Clears the back buffer
   glClear(GL_COLOR_BUFFER_BIT);
   //calls the palette function



   for (Event *e : events)
      e->draw();

   for (Shape *s : shapes)
      s->draw();

   palette();

   //swaps the buffers
   glutSwapBuffers();
}

void DisplayEvent::draw()
{}

void KeyboardEvent::draw()
{}

void MouseEvent::draw()
{}

//Constructor for the class KeyboardEvent
KeyboardEvent::KeyboardEvent(unsigned char k, int x, int y) : key(k), x(x), y(y) {}

/*************************************************************************//**
 * @brief A function to exit the program when the user presses the escape key.
 *
 * @par Description
 *   The function checks if the user pressed key is the escape key. If it is,
 *   it exits the program
 *
 * @param[in,out] events - a vector of all the events
 * @param [in,out] shapes - a vector of drawn shapes
 *
 ****************************************************************************/
void KeyboardEvent::doAction(vector<Event *>& events, vector<Shape *> &shapes)
{
  //if the user pressed escape of q key
  if(key == ESCAPE_KEY || key == 'q')
  {
    //Delete all the events
    for (Event *e : events)
       delete e;

       //Delete all the shapes
    for (Shape *s : shapes)
       delete s;
       //Clear the vectors from pointers
    shapes.clear();
    events.clear();
    exit(0); //exit the program
  }
  //If the user presses 'c'
  else if(key  == 'c')
  {
    //Clear the buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //Delete all the shapes
    for (Shape *s : shapes)
       delete s;
       //empty the vector
    shapes.clear();
  }
  //If the user presses d
  else if(key == 'd')
  {
    //If the vector is not empty
    if(shapes.size() > 0){
      //delete the last elemet
      shapes.erase(shapes.end() - 1);
    }
  }
   events.push_back(this); //Push this event on the vector
   glutPostRedisplay();
}

//Constructor for class MouseEvent
MouseEvent::MouseEvent(int b, int s, int x, int y)
: button(b), state(s), x(x), y(y)
{}

/*************************************************************************//**
 * @brief A function to push the mouse events on to the event vector.
 *
 * @par Description
 *   The function pushes the mouseevent created onto the events vector and
 *   then calls the glutPostRedisplay function.
 *
 * @param[in,out] events - a vector of all the events
 * @param [in,out] shapes - a vector of drawn shapes
 *
 ****************************************************************************/
void MouseEvent::doAction(vector<Event *>&events, vector<Shape *>&shapes)
{
  static bool flag = false;

  static int xStart = 0, yStart  = 0;
  int drag = -1;
  static int prev_x = 0, prev_y = 0;
  static int x1Change = 0, y1Change = 0, x2Change = 0, y2Change = 0;

  int w = glutGet(GLUT_WINDOW_WIDTH);
  int h = glutGet(GLUT_WINDOW_HEIGHT);

  int y = h - this->y;
  static const float *currentFillColor = White;
  static const float *currentBorderColor = White;
  static int shapeType = 0;

  static bool isDrag = false;
;

 if(x < (w/11))
 {
   if (y < (10 * h / 15))
   {
      if(!isDrag)
      {
         if(state == GLUT_DOWN)
         {
            if(button == GLUT_LEFT_BUTTON)
            {
              currentBorderColor = setColor(x, y, w , h);
            }
            else if (button == GLUT_RIGHT_BUTTON)
            {
              currentFillColor = setColor(x, y, w, h);
            }
         }
      }
    }
   else if((x < (w/22) && (y > (10* h/13))) || (x < (w/11) && (y < 12*h/13) && (y > 10 *h/13)))
   {
     if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
     {
     shapeType = setShape(x, y, w, h);
     }
   }
 }
 else if (x > (w/11))
 {
    if(button == GLUT_LEFT_BUTTON || (button == drag && !flag))
    {
      if(state == GLUT_DOWN)
      {
        isDrag = true;
        xStart = x;
        yStart = y;
        Attributes a(xStart, yStart, xStart, yStart, shapeType, currentBorderColor, currentFillColor);
        createShape(a, shapes);
      }
      else if(state == -1)
      {
        if(isDrag && shapes.size() > 0)
        {
            int x1 = xStart;
            int y1 = yStart;
            int x2 = this->x;
            int y2 = y;
            shapes.pop_back();
            if(shapeType == 2 || shapeType == 3)
            {
              if(x1 > x2)
              {
                swap(x1, x2);
              }
              if(y1 > y2)
              {
                swap(y1, y2);
              }
              Attributes a(x1, y1, x2, y2, shapeType, currentBorderColor, currentFillColor);
              createShape(a, shapes);
            }
            else
            {
              Attributes a(x1, y1, x2, y2, shapeType, currentBorderColor, currentFillColor);
              createShape(a, shapes);
            }
            //orientation(shapeType, x1, y1, x2, y2);
            //preview(shapeType, w, h, currentFillColor, currentBorderColor);

        }
      }
      else if(state == GLUT_UP)
      {
        if(isDrag && shapes.size() > 0)
        {
          int x1 = xStart;
          int y1 = yStart;
          int x2 = this->x;
          int y2 = y;
          shapes.pop_back();
          //orientation(shapeType, x1, y1, x2, y2);
          if(shapeType == 2 || shapeType == 3)
          {
            if(x1 > x2)
            {
              swap(x1, x2);
            }
            if(y1 > y2)
            {
              swap(y1, y2);
            }
            Attributes a(x1, y1, x2, y2, shapeType, currentBorderColor, currentFillColor);
            createShape(a, shapes);
          }
          else
          {
            Attributes a(x1, y1, x2, y2, shapeType, currentBorderColor, currentFillColor);
            createShape(a, shapes);
          }
          isDrag = false;
        }
      }
    }
    else if(button == GLUT_RIGHT_BUTTON || (button == drag && flag))
    {
      if(state == GLUT_DOWN)
      {
        Attributes a;
        a = shapeFocus(x, y, shapes);
        if((x - a.xStart) || (a.xEnd - x))
        {
          xStart = a.xStart;
          yStart = a.yStart;
          x1Change = x - a.xStart;
          y1Change = y - a.yStart;
          x2Change = a.xEnd - x;
          y2Change = a.yEnd - y;
          currentBorderColor = a.borderColor;
          currentFillColor = a.fillColor;
          createShape(a, shapes);
          isDrag = true;
          flag = true;
          prev_x = x;
          prev_y = y;
        }
      }
      else if(state == -1)
      {
        if(isDrag && shapes.size() > 0)
        {
          cout << "Here" << endl;
          int x1 = x - x1Change + (x - prev_x);
          int x2 = x + x2Change + (x - prev_x);
          int y1 = y - y1Change + (y - prev_y);
          int y2 = y + y2Change + (y - prev_y);
          shapeType = shapes[shapes.size()  - 1]->getShape().shapeType;
          shapes.pop_back();
          //orientation(shapeType, x1, y1, x2, y2);
          //preview(shapeType, w, h, currentFillColor, currentBorderColor);
          if(shapeType == 2 || shapeType == 3)
          {
            if(x1 > x2)
            {
              swap(x1, x2);
            }
            if(y1 > y2)
            {
              swap(y1, y2);
            }
            Attributes a(x1, y1, x2, y2, shapeType, currentBorderColor, currentFillColor);
            createShape(a, shapes);
          }
          else
          {
            Attributes a(x1, y1, x2, y2, shapeType, currentBorderColor, currentFillColor);
            createShape(a, shapes);
          }

        }
      }
      else if(state == GLUT_UP)
      {
        if(isDrag && shapes.size() > 0)
        {
            shapeType = shapes[shapes.size()  - 1]->getShape().shapeType;
            shapes.pop_back();
            int x1 = x - x1Change + (x - prev_x);
            int x2 = x + x2Change + (x - prev_x);
            int y1 = y - y1Change + (y - prev_y);
            int y2 = y + y2Change + (y - prev_y);
            if(shapeType == 2 || shapeType == 3)
            {
              if(x1 > x2)
              {
                swap(x1, x2);
              }
              if(y1 > y2)
              {
                swap(y1, y2);
              }
              Attributes a(x1, y1, x2, y2, shapeType, currentBorderColor, currentFillColor);
              createShape(a, shapes);
            }
            else
            {
              Attributes a(x1, y1, x2, y2, shapeType, currentBorderColor, currentFillColor);
              createShape(a, shapes);
            }
            isDrag = false;
            flag = false;
            x1Change = 0;
            x2Change = 0;
            y1Change = 0;
            y2Change = 0;
        }
      }
    }
 }
 prev_x = x;
 prev_y = y;

  events.push_back(this);
  glutPostRedisplay();
}

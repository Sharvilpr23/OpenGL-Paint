/***************************************************************************//**
 * @file dragOperations.h
 *
 * @author Sharvil Pai Raiker
 *                  Eli Fox
 *
 *@brief header file for creating shapes
 ******************************************************************************/
#ifndef DRAG_OPERAIONS_H
#define DRAG_OPERAIONS_H

#include "shape.h"
#include "attributes.h"
#include "event.h"
#include "graphics.h"
#include <vector>

//Function to create a shape
void createShape(Attributes &a, vector<Shape *> &shapes);

#endif

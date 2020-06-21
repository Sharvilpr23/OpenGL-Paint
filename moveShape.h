/***************************************************************************//**
 * @file moveShape.h
 *
 * @brief header file for shape focus, which is used to move current shape
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
#ifndef MOVE_SHAPE_H
#define MOVE_SHAPE_H

#include "shape.h"
#include "rectangle.h"
#include "event.h"
#include "attributes.h"
#include <vector>

Attributes shapeFocus(int x, int y, vector<Shape *> &shapes);

#endif

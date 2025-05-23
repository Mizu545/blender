/* SPDX-FileCopyrightText: 2023 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup freestyle
 */

#pragma once

#include "../BPy_ViewVertex.h"

#include "../../../view_map/ViewMap.h"

///////////////////////////////////////////////////////////////////////////////////////////

extern PyTypeObject TVertex_Type;

#define BPy_TVertex_Check(v) (PyObject_IsInstance((PyObject *)v, (PyObject *)&TVertex_Type))

/*---------------------------Python BPy_TVertex structure definition----------*/
typedef struct {
  BPy_ViewVertex py_vv;
  Freestyle::TVertex *tv;
} BPy_TVertex;

///////////////////////////////////////////////////////////////////////////////////////////

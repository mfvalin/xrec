/* RMNLIB - Library of useful routines for C and FORTRAN programming
 * Copyright (C) 1975-2001  Division de Recherche en Prevision Numerique
 *                          Environnement Canada
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation,
 * version 2.1 of the License.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include <wgl_x.h>

f77name(wglcmx)(left, bottom, right, top)
float *left, *bottom, *right, *top;
{
   wglcmx(*left, *bottom, *right, *top);
   }

/**
******
**/

wglcmx(left, bottom, right, top)
float left, bottom, right, top;
{
   XRectangle rect;
   int ileft, ibottom, iright, itop,w,h;

   wglgwz(&w,&h);
   wglxai(&ileft, &ibottom, left, bottom);
   wglxai(&iright, &itop,   right, top);

   rect.x = (short) ileft;
   rect.y = (short) (h - itop);
   rect.width = (unsigned int) (iright - ileft);
   rect.height = (unsigned int) (itop - ibottom);
   
   XSetClipRectangles(wglDisp, wglLineGC, 0, 0, &rect, 1, Unsorted);
   XSetClipRectangles(wglDisp, wglFillGC, 0, 0, &rect, 1, Unsorted);
   }
/*
    CIieeefp: x87FPUcmds.h
    Copyright (C) 2003-2004, 2007  Macaulay Institute

    This file is part of CIieeefp, a partial implementation of the rounding
    control and exception checking IEEE routines for Cygwin on an Intel
    platform.

    CIieeefp is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    CIieeefp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details. (LICENCE file in
    this directory.)

    You should have received a copy of the GNU Lesser General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Contact information:
      Gary Polhill,
      Macaulay Institute, Craigiebuckler, Aberdeen, AB15 8QH. United Kingdom
      g.polhill@macaulay.ac.uk
*/

/* This file contains declarations for the functions in X87FPUcmds.c
 */

#ifndef X87FPUCMDS_H
#define X87FPUCMDS_H

#include "x87FPUsys.h"

extern x87FPU_status_word x87FPU_fstsw(void);
extern x87FPU_control_word x87FPU_fstcw(void);
extern void x87FPU_fclex(void);
extern void x87FPU_fldcw(x87FPU_control_word cw);
extern x87FPU_status_word x87FPU_fxam(double num);

#endif

/*
    CIieeefp: x87FPUcmds.c
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

/* This file contains functions to access all the Intel x87 FPU
 * commands needed to implement the functions in CIieeefp.  This is
 * then the only file requiring its assembly to be hacked.
 */

#include "x87FPUsys.h"

/* x87FPU_fstsw() -> status_word
 *
 * Perform the fstsw instruction, returning the x87 FPU status word
 * retrieved. 
 */

x87FPU_status_word x87FPU_fstsw(void) {
  x87FPU_status_word sw;

  asm("fstsw %[status]" : [status] "=r" (sw));

  return sw;
}

/* x87FPU_fstcw() -> control_word
 *
 * Perform the fstcw instruction, returning the x87 FPU control word
 * retrieved.
 */

x87FPU_control_word x87FPU_fstcw(void) {
  x87FPU_control_word cw;

  asm("fstcw %[control]" : [control] "=m" (cw));

  return cw;
}

/* x87FPU_fclex()
 *
 * Issue the fclex instruction, which clears the exception flags.
 */

void x87FPU_fclex(void) {
  asm("fclex");
}

/* x87FPU_fldcw(sw)
 *
 * Perform the fldcw instruction, setting the control word to that
 * supplied as argument. This function clears the exception flags
 * using the fclex instruction.
 */

void x87FPU_fldcw(x87FPU_control_word cw) {
  asm("fclex");
  asm("fldcw %[control]" :: [control] "m" (cw));
}

/* x87FPU_fxam(num) -> status_word
 *
 * Perform the fxam instruction for the double precision number
 * supplied as argument. This instruction sets the condition code bits
 * in the x87 FPU status word to reflect the class of floating point
 * number on the top of the stack. The add instruction is there to get
 * num put onto the stack so that fxam can be applied to it.
 */

x87FPU_status_word x87FPU_fxam(double num) {
  x87FPU_status_word sw;

  asm("fldl %[number]" :: [number] "m" (num));
				// push num on fp stack
  asm("fxam");                  // set condition codes
  asm("fstsw %[status]" : [status] "=m" (sw));
				// store fp status register
  asm("fstpl %[popnum]" : [popnum] "=m" (num));
				// pop fp stack

  return sw;
}

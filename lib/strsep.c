/* Copyright (C) 1992, 1993 Free Software Foundation, Inc.
This file is part of the GNU C Library.

The GNU C Library is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public License as
published by the Free Software Foundation; either version 2 of the
License, or (at your option) any later version.

The GNU C Library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with the GNU C Library; see the file COPYING.LIB.  If
not, write to the Free Software Foundation, Inc., 675 Mass Ave,
Cambridge, MA 02139, USA.  */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif /* HAVE_CONFIG_H */

#include "ansidecl.h"

#if defined (HAVE_STRING_H)
#  include <string.h>
#elif defined (HAVE_STRINGS_H)
#  include <strings.h>
#endif /* HAVE_STRING_H */

char *
DEFUN(strsep, (stringp, delim),
      char **stringp AND CONST char *delim)
{
  char *begin, *end;

  begin = *stringp + strspn (*stringp, delim);
  end = *stringp + strcspn (*stringp, delim);

  if (end == *stringp)
    return NULL;

  if (*end != '\0')
    *end++ = '\0';
  *stringp = end;

  return begin;
}

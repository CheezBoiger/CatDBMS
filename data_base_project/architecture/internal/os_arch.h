/*
* Operating System Architecture check.
*
* Copyright (c) 2015 Mario Garcia <alexander.garcia18@yahoo.com>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
* USA
*
*/
#ifndef _OS_ARCH_H_
#define _OS_ARCH_H_

#pragma once

// Define Windows operating systems, default _WIN32 bit compatible with 64-bit OS Windows too!
#ifdef _WIN32
 #define _DB_CAT_WINDOWS
#elif defined(__CYGWIN__)
 #define _DB_CAT_CYGWIN
#elif defined(__OpenBSD__)
 #define _DB_CAT_BSD
#elif defined(__APPLE__) && defined(__MACH__)
 #define _DB_CAT_APPLE
#elif defined(__linux__)
 #define _DB_CAT_LINUX
#elif defined(__unix__)
 #define _DB_CAT_UNIX
#else
 #error Software is not compatible! What the hell kind of OS are you running?
#endif /* _WIN32 */


#endif /* _OS_ARCH_H_ */

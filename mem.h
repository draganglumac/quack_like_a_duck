/*
 * =====================================================================================
 *
 *       Filename:  mem.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26/01/14 12:28:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Dragan Glumac (draganglumac), dragan.glumac@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __MEM__
#define __MEM__

void *mem_malloc(size_t size);
void *mem_calloc(size_t num, size_t size);

#if defined(DEBUG)
	#define MALLOC(x) mem_malloc(x)
	#define CALLOC(x) mem_calloc(x)
#else
	#define MALLOC(x) malloc(x)
	#define CALLOC(x) calloc(x)
#endif

#endif

/*
	util_io.h
	file and directory utilities

	$Id: util_io.h,v 1.10 2010-02-22 23:21:33 sezero Exp $
*/

#ifndef __UTILIO_H
#define __UTILIO_H

#if defined(PLATFORM_WINDOWS)
#include <io.h>
#include "io_msvc.h"
#else
#include <unistd.h>
#endif

#if defined(PLATFORM_WINDOWS) && !defined(F_OK)
// values for the second argument to access(). MS does not define them
#define	R_OK	4		/* Test for read permission.  */
#define	W_OK	2		/* Test for write permission.  */
#define	X_OK	1		/* Test for execute permission.  */
#define	F_OK	0		/* Test for existence.  */
#endif

void	Q_mkdir (const char *path);
int	Q_rmdir (const char *path);
int	Q_unlink (const char *path);
void	Q_getwd (char *out, size_t size);
long	Q_filelength (FILE *f);

char	*Q_FindFirstFile (const char *path, const char *pattern);
char	*Q_FindNextFile (void);
void	Q_FindClose (void);

FILE	*SafeOpenWrite (const char *filename);
FILE	*SafeOpenRead (const char *filename);
void	SafeRead (FILE *f, void *buffer, int count);
void	SafeWrite (FILE *f, const void *buffer, int count);

int	LoadFile (const char *filename, void **bufferptr);
void	SaveFile (const char *filename, const void *buffer, int count);

void	CreatePath (char *path);
//void	Q_CopyFile (const char *frompath, const char *topath);
int	Q_CopyFile (const char *frompath, const char *topath);
int	Q_CopyFromFile (FILE *fromfile, const char *topath, size_t size);

#endif	/* __UTILIO_H */


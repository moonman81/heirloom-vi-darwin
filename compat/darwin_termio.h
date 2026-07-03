/*
 * darwin_termio.h - Darwin port shim for Ritter's ex/vi 3.7
 * Maps SysV termio to Darwin/POSIX termios.
 *
 * NOT part of upstream ex/vi. Port scaffolding only.
 * SPDX-License-Identifier: Zlib (this file only)
 */
#ifndef DARWIN_TERMIO_H
#define DARWIN_TERMIO_H

#include <termios.h>
#include <sys/ioctl.h>

/* SysV struct termio is essentially POSIX struct termios with
 * different field names + fewer fields. */
#define termio termios

/* NCCS shim — SysV termio had NCC=8; POSIX termios has NCCS=20 */
#ifndef NCC
#define NCC NCCS
#endif

/* Line-discipline flags Ritter's vi expects */
#ifndef ECHOK
#define ECHOK 0
#endif
#ifndef VSWTCH
#define VSWTCH VSTOP
#endif

/* SysV termio ioctls → BSD/Darwin equivalents.
 * The names are: get / set / set-with-drain. */
#ifndef TCGETA
#define TCGETA  TIOCGETA
#endif
#ifndef TCSETA
#define TCSETA  TIOCSETA
#endif
#ifndef TCSETAW
#define TCSETAW TIOCSETAW
#endif
#ifndef TCSETAF
#define TCSETAF TIOCSETAF
#endif



/* CBAUD — SysV baud-rate mask. Not needed on POSIX termios but some
 * code references it. Define as 0 to make comparisons harmless. */
#ifndef CBAUD
#define CBAUD 0
#endif

/* Other SysV termio flags that Darwin doesn't ship */
#ifndef CIBAUD
#define CIBAUD 0
#endif

#endif /* DARWIN_TERMIO_H */

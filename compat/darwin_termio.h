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

/* SysV struct termio → POSIX struct termios. */
#define termio termios

/* NCCS shim — SysV termio had NCC=8; POSIX termios has NCCS=20. */
#ifndef NCC
#define NCC NCCS
#endif

/* Line-discipline flags Ritter's vi expects. */
#ifndef ECHOK
#define ECHOK 0
#endif
#ifndef VSWTCH
#define VSWTCH VSTOP
#endif

/* SysV termio ioctls → BSD/Darwin equivalents. */
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

/*
 * NOTE — CBAUD / CIBAUD are DELIBERATELY NOT DEFINED here.
 *
 * On SysV termio, CBAUD is a bit mask for baud rate inside c_cflag.
 * On POSIX termios (Darwin), baud rate is NOT in c_cflag — it lives
 * in its own fields accessed via cfgetispeed()/cfgetospeed() and
 * cfsetispeed()/cfsetospeed().
 *
 * Any Ritter-vi code that used `tty.c_cflag & CBAUD` has been
 * rewritten to use `cfgetospeed(&tty)` under `#ifdef __APPLE__` in
 * the relevant .c files.  See the port's patches/ series.
 *
 * If your build fails with 'CBAUD undefined', DO NOT define it as 0
 * here — that silently pessimises terminal-speed detection.  Instead
 * rewrite the offending line to use cfgetispeed/cfgetospeed.
 */

#endif /* DARWIN_TERMIO_H */

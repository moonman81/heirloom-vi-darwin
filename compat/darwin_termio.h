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

/*
 * WARNING — CBAUD / CIBAUD:
 *
 * On SysV termio, CBAUD is a BIT MASK used to extract or set the
 * baud-rate bits inside c_cflag:
 *
 *     rate = tty.c_cflag & CBAUD;              // read speed
 *     tty.c_cflag = (tty.c_cflag & ~CBAUD) | B9600;   // set speed
 *
 * On POSIX termios (Darwin), baud rate is NOT stored in c_cflag.
 * It lives in its own hidden fields; you access it via:
 *
 *     speed_t rate = cfgetispeed(&tty);        // read
 *     cfsetispeed(&tty, B9600);                // set
 *     cfsetospeed(&tty, B9600);                // set
 *
 * Defining CBAUD = 0 makes the SysV-flavoured code COMPILE but
 * silently BREAKS runtime baud-rate handling: `tty.c_cflag & 0`
 * always reports zero, so vi's `ex_tty.c` terminal-speed detection
 * will always think the terminal is at speed 0 and pessimise its
 * cursor-motion path (assume slow terminal, minimise optimisation).
 *
 * The fully correct fix is to rewrite the SysV baud-rate paths in
 * ex_tty.c to use cfgetispeed / cfsetispeed on Darwin. That is
 * REMAINING WORK; the CBAUD = 0 shim below is a KNOWN HAZARD.
 */
#ifndef CBAUD
#define CBAUD  0   /* HAZARD — see comment above */
#endif
#ifndef CIBAUD
#define CIBAUD 0   /* HAZARD — see comment above */
#endif

#endif /* DARWIN_TERMIO_H */

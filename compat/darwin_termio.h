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

#endif /* DARWIN_TERMIO_H */

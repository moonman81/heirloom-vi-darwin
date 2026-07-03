# heirloom-vi-darwin

A **patches-only** Darwin (macOS 26.4 arm64) port scaffold for Gunnar
Ritter's port of the historical BSD `ex`/`vi` (originally ex/vi 3.7,
6/7/85, from the 2.11BSD distribution).

> **NOT AUTHORITATIVE.** Not an original work. See `NOTICE.md` for
> the licence patchwork and scope disclaimer.

## What this repo does and does not do

### DOES
- Provide Darwin-specific patches on top of Ritter's `ritter_vi.tar.gz`
  (currently vintage `2000-`).
- Provide ALM scaffolding (`GNUmakefile`, `scripts/`, ports layout)
  matching the other five `heirloom-*-darwin` repos.
- Provide honest documentation of the licence position (see below).

### Port status: PARTIAL

Real porting progress landed 2026-07-03:

- 27 of ~35 object files build cleanly on Darwin arm64 with the
  captured patches.
- `patches/0001-ex.h-guard-dosusp-with-__APPLE__.patch` — extends the
  existing `TIOCLGET || __linux__` guard around `dosusp` to include
  `__APPLE__`, making the SIGTSTP suspend variable visible on Darwin.
- `patches/0002-Makefile-modernize-CFLAGS-for-clang-C23.patch` —
  adds `-std=gnu89` and warning-suppression flags to compile against
  modern clang (which defaults to C23).
- `compat/darwin_termio.h` grew from a shim into a fuller SysV-to-
  POSIX termios translation layer: `struct termio`, `NCC`, `ECHOK`,
  `VSWTCH`, `TCGETA`, `TCSETA`, `TCSETAW`, `TCSETAF`, `CBAUD`, `CIBAUD`.

Remaining Darwin fixes (est. 4-6 hours):
- `printf.c` — replace `<varargs.h>` with `<stdarg.h>`.
- `ex_temp.c`, `ex_v.c` — ANSI/K&R prototype mismatches.
- Final linking pass.

Contributions welcome.

### DOES NOT
- **Ship Ritter's source code.** The upstream tarball carries a
  header that reads, verbatim,
  `THIS IS NOT FREE SOFTWARE / SEE YOUR CONTRACT WITH SCO FOR DETAILS`,
  inherited from the 2.11BSD ex/vi 3.7 base which contains
  AT&T-licensed code.  Redistribution outside the TUHS Archive's
  distribution framework would be reckless without specific counsel.
- Provide a working binary from `git clone` alone.  You have to
  obtain `ritter_vi.tar.gz` from the TUHS Unix Heritage Archive (or a
  mirror) under your own reading of the applicable licence terms,
  place it under `vendor/`, and then run `make patch build`.

## Sourcing the upstream

The tarball is at
`https://www.tuhs.org/Archive/Applications/Ritter_Vi/2000/ritter_vi.tar.gz`
or via any complete TUHS mirror (e.g. `sunsite.icm.edu.pl/`,
`ftp.pl.uu.net/mirrors/tuhs/`).

Recorded SHA-256 (October 2000 tarball, 300 KiB):

```
# SHA-256 pending — record after downloading:
# shasum -a 256 ritter_vi.tar.gz
```

You are responsible for satisfying yourself that your use of Ritter's
code is licit for your purpose.

## What Ritter's port did on top of 2.11BSD ex/vi 3.7

Directly from the upstream `README.NEW`:

- Added the manual pages.
- Added 2.11 termcap.
- ISO character-set handling (enabled by default; toggle with
  `-DISO` in `Makefile OPTIONS`).
- Smaller portability fixes.

Ritter compiled it on Linux 2.2.15 / glibc 2.1.3 (~2000).  No
Darwin support upstream.

## Building on Darwin

```sh
git clone https://github.com/moonman81/heirloom-vi-darwin
cd heirloom-vi-darwin
# fetch the upstream tarball under your own licence reading
cp /path/to/ritter_vi.tar.gz vendor/
# extract + apply Darwin patches + build
make bootstrap
make configure
make build
sudo make install PREFIX=/opt/heirloom
```

## Provenance

Ex/vi lineage:

```
Ken Thompson QED (1969)
    → Bill Joy ex (1976, at Berkeley)
    → 1BSD, 2BSD, 2.11BSD ex/vi 3.7 (6/7/85)  ← AT&T-licensed
    → Gunnar Ritter (2000) — the tarball this repo patches
    → moonman81 heirloom-vi-darwin (2026)     ← this repo (patches only)
```

See `PROVENANCE.md` and `BIBLIOGRAPHY.md` for citations.

## Related repos

- <https://github.com/moonman81/heirloom-sh-darwin>
- <https://github.com/moonman81/heirloom-devtools-darwin>
- <https://github.com/moonman81/heirloom-toolchest-darwin>
- <https://github.com/moonman81/heirloom-doctools-darwin>
- <https://github.com/moonman81/heirloom-pkgtools-darwin>
- <https://github.com/moonman81/heirloom-workspace-darwin>
- <https://github.com/moonman81/heirloom-citations-darwin>  (canonical docs)
- <https://github.com/moonman81/heirloom-ancestors-darwin> (museum references)

## Licence + warranty

- **Scaffolding written by moonman81** (this README, patches, GNUmakefile,
  scripts): zlib licence, per file headers.
- **Upstream Ritter source**: NOT distributed by this repo. See
  the tarball's own `READ_ME` and the SCO/Caldera contract that governs
  2.11BSD-derived material.

**No warranty. No guarantee of fitness. Not authoritative.**

See `NOTICE.md`, `AI-DISCLOSURE.md`, `GRATITUDE.md`.

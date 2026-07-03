# PROVENANCE — heirloom-vi-darwin

Chain of custody for the `vi` package as scaffolded by this Darwin
port.

## Lineage

```
┌──────────────────────────────────┐  1969
│  Ken Thompson — QED editor       │  PDP-7 ancestor
│  Bell Labs Research UNIX         │
└──────────────┬───────────────────┘
               │
               ▼
┌──────────────────────────────────┐  1971-1975
│  ed (V1-V6, AT&T)                │  Line editor
└──────────────┬───────────────────┘
               │
               ▼
┌──────────────────────────────────┐  1976-1977
│  George Coulouris — em (editor    │  screen-oriented editor from
│  for mortals), Queen Mary College │  QMC brought to Berkeley
└──────────────┬───────────────────┘
               │
               ▼
┌──────────────────────────────────┐  1976-1978
│  Bill Joy — ex, then vi          │  Berkeley (BSD)
│  UC Berkeley                     │
└──────────────┬───────────────────┘
               │
               ▼
┌──────────────────────────────────┐  1978-1988
│  1BSD → 2BSD → 2.11BSD           │  BSD tape distribution
│  ex/vi 3.7 (6/7/85)              │  Carries AT&T-licensed
│                                  │  fragments (SCO-inherited).
└──────────────┬───────────────────┘
               │  ritter_vi.tar.gz (October 2000):
               │  Ritter adds ISO chars, manual pages,
               │  2.11 termcap, portability patches.
               ▼
┌──────────────────────────────────┐  2000
│  Gunnar Ritter                   │  Freiburg im Breisgau, Germany
│  <g-r@bigfoot.de>                │  <gunnarr@acm.org>
└──────────────┬───────────────────┘
               │  Tarball obtainable from TUHS Archive.
               │  This repo tracks its SHA-256 in
               │  scripts/configure.sh output.
               ▼
┌──────────────────────────────────┐  2026-07-03 → present
│  moonman81                        │  Darwin port scaffold.
│  heirloom-vi-darwin              │  Patches only; upstream
│                                  │  source NOT redistributed.
└──────────────────────────────────┘
```

## Licensing overlay

- Layers before Ritter (Coulouris → Joy → 1BSD-2BSD → 2.11BSD)
  carry AT&T-licensed material subject to the SCO/Caldera contract
  applicable to whoever holds the SVR3/BSD-descent licence today.
- Ritter's added lines (ISO handling, manual pages, 2.11 termcap
  fixes) are marked with his copyright + zlib-style permission where
  he wrote them fresh.
- This repo (`heirloom-vi-darwin`) contributes:
  - README, NOTICE, AI-DISCLOSURE, GRATITUDE, PROVENANCE, BIBLIOGRAPHY:
    CC-BY-4.0.
  - `GNUmakefile`, `scripts/*.sh`, `compat/darwin_termio.h`:
    zlib-licence, © 2026 moonman81.
  - `patches/*.patch`: hunks against upstream Ritter source; each
    hunk inherits the licence of the upstream lines it modifies.

## Verifiable trail

- Upstream tarball SHA-256 recorded on first `make configure` in the
  build directory as `.upstream-sha256`.
- Every commit to this repo touches only scaffolding + patches, never
  ships upstream source directly.
- `git log --all --oneline` shows the arc.

## Related repos

- `moonman81/heirloom-sh-darwin`         — Bourne shell
- `moonman81/heirloom-devtools-darwin`   — make/sccs/yacc/lex/m4
- `moonman81/heirloom-toolchest-darwin`  — POSIX/SVR4 utilities
- `moonman81/heirloom-doctools-darwin`   — troff pipeline
- `moonman81/heirloom-pkgtools-darwin`   — pkgadd/rm/chk
- `moonman81/heirloom-workspace-darwin`  — workspace
- `moonman81/heirloom-citations-darwin`  — canonical documentation
- `moonman81/heirloom-ancestors-darwin`  — museum reference sources

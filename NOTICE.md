# NOTICE — heirloom-vi-darwin

## Scope

This repository is a **downstream Darwin port scaffold** — patches
plus ALM machinery — for Gunnar Ritter's `ritter_vi.tar.gz` (the year
2000 port of 2.11BSD ex/vi 3.7 to modern Unix).

**It is not an authoritative source.** Upstream is the tarball
distributed via the TUHS Unix Heritage Archive at
<https://www.tuhs.org/Archive/Applications/Ritter_Vi/2000/>.

## What this repository DOES ship

- README, NOTICE, AI-DISCLOSURE, GRATITUDE, PROVENANCE, BIBLIOGRAPHY.
- Darwin-specific compat shims (`compat/darwin_termio.h`, etc.).
- `GNUmakefile` + `scripts/*.sh` ALM scaffolding matching the other
  Heirloom Darwin repos.
- `patches/*.patch` — a git-format-patch series applied on top of
  extracted upstream source at build time.
- Test corpus + verification harness.

## What this repository DOES NOT ship

- **Ritter's source code.** The upstream `READ_ME` file (retained in
  the tarball you must fetch separately) reads verbatim:
  ```
  THIS IS NOT FREE SOFTWARE
  SEE YOUR CONTRACT WITH SCO FOR DETAILS
  ```
  and inherits AT&T-licensed material from the 2.11BSD base.  We do
  not redistribute it.

## Licence patchwork

Files with `SPDX-License-Identifier: Zlib` (this repo's port
scaffolding) are covered by the zlib licence, © 2026 moonman81.

Files under `patches/` are unified-diff hunks against the upstream
tarball; the licence status of each hunk is the same as the upstream
lines it modifies.  Because those upstream lines carry the SCO/AT&T
constraint, treat every hunk in `patches/` as under the same reading
you applied to the upstream tarball itself.

## Warranty

**No warranty.  No guarantee of originality.  No guarantee of fitness
for any purpose.**  This is a port project.  For the canonical vi
implementation on macOS, use the system-installed `vi` (nvi under the
hood) or GNU/BSD `vim`; this scaffold is for users who specifically
want to run Ritter's ex/vi 3.7 lineage on Darwin, with all the SCO/AT&T
legacy that entails.

## Reporting attribution concerns

If you believe this scaffold misrepresents authorship or violates a
licence, open a `Attribution concern` issue via the GitHub UI or email
<i.am.moonman@gmail.com>.  The maintainer will accept take-down
requests without argument.

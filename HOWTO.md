# HOWTO — heirloom-vi-darwin

Practical guide to using this port scaffold.

## Prerequisites

- macOS 26.4 (arm64) or any modern Darwin with Xcode CLT.
- Enough space for the extracted upstream tree (~1 MB).
- A copy of `ritter_vi.tar.gz` fetched from the TUHS Archive under
  your own licence reading.

## Steps

1. Clone this repo:

   ```sh
   git clone https://github.com/moonman81/heirloom-vi-darwin
   cd heirloom-vi-darwin
   ```

2. Fetch the upstream tarball. Recommended path is directly from
   TUHS:

   ```sh
   curl -L -o vendor/ritter_vi.tar.gz \
     https://www.tuhs.org/Archive/Applications/Ritter_Vi/2000/ritter_vi.tar.gz
   shasum -a 256 vendor/ritter_vi.tar.gz
   ```

3. Verify prerequisites + tarball:

   ```sh
   make bootstrap
   make configure
   ```

4. Extract + patch + build:

   ```sh
   make patch
   make build
   ```

   The build may not complete cleanly. Ritter's 25-year-old K&R-style
   C emits many warnings on modern clang. Patches in `patches/` fix
   the biggest issues (termio → termios, K&R prototypes, `signal()`
   handler types) but a full clean build has not been achieved on
   Darwin arm64 as of the current port revision. Contributions
   welcome.

5. Install if the build succeeded:

   ```sh
   sudo make install PREFIX=/opt/heirloom
   ```

6. Verify:

   ```sh
   make verify PREFIX=/opt/heirloom
   ```

## Alternatives

If you want vi on Darwin and don't specifically care about Ritter's
2.11BSD-lineage port, use one of:

- `vi` in `/usr/bin/vi` — Darwin's built-in nvi.
- `vim` from Homebrew — modern, actively maintained.
- `nvi` from Homebrew — Berkeley's free reimplementation.
- `neovim` from Homebrew — modern fork of vim.

Heirloom-vi-darwin is for users who specifically want to run the
2.11BSD ex/vi 3.7 lineage on Darwin, with all the historical baggage
that entails.

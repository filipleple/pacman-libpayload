# Pacman-libpayload

ASCII Pacman game, written with curses, ported to libpayload to be used
with coreboot.

## Building

* Build libpayload
* Start from `coreboot/payloads/pacman` or edit the `lpgcc` path in Makefile
* Run `make`
* Build coreboot with `An ELF executable payload`, pointing to the built
`pacman` file. So far, it's only been tested in qemu.

## Playing

Run `qemu-kvm -bios coreboot.rom -M q35`. Use the keys:

```
  x - left
  c - right
  k - up
  m - down
```
to move.

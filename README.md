# Pacman-libpayload

ASCII Pacman game, written with curses, ported to libpayload to be used
with coreboot.

![qemu screenshot](qemu.png)

## Running

Grab the latest release, and run `qemu-kvm -bios pacman_qemu_q35.rom -M q35`.

## Building

* Build libpayload
* Start from `coreboot/payloads/pacman` or edit the `lpgcc` path in Makefile
* Run `make`
* Build coreboot with `An ELF executable payload`, pointing to the built
`pacman` file. So far, it's only been tested in qemu.
* Run `qemu-kvm -bios coreboot.rom -M q35`.

## Playing

 Use the keys:

```
  x - left
  c - right
  k - up
  m - down
```
to move.

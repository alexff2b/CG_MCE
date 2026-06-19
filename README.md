# CG_MCE

**CG_MCE (Multi Config Emulator / Multi Core Emulator)** is an open modular emulator framework for retro computer systems.

The project combines software emulation with hardware experimentation. Its goal is to build a configurable computer architecture where processors, buses, memory and peripheral devices are independent modules.

CG_MCE is not limited to emulating a single machine. Instead, it provides a flexible platform capable of representing many computer configurations from the 1970s–1990s and beyond.

---

## Current Status

**Version:** v0.1 (Early Development)

Current work includes:

- Project architecture
- ANSI terminal user interface
- Z80 CPU core
- Modular system design
- Hardware backplane development
- Clock board development

---

## Main Goals

- Modular emulator architecture
- Configurable hardware profiles
- Multiple CPU support
- Cycle-accurate execution
- Modular memory system
- Modular I/O devices
- Console debugger
- Hardware verification using real prototype boards

---

## Project Structure

```
CG_MCE/
│
├── emulator.c
├── ansi_formatting.h
├── ui_console.h
├── Z80core.h
│
├── cpu/
├── memory/
├── bus/
├── devices/
├── machine/
├── debugger/
├── configuration/
└── documentation/
```

---

## Planned Features

- Z80
- Intel 8080
- Intel 8086
- MOS 6502
- Motorola 68000
- Additional processors

Supported systems will gradually include:

- Sinclair ZX Spectrum
- CP/M computers
- MSX
- Commodore systems
- IBM PC compatible systems
- Custom hardware configurations

---

## Long-Term Vision

CG_MCE is designed as a configurable computer platform rather than a fixed emulator.

Future versions may include:

- Plugin architecture
- Public C API
- AI integration
- Hardware co-simulation
- Multiple video adapters
- Network support
- Scriptable machine configuration

---

## Development

Language:

- C (current)
- C++ (planned architecture migration)

Development style:

- Modular design
- Header-first development
- Portable ANSI terminal interface

Platforms:

- Linux
- Android (Termux)
- Windows
- macOS

---

## License

License will be selected after the project reaches a stable public release.

---

## Author

CG (CosmoGenesis Project)

Project started from an interest in retro computing, hardware design, and modular computer architecture.

# CardGame

A simple self-played card game written in C++17.

## Requirements

- g++ with C++17 support
- make

## How to Run

### Clone and build

1. Clone the repository and navigate to the project directory
2. Compile:
   ```
   make
   ```
3. Run:
   ```
   ./cardgame.exe
   ```

### Other targets

| Command | Description |
|---|---|
| `make debug` | Build with debug symbols and `-DDEBUG` |
| `make run` | Build and run in one step |
| `make clean` | Remove compiled binary and object files |
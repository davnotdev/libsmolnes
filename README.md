# libsmolnes

`libsmolnes` is a slight modification of [`smolnes`](https://github.com/binji/smolnes)
to decouple it from SDL, allowing you to embed an impressively simple and tiny NES emulator into whatever you want.
`smolnes` doesn't contain sound or any ROM validation, just video and input. 

Disclaimer, I DID NOT CREATE [`smolnes`](https://github.com/binji/smolnes).
[`smolnes`](https://github.com/binji/smolnes) is a really cool NES emulator created by Ben Smith.
Please check go check it out.

## Usage

```sh
# Build Options
make
make sdl_example
make all
make clean

# Our example
./sdl_example
```

Please see the example using SDL. Have fun!


.PHONY: all clean
all: libsmolnes.a sdl_example

WARN=-Wall \
     -Wno-parentheses \
		 -Wno-misleading-indentation \
		 -Wno-bool-operation \
		 -Wno-discarded-qualifiers \
		 -Wno-incompatible-pointer-types-discards-qualifiers \
		 -Wno-unknown-warning-option \
		 -Wno-switch-outside-range \
		 -Wno-unused-value

libsmolnes.a: smolnes.c
	$(CC) -c -O2 -o smolnes.o $< -g ${WARN}
	$(AR) rcs $@ smolnes.o

sdl_example: sdl_example.c
	$(CC) -O2 -o $@ $< -g ${WARN} libsmolnes.a -lSDL2

clean:
	rm -f libsmolnes.a smolnes.o sdl_example

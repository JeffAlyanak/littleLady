CC	= lcc -Wa-l -Wl-m

BINS	= littleLady.gb
EMUL	= gvba littleLady.gb

all:	$(BINS)
	$(EMUL)

%.o:	%.c
	$(CC) -c -o $@ $<

%.s:	%.c
	$(CC) -S -o $@ $<

%.o:	%.s
	$(CC) -c -o $@ $<

%.gb:	%.o
	$(CC) -o $@ $<

clean:
	rm -f *.o *.lst *.map *.gb

# Link file, and write 0x80 at position 0x143 in header
littleLady.gb:	littleLady.o
	$(CC) -Wl-yp0x143=0x80 -o littleLady.gb littleLady.o

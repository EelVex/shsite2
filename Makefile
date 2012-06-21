
all: manual manpage utils

manual: doc/shsite2-manual.pdf

doc/shsite2-manual.pdf: doc/shsite2-manual.tex
	pdflatex -output-directory doc $^ && pdflatex -output-directory doc $^

manpage: shsite2.man

shsite2.man: doc/shsite2-manual.tex

utils: bin/shsite2_blocks bin/shsite2_block-put

bin/% : src/%.c
	@mkdir -p bin
	gcc -O3 -Wall -o $@ $^

clean:
	rm -f doc/*.{aux,log,toc}


all: manual manpage utils

manual: shsite2-manual.pdf

shsite2-manual.pdf: shsite2-manual.tex
	pdflatex $^ && pdflatex $^

manpage: shsite2.man

shsite2.man: shsite2-manual.tex

utils: bin/shsite2_blocks bin/shsite2_block-put

bin/% : %.c
	gcc -O3 -Wall -o $@ $^

clean:
	rm -f *.aux *.log *.toc

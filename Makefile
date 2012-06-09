
all: manual manpage

manual: shsite2-manual.pdf

shsite2-manual.pdf: shsite2-manual.tex
	pdflatex $^

manpage: shsite2.man

shsite2.man: shsite2-manual.tex

clean:
	rm -f *.aux *.log

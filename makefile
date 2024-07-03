# Makefile for LaTeX project

# Variables
TEX = pdflatex
MAIN = main
TEX_FILES = $(wildcard *.tex)

all: pdf

pdf: $(MAIN).pdf

$(MAIN).pdf: $(TEX_FILES)
	$(TEX) $(MAIN) 
	$(TEX) $(MAIN)
	$(TEX) $(MAIN)

clean:
	./clean.sh

run:
	./run.sh $(MAIN).pdf
	

.PHONY: all clean pdf

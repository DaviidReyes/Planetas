

Resultados_hw4.pdf: Resultados_hw4.tex ExtremosFijos.jpg ExtremosLibres.jpg TamborPunto_medio.jpg TamborMatriz_completa.jpg sonido.wav
	pdflatex Resultados_hw4.tex
ExtremosFijos.jpg ExtremosLibres.jpg TamborPunto_medio.jpg TamborMatriz_completa.jpg sonido.wav: Plots.py
	python Plots.py
Plots.py: archivo1.txt archivo2.txt archivo3.txt archivo4.txt
	python Plots.py archivo1.txt archivo2.txt archivo3.txt archivo4.txt
archivo1.txt archivo2.txt archivo3.txt archivo4.txt: Ondas.x
	./Ondas.x
	
Ondas.x:Ondas.c
	gcc -Wall Ondas.c -o Ondas.x -lm

	


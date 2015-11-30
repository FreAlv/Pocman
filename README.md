# Pocman

Este proyecto está basado en el juego Pacman. Consta de un personaje que debe evitar ser comido por 4 fantasmas, y para ganar debe comer todos las bolitas de la pantalla.

Para la entrada por teclado e impresión de pantalla hemos usado la librría Ncurses 
Usamos threads para permitir que el movimiento de los fantasmas sea independiente al movimiento del pacman.

Se usan las teclas direccionales, la tecla 'q' para salir del juego y la tecla 'enter' para seleccionar una opción en el menú.

El movimiento del pacman depende de la tecla pulsada. Las coordenadas del pacman cambian y posteriormente son impresas en la pantalla.

Los fantantasmas buscan al pacman, dependiendo de la posición de este. Para esto hemos implementado una inteligencia artifial que consta de varios if, dependiendo de la proximidad del pacman al fantasma, este elige hacia donde moverse.

Una clase llamada ControlJuego, controla las vidas, la puntuación, el nivel, la velocidad de los fantasmas y el modo especial que ocurre cuando el pacman come una bola grande y puede comer a los fantasmas. Además controla las pantallas usadas con la librería Ncurses.

El tablero consta de un array de dos dimenciones de números enteros:
 - Bolitas : 0
 - Paredes : 1
 - Bolas grandes : 2
 - Fantasmas : 3
 - Pacman : 4
 - Vida extra : 5
 - Espacios en blanco : 9
La función imprimir del tablero  imprime un caracter que representa a cada número.

El main se compone de 2 funciones principales, una para la entrada de teclado y otra para el movimiento de los fantasmas e impresión del tablero.

# README

Autor: Félix Javier Rojas Gallardo
Matrícula A01201946

## Sobre este repositorio

Este repositorio contiene pequeños avances de una copia de la tortuga de LOGO utilizando tkinter para generar la interfaz. El código está en desarrollo.

### Lista de comandos a definir

`FWD`
Mueve el cursor adelante *n* pixeles
regex: /FWD \d+/

`BAK`
Mueve el cursor atrás *n* pixeles
regex: /BAK \d+/

`DER`
Rota el cursor hacia la derecha *n* grados
regex: /DER \d+/

`IZQ`
Rota el cursor hacia la izquierda *n* grados
regex: /IZQ \d+/

`CNT`
Regresa el cursor al centro
regex: /CNT/

`ERA`
Borra la pantalla
regex: /ERA/

`sid`
Sí dibuja en la pantalla
regex: /SID/

`nod`
No dibuja en la pantalla
regex: /NOD/

`rep`
Repite la instrucciones
regex: /REP \[{1}\d+\]{1}/

`col`
Color *n* donde n va del 1 - 10
regex: /COL[\d]+/

### Gramática

```
<KEYWORD> ::= <LONE_KEYWORD>

<PARAMETRIZED_KEYWORD>

<LONE_KEYWORD> ::= ERA|CNT|SID|NOD

<PARAMETRIZED_KEYWORD> ::= FWD|BAK|IZQ|DER|COL <NUMBER>

<NUMBER> ::= [\d]+ 
```

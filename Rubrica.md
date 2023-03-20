# Rubrica

## Contenidos deseados

### Documento

- **Portada**
- Una **lista** con los **elementos del léxico** del lenguaje, incluyendo para cada uno su expresión regular que lo representa utilizando la notación básica.

### Lista de comandos

`ade`
Mueve el cursor adelante *n* pixeles
EBNF: <ade> ::= "ade " [1-9]+ "\n"
regex: /ade \d+/

`atr`
Mueve el cursor atrás *n* pixeles
EBNF: <atr> ::= "atr " [1-9]+ "\n"
regex: /atr \d+/

`der`
Rota el cursor hacia la derecha *n* grados
regex: /der \d+/

`izq`
Rota el cursor hacia la izquierda *n* grados
regex: /izq \d+/

`cnt`
Regresa el cursor al centro
regex: /cnt/

`brr`
Borra la pantalla
regex: /brr/

`sid`
Sí dibuja en la pantalla
regex: /sid/

`nod`
No dibuja en la pantalla
regex: /nod/

`rep`
Repite la instrucciones
regex: /rep \[{1}\d+\]{1}/

`col`
Color *n* donde n va del 1 - 10
regex: col (10|[1-9])

- El diseño de un **autómata determinístico** que modele el proceso de análisis del léxico del lenguaje según la técnica aprendida en el curso. **Este autómata NO se implementará**, pero su diseño es una práctica importante.
- El **diseño de los diagramas de sintaxis** y la **gramática BNF que modelen** la sintaxis del lenguaje que utiliza los lexemas previamente diseñados.
- El **código implementado**, documentado **con** los **comentarios** convenientes para entenderlo.
- Las **entradas** (inputs) con las **que se probó** el programa, describiendo si funcionaron o no.
- Un **breve comentario** sobre la **experiencia de aprendizaje** y los **resultados** obtenidos.

### Video

- **5 minutos máximo** 
- **Muestra la ejecución de tu programa** 
- **Pruebas significativas**
- **Elementos principales** 
- **Comentarios del proceso**
- **Aprendizajes**

## Ponderación

- 10% si se identificaron correctamente todos los elementos del léxico del lenguaje.
- 10% si se diseñaron correctamente las expresiones regulares de los lexemas del lenguaje.
- 10% si se diseñó correctamente el autómata determinístico que modela el analizador de léxico del lenguaje.
- 10% si se diseñaron correctamente los diagramas de sintaxis y la gramática de la sintaxis del lenguaje.
- 10% si el código implementado utiliza correctamente la librería para expresiones regulares y el método de descenso recursivo para la sintaxis.
- 10% si el código implementado es eficiente, tiene una interfaz de uso adecuada y está bien documentado.
- 20% si el programa funciona y realiza lo esperado (genera las gráficas esperadas y marca error en elementos mal construidos).
- 20% si el video cumple con las condiciones solicitadas y es una evidencia significativa de lo logrado y aprendido.

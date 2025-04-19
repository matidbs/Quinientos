QUINIENTOS O ESCALERA

Se deberá realizar un juego de dados denominado Quinientos o Escalera, que es un juego que puede desarrollarse para un jugador o dos jugadores.
El programa debe hacerse en un proyecto de CodeBlock en C/C++ y contar con un menú principal que permita iniciar un juego nuevo para un jugador, un juego nuevo para dos jugadores,  mostrar la puntuación más alta y la opción de Salir del juego.

Juego nuevo para un jugador
Esta opción permite a un solo jugador realizar una partida completa. 
Antes de comenzar a jugar deberá solicitar el nombre del jugador.
Una vez finalizada la partida, deberá mostrar el nombre del jugador y el puntaje obtenido.

Juego nuevo para dos jugadores
Esta opción permite a dos jugadores realizar una partida completa. 
Antes de comenzar a jugar deberá solicitar el nombre de cada jugador. Una vez finalizada la partida, deberá mostrar el nombre del jugador que haya ganado y el puntaje obtenido.

Mostrar puntuación más alta
Esta opción debe mostrar el nombre del jugador que haya finalizado el juego en la menor cantidad de rondas. En caso de empatar la cantidad de rondas, se debe analizar la menor cantidad de lanzamientos.

NOTA: Cabe aclarar que el sistema no tendrá la capacidad de guardar la puntuación en un archivo. Por lo que al salir del juego, se borrarán todos los datos de puntuación.

Reglamento del juego
El objetivo del juego es obtener al menos 500 puntos en la menor cantidad posible de  rondas, o sacar una escalera en un lanzamiento. 

Una ronda está compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para determinar el puntaje.

El puntaje de un lanzamiento está determinado por una serie de reglas que figuran en la sección Combinaciones ganadoras.

El puntaje final de la ronda será el valor máximo de los puntos obtenidos entre los 3 lanzamientos, con las siguientes excepciones:
Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento
Si en un lanzamiento se obtiene una combinación de 6 dados con valor 6, el puntaje total de la persona se resetea a 0. 

Para el caso de la opción para 2 jugadores, cada jugador debe completar una ronda (3 lanzamientos) alternativamente. 


Combinaciones ganadoras
Combinación
Nombre jugada
Puntaje otorgado
Menos de 3 dados con valores iguales (cualquier combinación)
Ejemplo: 6,5,5,2,2,1
Suma de dados
Suma de los valores de todos los dados
Para el ejemplo sería
6+5+5+2+2+1=21
3 dados o más con el mismo valor (hasta 5 iguales).
Ejemplo: 5, 5, 5,1,2,3.
Trío X++ (X es el número del dado)
X*10puntos

Para el ejemplo sería 5*10=50

En el caso que haya 2 ternas de dados se debe elegir la que otorgue el puntaje mayor.

Ejemplo:
1,1,1,2,2,2

Se debe otorgar 2*10=20 puntos
6 dados iguales (menos para el número 6) 
Sexteto X (X es el número del dado)


X*50 puntos
Escalera 
(1, 2, 3, 4, 5, 6) - En cualquier órden
Escalera
Gana la partida en esa ronda
Seis 6
Sexteto6- -
Resetea el puntaje total a 0 


Por cada lanzamiento el programa tiene que elegir la combinación ganadora que corresponda.
Por ejemplo:
⚁⚁⚁⚃⚄⚄
Trío X++ de 2: 2*10->20 puntos
El puntaje a otorgar deberá ser de 20 puntos.

⚁⚁⚁⚁⚁⚁
SextetoX de 2: 2*50->100 puntos.

Interfaz
Durante el turno de un jugador
Se deberá mostrar el nombre del jugador, el número de ronda, y el puntaje de ese momento. A medida que avanza la ronda se deberá el puntaje provisorio y la cantidad de lanzamientos.
Más abajo, se deberán listar los dados que conforman el lanzamiento y de obtener una combinación ganadora, el nombre de la combinación y el puntaje otorgado.

TURNO DE MARTA |  RONDA N° 3  | PUNTAJE TOTAL: 280 PUNTOS
------------------------------------------------------------------
MAXIMO PUNTAJE DE LA RONDA: 50 PUNTOS
LANZAMIENTO N° 2
------------------------------------------------------------------
⚀⚁⚂⚃⚄⚅
 ¡ESCALERA! ¡GANASTE LA PARTIDA!


NO ES OBLIGATORIO QUE SE MUESTREN LOS DADOS POR PANTALLA. ES SUFICIENTE QUE SE MUESTREN LOS NÚMEROS DE LOS DADOS.
Entre turnos
Cuando finaliza un turno y comienza el otro, deberá mostrar una pantalla que indique a quién le corresponde el próximo turno, el número de ronda y los puntajes de ambos jugadores. En el caso de que sea un juego para un jugador, debe indicar el número de ronda, el nombre del jugador y el puntaje.

RONDA N° 3
PRÓXIMO TURNO: JAVIER

PUNTAJE MARTA : 280 PUNTOS
PUNTAJE JAVIER: 150 PUNTOS

PRESIONAR UNA TECLA PARA CONTINUAR...

Ganador
Cuando un jugador gana la partida, se deberá mostrar una pantalla que indique el nombre y apellido de quien gano y la cantidad de rondas que le llevó ganar la partida.

Gana la partida quien haya obtenido los 500 puntos primero o escalera en un lanzamiento.

Características opcionales
1 - Existe la posibilidad de empate. Esto ocurre cuando ambos jugadores logran los 500 puntos  o más en la misma ronda. En dicho caso se puede desempatar contando la cantidad de lanzamientos y favoreciendo a quien obtuvo el puntaje máximo en la menor cantidad de tiradas.
2 - Predeterminar una cantidad de rondas al inicio de la partida. Si ningún jugador obtuvo los 500 puntos al finalizar las rondas, el ganador de la partida será aquel que haya obtenido el puntaje más alto.

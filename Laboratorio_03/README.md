# Ejercicios sugeridos

Estos ejercicios son sugeridos a manera de práctica y ***NO*** tendrán ningún 
tipo de ponderación

## Ejercicio 01

Usted fue contratado por una agencia de viajes. La agencia a sus pasajeros
les solicita los siguientes datos: 

* Nombre
* Apellido
* Teléfono 
* DUI 
* Dirección 
* Num de vuelo

Estos datos deben ser almacenados en una lista para que la agencia pueda tener 
un mejor control de todos los viajantes. 

Realice un programa haciendo uso de: 

+ Struct anidado
+ Funciones 
+ Recursividad 

Los empleados de la agencia deben ser capaces de: 

+ Ingresar empleados
+ Ver empleados insertados al principio 
+ Ver todos los empleados
+ Filtrar viajantes por num de vuelo

**Filtrar viajantes por num de vuelo** 

Al ser varios viajantes los que irán en un vuelo, el programa debe ser capaz de mostrar
a todos los viajantes pertenecientes a un mismo vuelo.

-------------------------------------------------------------------------------------------------------------

## Ejercicio 02

Una agencia de correos necesita su ayuda. Los correos con los que trabajan tienen dos clasificaciones 
***Nacional*** e ***Internacional***, dependiendo de la clasificicación se separan en dos listas 
diferentes. 

Cuando una persona quiere enviar un correo, los datos que debe entregar son:

+ Nombre
+ Tipo (internacional / nacional)
+ Destinatario (nombre de persona que recibira el paquete)
+ DUI

Si el tipo del correo es ***internacional*** se le hacen las siguientes preguntas:

+ País de destino
+ Ciudad de destino

Si el tipo del correo es ***nacional*** se le hace una pregunta adicional: 
+ Ciudad de destino

Realice un programa que sea capaz de: 

+ Solicitar los datos anteriormente mencionados bajos las condiciones del tipo de correo
+ Clasificar los correos según su tipo 
+ Mostrar los correos internacionales y nacionales de manera separada y junta (como en el ejercicio de laboratorio)

Recuerde hacer uso de structs anidados, funciones, recursividad y todo lo aprendido durante esta materia
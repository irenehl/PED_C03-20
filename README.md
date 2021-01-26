# Repositorio PED 03/20

## Comandos de Git
<br> 

* Crear un repositorio local (inicializar un repositorio) <br>
    `git init`

* Clonar un repositorio <br>
    `git clone URL`

* Agregar archivos al área de preparación (memoria temporal) <br>
    `git add . `

* Guarda los cambios realizados, junto con un mensaje descriptivo. Los cambios aún no están en la nube. <br>
    `git commit -m MENSAJE`

* Se usa para enviar confirmaciones locales a la rama maestra del repositorio remoto, en otras palabras, para subir en la nube (GitHub) <br>
    `git push`

* Muestra la lista de los archivos que se han cambiado junto con los archivos que están por ser preparados o confirmados. <br>
    `git status`

* Puede ser usado para establecer una configuración específica de usuario, como el email, nombre de usuario y tipo de formato, etc. <br>
    `git config `

    La opción --global le dice a GIT que vas a usar ese correo electrónico para todos los repositorios locales. Si quieres utilizar diferentes correos electrónicos para diferentes repositorios

    ***Para todos los repositorios*** <br>
        `git config --global `
    
    ***Para varios usuarios de GitHub*** <br>
        `git config --local `



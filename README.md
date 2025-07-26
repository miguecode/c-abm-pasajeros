# ✈️ ABM Pasajeros - Aplicación de Consola en C

Este proyecto es una aplicación de consola, fue hecho en 2022 y se trata de un Menú ABM para una gestión básica de los pasajeros de un vuelo de avión.

## 📘 Descripción

ABM Pasajeros es una aplicación de consola que permite gestionar pasajeros mediante operaciones básicas de CRUD (Crear, Leer, Actualizar, Eliminar). Este es otro de mis proyectos hechos en C que hice en la época donde aprendía a programar, y cuenta con persistencia de datos en archivos de texto (.csv) y archivos binarios (.bin). También tiene un sistema para autogenerar un ID numérico incremental.

## 🚀 Menú

Así se ve la pantalla principal al iniciar el programa.

<img src="https://github.com/user-attachments/assets/4c25fe68-a97a-45e0-a66d-5e87423c1270" width="450"/>

## 🛠️ Funcionalidades

- **Alta de Pasajeros**: Permite agregar un nuevo pasajero al sistema.
- **Baja de Pasajeros**: Permite eliminar un pasajero existente del sistema.
- **Modificación de Pasajeros**: Permite actualizar la información de un pasajero existente.
- **Listado de Pasajeros**: Muestra una lista de todos las pasajeros en el sistema.
- **Ordenamiento de Pasajeros**: Permite ordenar la lista de pasajeros según el criterio seleccionado.
- **Cargar o Guardar la lista de Pasajeros**: Carga o guarda la lista de pasajeros del sistema, con la posibilidad de hacerlo desde un archivo de texto o binario.

## 👨‍💻 Cómo Ejecutar el Proyecto

Para ejecutar este proyecto, hay que seguir estos pasos:

1. Compilar el proyecto con un IDE que cuente con compilador o mediante la línea de comandos.
2. Ejecutar el archivo `outDebug.exe` que se genera en la carpeta `build/Debug`.
3. Listo, ya se puede interactuar con el menú ABM de Pasajeros desde la consola. 🎉

- Usando **Visual Studio Code**, la extensión ***C/C++ Runner*** es perfecta para compilar y ejecutar el programa. Para hacerlo, simplemente hay que seleccionar la carpeta 'src'. Al compilar, se crea el archivo 'outDebug.exe' (en la ubicación que determine el archivo 'launch.json' que está en la carpeta '.vscode'). Este archivo **'outDebug.exe'** es el que correrá la aplicación.

  <img src="https://github.com/user-attachments/assets/21aac7da-b211-4983-b944-9590aa125365" width="500"/>

## 📌 Aclaraciones
- Para evitar un error, se recomienda compilar y ejecutar el programa con la extensión C/C++ Runner de Visual Studio Code, pero en su menú original:
 
  <img src="https://github.com/user-attachments/assets/3c5c3683-7e50-4f39-a5a4-420cd6621083" width="700"/>
  
- Al igual que otros de mis proyectos en C, seguramente la aplicación tiene errores de funcionalidad dependiendo de cómo se manipulen los archivos que persisten los datos.
- En este caso, se trabaja con 3 archivos que necesitan estar dentro de la carpeta 'src': "data.bin", "data.csv" y "ultimaID.txt".
- Fue creado en 2022, mientras cursaba la carrera de Tecnicatura Universitaria en Programación, en la Universidad Tecnológica Nacional.
- No se aceptan contribuciones ni está bajo ninguna licencia específica.

## 🗃️ Otros proyectos similares
- [ABM de Notebooks - Aplicación de consola en C](https://github.com/miguecode/c-abm-notebooks)
- [Carga Películas - Aplicación de consola en C](https://github.com/miguecode/c-carga-peliculas)
- [Calcular Costos - Aplicación de consola en C](https://github.com/miguecode/c-calcular-costos)

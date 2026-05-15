# Sistema-de-Control-de-Acceso-RFID
Este proyecto es una solución integral para la gestión de acceso físico. Utiliza tecnología RFID para identificar usuarios, procesa la información mediante una aplicación de escritorio y valida los permisos en tiempo real contra una base de datos centralizada.
Hardware (Arduino): El lector RFID detecta un chip y envía el UID (Identificador Único) a través del puerto serial.

Capa de Enlace (Python): Un script actúa como puente, recibiendo el UID y realizando una petición HTTP al backend.

Backend (PHP & MySQL): El servidor recibe el ID, consulta la base de datos de alumnos/usuarios y verifica si tienen permitido el acceso en ese horario.

Respuesta: Si el acceso es válido, el sistema envía una señal de regreso al Arduino para accionar un servomotor (puerta).

🛠️ Stack Tecnológico
Lenguajes: C++ (Arduino), Python, PHP, SQL.

Base de Datos: MySQL.

Protocolos: Comunicación Serial (UART), SPI (para el lector RFID).

Hardware: Arduino Uno/Nano, Lector MFRC522, Servomotor.

📁 Estructura del Repositorio
/Arduino: Código fuente (.ino) para el microcontrolador.

/Python_Bridge: Script de automatización y enlace serial.

/Backend_PHP: Lógica de validación y conexión a BD.

/Database: Esquema .sql con la estructura de tablas y usuarios.

📝 Características Principales
Validación en Tiempo Real: Consulta dinámica basada en el estatus del usuario.

Seguridad: Los permisos se gestionan desde el servidor, no en el hardware local.

Escalabilidad: Diseñado para manejar múltiples puntos de acceso vinculados a una misma base de datos.

# Informe de Comparación de Árbol B

## Autores
- Piero Adrian Delgado Chipana
- Sebastian Adriano Castro Mamani
- Davis Yovanny Arapa Chua

## Introducción
Este informe presenta una comparación experimental de los tiempos de carga y búsqueda en un Árbol B utilizando distintos valores de MAX KEYS (1, 2 y 3). Se evalúa el impacto de esta configuración en el rendimiento del árbol al insertar y buscar datos de un archivo de números aleatorios.

## Resultados Experimentales

### 1. MAX_KEYS = 1
- **Tiempo total de carga de datos:** 246 ms
- **Tiempo de búsqueda para la llave 0.11:** 2 microsegundos

### 2. MAX_KEYS = 2
- **Tiempo total de carga de datos:** 262 ms
- **Tiempo de búsqueda para la llave 0.11:** 3 microsegundos

### 3. MAX_KEYS = 3
- **Tiempo total de carga de datos:** 245 ms
- **Tiempo de búsqueda para la llave 0.11:** 4 microsegundos

![Imagen de WhatsApp 2024-11-05 a las 20 25 38_cf432d2a](https://github.com/user-attachments/assets/855f8a9b-4b92-4fe4-a905-4436e1bbfec5)

## Análisis de Resultados

- **Carga de Datos:** Los tiempos de carga de datos no muestran una variación significativa entre los diferentes valores de MAX KEYS. Esto sugiere que la cantidad de claves permitida en cada nodo no tiene un impacto considerable en el rendimiento de inserción para este tamaño de datos específico.
- **Tiempo de Búsqueda:** Observamos un leve incremento en el tiempo de búsqueda al aumentar el valor de MAX KEYS. A medida que MAX KEYS crece, el árbol B tiene menos niveles debido a la mayor capacidad de claves por nodo, pero las búsquedas dentro de los nodos pueden requerir comparaciones adicionales, lo cual incrementa el tiempo.

## Conclusión

Para esta prueba específica, el tiempo de carga y búsqueda se ve ligeramente afectado por la configuración de MAX KEYS. Un valor más bajo de MAX KEYS tiende a ofrecer búsquedas marginalmente más rápidas, mientras que los tiempos de carga permanecen casi constantes. Esto sugiere que, para aplicaciones donde la velocidad de búsqueda es crítica, un menor valor de MAX KEYS podría ser ventajoso, aunque la diferencia es mínima.

**Link del código que mira los tiempos:** [Aquí](https://replit.com/join/vwivgulvtl-pdelgadoc)

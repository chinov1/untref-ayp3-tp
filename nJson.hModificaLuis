/* Header file for nJson */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _NJSON_H_
#define _NJSON_H_

/**
 * Defino un nuevo tipo de dato enumerado que represente los valores booleanos
 * de `true` y `false`
 * @type boolean
 */
typedef enum _boolean {
	FALSE, TRUE
} boolean;

/**
 * Defino un nuevo tipo de dato puntero a función para representar el prototipo
 * de las funciones de escritura especificos para cada tipo de dato contenido en
 * un nJson.
 * @type writer
 */
typedef void (*writer)(FILE*, void*, unsigned);

/**
 * Estructura base para los nodos de JSON.
 * @type nJson
 */
typedef struct _nJson {
	/**
	 * Nombre del nodo.
	 */
	char* name;
	/**
	 * Puntero al valor almacenado en el nodo.
	 */
	void* value;
	/**
	 * Tamaño en bytes del valor almacenado en el nodo.
	 */
	unsigned value_size;
	/*
	 * Cantidad de elementos del valor, utilizado para el manejo de arrays.
	 */
	unsigned cant_elementos;

	/**
	 * Puntero a la lista de atributos dentro del nodo. Solo hijos directos.
	 */
	struct _nJson* children;
	/**
	 * Puntero a al siguiente nodo hermano, cuando los nodos son atributos de un
	 * nodo padre.
	 */
	struct _nJson* next;
	/**
	 * Función para escribir el tipo de dato especifico guardado como valor del
	 * nodo.
	 */
	writer write;
} nJson;

/**
 * Inicializa un nJson.
 * @param this nJson sobre el cual operará.
 * @return nJson* Puntero al nJson con el cual se operó.
 */
nJson* njson_init(nJson* this);

/**
 * Define un valor que representa el contenido de un nJson.
 * @param this nJson sobre el cual operará.
 * @param name Nombre que recibirá el nJson cuando sea tratado como atributo.
 * @param value Puntero al data que debe ser almacenado como valor del nJson.
 * @param value_size Tamaño en memoria del valor que se almacenará en el nJson.
 * @param size Tamaño en memoria del nJson `child`
 * @return nJson* Puntero al nJson con el cual se operó.
 */
nJson* njson_set_value(nJson* this, const char* name, void* value,
		unsigned value_size, unsigned elementos, writer write);

/**
 * Agrega un atributo al nJson especificado.
 * @param this nJson sobre el cual operará.
 * @param attribute nJson que será agregado como atributo en el nJson `this`.
 * @param attribute_size Tamaño en memoria del nJson `child`
 * @return nJson* Puntero al nJson con el cual se operó.
 */
nJson* njson_add_attribute(nJson* this, nJson* attribute,
		unsigned attribute_size);

/**
 * Escribe el texto que representa al nJson en el descriptor de archivo provisto
 * a la función.
 * @param this nJson sobre el cual operará.
 * @return nJson* Puntero al nJson con el cual se operó.
 */
nJson* njson_write(nJson* this, FILE* output);

/**
 * Primitiva para liberar la memoria allocada para cada uno de los nodos de la
 * estructura de nJson recursivamente.
 * @param this nJson sobre el cual operará.
 */
void njson_release(nJson* this);

/**
 * Escribe un nJson como texto en el archivo espeficado.
 */
void write_njson(FILE* output, void* value, unsigned cantidad);

/**
 * Escribe una cadena de caracteres como texto en el archivo espeficado.
 */
void write_string(FILE* output, void* value, unsigned cantidad);

/**
 * Escribe un entero como texto en el archivo espeficado.
 */
void write_int(FILE* output, void* value, unsigned cantidad);

/**
 * Escribe un booleano como texto en el archivo espeficado.
 */
void write_boolean(FILE* output, void* value, unsigned cantidad);

/**
 * Escribe un flotante como texto en el archivo espeficado.
 */
void write_float(FILE* output, void* value, unsigned cantidad);

/**
 * Escribe un flotante de doble presición como texto en el archivo espeficado.
 */
void write_double(FILE* output, void* value, unsigned cantidad);

#endif /* _NJSON_H_ */

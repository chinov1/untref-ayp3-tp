/* Definition file for nJson */

#include "nJson.h"

nJson* njson_init(nJson* this) {
	this->name = 0x0;
	this->value = 0x0;
	this->value_size = 0x0;
	this->cant_elementos = 0x0;  //Miembro nuevo, necesariio para tratar arrays.
	this->children = 0x0;
	this->next = 0x0;
	this->write = 0x0;
	return this;
}

nJson* njson_set_value(nJson* this, const char* name, void* value,
		unsigned value_size, writer write) {
	this->name = (char*) malloc((strlen(name) + 1) * sizeof(char));
	strcpy(this->name, name);

	this->value = malloc(value_size);
	memcpy(this->value, value, value_size);

	this->value_size = value_size;

	this->write = write;

	if (this->children) {
		njson_release(this->children);
	}
	return this;
}
/*-----------------------------------------------
 * Realizo modificaciones:
 * comento la ejecucion de limpieza de memoria del final.
 * me borra los nombres de los Json internos(contents y photo_info).
 */
nJson* njson_add_attribute(nJson* this, nJson* attribute, unsigned attribute_size) {
	if (this->children) {
		nJson* current = this->children;
		while (current->next != 0x0) {
			current = current->next;
		}
		current->next = (nJson*) malloc(attribute_size);
		memcpy(current->next, attribute, attribute_size);
	} else {
		this->children = (nJson*) malloc(attribute_size);
		memcpy(this->children, attribute, attribute_size);
	}
/*
	free(this->name);
	this->name = 0x0;
	free(this->value);
	this->value = 0x0;
	this->value_size = 0x0;
*/
	return this;
}

nJson* njson_write(nJson* this, FILE* output) {
	int i;

	if (this->name) {
		fprintf(output, "\"%s\":", this->name);
	}


	if (this->value_size) {
		if(this->cant_elementos > 1){ fprintf(output, " [ ");} //Si cant_elementos es mayor a 1 es un array
		for(i = 0; i < this->cant_elementos; i=i+1){           //Trata a todos valores como un arrays,
		this->write(output, this->value, i);                   //de un elemento hasta la cant_elemmentos
		fprintf(output, ",");                                  //Imprime "," que se imprimia en el ultimo if
		}
		if(this->cant_elementos > 1){ fprintf(output, " ], ");}
	}



	if (this->children) {
		if(this->cant_elementos > 1){ fprintf(output, " [ ");} //agrega corchetes a los array de nJson
		fprintf(output, "{");
		njson_write(this->children, output);
		fprintf(output, "}");
		if(this->cant_elementos > 1){ fprintf(output, " ], ");}
}


	if (this->next) {
		//fprintf(output, ",");
		njson_write(this->next, output);
	}

	return this;
}

void njson_release(nJson* this) {
	free(this->name);
	this->name = 0x0;

	free(this->value);
	this->value = 0x0;
	this->value_size = 0x0;

	this->write = 0x0;

	if (this->next) {
		njson_release(this->next);
		this->next = 0x0;
	}

	if (this->children) {
		njson_release(this->children);
		this->children = 0x0;
	}
}

/*******************************************************************************
 * Funciones auxiliares para escribir los tipos de datos especificos.
 * Se agrega a todas el parametro unsigned cantidad.
 ******************************************************************************/

void write_njson(FILE* output, void* value, unsigned cantidad) { //En este caso no se trata al valor como un array
	njson_write((nJson*) value, output);                         //ya que la funcion itera sobre si misma, por lo cual
	                                                             //no se suma el desplazamiento cantidad al puntero.
}

void write_string(FILE* output, void* value, unsigned cantidad) {//Igual que  la anterior, no se utiliza el desplamiento
	fprintf(output, "\"%s\"", (char*) value );                   //debido a que, la funcion, trata al valor como un string
}                                                                //y no como una cadena de caracteres.

void write_int(FILE* output, void* value, unsigned cantidad) {
	fprintf(output, "%d", *((int*) value + cantidad));
}

void write_boolean(FILE* output, void* value, unsigned cantidad) {
	fprintf(output, "%s", (*((boolean*) value + cantidad)) ? "true" : "false");
}

void write_double(FILE* output, void* value, unsigned cantidad) {
	fprintf(output, "%f", *((double*) value + cantidad));
}

void write_float(FILE* output, void* value, unsigned cantidad) {
	fprintf(output, "%f", *((float*) value + cantidad));
}

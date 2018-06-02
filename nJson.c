/* Definition file for nJson */

#include "nJson.h"

nJson* njson_init(nJson* this) {
	this->name = 0x0;
	this->value = 0x0;
	this->value_size = 0x0;
	this->cant_elementos = 0x0;
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

	free(this->name);
	this->name = 0x0;
	free(this->value);
	this->value = 0x0;
	this->value_size = 0x0;

	return this;
}

nJson* njson_write(nJson* this, FILE* output) {
	if (this->name) {
		fprintf(output, "\"%s\":", this->name);
	}

	if (this->value_size) {
		this->write(output, this->value);
	}

	if (this->children) {
		fprintf(output, "{");
		njson_write(this->children, output);
		fprintf(output, "}");
	}

	if (this->next) {
		fprintf(output, ",");
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
 ******************************************************************************/

void write_njson(FILE* output, void* value) {
	njson_write((nJson*) value, output);
}

void write_string(FILE* output, void* value) {
	fprintf(output, "\"%s\"", (char*) value);
}

void write_int(FILE* output, void* value) {
	fprintf(output, "%d", *(int*) value);
}

void write_boolean(FILE* output, void* value) {
	fprintf(output, "%s", (*(boolean*) value) ? "true" : "false");
}

void write_double(FILE* output, void* value) {
	fprintf(output, "%f", *(double*) value);
}

void write_float(FILE* output, void* value) {
	fprintf(output, "%f", *(float*) value);
}

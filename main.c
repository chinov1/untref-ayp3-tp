

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "nJson.h"

#define SUCCESS 0
#define ERROR 1

void print_help() {
	printf("Generador de datos en formato JSON.\n\n");
	printf("uso: untref-ayp3-tp [-f <nombre_archivo>]\n\n");
}

int main(int argc, char **argv) {

	FILE* output_file;

	nJson root;
	njson_init(&root);

	// Primera entrega 2018-05-05
	{
		// Se leen los parametros provistos al programa.
		if (argc > 1) {

			if (argc == 3 && strcmp(argv[1], "-f") == 0
					&& strlen(argv[2]) > 0) {
				output_file = fopen(argv[2], "w");

				if (!output_file) {
					printf(
							"Ocurrió un error al tratar de crear o acceder al archivo especificado.\n");
					return ERROR;
				}
			} else {if(strcmp(argv[1], "-c") == 0){output_file = stdout;} //Opcion parametro -c para salida en pantalla.
				else{

					print_help();
					return ERROR;
			}

			}
		}
	}

 		// Segunda entrega 2018-05-19

 	
 		 {

 			    nJson root;
 			    njson_init(&root);


 				// Se definen los distintos nodos que formarán el JSON.
 				nJson size_attribute;
 				char* size_value = "0 bytes";
 				njson_init(&size_attribute);
 				njson_set_value(&size_attribute, "size", size_value,
 						strlen(size_value) + 1, 1, write_string);

 				nJson hash_attribute;
 				char* hash_value = "37eb1ba1849d4b0fb0b28caf7ef3af52";
 				njson_init(&hash_attribute);
 				njson_set_value(&hash_attribute, "hash", hash_value,
 						strlen(hash_value) + 1, 1, write_string);

 				nJson bytes_attribute;
 				int bytes_value = 0;
 				njson_init(&bytes_attribute);
 				njson_set_value(&bytes_attribute, "bytes", &bytes_value, sizeof(int),
 						1, &write_int);

 				nJson thumb_exists_attribute;
 				boolean thumb_exists_value = FALSE;
 				njson_init(&thumb_exists_attribute);
 				njson_set_value(&thumb_exists_attribute, "thumb_exists",
 						&thumb_exists_value, sizeof(boolean), 1,  &write_boolean);

 				nJson rev_attribute;
 				char* rev_value = "714f029684fe";
 				njson_init(&rev_attribute);
 				njson_set_value(&rev_attribute, "rev", rev_value, strlen(rev_value) + 1,
 						1, &write_string);

 				nJson modified_attribute;
 				char* modified_value = "Wed, 27 Apr 2011 22:18:51 +0000";
 				njson_init(&modified_attribute);
 				njson_set_value(&modified_attribute, "rev", modified_value,
 						strlen(modified_value) + 1, 1, &write_string);

 				nJson path_attribute;
 				char* path_value = "/Photos";
 				njson_init(&path_attribute);
 				njson_set_value(&path_attribute, "path", path_value,
 						strlen(path_value) + 1, 1, &write_string);

 				nJson is_dir_attribute;
 				boolean is_dir_value = TRUE;
 				njson_init(&is_dir_attribute);
 				njson_set_value(&is_dir_attribute, "is_dir", &is_dir_value,
 						sizeof(boolean), 1, &write_boolean);

 				nJson icon_attribute;
 				char* icon_value = "folder";
 				njson_init(&icon_attribute);
 				njson_set_value(&icon_attribute, "icon", icon_value,
 						strlen(icon_value) + 1, 1, &write_string);

 				nJson root_attribute;
 				char* root_value = "dropbox";
 				njson_init(&root_attribute);
 				njson_set_value(&root_attribute, "root", root_value,
 						strlen(root_value) + 1, 1, &write_string);

 				nJson revision_attribute;
 				int revision_value = 29007;
 				njson_init(&revision_attribute);
 				njson_set_value(&revision_attribute, "revision", &revision_value,
 						sizeof(int), 1, &write_int);

 				nJson coordinates_lat_attribute;
 				double coordinates_lat_value = 37.77256666666666;
 				njson_init(&coordinates_lat_attribute);
 				njson_set_value(&coordinates_lat_attribute, "lat",
 						&coordinates_lat_value, sizeof(double), 1, &write_double);

 				nJson coordinates_long_attribute;
 				double coordinates_long_value = -122.45934166666667;
 				njson_init(&coordinates_long_attribute);
 				njson_set_value(&coordinates_long_attribute, "long",
 						&coordinates_long_value, sizeof(double), 1, &write_double);

 				nJson coordinates_object;
 				njson_init(&coordinates_object);
 				njson_add_attribute(&coordinates_object, &coordinates_lat_attribute,
 						sizeof(coordinates_lat_attribute));
 				njson_add_attribute(&coordinates_object, &coordinates_long_attribute,
 						sizeof(coordinates_long_attribute));

 				nJson coordinate_attribute;
 				njson_init(&coordinate_attribute);
 				njson_set_value(&coordinate_attribute, "coordinate",
 						&coordinates_object,
 						sizeof(coordinates_object), 1, &write_njson);

 				// Se combinan los diferentes nodos sobre el nodo raiz.
 				njson_add_attribute(&root, &size_attribute, sizeof(size_attribute));
 				njson_add_attribute(&root, &hash_attribute, sizeof(hash_attribute));
 				njson_add_attribute(&root, &bytes_attribute, sizeof(bytes_attribute));
 				njson_add_attribute(&root, &thumb_exists_attribute,
 						sizeof(bytes_attribute));
 				njson_add_attribute(&root, &rev_attribute, sizeof(rev_attribute));
 				njson_add_attribute(&root, &modified_attribute,
 						sizeof(modified_attribute));
 				njson_add_attribute(&root, &path_attribute, sizeof(path_attribute));
 				njson_add_attribute(&root, &is_dir_attribute, sizeof(is_dir_attribute));
 				njson_add_attribute(&root, &coordinate_attribute,
 						sizeof(coordinate_attribute));
 				njson_add_attribute(&root, &icon_attribute, sizeof(icon_attribute));
 				njson_add_attribute(&root, &root_attribute, sizeof(root_attribute));
 				njson_add_attribute(&root, &revision_attribute,
 						sizeof(revision_attribute));


 				njson_write(&root, output_file);
 				njson_release(&root);


 		 }








	// Tercera entrega 2018-06-09

		// Se definen los distintos nodos que formarán el JSON.

 		///*-----------------nJson photo_info definicion ---------------------------*/
 	{
 		nJson contents_photo_info;
 		njson_init(&contents_photo_info);
 		njson_set_value(&contents_photo_info,"photo_info",NULL, 0, 1, &njson_write);

 		nJson photo_info_lat_long_attribute;
 		double photo_info_lat_long_value[2] = {37.77256666666666, -122.45934166666667};
 		njson_init(&photo_info_lat_long_attribute);
 		njson_set_value(&photo_info_lat_long_attribute, "lat_long", &photo_info_lat_long_value, sizeof(photo_info_lat_long_value), 2,&write_double);


 		njson_add_attribute(&contents_photo_info, &photo_info_lat_long_attribute, sizeof(photo_info_lat_long_attribute));


 		nJson photo_info_time_taken_attribute;
 		char* photo_info_time_taken_value = "Wed, 28 Aug 2013 18:12:02 +0000";
 		njson_init(&photo_info_time_taken_attribute);
 		njson_set_value(&photo_info_time_taken_attribute, "time_taken", photo_info_time_taken_value, strlen(photo_info_time_taken_value) + 1, 1, &write_string);

 		njson_add_attribute(&contents_photo_info, &photo_info_time_taken_attribute, sizeof(photo_info_time_taken_attribute));


 /*-----------------nJson contents definicion ---------------------------*/
 		nJson* contents;
 		njson_init(&contents);


 		njson_set_value(&contents,"contents",0x0, 0, 2,&write_njson);    // el quinto parametro de un nJson Padre
                                                                     // es mayor que 1 solo a los efectos de
 																	                                   // considerarlo un array.

 		njson_set_value(&contents,"contents",0x0, 0, 2,&write_njson);



	    nJson contents_size_attribute;
		char* contents_size_value = "2.3 MB";

		njson_init(&contents_size_attribute);
		njson_set_value(&contents_size_attribute, "size", contents_size_value,
				strlen(contents_size_value) + 1, 1, write_string);


		nJson contents_bytes_attribute;
		int contents_bytes_value = 2453963;
		njson_init(&contents_bytes_attribute);
		njson_set_value(&contents_bytes_attribute, "bytes", &contents_bytes_value, sizeof(int), 1, &write_int);

		nJson contents_thumb_exists_attribute;
		boolean contents_thumb_exists_value = TRUE;
		njson_init(&contents_thumb_exists_attribute);
		njson_set_value(&contents_thumb_exists_attribute, "thumb_exists",
				&contents_thumb_exists_value, sizeof(boolean), 1, &write_boolean);

		nJson contents_rev_attribute;
		char* contents_rev_value = "38af1b183490";
		njson_init(&contents_rev_attribute);
		njson_set_value(&contents_rev_attribute, "rev", contents_rev_value, strlen(contents_rev_value) + 1, 1, &write_string);

		nJson contents_modified_attribute;
		char* contents_modified_value = "Mon, 07 Apr 2014 23:13:16 +0000";
		njson_init(&contents_modified_attribute);
		njson_set_value(&contents_modified_attribute, "modified", contents_modified_value,
				strlen(contents_modified_value) + 1, 1, &write_string);

		nJson contents_path_attribute;
		char* contents_path_value = "/Photos/flower.jpg";
		njson_init(&contents_path_attribute);
		njson_set_value(&contents_path_attribute, "path", contents_path_value,
				strlen(contents_path_value) + 1, 1, &write_string);



		nJson contents_is_dir_attribute;
		boolean contents_is_dir_value = FALSE;
		njson_init(&contents_is_dir_attribute);
		njson_set_value(&contents_is_dir_attribute, "is_dir", &contents_is_dir_value,
				sizeof(boolean), 1, &write_boolean);


		nJson contents_icon_attribute;
		char* contents_icon_value = "page_white_picture";
		njson_init(&contents_icon_attribute);
		njson_set_value(&contents_icon_attribute, "icon", contents_icon_value,
				strlen(contents_icon_value) + 1, 1, &write_string);

		nJson contents_root_attribute;
		char* contents_root_value = "dropbox";
		njson_init(&contents_root_attribute);
		njson_set_value(&contents_root_attribute, "root", contents_root_value,
				strlen(contents_root_value) + 1, 1, &write_string);

		nJson contents_revision_attribute;
		int contents_revision_value = 14511;
		njson_init(&contents_revision_attribute);
		njson_set_value(&contents_revision_attribute, "revision", &contents_revision_value,
				sizeof(int), 1, &write_int);

		// Se combinan los diferentes nodos sobre el nodo nJson contents.
				njson_add_attribute(&contents, &contents_size_attribute, sizeof(contents_size_attribute));
				//njson_add_attribute(&contents, &contents_hash_attribute, sizeof(contents_hash_attribute));
				njson_add_attribute(&contents, &contents_bytes_attribute, sizeof(contents_bytes_attribute));
				njson_add_attribute(&contents, &contents_thumb_exists_attribute,
						sizeof(contents_bytes_attribute));
				njson_add_attribute(&contents, &contents_rev_attribute, sizeof(contents_rev_attribute));
				njson_add_attribute(&contents, &contents_modified_attribute,
						sizeof(contents_modified_attribute));
				njson_add_attribute(&contents, &contents_path_attribute, sizeof(contents_path_attribute));



				njson_add_attribute(&contents, &contents_photo_info, sizeof(contents_photo_info));

				njson_add_attribute(&contents, &contents_is_dir_attribute, sizeof(contents_is_dir_attribute));

				njson_add_attribute(&contents, &contents_icon_attribute, sizeof(contents_icon_attribute));
				njson_add_attribute(&contents, &contents_root_attribute, sizeof(contents_root_attribute));
				njson_add_attribute(&contents, &contents_revision_attribute,
			                 			sizeof(contents_revision_attribute));

/*-----------------nJson root definicion ---------------------------*/
		nJson root;
	    njson_init(&root);

	    njson_set_value(&root,"raiz",0x0, 0, 2,&write_njson);




	    nJson size_attribute;
		char* size_value = "0 bytes";
		njson_init(&size_attribute);
		njson_set_value(&size_attribute, "size", size_value,
				strlen(size_value) + 1, 1, write_string);

		nJson hash_attribute;
		char* hash_value = "37eb1ba1849d4b0fb0b28caf7ef3af52";
		njson_init(&hash_attribute);
		njson_set_value(&hash_attribute, "hash", hash_value,
				strlen(hash_value) + 1, 1, write_string);

		nJson bytes_attribute;
		int bytes_value = 0;
		njson_init(&bytes_attribute);
		njson_set_value(&bytes_attribute, "bytes", &bytes_value, sizeof(int), 1,
				&write_int);

		nJson thumb_exists_attribute;
		boolean thumb_exists_value = FALSE;
		njson_init(&thumb_exists_attribute);
		njson_set_value(&thumb_exists_attribute, "thumb_exists",
				&thumb_exists_value, sizeof(boolean), 1, &write_boolean);

		nJson rev_attribute;
		char* rev_value = "714f029684fe";
		njson_init(&rev_attribute);
		njson_set_value(&rev_attribute, "rev", rev_value, strlen(rev_value) + 1, 1,&write_string);

		nJson modified_attribute;
		char* modified_value = "Wed, 27 Apr 2011 22:18:51 +0000";
		njson_init(&modified_attribute);
		njson_set_value(&modified_attribute, "modified", modified_value,
				strlen(modified_value) + 1, 1, &write_string);

		nJson path_attribute;
		char* path_value = "/Photos";
		njson_init(&path_attribute);
		njson_set_value(&path_attribute, "path", path_value,
				strlen(path_value) + 1, 1, &write_string);


		nJson is_dir_attribute;
		boolean is_dir_value = TRUE;
		njson_init(&is_dir_attribute);
		njson_set_value(&is_dir_attribute, "is_dir", &is_dir_value,
				sizeof(boolean), 1, &write_boolean);


		nJson icon_attribute;
		char* icon_value = "folder";
		njson_init(&icon_attribute);
		njson_set_value(&icon_attribute, "icon", icon_value,
				strlen(icon_value) + 1, 1, &write_string);





		nJson root_attribute;
		char* root_value = "dropbox";
		njson_init(&root_attribute);
		njson_set_value(&root_attribute, "root", root_value,
				strlen(root_value) + 1, 1, &write_string);




		nJson revision_attribute;
		int revision_value = 29007;
		njson_init(&revision_attribute);
		njson_set_value(&revision_attribute, "revision", &revision_value,
				sizeof(int), 1, &write_int);






		printf("sizeof(nJson) %i\n", sizeof(nJson));
		// Se combinan los diferentes nodos sobre el nodo raiz.
		njson_add_attribute(&root, &size_attribute, sizeof(size_attribute));
		njson_add_attribute(&root, &hash_attribute, sizeof(hash_attribute));
		njson_add_attribute(&root, &bytes_attribute, sizeof(bytes_attribute));
		njson_add_attribute(&root, &thumb_exists_attribute,
				sizeof(bytes_attribute));
		njson_add_attribute(&root, &rev_attribute, sizeof(rev_attribute));
		njson_add_attribute(&root, &modified_attribute,
				sizeof(modified_attribute));
		njson_add_attribute(&root, &path_attribute, sizeof(path_attribute));
		njson_add_attribute(&root, &is_dir_attribute, sizeof(is_dir_attribute));
		njson_add_attribute(&root, &icon_attribute, sizeof(icon_attribute));
		njson_add_attribute(&root, &root_attribute, sizeof(root_attribute));

		njson_add_attribute(&root, &contents, sizeof(nJson));//sizeof(nJson) en lugar de sizeof(contents)

		njson_add_attribute(&root, &revision_attribute,
				sizeof(revision_attribute));


	njson_write(&root, output_file);

	int valor=32;
	//nJson* modificado;

	modificar_njson(&root,&root, "bytes", &valor, sizeof(valor));//Prueba la funcion modificar_njson().
	//eliminar_njson(&root, &root, "rev");                       //Prueba la funcion eliminar_njson().
	//eliminar_njson(&root, &contents, "bytes");                 //Prueba la funcion eliminar_njson().


	njson_write(&root, output_file);
	njson_release(&root);
}

	// Se asegura un último salto de línea en la escritura del archivo.
	fprintf(output_file, "\n");
	fclose(output_file);
 	return 0;//SUCCESS;
 }

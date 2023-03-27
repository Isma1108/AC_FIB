#include "CacheSim.h"
#include "string.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

//Para una mayor eficiencia con los módulos:
#define mod(S, N) ((S) & (N-1))   // devuelve S % N, cuando N es potencia de 2

//En lcache[i] hay el tag que hay en la línia iésima de cache
int lcache[128]; 

unsigned int hits = 0, misses = 0;



/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
	memset(lcache, -1, 128*sizeof(int));
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	t1=GetTime();
	/* Escriu aqui el teu codi */

	byte = mod(address, 32);
	bloque_m = address >> 5;
	linea_mc = mod(bloque_m, 128);
	tag = bloque_m >> 7;

	miss = replacement = tag_out = 0;

	if (lcache[linea_mc] != tag) {
		miss = 1;
		++misses;
		if (lcache[linea_mc] != -1) {
			replacement = 1;
			tag_out = lcache[linea_mc];
		}
		lcache[linea_mc] = tag;
	}
	else ++hits;

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print (address, byte, bloque_m, linea_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
	printf("En total se han hecho %d hits i %d misses\n", hits, misses);
}

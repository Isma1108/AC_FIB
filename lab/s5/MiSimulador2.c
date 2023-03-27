#include "CacheSim.h"
#include "string.h"
#include <stdio.h>


/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

//En lcache[i] hay el tag que hay en la línia iésima de cache

//Para una mayor eficiencia con los módulos:
#define mod(S, N) ((S) & (N-1))   // devuelve S % N, cuando N es potencia de 2

typedef struct {
	int tag[2]; //2 vias, en cada una hay un bloque identificado por cierto tag
	int lru;
} cj_cache;

unsigned int misses = 0, hits = 0;

cj_cache cache[64]; 


/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */
		memset(cache, -1, 64*sizeof(cj_cache));
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reemplaça una linia valida
	unsigned int tag_out;	   // TAG de la linia reemplaçada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)
	
	
	t1=GetTime();
	/* Escriu aqui el teu codi */
	
	byte = mod(address, 32);
	bloque_m = address >> 5;
	conj_mc = mod(bloque_m, 64);
	tag = bloque_m >> 6;
	miss = replacement = tag_out = 0;

	if (cache[conj_mc].tag[0] == tag) {cache[conj_mc].lru = via_mc = 0; ++hits;}
	else if (cache[conj_mc].tag[1] == tag) {cache[conj_mc].lru = via_mc = 1; ++hits;}
	else {
		miss = 1;
		++misses;
		if (cache[conj_mc].lru == 0) {
			if (cache[conj_mc].tag[1] != -1) {
				replacement = 1;
				tag_out = cache[conj_mc].tag[1];
			}
			cache[conj_mc].tag[1] = tag;
			cache[conj_mc].lru = via_mc = 1;
		}
		else {
			if (cache[conj_mc].tag[0] != -1) {
				replacement = 1;
				tag_out = cache[conj_mc].tag[0];
			}
			cache[conj_mc].tag[0] = tag;
			cache[conj_mc].lru = via_mc = 0;
		}
	}

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. També mesurem el temps d'execució
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
	printf("En total se han hecho %d hits i %d misses\n", hits, misses);
}

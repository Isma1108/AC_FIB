#include "CacheSim.h"
#include <string.h>
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

//Para una mayor eficiencia con los módulos:
#define mod(S, N) ((S) & (N-1))

typedef struct {
	int tag;	
	char dirty;
} linea;

linea cache[128];

unsigned int misses = 0, hits = 0;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
	for (int i = 0; i < 128; ++i) {
		cache[i].tag = -1;
		cache[i].dirty = 0;
	}
}

/* La rutina reference es cridada per cada referencia a simular */ 
void reference (unsigned int address, unsigned int LE)
{
	unsigned int byte;
	unsigned int bloque_m; 
	unsigned int linea_mc;
	unsigned int tag;
	unsigned int miss;
	unsigned int lec_mp;
	unsigned int mida_lec_mp;
	unsigned int esc_mp;
	unsigned int mida_esc_mp;
	unsigned int replacement;
	unsigned int tag_out;

	/* Escriu aqui el teu codi */
	
	byte = mod(address, 32);
	bloque_m = address >> 5;
	linea_mc = mod(bloque_m, 128);
	tag = bloque_m >> 7;
	
	miss = replacement = tag_out = 0;
	lec_mp = esc_mp = 0;
	
	if (cache[linea_mc].tag != tag) {
		++misses;
		miss = lec_mp = 1;
		mida_lec_mp = 32;
		if (cache[linea_mc].tag != -1) {
			replacement = 1;
			if (cache[linea_mc].dirty) {
				esc_mp = 1;
				mida_esc_mp = 32;
				cache[linea_mc].dirty = 0;
			}
			tag_out = cache[linea_mc].tag;
		}
		cache[linea_mc].tag = tag;
	}
	else ++hits;

	if (LE == escriptura) cache[linea_mc].dirty = 1;
	
	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual
	 * */
	test_and_print (address, LE, byte, bloque_m, linea_mc, tag,
			miss, lec_mp, mida_lec_mp, esc_mp, mida_esc_mp,
			replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */ 
void final ()
{
 	/* Escriu aqui el teu codi */ 
	//printf("Hits: %d Misses: %d\n", hits, misses);
  
}

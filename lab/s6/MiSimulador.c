#include "CacheSim.h"
#include <string.h>
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

//Para una mayor eficiencia con los módulos:
#define mod(S, N) ((S) & (N-1))

//En lcache[i] hay el TAG que ocupa la línia iésima de cache, -1 si està vacía
int lcache[128];

unsigned int misses = 0, hits = 0;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al començar cada un dels tests.
 * */
void init_cache ()
{
	/* Escriu aqui el teu codi */
	memset(lcache, -1, sizeof(lcache));
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
	
	if (LE == lectura) {
		if (lcache[linea_mc] != tag) {
			++misses;
			miss = lec_mp = 1;
			mida_lec_mp = 32;
			if (lcache[linea_mc] != -1) {
				replacement = 1;
				tag_out = lcache[linea_mc];
			}
			lcache[linea_mc] = tag;
		}
		else ++hits;
	}
	else {
		if (lcache[linea_mc] != tag) {miss = 1; ++misses;}
		else ++hits;
		esc_mp = 1;
		mida_esc_mp = 1;
	}

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

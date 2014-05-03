void mv_achr( CHAR_DATA *ch, char *argument, CHAR_DATA *actor,
			OBJ_DATA *obj, CHAR_DATA *rndm,
			CHAR_DATA *vict, OBJ_DATA *v_obj );
void mv_aint( CHAR_DATA *ch, char *argument, CHAR_DATA *actor,
			OBJ_DATA *obj, CHAR_DATA *rndm,
			CHAR_DATA *vict, OBJ_DATA *v_obj );
void mv_aobj( CHAR_DATA *ch, char *argument, CHAR_DATA *actor,
			OBJ_DATA *obj, CHAR_DATA *rndm,
			CHAR_DATA *vict, OBJ_DATA *v_obj );
void mv_astr( CHAR_DATA *ch, char *argument, CHAR_DATA *actor,
			OBJ_DATA *obj, CHAR_DATA *rndm,
			CHAR_DATA *vict, OBJ_DATA *v_obj );
void mv_chr( CHAR_DATA *ch, char *argument, CHAR_DATA *actor,
			OBJ_DATA *obj, CHAR_DATA *rndm,
			CHAR_DATA *vict, OBJ_DATA *v_obj );
void mv_int( CHAR_DATA *ch, char *argument, CHAR_DATA *actor,
			OBJ_DATA *obj, CHAR_DATA *rndm,
			CHAR_DATA *vict, OBJ_DATA *v_obj );
void mv_obj( CHAR_DATA *ch, char *argument, CHAR_DATA *actor,
			OBJ_DATA *obj, CHAR_DATA *rndm,
			CHAR_DATA *vict, OBJ_DATA *v_obj );
void mv_str( CHAR_DATA *ch, char *argument, CHAR_DATA *actor,
			OBJ_DATA *obj, CHAR_DATA *rndm,
			CHAR_DATA *vict, OBJ_DATA *v_obj );
bool oblicz_wyrazenie( CHAR_DATA *mob, char *wyrazenie, CHAR_DATA *actor,
			OBJ_DATA *obj, CHAR_DATA *rndm,
			CHAR_DATA *vict, OBJ_DATA *v_obj, int *zwr_typ,
			int *zwr_wart, char *zwr_txt, void **zwr_wsk );
void usun_z_listy( TYP_ZMIENNEJ **lista, TYP_ZMIENNEJ *zm, CHAR_DATA *mob );
void zmien_zmienna( TYP_ZMIENNEJ **lista, char *nazwa, int typ, int wartosc,
		void *wsk, CHAR_DATA *mob );
TYP_ZMIENNEJ *znajdz_zmienna( TYP_ZMIENNEJ *lista, char *nazwa );
TYP_ZMIENNEJ *znajdz_zmienna_moba( CHAR_DATA *mob, char *nazwa );

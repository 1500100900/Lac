int interpretuj_zmysly		args( ( CHAR_DATA *ch, const char *argument ) );
void	mprog_process_cmnd	args( ( char* cmnd, CHAR_DATA* mob,
					CHAR_DATA* actor, OBJ_DATA* obj,
					CHAR_DATA* rndm, CHAR_DATA* vict,
					OBJ_DATA* v_obj ) );

extern MTRIG_DATA *mtrig_list;
extern RRAND_DATA *rrand_list;

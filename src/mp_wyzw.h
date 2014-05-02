char *	asctime_progbug		args( ( const struct tm *timeptr ) );

void	eprog_bash_trigger	args( ( CHAR_DATA *ch, int door ) );
bool	eprog_bounce_trigger	args( ( CHAR_DATA *ch, int door ) );
void	eprog_close_trigger	args( ( CHAR_DATA *ch, int door ) );
void	eprog_dig_trigger	args( ( CHAR_DATA *ch, int door ) );
void	eprog_lock_trigger	args( ( CHAR_DATA *ch, int door ) );
void	eprog_open_trigger	args( ( CHAR_DATA *ch, int door ) );
void	eprog_pass_trigger	args( ( CHAR_DATA *ch, int door ) );
void	eprog_pick_trigger	args( ( CHAR_DATA *ch, int door ) );
void	eprog_unlock_trigger	args( ( CHAR_DATA *ch, int door ) );

void	mprog_aggr_attack_trigger args( ( CHAR_DATA *mob, CHAR_DATA *ch ) );
void	mprog_asleep_time_trigger args( ( CHAR_DATA *ch ) );
void	mprog_bribe_trigger	args( ( CHAR_DATA* mob, CHAR_DATA* ch,
					int amount ) );
bool	mprog_death_trigger	args( ( CHAR_DATA* mob, CHAR_DATA* ch ) ) __attribute__( ( warn_unused_result ) );
bool	mprog_descr_trigger	args( ( CHAR_DATA *mob, CHAR_DATA *ch ) );
void	mprog_entry_trigger	args( ( CHAR_DATA* mob ) );
void    mprog_feed_trigger	args( ( CHAR_DATA *mob, CHAR_DATA *ch,
					OBJ_DATA *obj ) );
void	mprog_fight_trigger	args( ( CHAR_DATA* mob, CHAR_DATA* ch ) );
void	mprog_give_trigger	args( ( CHAR_DATA* mob, CHAR_DATA* ch,
					OBJ_DATA* obj ) );
void	mprog_greet_trigger	args( ( CHAR_DATA* mob ) );
void	mprog_hitprcnt_trigger	args( ( CHAR_DATA* mob, CHAR_DATA* ch ) );
bool	mprog_long_descr_trigger args( ( CHAR_DATA *mob, CHAR_DATA *ch,
					char *buf ) );
char *	mprog_next_command	args( ( char* clist, char *cmnd ) );
void	mprog_random_trigger	args( ( CHAR_DATA* mob ) );
void	mprog_soc_trigger	args( ( char *txt, CHAR_DATA *mob,
					CHAR_DATA *actor ) );
void	mprog_speech_trigger	args( ( CHAR_DATA *ch,	char *txt,
					CHAR_DATA *vict ) );
void	mprog_spell_victim_trigger args( ( char *txt, CHAR_DATA *mob,
					CHAR_DATA *actor ) );
void	mprog_time_trigger	args( ( CHAR_DATA *ch ) );
void	mprog_water_trigger	args( ( CHAR_DATA *mob, CHAR_DATA *ch,
					OBJ_DATA *obj ) );
void	mprog_wordlist_check	args( ( char * arg, CHAR_DATA *mob,
					CHAR_DATA* actor, OBJ_DATA* object,
					CHAR_DATA* vict, OBJ_DATA* v_obj,
					int type, MPROG_DATA *program,
					int gdzie ) );

void	oprog_close_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
bool	oprog_descr_trigger	args( ( OBJ_DATA *obj, CHAR_DATA *ch ) );
void	oprog_dig_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
void	oprog_drop_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
void	oprog_give_trigger	args( ( CHAR_DATA *ch, CHAR_DATA *adresat,
					OBJ_DATA *obj ) );
bool	oprog_long_descr_trigger args( ( OBJ_DATA *obj, CHAR_DATA *ch,
					char *buf ) );
void	oprog_open_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
void	oprog_put_and_putin_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj,
					OBJ_DATA *container ) );
void	oprog_putin_gold_trigger args( ( CHAR_DATA *ch, int amount,
					OBJ_DATA *container ) );
void	oprog_remove_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
void	oprog_take_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
void	oprog_use_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj,
					char *argument ) );
void	oprog_wear_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );

void	progbug			args( ( CHAR_DATA *mob, const char *str,
					... ) ) __attribute__( ( format( printf, 2, 3 ) ) );
void	progdebug		args( ( CHAR_DATA *mob, const char *str,
					... ) ) __attribute__( ( format( printf, 2, 3 ) ) );

bool	rprog_descr_trigger	args( ( CHAR_DATA *ch, ROOM_INDEX_DATA *room,
					char *txt ) );
bool	rprog_do_trigger	args( ( CHAR_DATA *ch, char *cmd,
					char *arg, bool skrot ) );
void	rprog_drop_trigger	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
void	rprog_greet_trigger	args( ( CHAR_DATA *ch ) );
void	rprog_look_trigger	args( ( CHAR_DATA *ch ) );
void	rprog_random_trigger	args( ( ROOM_INDEX_DATA *room ) );
void	rprog_speech_trigger	args( ( char *txt, CHAR_DATA *ch ) );
void	rprog_time_trigger	args( ( ROOM_INDEX_DATA *room ) );
void	rprog_undug_trigger	args( ( CHAR_DATA *ch ) );

extern char descr_prog_buffer[ 2 * MSL ];
extern bool descr_prog_in_progress;
extern int prog_nest;

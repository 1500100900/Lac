/*
 * Lam 24.8.98
 */
struct timer_data
{
    TIMER_DATA	*next;
    CHAR_DATA	*ch;
    int		time;
    bool	paused;	/* Alandar: do zatrzymywania odliczania timera */
    TIMER_FUN	*fun;
    union
    {
	int	i;
	void *	p;
    } arg[ 4 ];
    /* 4 argumenty wystarcza, mozna tam umieszczac wszelkie typy danych */
};

/*
 * Lam 28.3.99
 */
struct airobj_data
{
    AIROBJ_DATA	*next;
    OBJ_DATA *obj;
/*    int wysokosc; */
};

/*
 * Lam 28.3.99
 */
struct airchar_data
{
    AIRCHAR_DATA *next;
    CHAR_DATA *chr;
    int wysokosc;
    bool slaby_plywak;
};


bool	act_flag_avail		args( ( int act ) );
char	*act_flag_name_pl	args( ( int act, CHAR_DATA *ch ) );
bool	affect_bit_avail	args( ( int *vector ) );
char	*affect_bit_name_pl	args( ( int *vector ) );
void	affect_from_room	args( ( ROOM_INDEX_DATA *room, int sn ) );
bool	affect_join		args( ( CHAR_DATA *ch, AFFECT_DATA *paf, int how ) );
bool	affect_loc_avail	args( ( int location ) );
const char *affect_loc_name_pl_b args( ( int location ) );
int	affect_lookup		args( ( const char *race ) );
void	affect_remove		args( ( CHAR_DATA *ch, AFFECT_DATA *paf, bool checks ) );
void	affect_strip		args( ( CHAR_DATA *ch, int sn ) );
void	affect_to_char		args( ( CHAR_DATA *ch, AFFECT_DATA *paf ) );
void	affect_to_room		args( ( ROOM_INDEX_DATA *room, AFFECT_DATA *paf ) );
int	apply_ac		args( ( OBJ_DATA *obj, int iWear ) );
bool	authorized		args( ( CHAR_DATA *ch, char *skllnm ) );
int	can_carry_n		args( ( CHAR_DATA *ch ) );
int	can_carry_w		args( ( CHAR_DATA *ch ) );
bool	can_drop_obj		args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
bool	can_enter_room		args( ( CHAR_DATA *ch, ROOM_INDEX_DATA *room,
					bool pokaz ) );
bool	can_equip_at		args( ( OBJ_DATA *obj, int at ) );
bool	can_equip_index_at	args( ( OBJ_INDEX_DATA *obj, int at ) );
int	can_move		args( ( CHAR_DATA *ch, ROOM_INDEX_DATA *in_room,
					ROOM_INDEX_DATA *to_room, int door, bool czy ) );
bool	can_see			args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
bool	can_see_dla_okna	args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
bool	can_see_obj		args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
bool	can_see_room		args( ( CHAR_DATA *ch, ROOM_INDEX_DATA *room ) );
bool	can_see_who		args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
void	char_from_room		args( ( CHAR_DATA *ch ) );
void	char_to_room		args( ( CHAR_DATA *ch, ROOM_INDEX_DATA *pRoomIndex ) );
void	check_airchar		args( ( CHAR_DATA *chr ) );
void	check_race_wearlocs	args( ( CHAR_DATA *ch ) );
int	count_obj_list		args( ( OBJ_INDEX_DATA *obj, OBJ_DATA *list ) );
OBJ_DATA *create_money		args( ( int amount ) );
bool	czy_mozna_kopac		args( ( int sector_type, CHAR_DATA *ch ) );
int	czy_pasuje		args( ( OBJ_DATA *obj, CHAR_DATA *ch ) );
void	czy_rekord_graczy	args( ( void ) );
void	czy_rekord_polaczen	args( ( void ) );
void	czytaj_ciala		args( ( void ) );	/* Lam - handler.c */
void	czytaj_ustawienia	args( ( void ) );
bool	czy_zajete_imie		args( ( char *imie ) );
void	del_airchar		args( ( AIRCHAR_DATA *airchar ) );
void	del_airobj		args( ( AIROBJ_DATA *airobj ) );
void	del_timer		args( ( TIMER_DATA *timer ) );
void	end_of_game		args( ( void ) );
bool	equip_char		args( ( CHAR_DATA *ch, OBJ_DATA *obj, int iWear ) );
char	*exit_info_name_pl	args( ( int flag ) );
bool	extra_bit_avail		args( ( int *extra_flags ) );
char	*extra_bit_name_pl	args( ( int *extra_flags, CHAR_DATA *ch ) );
char	*extra_bit_name_pl_dla_ludzi args( ( int *extra_flags, CHAR_DATA *ch ) );
void	extract_char		args( ( CHAR_DATA *ch, bool fPull ) );
void	extract_obj		args( ( OBJ_DATA *obj ) );
AIRCHAR_DATA *find_airchar	args( ( CHAR_DATA *chr ) );
TIMER_DATA *find_timer		args( ( CHAR_DATA *ch, TIMER_FUN *fun ) );
int	get_age			args( ( CHAR_DATA *ch ) );
CHAR_DATA *get_char		args( ( CHAR_DATA *ch ) );
CHAR_DATA *get_char_area	args( ( CHAR_DATA *ch, char *argument ) );
CHAR_DATA *get_char_area2	args( ( CHAR_DATA *ch, char *argument ) );
CHAR_DATA *get_char_room	args( ( CHAR_DATA *ch, char *argument ) );
CHAR_DATA *get_char_room2	args( ( CHAR_DATA *ch, char *argument ) );
CHAR_DATA *get_char_world	args( ( CHAR_DATA *ch, char *argument ) );
CHAR_DATA *get_char_world2	args( ( CHAR_DATA *ch, char *argument ) );
CHAR_DATA *get_char_world_pc	args( ( CHAR_DATA *ch, char *argument ) );
CHAR_DATA *get_char_world_pc_tele args( ( CHAR_DATA *ch, char *argument ) );
int	get_clanstat		args( ( CHAR_DATA *ch ) );
int	get_curr_con		args( ( CHAR_DATA *ch ) );
int	get_curr_dex		args( ( CHAR_DATA *ch ) );
int	get_curr_int		args( ( CHAR_DATA *ch ) );
int	get_curr_str		args( ( CHAR_DATA *ch ) );
int	get_curr_wis		args( ( CHAR_DATA *ch ) );
int	get_damroll		args( ( CHAR_DATA *ch, int wpn ) );
OBJ_DATA *get_eq_char		args( ( CHAR_DATA *ch, int iWear ) );
int	get_hitroll		args( ( CHAR_DATA *ch, int wpn ) );
CHAR_DATA *get_mob_world_vnum	args( ( CHAR_DATA *ch, char *argument ) );
OBJ_DATA *get_obj_carry		args( ( CHAR_DATA *ch, char *argument ) );
OBJ_DATA *get_obj_here		args( ( CHAR_DATA *ch, char *argument ) );
OBJ_DATA *get_obj_list		args( ( CHAR_DATA *ch, char *argument,
					OBJ_DATA *list ) );
int	get_obj_number		args( ( OBJ_DATA *obj ) );
OBJ_DATA *get_obj_przechowalnia args( ( CHAR_DATA *ch, char *argument ) );
OBJ_DATA *get_obj_wear		args( ( CHAR_DATA *ch, char *argument ) );
int	get_obj_weight		args( ( OBJ_DATA *obj ) );
int	get_obj_weight_vis_only	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
OBJ_DATA *get_obj_world 	args( ( CHAR_DATA *ch, char *argument ) );
OBJ_DATA *get_obj_world_vnum	args( ( CHAR_DATA *ch, char *argument ) ); /* Tissarius */
int	get_trust		args( ( CHAR_DATA *ch ) );
bool	is_affected		args( ( CHAR_DATA *ch, int sn ) );
bool	is_authorized		args( ( CHAR_DATA *ch, char *skllnm ) );
bool	jest_w_lodzi		args( ( CHAR_DATA *ch ) );
int	liquid_lookup		args( ( const char *liquid ) );
bool	longstring		args( ( CHAR_DATA *ch, char *argument ) );
int	material_lookup		args( ( const char *material ) );
int	material_lookup_short	args( ( const char *material ) );
bool	ma_w_multi 		args( ( CHAR_DATA *ch, int sn ) );
bool	moze_uzyc		args( ( CHAR_DATA *ch, int sn ) );
const char *name_expand		args( ( CHAR_DATA *viewer, CHAR_DATA *ch ) );
const char *name_expand_obj	args( ( CHAR_DATA *viewer, OBJ_DATA *obj ) );
AIRCHAR_DATA *new_airchar	args( ( CHAR_DATA *chr ) );
AIROBJ_DATA *new_airobj		args( ( OBJ_DATA *obj ) );
TIMER_DATA *new_timer		args( ( void ) ) __attribute__( ( warn_unused_result ) );
void	obj_from_char		args( ( OBJ_DATA *obj ) );
void	obj_from_obj		args( ( OBJ_DATA *obj ) );
void	obj_from_przechowalnia	args( ( OBJ_DATA *obj ) );
void	obj_from_room		args( ( OBJ_DATA *obj ) );
void	obj_to_char		args( ( OBJ_DATA *obj, CHAR_DATA *ch ) );
void	obj_to_obj		args( ( OBJ_DATA *obj, OBJ_DATA *obj_to ) );
void	obj_to_przechowalnia	args( ( OBJ_DATA *obj, CHAR_DATA *ch ) );
void	obj_to_room		args( ( OBJ_DATA *obj, ROOM_INDEX_DATA *pRoomIndex ) );
time_t	policz_czas		args( ( char *arg ) );
void	popraw_czas_krainy	args( ( AREA_DATA *pArea ) );
int	race_lookup		args( ( const char *race ) );
char	*room_flag_name_pl	args( ( int room ) );
bool	room_is_affected	args( ( ROOM_INDEX_DATA *room, int sn ) );
bool	room_is_dark		args( ( ROOM_INDEX_DATA *pRoomIndex ) );
bool	room_is_private		args( ( ROOM_INDEX_DATA *pRoomIndex ) );
void	run_timer		args( ( TIMER_DATA *timer ) );
void	save_equip_char		args( ( CHAR_DATA *ch, OBJ_DATA *obj, int iWear ) );
bool	saves_spell		args( ( int level, CHAR_DATA *victim ) );
int	skill_get_trust		args( ( CHAR_DATA *ch ) );
int	skill_lookup_ang	args( ( const char *name ) );
int	skill_lookup_pl		args( ( const char *name ) );
bool	sprawdz_deny		args( ( CHAR_DATA *ch ) );
void	sprawdz_przyzwyczajanie	args( ( ROOM_INDEX_DATA *room ) );
void	sprawdz_przyzwyczajanie_ch args( ( CHAR_DATA *dch, bool czy_ciemnia ) );
void	sprawdz_restrykcje	args( ( CHAR_DATA *ch ) );
void	sprawdz_ubranie		args( ( CHAR_DATA *ch ) );
void	sprawdz_wampira		args( ( CHAR_DATA *ch ) );
void	timer_update		args( ( void ) );
void	unequip_char		args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
void	unequip_char_save	args( ( CHAR_DATA *ch, OBJ_DATA *obj ) );
char	*wear_flag_name_pl	args( ( int wear_flags ) );
int	wiek_krainy		args( ( AREA_DATA *pArea ) );
void	wypelnij_poziomy	args( ( CHAR_DATA *ch, int *poziomy ) );
void	wywal_smieci		args( ( CHAR_DATA *ch ) );
void	zapisz_ustawienia	args( ( void ) );
int	zloto_w_pojemnikach	args( ( OBJ_DATA *lista ) );
void	zmien_imie_postaci	args( ( CHAR_DATA *victim, char *new_name ) );
void	zmien_wlasciciela_wszedzie args( ( CHAR_DATA *victim, char *new_name ) );

extern	AIRCHAR_DATA	*airchar_list;
extern	AIROBJ_DATA	*airobj_list;
extern	TIMER_DATA	*timer_list;
extern	int		top_timer;
extern	bool		wzmocnienie_affect_join;

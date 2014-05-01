DECLARE_DO_FUN(	do_areas	);
DECLARE_DO_FUN(	do_astat	); /* Lam */
DECLARE_DO_FUN(	do_memory	);
DECLARE_DO_FUN(	do_przeladuj	); /* Lam */


void		*alloc_mem	args( ( int sMem ) ) __attribute__( ( warn_unused_result ) );
void		*alloc_perm	args( ( int sMem ) ) __attribute__( ( warn_unused_result ) );
void		append_file	args( ( CHAR_DATA *ch, char *file, char *str ) );
void		area_update	args( ( void ) );
void		boot_db		args( ( bool edytor ) );
CHAR_DATA	*create_mobile	args( ( MOB_INDEX_DATA *pMobIndex ) ) __attribute__( ( warn_unused_result ) );
OBJ_DATA	*create_object	args( ( OBJ_INDEX_DATA *pObjIndex,
					int level ) ) __attribute__( ( warn_unused_result ) );
void		del_alias	args( ( CHAR_DATA *ch, ALIAS_DATA * alias ) );
void		del_exit	args( ( EXIT_DATA *ex ) );
void		del_mpquest	args( ( CHAR_DATA *ch, MPQUEST_DATA *mpquest ) );
void		del_refuse	args( ( CHAR_DATA *ch, REFUSE_DATA *refuse ) );
void		del_tell	args( ( CHAR_DATA *ch, TELL_DATA *tell ) );
void		dodaj_imie	args( ( IMIONA_DATA *im ) );
void		dod_zwod	args( ( ZWOD_DATA **lista, CHAR_DATA *cel ) );
MPQUEST_DATA	*find_mpquest	args( ( CHAR_DATA *ch, int vnum ) );
char		fread_letter	args( ( FILE *fp ) );
int		fread_number	args( ( FILE *fp, int *status ) );
void		fread_to_eol	args( ( FILE *fp ) );
char		*fread_word	args( ( FILE *fp, int *status, bool czy_wielo ) );
void		free_char	args( ( CHAR_DATA *ch, bool sprawdz ) );
void		free_mem	args( ( void *pMem, int sMem ) );
char		*get_extra_descr args( ( const char *name, EXTRA_DESCR_DATA *ed ) );
MOB_INDEX_DATA	*get_mob_index	args( ( int vnum ) );
OBJ_INDEX_DATA	*get_obj_index	args( ( int vnum ) );
ROOM_INDEX_DATA	*get_room_index	args( ( int vnum ) );
void		lac_perror	args( ( const char *str ) );
void		log_string	args( ( const char *str ) );
void		log_string_ch	args( ( CHAR_DATA *ch, const char *str ) );
AFFECT_DATA	*new_affect	args( ( void ) ) __attribute__( ( warn_unused_result ) );
ALIAS_DATA	*new_alias	args( ( void ) ) __attribute__( ( warn_unused_result ) );
CHAR_DATA	*new_character	args( ( bool player ) ) __attribute__( ( warn_unused_result ) );
EXIT_DATA	*new_exit	args( ( void ) ) __attribute__( ( warn_unused_result ) );
MPQUEST_DATA	*new_mpquest	args( ( void ) ) __attribute__( ( warn_unused_result ) );
MPROG_DATA	*new_mprog	args( ( void ) ) __attribute__( ( warn_unused_result ) );
OBJ_DATA	*new_object	args( ( void ) ) __attribute__( ( warn_unused_result ) );
REFUSE_DATA	*new_refuse	args( ( void ) ) __attribute__( ( warn_unused_result ) );
TELL_DATA	*new_tell	args( ( void ) ) __attribute__( ( warn_unused_result ) );
IMIONA_DATA	*nowe_imie	args( ( void ) );
void		real_areas	args( ( CHAR_DATA *ch, char *argument,
					WHO_DESCRIPTOR_DATA *d ) );
void		real_bug	args( ( const char *str, int param, const char *plik,
					int linia, const char *funkcja, bool zrzut,
					bool zrob_core ) );
void		real_fread_vector args( ( int *flag, unsigned int size, FILE *fp, int *status ) );
bool		strefa_nalezy	args( ( ZONE_DATA *strefa, ZONE_LIST *lista ) );
void		tail_chain	args( ( void ) );
void		wywal_zwod	args( ( ZWOD_DATA **lista, CHAR_DATA *cel ) );
void		zapisz_imiona	args( ( void ) );
KOLES_DATA	*znajdz_kolesia	args( ( int vnum ) );
ZONE_DATA	*znajdz_strefe	args( ( char *nazwa ) );
void		zwolnij_imie	args( ( IMIONA_DATA *im ) );


extern AFFECT_DATA		*affect_free;
extern AREA_DATA		*area_czysciec; /* Lam */
extern AREA_DATA		*area_first;
extern AUCTION_DATA		*auction;
extern char			bug_buf[ ];
extern CHAR_DATA		*char_list;
extern CLAN_DATA		*clan_free;
extern CLAN_DATA		*clan_list;
extern CLAN_MEMBER_DATA		*clan_member_free;
extern CLAN_REL_DATA		*clan_rel_free;
extern char			*daPrompt;
extern time_t			down_time;
extern bool			fBootDb;
extern FIGHT_DATA		*fight_free;
extern HELP_DATA		*help_first;
extern char			*help_greeting;
extern char			*help_namehelp;
extern char			*hint_table[ MAX_HINT ];
extern FILE			*httpdlog;
extern char			HTTPD_log[ MIL ];
extern int			ilosc_czesci_ciala[ MAX_RACE ];
#if defined( IMUD )
extern	bool			imud_down; /* Lam */
#endif
extern IMIONA_DATA		*imiona[ MAX_DLUG_IMIENIA + 1 ][ 64 ];
extern KILL_DATA		kill_table[ ];
extern char			log_buf[ ];
extern char			lsc_clear_str[ MAX_INPUT_LENGTH ];
extern char			lsc_delimiter;
extern char			lsc_init_str[ MAX_INPUT_LENGTH ];
extern unsigned int		lsc_init_str_len;
extern struct miodek_data	miodek_table[ MAX_OFFENSIVE ];
extern MOB_INDEX_DATA		*mob_index_hash[ MAX_KEY_HASH ];
extern long			mud_age;
extern int			multi_count[ MAX_CLASS ];
extern NOTE_DATA		*note_free;
extern NOTE_DATA		*note_list;
extern OBJ_DATA			*object_list;
extern OBJ_DATA			*obj_free;
extern bool			ODPLUSKWIACZ;
extern char			*offensive_table[ MAX_OFFENSIVE ];
extern char			posdead_buf[ ];
extern int			pose_count[ MAX_CLASS ];
extern struct pose_data		pose_table[ MAX_CLASS ][ MAX_POSE ];
extern struct powody_data	powody[ MAX_POWODY ];
extern bool			PRZERABIACZ;
extern int			quit_count;
extern char			*quit_table[ MAX_QUIT ];
extern bool			Reboot;
extern ROOM_INDEX_DATA		*room_index_hash[ MAX_KEY_HASH ];
extern SCHEMAT_DATA		*schemat_list;
extern int			skill_count[ MAX_CLASS ];
extern SORTED_SKILL_DATA	*sorted_skill_list;
extern TIME_INFO_DATA		time_info;
extern int			top_clan;
extern int			top_clan_member;
extern int			top_clan_rel;
extern int			top_fight;
extern int			top_mob_index;
extern int			top_obj_index;
extern int			top_stosmp;
extern int			top_trap;
extern int			top_zmienna;
extern time_t			warning1;
extern time_t			warning2;
extern WEATHER_DATA		weather_info;
extern ZONE_DATA		*zone_first;
extern ZWOD_DATA		*zwod_free;
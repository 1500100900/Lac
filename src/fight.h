DECLARE_DO_FUN(	do_backstab	);
DECLARE_DO_FUN(	do_berserk	); /* by Thelonius */
DECLARE_DO_FUN(	do_change	); /* Lam */
DECLARE_DO_FUN(	do_circle_skill	); /* by Thelonius * do_circle() istnieje w bibliotece Allegro, wiec zmienilem tu */
DECLARE_DO_FUN(	do_disarm	);
DECLARE_DO_FUN(	do_flee		);
DECLARE_DO_FUN(	do_fury		); /* Qwert */
DECLARE_DO_FUN(	do_kick		);
DECLARE_DO_FUN(	do_kill		);
DECLARE_DO_FUN(	do_murder	);
DECLARE_DO_FUN(	do_pojedynek	); /* Lam */
DECLARE_DO_FUN(	do_rescue	);
DECLARE_DO_FUN(	do_sla		);
DECLARE_DO_FUN(	do_slay		);
DECLARE_DO_FUN(	do_socials	);

void	check_killer		args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
bool	czy_grupa_wrogow	args( ( CHAR_DATA *ch, CHAR_DATA *gch ) );
bool	czy_morderstwo		args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
void	damage			args( ( CHAR_DATA *ch, CHAR_DATA *victim, int dam,
					int dt, int wpn, bool czy_bez_walki ) );
void	death_cry		args( ( CHAR_DATA *ch, int dt, int pozycja ) );
void	dodaj_zabojce		args( ( CHAR_DATA *ofiara, CHAR_DATA *zabojca ) );
bool	group_gain		args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
bool	is_fighting		args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
bool	is_safe			args( ( CHAR_DATA *ch, CHAR_DATA *victim, bool czy ) );
void	multi_hit		args( ( CHAR_DATA *ch, CHAR_DATA *victim, int dt ) );
unsigned char ocen_przedmiot	args( ( int v1, int v2, int v3 ) );
void	one_hit			args( ( CHAR_DATA *ch, CHAR_DATA *victim, int dt,
					int wpn ) );
void	pp_get			args( ( CHAR_DATA *ch, char *victim_name ) ); /* Qwert */
void	raw_kill		args( ( CHAR_DATA *ch, CHAR_DATA *victim,
					bool czy_bez_walki, bool czy_dodac_zgon,
					int typ_zgonu ) );
void	set_fighting		args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
void	stop_fighting		args( ( CHAR_DATA *ch, bool fBoth ) );
void	stop_fighting_char	args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
void	strata_dosw_za_smierc	args( ( CHAR_DATA *victim ) );
void	update_pos		args( ( CHAR_DATA *victim ) );
void	violence_update		args( ( void ) );
int	xp_compute		args( ( CHAR_DATA *gch, CHAR_DATA *victim ) );
#if defined( __DMC__ ) || defined( PLAN9 )
CHAR_DATA *fighting_func	args( ( CHAR_DATA *ch ) );
#endif

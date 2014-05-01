DECLARE_DO_FUN(	do_clan	); /* Lam */

bool		can_see_clan	args( ( CHAR_DATA *ch, CLAN_DATA *clan ) );
void		check_clan_rel	args( ( void ) );
void		clan_log	args( ( CLAN_DATA *clan, char *str ) );
CLAN_DATA	*clan_lookup	args( ( char *arg ) );
CLAN_DATA	*clan_lookup2	args( ( char *arg ) );
CLAN_MEMBER_DATA *clan_member_new args( ( void ) ) __attribute__( ( warn_unused_result ) );
CLAN_DATA	*clan_new	args( ( void ) ) __attribute__( ( warn_unused_result ) );
CLAN_REL_DATA	*clan_rel_lookup args( ( CLAN_DATA *clana, CLAN_DATA *clanb ) );
CLAN_REL_DATA	*clan_rel_new	args( ( void ) ) __attribute__( ( warn_unused_result ) );
void		clan_remove	args( ( CLAN_DATA *clan ) );
bool		is_any_clan_member args( ( CHAR_DATA *ch ) );
bool		is_clan_member	args( ( CHAR_DATA *ch, CLAN_DATA *clan ) );
bool		is_same_clan	args( ( CHAR_DATA *ch, CHAR_DATA *victim ) );
bool		load_clan_statut args( ( CLAN_DATA *clan ) );
void		real_clan_info	args( ( CHAR_DATA *ch, CLAN_DATA *cl, WHO_DESCRIPTOR_DATA *d ) );
void		real_clan_lista	args( ( CHAR_DATA *ch, char *argument, WHO_DESCRIPTOR_DATA *d ) );
void		write_clan	args( ( CLAN_DATA *clan, int flagi ) );
void		write_clans( void );
void		zapisz_urny( void );

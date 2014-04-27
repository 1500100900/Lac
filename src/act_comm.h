DECLARE_DO_FUN(	do_beep		);
DECLARE_DO_FUN(	do_bug		);
DECLARE_DO_FUN(	do_chat		);
DECLARE_DO_FUN(	do_clan_chat	); /* Lam */
#if defined( MAM_SKASUJ )
DECLARE_DO_FUN(	do_delet	); /* Lam */
DECLARE_DO_FUN(	do_delete	); /* Lam */
#endif
DECLARE_DO_FUN(	do_delete_disabled); /* Lam */
DECLARE_DO_FUN(	do_email	); /* Lam */
DECLARE_DO_FUN(	do_emote	);
DECLARE_DO_FUN(	do_flame	); /* Lam */
DECLARE_DO_FUN(	do_follow	);
DECLARE_DO_FUN(	do_godtalk	); /* Lam */
DECLARE_DO_FUN(	do_grats	); /* Lam */
DECLARE_DO_FUN(	do_group	);
DECLARE_DO_FUN(	do_gtell	);
DECLARE_DO_FUN(	do_idea		);
DECLARE_DO_FUN(	do_ignore	); /* Lam */
DECLARE_DO_FUN(	do_immtalk	);
#if defined( IMUD )
DECLARE_DO_FUN(	do_imud		); /* Lam */
#endif
DECLARE_DO_FUN(	do_licz		); /* Lam */
DECLARE_DO_FUN(	do_monitor	); /* Lam */
DECLARE_DO_FUN(	do_mowdo	); /* Lam */
DECLARE_DO_FUN(	do_music	);
DECLARE_DO_FUN(	do_note		);
DECLARE_DO_FUN(	do_order	);
DECLARE_DO_FUN(	do_pose		);
DECLARE_DO_FUN(	do_quest	); /* Lam/Aldar/Quad/Winchester */
DECLARE_DO_FUN(	do_qui		);
DECLARE_DO_FUN(	do_quit		);
DECLARE_DO_FUN(	do_qwertalk	); /* Lam */
DECLARE_DO_FUN(	do_rent		);
DECLARE_DO_FUN(	do_reply	);
DECLARE_DO_FUN(	do_retell	); /* Lam */
DECLARE_DO_FUN(	do_save		);
DECLARE_DO_FUN(	do_say		);
DECLARE_DO_FUN(	do_separator	); /* Lam i Albi */
DECLARE_DO_FUN(	do_shout	);
DECLARE_DO_FUN(	do_split	);
DECLARE_DO_FUN(	do_tell		);
DECLARE_DO_FUN(	do_typo		);
DECLARE_DO_FUN(	do_wciel	); /* Lam */
DECLARE_DO_FUN(	do_whisper	); /* Lam */
DECLARE_DO_FUN(	do_yell		);


void	add_follower		args( ( CHAR_DATA *ch, CHAR_DATA *master ) );
bool	can_quit_now		args( ( CHAR_DATA *ch, bool fCicho ) );
void	die_follower		args( ( CHAR_DATA *ch ) );
bool	is_note_to		args( ( CHAR_DATA *ch, NOTE_DATA *pnote ) );
bool	is_same_group		args( ( CHAR_DATA *ach, CHAR_DATA *bch ) );
void	rewrite_all_notes 	args( ( void ) );
void	stop_follower		args( ( CHAR_DATA *ch ) );
void	talk_auction		args( ( char *argument ) );
#if defined( BLEDOMAT )
void	wczytaj_bledomat	args( ( void ) );
#endif

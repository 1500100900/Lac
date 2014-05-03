DECLARE_DO_FUN(	do_advance	);
DECLARE_DO_FUN(	do_aexits	);	/* Lam */
DECLARE_DO_FUN(	do_allow	);
DECLARE_DO_FUN(	do_asave	);	/* Lam */
DECLARE_DO_FUN(	do_at		);
DECLARE_DO_FUN(	do_bamfin	);
DECLARE_DO_FUN(	do_bamfout	);
DECLARE_DO_FUN(	do_ban		);	/* Lam */
DECLARE_DO_FUN(	do_bezkoloru	);	/* Lam */
DECLARE_DO_FUN(	do_bkukla	);	/* Vigud */
DECLARE_DO_FUN(	do_cecho	);	/* Lam */
DECLARE_DO_FUN(	do_count	);	/* Lam */
DECLARE_DO_FUN(	do_deny		);
DECLARE_DO_FUN(	do_disconnect	);
DECLARE_DO_FUN(	do_echo		);
DECLARE_DO_FUN(	do_epstat	);	/* Lam */
DECLARE_DO_FUN(	do_exp		);	/* Lam */
DECLARE_DO_FUN(	do_force	);
DECLARE_DO_FUN(	do_freeze	);
DECLARE_DO_FUN(	do_fstat	);	/* Lam */
DECLARE_DO_FUN(	do_gladuj	);	/* Lam */
DECLARE_DO_FUN(	do_goto		);
DECLARE_DO_FUN(	do_holylight	);
DECLARE_DO_FUN(	do_immcmd	);	/* Lam */
DECLARE_DO_FUN(	do_imtlset	);
DECLARE_DO_FUN(	do_info		);	/* Lam */
DECLARE_DO_FUN(	do_invis	);
DECLARE_DO_FUN(	do_kogobic	);	/* Vigud */
DECLARE_DO_FUN(	do_laguj	);	/* Qwert */
DECLARE_DO_FUN(	do_lecnowy	);	/* Lam */
DECLARE_DO_FUN(	do_log		);
DECLARE_DO_FUN(	do_mfind	);
DECLARE_DO_FUN(	do_mistat	);	/* Alucard */
DECLARE_DO_FUN(	do_mklon	);	/* Winchester */
DECLARE_DO_FUN(	do_mlista	);	/* Lam */
DECLARE_DO_FUN(	do_mload	);
DECLARE_DO_FUN(	do_mpodpluskw	);	/* Lam */
DECLARE_DO_FUN(	do_mpstat	);
DECLARE_DO_FUN(	do_mset		);
DECLARE_DO_FUN(	do_mstat	);
DECLARE_DO_FUN(	do_mwhere	);
DECLARE_DO_FUN(	do_newlock	);
DECLARE_DO_FUN(	do_noemote	);
DECLARE_DO_FUN(	do_notell	);
DECLARE_DO_FUN(	do_numlock	);
DECLARE_DO_FUN(	do_oaff		);	/* Lam */
DECLARE_DO_FUN(	do_odwampirz	);
DECLARE_DO_FUN(	do_ofind	);
DECLARE_DO_FUN(	do_oglos	);
DECLARE_DO_FUN(	do_oklon	);	/* Winchester */
DECLARE_DO_FUN(	do_oload	);
DECLARE_DO_FUN(	do_opstat	);	/* Lam */
DECLARE_DO_FUN(	do_oset		);
DECLARE_DO_FUN(	do_ostat	);
DECLARE_DO_FUN(	do_owhere	);
DECLARE_DO_FUN(	do_pardon	);
DECLARE_DO_FUN(	do_peace	);
DECLARE_DO_FUN(	do_plista	);
DECLARE_DO_FUN(	do_pomlista	);
DECLARE_DO_FUN(	do_pomszukaj	);	/* Lam */
DECLARE_DO_FUN(	do_purge	);
DECLARE_DO_FUN(	do_racestat	);	/* Lam */
DECLARE_DO_FUN(	do_reboo	);
DECLARE_DO_FUN(	do_reboot	);
DECLARE_DO_FUN(	do_recho	);
DECLARE_DO_FUN(	do_refuse	);	/* Gimza */
DECLARE_DO_FUN(	do_rekord	);	/* Lam */
DECLARE_DO_FUN(	do_rename	);	/* EA, sciagnal Lam */
DECLARE_DO_FUN(	do_restar	);	/* Lam */
DECLARE_DO_FUN(	do_restart	);	/* Lam */
DECLARE_DO_FUN(	do_restore	);
DECLARE_DO_FUN(	do_return	);
DECLARE_DO_FUN(	do_rhist	);	/* Lam */
DECLARE_DO_FUN(	do_rpstat	);	/* Lam */
DECLARE_DO_FUN(	do_rset		);
DECLARE_DO_FUN(	do_rstat	);
DECLARE_DO_FUN(	do_shutdow	);
DECLARE_DO_FUN(	do_shutdown	);
DECLARE_DO_FUN(	do_silence	);
DECLARE_DO_FUN(	do_slookup	);
DECLARE_DO_FUN(	do_snoop	);
DECLARE_DO_FUN(	do_sset		);
DECLARE_DO_FUN(	do_sstime	);
DECLARE_DO_FUN(	do_stopien	);	/* Lam */
DECLARE_DO_FUN(	do_switch	);
DECLARE_DO_FUN(	do_teleciap	);	/* Lam */
DECLARE_DO_FUN(	do_teleecho	);	/* Lam */
DECLARE_DO_FUN(	do_test		);	/* Lam */
DECLARE_DO_FUN(	do_transfer	);
DECLARE_DO_FUN(	do_trust	);
DECLARE_DO_FUN(	do_ulista	);	/* Lam */
DECLARE_DO_FUN(	do_users	);
DECLARE_DO_FUN(	do_vnumy	);	/* Lam */
DECLARE_DO_FUN(	do_wizhelp	);
DECLARE_DO_FUN(	do_wizlock	);
DECLARE_DO_FUN(	do_wiznet	);	/* Lam */
DECLARE_DO_FUN(	do_wymus	);	/* Lam */
DECLARE_DO_FUN(	do_zadstat	);	/* Ulryk */
DECLARE_DO_FUN(	do_zadustaw	);	/* Ulryk */


extern		BAN_DATA	*ban_free;
extern		BAN_DATA	*ban_list;

char		*ascdata		args( ( const struct tm *timeptr ) );
ROOM_INDEX_DATA	*find_location		args( ( CHAR_DATA *ch, char *arg ) );
const char	*item_type_name_pl	args( ( OBJ_DATA *obj ) );
void		konwersja_bumi		args( ( CHAR_DATA *ch ) );
const char	*krotko_bezczynnosc	args( ( int idle ) );
REFUSE_DATA	*refuse_lookup		args( ( CHAR_DATA *ch, char *arg ) );
void		wiznet		args( ( const char *string, CHAR_DATA *ch,
				OBJ_DATA *obj, void *arg, int flag, int no_flag,
				int min_level ) );

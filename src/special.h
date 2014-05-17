struct spec_type
{
    SPEC_FUN *fun;
    char *name;
};


extern char		spec_list[ MSL ];
extern const struct spec_type spec_table[ ];
extern SPEC_FUN		*spec_lookup	args( ( const char *name ) );
extern char		*spec_name	args( ( SPEC_FUN *fun ) );
extern void		build_spec_list	args( ( void ) );
extern bool		papuguj		args( ( CHAR_DATA *ch, char *argument ) );


/*
 * The following special functions are available for mobiles.
 */
extern DECLARE_SPEC_FUN(	spec_breath_any		);
extern DECLARE_SPEC_FUN(	spec_breath_acid	);
extern DECLARE_SPEC_FUN(	spec_breath_fire	);
extern DECLARE_SPEC_FUN(	spec_breath_frost	);
extern DECLARE_SPEC_FUN(	spec_breath_gas		);
extern DECLARE_SPEC_FUN(	spec_breath_lightning	);
extern DECLARE_SPEC_FUN(	spec_cast_adept		);
extern DECLARE_SPEC_FUN(	spec_cast_cleric	);
extern DECLARE_SPEC_FUN(	spec_cast_ghost		);
extern DECLARE_SPEC_FUN(	spec_cast_mage		);
extern DECLARE_SPEC_FUN(	spec_cast_psionicist	);
extern DECLARE_SPEC_FUN(	spec_cast_undead	);
extern DECLARE_SPEC_FUN(	spec_executioner	);
extern DECLARE_SPEC_FUN(	spec_fido		);
extern DECLARE_SPEC_FUN(	spec_guard		);
extern DECLARE_SPEC_FUN(	spec_healer		); /* Lam 1997 */
extern DECLARE_SPEC_FUN(	spec_janitor		);
extern DECLARE_SPEC_FUN(	spec_mayor		);
extern DECLARE_SPEC_FUN(	spec_poison		);
extern DECLARE_SPEC_FUN(	spec_parrot		); /* Ulryk 26.02.2003 */
extern DECLARE_SPEC_FUN(	spec_repairman		);
extern DECLARE_SPEC_FUN(	spec_thief		);
extern DECLARE_SPEC_FUN(	spec_unicorn		); /* Ulryk 03.03.2002 */
extern DECLARE_SPEC_FUN(	spec_vampire_elder	); /* Ulryk 20.11.2003 */
extern DECLARE_SPEC_FUN(	spec_waker		); /* Qwert 12.11.2000 */

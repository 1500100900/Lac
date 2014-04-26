/*
 * Ulryk: nekromanta
 */

extern void zwolnij_sluge		args( ( CHAR_DATA *ch ) );
extern void zabij_wszystkie_slugi	args( ( CHAR_DATA *ch ) );

DECLARE_SPELL_FUN(	spell_aura_strachu	);
DECLARE_SPELL_FUN(	spell_cienisty_pocisk	);
DECLARE_SPELL_FUN(	spell_eksplozja		);
DECLARE_SPELL_FUN(	spell_kontrola_umyslu	);
DECLARE_SPELL_FUN(	spell_koszmar		);
DECLARE_SPELL_FUN(	spell_kradziez_cienia	);
DECLARE_SPELL_FUN(	spell_mroczny_plomien	);
DECLARE_SPELL_FUN(	spell_mroczny_znak	);
DECLARE_SPELL_FUN(	spell_nekromantyczna_zbroja);
DECLARE_SPELL_FUN(	spell_odeslanie		);
DECLARE_SPELL_FUN(	spell_pocalunek_smierci	);
DECLARE_SPELL_FUN(	spell_przeklety_deszcz	);
DECLARE_SPELL_FUN(	spell_sprowadzenie_szkieletu);
DECLARE_SPELL_FUN(	spell_strefa_cienia	);
DECLARE_SPELL_FUN(	spell_stworzenie_mumii	);
DECLARE_SPELL_FUN(	spell_tarcza_umarlych	);
DECLARE_SPELL_FUN(	spell_tarcza_zla	);
DECLARE_SPELL_FUN(	spell_wejrzenie		);
DECLARE_SPELL_FUN(	spell_wskrzeszenie	);
DECLARE_SPELL_FUN(	spell_wycienczenie	);
DECLARE_SPELL_FUN(	spell_wyssanie_duszy	);
DECLARE_SPELL_FUN(	spell_wzmocnienie_umyslu);

DECLARE_WEAR_OFF_FUN(	wear_off_strefa_cienia	);

DECLARE_DO_FUN(	do_balsamuj			);

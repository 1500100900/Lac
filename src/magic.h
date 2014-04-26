/*
 * Psi spell_functions, in magic.c (by Thelonius).
 */
DECLARE_SPELL_FUN(	spell_adrenaline_control);
DECLARE_SPELL_FUN(	spell_agitation		);
DECLARE_SPELL_FUN(	spell_awe		);
DECLARE_SPELL_FUN(	spell_ballistic_attack	);
DECLARE_SPELL_FUN(	spell_bariera_zla	);
DECLARE_SPELL_FUN(	spell_cell_adjustment	);
DECLARE_SPELL_FUN(	spell_combat_mind	);
DECLARE_SPELL_FUN(	spell_complete_healing	);
DECLARE_SPELL_FUN(	spell_control_flames	);
DECLARE_SPELL_FUN(	spell_death_field	);
DECLARE_SPELL_FUN(	spell_detonate		);
DECLARE_SPELL_FUN(	spell_disintegrate	);
DECLARE_SPELL_FUN(	spell_displacement	);
DECLARE_SPELL_FUN(	spell_domination	);
DECLARE_SPELL_FUN(	spell_ectoplasmic_form	);
DECLARE_SPELL_FUN(	spell_ego_whip		);
DECLARE_SPELL_FUN(	spell_energy_containment);
DECLARE_SPELL_FUN(	spell_enhance_armor	);
DECLARE_SPELL_FUN(	spell_enhanced_strength	);
DECLARE_SPELL_FUN(	spell_flesh_armor	);
DECLARE_SPELL_FUN(	spell_inertial_barrier	);
DECLARE_SPELL_FUN(	spell_inflict_pain	);
DECLARE_SPELL_FUN(	spell_intellect_fortress);
DECLARE_SPELL_FUN(	spell_lend_health	);
DECLARE_SPELL_FUN(	spell_mental_barrier	);
DECLARE_SPELL_FUN(	spell_mind_thrust	);
DECLARE_SPELL_FUN(	spell_project_force	);
DECLARE_SPELL_FUN(	spell_psionic_blast	);
DECLARE_SPELL_FUN(	spell_psychic_crush	);
DECLARE_SPELL_FUN(	spell_psychic_drain	);
DECLARE_SPELL_FUN(	spell_psychic_healing	);
DECLARE_SPELL_FUN(	spell_share_strength	);
DECLARE_SPELL_FUN(	spell_thought_shield	);
DECLARE_SPELL_FUN(	spell_ultrablast	);

/*
 * Spell functions.
 */
DECLARE_SPELL_FUN(	spell_null		);
DECLARE_SPELL_FUN(	spell_acid_blast	);
DECLARE_SPELL_FUN(	spell_acid_breath	);
DECLARE_SPELL_FUN(	spell_alchemy		);	/* Lam */
DECLARE_SPELL_FUN(	spell_armor		);
DECLARE_SPELL_FUN(	spell_black_aura	);	/* Lam */
DECLARE_SPELL_FUN(	spell_bless		);
DECLARE_SPELL_FUN(	spell_blindness		);
DECLARE_SPELL_FUN(	spell_blokada_mentalna	);
DECLARE_SPELL_FUN(	spell_brama		);	/* Lam */
DECLARE_SPELL_FUN(	spell_breathe_water	);	/* by Thelonius */
DECLARE_SPELL_FUN(	spell_burning_hands	);
DECLARE_SPELL_FUN(	spell_call_lightning	);
DECLARE_SPELL_FUN(	spell_cause_critical	);
DECLARE_SPELL_FUN(	spell_cause_light	);
DECLARE_SPELL_FUN(	spell_cause_serious	);
DECLARE_SPELL_FUN(	spell_change_sex	);
DECLARE_SPELL_FUN(	spell_charm_person	);
DECLARE_SPELL_FUN(	spell_chill_touch	);
DECLARE_SPELL_FUN(	spell_colour_spray	);
DECLARE_SPELL_FUN(	spell_cone_of_silence	);	/* by Thelonius */
DECLARE_SPELL_FUN(	spell_continual_light	);
DECLARE_SPELL_FUN(	spell_control_weather	);
DECLARE_SPELL_FUN(	spell_create_food	);
DECLARE_SPELL_FUN(	spell_create_spring	);
DECLARE_SPELL_FUN(	spell_create_water	);
DECLARE_SPELL_FUN(	spell_cure_blindness	);
DECLARE_SPELL_FUN(	spell_cure_critical	);
DECLARE_SPELL_FUN(	spell_cure_light	);
DECLARE_SPELL_FUN(	spell_cure_poison	);
DECLARE_SPELL_FUN(	spell_cure_serious	);
DECLARE_SPELL_FUN(	spell_curse		);
DECLARE_SPELL_FUN(	spell_destroy_cursed	);
DECLARE_SPELL_FUN(	spell_detect_evil	);
DECLARE_SPELL_FUN(	spell_detect_hidden	);
DECLARE_SPELL_FUN(	spell_detect_invis	);
DECLARE_SPELL_FUN(	spell_detect_magic	);
DECLARE_SPELL_FUN(	spell_detect_poison	);
DECLARE_SPELL_FUN(	spell_dispel_evil	);
DECLARE_SPELL_FUN(	spell_dispel_magic	);	/* by Thelonius */
DECLARE_SPELL_FUN(	spell_dream		);	/* Lam */
DECLARE_SPELL_FUN(	spell_drogowskaz	);	/* Lam */
DECLARE_SPELL_FUN(	spell_earthquake	);
DECLARE_SPELL_FUN(	spell_enchant_weapon	);
DECLARE_SPELL_FUN(	spell_energy_drain	);
DECLARE_SPELL_FUN(	spell_exorcise		);
DECLARE_SPELL_FUN(	spell_faerie_fire	);
DECLARE_SPELL_FUN(	spell_faerie_fog	);
DECLARE_SPELL_FUN(	spell_finger_of_death	);	/* Lam */
DECLARE_SPELL_FUN(	spell_fireball		);
DECLARE_SPELL_FUN(	spell_fire_breath	);
DECLARE_SPELL_FUN(	spell_flamestrike	);
DECLARE_SPELL_FUN(	spell_flaming		);
DECLARE_SPELL_FUN(	spell_fly		);
DECLARE_SPELL_FUN(	spell_frost_breath	);
DECLARE_SPELL_FUN(	spell_gas_breath	);
DECLARE_SPELL_FUN(	spell_gate		);
DECLARE_SPELL_FUN(	spell_giant_strength	);
DECLARE_SPELL_FUN(	spell_harm		);
DECLARE_SPELL_FUN(	spell_heal		);
DECLARE_SPELL_FUN(	spell_identify		);
DECLARE_SPELL_FUN(	spell_iluzja		);
DECLARE_SPELL_FUN(	spell_infravision	);
DECLARE_SPELL_FUN(	spell_invis		);
DECLARE_SPELL_FUN(	spell_know_alignment	);
DECLARE_SPELL_FUN(	spell_kocie_ruchy	);
DECLARE_SPELL_FUN(	spell_kontrola_nad_woda	);	/* Lam */
DECLARE_SPELL_FUN(	spell_krwawe_lzy	);	/* Lam */
DECLARE_SPELL_FUN(	spell_laser_eyes	);	/* Lam */
DECLARE_SPELL_FUN(	spell_lightning_bolt	);
DECLARE_SPELL_FUN(	spell_lightning_breath	);
DECLARE_SPELL_FUN(	spell_locate_object	);
DECLARE_SPELL_FUN(	spell_magic_missile	);
DECLARE_SPELL_FUN(	spell_mana_gift		);	/* Lam */
DECLARE_SPELL_FUN(	spell_mass_heal		);
DECLARE_SPELL_FUN(	spell_mass_invis	);
DECLARE_SPELL_FUN(	spell_mass_protection	);	/* Lam */
DECLARE_SPELL_FUN(	spell_mass_refresh	);	/* Lam */
DECLARE_SPELL_FUN(	spell_mass_shield	);	/* Lam */
DECLARE_SPELL_FUN(	spell_moon_arrow	);	/* Lam */
DECLARE_SPELL_FUN(	spell_mute		);	/* by Thelonius */
DECLARE_SPELL_FUN(	spell_odblokowanie_mentalne);
DECLARE_SPELL_FUN(	spell_okno		);	/* Lam */
DECLARE_SPELL_FUN(	spell_pajeczyna		);	/* Lam */
DECLARE_SPELL_FUN(	spell_pass_door		);
DECLARE_SPELL_FUN(	spell_plasma_blast	);	/* Lam */
DECLARE_SPELL_FUN(	spell_poison		);
DECLARE_SPELL_FUN(	spell_polymorph_other	);
DECLARE_SPELL_FUN(	spell_portal		);	/* Lam */
DECLARE_SPELL_FUN(	spell_protection	);
DECLARE_SPELL_FUN(	spell_ray_of_truth	);	/* Lam */
DECLARE_SPELL_FUN(	spell_recharge_item	);	/* by Thelonius */
DECLARE_SPELL_FUN(	spell_refresh		);
DECLARE_SPELL_FUN(	spell_remove_alignment	);	/* by Thelonius */
DECLARE_SPELL_FUN(	spell_remove_curse	);
DECLARE_SPELL_FUN(	spell_remove_invis	);	/* Lam */
DECLARE_SPELL_FUN(	spell_remove_silence	);	/* by Thelonius */
DECLARE_SPELL_FUN(	spell_rytual_zycia	);	/* Lam */
DECLARE_SPELL_FUN(	spell_sanctuary		);
DECLARE_SPELL_FUN(	spell_shield		);
DECLARE_SPELL_FUN(	spell_shocking_grasp	);
DECLARE_SPELL_FUN(	spell_sleep		);
DECLARE_SPELL_FUN(	spell_splot_many	);
DECLARE_SPELL_FUN(	spell_stone_skin	);
DECLARE_SPELL_FUN(	spell_summon		);
DECLARE_SPELL_FUN(	spell_sunbeam		);	/* Lam */
DECLARE_SPELL_FUN(	spell_teleport		);
DECLARE_SPELL_FUN(	spell_teleport_group	);	/* Lam */
DECLARE_SPELL_FUN(	spell_turn_undead	);
DECLARE_SPELL_FUN(	spell_ventriloquate	);
DECLARE_SPELL_FUN(	spell_weaken		);
DECLARE_SPELL_FUN(	spell_word_of_recall	);
DECLARE_SPELL_FUN(	spell_zaburzenie_energii);

DECLARE_WEAR_OFF_FUN(	wear_off_blindness	);
DECLARE_WEAR_OFF_FUN(	wear_off_detect_evil	);
DECLARE_WEAR_OFF_FUN(	wear_off_detect_hidden	);
DECLARE_WEAR_OFF_FUN(	wear_off_detect_invis	);
DECLARE_WEAR_OFF_FUN(	wear_off_infravision	);
DECLARE_WEAR_OFF_FUN(	wear_off_mute		);

DECLARE_DO_FUN( do_cast );

extern char *target_name;

extern void say_spell		args( ( CHAR_DATA *ch, int sn ) );
extern void opoznienie_czaru	args( ( CHAR_DATA *ch, int sn ) );
extern void obj_cast_spell	args( ( int sn, int level, CHAR_DATA *ch,
					CHAR_DATA *victim, OBJ_DATA *obj,
					char *arg, int usage ) );

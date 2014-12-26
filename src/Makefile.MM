act_comm.o: act_comm.c merc.h config.h special.h necro.h act_wiz.h \
 act_info.h act_comm.h act_obj.h act_move.h screen.h db.h comm.h clan.h \
 update.h save.h mp_wyzw.h interp.h nanny.h const.h lanclicz.h handler.h \
 ssm.h globals.h
act_info.o: act_info.c merc.h config.h magic.h act_wiz.h act_info.h \
 act_comm.h act_obj.h act_move.h fight.h db.h comm.h clan.h update.h \
 httpd.h save.h mp_wyzw.h interp.h const.h lanclicz.h handler.h ssm.h \
 globals.h
act_move.o: act_move.c merc.h config.h act_wiz.h act_info.h act_obj.h \
 act_move.h fight.h db.h comm.h hunt.h update.h mp_wyzw.h const.h \
 lanclicz.h handler.h ssm.h globals.h
act_obj.o: act_obj.c merc.h config.h magic.h act_wiz.h act_info.h \
 act_comm.h act_obj.h act_move.h fight.h db.h comm.h update.h save.h \
 mp_wyzw.h const.h lanclicz.h handler.h ssm.h globals.h
act_wiz.o: act_wiz.c merc.h config.h act_wiz.h special.h act_info.h \
 act_comm.h act_obj.h act_move.h fight.h screen.h db.h gry.h comm.h \
 update.h save.h kzapisz.h mp_wyzw.h mp_wczyt.h mp_pol.h interp.h nanny.h \
 const.h lanclicz.h handler.h ssm.h clan.h globals.h
clan.o: clan.c merc.h config.h act_wiz.h act_info.h act_comm.h db.h \
 comm.h clan.h httpd.h save.h const.h lanclicz.h handler.h ssm.h \
 globals.h
comm.o: comm.c merc.h config.h act_wiz.h act_info.h screen.h db.h comm.h \
 update.h httpd.h save.h kzapisz.h interp.h nanny.h const.h lanclicz.h \
 handler.h ssm.h clan.h globals.h
const.o: const.c merc.h config.h palad.h necro.h qmagic.h magic.h db.h \
 const.h globals.h
db.o: db.c merc.h config.h special.h magic.h act_wiz.h act_comm.h \
 act_move.h db.h gry.h comm.h clan.h update.h httpd.h save.h mp_wczyt.h \
 mp_wyr.h mp_pol.h const.h lanclicz.h handler.h ssm.h globals.h
fight.o: fight.c merc.h config.h special.h palad.h necro.h magic.h \
 act_wiz.h act_info.h act_comm.h act_obj.h act_move.h fight.h um_ras.h \
 db.h comm.h clan.h update.h save.h mp_wyzw.h interp.h nanny.h const.h \
 lanclicz.h handler.h ssm.h globals.h
globals.o: globals.c globals.h
gry.o: gry.c merc.h config.h act_obj.h db.h gry.h comm.h const.h \
 lanclicz.h handler.h globals.h
handler.o: handler.c merc.h config.h necro.h act_wiz.h act_info.h \
 act_comm.h act_obj.h fight.h db.h comm.h clan.h update.h save.h mp_pol.h \
 mp_wyr.h const.h lanclicz.h handler.h ssm.h globals.h
httpd.o: httpd.c merc.h config.h act_info.h db.h comm.h clan.h httpd.h \
 interp.h const.h lanclicz.h
hunt.o: hunt.c merc.h config.h act_comm.h act_move.h fight.h db.h comm.h \
 update.h const.h lanclicz.h handler.h hunt.h globals.h
interp.o: interp.c merc.h config.h palad.h necro.h magic.h act_wiz.h \
 act_info.h act_comm.h act_obj.h act_move.h skr.h fight.h screen.h \
 um_ras.h db.h gry.h comm.h clan.h socjalne.h hunt.h mp_wyzw.h interp.h \
 lanclicz.h handler.h ssm.h globals.h
kzapisz.o: kzapisz.c merc.h config.h special.h db.h gry.h comm.h \
 kzapisz.h mp_wczyt.h mp_pol.h const.h lanclicz.h handler.h
lac.o: lac.c merc.h config.h comm.h
lanclicz.o: lanclicz.c merc.h config.h act_move.h db.h comm.h lanclicz.h \
 handler.h ssm.h
magic.o: magic.c merc.h config.h palad.h necro.h magic.h act_wiz.h \
 act_info.h act_comm.h act_obj.h act_move.h fight.h db.h comm.h update.h \
 mp_wyzw.h const.h lanclicz.h handler.h ssm.h globals.h
mp_pol.o: mp_pol.c merc.h config.h magic.h act_wiz.h act_info.h act_obj.h \
 act_move.h fight.h db.h comm.h hunt.h mp_wyzw.h mp_pol.h mp_wyr.h \
 interp.h const.h lanclicz.h handler.h ssm.h globals.h
mp_wczyt.o: mp_wczyt.c merc.h config.h mp_wczyt.h db.h mp_wyzw.h mp_pol.h \
 lanclicz.h ssm.h
mp_wyr.o: mp_wyr.c merc.h config.h special.h fight.h db.h comm.h \
 mp_wyzw.h mp_wyr.h nanny.h const.h lanclicz.h handler.h ssm.h clan.h \
 globals.h
mp_wyzw.o: mp_wyzw.c merc.h config.h act_wiz.h db.h comm.h mp_wyzw.h \
 mp_pol.h mp_wczyt.h mp_wyr.h lanclicz.h handler.h ssm.h globals.h
nanny.o: nanny.c merc.h config.h necro.h act_wiz.h act_info.h act_comm.h \
 screen.h db.h clan.h comm.h nanny.h save.h const.h lanclicz.h handler.h \
 ssm.h globals.h
necro.o: necro.c merc.h config.h necro.h magic.h act_info.h act_comm.h \
 act_move.h fight.h db.h comm.h update.h const.h lanclicz.h handler.h \
 ssm.h globals.h
palad.o: palad.c merc.h config.h palad.h magic.h act_comm.h act_move.h \
 fight.h db.h comm.h update.h const.h lanclicz.h handler.h ssm.h \
 globals.h
qmagic.o: qmagic.c merc.h config.h necro.h qmagic.h magic.h act_info.h \
 act_comm.h act_obj.h act_move.h fight.h db.h comm.h mp_wyzw.h const.h \
 lanclicz.h handler.h ssm.h globals.h
save.o: save.c merc.h config.h act_wiz.h act_info.h db.h comm.h clan.h \
 save.h kzapisz.h const.h lanclicz.h handler.h ssm.h globals.h
screen.o: screen.c merc.h config.h screen.h db.h comm.h lanclicz.h
skr.o: skr.c merc.h config.h act_wiz.h act_info.h act_comm.h act_obj.h \
 act_move.h fight.h db.h comm.h update.h const.h lanclicz.h handler.h \
 ssm.h skr.h globals.h
socjalne.o: socjalne.c merc.h config.h fight.h db.h comm.h socjalne.h \
 mp_wyzw.h const.h lanclicz.h handler.h globals.h
special.o: special.c merc.h config.h special.h magic.h act_wiz.h \
 act_comm.h act_move.h fight.h db.h comm.h hunt.h const.h lanclicz.h \
 handler.h globals.h
ssm.o: ssm.c merc.h config.h act_wiz.h db.h comm.h ssm.h
um_ras.o: um_ras.c merc.h config.h act_info.h act_move.h fight.h db.h \
 comm.h update.h const.h lanclicz.h handler.h ssm.h um_ras.h globals.h
update.o: update.c merc.h config.h palad.h act_wiz.h act_info.h \
 act_comm.h act_obj.h act_move.h fight.h db.h comm.h clan.h hunt.h \
 update.h save.h mp_wyzw.h mp_pol.h const.h lanclicz.h handler.h ssm.h \
 globals.h
gla/combo.o: gla/combo.c gla/glaca.h merc.h config.h lanclicz.h ssm.h
gla/glaca.o: gla/glaca.c gla/glaca.h merc.h config.h comm.h db.h const.h \
 mp_wczyt.h kzapisz.h ssm.h mp_pol.h
gla/kraina.o: gla/kraina.c gla/glaca.h merc.h config.h db.h kzapisz.h \
 handler.h
gla/lpl.o: gla/lpl.c gla/glaca.h merc.h config.h const.h
gla/mapa.o: gla/mapa.c gla/glaca.h merc.h config.h const.h
gla/mob.o: gla/mob.c gla/glaca.h merc.h config.h handler.h special.h gry.h \
 const.h db.h lanclicz.h
gla/pomieszczenie.o: gla/pomieszczenie.c gla/glaca.h merc.h config.h \
 handler.h const.h db.h ssm.h
gla/progi.o: gla/progi.c gla/glaca.h merc.h config.h db.h ssm.h mp_pol.h \
 mp_wczyt.h
gla/przedmiot.o: gla/przedmiot.c gla/glaca.h merc.h config.h const.h db.h \
 handler.h ssm.h
gla/reset.o: gla/reset.c gla/glaca.h merc.h config.h db.h kzapisz.h \
 lanclicz.h const.h
gla/vnum.o: gla/vnum.c gla/glaca.h merc.h config.h db.h
gla/wyjscie.o: gla/wyjscie.c gla/glaca.h merc.h config.h handler.h \
 const.h db.h ssm.h lanclicz.h

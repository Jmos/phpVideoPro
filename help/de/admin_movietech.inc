<? /* administration of categories */ ?>
<? /* $Id$ */ ?>

[title]
*intro#

[text]
Unter diesem Men�punkt k�nnen die f�r Filme verf�gbaren technischen Daten, wie
"*screen#", "*picture#", "*mediatype#" und "*tone#" bearbeitet werden. Es lassen
sich eigene Typen hinzuf�gen, wie auch vorhandene bearbeiten oder l�schen.

[title]
Vorhandene Eintr�ge bearbeiten

[text]
Um einen vorhandenen Eintrag anzupassen, ist auf das Edit-Icon in der selben
Zeile zu klicken. Dies f�hrt sodann zu einer Maske, in der die zugeh�rigen Daten
bearbeitet werden k�nnen. So kann z.B. der ausf�hrliche Name ("*name#") f�r
einen Typen ge�ndert werden. Vorsicht geboten ist jedoch bzgl. des Kurznamens
("*sname#"): in �lteren Versionen von phpVideoPro wurde dieser genutzt, um
verschiedene Pr�fungen durchzuf�hren - und ich bin nicht sicher, ob ich alle
diesbez�glichen Referenzen im Code bereits angepasst habe...

[title]
Einen neuen Eintrag hinzuf�gen

[text]
Hierf�r ist einfach auf "*add_entry#" in der letzten Zeile der Tabelle zu
klicken, zu der der gew�nschte Eintrag hinzugef�gt werden soll. Es erscheint
dann die gleiche Maske wie beim Bearbeiten oben - der Unterschied ist jedoch,
dass ein neuer Datensatz hinzugef�gt (also ein zus�tzlicher Typ verf�gbar) wird,
f�r den die Warnungen hinsichtlich des "*sname#" (s.o.) nat�rlich nicht gelten.

[title]
L�schen eines Eintrags

[text]
F�r diesen Zweck ist das M�lltonnen-Icon gedacht. Nach einem Klick auf selbiges
erscheint zun�chst eine Aufforderung zur Best�tigung - falls man versehentlich
daneben geklickt hat (und z.B. eigentlich bearbeiten wollte). Hat man die
L�schung best�tigt, wird zun�chst noch eine Integrit�tspr�fung durchgef�hrt:
Es sollte somit nicht m�glich sein, einen Typ zu l�schen, der noch von mindestens
einem Film referenziert wird.

[eof]
<? /* administration of categories */
 ?>
<? /* $Id$ */ ?>

[title]
*intro#

[text]
Die verschiedenen Dik-Typen unterst�tzen unterschiedliche Features (oder auch
Limitierungen), und diese lassen sich auf dieser Seite zuordnen. Die Handhabung
dieses Formulars ist �quivalent zu dem f�r die
<A HREF="{PHP_SELF}?topic=admin_cats">Kategorien</A>): vorhandene Eintr�ge
k�nnen bearbeitet, neue hinzugef�gt (letzteres �ber den freien Eintrag am
Ende der Tabelle), nicht (mehr) ben�tigte gel�scht werden (indem der Inhalt
des Feldes "*name#" f�r den betreffenden Eintrag geleert wird).

[title]
Felder

[text]
<b>*mediatype#:</b>
[text]
Jedem Medientyp k�nnen mehrere Disk-Typen zugeordnet werden. Eine VideoCD kann
beispielsweise eine "VCD" oder auch eine "SVCD" sein, und (wieder-) beschreibbare
Medien k�nnen unterschiedliche Kapazit�ten aufweisen. Mit dieser Auswahl-Box
wird der Medientyp festgelegt, dem der betreffende Disk-Typ zugeordnet ist.
[text]
<b>*name#:</b>
[text]
Namen sind Schall und Rauch - ein Disk-Typ kann also frei nach Gusto benannt
werden. Eine Eingabe in diesem Feld ist allerdings notwendig, um den Eintrag
speichern zu k�nnen.
[text]
<b>*disk_size#:</b>
[text]
Der hiermit definierte Wert ist optional; gedacht ist, wie anhand der bereits
definierten Disk-Typen ersichtlich, an eine Gr��e in MB oder GB.
[text]
<b>*longplay# / *region_code#:</b>
[text]
Mithilfe dieser Check-Boxen wird angegeben, ob das betreffende "Feature" f�r
diesen Disk-Typ verf�gbar ist.

[title]
L�schen eines Disk-Typs

[text]
Einen Disk-Typ zu l�schen ist einfach - jedoch l��t sich diese L�schung nur
schwer r�ckg�ngig machen. Daher sei hier kurz erw�hnt, was beim L�schen passiert:
[text]
Wird ein Disk-Typ gel�scht, der noch f�r das eine oder andere Medium gesetzt
ist, wird bei den betreffenden Medien diese Zuordnung aufgehoben (es steht dann
also anschlie�end dort nur noch "unbekannt"), anschlie�end wird die Definition
des betreffenden Disk-Typs gel�scht. Dies alles geschieht ohne eine Warnung.
Wie �blich ist es also auch diesbez�glich zu empfehlen, immer ein m�glichst
aktuelles Backup bereit zu haben :-)

[title]
Updates

[text]
Wie auch bei den Kategorien bereits erw�hnt, wenn auch an dieser Stelle etwas
unwahrscheinlicher, k�nnen ver�nderte/hinzugef�gte Disk-Typ Definitionen beim
Update auf eine neuere Version von phpVideoPro �berschrieben werden. Um dies
zu vermeiden (und �berhaupt), sollten die Disk-Typen, an die ich nicht gedacht,
die aber ben�tigt werden, mir zur Sicherheit mitgeteilt werden - damit ich sie
f�r folgende Versionen ber�cksichtigen kann.

[eof]

<? /* administration of categories */
 ?>
<? /* $Id$ */ ?>

[title]
*intro#

[text]
Hier lassen sich die Benutzerkonten verwalten. Diese werden ben�tigt, um die
Daten vor unbefugtem Zugriff zu sch�tzen: vor Manipulation, oder sogar vor
Einsicht.

[title]
Wie phpVideoPro Accounts verwendet

[text]
Defaultm��ig verwendet phpVideoPro den <i>guest</i> Account. Damit dieser
Standard funktionieren kann, darf dieser Account weder gel�scht, noch mit einem
Passwort versehen werden. Sollen &quot;G�ste&quot; komplett vom System
ausgeschlossen werden, sind von daher lediglich diesem Account alle Rechte zu
entziehen. Eine empfohlene gute Einstellung f�r dieses Gast-Konto ist, es
ausschlie�lich mit dem "Browse" Privileg zu versehen. Aber dies kann je nach
Einsatz von phpVideoPro variieren.

[text]
So lange sich der Besucher nicht angemeldet (eingeloggt) hat, verwendet
phpVideoPro das o.g. Gast-Konto. Die ebenfalls o.g. Einstellungen voraus
gesetzt, kann ein Besucher also keinerlei Daten �ndern. Sobald dies nun
versucht wird (z.B. durch Bet�tigen des *edit# Buttons in der Datensatz-
Anzeige), wird nun nicht die gew�nschte Seite (in diesem Fall zum Editieren
des Datensatzes) geladen, sondern der Besucher wird auf die &quot;Login&quot;
Seite weiter geleitet, damit er sich anmelden kann. Desweiteren sind einige
Men�s bereits ausgeblendet, sofern der (nicht) angemeldete Benutzer die
notwendigen Berechtigungen nicht besitzt (so z.B. das Administrations-Men�).

[title]
Einstellungen

[text]
Einige Einstellungen lassen sich direkt auf dieser Seite ver�ndern, indem die
entsprechenden Checkboxen (nicht) gesetzt werden und anschlie�end der
&quot;*update#&quot; Button bet�tigt wird:
[text]
<table align='center' border='1'>
 <tr><td><b>*read_access_short#</b></td>
     <td>Soll der Benutzer Daten betrachten k�nnen? Dies schlie�t die Anzeige
         von Listen sowie einzelnen Datens�tzen ein, dar�ber hinaus jedoch auch
	 die M�glichkeit, Labels zu generieren.</td></tr>
 <tr><td><b>*add_access_short#</b></td>
     <td>Soll der Benutzer <b><i>neue</i></b> Eintr�ge hinzuf�gen k�nnen? Dieses
         Privileg schlie�t das �ndern bereits existierender Eintr�ge <b><i>nicht</i></b>
	 mit ein.</td></tr>
 <tr><td><b>*upd_access_short#</b></td>
     <td>Soll der Benutzer vorhandene Eintr�ge ver�ndern k�nnen? Erlaubt nicht
         auch das Hinzuf�gen neuer Eintr�ge (siehe voriger Punkt).</td></tr>
 <tr><td><b>*del_access_short#</b></td>
     <td>Soll der Benutzer Eintr�ge l�schen k�nnen?</td></tr>
 <tr><td><b>*admin_access_short#</b></td>
     <td>Soll der Benutzer Zugriff auf die administrativen Seiten haben? Mit
         dieser Berechtigung kann sich ein Benutzer s�mtliche Rechte selbst
	 zuweisen, Konten erstellen/l�schen/modifizieren sowie beliebige
	 Einstellungen der Konfiguration �ndern. Daher ist mit dieser
	 Berechtigung vorsichtig um zu gehen!</td></tr>
</table>

[text]
Um neue Benutzerkonten hinzuzuf�gen, oder weitere Details an bereits vorhandenen
Konten zu �ndern, sind entsprechende Links vorhanden.

[eof]

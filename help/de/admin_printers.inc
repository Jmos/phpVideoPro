<? /* administration of categories */
 ?>
<? /* $Id$ */ ?>

[title]
*intro#

[text]
Mit dieser Seite verh�lt es sich wie bei "*admin_cats#" - nat�rlich mit der
nicht unwesentlichen Abweichungen, dass hier <b><i>Drucker</i></b> bearbeitet
werden und keine Kategorien :-) Um einen Drucker zu entfernen, ist einfach das
Namensfeld zu leeren (und das Formular abzuschicken). Um die Einstellungen f�r
einen Drucker anzupassen, einfach die entsprechenden Werte ver�ndern (und
ebenfalls den sch�nen Button am Ende der Seite dr�cken). Ein neuer Drucker
l��t sich in der letzten (leeren) Zeile hinzuf�gen.

[title]
Was ist ein Offset?

[text]
Der druckbare Bereich auf einem Blatt Papier stimmt nicht bei allen Druckern
�berein: es mag Drucker geben, die an beliebiger Stelle auf dem Papier drucken
k�nnen. Die meisten Drucker ben�tigen zumindest einen schmalen Rand zur
Papierf�hrung - aber auch hier sind sie sich nicht alle einig, wie schmal
"schmal" nun ist...

[text]
Wenn nun keine der vorhandenen Definitionen mit dem zu verwendenden Drucker
akkurat arbeitet, kann hier anhand der herausgefundenen Ma�e (Differenz der
Randeinstellungen bei einem Testdruck) ein neuer Drucker hinzugef�gt, oder aber
auch ein bestehender angepasst werden.

[title]
Einheiten

[text]
In der Spalte "*units#" finden sich verschiedene Ma�einheiten, die vielleicht
nicht alle gel�ufig sind. Daher hier eine kurze Auflistung:
<TABLE ALIGN="center" BORDER="1" WIDTH="90%">
  <TR><TH CLASS="help">Einheit</TH><TH CLASS="help">Vergleich</TH><TH CLASS="help">Beschreibung</TH></TR>
  <TR><TD>pt</TD><TD>&nbsp;</TD><TD>Der "Punkt" ist die kleinste Einheit bei PostScript</TD></TR>
  <TR><TD>inch</TD><TD>72 pt</TD><TD>Alte britische Ma�einheit, der wohl auch unser "Zollstock" seinen Namen verdankt</TD></TR>
  <TR><TD>mm</TD><TD>28.3465 pt</TD><TD>Millimeter ist die kleinste metrische Ma�einheit, die in unserem Kontext einen Sinn ergibt</TD></TR>
  <TR><TD>cm</TD><TD>2.8346 pt</TD><TD>Das gleiche wie 10 mm. Die Frage, ob PostScript nur 4 Stellen nach dem Komma unterst�tzt, geht an Michael (bis dahin am besten "mm" f�r genauere Angaben verwenden ;)</TD></TR>
</TABLE>

[title]
Eine letzte Anmerkung...

[text]
Hinzugef�gte/ge�nderte Angaben k�nnen bei einem Update (oder einer Neuinstallation)
verloren gehen, daher sind...
<ol>
 <li>...Backups empfohlen (phpVideoPro bietet entsprechende Funktionen an)</li>
 <li>...�nderungen/Angaben f�r neue Drucker am besten an mich zu schicken, so
     dass Sie in neueren Versionen von phpVideoPro gleich mit enthalten sind.
     Dies stellt sicher, dass sie dann auch bei Updates bzw. Neuinstallationen
     erhalten bleiben ;)</li>
</ol>

[eof]

# /* set_filter */
# /* $Id$ */

[title]
Einleitung

[text]
Beide Men�punkte - "*set_filter#" wie auch "*unset_filter#" - f�hren zum selben
Formular, mit nur einem kleinen (wenn auch signifikanten) Unterschied:
"*unset_filter#" l�scht zuvor alle gesetzten Filter, so da� problemlos
mit der Erstellung eines neuen Regelsets begonnen werden kann - ohne zuerst auf
bestehende Regeln pr�fen zu m�ssen.

[text]
Wurde dieses Formular �ber das Men� "*admin#" -&gt; "*admin_filter#" aufgerufen,
so werden die Default Filtereinstellungen, welche in der Datenbank gespeichert
sind, bearbeitet. Ein Aufruf �ber das "*edit#" Men� hingegen speichert
�nderungen in Cookies (und liest sie, ihre Existenz vorausgesetzt, auch aus
selbigen) - sofern Cookies aktiviert sind. Dies erm�glicht mehreren Benutzern,
zur gleichen Zeit mit ein und derselben Installation zu arbeiten, und dennoch
ihre eigenen Filtereinstellungen vornehmen zu k�nnen - ohne die eines anderen
zu �berschreiben.

[title]
Filterregeln

[text]
<H4>in einer gemeinsamen Zelle gruppierte Filter</H4>
  <OL>
   <li><b>Filter mit min/max Werten</b><br>
       Diese werden mit UND verkn�pft; gibt man also "min 60" und "max 90"
       f�r die L�nge an, bedeutet dies: alle Filme mit 60-90 Minuten L�nge.
       Wird nur einer der beiden Werte angegeben, findet nat�rlich auch nur
       dieser Ber�cksichtigung.
   <li><b>Titel</b><br>
       Ein beliebiger Teil des gew�nschten Titels kann hier eingegeben
       werden; der Begriff "Mission" w�rde hier also sowohl auf den Film
       "James Bond: In t�dlicher Mission" wie auch auf "Mission Impossible"
       zutreffen.
   <li><b>andere Filter</b><br>
       Alle anderen Filter werden mittels ODER verbunden; wird also z.B.
       als MedienTyp sowohl DVD als auch OVT aktiviert, hei�t dies: sowohl
       DVDs als auch Originalb�nder (wenn mir jemand ein Medium bringt,
       welches zugleich DVD und VHS-Tape ist, mu� ich diese Regel nochmals
       �berdenken :-)
  </OL>

[text]
<H4>Verkn�pfung der einzelnen Regeln</H4>

[text]
Die einzelnen Filterregeln werden nun wieder mit UND verbunden: "DVD" als
Medientyp und "Science Fiction" als Kategorie resultiert daher in allen DVDs,
welche Science Fiction Filme enthalten.

[eof]

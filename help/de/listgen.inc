<? /* medialist */
 ?>
<? /* $Id$ */ ?>

[title]
*intro#

[text]
Auch wenn dieser Punkt im Men� "*print#" zu finden ist, werden hier lediglich
Daten f�r den Druck vorbereitet. Ich hatte zun�chst verschiedene Varianten von
Ausgabeformaten in Erw�gung gezogen. An erster Stelle stand PostScript: damit
w�ren zwar alle Unix/Linux Benutzer wunderbar klar gekommen (verwendet doch
hier nahezu jeder "Druckertreiber" PostScript als Eingabeformat) - jedoch unsere
armen M$-Abh�ngigen (Windoze Benutzer) w�ren dar�ber sicher nicht besonders
gl�cklich gewesen (auch wenn sie zur Verarbeitung GhostScript installieren
k�nnten). Als Alternative bot sich an, die Listen als riesige, mehrseitige
Etiketten zu betrachten - da dies jedoch ebenso riesige Grafikdateien zum
Ergebnis h�tte, k�men zum einen die Drucker anst�ndig in's Schwitzen, und zum
anderen w�rde der Druck damit auch recht lange dauern...

[title]
Wie funktioniert es nun?

[text]
Also entschloss ich mich, die Listenaufbereitung auf unterschiedliche Weise
vonstatten gehen zu lassen: Die Listen entweder als reiner (ASCII) Text
erstellt, der sich sodann direkt (nach dem Speichern im Dateisystem und/oder
�ffnen mit einem beliebigen Texteditor wie [k]write) drucken l��t.<br>Zur
Alternative steht ein Export im CSV Format (die einzelnen Spalten sind mittels
Tabulatoren (Tab-Stops) getrennt, die erste Zeile enth�lt die Tabellen�berschriften),
wobei sich das Resultat dann in eine beliebige Textverarbeitung (Word,
OpenOffice/StarOffice etc.) oder Tabellenkalkulation (Excel, OpenOffice/StarOffice)
importieren und mittels dieser nachbereiten l��t.<br>
Ich empfehle f�r letzteres die Erstellung einer Dokumentvorlage, in der alle
gew�nschten Tabellen- und Textformatierungen (Schriftart und -gr��e,
Hintergrundfarben z.B. f�r den Tabellenkopf, Kopfzeilen der Seiten mit �berschrift
und Seitenzahlen etc.) bereits festgelegt sind. Besonders, wenn h�ufiger Listen
gedruckt werden sollen, hilft dies, den Zeitaufwand ein wenig zu begrenzen.

[title]
Formularfelder

[text]
<b>*list#:</b> Welche Liste erstellt werden soll (erkl�rt sich selbst)
<b>*format#:</b> <b><i>ASCII</i></b> bezeichnet eine formatierte Liste (etwas
spartanisch, eher f�r "Faule" gedacht, die sich nicht den Aufwand der
Nachbearbeitung machen wollen), die zum direkten Ausdruck gedacht ist (siehe
oben). <b><i>CSV</i></b> ebenfalls im ASCII Format, jedoch sind hier alle Felder
lediglich mit Tabulatoren getrennt, um anschlie�end in eine Tabelle umgewandelt
und dort weiter bearbeitet werden zu k�nnen (abermals siehe oben).<br>
<b>*line_count#</b>: Wie viele Zeilen reinen (ASCII) Textes auf eine Seite
Papier passen (dies kann je nach Drucker unterschiedlich sein). Der Vorgabewert
wird aus den Voreinstellungen (siehe
"<A HREF="{PHP_SELF}?topic=configuration">*configuration#</A>") �bernommen, kann
jedoch hier �berschrieben werden. F�r CSV Listen wird der Inhalt dieses Feldes
freilich ignoriert.

[eof]

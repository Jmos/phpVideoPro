<? /* administration of categories */
 ?>
<? /* $Id$ */ ?>

[title]
Administration der Kategorien

[text]
Hier lassen sich die Kategorien editieren. Wenn also eine �bersetzung nicht
gef�llt, kann sie in diesem Formular angepasst werden: einfach den entsprechenden
Wert in der Spalte "*category#" �ndern.

[text]
Ein Risiko bleibt dabei: mit dem Update auf die n�chste Version, oder auch nur
mit der Installation einer aktuelleren Sprachdatei sind die selbst erstellten
�bersetzungen wieder �berschrieben. Um dies zu vermeiden, kann in der Spalte
"*cat_internal_name#" der interne Name der Kategorie ebenfalls angepasst werden.
Da dieser jedoch als "Schl�ssel" f�r die �bersetzung dient, sollte sich hier
an die Regel gehalten werden, dass interne Kategorienamen immer mit "cat_"
beginnen m�ssen. Andernfalls besteht die Gefahr, dass es zu Konflikten mit
anderen �bersetzungen kommt. Das Resultat w�re ein fehlgeschlagenes Update:
entweder hier an dieser Stelle (falls bereits eine �bersetzung gleichen
"Schl�ssels" existiert), oder bei einem sp�teren Update (wenn eine solche
�bersetzung von <B>mir</B> hinzugef�gt werden sollte). Dieses Problem l��t sich
jedoch weitgehend vermeiden, wenn sich an meine Regeln gehalten wird :-)

[eof]

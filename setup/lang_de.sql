# ========================================================
# English Translation phrases for phpVideoPro
# ========================================================

INSERT INTO lang (message_id,lang,content) VALUES ('not_yet_implemented','de','Sorry - leider noch nicht verf�gbar.');
INSERT INTO lang VALUES('medium','de','Medium');
INSERT INTO lang VALUES('nr','de','Nr');
INSERT INTO lang VALUES('title','de','Titel');
INSERT INTO lang VALUES('length','de','L�nge');
INSERT INTO lang VALUES('year','de','Jahr');
INSERT INTO lang VALUES('date_rec','de','Aufnahmedatum');
INSERT INTO lang VALUES('category','de','Kategorie');
INSERT INTO lang VALUES('medialist','de','Medienliste');
INSERT INTO lang VALUES('enter_min_free','de','Mindestgr��e des freien Platzes in Minuten:');
INSERT INTO lang VALUES('display','de','Anzeigen');
INSERT INTO lang VALUES('free_space_on_media','de','Auf folgenden Medien sind noch mindestens %1 Minuten frei:');
INSERT INTO lang VALUES('free','de','Frei');
INSERT INTO lang VALUES('content','de','Inhalt');
INSERT INTO lang VALUES('filter_setup','de','Filter Setup');
INSERT INTO lang VALUES('mediatype','de','MedienTyp');
INSERT INTO lang VALUES('screen','de','Bildformat');
INSERT INTO lang VALUES('picture','de','Farbformat');
INSERT INTO lang VALUES('tone','de','Tonformat');
INSERT INTO lang VALUES('longplay','de','LongPlay');
INSERT INTO lang VALUES('fsk','de','FSK');
INSERT INTO lang VALUES('actor','de','Schauspieler');
INSERT INTO lang VALUES('director','de','Regie');
INSERT INTO lang VALUES('composer','de','Musik');
INSERT INTO lang VALUES('min','de','min');
INSERT INTO lang VALUES('max','de','max');
INSERT INTO lang VALUES('s/w','de','s/w');
INSERT INTO lang VALUES('farbe','de','Farbe');
INSERT INTO lang VALUES('3d','de','3D');
INSERT INTO lang VALUES('edit_entry','de','Bearbeite Datensatz %1');
INSERT INTO lang VALUES('view_entry','de','Anzeige des Datensatzes %1');
INSERT INTO lang VALUES('add_entry','de','Neuer Datensatz');
INSERT INTO lang VALUES('unknown','de','unbekannt');
INSERT INTO lang VALUES('country','de','Land');
INSERT INTO lang VALUES('medianr','de','MediaNr');
INSERT INTO lang VALUES('highest_db_entries','de','letzte DB-Eintr�ge');
INSERT INTO lang VALUES('no','de','Nein');
INSERT INTO lang VALUES('yes','de','Ja');
INSERT INTO lang VALUES('medialength','de','Bandl�nge');
INSERT INTO lang VALUES('minute_abbrev','de','min');
INSERT INTO lang VALUES('source','de','Quelle');
INSERT INTO lang VALUES('name','de','Name');
INSERT INTO lang VALUES('first_name','de','Vorname');
INSERT INTO lang VALUES('in_list','de','in Liste');
INSERT INTO lang VALUES('comments','de','Anmerkungen');
INSERT INTO lang VALUES('cancel','de','Abbrechen');
INSERT INTO lang VALUES('create','de','Erstellen');
INSERT INTO lang VALUES('update','de','Aktualisieren');
INSERT INTO lang VALUES('edit','de','Bearbeiten');
INSERT INTO lang VALUES('delete','de','L�schen');
INSERT INTO lang VALUES('invalid_media_nr','de','Die angegebene MediaNr ist entweder unvollst�ndig oder ung�ltig. Es mu� eine <b>Zahl</b> in <b>beiden</b> MediaNr Feldern eingegeben werden.');
INSERT INTO lang VALUES('warning','de','Warnung');
INSERT INTO lang VALUES('of_aquiration','de','der Aufnahme');
INSERT INTO lang VALUES('wrong_date','de','Das angegebene Datum %1 (%2) ist ung�ltig. Das anzugebende Datum mu� dem Schema "JJJJ-MM-DD" folgen, wobei "JJJJ" (vier Ziffern) f�r das Jahr, "MM" f�r den Monat (zwei Ziffern) und "DD" f�r den Tag (auch zwei Ziffern) steht. Soll an dieser Stelle <b>kein</b> Datum gespeichert werden, ist dieses Feld leer zu lassen (oder mit "0000-00-00" zu belegen).');
INSERT INTO lang VALUES('incomplete_date','de','Ist das exakte Datum nicht bekannt (sondern z.B. nur die Jahreszahl "2000"), sind die unbekannten Werte durch Nullen zu ersetzen - im genannten Beispiel entspr�che das der Eingabe "2000-00-00".');
INSERT INTO lang VALUES('hit_back_to_correct','de','Bitte auf den "Zur�ck" Button des Browsers klicken, um die Eingabe zu korrigieren.');
INSERT INTO lang VALUES('dupe_id_entered','de','Es existiert bereits ein Datensatz mit der angegebenen MediaNr in der Datenbank. Zur Korrektur der Eingabe bitte den "Zur�ck" Button des Browsers bet�tigen. Hinweis: direkt neben dem Eingabefeld f�r die MediaNr befindet sich eine Auswahlbox. Diese gibt die h�chste vergebene ID f�r jedes Medium an. Normalerweise ist es eine gute Idee, f�r ein neues Medium die erste (vierstellige) Zahl, bzw. f�r einen neuen Film auf dem gleichen Medium die zweite (zweistellige) Zahl um 1 zu erh�hen.');
INSERT INTO lang VALUES('create_success','de','Datensatz erfolgreich erstellt');
INSERT INTO lang VALUES('update_failed','de','Datensatz konnte nicht aktualisiert werden');
INSERT INTO lang VALUES('about','de','About');
INSERT INTO lang VALUES('history','de','History');
INSERT INTO lang VALUES('deleting_entry','de','L�sche Datensatz %1');
INSERT INTO lang VALUES('free_space_title','de','Verf�gbarer Platz auf Medien');
INSERT INTO lang VALUES('filter','de','Filter');
INSERT INTO lang VALUES('set_filter','de','Filter setzen');
INSERT INTO lang VALUES('unset_filter','de','Filter l�schen');
INSERT INTO lang VALUES('view','de','Anzeigen');
INSERT INTO lang VALUES('taperest_absolute','de','Bandrest (absolut)');
INSERT INTO lang VALUES('taperest_filtered','de','Bandrest (gefiltert)');
INSERT INTO lang VALUES('help','de','Hilfe');
INSERT INTO lang VALUES('general','de','Allgemein');


# when finished, activate language
UPDATE languages SET available='Yes' WHERE lang_id='de';

# /* view entry */
# /* $Id$ */

[title]
Introduktion

[text]
Detta formul�r visar alla tillg�ngliga detaljer om den valda noteringen.
Normalt sett ska det inte beh�vas n�gon f�rklaring, eftersom du borde k�nna tillt allt om
all data du skrivit sj�lv (Om inte, kanske f�ljande hj�lpsida intresserar dig
ang�ende "<A HREF="{PHP_SELF}?topic=add_entry">*add_entry#</A>"), men...

[title]
IMDB information

[text]
Om du vill ha tag i n�rmare info om en sk�despelare, regiss�r eller komposit�r:
bara klicka p� knappen som det st�r hans/hennes namn p� (eller f�rnamn, spelar ingen roll).
Detta kommer att �ppna ett nytt webbl�sarf�nster vilket l�nkar till Internet Movie DataBase
(IMDB) som du �verl�mnar efternamn, f�rnamn och det personen i fr�ga sysslar med, med info taget fr�n
phpVideoPro. Om denna information �r entydig (allts� att det matchar IMDB's info), 
kommer detta att leda dig till sidan med infon du ville ha. Annars, kommer IMDB-sajten att fr�ga dig efter ytterligare
information: Detta kan vara en lista p� folk som passade in p� f�rfr�gningen, eller
n�nting om att den inte hittade informationen du ville ha.
[text]
Efter IMDB �r en oberoende service/produkt, s� kan inte phpVideoPro p�verka informationen tillg�nglig d�r - 
t.ex. s� �r vi inte ansvariga f�r detta, och vi kommer inte att �ndra informationen d�r :-) 
Men vissa av oss k�nde, att det kunde vara en najs funktion att ge dig denna info med bara ett enda musklick...

[title]
Etikettutskrift

[text]
Valrutan titelerad "*print_label#" l�ter dig skriva ut en etikett f�r valda mediumet.
Det inneh�ller ett antal templates (mallar), och ska skriva ut titel och tid p� <b>alla</b> filmer p� det valda mediumet (om du t.ex.
visar "RVT 1234-2", och kassetten 1234 dessutom inneh�ller del 1 och
3, inneh�ller etiketten alla tre filmerna), men det �r vid det h�r laget (v0.2.4) begr�nsat 
till ett antal av totalt 4 rader, i.e. movies per medium. Detta kan kanske g�ras tillg�ngligt i en senare version.

[text]
F�r att skapa dina egna etiketter, bara l�gg dem i "labels/"-katalogen.
.config-filen beh�vs alltid och beskriver storleken p� etiketterna
plus storleken och position p� dem inneh�llande avsnitten. Om en .png-fil med samma namn
existerar, kommer det att anv�ndas - annars skapas en enkel (vit) mall (och med etikett, f�rst�s). F�r detaljer, ta en titt p� <A HREF="{PHP_SELF}?topic=howto_label">*howto_label#</A>.

[eof]

# /* How to create a help file */
# /* $Id$ */

[title]
Hur generar jag mina egna hj�lpsidor?

[text]
Det �r tillochmed enklare �n skapandet av en ny spr�kfil -
speciellt efter
�ndringarna som gjordes i v0.2 n�r hj�lpsidorna b�rjade drivas av mallar.
Nu beh�ver du inte ens kunna HTML - du beh�ver bara �ndra en enkel
textfil som <b>kan</b> inneh�lla lite makro/HTML-kod, men beh�ver inte det:
[text]
<OL>
 <LI>g� till hj�lp-katalogen, �ppna help_topics.php med din
     favorit-viewer f�r text (�n en g�ng, detta �r ren text). Strukturen
     p� denna fil �r sj�lvf�rklarande: 
     en rad b�rjar med "headline" som markerar en headline, ett �mne
     b�rjar med "li". Den f�rsta saken inom m�svingar �r hj�lp-rubriken.
     Titta efter namnet p� rubriken du vill skapa en hj�lpfil f�r.
 <LI>Om det inte finns en enda hj�lpfil tillg�ngligt f�r ditt spr�k �n,
     f�r du lov att skapa den korrekta katalogen f�r ditt spr�k f�rst.
     Hitta spr�kkoden f�r ditt spr�k (se
     "<A HREF="{PHP_SELF}?topic=howto_lang">*howto_lang#</A>" p� hur man
g�r detta), och skapa katalogen med namnet p� spr�kkoden nedan
     hj�lpkatalogen - t.ex. "help/fi" f�r finska.
 <LI>Nu: antingen skapa en ny fil med namnet <topic>.inc i din spr�k-
     katalog (e.g. "help/fi/about.inc" f�r det finska "About"-�mnet), eller
     kopiera det fr�n det engelska tr�det (help/en) som en mall.
 <LI>�ppna din nya hj�lpfil ("help/fi/about.inc" i ovanst�ende exempel) med
     med din favorit-editor och �vers�tt/skapa hj�lprubriken. Formatet p�
     en s�dan fil f�rklaras nedan.
 <LI>Det �r allt - du �r klar! phpVideoPro kommer automatiskt hitta och anv�nda
     hj�lpfilen till det definierade f�rstahandsspr�ket f�rst. Oroa dig inte om du
     saknar <b>vissa</b> hj�lpfiler f�r ditt spr�k: om phpVideoPro
     inte kan hitta en hj�lpfil i ditt f�rstahandsspr�k, visas den
     engelska som standard.
  </OL>

[title]
Filformat
[text]
Det generella formatet som anv�nds f�r hj�lpfilerna �r v�ldigt enkelt: varje rad startar
med en br�dg�rd ("#") som tolkas som kommentar (t.ex. ett som helt ignoreras). Den f�rsta raden
tolken b�rjar med m�ste vara en rad som inneh�ller enbart [title] 
tagg (inledande/avslutande blanktecken ignoreras). Tolken stannar p� [eof]-
taggen och sen (och bara sen) skickas hj�lpfilen till webbl�saren. Den tredje
taggen som �r ett m�ste �r [text]-taggen. Taggar <b>m�ste</b> placeras p� separata
rader f�r att identifieras (�n en g�ng, inledande/avslutande blanktecken ignoreras)!<br>So
sen d�, vad menas?
[text]
<ul>
 <li><b>[title]</b> markerar en headline. Allt som f�ljer denna tagg (upp till 
     n�sta tagg, som i de flesta fall [text]) ses som en headline f�r
     det f�ljande ([text]) blocket.
 <li><b>[text]</b> startar ett till textblock - h�r �r all information med
     detaljer. F�r att uppn� flera "paragrafer", bara starta flera [text]-
     block en efter en.
 <li><b>[eof]</b> betyder "End Of File" och s�ger till tolken att nu verkligen
     generera utdatan. Den s�ger ocks� till den att det inte �r av n�got mer
     intresse f�r honom :)
</ul>
[text]
Du kan anv�nda HTML-formateringskod som t.ex. f�r att understryka fraser med 
&lt;B&gt;bold&lt;/B&gt; markeringar, generera listor med &lt;UL&gt;, placera ut tabeller,
grafik, etc. Jag f�rklarar inte hur man g�r det - det finns b�ttre manualer
tillg�ngliga inom detta �mne. �n en g�ng, du <b>m�ste</b> inte anv�nda detta, men du
<b>kan</b>.

[title]
Makron

[text]
Det finns n�gra makron tillg�ngliga i hj�lpfilerna. De kan delas in i tv� kategorier:
variabler och �vers�ttare. Om du �r en aning mer van vid PHP (och tillochmed koden f�r phpVideoPro),
s� borde du vilja anv�nda dessa.
[text]
Allting som s�tts d�rimellan {m�svingar} ers�tts med global
variabel med sitt namn (om det �r tillg�ngligt). Denna variabel m�ste t.ex. INTE inneh�lla n�gra
blanksteg, etc. (se PHP-manualen f�r detta).
[text]
Allt som �r i tysk BTX-stil insatt mellan en *asterisk och en #br�dg�rds-
markering (�n en g�ng, inga blanksteg!) indikerar till tolken att det m�ste �vers�ttas
genom att anv�nda the fraserna definierade av spr�kfilerna. Sj�lvklart s� f�ljer den reglerna av phpVideoPros �vers�ttningssystem.

[eof]
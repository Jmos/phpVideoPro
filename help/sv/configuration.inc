# /* configure */
# /* $Id$ */

[title]
Introduktion

[text]
P� denna sk�rm st�ller du in globala defaults till phpVideoPro, som spr�k-
specifika inst�llningar, f�rger att anv�nda etc. 
[title]
*language_settings#

[text]
<b>*scan_new_lang_files#:</b> F�r att hantera spr�ken som �r installerade
s�v�l som ytterligare tillg�ngliga, anv�nder phpVideoPro dess egna
database. S� f�r att l�gga till ett nytt spr�k, m�ste man
uppdatera detta. Detta �r gjort med SQL-filer som jag f�r enkelhetens
skull kommer att kalla "spr�kfiler" fram�ver. En ny spr�kfil m�ste bli
introducerat till systemet, som g�rs med genom att kryssa i denna checkbox
(och
skicka formul�ret, s� klart :). Se "Spr�k att installera" nedan,
s�v�l som 
"<A HREF="{PHP_SELF}?topic=howto_lang">*howto_lang#</A>" f�r detaljer).

[text]
<b>*select_add_lang#:</b> Sj�lvklart, du kan bara installera tillg�ngliga 
spr�k - phpVideoPro tillh�r inte kategorin av AI och kan inte skapa nya
spr�k "on the fly" :) F�r att uppdatera redan installerade spr�k, se
n�sta f�rem�l.

[text]
<b>*refresh_lang#:</b> Om du har en ny spr�kfil f�r ett spr�k du
redan har installerat, som inneh�ller korrigerade och fr�scha tillagda fraser, 
beh�ver du ett s�tt att byta ut dem gamla fraserna p�. Detta �r t.ex. i
det fallet n�r du uppdaterar fr�n en
f�reg�ende version av phpVideoPro. F�r spr�ket du valt h�r, tas alla fraser
bort fr�n databasen och de nya spr�kfilerna importeras ist�llet. Vid
n�got tillf�lle i framtiden kanske jag l�gger till en funktion f�r att
l�gga till endast nya fraser och inte ta bort n�got
fr�n databasen - Men det �r inte gjort �n. 
[text]
<b>*select_primary_lang#:</b> I m�ngden av installerade spr�k, kan
du v�lja din favorit. Om ditt modersm�l finns med, antar jag
att du f�redrar det :) F�r alla fraser som saknas i dina favorit-
spr�kfiler, kommer det att finnas
en "fall-back" till de engelska fraserna. Om den engelska frasen �ven den
saknas 
(vilket inte borde h�nda, s�vida inte importeringen av den
engelska spr�kfilen misslyckades),
s� finns det n�gra "debug-fraser" som visas som du kan gissa dig till 
inneh�llet av.
Om detta skulle h�nda, och du vet att det inte �r ditt egna fel
(till exempel eftersom du tog bort de engelska fraserna fr�n databasen
manuellt ;) - var god upplys 
<A HREF="mailto:izzysoft@qumran.org">mig</A> om detta, d�r du
n�mner den saknade frasen och vart felet uppstod.

[title]
*colors#

[text]
<b>*page_bg# / *table_bg# / *th_bg#:</b> Dessa inst�llningar renderas
inuti det eventuellt standard-valda stylesheet'et och namnen
�r sj�lvf�rklarande.

[text]
<b>*feedback_ok# / *feedback_err#:</b> Dessa inst�llningar �r inte
renderade inuti n�got stylesheet. Dem anv�nds f�r systemanrop p�
anv�ndarens beg�ran, till exempel p�st�enden som "notering skapades
utan problem" n�r man skapar en ny notering i databasen, eller "Error
&lt;n�gon f�rklaring&gt;" n�r n�got gick fel, f�r
att understryka dessa meddelanden i sammanhang med den vanliga formul�r-
data dem visas med.

[text]
<b>*template_set#:</b> med b�rjan fr�n v0.1.5, �r phpVideoPro baserat
p� mallar.
Jag (f�rfattaren) bara stod till f�rfogande med ett initialt set av
mallar; men s� fort det finns
ytterligare sets av mallar tillg�ngliga (som endast kommer att uppst� n�r
<b>DU</b>
skriver dem - D� jag inte �r n�gon bra designer), �r detta platsen att
g�ra ditt val p�.

[title]
*general#

[text]
<b>*display_limit#:</b> Tidigare versioner av phpVideoPro visade listor,
till exempel med
*medialist# meny-f�rem�let, alltid i dess fulla l�ngd, till exempel med
allt som �r inskrivet som finns med i databasen. Har man en stor
samling, �r detta inte bara n�got som leder till l�nga
v�ntetider f�r att ladda in sidan, men ocks� den l�nga listan
skulle ocks� kunna vara f�rvirrande f�r en eller 
annan person :-) Dock med b�rjan fr�n version 0.2.3, tillhandah�ller phpVideoPro
m�jligheten att visa dessa listor i delar vars storlek du kan
specifiera h�r:
Hur m�nga rader lines du �nskar visas i dem listorna.
Navigering tillhandah�lls av fyra knappar som flyttar dig till det
f�rsta/sista resp. f�reg�ende/n�sta
sidan av den kompletta listan.

[text]
Jag m�ste erk�nna att med personlistorna kan denna finess kanske 
fungera p� ett skumt s�tt: inte bara det att radr�kningen skiljer sig fr�n
det inskrivna 
"*display_limit#" - �ven kan det tillochmed skilja sig mellan sidor!
Anledningen �r v�ldigt simpel: phpVideoPro anst�ller "*display_limit#"
p� personalen h�r. S� skillnaden dyker upp n�r du markerat lite 
personalmedlemmar som inte ska visas 
(vid anv�ndning av valet "*in_list#" inom "*edit#" formul�ret.

[text]
<b>*lines_per_page#:</b> Detta �r f�r f�rberedelsen av "endast
text"-listor f�r utskrift (se <A
HREF="{PHP_SELF}?topic=listgen">*listgen#</A>) och specificerar det antal
rader som passar p� ett ark papper. Efter dessa specificerade
antalet rader, blir en "form feed" insatt till att starta en ny sida. Du
kan �verskrida
denna standard p� *listgen# formul�ret.

[text]
<b>*date_format#:</b> Specificerar formatet datumet borde presenteras
som. Detta
�r en nyhet i v0.2.6 av phpVideoPro, s� det kan vara ett par
kolumner/f�lt som ignorerar
detta v�rde (det kommer f�rhoppningsvis att inte vara n�got av detta i 
v0.3.0 and above - om
du hittar n�got som saknas sen, var god rapportera det till mig!). Det
skall anv�ndas
genom hela programmet f�r listningar, formul�r och vad som �n 
inneh�ller
ett datumf�lt.

[eof]

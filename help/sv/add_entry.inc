# /* add_entry */
# /* $Id$ */

[title]
Introduktion

[text]
Genom att anv�nda detta menyf�rem�l, kan du l�gga in en ny notering i din video-databas. De flesta
f�lten i detta formul�r �r sj�lvf�rklarande; men det finns n�gra som beh�ver kommenteras
litegrann (f�rutom det faktum att den ej namngivna input-rutan ovanp� har som syfte att h�lla
kvar filmtiteln ;):

[title]
MediaTyp

[text]
<IMG SRC="{base_url}help/img/mtype_nr.png" ALT="bit av 'l�gg till notering' meny: mediatyp" ALIGN=LEFT
HSPACE=5>
Rutan "MediaTyp" (r�d-markerad i bilden som visas) ger dig en lista p�
tillg�ngliga mediatyper att v�lja fr�n. Denna ruta i sig sj�lvt, beh�ver ingen
f�rklaring, antar jag - men jag vill dra din uppm�rksamhet mot dem andra tv� markeringarna:
det finns ett tv�delat MediaNr att skriva in (bl�-markerat). Den f�rsta biten st�r f�r
den fysiska median, till exempel kassett eller disk. Den andra biten g�ller filmen p� den median. 
L�t oss s�ga, att du har spelat in tv� filmer p� kassett # 20, s� den f�rsta
filmen borde vara 20-1 och den andra 20-2.
[text]
Nu till funktionen: L�t oss f�rest�lla oss, att vi just har spelat in 2 filmer p� en tom kassett,
 och nu vill du skapa databas-noteringarna f�r dessa. �r du s�ker p�
att du kom ih�g det sista (fysiska) MediaNr du tilldelat? Den gr�n-markerade rutan
hj�lper dig i ditt s�kande efter det h�gsta tilldelade numret <b>f�r varje mediatyp</b>!
�ppna det bara, f�r att visa alla dess inneh�ll. F�r skapandeprocessen, �r det inte
ett problem f�r alla, vilket v�rde du valt - den gr�n-markerade rutan �r f�r din information
endast, dess inneh�ll �r inte sparat n�gonstans i databasen.
[text]
Men ett sista ord om bl�-markerade MediaNr: kombinationen av nummer
inskrivna h�r, t.ex. den fysiska kassetten och den logiska enheten p� det, tillsammans med
den valda MediaTypen, m�ste vara unik genom hela databasen. Det 
�r, t.ex, bara en DVD #1 i din samling, n�sta DVD ska vara #2, 
osv... Detta programs syfte �r inte att anv�ndas till att hantera n�gon videobutik eller
kommersiellt videokassettbibliotek, utan f�r privata samlingar endast :)

[title]
*date_rec#

[text]
Datumf�ltet �r uppdelat i "m�nader och �r"-f�lt. Tills vidare, �r ordningen
h�rdkodad att vara dag-m�nad-�r. Naturligtvis kommer detta att �ndras i en av dem
f�ljande versionerna av phpVideoPro, att anv�nda ordningen konfigurerad med datumformat-inst�llningen
i setup-menyn och att l�sa av landspecifika inst�llningar (eller
med special-anv�ndar-inst�llningar :) i �tanke.

[title]
*counter_start_stopp#

[text]
Dessa f�lt �r mestadels av intresse f�r dem av er som har videobandspelare
utan indexeringsfunktion: du kan skriva in r�knarna fr�n b�rjan
respektive slutet av din inspelning h�r. Eftersom den enda format-restriktionen
�r en l�ngd p� 10 tecken, spelar det ingen roll om du skriver in enkla numeriska
r�knar-v�rden, eller t.om. tidskoder h�r - beroende p� hur din videobandspelare
visar tiden.

[title]
*commercials#

[text]
�ven fast detta f�lt borde vara sj�lvf�rklarande, �r en del ord p� v�rderna att
v�lja: du markerar h�r ifall inspelningen �r avbruten av "reklamblock"
("*yes#") eller inte ("*no#"), eller om du klipper bort dessa  block manuellt ("*cut_off#").
Om du inte kan komma ih�g, s� har du t.om. m�jligheten att s�ga till om din os�kerhet
h�r genom att v�lja "*unknown#".

[title]
Kategorier

[text]
Den valda kategorin i den f�rsta rutan kommer att visas j�msides med huvudfilms-
datan i listorna. Inte nog med det: om du s�ker efter en notering (just
nu genom att anv�nda filter-funktionen) och specifierar en kategori, kommer alla tre av kategorierna
att tas i �tanke.

[title]
Personal

[text]
Var f�rsiktig med att fylla i informationen i dem h�gra f�lten h�r: det f�rsta �r
alltid f�r familjenamnet, det andra f�r det f�rsta namnet. Namn p� personalmedlemmar 
�r inte lagrade tillsammans med film-datan, utan i en separat tabell.
Med film-datan, finns det bara en referens lagrad - s� om du senare vill g� till
listan med n�gra noteringar f�r en specifik person, s� kan du hamna i trubbel: p�
<A HREF="http://www.qumran.org/homes/izzy/">demosajten</A>, s�g jag redan
noteringar som h�ller b�da namndelarna i ett f�lt, bara f�r att lagra tv� personer i
en notering. Sj�lvklart <i>kan</i> du g�ra s� - men det �r inte s� jag planerat det,
och n�gra framtida funktioner beh�ver inte n�dv�ndigtvis t�nkas f� denna m�jlighet.

[text]
Slutligen, finns det en checkruta fastklistrad till varje namn, m�rkt "i listan". Denna,
ocks�, refererar till en najs funktion: det kommer att finnas en m�jlighet till att lista upp,
t.ex. alla sk�despelare tillsammans med titeln p� filmerna dem spelade en roll i.
Genom att markera denna checkruta, kan du best�mma ifall att denna film skall visas f�r
denna sk�despelare. Om, till exempel, din favoritsk�despelare nu spelar v�ldigt seri�sa roller -
men faktiskt spelade i n�gra se*-filmer tidigare, vilka du bara spelade in f�r, humm, l�t oss
s�ga "intresse", men ingen f�rutom du skall nu f� veta om detta (medan l�sning av dina utskrivna kassettlistor),
beh�ver du bara kryssa av rutan h�r och han/hon kommer d� inte att dyka upp tillsammans med
denna films titel i sk�despelarlistan.

[eof]

# /* set_filter */
# /* $Id$ */

[title]
Introduktion

[text]
B�da menyf�rem�len, "*set_filter#" s� v�l som "*unset_filter#",
anropar exakt samma formul�r - med en liten skillnad:
"*unset_filter#" kommer att ta bort alla
filter f�rst, s� du kan starta med ett f�rskt formul�r utan n�got
som blir inst�llt.

[title]
Filter-regler

[text]
<H4>F�rem�l placerade i en tabellcell tillsammans</H4>
<OL>
 <li><b>f�rem�l som inneh�ller min/max v�rden</b><br>
     Dessa f�rem�l �r anslutna med OCH, s� ifall du t.ex. skriver in 
     "Min 60" och
     "Max 90" f�r l�ngd-f�ltet, betyder detta: alla filmer med en l�ngd
     som �r mellan 60 och 90 minuter. Sj�lvklart, ifall bara ett v�rde 
     (t.ex.: min ELLER max) �r specificerat, kommer bara detta att finnas med.
 <li><b>title</b><br>
     h�r kan du skriva in n�gon <i>SubString</i> som inneh�lls i 
     titeln/titlarna du �nskar visas; med "hard" inskrivet skulle
     du f� matchningar av Beatles' "A Hard Day's Night" s� v�l som "Die Hard".
 <li><b>andra f�rem�l</b><br>
     alla andra f�rem�l �r anslutna av ELLER, t.ex.: kryssa i rutan
     RVT och OVT f�r MediaTyp resulterar i alla kassetter, oavsett om det �r
original(ink�pta) videos eller sj�lvinspelade.
</OL>

[text]
<H4>Att kombinera tabellcell-f�rem�l</H4>
Ensamma p�st�enden (d�r p�st�endena betyder inneh�llet av varje
tabellcell, ett bygge av celler, ett p�st�ende) �r anslutet till OCH.
Kryssa i "DVD" som MediaTyp
och "Science Fiction" som kategori resulterar dock i alla DVDs med
Science Fiction-filmer p�.

[eof]

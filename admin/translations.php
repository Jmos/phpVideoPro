<?php
 #############################################################################
 # phpVideoPro                              (c) 2001-2008 by Itzchak Rehberg #
 # written by Itzchak Rehberg <izzysoft AT qumran DOT org>                   #
 # http://www.izzysoft.de/                                                   #
 # ------------------------------------------------------------------------- #
 # This program is free software; you can redistribute and/or modify it      #
 # under the terms of the GNU General Public License (see doc/LICENSE)       #
 # ------------------------------------------------------------------------- #
 # Edit Translations                                                         #
 #############################################################################

 /* $Id$ */

 #========================================================[ initial setup ]==
 $page_id = "admin_translations";
 include("../inc/includes.inc");

 #-------------------------------------------------[ Register global vars ]---
 if (isset($_POST["update"])) $update = TRUE; else $update = FALSE;
 if (isset($_POST["sellang"])) $sellang = TRUE; else $sellang = FALSE;
 if (isset($_GET["savelang"])) $savelang = TRUE; else $savelang = FALSE;
 if (isset($_REQUEST["targetlang"]) && preg_match("/^[a-z]{2}$/",$_REQUEST["targetlang"])) $targetlang = $_REQUEST["targetlang"]; else $targetlang = "";
 if (isset($_REQUEST["start"]) && !preg_match("/[^\d]/",$_REQUEST["start"])) $start = $_REQUEST["start"]; else $start = 0;
 if (isset($_REQUEST["key"]) && !preg_match("/[^0-9a-z\!]/",$searchkey)) $searchkey = $_REQUEST["key"];

 #--------------------------------------------------[ Check authorization ]---
 if (!$pvp->auth->admin) kickoff();

 #--------------------------------------------------[ initialize template ]---
 include("../inc/class.nextmatch.inc");

 $t = new Template($pvp->tpl_dir);
 $t->set_file(array("list"=>"admin_translations.tpl"));
 $t->set_block("list","mtitleblock","mtitlelist");
 $t->set_block("list","mdatablock","mdatalist");
 $t->set_block("list","emptyblock","emptylist");
 $t->set_var("listtitle",lang($page_id));
 $t->set_var("formtarget",$_SERVER["PHP_SELF"] ."\" enctype=\"multipart/form-data");

 #======================================================[ init target lang ]==
 if (!$targetlang) {
   $sel_lang = "<SELECT NAME='targetlang'>";
   $langs    = $db->get_languages();
   $lcount   = count($langs);
   for ($i=0;$i<$lcount;++$i) {
     $langname = $langs[$i]["name"]." (".lang("lang_".$langs[$i]["id"]).")";
     $sel_lang .= "<OPTION VALUE='".$langs[$i]["id"]."'>$langname</OPTION>";
   }
   $sel_lang .= "</SELECT>";
   $t->set_var("sel_lang_title",lang("sel_target_lang"));
   $t->set_var("sel_lang",$sel_lang);
   $t->parse("emptylist","emptyblock");
   $t->set_var("submit_name",lang("sellang"));
   $t->set_var("submit",lang("submit"));
   $hidden = "";
   if (!$pvp->cookie->active) $hidden = "<INPUT TYPE='hidden' NAME='sess_id' VALUE='".$_REQUEST["sess_id"]."'>";
   $t->set_var("hidden",$hidden);
   include("../inc/header.inc");
   $t->pparse("out","list");
   include("../inc/footer.inc");
   exit;
 }

 #========================================================[ save lang file ]==
 if ($savelang) {
   $langs = $db->get_languages();
   $lcount = count($langs);
   for($i=0;$i<$lcount;++$i) {
     if ($langs[$i]["id"] == $targetlang) {
#       $tlang = $langs[$i]["name"];
       $tl = $db->get_singletrans("en","","lang_".$langs[$i]["id"]);
       $tlang = $tl["lang_".$langs[$i]["id"]];
       $tchar = $langs[$i]["charset"];
       break;
     }
   }
   if (!$tchar) $tchar = "utf-8";
   $trans = $db->get_singletrans($targetlang);
   $totals = count($trans["xlist"]);
   $sql   = "# ========================================================\n"
          . "# $tlang Language File created by phpVideoPro v".$version."\n"
          . "# ========================================================\n\n"
          . "UPDATE pvp_languages SET charset='$tchar' WHERE lang_id='$targetlang';\n";
   for ($i=0;$i<$totals;++$i) {
     $msgid = $trans["xlist"][$i];
     $sql .= "INSERT INTO pvp_lang VALUES ('$msgid','$targetlang','".addslashes(str_replace("\n"," ",$trans[$msgid]))."','".addslashes($trans["xcomment"]["$msgid"])."');\n";
   }
   header("Content-type: application/octet-stream");
   header("Content-Disposition: attachment; filename=lang_".$targetlang.".sql");
   echo $sql;
   exit;
 }

 #=================================================[ initialize shortcuts ]===
 for ($i=0;$i<10;++$i)   $keys[] = "$i";    // 0-9
 for ($i=97;$i<122;++$i) $keys[] = chr($i); // a-z
 $abc = "<A HREF='".$_SERVER["PHP_SELF"]."?targetlang=$targetlang;key=!'>!</A>";
 foreach ($keys as $key) {
   $abc .= "&nbsp;&nbsp;<A HREF='".$_SERVER["PHP_SELF"]."?targetlang=$targetlang;key=$key'>"
         . strtoupper($key)."</A>";
 }
 $t->set_var("abc",$abc);

 #=================================[ get translations and setup variables ]===
 $query = "\$db->get_singletrans(\"en\",$start,\"\",\"$searchkey\")";
 $nextmatch = new nextmatch ($query,$pvp->tpl_dir,$_SERVER["PHP_SELF"]."?targetlang=$targetlang",$start,";key=$searchkey");

 $list = $nextmatch->list;
 for ($i=0;$i<$nextmatch->listcount -2;$i++) {
   $msgid  = $list["xlist"][$i];
   if ($update) $db->set_translation($msgid,$_POST[$msgid."_trans"],$targetlang);
   $orig   = $list["$msgid"];
   $target = $db->get_singletrans($targetlang,"",$msgid);
   if ($orig) $orig = htmlentities($orig);
   $t->set_var("code",$msgid);
   $t->set_var("orig",$orig);
   $rows  = ceil( strlen($orig)/40 ) +1;
   if (isset($target[$msgid])) $tmsg = $target[$msgid]; else $tmsg = "";
   $input = "<TEXTAREA NAME='$msgid"."_trans' COLS='50' ROWS='$rows'>$tmsg</TEXTAREA>";
   $t->set_var("trans",$input);
   $t->set_var("sample",$list["xcomment"]["$msgid"]);
   if ($i) $t->parse("mdatalist","mdatablock",TRUE);
     else $t->parse("mdatalist","mdatablock");
 }
 if ($update) $db->lang_available($targetlang,1);
 $hidden = "<INPUT TYPE='hidden' NAME='targetlang' VALUE='$targetlang'>";
 if (isset($searchkey)) $hidden .= "<INPUT TYPE='hidden' NAME='key' VALUE='$searchkey'>";
 if ($start) $hidden .= "<INPUT TYPE='hidden' NAME='start' VALUE='$start'>";
 if (!$pvp->cookie->active) $hidden .= "<INPUT TYPE='hidden' NAME='sess_id' VALUE='".$_REQUEST["sess_id"]."'>";
 $t->set_var("charset","$charset,iso-8859-1");
 $t->set_var("code",lang("trans_code"));
 $t->set_var("orig",lang("orig_trans","en"));
 $t->set_var("trans",lang("target_trans",$targetlang));
 $t->set_var("sample",lang("comments"));
 $t->set_var("submit_name","update");
 $t->set_var("submit",lang("update"));
 $t->set_var("save","<A HREF='".$_SERVER["PHP_SELF"]."?targetlang=$targetlang&savelang=1'>".lang("save_lang_file")."</A>");
 $t->set_var("hidden",$hidden);
 $t->set_var("first",$nextmatch->first);
 $t->set_var("left",$nextmatch->left);
 $t->set_var("right",$nextmatch->right);
 $t->set_var("last",$nextmatch->last);
 $t->parse("mtitlelist","mtitleblock");

 include("../inc/header.inc");
 $t->pparse("out","list");
 include("../inc/footer.inc");
?>
<?php
 #############################################################################
 # phpVideoPro                              (c) 2001-2007 by Itzchak Rehberg #
 # written by Itzchak Rehberg <izzysoft AT qumran DOT org>                   #
 # http://www.izzysoft.de/                                                   #
 # ------------------------------------------------------------------------- #
 # This program is free software; you can redistribute and/or modify it      #
 # under the terms of the GNU General Public License (see doc/LICENSE)       #
 # ------------------------------------------------------------------------- #
 # Display data for a given medium                                           #
 #############################################################################

 /* $Id$ */

 $page_id = "medium";
 include("inc/includes.inc");

 #==================================================[ Check authorization ]===
 if ( !$pvp->auth->browse) {
   kickoff(); // kick-off unauthorized visitors
 }

 #=============================================================[ VulCheck ]===
 if (!empty($_POST["edit"]) && $_POST["edit"]!=lang("edit")) $vuls[] = "Post[edit]";
 if (!empty($_POST["save"]) && $_POST["save"]!=lang("update")) $vuls[] = "Post[update]";
 if (!empty($_POST["cancel"]) && $_POST["cancel"]!=lang("cancel")) $vuls[] = "Post[cancel]";
 if (!empty($_POST["disktype_id"]) && !is_numeric($_POST["disktype_id"])) $vuls[] = "Post[disktype_id]";
 if ($vc=count($vuls)) {
   $msg = lang("input_errors_occured",$vc) . "<UL>\n";
   for ($i=0;$i<$vc;++$i) {
     $msg .= "<LI>Variable ".$vuls[$i]."</LI>\n";
   }
   $msg .= "</UL>";
   $pvp->common->die_error($msg);
 }

 #======================================================[ Setup page vars ]===
 $mtype_id = $_REQUEST["mtype_id"];
 $cass_id  = $_REQUEST["cass_id"];
 $mtype  = $db->get_mtypes("id=$mtype_id");
 $medium = $mtype[0]["sname"] ." ". $cass_id;
 $cass_id = (int) $cass_id;
 $mid    = $db->get_movieid($mtype_id,$cass_id);
 if ($_POST["edit"]) $edit = TRUE; else $edit = FALSE;

 function techbutton ($name,$value,$onclick="") {
   GLOBAL $pvp,$edit;
   if ($edit) { $field = "<INPUT "; $class = "yesnoinput";
   } else { $field = "<INPUT TYPE='button' "; $class = "yesnobutton"; }
   $field  .= "NAME='$name' VALUE='$value' CLASS='$class'";
   if (!$edit && $onclick) $field .= " onClick=\"window.location.href='"
     . $pvp->link->slink($onclick) . "'\"";
   $field .= ">";
   return $field;
 }
 function namebutton ($name,$value,$onclick="") {
   GLOBAL $pvp,$edit;
   if ($edit) { $field = "<INPUT "; $class = "nameinput";
   } else { $field = "<INPUT TYPE='button' "; $class = "namebutton"; }
   $field  .= "NAME='$name' VALUE='$value' CLASS='$class'";
   if (!$edit && $onclick) $field .= " onClick=\"window.location.href='"
     . $pvp->link->slink($onclick) . "'\"";
   $field .= ">";
   return $field;
 }
 function ownerbox ($name,$value,$onclick="") {
   GLOBAL $pvp,$edit,$minfo,$db;
   if ($edit && ($minfo->owner_id == $pvp->auth->user_id ||$pvp->auth->admin)) {
     $field = "<SELECT NAME='owner_id'>";
     $users = $db->get_users(); $uc = count($users);
     for ($i=0;$i<$uc;++$i) {
       $field .= "<OPTION VALUE='".$users[$i]->id."'";
       if ($users[$i]->id == $minfo->owner_id) $field .= " SELECTED";
       $field .= ">".ucfirst($users[$i]->login)."</OPTION>";
     }
     $field .= "</SELECT>";
   } else {
     $field  = "<INPUT TYPE='button' NAME='$name' VALUE='$value' CLASS='namebutton'";
     if ($onclick) $field .= " onClick=\"window.location.href='"
       . $pvp->link->slink($onclick) . "'\"";
     $field .= ">";
   }
   return $field;
 }
 function disktypebox ($name,$value) {
   GLOBAL $pvp,$edit,$minfo,$db,$mtype_id;
   if ($edit && ($pvp->auth->admin || $minfo->owner_id==$pvp->auth->user_id || $db->get_usergrants(array($minfo->owner_id),array(0,$pvp->auth->user_id),array("UPDATE")))) {
     $field  = "<SELECT NAME='disks_id'>";
     $dt     = $db->get_disktypes($mtype_id);
     $dtc = count($dt);
     for ($i=0;$i<$dtc;++$i) {
       $field .= "<OPTION VALUE='".$dt[$i]->id."'";
       if ($dt[$i]->id==$value) $field .= " SELECTED";
       $field .= ">".$dt[$i]->name."</OPTION>";
     }
     $field .= "</SELECT>";
   } else {
     $field  = "<INPUT TYPE='button' NAME='$name' VALUE='".$minfo->type."' CLASS='namebutton'>";
   }
   return $field;
 }
 function rcbutton () {
   GLOBAL $pvp,$edit,$minfo;
   if ($edit) {
     $field = "";
     for ($i=0;$i<7;++$i) {
       $field .= "<INPUT TYPE='checkbox' NAME='rc[]' VALUE='$i' CLASS='checkbox'";
       if (isset($minfo->rc[$i]) && $minfo->rc[$i]) $field .= " CHECKED";
       $field .= ">$i";
       if ($i<6) $field .= "&nbsp;";
     }
   } else {
     for ($i=0;$i<7;++$i) {
       if (isset($minfo->rc[$i]) && $minfo->rc[$i])
         $field .= "<INPUT TYPE='button' NAME='rc[]' VALUE='$i' CLASS='checkbox'>";
     }
   }
   return $field;
 }

 #=============================================[ obtain media information ]===
 $minfo = $db->get_mediainfo($mtype_id,$cass_id);

 #==============================================[ Was the form submitted? ]===
 if (isset($_POST["save"])) {
   $check = array("size","owner_id","storeplace","lentto","disks_id");
   foreach ($check as $val) {
     if ($minfo->$val != $_POST["$val"]) $sinfo->$val = $_POST["$val"];
   }
   if (isset($sinfo->owner_id) && $minfo->owner_id != $pvp->auth->user_id)
     unset($sinfo->owner_id);
   $rc = $_POST["rc"];
   $rccount = count($rc);
   for ($i=0;$i<$rccount;++$i) {
     $sinfo->rc[$rc[$i]] = 1;
   }
   $db->set_mediainfo($mtype_id,$cass_id,$sinfo);
   $minfo = $db->get_mediainfo($mtype_id,$cass_id);
 }

 #=======================================================[ prepare output ]===
 $t = new Template($pvp->tpl_dir);
 $t->set_var("listtitle",lang("medium_overview",$medium));
 if (empty($mid) && !$db->get_usergrants(array(0,$minfo->owner_id),array($pvp->auth->user_id),array("SELECT"))) {
   $t->set_file(array("template"=>"error.tpl"));
   $t->set_var("details",lang("medium_no_access"));
 } else {
   $t->set_file(array("template"=>"medium.tpl"));
   $t->set_block("template","techblock","tech");
   $t->set_block("template","movieblock","movie");
   $t->set_var("techdata",lang("techdata"));
   $t->set_var("moviedata",lang("movies"));
   $t->set_var("form_target",$_SERVER["PHP_SELF"]);

   $owner = ucfirst($minfo->owner);                         // Owner
   if (empty($owner)) $owner = lang("unknown");
   $t->set_var("tname",lang("owner").":&nbsp;");
   $t->set_var("tunit","&nbsp;");
   $t->set_var("tdata",ownerbox("owner",$owner));
   $t->parse("tech","techblock");
   $t->set_var("tname",lang("storeplace").":&nbsp;");       // StorePlace
   $t->set_var("tunit","&nbsp;");
   $t->set_var("tdata",namebutton("storeplace",$minfo->storeplace));
   $t->parse("tech","techblock",TRUE);
   $t->set_var("tname",lang("lentto").":&nbsp;");           // Lent To
   $t->set_var("tunit","&nbsp;");
   $t->set_var("tdata",namebutton("lentto",$minfo->lentto));
   $t->parse("tech","techblock",TRUE);
   $dt = $db->get_disktypes($mtype_id);
   if (count($dt) && !empty($dt[0]->name)) {                // DiskType
     $t->set_var("tname",lang("disk_type").":&nbsp;");
     $t->set_var("tunit","&nbsp;");
     $t->set_var("tdata",disktypebox("disktype",$minfo->disks_id));
     $t->parse("tech","techblock",TRUE);
   }
   if ($minfo->rcsupport && ($minfo->rc!=""||$edit)) {      // RC
     $t->set_var("tname",lang("region_code").":&nbsp;");
     $t->set_var("tunit","&nbsp;");
     $t->set_var("tdata",rcbutton("rc",$minfo->rc));
     $t->parse("tech","techblock",TRUE);
   }
   if ($minfo->size!=""||$edit) {                           // Media Length
     $t->set_var("tname",lang("medialength").":&nbsp;");
     $t->set_var("tunit",lang("minute_abbrev"));
     $t->set_var("tdata",techbutton("size",$minfo->size,"medialength.php?cass_id=$cass_id&mtype_id=$mtype_id"));
     $t->parse("tech","techblock",TRUE);
   }
   if ($minfo->free!="" && !$edit) {                        // Free Space
     $t->set_var("tname",lang("free").":&nbsp;");
     $t->set_var("tunit",lang("minute_abbrev"));
     $t->set_var("tdata",techbutton("free",$minfo->free));
     $t->parse("tech","techblock",TRUE);
   }
   if (!$edit) {                                            // Is R/W
     $t->set_var("tname",lang("is_rw").":&nbsp;");
     $t->set_var("tunit","&nbsp;");
     $t->set_var("tdata",techbutton("rw",$minfo->rw));
     $t->parse("tech","techblock",TRUE);
   }

 #----------------------------------------------[ Set form action buttons ]---
   $hidden = "<INPUT TYPE='hidden' NAME='mtype_id' VALUE='$mtype_id'>"
           . "<INPUT TYPE='hidden' NAME='cass_id' VALUE='$cass_id'>";
   if ($pvp->auth->admin || $minfo->owner_id==$pvp->auth->user_id || $db->get_usergrants(array($minfo->owner_id),array(0,$pvp->auth->user_id),array("UPDATE"))) {
     // allow edit only when permission is given
     if ($edit) {
       $actions = "<INPUT NAME='save' VALUE='".lang("update")."' TYPE='submit'>&nbsp;"
                . "<INPUT NAME='cancel' VALUE='".lang("cancel")."' TYPE='submit' onClick='JavaScript:back()'>"
                . $hidden;
       $t->set_var("formactions",$actions);
     } else {
       $actions = "<INPUT NAME='edit' VALUE='".lang("edit")."' TYPE='submit'>".$hidden;
       $t->set_var("formactions",$actions);
     }
   }

 #=============================================[ obtain movie information ]===
   $mcount = count($mid);
   for ($i=0;$i<$mcount;++$i) {
     $movie = $db->get_movie($mid[$i]);
     $url   = $base_url ."index.php?sel_entry=1&mtype_id=$mtype_id&cass_id=$cass_id&part=".$movie['part'];
     $mlink = $pvp->link->linkurl($url,$movie['part']."&nbsp;");
     $mdata = $movie['title']." (".$movie['cat1']. ", ".$movie['length']." ".lang("minute_abbrev").")";
     $t->set_var("mlink",$mlink);
     $t->set_var("mdata",$mdata);
     if ($i) $t->parse("movie","movieblock",TRUE);
       else $t->parse("movie","movieblock");
   }
 } // end !empty($mid)

 include("inc/header.inc");
 $t->pparse("out","template");

 include("inc/footer.inc");
?>
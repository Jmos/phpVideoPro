<?php
 #############################################################################
 # phpVideoPro                                   (c) 2001 by Itzchak Rehberg #
 # written by Itzchak Rehberg <izzysoft@qumran.org>                          #
 # http://www.qumran.org/homes/izzy/                                         #
 # ------------------------------------------------------------------------- #
 # This program is free software; you can redistribute and/or modify it      #
 # under the terms of the GNU General Public License (see doc/LICENSE)       #
 # ------------------------------------------------------------------------- #
 # User Login Page                                                           #
 #############################################################################

 /* $Id$ */

 $page_id = "login";
 include("inc/includes.inc");
 if ($sess_id &!$pvp->session->verify($sess_id)) $login_hint = "session_expired";
 if ($login_hint) $login_hint = lang("$login_hint");
 if ($sess_id && $logout) {
   $pvp->session->end($sess_id);
   if ($pvp->config->enable_cookies) $pvp->cookie->delete("sess_id");
   $sess_id = "";
 }
 $t = new Template($pvp->tpl_dir);

 if ($submit) {
   if ($sess_id = $pvp->session->create($login,$passwd) ) {
     if ($pvp->config->enable_cookies) {
       $pvp->cookie->set("sess_id",$sess_id);
       header("Location: index.php");
     } else {
       header("Location: index.php?sess_id=$sess_id");
     }
     exit;
   } else {
     $login_hint = $colors["err"] . lang("login_failed") . "</FONT><BR>\n";
   }
 }

 $t->set_file(array("template"=>"login.tpl"));
 $t->set_var("formtarget",$PHP_SELF);
 $t->set_var("login_hint",$login_hint);
 $t->set_var("welcome",lang("welcome"));
 $t->set_var("head_login",lang("login"));
 $t->set_var("head_passwd",lang("password"));
 $t->set_var("submit",lang("submit"));

 $menue = 0;
 include("inc/header.inc");
 $t->pparse("out","template");

 include("inc/footer.inc");
?>
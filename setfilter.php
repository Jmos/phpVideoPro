<?php
 /***************************************************************************\
 * phpVideoPro                                   (c) 2001 by Itzchak Rehberg *
 * written by Itzchak Rehberg <izzysoft@qumran.org>                          *
 * http://www.qumran.org/homes/izzy/                                         *
 * --------------------------------------------------------------------------*
 * This program is free software; you can redistribute and/or modify it      *
 * under the terms of the GNU General Public License (see doc/LICENSE)       *
 * --------------------------------------------------------------------------*
 * Set/UnSet filters                                                         *
 \***************************************************************************/

 /* $Id$ */

  $page_id = "filter";
  include("inc/header.inc");

  function sort_ar($a1,$a2) {
    if($a1[name]<$a2[name]) return -1;
      else if ($a1[name]>$a2[name]) return 1;
  }

  // init templates
  $t = new Template($pvp->tpl_dir);
  $t->set_file(array("t_list"=>"setfilter_list.tpl",
                     "t_item"=>"setfilter_item.tpl",
                     "tone_list"=>"setfilter_tone_list.tpl"));
  $t->set_block("t_item","inputblock","inputlist");
  $t->set_block("tone_list","listblock","listlist");
  $t->set_block("listblock","itemblock","itemlist");

  ##############################################################################
  # create a dump of posted data for debugging purposes and send them to the
  # debug output function
  $ddump = "Saving data:<p>\n<ul>";
  while (list($key, $val) = each($HTTP_POST_VARS)) {
    $ddump .= "<li>$key => $val<br>";
  }
  $ddump .= "</ul></TD><TD>\n";
  debug("V",$ddump);

  if ($reset) { // user wants to unset all filter
    $db->unset_preferences("filter");
  } elseif ($save) { // new filter values were submitted
    $mtypes = $db->get_mtypes();
    for ($i=0;$i<count($mtypes);$i++) {
      $id = $mtypes[$i][id];
      $field = "mtype_" . $id;
      if (${$field}) $filter->mtype->$id = TRUE; else $filter->mtype->$id = FALSE;
    }
    $filter->length_min  = $length_min;
    $filter->length_max  = $length_max;
    $filter->aquired_min = $aquired_min;
    $filter->aquired_max = $aquired_max;
    $pict = $db->get_pict();
    for ($i=0;$i<count($pict);$i++) {
      $id    = $pict[$i][id];
      $field = "pict_" . $id;
      if (${$field}) $filter->pict->$id = TRUE; else $filter->pict->$id = FALSE;
    }
    $pict = $db->get_color();
    for ($i=0;$i<count($pict);$i++) {
      $id    = $pict[$i][id];
      $field = "color_" . $id;
      if (${$field}) $filter->color->$id = TRUE; else $filter->color->$id = FALSE;
    }
    $pict = $db->get_tone();
    for ($i=0;$i<count($pict);$i++) {
      $id    = $pict[$i][id];
      $field = "tone_" . $id;
      if (${$field}) $filter->tone->$id = TRUE; else $filter->tone->$id = FALSE;
    }
    $filter->lp = $lp;
    $filter->fsk_min = $fsk_min;
    $filter->fsk_max = $fsk_max;
    $filter->title   = $title;
    // first reset, then set anew - to allow editing of pre-sets:
    $max = count($filter->cat);
    for ($i=0;$i<$max;$i++) $filter->cat->$i = FALSE;
    for ($i=0;$i<count($cat_id);$i++) {
      $filter->cat->$cat_id[$i] = TRUE;
    }
    $max = count($filter->actor);
    for ($i=0;$i<$max;$i++) $filter->actor->$i = FALSE;
    for ($i=0;$i<count($act_id);$i++) {
      $filter->actor->$act_id[$i] = TRUE;
    }
    $max = count($filter->director);
    for ($i=0;$i<$max;$i++) $filter->director->$i = FALSE;
    for ($i=0;$i<count($dir_id);$i++) {
      $filter->director->$dir_id[$i] = TRUE;
    }
    $max = count($filter->composer);
    for ($i=0;$i<$max;$i++) $filter->composer->$i = FALSE;
    for ($i=0;$i<count($mus_id);$i++) {
      $filter->composer->$mus_id[$i] = TRUE;
    }
    $save = rawurlencode( serialize($filter) );
    $db->set_preferences("filter",$save);
/* ?>
<HTML><HEAD>
  <meta http-equiv="refresh" content="0; URL=<? echo $base_url . "index.php" ?>">
</HEAD></HTML><? */
  }

  $filter = $db->get_preferences("filter");
  if ( $filter ) { // there are already filters defined
    $filter = unserialize ( rawurldecode( $filter ) );
  }
  ########################################################################################
  # Create the Form Fields
  // ------------------------------------------------------------------[ left side ]------
  # mtype
    unset ($id,$name);
    $mtypes = $db->get_mtypes();
    for ($i=0;$i<count($mtypes);$i++) {
      $id[$i]   = $mtypes[$i][id];
      $name[$i] = $mtypes[$i][sname];
      if ($filter->mtype->$id[$i]) { $checked[$i] = " CHECKED"; } else { $checked[$i] = ""; }
    }
    $t->set_var("item","");
    for ($k=0;$k<count($id);$k++) {
      $t->set_var("input","<INPUT TYPE=\"checkbox\" NAME=\"mtype_" . $id[$k] . "\" . $checked[$k] class=\"checkbox\">&nbsp;$name[$k]</TD>");
      $t->parse("inputlist","inputblock",TRUE);
    }
    $t->parse("mtype","t_item");

    # length
    $input = lang("min") . ":&nbsp;<INPUT NAME=\"length_min\"";
    if ( isset($filter->length_min) ) $input .= " VALUE=\"" . $filter->length_min . "\"";
    $input .= $form["addon_filmlen"] . ">";
    $t->set_var("input",$input);
    $t->parse("inputlist","inputblock");
    $input = lang("max") . ":&nbsp;<INPUT NAME=\"length_max\"";
    if ( isset($filter->length_max) ) $input .= " VALUE=\"" . $filter->length_max . "\"";
    $input .= $form["addon_filmlen"] . ">";
    $t->set_var("input",$input);
    $t->parse("inputlist","inputblock",TRUE);
    $t->parse("length","t_item");

    # date
    $addon = "SIZE=\"10\" MAXLENGTH=\"10\"";
    $input = lang("min") . ":&nbsp;<INPUT NAME=\"aquired_min\"";
    if ( isset($filter->aquired_min) ) $input .= " VALUE=\"" . $filter->aquired_min . "\"";
    $input .= "$addon>";
    $t->set_var("input",$input);
    $t->parse("inputlist","inputblock");
    $input = lang("max") . ":&nbsp;<INPUT NAME=\"aquired_max\"";
    if ( isset($filter->aquired_max) ) $input .= " VALUE=\"" . $filter->aquired_max . "\"";
    $input .= "$addon>";
    $t->set_var("input",$input);
    $t->parse("inputlist","inputblock",TRUE);
    $t->parse("date","t_item");

    # screen
    unset($id);
    $t->set_var("inputlist","");
    $t->set_var("item","");
    $pict = $db->get_pict();
    for ($i=0,$k=1;$i<count($pict);$i++,$k++) {
      $id[$i]   = $pict[$i][id];
      $name[$i] = $pict[$i][name];
    }
    for ($k=0;$k<count($id);$k++) {
      if ($filter->pict->$id[$k]) { $checked = " CHECKED"; } else { $checked = ""; }
      $t->set_var("input","<INPUT TYPE=\"checkbox\" NAME=\"pict_" . $id[$k] . "\"$checked class=\"checkbox\">&nbsp;$name[$k]");
      $t->parse("inputlist","inputblock",TRUE);
    }
    $t->parse("screen","t_item");

    # picture
    unset($id);
    $t->set_var("inputlist","");
    $t->set_var("item","");
    $pict = $db->get_color();
    for ($i=0;$i<count($pict);$i++) {
      $id[$i]   = $pict[$i][id];
      $name[$i] = $pict[$i][name];
      $input = "<INPUT TYPE=\"checkbox\" NAME=\"color_$id[$i]\"";
      if ($filter->color->$id[$i]) $input .= " CHECKED";
      $input .= " class=\"checkbox\">&nbsp;" . lang("$name[$i]");
      $t->set_var("input",$input);
      $t->parse("inputlist","inputblock",TRUE);
    }
    $t->parse("picture","t_item");

    # tone
    unset($id);
    $t->set_var("itemlist","");
    $pict = $db->get_tone();
    for ($i=0;$i<count($pict);$i++) {
      $id[$i]   = $pict[$i][id];
      $name[$i] = $pict[$i][name];
      $t->set_var("input",$name[$i]);
      $t->parse("itemlist","itemblock",TRUE);
    }
    $t->parse("listlist","listblock");
    $t->set_var("itemlist","");
    for ($i=0;$i<count($name);$i++) {
      $input = "<INPUT TYPE=\"checkbox\" NAME=\"tone_" . $id[$i] . "\"";
      if ($filter->tone->$id[$i]) $input .= " CHECKED";
      $input .= " class=\"checkbox\">";
      $t->set_var("input",$input);
      $t->parse("itemlist","itemblock",TRUE);
    }
    $t->parse("listlist","listblock",TRUE);
    $t->parse("tone","tone_list");

    # longplay
    if ($filter->lp) { $checked = " CHECKED"; } else { $checked = ""; }
    $t->set_var("longplay","<INPUT TYPE=\"checkbox\" NAME=\"lp\"$checked class=\"checkbox\">");

    # fsk
    $input = lang("min") . ":&nbsp;<INPUT NAME=\"fsk_min\"";
    if ( isset($filter->fsk_min) ) $input .= " VALUE=\"" . $filter->fsk_min . "\"";
    $input .= $form["addon_fsk"] . ">";
    $t->set_var("input",$input);
    $t->parse("inputlist","inputblock");
    $input = lang("max") . ":&nbsp;<INPUT NAME=\"fsk_max\"";
    if ( isset($filter->fsk_max) ) $input .= " VALUE=\"" . $filter->fsk_max . "\"";
    $input .= $form["addon_fsk"] . ">";
    $t->set_var("input",$input);
    $t->parse("inputlist","inputblock",TRUE);
    $t->parse("fsk","t_item");

  // -----------------------------------------------------------------[ right side ]------
    # title
    $input = "<INPUT NAME=\"title\"";
    if ( isset($filter->title) ) $input .= " VALUE=\"" . $filter->title . "\"";
    $input .= $form["addon_title"] . ">";
    $t->set_var("title",$input);

    # category
    unset($id);
    $pict = $db->get_category("");
    $option = "";
    for ($i=0;$i<count($pict);$i++) {
      $id   = $pict[$i][id];
      $name = $pict[$i][name];
      $option .= "<OPTION VALUE=\"$id\"";
      if ($filter->cat->$id) $option .= " SELECTED";
      $option .= ">$name</OPTION>";
    }
    $t->set_var("category","<SELECT NAME=\"cat_id[]\" SIZE=\"7\" MULTIPLE class=\"multiselect\">$option</SELECT>");

    # actor
    unset($id);
    $pict = $db->get_actor("");
    usort ($pict,"sort_ar");
    $option = "";
    for ($i=0;$i<count($pict);$i++) {
      $id   = $pict[$i][id];
      $name = $pict[$i][name];
      $firstname = $pict[$i][firstname];
      $option .= "<OPTION VALUE=\"$id\"";
      if ($filter->actor->$id) $option .= " SELECTED";
      $option .= ">$name, $firstname</OPTION>";
    }
    $t->set_var("actor","<SELECT NAME=\"act_id[]\" SIZE=\"7\" MULTIPLE class=\"multiselect\">$option</SELECT>");

    # director
    unset($id);
    $pict = $db->get_director("");
    usort ($pict,"sort_ar");
    $option = "";
    for ($i=0;$i<count($pict);$i++) {
      $id   = $pict[$i][id];
      $name = $pict[$i][name];
      $firstname = $pict[$i][firstname];
      $option .= "<OPTION VALUE=\"$id\"";
      if ($filter->director->$id) $option .= " SELECTED";
      $option .= ">$name, $firstname</OPTION>";
    }
    $t->set_var("director","<SELECT NAME=\"dir_id[]\" SIZE=\"7\" MULTIPLE class=\"multiselect\">$option</SELECT>");

    # composer
    unset($id);
    $pict = $db->get_music("");
    usort ($pict,"sort_ar");
    dbquery("SELECT id,name,firstname FROM music ORDER BY name");
    $option = "";
    for ($i=0;$i<count($pict);$i++) {
      $id   = $pict[$i][id];
      $name = $pict[$i][name];
      $firstname = $pict[$i][firstname];
      $option .= "<OPTION VALUE=\"$id\"";
      if ($filter->composer->$id) $option .= " SELECTED";
      $option .= ">$name, $firstname</OPTION>";
    }
    $t->set_var("composer","<SELECT NAME=\"mus_id[]\" SIZE=\"7\" MULTIPLE class=\"multiselect\">$option</SELECT>");

# build target
$t->set_var("form_target",$PHP_SELF);
$t->set_var("listtitle",lang("filter_setup"));
$t->set_var("mtype_name",lang("mediatype"));
$t->set_var("length_name",lang("length"));
$t->set_var("date_name",lang("date_rec"));
$t->set_var("screen_name",lang("screen"));
$t->set_var("picture_name",lang("picture"));
$t->set_var("tone_name",lang("tone"));
$t->set_var("longplay_name",lang("longplay"));
$t->set_var("fsk_name",lang("fsk"));
$t->set_var("title_name",lang("title"));
$t->set_var("category_name",lang("category"));
$t->set_var("actor_name",lang("actor"));
$t->set_var("director_name",lang("director"));
$t->set_var("composer_name",lang("composer"));
$t->pparse("out","t_list");

include("inc/footer.inc");
?>
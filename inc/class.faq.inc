<?php
 #############################################################################
 # iFAQMaker                                     (c) 2004 by Itzchak Rehberg #
 # written by Itzchak Rehberg <izzysoft@qumran.org>                          #
 # http://www.qumran.org/homes/izzy/                                         #
 # ------------------------------------------------------------------------- #
 # This program is free software; you can redistribute and/or modify it      #
 # under the terms of the GNU General Public License (see doc/LICENSE)       #
 # ------------------------------------------------------------------------- #
 # FAQ Generator Base Class File                                             #
 # ------------------------------------------------------------------------- #
 # Requirements:                                                             #
 #  * class.template.inc                                                     #
 #  * global function: string lang(string) for translations                  #
 #############################################################################

 /* $Id$ */

require_once(dirname(__FILE__)."/class.template.inc");

#====================================================[ Build page content ]===
/** FAQ Generator
 * @package Api
 * @class faq
 * @author Izzy (izzysoft@qumran.org)
 * @copyright (c) 2004 by Itzchak Rehberg and IzzySoft
 */
class faq {

 /** Constructor: Setting up the templates
  * @constructor faq
  * @param string tpl_dir Directory containing the HTML template files
  * @param string tpl_file Filename of the template file to use
  * @param mixed toc style of the "table of contents" (ul|ol), empty for no toc
  *  If the "tocblock" is not defined in your template at all, specify "0" here
  */
 function faq($dir,$file,$toc="") {
  $this->version = "0.1.1";
  $this->t = new Template($dir);
  $this->t->set_file(array("main"=>"$file"));
  $this->t->set_block("main","titleblock","titlelist");
  $this->t->set_block("titleblock","textblock","textlist");
  if ($toc!==0)
    $this->t->set_block("main","tocblock","toclist");
  $this->img->logo = "islogo.gif";
  $this->img->w3c  = "w3c.jpg";
  $this->toc = $toc;
  $this->toclist = "";
 }

 /** Read the input file
  * @method private fileRead
  * @param string filename
  */
 function fileRead($file) {
  $this->input = file($file);
  if (substr(trim($this->input[0]),0,1)=="!") { // "symbolic link"
    $file = dirname($file) . "/" . trim(substr($this->input[0],1));
    $this->input = file($file);
  }
 }

 /** Parse input text into blocks.
  *  Blocks start with a line containing only the "block header", which
  *  looks like <pre>[&lt;blockname&gt;|level|hname]</pre> where:<ul>
  *  <li><i>&lt;blockname&gt;</i> is one of "title", "text" or "eof"</li>
  *  <li><i>level</i> is an integer (or empty) for e.g. &lt;H1&gt;</li>
  *  <li><i>hname</i> is a name (&lt;A NAME="<i>name</i>"&gt;) for references</li></ul>
  *  everything after the <li>&lt;blockname&gt;</i> is optional.
  * @method public parseInput
  * @param string filename input file name
  */
 function parseInput($file,$title="") {
  $this->fileRead($file);
  $blocknr = -1;
  $lines = count($this->input);
  for ($i=0;$i<$lines;++$i) {
    $line = trim($this->input[$i]);
    if ( substr(trim($line),0,1) == "#" ) continue; // strip off comments
    $mark = preg_match("/^\[(\S+)\]$/",$line,$hit);
    if ($mark) {
      ++$blocknr;
      $desc = preg_match("/([^\|]+)\|([^\|]*)\|(\S*)$/",$hit[1],$set);
      if ($desc) { // Special settings for this block
        $this->block[$blocknr]->type  = $set[1];
        $this->block[$blocknr]->level = $set[2]; // <h$level>
	$this->block[$blocknr]->name  = $set[3]; // <a name=...>
      } else {
        $this->block[$blocknr]->type  = $hit[1];
        $this->block[$blocknr]->level = 1; // <h$level>
	$this->block[$blocknr]->name  = $blocknr; // <a name=...>
      }
      $this->block[$blocknr]->content = "";
      if ($hit[1]=="eof") break;
    } elseif ($blocknr>-1) {
      $this->block[$blocknr]->content .= $line."\n";
    }
  }
  $this->blocks = ++$blocknr;
  $this->textReplace();
  if (!empty($title)) $this->t->set_var("listtitle",$title);
 } // end parse_input()

 /** Replace variables and translations
  * @method private textReplace
  */
 function textReplace() {
  for ($k=0;$k<$this->blocks;++$k) {
   $content = $this->block[$k]->content;
   if ( preg_match_all("/\{\S+\}/",$content,$matches) ) { // replace variables
    for ($i=0;$i<count($matches[0]);$i++) {
      $var = substr($matches[0][$i],1,strlen($matches[0][$i])-2);
      $pos = strpos($var,"->");
      if ($pos) {
       $obj = substr($var,0,$pos); $prop = substr($var,$pos+2);
       GLOBAL $$obj;
       $rvar = $$obj->$prop;
      } else { $rvar = $GLOBALS[$var]; }
      $content = preg_replace("/\{$var\}/",$rvar,$content);
    }
   }
   if ( preg_match_all("/\*\S+\#/",$content,$matches) ) { // replace translations
    for ($i=0;$i<count($matches[0]);$i++) {
      $var  = substr($matches[0][$i],1,strlen($matches[0][$i])-2);
      $rvar = lang($var);
      $content = preg_replace("/\*$var\#/",$rvar,$content);
    }
   }
   $this->block[$k]->content = $content;
  }
 } // end textReplace

 /** Output the text
  * @method public parseOutput
  */
 function parseOutput() {
  $text_open = FALSE; $block_open = 0; $toclevel = 0; $list = $this->toc;
  for ($i=0;$i<$this->blocks;++$i) {
    switch (strtolower($this->block[$i]->type)) {
      case "title" : if (!$text_open && $block_open>0) {
                       $this->set_nav("textlist",""); // init empty textblock
		     }
                     $text_open = FALSE;
                     switch ($block_open) {
                       case 0 : break; // first title just starts here
                       case 1 : $this->t->parse("titlelist","titleblock"); break;
                       default: $this->t->parse("titlelist","titleblock",TRUE);
                     }
                     $this->set_nav("title",trim($this->block[$i]->content));
                     $this->set_nav("t_name",$this->block[$i]->name);
		     $this->set_nav("t_level",$this->block[$i]->level);
                     $this->set_nav("textlist",""); // init empty textblock
		     if (!empty($this->toc)) {
                       $ldiff = $this->block[$i]->level - $toclevel;
                       for ($k=-1;$k>$ldiff;--$k) { // level diff > 1 downstairs
                         $this->toclist .= "</$list>";
                         if ($k==$ldiff+1) $ldiff = -1;
                       }
		       switch ($ldiff) {
		         case -1 : $this->toclist .= "</$list>"; break;
			 case  0 : if ($toclevel>0) $this->toclist .= "</li>"; break;
			 case  1 : $this->toclist .= "<$list>"; break;
			 default : break;
		       }
		       $toclevel = $this->block[$i]->level;
		       $this->toclist .= "<li><a class='toc' href='#".$this->block[$i]->name."'>".trim($this->block[$i]->content)."</a>";
		     }
                     ++$block_open;
                     break;
      case "text"  : $this->set_nav("text",trim($this->block[$i]->content));
                     if ($text_open) {
                       $this->t->parse("textlist","textblock",TRUE);
                     } else {
                       $this->t->parse("textlist","textblock");
                     }
                     $text_open = TRUE;
                     break;
      case "eof"   : break 2;
      default      : break; // echo "<b><i>!!!(".$this->block[$i]->type.")".$this->block[$i]->content."!!!</i></b>\n";
    }
  } // end blocks = end input || eof
  #-- whether to parse the TOC into to the template
  if (empty($this->toc)) {
    $this->set_nav("toclist","");
  } else {
    for ($k=0;$k<$toclevel;++$k) { $this->toclist .= "</li></$list>"; }
       $this->set_nav("toc",$this->toclist);
    $this->t->parse("toclist","tocblock");
  }
  switch ($block_open) { // parse open blocks
    case 0 : break; // nothing to do
    case 1 : $this->t->parse("titlelist","titleblock"); break;
    default: $this->t->parse("titlelist","titleblock",TRUE);
  }
  $this->t->pparse("out","main");
 }

 /** Set template variables. Wrapper around Template::set_var
  * @method public set_nav
  * @param string name name of template variable
  * @param string content value of template variable
  */
 function set_nav($name,$content) {
   $this->t->set_var($name,$content);
 }

} // end class

/** Type of the TOC: "ol", "ul" or "" (no TOC)
 * @attribute private string toc
 * @class faq
 */
/** Content of the TOC (to be parsed into {toc})
 * @attribute private string toclist
 * @class faq
 */
/** Content of the parsed input file (one line per cell)
 * @attribute private array input
 * @class faq
 */
/** Content of the parsed input file, splitted into blocks
 * @attribute private array block
 * @class faq
 */
/** Number of blocks created
 * @attribute private integer blocks
 * @class faq
 */

?>
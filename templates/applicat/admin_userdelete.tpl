<BR>
<TABLE ALIGN="center" CELLPADDING="0" CELLSPACING="0" BORDER="0"><TR><TD>
<DIV STYLE="display:inline">
<TABLE WIDTH="95%" CELLPADDING="0" CELLSPACING="0" CLASS="window" BORDER=0" ALIGN="center"><TR><TD>
<TABLE WIDTH="100%" CELLPADDING="0" CELLSPACING="0" BORDER="0">
 <TR><TD NOWRAP WIDTH="100%" CLASS="wintitle"><DIV STYLE="margin:2">{listtitle}</DIV></TD>
     <TD ALIGN="right" CLASS="wintitle" STYLE="vertical-align:middle;">
      <INPUT TYPE="image" NAME="button_help" CLASS="imgbut" SRC="{tpl_dir}images/win_help.gif" WIDTH="14" HEIGHT="13" onClick="{help_link}"></TD>
     <TD CLASS="wintitle" STYLE="vertical-align:middle;"><DIV STYLE="width:20;text-align:center;">
      <INPUT TYPE="image" NAME="button_close" CLASS="imgbut" SRC="{tpl_dir}images/win_close.gif" WIDTH="14" HEIGHT="13" onClick="window.location.href='{logoff_link}'"></DIV></TD></TR>
</TABLE></TD></TR>
<TR><TD BGCOLOR="#AAAAAA"><IMG SRC="{tpl_dir}0.gif" WIDTH="1" HEIGHT="1" BORDER="0"></TD></TR>
<TR><TD BGCOLOR="#FFFFFF"><IMG SRC="{tpl_dir}0.gif" WIDTH="1" HEIGHT="1" BORDER="0"></TD></TR>
<TR><TD>

<FORM NAME="deleform" METHOD="post" ACTION="{formtarget}">
 <INPUT TYPE="hidden" NAME="delete" VALUE="{delete}">
 <TABLE ALIGN="center" BORDER="0">
  <TR><TD COLSPAN="2"><B><DIV ALIGN="center">{delete_yn}</DIV></B></FONT></TD></TR>
  <TR><TD WIDTH="50%"><DIV ALIGN="center"><INPUT TYPE="submit" NAME="cancel" VALUE="{no}"></DIV></TD>
      <TD WIDTH="50%"><DIV ALIGN="center"><INPUT TYPE="submit" NAME="confirmed" VALUE="{yes}"></DIV></TD></TR>
 {hidden}
 </TABLE>
</FORM>

</TABLE>
</DIV>
</TD></TR></TABLE>
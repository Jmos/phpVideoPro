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

<FORM NAME="config_form" METHOD="post" ACTION="{formtarget}">
<TABLE ALIGN="center" WIDTH="100%" BORDER="1" STYLE="margin:5">
<!-- BEGIN listblock -->
 <TR><TH>{list_head}</TH></TR>
 <TR CLASS="content"><TD>
  <TABLE WIDTH=100%>
  <!-- BEGIN itemblock -->
   <TR><TD WIDTH=70%><b>{item_name}</b><br>{item_comment}</TD>
    <TD WIDTH=30%>{item_input}</TD></TR>
  <!-- END itemblock -->
  </TABLE></TD></TR>
  {sess_id}
<!-- END listblock -->
</TABLE>

</TD></TR>
<TR><TD BGCOLOR="#AAAAAA"><IMG SRC="{tpl_dir}0.gif" WIDTH="1" HEIGHT="1" BORDER="0"></TD></TR>
<TR><TD BGCOLOR="#FFFFFF"><IMG SRC="{tpl_dir}0.gif" WIDTH="1" HEIGHT="1" BORDER="0"></TD></TR>

 <TR><TD><DIV STYLE="margin:3;text-align:center">{update}</DIV></TD></TR>
</FORM>
{config_end}

</TABLE>
</DIV>
</TD></TR></TABLE>